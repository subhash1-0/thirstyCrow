// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/Basics.java
#include <org/mpisws/p2p/transport/peerreview/Basics.hpp>

#include <java/lang/String.hpp>

org::mpisws::p2p::transport::peerreview::Basics::Basics(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::Basics::Basics()
    : Basics(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::String* org::mpisws::p2p::transport::peerreview::Basics::renderStatus(int32_t status)
{
    clinit();
    switch (status) {
    case STATUS_TRUSTED:
        return u"TRUSTED"_j;
    case STATUS_SUSPECTED:
        return u"SUSPECTED"_j;
    case STATUS_EXPOSED:
        return u"EXPOSED"_j;
    default:
        return u"UNKNOWN"_j;
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::Basics::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.Basics", 42);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::Basics::getClass0()
{
    return class_();
}

