// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/DefaultSocketStrategy.java
#include <rice/p2p/past/rawserialization/DefaultSocketStrategy.hpp>

rice::p2p::past::rawserialization::DefaultSocketStrategy::DefaultSocketStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::rawserialization::DefaultSocketStrategy::DefaultSocketStrategy(bool answer) 
    : DefaultSocketStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(answer);
}

void rice::p2p::past::rawserialization::DefaultSocketStrategy::init()
{
    answer = false;
}

void rice::p2p::past::rawserialization::DefaultSocketStrategy::ctor(bool answer)
{
    super::ctor();
    init();
    this->answer = answer;
}

bool rice::p2p::past::rawserialization::DefaultSocketStrategy::sendAlongSocket(int32_t sendType, ::rice::p2p::past::PastContent* content)
{
    return answer;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::rawserialization::DefaultSocketStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.rawserialization.DefaultSocketStrategy", 52);
    return c;
}

java::lang::Class* rice::p2p::past::rawserialization::DefaultSocketStrategy::getClass0()
{
    return class_();
}

