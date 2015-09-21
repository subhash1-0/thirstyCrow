// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/reader/EntryDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/reader/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::history::reader::EntryDeserializer
    : public virtual ::java::lang::Object
{
    virtual ::java::lang::String* entryId(int16_t id) = 0;
    virtual ::java::lang::String* read(::org::mpisws::p2p::transport::peerreview::history::IndexEntry* ie, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
