// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierNotEnoughFragmentsException.java
#include <rice/p2p/glacier/v2/GlacierNotEnoughFragmentsException.hpp>

rice::p2p::glacier::v2::GlacierNotEnoughFragmentsException::GlacierNotEnoughFragmentsException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::GlacierNotEnoughFragmentsException::GlacierNotEnoughFragmentsException(::java::lang::String* msg, int32_t checked, int32_t found) 
    : GlacierNotEnoughFragmentsException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg,checked,found);
}

void rice::p2p::glacier::v2::GlacierNotEnoughFragmentsException::ctor(::java::lang::String* msg, int32_t checked, int32_t found)
{
    super::ctor(msg);
    this->checked = checked;
    this->found = found;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierNotEnoughFragmentsException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.GlacierNotEnoughFragmentsException", 54);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierNotEnoughFragmentsException::getClass0()
{
    return class_();
}

