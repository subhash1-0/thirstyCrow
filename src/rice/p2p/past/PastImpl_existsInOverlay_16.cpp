// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_existsInOverlay_16.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <ObjectArray.hpp>

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

rice::p2p::past::PastImpl_existsInOverlay_16::PastImpl_existsInOverlay_16(PastImpl *PastImpl_this, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_existsInOverlay_16::receiveResult(::java::lang::Object* result)
{
    auto results = java_cast< ::java::lang::ObjectArray* >(result);
    for (auto i = int32_t(0); i < npc(results)->length; i++) {
        if(dynamic_cast< PastContentHandle* >((*results)[i]) != nullptr) {
            npc(parent)->receiveResult(::java::lang::Boolean::TRUE());
            return;
        }
    }
    npc(parent)->receiveResult(::java::lang::Boolean::FALSE());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_existsInOverlay_16::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_existsInOverlay_16::getClass0()
{
    return class_();
}

