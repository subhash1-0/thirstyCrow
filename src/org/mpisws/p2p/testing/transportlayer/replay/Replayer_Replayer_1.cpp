// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Replayer.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer_Replayer_1.hpp>

#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer.hpp>
#include <rice/pastry/Id.hpp>

org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_1::Replayer_Replayer_1(Replayer *Replayer_this, ::rice::pastry::Id* id)
    : super(*static_cast< ::default_init_tag* >(0))
    , Replayer_this(Replayer_this)
    , id(id)
{
    clinit();
    ctor();
}

rice::pastry::Id* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_1::generateNodeId()
{
    return id;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_1::getClass0()
{
    return class_();
}

