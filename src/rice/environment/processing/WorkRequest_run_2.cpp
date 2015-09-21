// Generated from /pastry-2.1/src/rice/environment/processing/WorkRequest.java
#include <rice/environment/processing/WorkRequest_run_2.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/processing/WorkRequest.hpp>

rice::environment::processing::WorkRequest_run_2::WorkRequest_run_2(WorkRequest *WorkRequest_this, ::java::lang::Exception* e)
    : super(*static_cast< ::default_init_tag* >(0))
    , WorkRequest_this(WorkRequest_this)
    , e(e)
{
    clinit();
    ctor();
}

void rice::environment::processing::WorkRequest_run_2::run()
{
    WorkRequest_this->returnError(e);
}

java::lang::String* rice::environment::processing::WorkRequest_run_2::toString()
{
    return ::java::lang::StringBuilder().append(u"invc error of "_j)->append(static_cast< ::java::lang::Object* >(WorkRequest_this->c))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::WorkRequest_run_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::WorkRequest_run_2::getClass0()
{
    return class_();
}

