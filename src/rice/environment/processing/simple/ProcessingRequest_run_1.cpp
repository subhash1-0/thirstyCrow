// Generated from /pastry-2.1/src/rice/environment/processing/simple/ProcessingRequest.java
#include <rice/environment/processing/simple/ProcessingRequest_run_1.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/Executable.hpp>
#include <rice/environment/processing/simple/ProcessingRequest.hpp>

rice::environment::processing::simple::ProcessingRequest_run_1::ProcessingRequest_run_1(ProcessingRequest *ProcessingRequest_this, ::java::lang::Object* result)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProcessingRequest_this(ProcessingRequest_this)
    , result(result)
{
    clinit();
    ctor();
}

void rice::environment::processing::simple::ProcessingRequest_run_1::run()
{
    ProcessingRequest_this->returnResult(result);
}

java::lang::String* rice::environment::processing::simple::ProcessingRequest_run_1::toString()
{
    return ::java::lang::StringBuilder().append(u"return ProcessingRequest for "_j)->append(static_cast< ::java::lang::Object* >(ProcessingRequest_this->r))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(ProcessingRequest_this->c))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::ProcessingRequest_run_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::simple::ProcessingRequest_run_1::getClass0()
{
    return class_();
}

