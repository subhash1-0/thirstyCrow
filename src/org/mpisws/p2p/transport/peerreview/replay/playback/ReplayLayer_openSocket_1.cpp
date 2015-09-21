// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.java
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer_openSocket_1.hpp>

#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.hpp>

org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer_openSocket_1::ReplayLayer_openSocket_1(ReplayLayer *ReplayLayer_this, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplayLayer_this(ReplayLayer_this)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer_openSocket_1::getIdentifier()
{
    return i;
}

java::util::Map* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer_openSocket_1::getOptions()
{
    return options;
}

bool org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer_openSocket_1::cancel()
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer_openSocket_1::getClass0()
{
    return class_();
}

