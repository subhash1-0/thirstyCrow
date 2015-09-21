// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar
#include <net/sbbi/upnp/devices/UPNPRootDevice.hpp>

extern void unimplemented_(const char16_t* name);
net::sbbi::upnp::devices::UPNPRootDevice::UPNPRootDevice(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

net::sbbi::upnp::devices::UPNPRootDevice::UPNPRootDevice(::java::net::URL* arg0, ::java::lang::String* arg1)
    : UPNPRootDevice(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

net::sbbi::upnp::devices::UPNPRootDevice::UPNPRootDevice(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware)
    : UPNPRootDevice(*static_cast< ::default_init_tag* >(0))
{
    ctor(deviceDefLoc, maxAge, vendorFirmware);
}

net::sbbi::upnp::devices::UPNPRootDevice::UPNPRootDevice(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware, ::java::lang::String* discoveryUSN, ::java::lang::String* discoveryUDN)
    : UPNPRootDevice(*static_cast< ::default_init_tag* >(0))
{
    ctor(deviceDefLoc, maxAge, vendorFirmware, discoveryUSN, discoveryUDN);
}

java::lang::Class*& net::sbbi::upnp::devices::UPNPRootDevice::class$net$sbbi$upnp$devices$UPNPRootDevice()
{
    clinit();
    return class$net$sbbi$upnp$devices$UPNPRootDevice_;
}
java::lang::Class* net::sbbi::upnp::devices::UPNPRootDevice::class$net$sbbi$upnp$devices$UPNPRootDevice_;
org::apache::commons::logging::Log*& net::sbbi::upnp::devices::UPNPRootDevice::log()
{
    clinit();
    return log_;
}
org::apache::commons::logging::Log* net::sbbi::upnp::devices::UPNPRootDevice::log_;

void ::net::sbbi::upnp::devices::UPNPRootDevice::ctor(::java::net::URL* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::net::sbbi::upnp::devices::UPNPRootDevice::ctor(::java::net::URL* arg0, ::java::lang::String* arg1)");
}

void ::net::sbbi::upnp::devices::UPNPRootDevice::ctor(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::net::sbbi::upnp::devices::UPNPRootDevice::ctor(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware)");
}

void ::net::sbbi::upnp::devices::UPNPRootDevice::ctor(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware, ::java::lang::String* discoveryUSN, ::java::lang::String* discoveryUDN)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::net::sbbi::upnp::devices::UPNPRootDevice::ctor(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware, ::java::lang::String* discoveryUSN, ::java::lang::String* discoveryUDN)");
}

/* private: void net::sbbi::upnp::devices::UPNPRootDevice::fillUPNPDevice(UPNPDevice* arg0, UPNPDevice* arg1, ::org::apache::commons::jxpath::JXPathContext* arg2, ::java::net::URL* arg3) */
/* private: void net::sbbi::upnp::devices::UPNPRootDevice::fillUPNPDeviceIconsList(UPNPDevice* arg0, ::org::apache::commons::jxpath::JXPathContext* arg1, ::java::net::URL* arg2) */
/* private: void net::sbbi::upnp::devices::UPNPRootDevice::fillUPNPServicesList(UPNPDevice* arg0, ::org::apache::commons::jxpath::JXPathContext* arg1) */
java::net::URL* net::sbbi::upnp::devices::UPNPRootDevice::getDeviceDefLoc()
{ /* stub */
return deviceDefLoc ; /* getter */
}

java::lang::String* net::sbbi::upnp::devices::UPNPRootDevice::getDeviceDefLocData()
{ /* stub */
return deviceDefLocData ; /* getter */
}

java::lang::String* net::sbbi::upnp::devices::UPNPRootDevice::getDiscoveryUDN()
{ /* stub */
return discoveryUDN ; /* getter */
}

java::lang::String* net::sbbi::upnp::devices::UPNPRootDevice::getDiscoveryUSN()
{ /* stub */
return discoveryUSN ; /* getter */
}

/* private: java::lang::String* net::sbbi::upnp::devices::UPNPRootDevice::getMandatoryData(::org::apache::commons::jxpath::JXPathContext* ctx, ::java::lang::String* ctxFieldName) */
/* private: java::lang::String* net::sbbi::upnp::devices::UPNPRootDevice::getNonMandatoryData(::org::apache::commons::jxpath::JXPathContext* arg0, ::java::lang::String* arg1) */
int32_t net::sbbi::upnp::devices::UPNPRootDevice::getSpecVersionMajor()
{ /* stub */
return specVersionMajor ; /* getter */
}

int32_t net::sbbi::upnp::devices::UPNPRootDevice::getSpecVersionMinor()
{ /* stub */
return specVersionMinor ; /* getter */
}

org::apache::commons::jxpath::Container* net::sbbi::upnp::devices::UPNPRootDevice::getUPNPDevice()
{ /* stub */
    unimplemented_(u"org::apache::commons::jxpath::Container* net::sbbi::upnp::devices::UPNPRootDevice::getUPNPDevice()");
    return 0;
}

java::net::URL* net::sbbi::upnp::devices::UPNPRootDevice::getURL(::java::lang::String* arg0, ::java::net::URL* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::URL* net::sbbi::upnp::devices::UPNPRootDevice::getURL(::java::lang::String* arg0, ::java::net::URL* arg1)");
    return 0;
}

java::net::URL* net::sbbi::upnp::devices::UPNPRootDevice::getURLBase()
{ /* stub */
    unimplemented_(u"java::net::URL* net::sbbi::upnp::devices::UPNPRootDevice::getURLBase()");
    return 0;
}

int64_t net::sbbi::upnp::devices::UPNPRootDevice::getValidityTime()
{ /* stub */
return validityTime ; /* getter */
}

java::lang::String* net::sbbi::upnp::devices::UPNPRootDevice::getVendorFirmware()
{ /* stub */
return vendorFirmware ; /* getter */
}

void net::sbbi::upnp::devices::UPNPRootDevice::resetValidityTime(::java::lang::String* newMaxAge)
{ /* stub */
    unimplemented_(u"void net::sbbi::upnp::devices::UPNPRootDevice::resetValidityTime(::java::lang::String* newMaxAge)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* net::sbbi::upnp::devices::UPNPRootDevice::class_()
{
    static ::java::lang::Class* c = ::class_(u"net.sbbi.upnp.devices.UPNPRootDevice", 36);
    return c;
}

java::lang::Class* net::sbbi::upnp::devices::UPNPRootDevice::getClass0()
{
    return class_();
}

