// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/devices/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/services/fwd-pastry-2.1.hpp>
#include <org/apache/commons/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class net::sbbi::upnp::devices::UPNPDevice
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::String* UDN {  };
    int64_t UPC {  };
    ::java::lang::String* USN {  };
    ::java::util::List* childDevices {  };

private:
    static ::java::lang::Class* class$net$sbbi$upnp$devices$UPNPDevice_;

public: /* protected */
    ::java::util::List* deviceIcons {  };
    ::java::lang::String* deviceType {  };
    ::java::lang::String* friendlyName {  };

private:
    static ::org::apache::commons::logging::Log* log_;

public: /* protected */
    ::java::lang::String* manufacturer {  };
    ::java::net::URL* manufacturerURL {  };
    ::java::lang::String* modelDescription {  };
    ::java::lang::String* modelName {  };
    ::java::lang::String* modelNumber {  };
    ::java::lang::String* modelURL {  };
    UPNPDevice* parent {  };
    ::java::net::URL* presentationURL {  };
    ::java::lang::String* serialNumber {  };
    ::java::util::List* services {  };

protected:
    void ctor();

public:
    virtual UPNPDevice* getChildDevice(::java::lang::String* arg0);
    virtual ::java::util::List* getChildDevices();
    virtual ::java::util::List* getDeviceIcons();
    virtual ::java::lang::String* getDeviceType();
    virtual UPNPDevice* getDirectParent();
    virtual ::java::lang::String* getFriendlyName();
    virtual ::java::lang::String* getManufacturer();
    virtual ::java::net::URL* getManufacturerURL();
    virtual ::java::lang::String* getModelDescription();
    virtual ::java::lang::String* getModelName();
    virtual ::java::lang::String* getModelNumber();
    virtual ::java::lang::String* getModelURL();
    virtual ::java::net::URL* getPresentationURL();
    virtual ::java::lang::String* getSerialNumber();
    virtual ::net::sbbi::upnp::services::UPNPService* getService(::java::lang::String* arg0);
    virtual ::net::sbbi::upnp::services::UPNPService* getServiceByID(::java::lang::String* arg0);
    virtual ::java::util::List* getServices();
    virtual ::java::util::List* getServices(::java::lang::String* arg0);
    virtual ::java::util::List* getTopLevelChildDevices();
    virtual ::java::lang::String* getUDN();
    virtual int64_t getUPC();
    virtual ::java::lang::String* getUSN();
    virtual bool isRootDevice();
    ::java::lang::String* toString() override;

    // Generated
    UPNPDevice();
protected:
    UPNPDevice(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static ::java::lang::Class*& class$net$sbbi$upnp$devices$UPNPDevice();

private:
    static ::org::apache::commons::logging::Log*& log();
    virtual ::java::lang::Class* getClass0();
};
