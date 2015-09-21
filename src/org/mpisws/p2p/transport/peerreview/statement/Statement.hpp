// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/statement/Statement.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::statement::Statement
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* originator {  };
    ::rice::p2p::commonapi::rawserialization::RawSerializable* subject {  };
    int64_t evidenceSeq {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence);
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

public: /* protected */
    virtual bool isResponse() = 0;

    // Generated

public:
    Statement(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence);
    Statement(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer);
protected:
    Statement(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
