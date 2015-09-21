// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/AuditResponse.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::AuditResponse
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* logOwner {  };
    ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* logSnippet {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* logOwner, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* logSnippet);

public:
    int16_t getEvidenceType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* getLogSnippet();
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getLogOwner();
    virtual int64_t getFirstSeq();

    // Generated
    AuditResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* logOwner, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* logSnippet);
    AuditResponse(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize);
protected:
    AuditResponse(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
