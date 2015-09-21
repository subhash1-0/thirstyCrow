// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtInit.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit
    : public HistoryEvent
{

public:
    typedef HistoryEvent super;

public: /* package */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* handle {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* handle);

public:
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    EvtInit(::rice::p2p::commonapi::rawserialization::RawSerializable* handle);
    EvtInit(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer);
protected:
    EvtInit(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::nio::ByteBuffer* serialize();

private:
    virtual ::java::lang::Class* getClass0();
};
