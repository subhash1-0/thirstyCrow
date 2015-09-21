// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/reader/LogReader.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/reader/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::reader::LogReader
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    EntryDeserializer* deserializer {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };
    int64_t entryIndex {  };
protected:
    void ctor(::java::lang::String* name, ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* factory, EntryDeserializer* deserializer) /* throws(IOException) */;

public:
    virtual ::java::lang::String* readEntry() /* throws(IOException) */;

    // Generated
    LogReader(::java::lang::String* name, ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* factory, EntryDeserializer* deserializer);
protected:
    LogReader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
