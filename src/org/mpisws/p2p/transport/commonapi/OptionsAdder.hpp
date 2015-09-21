// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/OptionsAdder.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::commonapi::OptionsAdder
    : public virtual ::java::lang::Object
{
    virtual ::java::util::Map* addOptions(::java::util::Map* options, ::rice::p2p::commonapi::rawserialization::RawMessage* m) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
