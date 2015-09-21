// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/statement/IncompleteStatementInfo.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    bool finished {  };
    ::java::lang::Object* sender {  };
    int64_t currentTimeout {  };
    Statement* statement {  };
    bool isMissingCertificate_ {  };
    ::rice::p2p::commonapi::rawserialization::RawSerializable* missingCertificateID {  };
    ::java::util::Map* options {  };
protected:
    void ctor(bool finished, ::java::lang::Object* source, int64_t currentTimeout, Statement* statement, bool isMissingCertificate, ::rice::p2p::commonapi::rawserialization::RawSerializable* missingCertificateId, ::java::util::Map* options);

public:
    virtual bool isMissingCertificate();
    virtual bool isFinished();
    virtual int64_t getCurrentTimeout();

    // Generated
    IncompleteStatementInfo(bool finished, ::java::lang::Object* source, int64_t currentTimeout, Statement* statement, bool isMissingCertificate, ::rice::p2p::commonapi::rawserialization::RawSerializable* missingCertificateId, ::java::util::Map* options);
protected:
    IncompleteStatementInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
