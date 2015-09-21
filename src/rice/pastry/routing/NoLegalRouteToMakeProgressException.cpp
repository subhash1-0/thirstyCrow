// Generated from /pastry-2.1/src/rice/pastry/routing/NoLegalRouteToMakeProgressException.java
#include <rice/pastry/routing/NoLegalRouteToMakeProgressException.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/Id.hpp>

rice::pastry::routing::NoLegalRouteToMakeProgressException::NoLegalRouteToMakeProgressException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::NoLegalRouteToMakeProgressException::NoLegalRouteToMakeProgressException(::rice::pastry::Id* target) 
    : NoLegalRouteToMakeProgressException(*static_cast< ::default_init_tag* >(0))
{
    ctor(target);
}

void rice::pastry::routing::NoLegalRouteToMakeProgressException::ctor(::rice::pastry::Id* target)
{
    super::ctor(::java::lang::StringBuilder().append(u"No legal route to the target "_j)->append(static_cast< ::java::lang::Object* >(target))->toString());
    this->target = target;
}

rice::pastry::Id* rice::pastry::routing::NoLegalRouteToMakeProgressException::getTarget()
{
    return target;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::NoLegalRouteToMakeProgressException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.NoLegalRouteToMakeProgressException", 55);
    return c;
}

java::lang::Class* rice::pastry::routing::NoLegalRouteToMakeProgressException::getClass0()
{
    return class_();
}

