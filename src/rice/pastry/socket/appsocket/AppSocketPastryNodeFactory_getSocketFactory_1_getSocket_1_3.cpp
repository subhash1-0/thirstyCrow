// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3(AppSocketPastryNodeFactory_getSocketFactory_1 *AppSocketPastryNodeFactory_getSocketFactory_1_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, int32_t appid, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getSocketFactory_1_this(AppSocketPastryNodeFactory_getSocketFactory_1_this)
    , ret(ret)
    , appid(appid)
    , c(c)
{
    clinit();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(ret)->setSubCancellable(new AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1(this, sock));
    try {
        (new AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2(this, appid, c))->receiveSelectResult(sock, false, true);
    } catch (::java::io::IOException* ioe) {
        npc(c)->receiveException(ioe);
    }
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3::getClass0()
{
    return class_();
}

