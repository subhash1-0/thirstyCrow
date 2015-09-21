// Generated from /pastry-2.1/src/rice/environment/processing/WorkRequest.java
#include <rice/environment/processing/WorkRequest_run_1.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/processing/WorkRequest.hpp>

rice::environment::processing::WorkRequest_run_1::WorkRequest_run_1(WorkRequest *WorkRequest_this, ::java::lang::Object* result)
    : super(*static_cast< ::default_init_tag* >(0))
    , WorkRequest_this(WorkRequest_this)
    , result(result)
{
    clinit();
    ctor();
}

void rice::environment::processing::WorkRequest_run_1::run()
{
    WorkRequest_this->returnResult(result);
}

java::lang::String* rice::environment::processing::WorkRequest_run_1::toString()
{
    return ::java::lang::StringBuilder().append(u"invc result of "_j)->append(static_cast< ::java::lang::Object* >(WorkRequest_this->c))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::WorkRequest_run_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::WorkRequest_run_1::getClass0()
{
    return class_();
}

