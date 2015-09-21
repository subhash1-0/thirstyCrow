// Generated from /pastry-2.1/src/rice/pastry/NetworkListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::NetworkListener
    : public virtual ::java::lang::Object
{
    static constexpr int32_t TYPE_TCP { int32_t(0) };
    static constexpr int32_t TYPE_UDP { int32_t(1) };
    static constexpr int32_t TYPE_SR_TCP { int32_t(16) };
    static constexpr int32_t TYPE_SR_UDP { int32_t(17) };
    static constexpr int32_t REASON_NORMAL { int32_t(0) };
    static constexpr int32_t REASON_SR { int32_t(1) };
    static constexpr int32_t REASON_BOOTSTRAP { int32_t(2) };
    static constexpr int32_t REASON_ACC_NORMAL { int32_t(3) };
    static constexpr int32_t REASON_ACC_SR { int32_t(4) };
    static constexpr int32_t REASON_ACC_BOOTSTRAP { int32_t(5) };
    static constexpr int32_t REASON_APP_SOCKET_NORMAL { int32_t(6) };
    virtual void channelOpened(::java::net::InetSocketAddress* addr, int32_t reason) = 0;
    virtual void channelClosed(::java::net::InetSocketAddress* addr) = 0;
    virtual void dataSent(int32_t msgAddress, int16_t msgType, ::java::net::InetSocketAddress* socketAddress, int32_t size, int32_t wireType) = 0;
    virtual void dataReceived(int32_t msgAddress, int16_t msgType, ::java::net::InetSocketAddress* socketAddress, int32_t size, int32_t wireType) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
