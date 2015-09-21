// Generated from /pastry-2.1/src/rice/pastry/socket/nat/NATHandler.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::socket::nat::NATHandler
    : public virtual ::java::lang::Object
{
    virtual ::java::net::InetAddress* findFireWall(::java::net::InetAddress* bindAddress) /* throws(IOException) */ = 0;
    virtual ::java::net::InetAddress* getFireWallExternalAddress() = 0;
    virtual int32_t findAvailableFireWallPort(int32_t internal, int32_t external, int32_t tries, ::java::lang::String* appName) /* throws(IOException) */ = 0;
    virtual void openFireWallPort(int32_t local, int32_t external, ::java::lang::String* appName) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
