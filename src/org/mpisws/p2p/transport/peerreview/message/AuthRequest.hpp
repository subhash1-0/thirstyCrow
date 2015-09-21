// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AuthRequest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::AuthRequest
    : public virtual ::java::lang::Object
    , public virtual PeerReviewMessage
{

public:
    typedef ::java::lang::Object super;
    int64_t timestamp {  };
    ::rice::p2p::commonapi::rawserialization::RawSerializable* subject {  };
protected:
    void ctor(int64_t timestamp, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject);

public:
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    AuthRequest(int64_t timestamp, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject);
    AuthRequest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer);
protected:
    AuthRequest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
