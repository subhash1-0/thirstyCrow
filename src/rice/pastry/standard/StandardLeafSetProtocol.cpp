// Generated from /pastry-2.1/src/rice/pastry/standard/StandardLeafSetProtocol.java
#include <rice/pastry/standard/StandardLeafSetProtocol.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Error.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Observer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdSet.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/BroadcastLeafSet.hpp>
#include <rice/pastry/leafset/InitiateLeafSetMaintenance.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/LeafSetProtocolAddress.hpp>
#include <rice/pastry/leafset/RequestLeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>

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

rice::pastry::standard::StandardLeafSetProtocol::StandardLeafSetProtocol(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardLeafSetProtocol::StandardLeafSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt) 
    : StandardLeafSetProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,local,ls,rt);
}

void rice::pastry::standard::StandardLeafSetProtocol::init()
{
    cachedSet = nullptr;
}

constexpr bool rice::pastry::standard::StandardLeafSetProtocol::failstop;

void rice::pastry::standard::StandardLeafSetProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt)
{
    super::ctor(ln, ::rice::pastry::leafset::LeafSetProtocolAddress::getCode());
    init();
    leafSet = ls;
    auto i = npc(npc(leafSet)->asList())->iterator();
    while (npc(i)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next()));
        npc(nh)->addObserver(static_cast< ::java::util::Observer* >(this));
    }
    cachedSet = new ::java::util::HashSet(npc(leafSet)->maxSize() * int32_t(2));
    routeTable = rt;
    logger = npc(npc(npc(ln)->getEnvironment())->getLogManager())->getLogger(getClass(), nullptr);
}

void rice::pastry::standard::StandardLeafSetProtocol::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    if(dynamic_cast< ::rice::pastry::leafset::BroadcastLeafSet* >(msg) != nullptr) {
        auto bls = java_cast< ::rice::pastry::leafset::BroadcastLeafSet* >(msg);
        auto type = npc(bls)->type();
        auto from = npc(bls)->from();
        auto remotels = npc(bls)->leafSet();
        auto changed = mergeLeafSet(remotels, from);
        if(type == ::rice::pastry::leafset::BroadcastLeafSet::JoinInitial) {
        }
        if(!failstop) {
            if(changed)
                broadcast();

            checkLeafSet(remotels, from, false);
            return;
        }
        if(type == ::rice::pastry::leafset::BroadcastLeafSet::JoinInitial)
            broadcast();

        if(type == ::rice::pastry::leafset::BroadcastLeafSet::Correction && changed)
            broadcast();

        checkLeafSet(remotels, from, true);
    } else if(dynamic_cast< ::rice::pastry::leafset::RequestLeafSet* >(msg) != nullptr) {
        auto rls = java_cast< ::rice::pastry::leafset::RequestLeafSet* >(msg);
        auto returnHandle = npc(rls)->returnHandle();
        if(npc(returnHandle)->isAlive()) {
            auto bls = new ::rice::pastry::leafset::BroadcastLeafSet(npc(thePastryNode)->getLocalHandle(), leafSet, ::rice::pastry::leafset::BroadcastLeafSet::Update, npc(rls)->getTimeStamp());
            npc(thePastryNode)->send(returnHandle, bls, nullptr, options);
        }
    } else if(dynamic_cast< ::rice::pastry::leafset::InitiateLeafSetMaintenance* >(msg) != nullptr) {
        maintainLeafSet();
    } else
        throw new ::java::lang::Error(u"message received is of unknown type"_j);
}

bool rice::pastry::standard::StandardLeafSetProtocol::checkLeafSet(::rice::pastry::leafset::LeafSet* remotels, ::rice::pastry::NodeHandle* from, bool notifyMissing)
{
    ::java::util::HashSet* insertedHandles;
    if(notifyMissing) {
        npc(cachedSet)->clear();
        insertedHandles = cachedSet;
    } else
        insertedHandles = nullptr;
    auto bl = new ::rice::pastry::leafset::BroadcastLeafSet(npc(thePastryNode)->getLocalHandle(), leafSet, ::rice::pastry::leafset::BroadcastLeafSet::Correction, int32_t(0));
    auto changed = npc(remotels)->merge(leafSet, npc(thePastryNode)->getLocalHandle(), nullptr, true, insertedHandles);
    if(changed) {
        npc(thePastryNode)->send(from, bl, nullptr, options);
        if(notifyMissing) {
            auto it = (new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(insertedHandles)))->iterator();
            while (npc(it)->hasNext()) {
                auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(it)->next()));
                npc(thePastryNode)->send(nh, bl, nullptr, options);
            }
        }
    }
    return changed;
}

bool rice::pastry::standard::StandardLeafSetProtocol::mergeLeafSet(::rice::pastry::leafset::LeafSet* remotels, ::rice::pastry::NodeHandle* from)
{
    return npc(leafSet)->merge(remotels, from, routeTable, false, nullptr);
}

void rice::pastry::standard::StandardLeafSetProtocol::broadcast()
{
    broadcast(::rice::pastry::leafset::BroadcastLeafSet::JoinAdvertise);
}

void rice::pastry::standard::StandardLeafSetProtocol::broadcast(int32_t type)
{
    auto bls = new ::rice::pastry::leafset::BroadcastLeafSet(npc(thePastryNode)->getLocalHandle(), leafSet, type, int32_t(0));
    auto cwSize = npc(leafSet)->cwSize();
    auto ccwSize = npc(leafSet)->ccwSize();
    auto sent = new ::rice::pastry::IdSet();
    for (auto i = -ccwSize; i <= cwSize; i++) {
        if(i == 0)
            continue;

        auto nh = npc(leafSet)->get(i);
        if(nh == nullptr || npc(nh)->isAlive() == false)
            continue;

        if(!npc(sent)->isMember(npc(nh)->getNodeId())) {
            npc(thePastryNode)->send(nh, bls, nullptr, options);
            npc(sent)->addMember(npc(nh)->getNodeId());
        }
    }
}

void rice::pastry::standard::StandardLeafSetProtocol::broadcast(::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::NodeHandle* from)
{
    auto bls = new ::rice::pastry::leafset::BroadcastLeafSet(npc(thePastryNode)->getLocalHandle(), leafSet, ::rice::pastry::leafset::BroadcastLeafSet::JoinAdvertise, int32_t(0));
    auto cwSize = npc(ls)->cwSize();
    auto ccwSize = npc(ls)->ccwSize();
    for (auto i = -ccwSize; i <= cwSize; i++) {
        ::rice::pastry::NodeHandle* nh;
        if(i == 0)
            nh = from;
        else
            nh = npc(ls)->get(i);
        if(nh == nullptr || npc(nh)->isAlive() == false)
            continue;

        npc(thePastryNode)->send(nh, bls, nullptr, options);
    }
}

void rice::pastry::standard::StandardLeafSetProtocol::maintainLeafSet()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"maintainLeafSet "_j)->append(static_cast< ::java::lang::Object* >(npc(npc(thePastryNode)->getLocalHandle())->getNodeId()))->toString());

    auto lostMembers = false;
    for (auto i = -npc(leafSet)->ccwSize(); i < 0; i++) {
        auto nh = npc(leafSet)->get(i);
        if(nh != nullptr && !npc(nh)->ping()) {
            npc(leafSet)->remove(nh);
            lostMembers = true;
        }
    }
    for (auto i = npc(leafSet)->cwSize(); i > 0; i--) {
        auto nh = npc(leafSet)->get(i);
        if(nh != nullptr && !npc(nh)->ping()) {
            npc(leafSet)->remove(nh);
            lostMembers = true;
        }
    }
    if(lostMembers || (npc(leafSet)->size() < npc(leafSet)->maxSize())) {
        requestLeafSet();
    }
}

void rice::pastry::standard::StandardLeafSetProtocol::requestLeafSet()
{
    auto rls = new ::rice::pastry::leafset::RequestLeafSet(npc(thePastryNode)->getLocalHandle(), npc(npc(npc(thePastryNode)->getEnvironment())->getTimeSource())->currentTimeMillis());
    auto cwSize = npc(leafSet)->cwSize();
    auto ccwSize = npc(leafSet)->ccwSize();
    auto allDead = true;
    for (auto i = -ccwSize; i < 0; i++) {
        auto handle = npc(leafSet)->get(i);
        if(handle != nullptr && npc(handle)->isAlive()) {
            npc(thePastryNode)->send(handle, rls, nullptr, options);
            allDead = false;
            break;
        }
    }
    if(allDead && npc(leafSet)->size() > 0)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Ring failure at"_j)->append(static_cast< ::java::lang::Object* >(npc(npc(thePastryNode)->getLocalHandle())->getNodeId()))
                ->append(u"all ccw leafset entries failed"_j)->toString());


    allDead = true;
    for (auto i = cwSize; i > 0; i--) {
        auto handle = npc(leafSet)->get(i);
        if(handle != nullptr && npc(handle)->isAlive()) {
            npc(thePastryNode)->send(handle, rls, nullptr, options);
            allDead = false;
            break;
        }
    }
    if(allDead && npc(leafSet)->size() > 0)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Ring failure at"_j)->append(static_cast< ::java::lang::Object* >(npc(npc(thePastryNode)->getLocalHandle())->getNodeId()))
                ->append(u"all cw leafset entries failed"_j)->toString());


}

bool rice::pastry::standard::StandardLeafSetProtocol::deliverWhenNotReady()
{
    return true;
}

void rice::pastry::standard::StandardLeafSetProtocol::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    super::leafSetChange(nh, wasAdded);
    if(wasAdded) {
        npc(nh)->addObserver(static_cast< ::java::util::Observer* >(this));
    } else {
        npc(nh)->deleteObserver(static_cast< ::java::util::Observer* >(this));
    }
}

void rice::pastry::standard::StandardLeafSetProtocol::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    if(arg == static_cast< ::java::lang::Object* >(::rice::pastry::NodeHandle::DECLARED_DEAD())) {
        npc(leafSet)->remove(java_cast< ::rice::pastry::NodeHandle* >(o));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardLeafSetProtocol::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardLeafSetProtocol", 44);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardLeafSetProtocol::getClass0()
{
    return class_();
}

