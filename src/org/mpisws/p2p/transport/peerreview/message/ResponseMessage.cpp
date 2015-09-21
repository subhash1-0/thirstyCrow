// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/ResponseMessage.java
#include <org/mpisws/p2p/transport/peerreview/message/ResponseMessage.hpp>

#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

org::mpisws::p2p::transport::peerreview::message::ResponseMessage::ResponseMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::ResponseMessage::ResponseMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* response) 
    : ResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(originator,subject,evidenceSeq,response);
}

org::mpisws::p2p::transport::peerreview::message::ResponseMessage::ResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer)  /* throws(IOException) */
    : ResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,idSerializer,evSerializer);
}

void org::mpisws::p2p::transport::peerreview::message::ResponseMessage::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* response)
{
    super::ctor(originator, subject, evidenceSeq, response);
}

void org::mpisws::p2p::transport::peerreview::message::ResponseMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evSerializer) /* throws(IOException) */
{
    super::ctor(buf, idSerializer, evSerializer);
}

int16_t org::mpisws::p2p::transport::peerreview::message::ResponseMessage::getType()
{
    return MSG_RESPONSE;
}

bool org::mpisws::p2p::transport::peerreview::message::ResponseMessage::isResponse()
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::ResponseMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.ResponseMessage", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::ResponseMessage::getClass0()
{
    return class_();
}

