// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AccusationMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/Statement.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::AccusationMessage
    : public ::org::mpisws::p2p::transport::peerreview::statement::Statement
{

public:
    typedef ::org::mpisws::p2p::transport::peerreview::statement::Statement super;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence);
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer) /* throws(IOException) */;
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* evidenceRecord, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence);

public:
    int16_t getType() override;

public: /* protected */
    bool isResponse() override;

    // Generated

public:
    AccusationMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence);
    AccusationMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer);
    AccusationMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* evidenceRecord, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence);
protected:
    AccusationMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
