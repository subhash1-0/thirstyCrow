// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2(AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3 *AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_this, int32_t appid, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_this(AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_this)
    , appid(appid)
    , c(c)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2::init()
{
    {
        auto idBytes = ::rice::p2p::util::MathUtils::intToByteArray_(appid);
        buf = ::java::nio::ByteBuffer::wrap(idBytes);
    }
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(socket)->write(buf) < 0) {
        npc(c)->receiveException(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket was closed by remote host. "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString()));
        return;
    }
    if(npc(buf)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    }
    npc(c)->receiveResult(socket);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(c)->receiveException(ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2::getClass0()
{
    return class_();
}

