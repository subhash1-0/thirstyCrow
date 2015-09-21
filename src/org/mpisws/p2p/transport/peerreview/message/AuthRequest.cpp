// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AuthRequest.java
#include <org/mpisws/p2p/transport/peerreview/message/AuthRequest.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
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

org::mpisws::p2p::transport::peerreview::message::AuthRequest::AuthRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::AuthRequest::AuthRequest(int64_t timestamp, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject) 
    : AuthRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(timestamp,subject);
}

org::mpisws::p2p::transport::peerreview::message::AuthRequest::AuthRequest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer)  /* throws(IOException) */
    : AuthRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,serializer);
}

void org::mpisws::p2p::transport::peerreview::message::AuthRequest::ctor(int64_t timestamp, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject)
{
    super::ctor();
    this->timestamp = timestamp;
    this->subject = subject;
}

int16_t org::mpisws::p2p::transport::peerreview::message::AuthRequest::getType()
{
    return MSG_AUTHREQ;
}

void org::mpisws::p2p::transport::peerreview::message::AuthRequest::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer) /* throws(IOException) */
{
    super::ctor();
    timestamp = npc(buf)->readLong();
    subject = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(serializer)->deserialize(buf));
}

void org::mpisws::p2p::transport::peerreview::message::AuthRequest::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(timestamp);
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject))->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AuthRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.AuthRequest", 55);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AuthRequest::getClass0()
{
    return class_();
}

