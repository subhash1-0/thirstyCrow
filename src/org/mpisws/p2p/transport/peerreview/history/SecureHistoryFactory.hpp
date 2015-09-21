// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory
    : public virtual ::java::lang::Object
{
    virtual SecureHistory* create(::java::lang::String* name, int64_t baseSeq, ::int8_tArray* baseHash) /* throws(IOException) */ = 0;
    virtual SecureHistory* createTemp(int64_t baseSeq, ::int8_tArray* baseHash) /* throws(IOException) */ = 0;
    virtual SecureHistory* open(::java::lang::String* name, ::java::lang::String* mode) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
