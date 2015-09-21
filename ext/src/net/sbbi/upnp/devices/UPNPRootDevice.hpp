// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/devices/fwd-pastry-2.1.hpp>
#include <org/apache/commons/jxpath/fwd-pastry-2.1.hpp>
#include <org/apache/commons/jxpath/xml/fwd-pastry-2.1.hpp>
#include <org/apache/commons/logging/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/devices/UPNPDevice.hpp>

struct default_init_tag;

class net::sbbi::upnp::devices::UPNPRootDevice
    : public UPNPDevice
{

public:
    typedef UPNPDevice super;

private:
    ::org::apache::commons::jxpath::xml::DocumentContainer* UPNPDevice_ {  };
    ::java::net::URL* URLBase {  };
    static ::java::lang::Class* class$net$sbbi$upnp$devices$UPNPRootDevice_;
    int64_t creationTime {  };
    ::java::net::URL* deviceDefLoc {  };
    ::java::lang::String* deviceDefLocData {  };
    ::java::lang::String* discoveryUDN {  };
    ::java::lang::String* discoveryUSN {  };
    static ::org::apache::commons::logging::Log* log_;
    int32_t specVersionMajor {  };
    int32_t specVersionMinor {  };
    int64_t validityTime {  };
    ::java::lang::String* vendorFirmware {  };

protected:
    void ctor(::java::net::URL* arg0, ::java::lang::String* arg1);
    void ctor(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware);
    void ctor(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware, ::java::lang::String* discoveryUSN, ::java::lang::String* discoveryUDN);
    /*void fillUPNPDevice(UPNPDevice* arg0, UPNPDevice* arg1, ::org::apache::commons::jxpath::JXPathContext* arg2, ::java::net::URL* arg3); (private) */
    /*void fillUPNPDeviceIconsList(UPNPDevice* arg0, ::org::apache::commons::jxpath::JXPathContext* arg1, ::java::net::URL* arg2); (private) */
    /*void fillUPNPServicesList(UPNPDevice* arg0, ::org::apache::commons::jxpath::JXPathContext* arg1); (private) */

public:
    virtual ::java::net::URL* getDeviceDefLoc();
    virtual ::java::lang::String* getDeviceDefLocData();
    virtual ::java::lang::String* getDiscoveryUDN();
    virtual ::java::lang::String* getDiscoveryUSN();
    /*::java::lang::String* getMandatoryData(::org::apache::commons::jxpath::JXPathContext* ctx, ::java::lang::String* ctxFieldName); (private) */
    /*::java::lang::String* getNonMandatoryData(::org::apache::commons::jxpath::JXPathContext* arg0, ::java::lang::String* arg1); (private) */
    virtual int32_t getSpecVersionMajor();
    virtual int32_t getSpecVersionMinor();
    virtual ::org::apache::commons::jxpath::Container* getUPNPDevice();
    static ::java::net::URL* getURL(::java::lang::String* arg0, ::java::net::URL* arg1);
    virtual ::java::net::URL* getURLBase();
    virtual int64_t getValidityTime();
    virtual ::java::lang::String* getVendorFirmware();
    virtual void resetValidityTime(::java::lang::String* newMaxAge);

    // Generated
    UPNPRootDevice(::java::net::URL* arg0, ::java::lang::String* arg1);
    UPNPRootDevice(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware);
    UPNPRootDevice(::java::net::URL* deviceDefLoc, ::java::lang::String* maxAge, ::java::lang::String* vendorFirmware, ::java::lang::String* discoveryUSN, ::java::lang::String* discoveryUDN);
protected:
    UPNPRootDevice(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static ::java::lang::Class*& class$net$sbbi$upnp$devices$UPNPRootDevice();

private:
    static ::org::apache::commons::logging::Log*& log();
    virtual ::java::lang::Class* getClass0();
};
