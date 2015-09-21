// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/MyEntryDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/BasicEntryDeserializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEvents.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer
    : public ::org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer
    , public virtual MyEvents
{

public:
    typedef ::org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer super;

public: /* package */
    ::org::mpisws::p2p::transport::util::Serializer* serializer {  };
protected:
    void ctor(::org::mpisws::p2p::transport::util::Serializer* serializer);

public:
    ::java::lang::String* entryId(int16_t id) override;
    ::java::lang::String* read(::org::mpisws::p2p::transport::peerreview::history::IndexEntry* ie, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history) /* throws(IOException) */ override;

    // Generated
    MyEntryDeserializer(::org::mpisws::p2p::transport::util::Serializer* serializer);
protected:
    MyEntryDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
