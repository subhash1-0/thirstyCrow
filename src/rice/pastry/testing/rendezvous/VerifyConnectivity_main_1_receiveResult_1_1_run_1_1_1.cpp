// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1_receiveResult_1_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1(VerifyConnectivity_main_1_receiveResult_1_1 *VerifyConnectivity_main_1_receiveResult_1_1_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , VerifyConnectivity_main_1_receiveResult_1_1_this(VerifyConnectivity_main_1_receiveResult_1_1_this)
{
    clinit();
    ctor();
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1::udpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"UDP works. "_j)->append(static_cast< ::java::lang::Object* >(from))->toString());
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1::tcpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"TCP works. "_j)->append(static_cast< ::java::lang::Object* >(from))->toString());
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(exception)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1::getClass0()
{
    return class_();
}

