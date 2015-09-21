// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_insert_8.hpp>

#include <rice/p2p/past/PastImpl_insert_8_receiveResult_8_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>

rice::p2p::past::PastImpl_insert_8::PastImpl_insert_8(PastImpl *PastImpl_this, PastContent* obj, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , obj(obj)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_insert_8::receiveResult(::java::lang::Object* array)
{
    PastImpl_this->cache(obj, new PastImpl_insert_8_receiveResult_8_1(this, array));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_insert_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_insert_8::getClass0()
{
    return class_();
}

