// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/devices/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/impls/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/messages/fwd-pastry-2.1.hpp>
#include <org/apache/commons/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class net::sbbi::upnp::impls::InternetGatewayDevice
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::Class* class$net$sbbi$upnp$impls$InternetGatewayDevice_;
    ::net::sbbi::upnp::devices::UPNPRootDevice* igd {  };
    static ::org::apache::commons::logging::Log* log_;
    ::net::sbbi::upnp::messages::UPNPMessageFactory* msgFactory {  };

protected:
    void ctor(::net::sbbi::upnp::devices::UPNPRootDevice* igd);
    /*void ctor(::net::sbbi::upnp::devices::UPNPRootDevice* arg0, bool arg1, bool arg2); (private) */

public:
    virtual bool addPortMapping(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, int32_t arg3, ::java::lang::String* arg4, int32_t arg5, ::java::lang::String* arg6);
    /*void checkPortMappingProtocol(::java::lang::String* prot); (private) */
    /*void checkPortRange(int32_t port); (private) */
    virtual bool deletePortMapping(::java::lang::String* arg0, int32_t arg1, ::java::lang::String* arg2);
    static InternetGatewayDeviceArray* getDevices(int32_t timeout);
    static InternetGatewayDeviceArray* getDevices(int32_t timeout, int32_t ttl, int32_t mx, ::java::net::NetworkInterface* ni);
    virtual ::java::lang::String* getExternalIPAddress();
    virtual ::net::sbbi::upnp::messages::ActionResponse* getGenericPortMappingEntry(int32_t arg0);
    virtual ::net::sbbi::upnp::devices::UPNPRootDevice* getIGDRootDevice();
    static InternetGatewayDeviceArray* getIPDevices(int32_t timeout);
    virtual ::java::lang::Integer* getNatMappingsCount();
    virtual ::java::lang::Integer* getNatTableSize();
    static InternetGatewayDeviceArray* getPPPDevices(int32_t timeout);
    virtual ::net::sbbi::upnp::messages::ActionResponse* getSpecificPortMappingEntry(::java::lang::String* arg0, int32_t arg1, ::java::lang::String* arg2);
    /*static InternetGatewayDeviceArray* lookupDeviceDevices(int32_t arg0, int32_t arg1, int32_t arg2, bool arg3, bool arg4, ::java::net::NetworkInterface* arg5); (private) */

    // Generated
    InternetGatewayDevice(::net::sbbi::upnp::devices::UPNPRootDevice* igd);
protected:
    InternetGatewayDevice(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static ::java::lang::Class*& class$net$sbbi$upnp$impls$InternetGatewayDevice();

private:
    static ::org::apache::commons::logging::Log*& log();
    virtual ::java::lang::Class* getClass0();
};
