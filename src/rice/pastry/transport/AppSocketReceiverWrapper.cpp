// Generated from /pastry-2.1/src/rice/pastry/transport/AppSocketReceiverWrapper.java
#include <rice/pastry/transport/AppSocketReceiverWrapper.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>
#include <rice/pastry/transport/SocketAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::transport::AppSocketReceiverWrapper::AppSocketReceiverWrapper(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::transport::AppSocketReceiverWrapper::AppSocketReceiverWrapper(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, SocketAdapter* socket, ::rice::environment::Environment* env) 
    : AppSocketReceiverWrapper(*static_cast< ::default_init_tag* >(0))
{
    ctor(receiver,socket,env);
}

void rice::pastry::transport::AppSocketReceiverWrapper::ctor(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, SocketAdapter* socket, ::rice::environment::Environment* env)
{
    super::ctor();
    this->receiver = receiver;
    this->socket = socket;
    this->logger = npc(npc(env)->getLogManager())->getLogger(AppSocketReceiverWrapper::class_(), nullptr);
}

void rice::pastry::transport::AppSocketReceiverWrapper::receiveException(::org::mpisws::p2p::transport::P2PSocket* s, ::java::lang::Exception* ioe)
{
    npc(receiver)->receiveException(socket, ioe);
}

void rice::pastry::transport::AppSocketReceiverWrapper::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* s, bool canRead, bool canWrite) /* throws(IOException) */
{
    npc(receiver)->receiveSelectResult(socket, canRead, canWrite);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::AppSocketReceiverWrapper::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.transport.AppSocketReceiverWrapper", 46);
    return c;
}

java::lang::Class* rice::pastry::transport::AppSocketReceiverWrapper::getClass0()
{
    return class_();
}

