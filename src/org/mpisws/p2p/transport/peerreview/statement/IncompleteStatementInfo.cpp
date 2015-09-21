// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/statement/IncompleteStatementInfo.java
#include <org/mpisws/p2p/transport/peerreview/statement/IncompleteStatementInfo.hpp>

#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/Statement.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::IncompleteStatementInfo(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::IncompleteStatementInfo(bool finished, ::java::lang::Object* source, int64_t currentTimeout, Statement* statement, bool isMissingCertificate, ::rice::p2p::commonapi::rawserialization::RawSerializable* missingCertificateId, ::java::util::Map* options) 
    : IncompleteStatementInfo(*static_cast< ::default_init_tag* >(0))
{
    ctor(finished,source,currentTimeout,statement,isMissingCertificate,missingCertificateId,options);
}

void org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::ctor(bool finished, ::java::lang::Object* source, int64_t currentTimeout, Statement* statement, bool isMissingCertificate, ::rice::p2p::commonapi::rawserialization::RawSerializable* missingCertificateId, ::java::util::Map* options)
{
    super::ctor();
    this->finished = finished;
    this->sender = source;
    this->currentTimeout = currentTimeout;
    this->statement = statement;
    this->isMissingCertificate_ = isMissingCertificate;
    this->missingCertificateID = missingCertificateId;
    this->options = options;
}

bool org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::isMissingCertificate()
{
    return isMissingCertificate_;
}

bool org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::isFinished()
{
    return finished;
}

int64_t org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::getCurrentTimeout()
{
    return currentTimeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.statement.IncompleteStatementInfo", 69);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::statement::IncompleteStatementInfo::getClass0()
{
    return class_();
}

