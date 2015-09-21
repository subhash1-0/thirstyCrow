// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/IndexEntryFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory
    : public virtual ::java::lang::Object
{
    virtual IndexEntry* build(::rice::p2p::commonapi::rawserialization::InputBuffer* indexFile) /* throws(IOException) */ = 0;
    virtual int32_t getSerializedSize() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
