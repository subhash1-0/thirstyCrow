// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusTransport_receiveMessage_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusTransport.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport_receiveMessage_1::PRRegressionTest_BogusTransport_receiveMessage_1(PRRegressionTest_BogusTransport *PRRegressionTest_BogusTransport_this, PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_BogusTransport_this(PRRegressionTest_BogusTransport_this)
    , i(i)
    , m(m)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport_receiveMessage_1::run()
{
    try {
        npc(PRRegressionTest_BogusTransport_this->callback)->messageReceived(i, m, nullptr);
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
        ::java::lang::System::exit(0);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport_receiveMessage_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport_receiveMessage_1::getClass0()
{
    return class_();
}

