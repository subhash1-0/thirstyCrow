// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTestNoClientAuth.java
#include <org/mpisws/p2p/testing/transportlayer/SSLTestNoClientAuth_main_2_receiveResult_2_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SSLTestNoClientAuth_main_2.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2_receiveResult_2_1::SSLTestNoClientAuth_main_2_receiveResult_2_1(SSLTestNoClientAuth_main_2 *SSLTestNoClientAuth_main_2_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SSLTestNoClientAuth_main_2_this(SSLTestNoClientAuth_main_2_this)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2_receiveResult_2_1::init()
{
    writeMe = ::java::nio::ByteBuffer::wrap((new ::java::lang::String(u"foo"_j))->getBytes());
}

void org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2_receiveResult_2_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    npc(socket)->write(writeMe);
    if(npc(writeMe)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    }
    npc(::java::lang::System::out())->println(u"done writing"_j);
}

void org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2_receiveResult_2_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"bob: ex:"_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2_receiveResult_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2_receiveResult_2_1::getClass0()
{
    return class_();
}

