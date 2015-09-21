// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_insert_8_receiveResult_8_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl_insert_8.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_insert_8_receiveResult_8_1::PastImpl_insert_8_receiveResult_8_1(PastImpl_insert_8 *PastImpl_insert_8_this, ::java::lang::Object* array)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_insert_8_this(PastImpl_insert_8_this)
    , array(array)
{
    clinit();
    ctor();
}

void rice::p2p::past::PastImpl_insert_8_receiveResult_8_1::receiveResult(::java::lang::Object* o)
{
    npc(PastImpl_insert_8_this->parent)->receiveResult(array);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_insert_8_receiveResult_8_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_insert_8_receiveResult_8_1::getClass0()
{
    return class_();
}

