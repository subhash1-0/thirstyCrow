// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/statement/Statement.java
#include <org/mpisws/p2p/transport/peerreview/statement/Statement.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceSerializer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::statement::Statement::Statement(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::statement::Statement::Statement(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence) 
    : Statement(*static_cast< ::default_init_tag* >(0))
{
    ctor(originator,subject,evidenceSeq,evidence);
}

org::mpisws::p2p::transport::peerreview::statement::Statement::Statement(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer)  /* throws(IOException) */
    : Statement(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,idSerializer,evSerializer);
}

void org::mpisws::p2p::transport::peerreview::statement::Statement::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence)
{
    super::ctor();
    this->originator = originator;
    this->subject = subject;
    this->evidenceSeq = evidenceSeq;
    this->evidence = evidence;
}

void org::mpisws::p2p::transport::peerreview::statement::Statement::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer) /* throws(IOException) */
{
    super::ctor();
    originator = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idSerializer)->deserialize(buf));
    subject = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idSerializer)->deserialize(buf));
    evidenceSeq = npc(buf)->readLong();
    evidence = npc(evSerializer)->deserialize(buf, npc(buf)->readByte(), isResponse());
}

void org::mpisws::p2p::transport::peerreview::statement::Statement::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(originator))->serialize(buf);
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject))->serialize(buf);
    npc(buf)->writeLong(evidenceSeq);
    npc(buf)->writeByte(static_cast< int8_t >(npc(evidence)->getEvidenceType()));
    npc(evidence)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::statement::Statement::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.statement.Statement", 55);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::statement::Statement::getClass0()
{
    return class_();
}

