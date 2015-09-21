// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierImpl.java
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierImpl_openSocket_1.hpp>

#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierImpl.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

org::mpisws::p2p::transport::peerreview::replay::VerifierImpl_openSocket_1::VerifierImpl_openSocket_1(VerifierImpl *VerifierImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , VerifierImpl_this(VerifierImpl_this)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl_openSocket_1::getIdentifier()
{
    return i;
}

java::util::Map* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl_openSocket_1::getOptions()
{
    return options;
}

bool org::mpisws::p2p::transport::peerreview::replay::VerifierImpl_openSocket_1::cancel()
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl_openSocket_1::getClass0()
{
    return class_();
}

