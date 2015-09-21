// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl_lookup_9.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2.hpp>
#include <rice/p2p/past/PastImpl.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1::PastImpl_lookup_9_receiveResult_9_1(PastImpl_lookup_9 *PastImpl_lookup_9_this, bool cache, ::rice::Continuation* command_, ::rice::p2p::commonapi::Id* id, ::java::lang::String* name, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_lookup_9_this(PastImpl_lookup_9_this)
    , cache(cache)
    , command(command_)
    , id(id)
{
    clinit();
    ctor(name, command);
}

void rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        if(cache) {
            PastImpl_lookup_9_this->PastImpl_this->cache(java_cast< PastContent* >(o), new PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1(this, command, o));
        } else {
            npc(command)->receiveResult(o);
        }
    } else {
        PastImpl_lookup_9_this->PastImpl_this->lookupHandles(id, PastImpl_lookup_9_this->PastImpl_this->replicationFactor + int32_t(1), static_cast< ::rice::Continuation* >(new PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2(this, cache, command)));
    }
}

void rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1::receiveException(::java::lang::Exception* e)
{
    receiveResult(static_cast< ::java::lang::Object* >(nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1::getClass0()
{
    return class_();
}

