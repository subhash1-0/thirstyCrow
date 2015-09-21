// Generated from /pastry-2.1/src/rice/pastry/NetworkListener.java
#include <rice/pastry/NetworkListener.hpp>

constexpr int32_t rice::pastry::NetworkListener::TYPE_TCP;

constexpr int32_t rice::pastry::NetworkListener::TYPE_UDP;

constexpr int32_t rice::pastry::NetworkListener::TYPE_SR_TCP;

constexpr int32_t rice::pastry::NetworkListener::TYPE_SR_UDP;

constexpr int32_t rice::pastry::NetworkListener::REASON_NORMAL;

constexpr int32_t rice::pastry::NetworkListener::REASON_SR;

constexpr int32_t rice::pastry::NetworkListener::REASON_BOOTSTRAP;

constexpr int32_t rice::pastry::NetworkListener::REASON_ACC_NORMAL;

constexpr int32_t rice::pastry::NetworkListener::REASON_ACC_SR;

constexpr int32_t rice::pastry::NetworkListener::REASON_ACC_BOOTSTRAP;

constexpr int32_t rice::pastry::NetworkListener::REASON_APP_SOCKET_NORMAL;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::NetworkListener::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.NetworkListener", 27);
    return c;
}

