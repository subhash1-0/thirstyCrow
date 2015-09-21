// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTestNoClientAuth.java
#include <org/mpisws/p2p/testing/transportlayer/SSLTestNoClientAuth_main_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SSLTestNoClientAuth_main_2_receiveResult_2_1.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2::SSLTestNoClientAuth_main_2()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"*************** Bob: Opened Socket "_j)->append(static_cast< ::java::lang::Object* >(sock))->toString());
    npc(sock)->register_(false, true, new SSLTestNoClientAuth_main_2_receiveResult_2_1(this));
}

void org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"bob2: ex:"_j)->append(static_cast< ::java::lang::Object* >(ex))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2::getClass0()
{
    return class_();
}

