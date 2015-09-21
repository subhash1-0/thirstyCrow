// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/MyScribeContent.java
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeContent.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

org::mpisws::p2p::testing::transportlayer::replay::MyScribeContent::MyScribeContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::MyScribeContent::MyScribeContent(::rice::p2p::commonapi::NodeHandle* from, int32_t seq) 
    : MyScribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,seq);
}

void org::mpisws::p2p::testing::transportlayer::replay::MyScribeContent::ctor(::rice::p2p::commonapi::NodeHandle* from, int32_t seq)
{
    super::ctor();
    this->from = from;
    this->seq = seq;
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::replay::MyScribeContent::toString()
{
    return ::java::lang::StringBuilder().append(u"MyScribeContent #"_j)->append(seq)
        ->append(u" from "_j)
        ->append(static_cast< ::java::lang::Object* >(from))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyScribeContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.MyScribeContent", 60);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyScribeContent::getClass0()
{
    return class_();
}

