// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>

struct org::mpisws::p2p::transport::priority::PriorityTransportLayer
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
{

private:
    static ::java::lang::String* OPTION_PRIORITY_;

public:
    static constexpr int8_t MAX_PRIORITY { int8_t(-15) };
    static constexpr int8_t HIGH_PRIORITY { int8_t(-10) };
    static constexpr int8_t MEDIUM_HIGH_PRIORITY { int8_t(-5) };
    static constexpr int8_t MEDIUM_PRIORITY { int8_t(0) };
    static constexpr int8_t MEDIUM_LOW_PRIORITY { int8_t(5) };
    static constexpr int8_t LOW_PRIORITY { int8_t(10) };
    static constexpr int8_t LOWEST_PRIORITY { int8_t(15) };
    static constexpr int8_t DEFAULT_PRIORITY { int8_t(0) };
    static constexpr int32_t STATUS_NOT_CONNECTED { int32_t(0) };
    static constexpr int32_t STATUS_CONNECTING { int32_t(1) };
    static constexpr int32_t STATUS_CONNECTED { int32_t(2) };
    virtual void addTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener) = 0;
    virtual void removeTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener) = 0;
    virtual void addPriorityTransportLayerListener(PriorityTransportLayerListener* listener) = 0;
    virtual void removePriorityTransportLayerListener(PriorityTransportLayerListener* listener) = 0;
    virtual int32_t connectionStatus(::java::lang::Object* i) = 0;
    virtual ::java::util::Map* connectionOptions(::java::lang::Object* i) = 0;
    virtual ::java::util::Collection* nodesWithPendingMessages() = 0;
    virtual int32_t queueLength(::java::lang::Object* i) = 0;
    virtual int64_t bytesPending(::java::lang::Object* i) = 0;
    virtual ::java::util::List* getPendingMessages(::java::lang::Object* i) = 0;
    virtual void openPrimaryConnection(::java::lang::Object* i, ::java::util::Map* options) = 0;
    virtual void addPrimarySocketListener(PrimarySocketListener* listener) = 0;
    virtual void removePrimarySocketListener(PrimarySocketListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
    static ::java::lang::String*& OPTION_PRIORITY();
};
