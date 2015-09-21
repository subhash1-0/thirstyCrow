// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_MultiContinuation_getSubContinuation_1.hpp>

#include <java/lang/Exception.hpp>
#include <rice/Continuation_MultiContinuation.hpp>

rice::Continuation_MultiContinuation_getSubContinuation_1::Continuation_MultiContinuation_getSubContinuation_1(Continuation_MultiContinuation *Continuation_MultiContinuation_this, int32_t index)
    : super(*static_cast< ::default_init_tag* >(0))
    , Continuation_MultiContinuation_this(Continuation_MultiContinuation_this)
    , index(index)
{
    clinit();
    ctor();
}

void rice::Continuation_MultiContinuation_getSubContinuation_1::receiveResult(::java::lang::Object* o)
{
    Continuation_MultiContinuation_this->receive(index, o);
}

void rice::Continuation_MultiContinuation_getSubContinuation_1::receiveException(::java::lang::Exception* e)
{
    Continuation_MultiContinuation_this->receive(index, e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_MultiContinuation_getSubContinuation_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::Continuation_MultiContinuation_getSubContinuation_1::getClass0()
{
    return class_();
}

