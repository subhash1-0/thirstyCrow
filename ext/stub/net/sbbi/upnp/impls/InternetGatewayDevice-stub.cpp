// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar
#include <net/sbbi/upnp/impls/InternetGatewayDevice.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace net
{
    namespace sbbi
    {
        namespace upnp
        {
            namespace impls
            {
typedef ::SubArray< ::net::sbbi::upnp::impls::InternetGatewayDevice, ::java::lang::ObjectArray > InternetGatewayDeviceArray;
            } // impls
        } // upnp
    } // sbbi
} // net

extern void unimplemented_(const char16_t* name);
net::sbbi::upnp::impls::InternetGatewayDevice::InternetGatewayDevice(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

net::sbbi::upnp::impls::InternetGatewayDevice::InternetGatewayDevice(::net::sbbi::upnp::devices::UPNPRootDevice* igd)
    : InternetGatewayDevice(*static_cast< ::default_init_tag* >(0))
{
    ctor(igd);
}

java::lang::Class*& net::sbbi::upnp::impls::InternetGatewayDevice::class$net$sbbi$upnp$impls$InternetGatewayDevice()
{
    clinit();
    return class$net$sbbi$upnp$impls$InternetGatewayDevice_;
}
java::lang::Class* net::sbbi::upnp::impls::InternetGatewayDevice::class$net$sbbi$upnp$impls$InternetGatewayDevice_;
org::apache::commons::logging::Log*& net::sbbi::upnp::impls::InternetGatewayDevice::log()
{
    clinit();
    return log_;
}
org::apache::commons::logging::Log* net::sbbi::upnp::impls::InternetGatewayDevice::log_;

void ::net::sbbi::upnp::impls::InternetGatewayDevice::ctor(::net::sbbi::upnp::devices::UPNPRootDevice* igd)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::net::sbbi::upnp::impls::InternetGatewayDevice::ctor(::net::sbbi::upnp::devices::UPNPRootDevice* igd)");
}

/* private: void ::net::sbbi::upnp::impls::InternetGatewayDevice::ctor(::net::sbbi::upnp::devices::UPNPRootDevice* arg0, bool arg1, bool arg2) */
bool net::sbbi::upnp::impls::InternetGatewayDevice::addPortMapping(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, int32_t arg3, ::java::lang::String* arg4, int32_t arg5, ::java::lang::String* arg6)
{ /* stub */
    unimplemented_(u"bool net::sbbi::upnp::impls::InternetGatewayDevice::addPortMapping(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, int32_t arg3, ::java::lang::String* arg4, int32_t arg5, ::java::lang::String* arg6)");
    return 0;
}

/* private: void net::sbbi::upnp::impls::InternetGatewayDevice::checkPortMappingProtocol(::java::lang::String* prot) */
/* private: void net::sbbi::upnp::impls::InternetGatewayDevice::checkPortRange(int32_t port) */
bool net::sbbi::upnp::impls::InternetGatewayDevice::deletePortMapping(::java::lang::String* arg0, int32_t arg1, ::java::lang::String* arg2)
{ /* stub */
    unimplemented_(u"bool net::sbbi::upnp::impls::InternetGatewayDevice::deletePortMapping(::java::lang::String* arg0, int32_t arg1, ::java::lang::String* arg2)");
    return 0;
}

net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getDevices(int32_t timeout)
{ /* stub */
    clinit();
    unimplemented_(u"net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getDevices(int32_t timeout)");
    return 0;
}

net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getDevices(int32_t timeout, int32_t ttl, int32_t mx, ::java::net::NetworkInterface* ni)
{ /* stub */
    clinit();
    unimplemented_(u"net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getDevices(int32_t timeout, int32_t ttl, int32_t mx, ::java::net::NetworkInterface* ni)");
    return 0;
}

java::lang::String* net::sbbi::upnp::impls::InternetGatewayDevice::getExternalIPAddress()
{ /* stub */
    unimplemented_(u"java::lang::String* net::sbbi::upnp::impls::InternetGatewayDevice::getExternalIPAddress()");
    return 0;
}

net::sbbi::upnp::messages::ActionResponse* net::sbbi::upnp::impls::InternetGatewayDevice::getGenericPortMappingEntry(int32_t arg0)
{ /* stub */
    unimplemented_(u"net::sbbi::upnp::messages::ActionResponse* net::sbbi::upnp::impls::InternetGatewayDevice::getGenericPortMappingEntry(int32_t arg0)");
    return 0;
}

net::sbbi::upnp::devices::UPNPRootDevice* net::sbbi::upnp::impls::InternetGatewayDevice::getIGDRootDevice()
{ /* stub */
    unimplemented_(u"net::sbbi::upnp::devices::UPNPRootDevice* net::sbbi::upnp::impls::InternetGatewayDevice::getIGDRootDevice()");
    return 0;
}

net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getIPDevices(int32_t timeout)
{ /* stub */
    clinit();
    unimplemented_(u"net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getIPDevices(int32_t timeout)");
    return 0;
}

java::lang::Integer* net::sbbi::upnp::impls::InternetGatewayDevice::getNatMappingsCount()
{ /* stub */
    unimplemented_(u"java::lang::Integer* net::sbbi::upnp::impls::InternetGatewayDevice::getNatMappingsCount()");
    return 0;
}

java::lang::Integer* net::sbbi::upnp::impls::InternetGatewayDevice::getNatTableSize()
{ /* stub */
    unimplemented_(u"java::lang::Integer* net::sbbi::upnp::impls::InternetGatewayDevice::getNatTableSize()");
    return 0;
}

net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getPPPDevices(int32_t timeout)
{ /* stub */
    clinit();
    unimplemented_(u"net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::getPPPDevices(int32_t timeout)");
    return 0;
}

net::sbbi::upnp::messages::ActionResponse* net::sbbi::upnp::impls::InternetGatewayDevice::getSpecificPortMappingEntry(::java::lang::String* arg0, int32_t arg1, ::java::lang::String* arg2)
{ /* stub */
    unimplemented_(u"net::sbbi::upnp::messages::ActionResponse* net::sbbi::upnp::impls::InternetGatewayDevice::getSpecificPortMappingEntry(::java::lang::String* arg0, int32_t arg1, ::java::lang::String* arg2)");
    return 0;
}

/* private: net::sbbi::upnp::impls::InternetGatewayDeviceArray* net::sbbi::upnp::impls::InternetGatewayDevice::lookupDeviceDevices(int32_t arg0, int32_t arg1, int32_t arg2, bool arg3, bool arg4, ::java::net::NetworkInterface* arg5) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* net::sbbi::upnp::impls::InternetGatewayDevice::class_()
{
    static ::java::lang::Class* c = ::class_(u"net.sbbi.upnp.impls.InternetGatewayDevice", 41);
    return c;
}

java::lang::Class* net::sbbi::upnp::impls::InternetGatewayDevice::getClass0()
{
    return class_();
}

