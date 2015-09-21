// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java
#include <rice/pastry/commonapi/PastryEndpoint.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observable.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/Destructable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/ScheduledMessage.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/commonapi/PastryEndpoint_networkNeighbors_3.hpp>
#include <rice/pastry/commonapi/PastryEndpoint_routeHelper_1.hpp>
#include <rice/pastry/commonapi/PastryEndpoint_routeHelper_2.hpp>
#include <rice/pastry/commonapi/PastryEndpoint_PEDeserializer.hpp>
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/standard/StandardAddress.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi
    } // p2p
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

rice::pastry::commonapi::PastryEndpoint::PastryEndpoint(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::commonapi::PastryEndpoint::PastryEndpoint(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, bool register_) 
    : PastryEndpoint(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,application,instance,register_);
}

rice::pastry::commonapi::PastryEndpoint::PastryEndpoint(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, int32_t address, bool register_) 
    : PastryEndpoint(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,application,instance,address,register_);
}

void rice::pastry::commonapi::PastryEndpoint::init()
{
    consistentRouting = true;
}

void rice::pastry::commonapi::PastryEndpoint::ctor(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, bool register_)
{
    ctor(pn, application, instance, int32_t(0), register_);
}

void rice::pastry::commonapi::PastryEndpoint::ctor(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, int32_t address, bool register_)
{
    super::ctor(pn, instance, address == 0 ? ::rice::pastry::standard::StandardAddress::getAddress(npc(application)->getClass(), instance, npc(pn)->getEnvironment()) : address, nullptr, npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(npc(application)->getClass(), instance == nullptr ? u"-endpoint"_j : ::java::lang::StringBuilder().append(instance)->append(u"-endpoint"_j)->toString()));
    init();
    appDeserializer = deserializer;
    deserializer = new PastryEndpoint_PEDeserializer(this);
    this->application = application;
    if(register_)
        static_cast< ::rice::pastry::client::PastryAppl* >(this)->register_();

}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryEndpoint::getId()
{
    return npc(thePastryNode)->getNodeId();
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::commonapi::PastryEndpoint::route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::NodeHandle* hint)
{
    return route(key, msg, hint, static_cast< ::rice::p2p::commonapi::DeliveryNotification* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::commonapi::PastryEndpoint::route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe)
{
    return route(key, msg, hint, deliverAckToMe, static_cast< ::java::util::Map* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::commonapi::PastryEndpoint::route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] route "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(key))->toString());

    auto pm = new PastryEndpointMessage(this->getAddress(), msg, npc(thePastryNode)->getLocalHandle());
    return routeHelper(key, pm, hint, deliverAckToMe, options);
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::commonapi::PastryEndpoint::route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::rawserialization::RawMessage* msg, ::rice::p2p::commonapi::NodeHandle* hint)
{
    return route(key, msg, hint, static_cast< ::rice::p2p::commonapi::DeliveryNotification* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::commonapi::PastryEndpoint::route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::rawserialization::RawMessage* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe)
{
    return route(key, msg, hint, deliverAckToMe, static_cast< ::java::util::Map* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::commonapi::PastryEndpoint::route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::rawserialization::RawMessage* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] route "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(key))->toString());

    auto pm = new PastryEndpointMessage(this->getAddress(), msg, npc(thePastryNode)->getLocalHandle());
    return routeHelper(key, pm, hint, deliverAckToMe, options);
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::commonapi::PastryEndpoint::routeHelper(::rice::p2p::commonapi::Id* key, PastryEndpointMessage* pm, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    if(options == nullptr)
        options = java_cast< ::java::util::Map* >(this->options);

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"routeHelper("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(pm))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(hint))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u").init()"_j)->toString());

    if((key == nullptr) && (hint == nullptr)) {
        throw new ::java::lang::IllegalArgumentException(u"key and hint are null!"_j);
    }
    auto noKey = false;
    if(key == nullptr) {
        noKey = true;
        key = npc(hint)->getId();
    }
    auto const rm = new ::rice::pastry::routing::RouteMessage(java_cast< ::rice::pastry::Id* >(key), static_cast< ::rice::pastry::messaging::Message* >(pm), java_cast< ::rice::pastry::NodeHandle* >(hint), static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    npc(rm)->setPrevNode(npc(thePastryNode)->getLocalHandle());
    if(noKey) {
        npc(npc(rm)->getOptions())->setMultipleHopsAllowed(false);
        npc(rm)->setDestinationHandle(java_cast< ::rice::pastry::NodeHandle* >(hint));
    }
    auto const final_key = key;
    ::rice::p2p::commonapi::MessageReceipt* const ret = new PastryEndpoint_routeHelper_1(this, final_key, pm, hint, deliverAckToMe, rm);
    if((deliverAckToMe != nullptr) || (npc(logger)->level <= ::rice::environment::logging::Logger::FINE)) {
        npc(rm)->setRouteMessageNotification(new PastryEndpoint_routeHelper_2(this, final_key, pm, hint, deliverAckToMe, ret));
    }
    npc(rm)->setTLOptions(::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, ::org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY(), ::java::lang::Integer::valueOf(npc(pm)->getPriority())));
    npc(npc(thePastryNode)->getRouter())->route(rm);
    return ret;
}

rice::p2p::commonapi::CancellableTask* rice::pastry::commonapi::PastryEndpoint::scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay)
{
    auto pm = new PastryEndpointMessage(this->getAddress(), message, npc(thePastryNode)->getLocalHandle());
    return npc(thePastryNode)->scheduleMsg(pm, delay);
}

rice::p2p::commonapi::CancellableTask* rice::pastry::commonapi::PastryEndpoint::scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period)
{
    auto pm = new PastryEndpointMessage(this->getAddress(), message, npc(thePastryNode)->getLocalHandle());
    return npc(thePastryNode)->scheduleMsg(pm, delay, period);
}

rice::p2p::commonapi::CancellableTask* rice::pastry::commonapi::PastryEndpoint::scheduleMessageAtFixedRate(::rice::p2p::commonapi::Message* msg, int64_t delay, int64_t period)
{
    auto pm = new PastryEndpointMessage(this->getAddress(), msg, npc(thePastryNode)->getLocalHandle());
    return npc(thePastryNode)->scheduleMsgAtFixedRate(pm, delay, period);
}

rice::p2p::commonapi::NodeHandleSet* rice::pastry::commonapi::PastryEndpoint::localLookup(::rice::p2p::commonapi::Id* key, int32_t num, bool safe)
{
    ::rice::p2p::commonapi::NodeHandleSet* ret = npc(getRoutingTable())->alternateRoutes(java_cast< ::rice::pastry::Id* >(key), num);
    if(npc(ret)->size() == 0) {
        auto index = npc(getLeafSet())->mostSimilar(java_cast< ::rice::pastry::Id* >(key));
        ::rice::p2p::commonapi::NodeHandle* nh = npc(getLeafSet())->get(index);
        auto set = new ::rice::pastry::NodeSet();
        npc(set)->put(java_cast< ::rice::pastry::NodeHandle* >(nh));
        ret = set;
    }
    return ret;
}

rice::p2p::commonapi::NodeHandleSet* rice::pastry::commonapi::PastryEndpoint::neighborSet(int32_t num)
{
    return npc(getLeafSet())->neighborSet(num);
}

rice::p2p::commonapi::NodeHandleSet* rice::pastry::commonapi::PastryEndpoint::replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank)
{
    auto leafset = getLeafSet();
    if(maxRank > npc(leafset)->maxSize() / int32_t(2) + int32_t(1)) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"maximum replicaSet size for this configuration exceeded; asked for "_j)->append(maxRank)
            ->append(u" but max is "_j)
            ->append((npc(leafset)->maxSize() / int32_t(2) + int32_t(1)))->toString());
    }
    if(maxRank > npc(leafset)->size()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"trying to get a replica set of size "_j)->append(maxRank)
                ->append(u" but only "_j)
                ->append(npc(leafset)->size())
                ->append(u" nodes in leafset"_j)->toString());

    }
    return npc(leafset)->replicaSet(java_cast< ::rice::pastry::Id* >(id), maxRank);
}

rice::p2p::commonapi::NodeHandleSet* rice::pastry::commonapi::PastryEndpoint::replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank, ::rice::p2p::commonapi::NodeHandle* root, ::rice::p2p::commonapi::NodeHandleSet* set)
{
    auto leaf = new ::rice::pastry::leafset::LeafSet(java_cast< ::rice::pastry::NodeHandle* >(root), npc(getLeafSet())->maxSize(), false);
    for (auto i = int32_t(0); i < npc(set)->size(); i++) 
                npc(leaf)->put(java_cast< ::rice::pastry::NodeHandle* >(npc(set)->getHandle(i)));

    return npc(leaf)->replicaSet(java_cast< ::rice::pastry::Id* >(id), maxRank);
}

rice::p2p::commonapi::IdRange* rice::pastry::commonapi::PastryEndpoint::range(::rice::p2p::commonapi::NodeHandle* n, int32_t r, ::rice::p2p::commonapi::Id* key, bool cumulative)
{
    auto pKey = java_cast< ::rice::pastry::Id* >(key);
    if(cumulative)
        return npc(getLeafSet())->range(java_cast< ::rice::pastry::NodeHandle* >(n), r);

    auto ccw = npc(getLeafSet())->range(java_cast< ::rice::pastry::NodeHandle* >(n), r, false);
    auto cw = npc(getLeafSet())->range(java_cast< ::rice::pastry::NodeHandle* >(n), r, true);
    if(cw == nullptr || npc(ccw)->contains(pKey) || npc(pKey)->isBetween(npc(cw)->getCW(), npc(ccw)->getCCW()))
        return ccw;
    else
        return cw;
}

rice::p2p::commonapi::IdRange* rice::pastry::commonapi::PastryEndpoint::range(::rice::p2p::commonapi::NodeHandle* n, int32_t r, ::rice::p2p::commonapi::Id* key)
{
    return range(n, r, key, false);
}

rice::p2p::commonapi::NodeHandle* rice::pastry::commonapi::PastryEndpoint::getLocalNodeHandle()
{
    return npc(thePastryNode)->getLocalHandle();
}

void rice::pastry::commonapi::PastryEndpoint::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] deliver "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" from "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(msg)->getSenderId()))->toString());

    if(dynamic_cast< PastryEndpointMessage* >(msg) != nullptr) {
        npc(application)->deliver(nullptr, npc((java_cast< PastryEndpointMessage* >(msg)))->getMessage());
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received unknown message "_j)->append(static_cast< ::java::lang::Object* >(msg))
                ->append(u" - dropping on floor"_j)->toString());

    }
}

bool rice::pastry::commonapi::PastryEndpoint::enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* key, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt)
{
    throw new ::java::lang::RuntimeException(u"Should not be called, should only be handled by PastryEndpoint.receiveMessage()"_j);
}

void rice::pastry::commonapi::PastryEndpoint::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    npc(application)->update(nh, wasAdded);
}

void rice::pastry::commonapi::PastryEndpoint::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] recv "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))->toString());

    if(dynamic_cast< ::rice::pastry::routing::RouteMessage* >(msg) != nullptr) {
        try {
            auto rm = java_cast< ::rice::pastry::routing::RouteMessage* >(msg);
            ::rice::p2p::commonapi::NodeHandle* destinationHandle = npc(rm)->getDestinationHandle();
            if(deliverWhenNotReady() || npc(thePastryNode)->isReady() || npc(rm)->getPrevNode() == npc(thePastryNode)->getLocalHandle() || (destinationHandle != nullptr && destinationHandle == static_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(thePastryNode)->getLocalHandle()))) {
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping "_j)->append(static_cast< ::java::lang::Object* >(msg))
                        ->append(u" because node is not ready."_j)->toString());

                return;
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
                    ->append(u"] forward "_j)
                    ->append(static_cast< ::java::lang::Object* >(msg))->toString());

            if(npc(application)->forward(rm)) {
                if(npc(rm)->getNextHop() != nullptr) {
                    auto nextHop = npc(rm)->getNextHop();
                    if(npc(getNodeId())->equals(npc(nextHop)->getNodeId())) {
                        auto pMsg = java_cast< PastryEndpointMessage* >(npc(rm)->unwrap(deserializer));
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
                                ->append(u"] deliver "_j)
                                ->append(static_cast< ::java::lang::Object* >(pMsg))
                                ->append(u" from "_j)
                                ->append(static_cast< ::java::lang::Object* >(npc(pMsg)->getSenderId()))->toString());

                        npc(application)->deliver(npc(rm)->getTarget(), npc(pMsg)->getMessage());
                        npc(rm)->sendSuccess(npc(thePastryNode)->getLocalHandle());
                    } else {
                        if(npc(rm)->getDestinationHandle() == npc(thePastryNode)->getLocalHandle()) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, removing destNodeHandle: "_j)->append(static_cast< ::java::lang::Object* >(npc(rm)->getDestinationHandle()))
                                    ->append(u" from "_j)
                                    ->append(static_cast< ::java::lang::Object* >(rm))->toString());

                            npc(rm)->setDestinationHandle(nullptr);
                        }
                        npc(npc(thePastryNode)->getRouter())->route(rm);
                    }
                }
            } else {
                npc(rm)->sendSuccess(npc(thePastryNode)->getLocalHandle());
            }
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                npc(logger)->logException(this->toString(), ioe);

        }
    } else {
        messageForAppl(msg);
    }
}

void rice::pastry::commonapi::PastryEndpoint::process(::rice::Executable* task, ::rice::Continuation* command)
{
    npc(thePastryNode)->process(task, command);
}

java::lang::String* rice::pastry::commonapi::PastryEndpoint::getInstance()
{
    return instance;
}

rice::environment::Environment* rice::pastry::commonapi::PastryEndpoint::getEnvironment()
{
    return npc(thePastryNode)->getEnvironment();
}

java::lang::String* rice::pastry::commonapi::PastryEndpoint::toString()
{
    return ::java::lang::StringBuilder().append(u"PastryEndpoint "_j)->append(static_cast< ::java::lang::Object* >(application))
        ->append(u" "_j)
        ->append(instance)
        ->append(u" "_j)
        ->append(getAddress())->toString();
}

void rice::pastry::commonapi::PastryEndpoint::setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    appDeserializer = md;
}

rice::p2p::commonapi::rawserialization::MessageDeserializer* rice::pastry::commonapi::PastryEndpoint::getDeserializer()
{
    return appDeserializer;
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryEndpoint::readId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */
{
    if(type != ::rice::pastry::Id::TYPE)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Invalid type:"_j)->append(type)->toString());

    return ::rice::pastry::Id::build(buf);
}

rice::p2p::commonapi::NodeHandle* rice::pastry::commonapi::PastryEndpoint::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return npc(thePastryNode)->readNodeHandle(buf);
}

rice::p2p::commonapi::IdRange* rice::pastry::commonapi::PastryEndpoint::readIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return new ::rice::pastry::IdRange(buf);
}

rice::p2p::commonapi::NodeHandle* rice::pastry::commonapi::PastryEndpoint::coalesce(::rice::p2p::commonapi::NodeHandle* newHandle)
{
    return npc(thePastryNode)->coalesce(java_cast< ::rice::pastry::NodeHandle* >(newHandle));
}

rice::p2p::commonapi::NodeHandleSet* rice::pastry::commonapi::PastryEndpoint::readNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */
{
    switch (type) {
    case ::rice::pastry::NodeSet::TYPE:
        return new ::rice::pastry::NodeSet(buf, thePastryNode);
    case ::rice::pastry::routing::RouteSet::TYPE:
        return new ::rice::pastry::routing::RouteSet(buf, thePastryNode, thePastryNode);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type: "_j)->append(type)->toString());
}

java::util::List* rice::pastry::commonapi::PastryEndpoint::networkNeighbors(int32_t num)
{
    auto handles = new ::java::util::HashSet();
    auto l = java_cast< ::java::util::List* >(npc(npc(thePastryNode)->getRoutingTable())->asList());
    auto i = npc(l)->iterator();
    while (npc(i)->hasNext()) {
        npc(handles)->add(static_cast< ::java::lang::Object* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next())));
    }
    l = npc(npc(thePastryNode)->getLeafSet())->asList();
    i = npc(l)->iterator();
    while (npc(i)->hasNext()) {
        npc(handles)->add(static_cast< ::java::lang::Object* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next())));
    }
    auto array = java_cast< ::rice::p2p::commonapi::NodeHandleArray* >(npc(handles)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::NodeHandleArray(int32_t(0)))));
    ::java::util::Arrays::sort(array, new PastryEndpoint_networkNeighbors_3(this));
    if(npc(array)->length <= num)
        return ::java::util::Arrays::asList(array);

    auto ret = new ::rice::p2p::commonapi::NodeHandleArray(num);
    ::java::lang::System::arraycopy(array, 0, ret, 0, num);
    return ::java::util::Arrays::asList(ret);
}

void rice::pastry::commonapi::PastryEndpoint::destroy()
{
    if(application != nullptr) {
        if(dynamic_cast< ::rice::Destructable* >(application) != nullptr) {
            npc((java_cast< ::rice::Destructable* >(application)))->destroy();
        }
    }
    super::destroy();
}

int32_t rice::pastry::commonapi::PastryEndpoint::proximity(::rice::p2p::commonapi::NodeHandle* nh)
{
    return npc(thePastryNode)->proximity(java_cast< ::rice::pastry::NodeHandle* >(nh));
}

bool rice::pastry::commonapi::PastryEndpoint::isAlive(::rice::p2p::commonapi::NodeHandle* nh)
{
    return npc(thePastryNode)->isAlive(java_cast< ::rice::pastry::NodeHandle* >(nh));
}

int32_t rice::pastry::commonapi::PastryEndpoint::getAppId()
{
    return getAddress();
}

void rice::pastry::commonapi::PastryEndpoint::setConsistentRouting(bool val)
{
    consistentRouting = val;
}

bool rice::pastry::commonapi::PastryEndpoint::deliverWhenNotReady()
{
    return !consistentRouting;
}

bool rice::pastry::commonapi::PastryEndpoint::routingConsistentFor(::rice::p2p::commonapi::Id* id)
{
    if(!npc(thePastryNode)->isReady())
        return false;

    auto set = replicaSet(id, int32_t(1));
    if(npc(set)->size() == 0)
        return false;

    return npc(npc(set)->getHandle(int32_t(0)))->equals(npc(thePastryNode)->getLocalHandle());
}

void rice::pastry::commonapi::PastryEndpoint::setSendOptions(::java::util::Map* options)
{
    this->options = options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::commonapi::PastryEndpoint::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.commonapi.PastryEndpoint", 36);
    return c;
}

void rice::pastry::commonapi::PastryEndpoint::accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver)
{
    PastryAppl::accept(receiver);
}

void rice::pastry::commonapi::PastryEndpoint::connect(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout)
{
    PastryAppl::connect(handle, receiver, timeout);
}

void rice::pastry::commonapi::PastryEndpoint::register_()
{
    PastryAppl::register_();
}

java::lang::Class* rice::pastry::commonapi::PastryEndpoint::getClass0()
{
    return class_();
}

