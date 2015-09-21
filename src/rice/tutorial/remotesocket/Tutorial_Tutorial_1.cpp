// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial.java
#include <rice/tutorial/remotesocket/Tutorial_Tutorial_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/tutorial/remotesocket/Tutorial_Tutorial_1_receiveResult_1_1.hpp>
#include <rice/tutorial/remotesocket/Tutorial.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::remotesocket::Tutorial_Tutorial_1::Tutorial_Tutorial_1(Tutorial *Tutorial_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , Tutorial_this(Tutorial_this)
{
    clinit();
    ctor();
}

void rice::tutorial::remotesocket::Tutorial_Tutorial_1::receiveResult(::rice::p2p::commonapi::appsocket::AppSocket* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Opened AppSocket "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
    auto const out = ::java::nio::ByteBuffer::wrap(npc(::rice::pastry::Id::build())->toByteArray_());
    npc(result)->register_(false, true, -int32_t(1), new Tutorial_Tutorial_1_receiveResult_1_1(this, out));
}

void rice::tutorial::remotesocket::Tutorial_Tutorial_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::p2p::commonapi::appsocket::AppSocket* >(result));
}

void rice::tutorial::remotesocket::Tutorial_Tutorial_1::receiveException(::java::lang::Exception* exception)
{
    npc(exception)->printStackTrace();
    throw new ::java::lang::RuntimeException(u"Not implemented. "_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::remotesocket::Tutorial_Tutorial_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::remotesocket::Tutorial_Tutorial_1::getClass0()
{
    return class_();
}

