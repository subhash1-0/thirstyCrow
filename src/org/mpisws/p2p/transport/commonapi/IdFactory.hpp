// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/IdFactory.java

#pragma once

#include <org/mpisws/p2p/transport/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::commonapi::IdFactory
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::Id* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
