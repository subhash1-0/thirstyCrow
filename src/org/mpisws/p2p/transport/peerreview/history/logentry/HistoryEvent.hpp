// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::logentry::HistoryEvent
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;
    virtual int16_t getType() = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;
    virtual ::java::nio::ByteBuffer* serialize() /* throws(IOException) */;

    // Generated
    HistoryEvent();
protected:
    HistoryEvent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
