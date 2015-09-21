// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/nio/channels/Channel.hpp>

struct java::nio::channels::NetworkChannel
    : public virtual Channel
{

    virtual NetworkChannel* bind(::java::net::SocketAddress* arg0) = 0;
    virtual ::java::net::SocketAddress* getLocalAddress() = 0;
    virtual ::java::lang::Object* getOption(::java::net::SocketOption* arg0) = 0;
    virtual NetworkChannel* setOption(::java::net::SocketOption* arg0, ::java::lang::Object* arg1) = 0;
    virtual ::java::util::Set* supportedOptions() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
