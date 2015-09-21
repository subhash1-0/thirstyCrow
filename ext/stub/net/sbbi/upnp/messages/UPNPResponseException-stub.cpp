// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar
#include <net/sbbi/upnp/messages/UPNPResponseException.hpp>

extern void unimplemented_(const char16_t* name);
net::sbbi::upnp::messages::UPNPResponseException::UPNPResponseException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

net::sbbi::upnp::messages::UPNPResponseException::UPNPResponseException()
    : UPNPResponseException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

net::sbbi::upnp::messages::UPNPResponseException::UPNPResponseException(int32_t detailErrorCode, ::java::lang::String* detailErrorDescription)
    : UPNPResponseException(*static_cast< ::default_init_tag* >(0))
{
    ctor(detailErrorCode, detailErrorDescription);
}

constexpr int64_t net::sbbi::upnp::messages::UPNPResponseException::serialVersionUID;

void ::net::sbbi::upnp::messages::UPNPResponseException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::net::sbbi::upnp::messages::UPNPResponseException::ctor()");
}

void ::net::sbbi::upnp::messages::UPNPResponseException::ctor(int32_t detailErrorCode, ::java::lang::String* detailErrorDescription)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::net::sbbi::upnp::messages::UPNPResponseException::ctor(int32_t detailErrorCode, ::java::lang::String* detailErrorDescription)");
}

int32_t net::sbbi::upnp::messages::UPNPResponseException::getDetailErrorCode()
{ /* stub */
return detailErrorCode ; /* getter */
}

java::lang::String* net::sbbi::upnp::messages::UPNPResponseException::getDetailErrorDescription()
{ /* stub */
return detailErrorDescription ; /* getter */
}

java::lang::String* net::sbbi::upnp::messages::UPNPResponseException::getFaultCode()
{ /* stub */
return faultCode ; /* getter */
}

java::lang::String* net::sbbi::upnp::messages::UPNPResponseException::getFaultString()
{ /* stub */
return faultString ; /* getter */
}

java::lang::String* net::sbbi::upnp::messages::UPNPResponseException::getLocalizedMessage()
{ /* stub */
    unimplemented_(u"java::lang::String* net::sbbi::upnp::messages::UPNPResponseException::getLocalizedMessage()");
    return 0;
}

java::lang::String* net::sbbi::upnp::messages::UPNPResponseException::getMessage()
{ /* stub */
    unimplemented_(u"java::lang::String* net::sbbi::upnp::messages::UPNPResponseException::getMessage()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* net::sbbi::upnp::messages::UPNPResponseException::class_()
{
    static ::java::lang::Class* c = ::class_(u"net.sbbi.upnp.messages.UPNPResponseException", 44);
    return c;
}

java::lang::Class* net::sbbi::upnp::messages::UPNPResponseException::getClass0()
{
    return class_();
}

