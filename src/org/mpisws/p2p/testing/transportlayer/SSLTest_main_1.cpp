// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTest.java
#include <org/mpisws/p2p/testing/transportlayer/SSLTest_main_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SSLTest_main_1_incomingSocket_1_1.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::SSLTest_main_1::SSLTest_main_1()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::SSLTest_main_1::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"************* Alice: Incoming Socket "_j)->append(static_cast< ::java::lang::Object* >(s))->toString());
    npc(s)->register_(true, false, new SSLTest_main_1_incomingSocket_1_1(this));
}

void org::mpisws::p2p::testing::transportlayer::SSLTest_main_1::messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
}

void org::mpisws::p2p::testing::transportlayer::SSLTest_main_1::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest_main_1::getClass0()
{
    return class_();
}

