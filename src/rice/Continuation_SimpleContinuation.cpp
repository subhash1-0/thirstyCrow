// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_SimpleContinuation.hpp>

#include <java/lang/Exception.hpp>

rice::Continuation_SimpleContinuation::Continuation_SimpleContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_SimpleContinuation::Continuation_SimpleContinuation()
    : Continuation_SimpleContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::Continuation_SimpleContinuation::receiveException(::java::lang::Exception* result)
{
    receiveResult(result);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_SimpleContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.SimpleContinuation", 36);
    return c;
}

java::lang::Class* rice::Continuation_SimpleContinuation::getClass0()
{
    return class_();
}

