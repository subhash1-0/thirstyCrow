// Generated from /pastry-2.1/src/rice/p2p/splitstream/Stripe.java
#include <rice/p2p/splitstream/Stripe_subscribeFailed_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/splitstream/Stripe.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::splitstream::Stripe_subscribeFailed_1::Stripe_subscribeFailed_1(Stripe *Stripe_this, ::rice::p2p::scribe::Topic* topic)
    : super(*static_cast< ::default_init_tag* >(0))
    , Stripe_this(Stripe_this)
    , topic(topic)
{
    clinit();
    ctor();
}

void rice::p2p::splitstream::Stripe_subscribeFailed_1::run()
{
    if(Stripe_this->getParent() == nullptr) {
        npc(Stripe_this->scribe)->subscribe(topic, Stripe_this);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::Stripe_subscribeFailed_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::splitstream::Stripe_subscribeFailed_1::getClass0()
{
    return class_();
}

