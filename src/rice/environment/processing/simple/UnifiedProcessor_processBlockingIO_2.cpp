// Generated from /pastry-2.1/src/rice/environment/processing/simple/UnifiedProcessor.java
#include <rice/environment/processing/simple/UnifiedProcessor_processBlockingIO_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/environment/processing/WorkRequest.hpp>
#include <rice/environment/processing/simple/UnifiedProcessor.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::processing::simple::UnifiedProcessor_processBlockingIO_2::UnifiedProcessor_processBlockingIO_2(UnifiedProcessor *UnifiedProcessor_this, ::rice::environment::processing::WorkRequest* workRequest)
    : super(*static_cast< ::default_init_tag* >(0))
    , UnifiedProcessor_this(UnifiedProcessor_this)
    , workRequest(workRequest)
{
    clinit();
    ctor();
}

java::lang::Object* rice::environment::processing::simple::UnifiedProcessor_processBlockingIO_2::execute() /* throws(Exception) */
{
    npc(workRequest)->run();
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::UnifiedProcessor_processBlockingIO_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::simple::UnifiedProcessor_processBlockingIO_2::getClass0()
{
    return class_();
}

