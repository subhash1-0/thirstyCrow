// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AuthResponse.java
#include <org/mpisws/p2p/transport/peerreview/message/AuthResponse.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
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

org::mpisws::p2p::transport::peerreview::message::AuthResponse::AuthResponse(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::AuthResponse::AuthResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo) 
    : AuthResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(subject,authFrom,authTo);
}

org::mpisws::p2p::transport::peerreview::message::AuthResponse::AuthResponse(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize)  /* throws(IOException) */
    : AuthResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,serializer,hashSize,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::message::AuthResponse::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo)
{
    super::ctor();
    this->subject = subject;
    this->authFrom = authFrom;
    this->authTo = authTo;
}

int16_t org::mpisws::p2p::transport::peerreview::message::AuthResponse::getType()
{
    return MSG_AUTHREQ;
}

void org::mpisws::p2p::transport::peerreview::message::AuthResponse::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */
{
    super::ctor();
    subject = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(serializer)->deserialize(buf));
    authFrom = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(buf, hashSize, signatureSize);
    authTo = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(buf, hashSize, signatureSize);
}

void org::mpisws::p2p::transport::peerreview::message::AuthResponse::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject))->serialize(buf);
    npc(authFrom)->serialize(buf);
    npc(authTo)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AuthResponse::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.AuthResponse", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AuthResponse::getClass0()
{
    return class_();
}

