// Generated from /pastry-2.1/src/rice/pastry/standard/TooManyRouteAttempts.java
#include <rice/pastry/standard/TooManyRouteAttempts.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>

rice::pastry::standard::TooManyRouteAttempts::TooManyRouteAttempts(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::TooManyRouteAttempts::TooManyRouteAttempts(::rice::pastry::routing::RouteMessage* rm, int32_t max_retries) 
    : TooManyRouteAttempts(*static_cast< ::default_init_tag* >(0))
{
    ctor(rm,max_retries);
}

void rice::pastry::standard::TooManyRouteAttempts::ctor(::rice::pastry::routing::RouteMessage* rm, int32_t max_retries)
{
    super::ctor(::java::lang::StringBuilder().append(u"Too many attempts to route the message "_j)->append(static_cast< ::java::lang::Object* >(rm))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::TooManyRouteAttempts::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.TooManyRouteAttempts", 41);
    return c;
}

java::lang::Class* rice::pastry::standard::TooManyRouteAttempts::getClass0()
{
    return class_();
}

