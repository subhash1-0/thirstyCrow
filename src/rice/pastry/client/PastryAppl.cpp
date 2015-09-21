// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java
#include <rice/pastry/client/PastryAppl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/client/NodeIsNotReadyException.hpp>
#include <rice/pastry/client/PastryAppl_routeMsg_1.hpp>
#include <rice/pastry/client/PastryAppl_routeMsg_2.hpp>
#include <rice/pastry/client/PastryAppl_LeafSetObserver.hpp>
#include <rice/pastry/client/PastryAppl_RouteSetObserver.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/JavaSerializedDeserializer.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/messaging/RawMessageDelivery.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/StandardAddress.hpp>

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

rice::pastry::client::PastryAppl::PastryAppl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::client::PastryAppl::PastryAppl(::rice::pastry::PastryNode* pn) 
    : PastryAppl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

rice::pastry::client::PastryAppl::PastryAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance) 
    : PastryAppl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,instance);
}

rice::pastry::client::PastryAppl::PastryAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) 
    : PastryAppl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,instance,address,md);
}

rice::pastry::client::PastryAppl::PastryAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, ::rice::environment::logging::Logger* logger) 
    : PastryAppl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,instance,address,md,logger);
}

rice::pastry::client::PastryAppl::PastryAppl(::rice::pastry::PastryNode* pn, int32_t port) 
    : PastryAppl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,port);
}

void rice::pastry::client::PastryAppl::ctor(::rice::pastry::PastryNode* pn)
{
    ctor(pn, static_cast< ::java::lang::String* >(nullptr));
}

void rice::pastry::client::PastryAppl::ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance)
{
    ctor(pn, instance, int32_t(0), nullptr);
    register_();
}

void rice::pastry::client::PastryAppl::ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    ctor(pn, instance, address, md, nullptr);
}

void rice::pastry::client::PastryAppl::ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, ::rice::environment::logging::Logger* logger)
{
    super::ctor();
    this->address = address;
    if(instance != nullptr) {
        this->instance = instance;
    }
    if(address == 0)
        this->address = ::rice::pastry::standard::StandardAddress::getAddress(this->getClass(), instance, npc(pn)->getEnvironment());

    thePastryNode = pn;
    this->logger = logger;
    if(this->logger == nullptr) {
        this->logger = npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(getClass(), instance);
    }
    deserializer = md;
    if(deserializer == nullptr)
        deserializer = new ::rice::pastry::messaging::JavaSerializedDeserializer(pn);

}

void rice::pastry::client::PastryAppl::ctor(::rice::pastry::PastryNode* pn, int32_t port)
{
    ctor(pn, nullptr, port, nullptr);
}

void rice::pastry::client::PastryAppl::register_()
{
    npc(thePastryNode)->registerReceiver(getAddress(), this);
    npc(thePastryNode)->addLeafSetListener(new PastryAppl_LeafSetObserver(this));
    npc(thePastryNode)->addRouteSetListener(new PastryAppl_RouteSetObserver(this));
    npc(thePastryNode)->registerApp(this);
}

int32_t rice::pastry::client::PastryAppl::getAddress()
{
    return address;
}

void rice::pastry::client::PastryAppl::receiveMessageInternal(::rice::pastry::messaging::RawMessageDelivery* msg)
{
    ::rice::pastry::messaging::Message* m;
    try {
        m = npc(msg)->deserialize(deserializer);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Error deserializing "_j)->append(static_cast< ::java::lang::Object* >(msg))
                ->append(u" in "_j)
                ->append(static_cast< ::java::lang::Object* >(this))
                ->append(u".  Message will be dropped."_j)->toString(), ioe);

        return;
    } catch (::java::lang::RuntimeException* re) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Error deserializing "_j)->append(static_cast< ::java::lang::Object* >(msg))
                ->append(u" in "_j)
                ->append(static_cast< ::java::lang::Object* >(this))
                ->append(u".  Message will be dropped."_j)->toString(), re);

        throw re;
    }
    receiveMessage(m);
}

void rice::pastry::client::PastryAppl::setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* deserializer)
{
    this->deserializer = deserializer;
}

rice::p2p::commonapi::rawserialization::MessageDeserializer* rice::pastry::client::PastryAppl::getDeserializer()
{
    return this->deserializer;
}

void rice::pastry::client::PastryAppl::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] recv "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))->toString());

    if(dynamic_cast< ::rice::pastry::routing::RouteMessage* >(msg) != nullptr) {
        auto rm = java_cast< ::rice::pastry::routing::RouteMessage* >(msg);
        auto destinationHandle = npc(rm)->getDestinationHandle();
        if(deliverWhenNotReady() || npc(thePastryNode)->isReady() || npc(rm)->getPrevNode() == npc(thePastryNode)->getLocalHandle() || (destinationHandle != nullptr && destinationHandle == npc(thePastryNode)->getLocalHandle())) {
        } else {
            if(npc(rm)->sendFailed(new NodeIsNotReadyException(npc(thePastryNode)->getLocalHandle()))) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping "_j)->append(static_cast< ::java::lang::Object* >(msg))
                        ->append(u" because node is not ready."_j)->toString());

            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping "_j)->append(static_cast< ::java::lang::Object* >(msg))
                        ->append(u" because node is not ready."_j)->toString());

            }
            return;
        }
        try {
            auto innerMessage = npc(rm)->unwrap(deserializer);
            if(enrouteMessage(innerMessage, npc(rm)->getTarget(), npc(rm)->getNextHop(), npc(rm)->getOptions())) {
                if(npc(rm)->getDestinationHandle() == npc(thePastryNode)->getLocalHandle()) {
                    messageForAppl(innerMessage);
                } else {
                    npc(npc(thePastryNode)->getRouter())->route(rm);
                }
            }
        } catch (::java::io::IOException* ioe) {
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Error deserializing message "_j)->append(static_cast< ::java::lang::Object* >(rm))->toString(), ioe);
        }
    } else {
        messageForAppl(msg);
    }
}

rice::pastry::Id* rice::pastry::client::PastryAppl::getNodeId()
{
    return npc(thePastryNode)->getNodeId();
}

rice::pastry::NodeHandle* rice::pastry::client::PastryAppl::getNodeHandle()
{
    return npc(thePastryNode)->getLocalHandle();
}

bool rice::pastry::client::PastryAppl::routeMsgDirect(::rice::pastry::NodeHandle* dest, ::rice::pastry::messaging::Message* msg, ::rice::pastry::routing::SendOptions* opt)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] routemsgdirect "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(dest))->toString());

    if(!npc(dest)->isAlive())
        return false;

    npc(thePastryNode)->send(dest, msg, nullptr, options);
    return npc(dest)->isAlive();
}

void rice::pastry::client::PastryAppl::routeMsg(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::pastry::routing::SendOptions* opt)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] routemsg "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(key))->toString());

    auto rm = new ::rice::pastry::routing::RouteMessage(key, msg, opt, static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    npc(rm)->setTLOptions(options);
    npc(npc(thePastryNode)->getRouter())->route(rm);
}

rice::p2p::commonapi::MessageReceipt* rice::pastry::client::PastryAppl::routeMsg(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::pastry::routing::SendOptions* opt, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] routemsg "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(key))->toString());

    auto const rm = new ::rice::pastry::routing::RouteMessage(key, msg, opt, static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    ::rice::p2p::commonapi::MessageReceipt* const ret = new PastryAppl_routeMsg_1(this, key, msg, deliverAckToMe, rm);
    if((deliverAckToMe != nullptr) || (npc(logger)->level <= ::rice::environment::logging::Logger::FINE)) {
        npc(rm)->setRouteMessageNotification(new PastryAppl_routeMsg_2(this, key, msg, deliverAckToMe, ret));
    }
    npc(rm)->setTLOptions(::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, ::org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY(), ::java::lang::Integer::valueOf(npc(msg)->getPriority())));
    npc(npc(thePastryNode)->getRouter())->route(rm);
    return ret;
}

rice::pastry::leafset::LeafSet* rice::pastry::client::PastryAppl::getLeafSet()
{
    return npc(npc(thePastryNode)->getLeafSet())->copy();
}

rice::pastry::routing::RoutingTable* rice::pastry::client::PastryAppl::getRoutingTable()
{
    return npc(thePastryNode)->getRoutingTable();
}

bool rice::pastry::client::PastryAppl::isClosest(::rice::pastry::Id* key)
{
    return npc(thePastryNode)->isClosest(key);
}

bool rice::pastry::client::PastryAppl::enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* key, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt)
{
    return true;
}

void rice::pastry::client::PastryAppl::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
}

void rice::pastry::client::PastryAppl::routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
}

void rice::pastry::client::PastryAppl::notifyReady()
{
}

bool rice::pastry::client::PastryAppl::deliverWhenNotReady()
{
    return false;
}

void rice::pastry::client::PastryAppl::destroy()
{
}

void rice::pastry::client::PastryAppl::connect(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout)
{
    npc(thePastryNode)->connect(java_cast< ::rice::pastry::NodeHandle* >(handle), receiver, this, timeout);
}

void rice::pastry::client::PastryAppl::accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver)
{
    this->receiver = receiver;
}

bool rice::pastry::client::PastryAppl::canReceiveSocket()
{
    return receiver != nullptr;
}

void rice::pastry::client::PastryAppl::finishReceiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
{
    auto theReceiver = receiver;
    receiver = nullptr;
    npc(theReceiver)->receiveSocket(socket);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::client::PastryAppl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.client.PastryAppl", 29);
    return c;
}

java::lang::Class* rice::pastry::client::PastryAppl::getClass0()
{
    return class_();
}

