// Generated from /pastry-2.1/src/rice/pastry/dist/NodeIsDeadException.java
#include <rice/pastry/dist/NodeIsDeadException.hpp>

#include <java/lang/Exception.hpp>

rice::pastry::dist::NodeIsDeadException::NodeIsDeadException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::dist::NodeIsDeadException::NodeIsDeadException(::java::lang::Exception* e) 
    : NodeIsDeadException(*static_cast< ::default_init_tag* >(0))
{
    ctor(e);
}

void rice::pastry::dist::NodeIsDeadException::ctor(::java::lang::Exception* e)
{
    super::ctor();
    originalException = e;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::dist::NodeIsDeadException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.dist.NodeIsDeadException", 36);
    return c;
}

java::lang::Class* rice::pastry::dist::NodeIsDeadException::getClass0()
{
    return class_();
}

