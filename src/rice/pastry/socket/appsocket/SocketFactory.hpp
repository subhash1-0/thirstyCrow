// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/SocketFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::socket::appsocket::SocketFactory
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::Cancellable* getAppSocket(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* getSocketChannel(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
