// Generated from /pastry-2.1/src/rice/pastry/standard/PeriodicLeafSetProtocol.java
#include <rice/pastry/standard/PeriodicLeafSetProtocol.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Observer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/util/TimerWeakHashMap.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/ScheduledMessage.hpp>
#include <rice/pastry/leafset/BroadcastLeafSet.hpp>
#include <rice/pastry/leafset/InitiateLeafSetMaintenance.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/LeafSetProtocolAddress.hpp>
#include <rice/pastry/leafset/RequestLeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/InitiatePingNeighbor.hpp>
#include <rice/pastry/standard/PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1.hpp>
#include <rice/pastry/standard/PeriodicLeafSetProtocol_PLSPMessageDeserializer.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::standard::PeriodicLeafSetProtocol::PeriodicLeafSetProtocol(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::PeriodicLeafSetProtocol::PeriodicLeafSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt) 
    : PeriodicLeafSetProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,local,ls,rt);
}

void rice::pastry::standard::PeriodicLeafSetProtocol::init()
{
    hasSetStrategy = false;
    ready = false;
    destroyed = false;
}

void rice::pastry::standard::PeriodicLeafSetProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt)
{
    super::ctor(ln, nullptr, ::rice::pastry::leafset::LeafSetProtocolAddress::getCode(), new PeriodicLeafSetProtocol_PLSPMessageDeserializer(ln));
    init();
    this->localNode = ln;
    npc(ln)->addObserver(this);
    auto params = npc(npc(ln)->getEnvironment())->getParameters();
    if(npc(params)->contains(u"pastry_periodic_leafset_protocol_use_own_random"_j) && npc(params)->getBoolean(u"pastry_periodic_leafset_protocol_use_own_random"_j)) {
        if(npc(params)->contains(u"pastry_periodic_leafset_protocol_random_seed"_j) && !npc(npc(params)->getString(u"pastry_periodic_leafset_protocol_random_seed"_j))->equalsIgnoreCase(u"clock"_j)) {
            this->random = new ::rice::environment::random::simple::SimpleRandomSource(npc(params)->getLong(u"pastry_periodic_leafset_protocol_random_seed"_j), npc(npc(ln)->getEnvironment())->getLogManager(), u"socket"_j);
        } else {
            this->random = new ::rice::environment::random::simple::SimpleRandomSource(npc(npc(ln)->getEnvironment())->getLogManager(), u"periodic_leaf_set"_j);
        }
    } else {
        this->random = npc(npc(ln)->getEnvironment())->getRandomSource();
    }
    this->timeSource = npc(npc(ln)->getEnvironment())->getTimeSource();
    this->localHandle = local;
    this->leafSet = ls;
    auto i = npc(npc(this->leafSet)->asList())->iterator();
    while (npc(i)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next()));
        npc(nh)->addObserver(this, 50);
    }
    this->routeTable = rt;
    this->lastTimeReceivedBLS = new ::rice::p2p::util::TimerWeakHashMap(npc(npc(npc(ln)->getEnvironment())->getSelectorManager())->getTimer(), int32_t(300000));
    this->lastTimeSentBLS = new ::rice::p2p::util::TimerWeakHashMap(npc(npc(npc(ln)->getEnvironment())->getSelectorManager())->getTimer(), int32_t(300000));
    auto p = npc(npc(ln)->getEnvironment())->getParameters();
    PING_NEIGHBOR_PERIOD = npc(p)->getInt(u"pastry_protocol_periodicLeafSet_ping_neighbor_period"_j);
    LEASE_PERIOD = npc(p)->getInt(u"pastry_protocol_periodicLeafSet_lease_period"_j);
    BLS_THROTTLE = npc(p)->getInt(u"pastry_protocol_periodicLeafSet_request_lease_throttle"_j);
    this->lastTimeRenewedLease = new ::rice::p2p::util::TimerWeakHashMap(npc(npc(npc(ln)->getEnvironment())->getSelectorManager())->getTimer(), LEASE_PERIOD * int32_t(2));
    pingNeighborMessage = npc(localNode)->scheduleMsgAtFixedRate(new InitiatePingNeighbor(), PING_NEIGHBOR_PERIOD, PING_NEIGHBOR_PERIOD);
}

void rice::pastry::standard::PeriodicLeafSetProtocol::updateRecBLS(::rice::pastry::NodeHandle* from, int64_t time)
{
    if(time == 0)
        return;

    auto oldTime = java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Long* >(npc(lastTimeReceivedBLS)->get(from)));
    if((oldTime == nullptr) || (npc(oldTime)->longValue() < time)) {
        npc(lastTimeReceivedBLS)->put(from, new ::java::lang::Long(time));
        auto leaseTime = time + LEASE_PERIOD - npc(timeSource)->currentTimeMillis();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
            npc(logger)->log(::java::lang::StringBuilder().append(u"PLSP.updateRecBLS("_j)->append(static_cast< ::java::lang::Object* >(from))
                ->append(u","_j)
                ->append(time)
                ->append(u"):"_j)
                ->append(leaseTime)->toString());
        } else {
            if(leaseTime < 10 && npc(logger)->level <= ::rice::environment::logging::Logger::INFO) {
                npc(logger)->log(::java::lang::StringBuilder().append(u"PLSP.updateRecBLS("_j)->append(static_cast< ::java::lang::Object* >(from))
                    ->append(u","_j)
                    ->append(time)
                    ->append(u"):"_j)
                    ->append(leaseTime)->toString());
            }
        }
        if(hasSetStrategy)
            isReady();

    }
}

void rice::pastry::standard::PeriodicLeafSetProtocol::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(dynamic_cast< ::rice::pastry::leafset::BroadcastLeafSet* >(msg) != nullptr) {
        auto bls = java_cast< ::rice::pastry::leafset::BroadcastLeafSet* >(msg);
        if(npc(bls)->type() == ::rice::pastry::leafset::BroadcastLeafSet::JoinInitial) {
            npc(leafSet)->merge(npc(bls)->leafSet(), npc(bls)->from(), routeTable, false, nullptr);
            broadcastAll();
        } else {
            auto set = npc(leafSet)->neighborSet(::java::lang::Integer::MAX_VALUE);
            for (auto i = int32_t(0); i < npc(set)->size(); i++) 
                                if(npc(npc(bls)->leafSet())->test(npc(set)->get(i)))
                    npc(npc(set)->get(i))->checkLiveness();


            set = npc(npc(bls)->leafSet())->neighborSet(::java::lang::Integer::MAX_VALUE);
            for (auto i = int32_t(0); i < npc(set)->size(); i++) 
                                if(!npc(npc(set)->get(i))->isAlive())
                    npc(npc(set)->get(i))->checkLiveness();


            npc(leafSet)->merge(npc(bls)->leafSet(), npc(bls)->from(), routeTable, false, nullptr);
        }
        if((npc(npc(bls)->leafSet())->get(1) == localHandle) || (npc(npc(bls)->leafSet())->get(-int32_t(1)) == localHandle)) {
            updateRecBLS(npc(bls)->from(), npc(bls)->getTimeStamp());
        }
    } else if(dynamic_cast< ::rice::pastry::leafset::RequestLeafSet* >(msg) != nullptr) {
        auto rls = java_cast< ::rice::pastry::leafset::RequestLeafSet* >(msg);
        if(npc(rls)->getTimeStamp() > 0) {
            npc(lastTimeRenewedLease)->put(npc(rls)->returnHandle(), new ::java::lang::Long(npc(timeSource)->currentTimeMillis()));
            npc(leafSet)->put(npc(rls)->returnHandle());
            if(!npc(npc(rls)->returnHandle())->isAlive()) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Issued lease to dead node:"_j)->append(static_cast< ::java::lang::Object* >(npc(rls)->returnHandle()))
                        ->append(u" initiating checkLiveness()"_j)->toString());

                npc(npc(rls)->returnHandle())->checkLiveness();
            }
        }
        npc(thePastryNode)->send(npc(rls)->returnHandle(), new ::rice::pastry::leafset::BroadcastLeafSet(localHandle, leafSet, ::rice::pastry::leafset::BroadcastLeafSet::Update, npc(rls)->getTimeStamp()), nullptr, options);
    } else if(dynamic_cast< ::rice::pastry::leafset::InitiateLeafSetMaintenance* >(msg) != nullptr) {
        auto set = npc(leafSet)->neighborSet(::java::lang::Integer::MAX_VALUE);
        if(npc(set)->size() > 1) {
            auto handle = npc(set)->get(npc(random)->nextInt(npc(set)->size() - int32_t(1)) + int32_t(1));
            npc(thePastryNode)->send(handle, new ::rice::pastry::leafset::RequestLeafSet(localHandle, npc(timeSource)->currentTimeMillis()), nullptr, options);
            npc(thePastryNode)->send(handle, new ::rice::pastry::leafset::BroadcastLeafSet(localHandle, leafSet, ::rice::pastry::leafset::BroadcastLeafSet::Update, int32_t(0)), nullptr, options);
            auto check = npc(set)->get(npc(random)->nextInt(npc(set)->size() - int32_t(1)) + int32_t(1));
            npc(check)->checkLiveness();
        }
    } else if(dynamic_cast< InitiatePingNeighbor* >(msg) != nullptr) {
        auto left = npc(leafSet)->get(-int32_t(1));
        auto right = npc(leafSet)->get(1);
        if(left != nullptr) {
            sendBLS(left, !hasLease(left));
        }
        if(right != nullptr) {
            sendBLS(right, !hasLease(right));
        }
    }
}

void rice::pastry::standard::PeriodicLeafSetProtocol::broadcastAll()
{
    auto bls = new ::rice::pastry::leafset::BroadcastLeafSet(localHandle, leafSet, ::rice::pastry::leafset::BroadcastLeafSet::JoinAdvertise, int32_t(0));
    auto set = npc(leafSet)->neighborSet(::java::lang::Integer::MAX_VALUE);
    for (auto i = int32_t(1); i < npc(set)->size(); i++) 
                npc(thePastryNode)->send(npc(set)->get(i), bls, nullptr, options);

}

void rice::pastry::standard::PeriodicLeafSetProtocol::start()
{
    if(!hasSetStrategy) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"PLSP.start(): Setting self as ReadyStrategy"_j);

        npc(localNode)->setReadyStrategy(this);
        hasSetStrategy = true;
        npc(localNode)->addLeafSetListener(this);
        isReady();
    }
}

void rice::pastry::standard::PeriodicLeafSetProtocol::stop()
{
    if(hasSetStrategy) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"PLSP.start(): Removing self as ReadyStrategy"_j);

        hasSetStrategy = false;
        npc(localNode)->deleteLeafSetListener(this);
    }
}

void rice::pastry::standard::PeriodicLeafSetProtocol::nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added)
{
    auto newLeft = npc(leafSet)->get(-int32_t(1));
    if(newLeft != nullptr && (lastLeft != newLeft)) {
        lastLeft = newLeft;
        sendBLS(lastLeft, true);
    }
    auto newRight = npc(leafSet)->get(1);
    if(newRight != nullptr && (lastRight != newRight)) {
        lastRight = newRight;
        sendBLS(lastRight, true);
    }
}

void rice::pastry::standard::PeriodicLeafSetProtocol::setReady(bool r)
{
    if(ready != r) {
        {
            synchronized synchronized_0(thePastryNode);
            {
                ready = r;
            }
        }
        npc(thePastryNode)->notifyReadyObservers();
    }
}

bool rice::pastry::standard::PeriodicLeafSetProtocol::isReady()
{
    auto shouldBeReady = this->shouldBeReady();
    if(shouldBeReady != ready) {
        npc(thePastryNode)->setReady(shouldBeReady);
    }
    return shouldBeReady;
}

bool rice::pastry::standard::PeriodicLeafSetProtocol::shouldBeReady()
{
    auto left = npc(leafSet)->get(-int32_t(1));
    auto right = npc(leafSet)->get(1);
    auto ret = true;
    if(!hasLease(left)) {
        ret = false;
        sendBLS(left, true);
    }
    if(!hasLease(right)) {
        ret = false;
        sendBLS(right, true);
    }
    return ret;
}

bool rice::pastry::standard::PeriodicLeafSetProtocol::hasLease(::rice::pastry::NodeHandle* nh)
{
    auto curTime = npc(timeSource)->currentTimeMillis();
    auto leaseOffset = curTime - LEASE_PERIOD;
    if(nh != nullptr) {
        auto time = java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Long* >(npc(lastTimeReceivedBLS)->get(nh)));
        if(time == nullptr || (npc(time)->longValue() < leaseOffset)) {
            return false;
        }
    }
    return true;
}

bool rice::pastry::standard::PeriodicLeafSetProtocol::sendBLS(::rice::pastry::NodeHandle* sendTo, bool checkLiveness)
{
    auto time = java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Long* >(npc(lastTimeSentBLS)->get(sendTo)));
    auto currentTime = npc(timeSource)->currentTimeMillis();
    if(time == nullptr || (npc(time)->longValue() < (currentTime - BLS_THROTTLE))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"PeriodicLeafSetProtocol: Checking liveness on neighbor:"_j)->append(static_cast< ::java::lang::Object* >(sendTo))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(time))
                ->append(u" cl:"_j)
                ->append(checkLiveness)->toString());

        npc(lastTimeSentBLS)->put(sendTo, new ::java::lang::Long(currentTime));
        npc(thePastryNode)->send(sendTo, new ::rice::pastry::leafset::BroadcastLeafSet(localHandle, leafSet, ::rice::pastry::leafset::BroadcastLeafSet::Update, int32_t(0)), nullptr, options);
        npc(thePastryNode)->send(sendTo, new ::rice::pastry::leafset::RequestLeafSet(localHandle, currentTime), nullptr, options);
        if(checkLiveness) {
            npc(sendTo)->checkLiveness();
        }
        return true;
    }
    return false;
}

void rice::pastry::standard::PeriodicLeafSetProtocol::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    throw new ::java::lang::RuntimeException(u"Should not be called."_j);
}

bool rice::pastry::standard::PeriodicLeafSetProtocol::deliverWhenNotReady()
{
    return true;
}

void rice::pastry::standard::PeriodicLeafSetProtocol::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"PLSP: destroy() called"_j);

    destroyed = true;
    if(pingNeighborMessage != nullptr)
        npc(pingNeighborMessage)->cancel();

    pingNeighborMessage = nullptr;
    lastLeft = nullptr;
    lastRight = nullptr;
    npc(lastTimeReceivedBLS)->clear();
    npc(lastTimeRenewedLease)->clear();
    npc(lastTimeSentBLS)->clear();
}

void rice::pastry::standard::PeriodicLeafSetProtocol::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    super::leafSetChange(nh, wasAdded);
    if(wasAdded) {
        npc(nh)->addObserver(this, 50);
        if(!npc(nh)->isAlive()) {
            removeFromLeafsetIfPossible(nh);
        }
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Removed "_j)->append(static_cast< ::java::lang::Object* >(nh))
                ->append(u" from the LeafSet."_j)->toString());

        npc(nh)->deleteObserver(static_cast< ::java::util::Observer* >(this));
    }
}

void rice::pastry::standard::PeriodicLeafSetProtocol::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    if(destroyed)
        return;

    if(dynamic_cast< ::rice::pastry::NodeHandle* >(o) != nullptr) {
        if(arg == static_cast< ::java::lang::Object* >(::rice::pastry::NodeHandle::DECLARED_DEAD())) {
            removeFromLeafsetIfPossible(java_cast< ::rice::pastry::NodeHandle* >(o));
        }
        return;
    }
    if(dynamic_cast< ::rice::pastry::PastryNode* >(o) != nullptr) {
        if(dynamic_cast< ::java::lang::Boolean* >(arg) != nullptr) {
            auto rdy = java_cast< ::java::lang::Boolean* >(arg);
            if(npc(rdy)->equals(static_cast< ::java::lang::Object* >(::java::lang::Boolean::TRUE()))) {
                npc(localNode)->deleteObserver(this);
                start();
            }
        }
    }
}

void rice::pastry::standard::PeriodicLeafSetProtocol::removeFromLeafsetIfPossible(::rice::pastry::NodeHandle* nh)
{
    if(npc(nh)->isAlive())
        return;

    auto l_time = java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Long* >(npc(lastTimeRenewedLease)->get(nh)));
    if(l_time == nullptr) {
        npc(leafSet)->remove(nh);
    } else {
        auto leaseExpiration = npc(l_time)->longValue() + LEASE_PERIOD;
        auto now = npc(timeSource)->currentTimeMillis();
        if(leaseExpiration > now) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Removing "_j)->append(static_cast< ::java::lang::Object* >(nh))
                    ->append(u" from leafset later."_j)
                    ->append((leaseExpiration - now))->toString());

            npc(npc(npc(npc(thePastryNode)->getEnvironment())->getSelectorManager())->getTimer())->schedule(new PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1(this, nh), leaseExpiration - now);
        } else {
            npc(leafSet)->remove(nh);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::PeriodicLeafSetProtocol::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.PeriodicLeafSetProtocol", 44);
    return c;
}

java::lang::Class* rice::pastry::standard::PeriodicLeafSetProtocol::getClass0()
{
    return class_();
}

