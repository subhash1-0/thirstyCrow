// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_deliver_6.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation_ListenerContinuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCPastImpl_deliver_6::GCPastImpl_deliver_6(GCPastImpl *GCPastImpl_this, ::java::lang::String* name, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
{
    clinit();
    ctor(name, env);
}

void rice::p2p::past::gc::GCPastImpl_deliver_6::receiveResult(::java::lang::Object* o)
{
    if(npc(npc(GCPastImpl_this->environment)->getTimeSource())->currentTimeMillis() > GCPastImpl::DEFAULT_EXPIRATION)
        GCPastImpl_this->collect(npc(GCPastImpl_this->storage)->scanMetadataValuesNull(), new ::rice::Continuation_ListenerContinuation(u"Removal of default expired ids"_j, GCPastImpl_this->environment));

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_6::getClass0()
{
    return class_();
}

