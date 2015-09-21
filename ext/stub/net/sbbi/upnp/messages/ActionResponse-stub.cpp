// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar
#include <net/sbbi/upnp/messages/ActionResponse.hpp>

extern void unimplemented_(const char16_t* name);
net::sbbi::upnp::messages::ActionResponse::ActionResponse(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

net::sbbi::upnp::messages::ActionResponse::ActionResponse()
    : ActionResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::net::sbbi::upnp::messages::ActionResponse::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::net::sbbi::upnp::messages::ActionResponse::ctor()");
}

void net::sbbi::upnp::messages::ActionResponse::addResult(::net::sbbi::upnp::services::ServiceActionArgument* arg, ::java::lang::String* value)
{ /* stub */
    unimplemented_(u"void net::sbbi::upnp::messages::ActionResponse::addResult(::net::sbbi::upnp::services::ServiceActionArgument* arg, ::java::lang::String* value)");
}

net::sbbi::upnp::services::ServiceActionArgument* net::sbbi::upnp::messages::ActionResponse::getOutActionArgument(::java::lang::String* actionArgumentName)
{ /* stub */
    unimplemented_(u"net::sbbi::upnp::services::ServiceActionArgument* net::sbbi::upnp::messages::ActionResponse::getOutActionArgument(::java::lang::String* actionArgumentName)");
    return 0;
}

java::util::Set* net::sbbi::upnp::messages::ActionResponse::getOutActionArgumentNames()
{ /* stub */
    unimplemented_(u"java::util::Set* net::sbbi::upnp::messages::ActionResponse::getOutActionArgumentNames()");
    return 0;
}

java::lang::String* net::sbbi::upnp::messages::ActionResponse::getOutActionArgumentValue(::java::lang::String* actionArgumentName)
{ /* stub */
    unimplemented_(u"java::lang::String* net::sbbi::upnp::messages::ActionResponse::getOutActionArgumentValue(::java::lang::String* actionArgumentName)");
    return 0;
}

java::lang::String* net::sbbi::upnp::messages::ActionResponse::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* net::sbbi::upnp::messages::ActionResponse::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* net::sbbi::upnp::messages::ActionResponse::class_()
{
    static ::java::lang::Class* c = ::class_(u"net.sbbi.upnp.messages.ActionResponse", 37);
    return c;
}

java::lang::Class* net::sbbi::upnp::messages::ActionResponse::getClass0()
{
    return class_();
}

