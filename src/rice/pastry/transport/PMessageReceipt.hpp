// Generated from /pastry-2.1/src/rice/pastry/transport/PMessageReceipt.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct rice::pastry::transport::PMessageReceipt
    : public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
{
    ::rice::pastry::NodeHandle* getIdentifier() = 0;
    ::rice::pastry::messaging::Message* getMessage() = 0;
    /*::java::util::Map* getOptions(); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
};
