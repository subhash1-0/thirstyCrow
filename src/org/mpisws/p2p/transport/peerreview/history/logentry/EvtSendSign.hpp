// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtSendSign.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;
    ::int8_tArray* signature {  };
    ::int8_tArray* restOfMessage {  };
protected:
    void ctor(::int8_tArray* signature, ::int8_tArray* restOfMessage);
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t signatureSize) /* throws(IOException) */;

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual int16_t getType();

    // Generated
    EvtSendSign(::int8_tArray* signature, ::int8_tArray* restOfMessage);
    EvtSendSign(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t signatureSize);
protected:
    EvtSendSign(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
