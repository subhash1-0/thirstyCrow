// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectInputStream.java
#include <rice/p2p/util/XMLObjectInputStream_ValidationList_Callback.hpp>

#include <java/io/ObjectInputValidation.hpp>

rice::p2p::util::XMLObjectInputStream_ValidationList_Callback::XMLObjectInputStream_ValidationList_Callback(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::XMLObjectInputStream_ValidationList_Callback::XMLObjectInputStream_ValidationList_Callback(::java::io::ObjectInputValidation* obj, int32_t priority, XMLObjectInputStream_ValidationList_Callback* next) 
    : XMLObjectInputStream_ValidationList_Callback(*static_cast< ::default_init_tag* >(0))
{
    ctor(obj,priority,next);
}

void rice::p2p::util::XMLObjectInputStream_ValidationList_Callback::ctor(::java::io::ObjectInputValidation* obj, int32_t priority, XMLObjectInputStream_ValidationList_Callback* next)
{
    super::ctor();
    this->obj = obj;
    this->priority = priority;
    this->next = next;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLObjectInputStream_ValidationList_Callback::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLObjectInputStream.ValidationList.Callback", 58);
    return c;
}

java::lang::Class* rice::p2p::util::XMLObjectInputStream_ValidationList_Callback::getClass0()
{
    return class_();
}

