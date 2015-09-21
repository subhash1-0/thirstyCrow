// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/EvidenceSerializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer
    : public virtual ::java::lang::Object
{
    virtual Evidence* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t type, bool isResponse) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
