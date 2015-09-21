// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java
#include <rice/pastry/standard/StandardRouter.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Error.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/NoRouteToHostException.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observer.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/exception/AppNotRegisteredException.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/messaging/MessageDispatch.hpp>
#include <rice/pastry/routing/BroadcastRouteRow.hpp>
#include <rice/pastry/routing/NoLegalRouteToMakeProgressException.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RouterAddress.hpp>
#include <rice/pastry/routing/RouterStrategy.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/standard/StandardRouter_getBestRoutingCandidates_4.hpp>
#include <rice/pastry/standard/StandardRouter_StandardRouter_1.hpp>
#include <rice/pastry/standard/StandardRouter_route_2.hpp>
#include <rice/pastry/standard/StandardRouter_sendTheMessage_3.hpp>
#include <rice/pastry/standard/StandardRouter_AliveRouterStrategy.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>
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
rice::pastry::standard::StandardRouter::StandardRouter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardRouter::StandardRouter(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch) 
    : StandardRouter(*static_cast< ::default_init_tag* >(0))
{
    ctor(thePastryNode,dispatch);
}

rice::pastry::standard::StandardRouter::StandardRouter(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy) 
    : StandardRouter(*static_cast< ::default_init_tag* >(0))
{
    ctor(thePastryNode,dispatch,strategy);
}

void rice::pastry::standard::StandardRouter::init()
{
    ROUTE_TABLE_PATCH_THROTTLE = int32_t(5000);
    lastTimeSentRouteTablePatch = new ::java::util::HashMap();
}

void rice::pastry::standard::StandardRouter::ctor(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch)
{
    ctor(thePastryNode, dispatch, new StandardRouter_AliveRouterStrategy());
}

void rice::pastry::standard::StandardRouter::ctor(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy)
{
    super::ctor(thePastryNode, nullptr, ::rice::pastry::routing::RouterAddress::getCode(), new StandardRouter_StandardRouter_1(this, thePastryNode));
    init();
    this->dispatch = dispatch;
    this->routerStrategy = strategy;
    if(routerStrategy == nullptr) {
        routerStrategy = new StandardRouter_AliveRouterStrategy();
    }
}

void rice::pastry::standard::StandardRouter::setRouterStrategy(::rice::pastry::routing::RouterStrategy* strategy)
{
    this->routerStrategy = strategy;
}

void rice::pastry::standard::StandardRouter::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"receiveMessage("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

    if(dynamic_cast< ::rice::pastry::routing::RouteMessage* >(msg) != nullptr) {
        route(java_cast< ::rice::pastry::routing::RouteMessage* >(msg));
    } else {
        throw new ::java::lang::Error(::java::lang::StringBuilder().append(u"message "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" bounced at StandardRouter"_j)->toString());
    }
}

void rice::pastry::standard::StandardRouter::route(::rice::pastry::routing::RouteMessage* rm)
{
    if(!npc(npc(npc(thePastryNode)->getEnvironment())->getSelectorManager())->isSelectorThread()) {
        npc(npc(npc(thePastryNode)->getEnvironment())->getSelectorManager())->invoke(new StandardRouter_route_2(this, rm));
        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"route("_j)->append(static_cast< ::java::lang::Object* >(rm))
            ->append(u")"_j)->toString());

    if(routeMessage(rm) == false)
        receiveRouteMessage(rm);

}

bool rice::pastry::standard::StandardRouter::routeMessage(::rice::pastry::routing::RouteMessage* rm)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"routeMessage("_j)->append(static_cast< ::java::lang::Object* >(rm))
            ->append(u")"_j)->toString());

    if(npc(rm)->getNextHop() == nullptr)
        return false;

    npc(rm)->setSender(npc(thePastryNode)->getLocalHandle());
    auto handle = npc(rm)->getNextHop();
    npc(rm)->setNextHop(nullptr);
    npc(rm)->setPrevNode(npc(thePastryNode)->getLocalHandle());
    if(npc(npc(thePastryNode)->getLocalHandle())->equals(static_cast< ::java::lang::Object* >(handle))) {
        if(npc(rm)->getDestinationHandle() != nullptr && !npc(npc(rm)->getDestinationHandle())->equals(static_cast< ::java::lang::Object* >(npc(thePastryNode)->getLocalHandle()))) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Message "_j)->append(static_cast< ::java::lang::Object* >(rm))
                    ->append(u" has destination "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(rm)->getDestinationHandle()))
                    ->append(u" but I'm the root of the id.  Dropping.  This could happen if the destination has died while the route message was in transit, or if the local node does not yet have logging state because it is boostrapping."_j)->toString());

            npc(rm)->sendFailed(new ::java::net::NoRouteToHostException(npc(npc(rm)->getDestinationHandle())->toString()));
            return true;
        }
        npc(thePastryNode)->receiveMessage(npc(rm)->internalMsg);
        npc(rm)->sendSuccess(npc(thePastryNode)->getLocalHandle());
    } else {
        sendTheMessage(rm, handle);
    }
    return true;
}

void rice::pastry::standard::StandardRouter::sendTheMessage(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendTheMessage("_j)->append(static_cast< ::java::lang::Object* >(rm))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u")"_j)->toString());

    npc(rm)->setTLCancellable(npc(thePastryNode)->send(handle, rm, new StandardRouter_sendTheMessage_3(this, rm, handle), npc(rm)->getTLOptions()));
}

void rice::pastry::standard::StandardRouter::receiveRouteMessage(::rice::pastry::routing::RouteMessage* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"receiveRouteMessage("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

    auto target = npc(msg)->getTarget();
    if(target == nullptr)
        target = npc(thePastryNode)->getNodeId();

    auto cwSize = npc(npc(thePastryNode)->getLeafSet())->cwSize();
    auto ccwSize = npc(npc(thePastryNode)->getLeafSet())->ccwSize();
    auto lsPos = npc(npc(thePastryNode)->getLeafSet())->mostSimilar(target);
    if(lsPos == 0) {
        npc(msg)->setNextHop(npc(thePastryNode)->getLocalHandle());
    } else {
        npc(npc(msg)->getOptions())->setRerouteIfSuspected(true);
        auto i = getBestRoutingCandidates(target);
        auto nextHop = npc(routerStrategy)->pickNextHop(msg, i);
        if(nextHop == nullptr) {
            npc(msg)->sendFailed(new ::rice::pastry::routing::NoLegalRouteToMakeProgressException(target));
            return;
        }
        npc(msg)->setNextHop(nextHop);
    }
    checkForRouteTableHole(msg, npc(msg)->getNextHop());
    npc(msg)->setPrevNode(npc(thePastryNode)->getLocalHandle());
    deliverToApplication(msg);
}

java::util::Iterator* rice::pastry::standard::StandardRouter::getBestRoutingCandidates(::rice::pastry::Id* target)
{
    auto cwSize = npc(npc(thePastryNode)->getLeafSet())->cwSize();
    auto ccwSize = npc(npc(thePastryNode)->getLeafSet())->ccwSize();
    auto lsPos = npc(npc(thePastryNode)->getLeafSet())->mostSimilar(target);
    if(lsPos == 0) {
        return npc(::java::util::Collections::singleton(npc(thePastryNode)->getLocalHandle()))->iterator();
    }
    auto leafSetOnly = false;
    if((lsPos > 0 && (lsPos < cwSize || !npc(npc(npc(npc(thePastryNode)->getLeafSet())->get(lsPos))->getNodeId())->clockwise(target))) || (lsPos < 0 && (-lsPos < ccwSize || npc(npc(npc(npc(thePastryNode)->getLeafSet())->get(lsPos))->getNodeId())->clockwise(target)))) {
        leafSetOnly = true;
    }
    return getBestRoutingCandidates(target, lsPos, leafSetOnly);
}

java::util::Iterator* rice::pastry::standard::StandardRouter::getBestRoutingCandidates(::rice::pastry::Id* target, int32_t lsPos, bool leafSetOnly)
{
    if(leafSetOnly) {
        return npc(getLSCollection(lsPos))->iterator();
    }
    return new StandardRouter_getBestRoutingCandidates_4(this, target, lsPos);
}

java::util::ArrayList* rice::pastry::standard::StandardRouter::getLSCollection(int32_t lsPos)
{
    auto lsCollection = new ::java::util::ArrayList();
    if(lsPos > 0) {
        for (auto i = lsPos; i > 0; i--) {
            auto temp = npc(npc(thePastryNode)->getLeafSet())->get(i);
            npc(lsCollection)->add(static_cast< ::java::lang::Object* >(temp));
        }
    } else {
        for (auto i = lsPos; i < 0; i++) {
            auto temp = npc(npc(thePastryNode)->getLeafSet())->get(i);
            npc(lsCollection)->add(static_cast< ::java::lang::Object* >(temp));
        }
    }
    return lsCollection;
}

void rice::pastry::standard::StandardRouter::deliverToApplication(::rice::pastry::routing::RouteMessage* msg)
{
    auto appl = npc(dispatch)->getDestinationByAddress(npc(msg)->getAuxAddress());
    if(appl == nullptr) {
        if(npc(msg)->sendFailed(new ::rice::p2p::commonapi::exception::AppNotRegisteredException(npc(msg)->getAuxAddress()))) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping message "_j)->append(static_cast< ::java::lang::Object* >(msg))
                    ->append(u" because the application address "_j)
                    ->append(npc(msg)->getAuxAddress())
                    ->append(u" is unknown."_j)->toString());

        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping message "_j)->append(static_cast< ::java::lang::Object* >(msg))
                    ->append(u" because the application address "_j)
                    ->append(npc(msg)->getAuxAddress())
                    ->append(u" is unknown."_j)->toString());

        }
        return;
    }
    npc(appl)->receiveMessage(msg);
}

void rice::pastry::standard::StandardRouter::checkForRouteTableHole(::rice::pastry::routing::RouteMessage* msg, ::rice::pastry::NodeHandle* handle)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"checkForRouteTableHole("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u")"_j)->toString());

    auto prevNode = npc(msg)->getPrevNode();
    if(prevNode == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"No prevNode defined in "_j)->append(static_cast< ::java::lang::Object* >(msg))->toString());

        return;
    }
    if(npc(prevNode)->equals(static_cast< ::java::lang::Object* >(getNodeHandle()))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"prevNode is me in "_j)->append(static_cast< ::java::lang::Object* >(msg))->toString());

        return;
    }
    auto ls = npc(thePastryNode)->getLeafSet();
    if(npc(ls)->overlaps())
        return;

    if(npc(ls)->member(prevNode)) {
        auto index = npc(ls)->getIndex(prevNode);
        if((index == npc(ls)->cwSize()) || (index == -npc(ls)->ccwSize())) {
        } else {
            return;
        }
    }
    auto prevId = npc(prevNode)->getNodeId();
    auto key = npc(msg)->getTarget();
    auto diffDigit = npc(prevId)->indexOfMSDD(key, npc(npc(thePastryNode)->getRoutingTable())->baseBitLength());
    if(diffDigit >= 0 && diffDigit == npc(npc(thePastryNode)->getNodeId())->indexOfMSDD(key, npc(npc(thePastryNode)->getRoutingTable())->baseBitLength())) {
        {
            synchronized synchronized_0(lastTimeSentRouteTablePatch);
            {
                if(npc(lastTimeSentRouteTablePatch)->containsKey(prevNode)) {
                    int64_t lastTime = (npc(java_cast< ::java::lang::Long* >(npc(lastTimeSentRouteTablePatch)->get(prevNode))))->longValue();
                    if(lastTime > (npc(npc(npc(thePastryNode)->getEnvironment())->getTimeSource())->currentTimeMillis() - ROUTE_TABLE_PATCH_THROTTLE)) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"not sending route table patch to "_j)->append(static_cast< ::java::lang::Object* >(prevNode))
                                ->append(u" because throttled.  Last Time:"_j)
                                ->append(lastTime)->toString());

                        return;
                    }
                }
                npc(lastTimeSentRouteTablePatch)->put(prevNode, ::java::lang::Long::valueOf(npc(npc(npc(thePastryNode)->getEnvironment())->getTimeSource())->currentTimeMillis()));
            }
        }
        auto row = npc(npc(thePastryNode)->getRoutingTable())->getRow(diffDigit);
        auto brr = new ::rice::pastry::routing::BroadcastRouteRow(npc(thePastryNode)->getLocalHandle(), row);
        if(npc(prevNode)->isAlive()) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
                npc(logger)->log(::java::lang::StringBuilder().append(u"Found hole in "_j)->append(static_cast< ::java::lang::Object* >(prevNode))
                    ->append(u"'s routing table. Sending "_j)
                    ->append(npc(brr)->toStringFull())->toString());
            }
            npc(thePastryNode)->send(prevNode, brr, nullptr, options);
        }
    }
}

bool rice::pastry::standard::StandardRouter::deliverWhenNotReady()
{
    return true;
}

void rice::pastry::standard::StandardRouter::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    throw new ::java::lang::RuntimeException(u"Should not be called."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardRouter", 35);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardRouter::getClass0()
{
    return class_();
}

