// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress_1.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::MyInetSocketAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::MyInetSocketAddress(::java::net::InetAddress* addr, int32_t port) 
    : MyInetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(addr,port);
}

org::mpisws::p2p::transport::util::Serializer*& org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::serializer()
{
    clinit();
    return serializer_;
}
org::mpisws::p2p::transport::util::Serializer* org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::serializer_;

void org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::ctor(::java::net::InetAddress* addr, int32_t port)
{
    super::ctor(addr, port);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(serializer_)->serialize(this, buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.MyInetSocketAddress", 68);
    return c;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        serializer_ = new MyInetSocketAddress_1();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress::getClass0()
{
    return class_();
}

