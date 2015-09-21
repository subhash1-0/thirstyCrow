// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouteSetProtocol.java
#include <rice/pastry/standard/StandardRouteSetProtocol.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Error.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Observer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/BroadcastRouteRow.hpp>
#include <rice/pastry/routing/InitiateRouteSetMaintenance.hpp>
#include <rice/pastry/routing/RequestRouteRow.hpp>
#include <rice/pastry/routing/RouteProtocolAddress.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/StandardRouteSetProtocol_SRSPDeserializer.hpp>
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

rice::pastry::standard::StandardRouteSetProtocol::StandardRouteSetProtocol(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardRouteSetProtocol::StandardRouteSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt) 
    : StandardRouteSetProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,rt);
}

rice::pastry::standard::StandardRouteSetProtocol::StandardRouteSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) 
    : StandardRouteSetProtocol(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,rt,md);
}

void rice::pastry::standard::StandardRouteSetProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt)
{
    ctor(ln, rt, nullptr);
}

void rice::pastry::standard::StandardRouteSetProtocol::ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    super::ctor(ln, nullptr, ::rice::pastry::routing::RouteProtocolAddress::getCode(), md == nullptr ? static_cast< ::rice::p2p::commonapi::rawserialization::MessageDeserializer* >(new StandardRouteSetProtocol_SRSPDeserializer(ln)) : md);
    this->environmet = npc(ln)->getEnvironment();
    maxTrials = (int32_t(1) << npc(rt)->baseBitLength()) / int32_t(2);
    routeTable = rt;
    logger = npc(npc(environmet)->getLogManager())->getLogger(getClass(), nullptr);
}

void rice::pastry::standard::StandardRouteSetProtocol::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    if(dynamic_cast< ::rice::pastry::routing::BroadcastRouteRow* >(msg) != nullptr) {
        auto brr = java_cast< ::rice::pastry::routing::BroadcastRouteRow* >(msg);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER + int32_t(5))
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received "_j)->append(npc(brr)->toStringFull())->toString());

        auto row = npc(brr)->getRow();
        auto nh = npc(brr)->from();
        if(npc(nh)->isAlive())
            npc(routeTable)->put(nh);

        for (auto i = int32_t(0); i < npc(row)->length; i++) {
            auto rs = (*row)[i];
            for (auto j = int32_t(0); rs != nullptr && j < npc(rs)->size(); j++) {
                nh = npc(rs)->get(j);
                if(npc(nh)->isAlive() == false)
                    continue;

                npc(routeTable)->put(nh);
            }
        }
    } else if(dynamic_cast< ::rice::pastry::routing::RequestRouteRow* >(msg) != nullptr) {
        auto rrr = java_cast< ::rice::pastry::routing::RequestRouteRow* >(msg);
        int32_t reqRow = npc(rrr)->getRow();
        auto nh = npc(rrr)->returnHandle();
        auto row = npc(routeTable)->getRow(reqRow);
        auto brr = new ::rice::pastry::routing::BroadcastRouteRow(npc(thePastryNode)->getLocalHandle(), row);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER + int32_t(5))
            npc(logger)->log(::java::lang::StringBuilder().append(u"Responding to "_j)->append(static_cast< ::java::lang::Object* >(rrr))
                ->append(u" with "_j)
                ->append(npc(brr)->toStringFull())->toString());

        npc(thePastryNode)->send(nh, brr, nullptr, options);
    } else if(dynamic_cast< ::rice::pastry::routing::InitiateRouteSetMaintenance* >(msg) != nullptr) {
        maintainRouteSet();
    } else
        throw new ::java::lang::Error(u"StandardRouteSetProtocol: received message is of unknown type"_j);
}

void rice::pastry::standard::StandardRouteSetProtocol::maintainRouteSet()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"maintainRouteSet "_j)->append(static_cast< ::java::lang::Object* >(npc(npc(thePastryNode)->getLocalHandle())->getNodeId()))->toString());

    for (auto i = static_cast< int16_t >((npc(routeTable)->numRows() - int32_t(1))); i >= 0; i--) {
        auto row = npc(routeTable)->getRow(i);
        auto brr = new ::rice::pastry::routing::BroadcastRouteRow(npc(thePastryNode)->getLocalHandle(), row);
        auto rrr = new ::rice::pastry::routing::RequestRouteRow(npc(thePastryNode)->getLocalHandle(), i);
        auto myCol = npc(npc(npc(thePastryNode)->getLocalHandle())->getNodeId())->getDigit(i, npc(routeTable)->baseBitLength());
        int32_t j;
        for (j = 0; j < maxTrials; j++) {
            auto col = npc(npc(environmet)->getRandomSource())->nextInt(npc(routeTable)->numColumns());
            if(col == myCol)
                continue;

            auto rs = (*row)[col];
            if(rs != nullptr && npc(rs)->size() > 0) {
                ::rice::pastry::NodeHandle* nh;
                nh = npc(rs)->closestNode(10);
                if(!npc(nh)->isAlive()) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"found dead node in table:"_j)->append(static_cast< ::java::lang::Object* >(nh))->toString());

                    npc(rs)->remove(nh);
                    break;
                }
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"swapping with "_j)->append((i + int32_t(1)))
                        ->append(u"/"_j)
                        ->append(npc(routeTable)->numRows())
                        ->append(u" "_j)
                        ->append((j + int32_t(1)))
                        ->append(u"/"_j)
                        ->append(maxTrials)
                        ->append(u":"_j)
                        ->append(static_cast< ::java::lang::Object* >(nh))->toString());

                npc(thePastryNode)->send(nh, brr, nullptr, options);
                npc(thePastryNode)->send(nh, rrr, nullptr, options);
                break;
            }
        }
        if(j == maxTrials)
            break;

    }
}

bool rice::pastry::standard::StandardRouteSetProtocol::deliverWhenNotReady()
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouteSetProtocol::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardRouteSetProtocol", 45);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardRouteSetProtocol::getClass0()
{
    return class_();
}

