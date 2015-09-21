// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java
#include <rice/tutorial/sendfile/MyApp_sendMyMsgDirect_2_receiveSocket_2_1.hpp>

#include <java/io/File.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>
#include <rice/tutorial/sendfile/MyApp_sendMyMsgDirect_2.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2_receiveSocket_2_1::MyApp_sendMyMsgDirect_2_receiveSocket_2_1(MyApp_sendMyMsgDirect_2 *MyApp_sendMyMsgDirect_2_this, ::java::io::File* f)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_sendMyMsgDirect_2_this(MyApp_sendMyMsgDirect_2_this)
    , f(f)
{
    clinit();
    ctor();
}

void rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2_receiveSocket_2_1::receiveException(::java::lang::Exception* exception)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Error sending: "_j)->append(static_cast< ::java::lang::Object* >(f))
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(exception))->toString());
}

void rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2_receiveSocket_2_1::receiveResult(::org::mpisws::p2p::filetransfer::FileReceipt* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Send complete: "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
}

void rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2_receiveSocket_2_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::filetransfer::FileReceipt* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2_receiveSocket_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2_receiveSocket_2_1::getClass0()
{
    return class_();
}

