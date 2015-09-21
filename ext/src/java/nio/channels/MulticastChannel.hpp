// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/NetworkChannel.hpp>

struct java::nio::channels::MulticastChannel
    : public virtual NetworkChannel
{

    /*void close(); (already declared) */
    virtual MembershipKey* join(::java::net::InetAddress* arg0, ::java::net::NetworkInterface* arg1) = 0;
    virtual MembershipKey* join(::java::net::InetAddress* arg0, ::java::net::NetworkInterface* arg1, ::java::net::InetAddress* arg2) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
