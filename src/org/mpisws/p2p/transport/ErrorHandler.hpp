// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ErrorHandler.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::ErrorHandler
    : public virtual ::java::lang::Object
{
    virtual void receivedUnexpectedData(::java::lang::Object* i, ::int8_tArray* bytes, int32_t location, ::java::util::Map* options) = 0;
    virtual void receivedException(::java::lang::Object* i, ::java::lang::Throwable* error) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
