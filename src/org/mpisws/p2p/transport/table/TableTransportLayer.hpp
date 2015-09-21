// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/table/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>

struct org::mpisws::p2p::transport::table::TableTransportLayer
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
{
    virtual ::rice::p2p::commonapi::Cancellable* requestValue(::java::lang::Object* source, ::java::lang::Object* key, ::rice::Continuation* c, ::java::util::Map* options) = 0;
    virtual bool hasKey(::java::lang::Object* k) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
