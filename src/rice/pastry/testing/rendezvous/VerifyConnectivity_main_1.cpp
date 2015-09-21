// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1_receiveResult_1_1.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::rendezvous::VerifyConnectivity_main_1::VerifyConnectivity_main_1(int32_t externalPort, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* verifier, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , externalPort(externalPort)
    , factory(factory)
    , verifier(verifier)
    , bootaddress(bootaddress)
    , env(env)
{
    clinit();
    ctor();
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1::receiveResult(::java::net::InetAddress* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"My external address is "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
    ::java::lang::Runnable* r = new VerifyConnectivity_main_1_receiveResult_1_1(this, result, externalPort, factory, verifier, bootaddress);
    npc(npc(env)->getSelectorManager())->invoke(r);
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::net::InetAddress* >(result));
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1::receiveException(::java::io::IOException* exception)
{
    npc(exception)->printStackTrace();
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity_main_1::getClass0()
{
    return class_();
}

