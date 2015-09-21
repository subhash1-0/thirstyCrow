// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_ExternalContinuation.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>

rice::Continuation_ExternalContinuation::Continuation_ExternalContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_ExternalContinuation::Continuation_ExternalContinuation()
    : Continuation_ExternalContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::Continuation_ExternalContinuation::ctor()
{
    super::ctor();
    init();
}

void rice::Continuation_ExternalContinuation::init()
{
    done = false;
}

void rice::Continuation_ExternalContinuation::receiveResult(::java::lang::Object* o)
{
    result = o;
    done = true;
    notify();
}

void rice::Continuation_ExternalContinuation::receiveException(::java::lang::Exception* e)
{
    exception = e;
    done = true;
    notify();
}

java::lang::Object* rice::Continuation_ExternalContinuation::getResult()
{
    if(exception != nullptr) {
        throw new ::java::lang::IllegalArgumentException(u"Exception was thrown in ExternalContinuation, but getResult() called!"_j);
    }
    return result;
}

java::lang::Exception* rice::Continuation_ExternalContinuation::getException()
{
    return exception;
}

void rice::Continuation_ExternalContinuation::sleep()
{
    try {
        while (!done) {
            wait();
        }
    } catch (::java::lang::InterruptedException* e) {
        exception = e;
    }
}

bool rice::Continuation_ExternalContinuation::exceptionThrown()
{
    return (exception != nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_ExternalContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.ExternalContinuation", 38);
    return c;
}

java::lang::Class* rice::Continuation_ExternalContinuation::getClass0()
{
    return class_();
}

