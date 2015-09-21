// Generated from /pastry-2.1/src/rice/pastry/socket/nat/StubNATHandler.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/socket/nat/NATHandler.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::StubNATHandler
    : public virtual ::java::lang::Object
    , public virtual NATHandler
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::String* errorString {  };
protected:
    void ctor(::rice::environment::Environment* environment, ::java::net::InetAddress* address);

public:
    ::java::net::InetAddress* getFireWallExternalAddress() override;
    ::java::net::InetAddress* findFireWall(::java::net::InetAddress* bindAddress) /* throws(IOException) */ override;
    int32_t findAvailableFireWallPort(int32_t internal, int32_t external, int32_t tries, ::java::lang::String* appName) /* throws(IOException) */ override;
    void openFireWallPort(int32_t local, int32_t external, ::java::lang::String* appName) /* throws(IOException) */ override;

    // Generated
    StubNATHandler(::rice::environment::Environment* environment, ::java::net::InetAddress* address);
protected:
    StubNATHandler(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
