// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/socket/nat/rendezvous/ByteBufferMsg.hpp>
#include <rice/pastry/socket/nat/rendezvous/OpenChannelMsg.hpp>
#include <rice/pastry/socket/nat/rendezvous/PilotForwardMsg.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_openChannel_2.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_openChannel_3.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_openChannel_4.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_sendMessage_5.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_sendMessage_6.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_sendMessage_7.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_RendezvousApp_1.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>
#include <rice/selector/SelectorManager.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousApp::RendezvousApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousApp::RendezvousApp(::rice::pastry::PastryNode* pn) 
    : RendezvousApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::socket::nat::rendezvous::RendezvousApp::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn, nullptr, int32_t(0), nullptr);
    setDeserializer(new RendezvousApp_RendezvousApp_1(this));
    leafSet = npc(pn)->getLeafSet();
    selectorManager = npc(npc(pn)->getEnvironment())->getSelectorManager();
}

void rice::pastry::socket::nat::rendezvous::RendezvousApp::isNatted(::rice::p2p::commonapi::NodeHandle* bootstrap, ::rice::Continuation* receiveResult)
{
}

void rice::pastry::socket::nat::rendezvous::RendezvousApp::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    if(dynamic_cast< ByteBufferMsg* >(msg) != nullptr) {
        auto bbm = java_cast< ByteBufferMsg* >(msg);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"messageForAppl("_j)->append(static_cast< ::java::lang::Object* >(bbm))
                ->append(u")"_j)->toString());

        try {
            npc(tl)->messageReceivedFromOverlay(java_cast< RendezvousSocketNodeHandle* >(npc(bbm)->getOriginalSender()), npc(bbm)->buffer, nullptr);
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"dropping "_j)->append(static_cast< ::java::lang::Object* >(bbm))->toString(), ioe);

        }
        return;
    }
    if(dynamic_cast< PilotForwardMsg* >(msg) != nullptr) {
        auto pfm = java_cast< PilotForwardMsg* >(msg);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Forwarding message "_j)->append(static_cast< ::java::lang::Object* >(pfm))->toString());

        npc(thePastryNode)->send(npc(pfm)->getTarget(), npc(pfm)->getBBMsg(), nullptr, nullptr);
        return;
    }
    if(dynamic_cast< OpenChannelMsg* >(msg) != nullptr) {
        auto ocm = java_cast< OpenChannelMsg* >(msg);
        npc(tl)->openChannel(npc(ocm)->getSource(), npc(ocm)->getRendezvous(), npc(ocm)->getUid());
        return;
    }
}

bool rice::pastry::socket::nat::rendezvous::RendezvousApp::deliverWhenNotReady()
{
    return true;
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousApp::openChannel(RendezvousSocketNodeHandle* target, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid, ::rice::Continuation* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openChannel()"_j)->append(static_cast< ::java::lang::Object* >(source))
            ->append(u"->"_j)
            ->append(static_cast< ::java::lang::Object* >(target))
            ->append(u" via "_j)
            ->append(static_cast< ::java::lang::Object* >(rendezvous))
            ->append(u" uid:"_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))->toString());

    if(npc(target)->getLiveness() > ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_DEAD) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"openChannel() attempted to open to dead_forever target. Dropping."_j)->append(static_cast< ::java::lang::Object* >(source))
                ->append(u"->"_j)
                ->append(static_cast< ::java::lang::Object* >(target))
                ->append(u" via "_j)
                ->append(static_cast< ::java::lang::Object* >(rendezvous))
                ->append(u" uid:"_j)
                ->append(uid)
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(options))->toString());

        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->receiveException(new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(target));

        return nullptr;
    }
    if(npc(target)->canContactDirect()) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Target must be firewalled.  Target:"_j)->append(static_cast< ::java::lang::Object* >(target))->toString());
    }
    if(!npc(selectorManager)->isSelectorThread()) {
        auto const ret = new ::rice::p2p::util::AttachableCancellable();
        npc(selectorManager)->invoke(new RendezvousApp_openChannel_2(this, ret, target, rendezvous, source, uid, deliverAckToMe, options));
        return ret;
    }
    auto msg = new OpenChannelMsg(getAddress(), rendezvous, source, uid);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"routing "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(target))->toString());

    auto const rm = new ::rice::pastry::routing::RouteMessage(npc(target)->getNodeId(), msg, static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    npc(rm)->setDestinationHandle(target);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openChannel("_j)->append(static_cast< ::java::lang::Object* >(target))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(rendezvous))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(source))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u") sending via "_j)
            ->append(static_cast< ::java::lang::Object* >(rm))->toString());

    ::rice::p2p::commonapi::Cancellable* const ret = new RendezvousApp_openChannel_3(this, target, rendezvous, source, uid, deliverAckToMe, options, rm);
    if((deliverAckToMe != nullptr) || (npc(logger)->level <= ::rice::environment::logging::Logger::INFO)) {
        npc(rm)->setRouteMessageNotification(new RendezvousApp_openChannel_4(this, target, rendezvous, source, uid, deliverAckToMe, options));
    }
    npc(rm)->setTLOptions(options);
    npc(npc(thePastryNode)->getRouter())->route(rm);
    return ret;
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousApp::openChannel(::java::lang::Object* target, ::java::lang::Object* rendezvous, ::java::lang::Object* source, int32_t uid, ::rice::Continuation* deliverResultToMe, ::java::util::Map* options)
{ 
    return openChannel(dynamic_cast< RendezvousSocketNodeHandle* >(target), dynamic_cast< RendezvousSocketNodeHandle* >(rendezvous), dynamic_cast< RendezvousSocketNodeHandle* >(source), uid, deliverResultToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::socket::nat::rendezvous::RendezvousApp::sendMessage(RendezvousSocketNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* ops)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(ops))
            ->append(u")"_j)->toString());

    auto const options = ::org::mpisws::p2p::transport::util::OptionsFactory::removeOption(ops, ::org::mpisws::p2p::transport::wire::WireTransportLayer::OPTION_TRANSPORT_TYPE());
    auto priority = int32_t(0);
    if(npc(options)->containsKey(::org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY())) {
        priority = (npc((java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY()))))))->intValue();
    }
    auto msg = new ByteBufferMsg(m, npc(thePastryNode)->getLocalHandle(), priority, getAddress());
    if(npc(options)->containsKey(::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::OPTION_USE_PILOT())) {
        auto pilot = java_cast< RendezvousSocketNodeHandle* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::OPTION_USE_PILOT())));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(m))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(options))
                ->append(u") sending via "_j)
                ->append(static_cast< ::java::lang::Object* >(pilot))->toString());

        auto const ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
        npc(ret)->setSubCancellable(npc(thePastryNode)->send(pilot, new PilotForwardMsg(getAddress(), msg, i), new RendezvousApp_sendMessage_5(this, deliverAckToMe, ret), nullptr));
        return ret;
    } else {
        auto const rm = new ::rice::pastry::routing::RouteMessage(npc(i)->getNodeId(), msg, static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
        npc(rm)->setDestinationHandle(i);
        npc(rm)->setTLOptions(options);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(m))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(options))
                ->append(u") sending via "_j)
                ->append(static_cast< ::java::lang::Object* >(rm))->toString());

        ::org::mpisws::p2p::transport::MessageRequestHandle* const ret = new RendezvousApp_sendMessage_6(this, i, m, deliverAckToMe, options, rm);
        if((deliverAckToMe != nullptr) || (npc(logger)->level <= ::rice::environment::logging::Logger::FINE)) {
            npc(rm)->setRouteMessageNotification(new RendezvousApp_sendMessage_7(this, i, m, deliverAckToMe, options, ret));
        }
        npc(rm)->setTLOptions(options);
        npc(npc(thePastryNode)->getRouter())->route(rm);
        return ret;
    }
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::socket::nat::rendezvous::RendezvousApp::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< RendezvousSocketNodeHandle* >(i), m, dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

java::lang::String* rice::pastry::socket::nat::rendezvous::RendezvousApp::toString()
{
    return ::java::lang::StringBuilder().append(u"RendezvousApp{"_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
        ->append(u"}"_j)->toString();
}

void rice::pastry::socket::nat::rendezvous::RendezvousApp::setTransportLayer(::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayer* tl)
{
    this->tl = tl;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousApp", 47);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp::getClass0()
{
    return class_();
}

