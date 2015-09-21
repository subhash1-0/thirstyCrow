// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java
#include <rice/pastry/standard/StandardJoinProtocol.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/pastry/ExponentialBackoffScheduledMessage.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/ScheduledMessage.hpp>
#include <rice/pastry/join/InitiateJoin.hpp>
#include <rice/pastry/join/JoinAddress.hpp>
#include <rice/pastry/join/JoinRequest.hpp>
#include <rice/pastry/leafset/BroadcastLeafSet.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/BroadcastRouteRow.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/StandardJoinProtocol_handleInitiateJoin_1.hpp>
#include <rice/pastry/standard/StandardJoinProtocol_handleIntermediateHop_2.hpp>
#include <rice/pastry/standard/StandardJoinProtocol_respondToJoiner_3.hpp>
#include <rice/pastry/standard/StandardJoinProtocol_SJPDeserializer.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
        } // routing
    } // pastry
} // rice

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

rice::pastry::standard::StandardJoinProtocol::StandardJoinProtocol(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardJoinProtocol::StandardJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls) 
    : StandardJoinProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,lh,rt,ls);
}

rice::pastry::standard::StandardJoinProtocol::StandardJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) 
    : StandardJoinProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,lh,rt,ls,md);
}

void rice::pastry::standard::StandardJoinProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls)
{
    ctor(ln, lh, rt, ls, nullptr);
}

void rice::pastry::standard::StandardJoinProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    super::ctor(ln, nullptr, ::rice::pastry::join::JoinAddress::getCode(), md == nullptr ? static_cast< ::rice::p2p::commonapi::rawserialization::MessageDeserializer* >(new StandardJoinProtocol_SJPDeserializer(ln)) : md);
    localHandle = lh;
    routeTable = rt;
    leafSet = ls;
}

int32_t rice::pastry::standard::StandardJoinProtocol::getAddress()
{
    return ::rice::pastry::join::JoinAddress::getCode();
}

void rice::pastry::standard::StandardJoinProtocol::initiateJoin(::java::util::Collection* bootstrap)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
        npc(logger)->log(::java::lang::StringBuilder().append(u"initiateJoin("_j)->append(static_cast< ::java::lang::Object* >(bootstrap))
            ->append(u")"_j)->toString());

    if(bootstrap == nullptr || npc(bootstrap)->isEmpty()) {
        npc(thePastryNode)->setReady();
    } else {
        joinEvent = new ::rice::pastry::ExponentialBackoffScheduledMessage(thePastryNode, new ::rice::pastry::join::InitiateJoin(bootstrap), npc(npc(npc(thePastryNode)->getEnvironment())->getSelectorManager())->getTimer(), int32_t(0), int32_t(2000), int32_t(2), int32_t(60000));
    }
}

void rice::pastry::standard::StandardJoinProtocol::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(dynamic_cast< ::rice::pastry::join::JoinRequest* >(msg) != nullptr) {
        auto jr = java_cast< ::rice::pastry::join::JoinRequest* >(msg);
        handleJoinRequest(jr);
    } else if(dynamic_cast< ::rice::pastry::routing::RouteMessage* >(msg) != nullptr) {
        auto rm = java_cast< ::rice::pastry::routing::RouteMessage* >(msg);
        handleIntermediateHop(rm);
    } else if(dynamic_cast< ::rice::pastry::join::InitiateJoin* >(msg) != nullptr) {
        auto ij = java_cast< ::rice::pastry::join::InitiateJoin* >(msg);
        handleInitiateJoin(ij);
    }
}

void rice::pastry::standard::StandardJoinProtocol::handleInitiateJoin(::rice::pastry::join::InitiateJoin* ij)
{
    auto const nh = npc(ij)->getHandle();
    if(nh == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"ERROR: Cannot join ring.  All bootstraps are faulty."_j)->append(static_cast< ::java::lang::Object* >(ij))->toString());

        npc(thePastryNode)->joinFailed(new ::rice::pastry::JoinFailedException(::java::lang::StringBuilder().append(u"Cannot join ring.  All bootstraps are faulty."_j)->append(static_cast< ::java::lang::Object* >(ij))->toString()));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"InitiateJoin attempting to join:"_j)->append(static_cast< ::java::lang::Object* >(nh))
                ->append(u" liveness:"_j)
                ->append(npc(nh)->getLiveness())->toString());

        getJoinRequest(nh, new StandardJoinProtocol_handleInitiateJoin_1(this, nh));
    }
}

void rice::pastry::standard::StandardJoinProtocol::getJoinRequest(::rice::pastry::NodeHandle* bootstrap, ::rice::Continuation* deliverJRToMe)
{
    auto jr = new ::rice::pastry::join::JoinRequest(localHandle, npc(npc(thePastryNode)->getRoutingTable())->baseBitLength(), npc(npc(npc(thePastryNode)->getEnvironment())->getTimeSource())->currentTimeMillis());
    npc(deliverJRToMe)->receiveResult(jr);
}

void rice::pastry::standard::StandardJoinProtocol::handleIntermediateHop(::rice::pastry::routing::RouteMessage* rm)
{
    try {
        auto jr = java_cast< ::rice::pastry::join::JoinRequest* >(npc(rm)->unwrap(deserializer));
        auto localId = npc(localHandle)->getNodeId();
        auto jh = npc(jr)->getHandle();
        auto nid = npc(jh)->getNodeId();
        if(!npc(jh)->equals(static_cast< ::java::lang::Object* >(localHandle))) {
            int32_t base = npc(npc(thePastryNode)->getRoutingTable())->baseBitLength();
            auto msdd = npc(localId)->indexOfMSDD(nid, base);
            auto last = npc(jr)->lastRow();
            for (auto i = last - int32_t(1); msdd > 0 && i >= msdd; i--) {
                auto row = npc(routeTable)->getRow(i);
                npc(jr)->pushRow(row);
            }
            npc(rm)->setRouteMessageNotification(new StandardJoinProtocol_handleIntermediateHop_2(this));
            npc(rm)->setTLOptions(getOptions(jr, npc(rm)->getTLOptions()));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Routing "_j)->append(static_cast< ::java::lang::Object* >(rm))->toString());

            npc(npc(thePastryNode)->getRouter())->route(rm);
        }
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->logException(u"StandardJoinProtocol.receiveMessage()"_j, ioe);

    }
}

void rice::pastry::standard::StandardJoinProtocol::handleJoinRequest(::rice::pastry::join::JoinRequest* jr)
{
    if(npc(jr)->accepted() == false) {
        respondToJoiner(jr);
    } else {
        completeJoin(jr);
    }
}

void rice::pastry::standard::StandardJoinProtocol::respondToJoiner(::rice::pastry::join::JoinRequest* jr)
{
    auto joiner = npc(jr)->getHandle();
    if(npc(thePastryNode)->isReady()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
            npc(logger)->log(::java::lang::StringBuilder().append(u"acceptJoin "_j)->append(static_cast< ::java::lang::Object* >(jr))->toString());

        npc(jr)->acceptJoin(localHandle, leafSet);
        npc(thePastryNode)->send(joiner, jr, new StandardJoinProtocol_respondToJoiner_3(this, jr), getOptions(jr, options));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"NOTE: Dropping incoming JoinRequest "_j)->append(static_cast< ::java::lang::Object* >(jr))
                ->append(u" because local node is not ready!"_j)->toString());

    }
}

java::util::Map* rice::pastry::standard::StandardJoinProtocol::getOptions(::rice::pastry::join::JoinRequest* jr, ::java::util::Map* existing)
{
    return existing;
}

void rice::pastry::standard::StandardJoinProtocol::completeJoin(::rice::pastry::join::JoinRequest* jr)
{
    auto jh = npc(jr)->getJoinHandle();
    if(npc(npc(jh)->getId())->equals(npc(localHandle)->getId()) && !npc(jh)->equals(static_cast< ::java::lang::Object* >(localHandle))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"NodeId collision, unable to join: "_j)->append(static_cast< ::java::lang::Object* >(localHandle))
                ->append(u":"_j)
                ->append(static_cast< ::java::lang::Object* >(jh))->toString());

    } else if(npc(jh)->isAlive() == true) {
        npc(routeTable)->put(jh);
        auto bls = new ::rice::pastry::leafset::BroadcastLeafSet(jh, npc(jr)->getLeafSet(), ::rice::pastry::leafset::BroadcastLeafSet::JoinInitial, int32_t(0));
        npc(thePastryNode)->receiveMessage(bls);
        broadcastRows(jr);
        setReady();
    }
}

void rice::pastry::standard::StandardJoinProtocol::setReady()
{
    if(joinEvent != nullptr)
        npc(joinEvent)->cancel();

    joinEvent = nullptr;
    npc(thePastryNode)->setReady();
}

void rice::pastry::standard::StandardJoinProtocol::broadcastRows(::rice::pastry::join::JoinRequest* jr)
{
    auto n = npc(jr)->numRows();
    for (auto i = npc(jr)->lastRow(); i < n; i++) {
        auto row = npc(jr)->getRow(i);
        if(row != nullptr) {
            auto brr = new ::rice::pastry::routing::BroadcastRouteRow(localHandle, row);
            npc(thePastryNode)->receiveMessage(brr);
        }
    }
    for (auto i = npc(jr)->lastRow(); i < n; i++) {
        auto row = npc(jr)->getRow(i);
        auto brr = new ::rice::pastry::routing::BroadcastRouteRow(localHandle, row);
        for (auto j = int32_t(0); j < npc(row)->length; j++) {
            auto rs = (*row)[j];
            if(rs == nullptr)
                continue;

            auto nh = npc(rs)->closestNode();
            if(nh != nullptr)
                npc(thePastryNode)->send(nh, brr, nullptr, options);

        }
    }
}

void rice::pastry::standard::StandardJoinProtocol::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    throw new ::java::lang::RuntimeException(u"Should not be called."_j);
}

bool rice::pastry::standard::StandardJoinProtocol::deliverWhenNotReady()
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardJoinProtocol::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardJoinProtocol", 41);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardJoinProtocol::getClass0()
{
    return class_();
}

