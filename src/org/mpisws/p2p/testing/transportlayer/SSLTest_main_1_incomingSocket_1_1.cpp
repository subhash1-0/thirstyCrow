// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTest.java
#include <org/mpisws/p2p/testing/transportlayer/SSLTest_main_1_incomingSocket_1_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SSLTest_main_1.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::SSLTest_main_1_incomingSocket_1_1::SSLTest_main_1_incomingSocket_1_1(SSLTest_main_1 *SSLTest_main_1_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SSLTest_main_1_this(SSLTest_main_1_this)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::SSLTest_main_1_incomingSocket_1_1::init()
{
    readMe = ::java::nio::ByteBuffer::allocate(npc((new ::java::lang::String(u"foo"_j))->getBytes())->length);
}

void org::mpisws::p2p::testing::transportlayer::SSLTest_main_1_incomingSocket_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead) {
        npc(socket)->read(readMe);
        if(npc(readMe)->hasRemaining()) {
            npc(socket)->register_(true, false, this);
        } else {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Alice read: "_j)->append(new ::java::lang::String(npc(readMe)->array()))->toString());
        }
    }
}

void org::mpisws::p2p::testing::transportlayer::SSLTest_main_1_incomingSocket_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"alice: ex:"_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest_main_1_incomingSocket_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest_main_1_incomingSocket_1_1::getClass0()
{
    return class_();
}

