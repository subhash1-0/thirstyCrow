// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtSign.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign
    : public HistoryEvent
{

public:
    typedef HistoryEvent super;
    ::int8_tArray* hTopMinusOne {  };
    ::int8_tArray* signature {  };
protected:
    void ctor(::int8_tArray* hTopMinusOne, ::int8_tArray* signature);

public:
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    EvtSign(::int8_tArray* hTopMinusOne, ::int8_tArray* signature);
    EvtSign(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize);
protected:
    EvtSign(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::nio::ByteBuffer* serialize();

private:
    virtual ::java::lang::Class* getClass0();
};
