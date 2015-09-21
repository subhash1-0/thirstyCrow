// Generated from /pastry-2.1/src/rice/tutorial/appsocket/MyApp.java
#include <rice/tutorial/appsocket/MyApp_sendMyMsgDirect_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/tutorial/appsocket/MyApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::appsocket::MyApp_sendMyMsgDirect_2::MyApp_sendMyMsgDirect_2(MyApp *MyApp_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_this(MyApp_this)
{
    clinit();
    ctor();
}

void rice::tutorial::appsocket::MyApp_sendMyMsgDirect_2::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    npc(socket)->register_(false, true, 30000, this);
}

void rice::tutorial::appsocket::MyApp_sendMyMsgDirect_2::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    npc(e)->printStackTrace();
}

void rice::tutorial::appsocket::MyApp_sendMyMsgDirect_2::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    try {
        auto ret = npc(socket)->write(MyApp_this->out);
        if(!npc(MyApp_this->out)->hasRemaining()) {
            npc(socket)->close();
            npc(MyApp_this->out)->clear();
        } else {
            npc(socket)->register_(false, true, 30000, this);
        }
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::appsocket::MyApp_sendMyMsgDirect_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::appsocket::MyApp_sendMyMsgDirect_2::getClass0()
{
    return class_();
}

