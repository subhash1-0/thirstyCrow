// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java
#include <rice/pastry/standard/ConsistentJoinProtocol.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Observer.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/util/TimerWeakHashMap.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/ReadyStrategy.hpp>
#include <rice/pastry/ScheduledMessage.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/standard/ConsistentJoinMsg.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol_ConsistentJoinProtocol_1.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol_CJPDeserializer.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol_FailedTime.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol_RequestFromEveryoneMsg.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>

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
rice::pastry::standard::ConsistentJoinProtocol::ConsistentJoinProtocol(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::ConsistentJoinProtocol::ConsistentJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy) 
    : ConsistentJoinProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,lh,rt,ls,nextReadyStrategy);
}

rice::pastry::standard::ConsistentJoinProtocol::ConsistentJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) 
    : ConsistentJoinProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,lh,rt,ls,nextReadyStrategy,md);
}

void rice::pastry::standard::ConsistentJoinProtocol::init()
{
    tryingToGoReady = false;
}

constexpr int32_t rice::pastry::standard::ConsistentJoinProtocol::MAX_NUM_TO_HEAR_FROM;

void rice::pastry::standard::ConsistentJoinProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy)
{
    ctor(ln, lh, rt, ls, nextReadyStrategy, nullptr);
}

void rice::pastry::standard::ConsistentJoinProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    super::ctor(ln, lh, rt, ls, md != nullptr ? md : static_cast< ::rice::p2p::commonapi::rawserialization::MessageDeserializer* >(new ConsistentJoinProtocol_CJPDeserializer(ln)));
    init();
    gotResponse = new ::rice::p2p::util::TimerWeakHashMap(npc(npc(npc(ln)->getEnvironment())->getSelectorManager())->getTimer(), int32_t(300000));
    failed = new ::java::util::HashMap();
    observing = new ::java::util::HashSet();
    this->nextReadyStrategy = nextReadyStrategy;
    npc(ls)->addNodeSetListener(this);
    npc(ln)->addObserver(this);
    auto p = npc(npc(ln)->getEnvironment())->getParameters();
    MAX_TIME_TO_BE_SCHEDULED = npc(p)->getInt(u"pastry_protocol_consistentJoin_max_time_to_be_scheduled"_j);
    RETRY_INTERVAL = npc(p)->getInt(u"pastry_protocol_consistentJoin_retry_interval"_j);
    failedNodeExpirationTime = npc(p)->getInt(u"pastry_protocol_consistentJoin_failedRetentionTime"_j);
    maxFailedEntries = npc(p)->getInt(u"pastry_protocol_consistentJoin_maxFailedToSend"_j);
    auto cleanupInterval = npc(p)->getInt(u"pastry_protocol_consistentJoin_cleanup_interval"_j);
    npc(npc(npc(ln)->getEnvironment())->getSelectorManager())->addLoopObserver(this);
    cleanupTask = new ConsistentJoinProtocol_ConsistentJoinProtocol_1(this);
    npc(npc(npc(ln)->getEnvironment())->getSelectorManager())->schedule(cleanupTask, static_cast< int64_t >(cleanupInterval), static_cast< int64_t >(cleanupInterval));
}

void rice::pastry::standard::ConsistentJoinProtocol::setReady()
{
    if(joinEvent != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"cancelling "_j)->append(static_cast< ::java::lang::Object* >(joinEvent))->toString());

        npc(joinEvent)->cancel();
        joinEvent = nullptr;
    }
    if(tryingToGoReady)
        return;

    tryingToGoReady = true;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"ConsistentJonProtocol.setReady()"_j);

    npc(gotResponse)->clear();
    auto i = npc(whoDoWeNeedAResponseFrom())->iterator();
    while (npc(i)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
        sendTheMessage(nh, false);
    }
    if(retryTask == nullptr)
        retryTask = npc(thePastryNode)->scheduleMsg(new ConsistentJoinProtocol_RequestFromEveryoneMsg(this, getAddress()), RETRY_INTERVAL, RETRY_INTERVAL);

}

void rice::pastry::standard::ConsistentJoinProtocol::addToLeafSet(::rice::pastry::NodeHandle* nh)
{
    npc(leafSet)->put(nh);
    if(!npc(observing)->contains(static_cast< ::java::lang::Object* >(nh))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"CJP observing "_j)->append(static_cast< ::java::lang::Object* >(nh))->toString());

        npc(nh)->addObserver(this, 40);
        npc(observing)->add(static_cast< ::java::lang::Object* >(nh));
    }
}

void rice::pastry::standard::ConsistentJoinProtocol::requestFromEveryoneWeHaventHeardFrom()
{
    if(npc(thePastryNode)->isReady()) {
        npc(retryTask)->cancel();
        retryTask = nullptr;
        return;
    }
    auto c = whoDoWeNeedAResponseFrom();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"CJP: timeout1, still waiting to hear from "_j)->append(npc(c)->size())
            ->append(u" nodes."_j)->toString());

    auto i = npc(c)->iterator();
    while (npc(i)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next()));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"CJP: timeout2, still waiting to hear from "_j)->append(static_cast< ::java::lang::Object* >(nh))->toString());

        try {
            sendTheMessage(nh, false);
        } catch (::java::lang::NullPointerException* npe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"npe, nh = "_j)->append(static_cast< ::java::lang::Object* >(nh))
                    ->append(u" c:"_j)
                    ->append(static_cast< ::java::lang::Object* >(c))->toString());

            throw npe;
        }
    }
}

void rice::pastry::standard::ConsistentJoinProtocol::otherNodesMaySuspectFaulty(int32_t timeNotScheduled)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->log(::java::lang::StringBuilder().append(u"WARNING: CJP.otherNodesMaySuspectFaulty("_j)->append(timeNotScheduled)
            ->append(u")"_j)->toString());

    npc(nextReadyStrategy)->stop();
    npc(thePastryNode)->setReadyStrategy(npc(thePastryNode)->getDefaultReadyStrategy());
    tryingToGoReady = false;
    npc(thePastryNode)->notifyReadyObservers();
    setReady();
}

java::util::Collection* rice::pastry::standard::ConsistentJoinProtocol::whoDoWeNeedAResponseFrom()
{
    auto ret = new ::java::util::HashSet();
    auto leftIndex = npc(leafSet)->ccwSize();
    if(leftIndex > MAX_NUM_TO_HEAR_FROM / int32_t(2))
        leftIndex = MAX_NUM_TO_HEAR_FROM / int32_t(2);

    auto rightIndex = npc(leafSet)->ccwSize();
    if(rightIndex > MAX_NUM_TO_HEAR_FROM / int32_t(2))
        rightIndex = MAX_NUM_TO_HEAR_FROM / int32_t(2);

    for (auto i = -leftIndex; i <= rightIndex; i++) {
        if(i != 0) {
            auto nh = npc(leafSet)->get(i);
            if(java_cast< ::java::lang::Object* >(npc(gotResponse)->get(nh)) == nullptr) {
                npc(ret)->add(static_cast< ::java::lang::Object* >(nh));
            }
        }
    }
    return ret;
}

void rice::pastry::standard::ConsistentJoinProtocol::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"CJP: receiveMessage("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

    if(dynamic_cast< ConsistentJoinMsg* >(msg) != nullptr) {
        auto cjm = java_cast< ConsistentJoinMsg* >(msg);
        auto j = npc(npc(cjm)->ls)->get(0);
        if(npc(j)->getLiveness() > ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_SUSPECTED) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"got message from dead node:"_j)->append(static_cast< ::java::lang::Object* >(msg))->toString());

            npc(j)->checkLiveness();
        }
        npc(failed)->remove(static_cast< ::java::lang::Object* >(j));
        addToLeafSet(j);
        auto it = npc(npc(cjm)->failed)->iterator();
        while (npc(it)->hasNext()) {
            auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(it)->next()));
            if(npc(leafSet)->member(nh)) {
                if(npc(nh)->getLiveness() == ::rice::pastry::NodeHandle::LIVENESS_DEAD) {
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"CJP: checking liveness2 on "_j)->append(static_cast< ::java::lang::Object* >(nh))->toString());

                    npc(nh)->checkLiveness();
                }
            }
        }
        auto lprime = npc(leafSet)->copy();
        for (auto i = -npc(npc(cjm)->ls)->ccwSize(); i <= npc(npc(cjm)->ls)->cwSize(); i++) {
            auto nh = npc(npc(cjm)->ls)->get(i);
            if(!npc(failed)->containsKey(static_cast< ::java::lang::Object* >(nh)) && npc(nh)->getLiveness() < ::rice::pastry::NodeHandle::LIVENESS_DEAD) {
                npc(lprime)->put(nh);
            }
        }
        auto addThese = new ::java::util::HashSet();
        for (auto i = -npc(lprime)->ccwSize(); i <= npc(lprime)->cwSize(); i++) {
            if(i != 0) {
                auto nh = npc(lprime)->get(i);
                if(!npc(leafSet)->member(nh)) {
                    npc(addThese)->add(static_cast< ::java::lang::Object* >(nh));
                }
            }
        }
        auto it2 = npc(addThese)->iterator();
        while (npc(it2)->hasNext()) {
            auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(it2)->next()));
            if(!npc(failed)->containsKey(static_cast< ::java::lang::Object* >(nh)) && npc(nh)->getLiveness() < ::rice::pastry::NodeHandle::LIVENESS_DEAD) {
                addToLeafSet(nh);
                sendTheMessage(nh, false);
            }
        }
        if(npc(cjm)->request) {
            sendTheMessage(j, true);
        }
        npc(gotResponse)->put(j, new ::java::lang::Object());
        if(tryingToGoReady)
            doneProbing();

    } else if(dynamic_cast< ConsistentJoinProtocol_RequestFromEveryoneMsg* >(msg) != nullptr) {
        requestFromEveryoneWeHaventHeardFrom();
    } else {
        super::receiveMessage(msg);
    }
}

void rice::pastry::standard::ConsistentJoinProtocol::doneProbing()
{
    auto leftIndex = npc(leafSet)->ccwSize();
    auto rightIndex = npc(leafSet)->cwSize();
    if(leftIndex > MAX_NUM_TO_HEAR_FROM / int32_t(2))
        leftIndex = MAX_NUM_TO_HEAR_FROM / int32_t(2);

    if(rightIndex > MAX_NUM_TO_HEAR_FROM / int32_t(2))
        rightIndex = MAX_NUM_TO_HEAR_FROM / int32_t(2);

    if(npc(leafSet)->isComplete() || ((leftIndex == MAX_NUM_TO_HEAR_FROM / int32_t(2)) && (rightIndex == MAX_NUM_TO_HEAR_FROM / int32_t(2)))) {
        auto toHearFrom = new ::java::util::ArrayList();
        auto seen = new ::java::util::HashSet();
        for (auto i = -leftIndex; i <= rightIndex; i++) {
            if(i != 0) {
                auto nh = npc(leafSet)->get(i);
                if(!npc(seen)->contains(static_cast< ::java::lang::Object* >(nh)) && (java_cast< ::java::lang::Object* >(npc(gotResponse)->get(nh)) == nullptr)) {
                    npc(toHearFrom)->add(static_cast< ::java::lang::Object* >(nh));
                }
                npc(seen)->add(static_cast< ::java::lang::Object* >(nh));
            }
        }
        if(npc(toHearFrom)->size() == 0) {
            if(!npc(thePastryNode)->isReady()) {
                if(nextReadyStrategy == nullptr) {
                    npc(thePastryNode)->setReady();
                } else {
                    npc(nextReadyStrategy)->start();
                }
                if(retryTask != nullptr) {
                    npc(retryTask)->cancel();
                    retryTask = nullptr;
                }
                tryingToGoReady = false;
            }
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
                auto toHearFromStr = u""_j;
                auto i = npc(toHearFrom)->iterator();
                while (npc(i)->hasNext()) {
                    auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next()));
                    toHearFromStr = ::java::lang::StringBuilder(toHearFromStr).append(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(nh))->append(u":"_j)
                        ->append(npc(nh)->getLiveness())
                        ->append(u","_j)->toString())->toString();
                }
                npc(logger)->log(::java::lang::StringBuilder().append(u"CJP: still need to hear from:"_j)->append(toHearFromStr)->toString());
            }
        }
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"CJP: LS is not complete: "_j)->append(static_cast< ::java::lang::Object* >(leafSet))->toString());

        ::rice::pastry::NodeHandle* left = nullptr;
        ::rice::pastry::NodeHandle* right = nullptr;
        {
            synchronized synchronized_0(leafSet);
            {
                auto index = -npc(leafSet)->ccwSize();
                if((index != 0) && index != -npc(leafSet)->maxSize() / int32_t(2)) {
                    left = npc(leafSet)->get(index);
                }
                index = npc(leafSet)->cwSize();
                if((index != 0) && index != npc(leafSet)->maxSize() / int32_t(2)) {
                    right = npc(leafSet)->get(index);
                }
            }
        }
        if(left != nullptr)
            sendTheMessage(left, true);

        if(right != nullptr)
            sendTheMessage(right, true);

    }
}

void rice::pastry::standard::ConsistentJoinProtocol::sendTheMessage(::rice::pastry::NodeHandle* nh, bool reply)
{
    if(!reply) {
        if(!tryingToGoReady)
            return;

    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"CJP:  sendTheMessage("_j)->append(static_cast< ::java::lang::Object* >(nh))
            ->append(u","_j)
            ->append(reply)
            ->append(u")"_j)->toString());

    ::java::util::HashSet* toSend;
    if(npc(failed)->size() < maxFailedEntries) {
        toSend = new ::java::util::HashSet(static_cast< ::java::util::Collection* >(npc(failed)->keySet()));
    } else {
        auto l = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(failed)->values()));
        ::java::util::Collections::sort(l);
        toSend = new ::java::util::HashSet();
        for (auto i = int32_t(0); i < maxFailedEntries; i++) {
            auto tf = java_cast< ConsistentJoinProtocol_FailedTime* >(java_cast< ConsistentJoinProtocol_FailedTime* >(npc(l)->get(i)));
            npc(toSend)->add(static_cast< ::java::lang::Object* >(npc(tf)->handle));
        }
    }
    npc(thePastryNode)->send(nh, new ConsistentJoinMsg(leafSet, toSend, !reply), nullptr, options);
}

void rice::pastry::standard::ConsistentJoinProtocol::nodeSetUpdate(::rice::pastry::NodeSetEventSource* set, ::rice::pastry::NodeHandle* handle, bool added)
{
    if(npc(thePastryNode)->isReady())
        return;

    if(added) {
        if(java_cast< ::java::lang::Object* >(npc(gotResponse)->get(handle)) == nullptr) {
            sendTheMessage(handle, false);
        }
    } else {
        doneProbing();
    }
    return;
}

void rice::pastry::standard::ConsistentJoinProtocol::update(::java::util::Observable* arg0, ::java::lang::Object* arg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"CJP: update("_j)->append(static_cast< ::java::lang::Object* >(arg0))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(arg))
            ->append(u")"_j)
            ->append(npc(npc(arg)->getClass())->getName())->toString());

    if(dynamic_cast< ::rice::pastry::NodeHandle* >(arg0) != nullptr) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(arg0);
        if((java_cast< ::java::lang::Integer* >(arg)) == ::rice::pastry::NodeHandle::DECLARED_DEAD()) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"CJP:"_j)->append(static_cast< ::java::lang::Object* >(arg0))
                    ->append(u" declared dead"_j)->toString());

            if(!npc(failed)->containsKey(static_cast< ::java::lang::Object* >(nh))) {
                npc(failed)->put(static_cast< ::java::lang::Object* >(nh), static_cast< ::java::lang::Object* >(new ConsistentJoinProtocol_FailedTime(nh, npc(npc(npc(thePastryNode)->getEnvironment())->getTimeSource())->currentTimeMillis())));
            }
            doneProbing();
        }
        if((java_cast< ::java::lang::Integer* >(arg)) == ::rice::pastry::NodeHandle::DECLARED_LIVE()) {
            npc(failed)->remove(static_cast< ::java::lang::Object* >(nh));
            if(!npc(thePastryNode)->isReady()) {
                if(npc(leafSet)->test(nh)) {
                    npc(leafSet)->put(nh);
                    sendTheMessage(nh, false);
                }
            }
        }
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->logException(u"update()"_j, new ::java::lang::Exception(u"Stack Trace"_j));

    }
}

int32_t rice::pastry::standard::ConsistentJoinProtocol::delayInterest()
{
    return MAX_TIME_TO_BE_SCHEDULED;
}

void rice::pastry::standard::ConsistentJoinProtocol::loopTime(int32_t loopTime)
{
    otherNodesMaySuspectFaulty(loopTime);
}

void rice::pastry::standard::ConsistentJoinProtocol::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"CJP: destroy() called"_j);

    npc(npc(npc(thePastryNode)->getEnvironment())->getSelectorManager())->removeLoopObserver(this);
    npc(cleanupTask)->cancel();
    auto it2 = npc(observing)->iterator();
    while (npc(it2)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(it2)->next()));
        npc(nh)->deleteObserver(static_cast< ::java::util::Observer* >(this));
        npc(it2)->remove();
    }
    npc(observing)->clear();
    observing = nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.ConsistentJoinProtocol", 43);
    return c;
}

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol::getClass0()
{
    return class_();
}

