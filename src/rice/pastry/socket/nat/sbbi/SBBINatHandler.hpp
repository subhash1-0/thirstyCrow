// Generated from /pastry-2.1/src/rice/pastry/socket/nat/sbbi/SBBINatHandler.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/impls/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/messages/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/sbbi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/socket/nat/NATHandler.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::sbbi::SBBINatHandler
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::socket::nat::NATHandler
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::Environment* environment {  };
    bool searchedForFireWall {  };
    ::net::sbbi::upnp::impls::InternetGatewayDevice* fireWall {  };
    ::java::net::InetAddress* fireWallExternalAddress {  };
    ::java::net::InetAddress* localAddress {  };
protected:
    void ctor(::rice::environment::Environment* env, ::java::net::InetAddress* localAddress);

public:
    ::java::net::InetAddress* findFireWall(::java::net::InetAddress* bindAddress) /* throws(IOException) */ override;

public: /* package */
    int32_t findPortTries {  };

public:
    int32_t findAvailableFireWallPort(int32_t internal, int32_t external, int32_t tries, ::java::lang::String* appName) /* throws(IOException) */ override;
    static constexpr int32_t MAX_PORT { int32_t(65535) };

private:
    bool checkSpecificPortMappingEntryResponse(::net::sbbi::upnp::messages::ActionResponse* response, int32_t internal, int32_t external, ::java::lang::String* type, ::java::lang::String* app);

public:
    void openFireWallPort(int32_t local, int32_t external, ::java::lang::String* appName) /* throws(IOException) */ override;
    ::java::net::InetAddress* getFireWallExternalAddress() override;

    // Generated
    SBBINatHandler(::rice::environment::Environment* env, ::java::net::InetAddress* localAddress);
protected:
    SBBINatHandler(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
