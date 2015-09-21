// Generated from /pastry-2.1/src/rice/p2p/past/PastPolicy.java
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy_fetch_1.hpp>
#include <rice/persistence/Cache.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastPolicy_DefaultPastPolicy::PastPolicy_DefaultPastPolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::PastPolicy_DefaultPastPolicy::PastPolicy_DefaultPastPolicy()
    : PastPolicy_DefaultPastPolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::past::PastPolicy_DefaultPastPolicy::fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::persistence::Cache* backup, Past* past, ::rice::Continuation* command)
{
    if((backup != nullptr) && npc(backup)->exists(id)) {
        npc(backup)->getObject(id, command);
    } else {
        npc(past)->lookup(id, false, new PastPolicy_DefaultPastPolicy_fetch_1(this, past, id, hint, command));
    }
}

bool rice::p2p::past::PastPolicy_DefaultPastPolicy::allowInsert(PastContent* content)
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastPolicy_DefaultPastPolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.PastPolicy.DefaultPastPolicy", 42);
    return c;
}

java::lang::Class* rice::p2p::past::PastPolicy_DefaultPastPolicy::getClass0()
{
    return class_();
}

