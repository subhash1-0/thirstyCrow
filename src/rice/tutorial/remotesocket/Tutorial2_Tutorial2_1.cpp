// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial2.java
#include <rice/tutorial/remotesocket/Tutorial2_Tutorial2_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/nio/channels/SocketChannel.hpp>
#include <rice/tutorial/remotesocket/Tutorial2_Tutorial2_1_receiveResult_1_1.hpp>
#include <rice/tutorial/remotesocket/Tutorial2.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::remotesocket::Tutorial2_Tutorial2_1::Tutorial2_Tutorial2_1(Tutorial2 *Tutorial2_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , Tutorial2_this(Tutorial2_this)
{
    clinit();
    ctor();
}

void rice::tutorial::remotesocket::Tutorial2_Tutorial2_1::receiveResult(::java::nio::channels::SocketChannel* socket)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Opened SocketChannel "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString());
    (new ::java::lang::Thread(static_cast< ::java::lang::Runnable* >(new Tutorial2_Tutorial2_1_receiveResult_1_1(this, socket))))->start();
}

void rice::tutorial::remotesocket::Tutorial2_Tutorial2_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::nio::channels::SocketChannel* >(result));
}

void rice::tutorial::remotesocket::Tutorial2_Tutorial2_1::receiveException(::java::lang::Exception* exception)
{
    npc(exception)->printStackTrace();
    throw new ::java::lang::RuntimeException(u"Not implemented. "_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::remotesocket::Tutorial2_Tutorial2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::remotesocket::Tutorial2_Tutorial2_1::getClass0()
{
    return class_();
}

