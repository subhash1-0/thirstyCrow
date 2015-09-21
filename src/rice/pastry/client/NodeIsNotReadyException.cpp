// Generated from /pastry-2.1/src/rice/pastry/client/NodeIsNotReadyException.java
#include <rice/pastry/client/NodeIsNotReadyException.hpp>

#include <rice/pastry/NodeHandle.hpp>

rice::pastry::client::NodeIsNotReadyException::NodeIsNotReadyException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::client::NodeIsNotReadyException::NodeIsNotReadyException(::rice::pastry::NodeHandle* handle) 
    : NodeIsNotReadyException(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle);
}

void rice::pastry::client::NodeIsNotReadyException::ctor(::rice::pastry::NodeHandle* handle)
{
    super::ctor();
    this->handle = handle;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::client::NodeIsNotReadyException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.client.NodeIsNotReadyException", 42);
    return c;
}

java::lang::Class* rice::pastry::client::NodeIsNotReadyException::getClass0()
{
    return class_();
}

