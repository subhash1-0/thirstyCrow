// Generated from /pastry-2.1/src/rice/p2p/commonapi/IdRange.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::commonapi::IdRange
    : public virtual ::java::io::Serializable
{
    virtual bool containsId(Id* key) = 0;
    virtual Id* getCCWId() = 0;
    virtual Id* getCWId() = 0;
    virtual IdRange* getComplementRange() = 0;
    virtual IdRange* mergeRange(IdRange* range) = 0;
    virtual IdRange* diffRange(IdRange* range) = 0;
    virtual IdRange* intersectRange(IdRange* range) = 0;
    virtual bool isEmpty() = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
