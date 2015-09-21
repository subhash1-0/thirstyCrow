// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/OutgoingUserDataMessage.java
#include <org/mpisws/p2p/transport/peerreview/message/OutgoingUserDataMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/PeerInfo.hpp>
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

org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::OutgoingUserDataMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::OutgoingUserDataMessage(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen, ::java::util::Map* options, ::org::mpisws::p2p::transport::peerreview::commitment::PeerInfo* pi, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe) 
    : OutgoingUserDataMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(topSeq,senderHandle,topMinusOne,sig,message,relevantlen,options,pi,deliverAckToMe);
}

void org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::ctor(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen, ::java::util::Map* options, ::org::mpisws::p2p::transport::peerreview::commitment::PeerInfo* pi, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe)
{
    super::ctor(topSeq, senderHandle, topMinusOne, sig, message, relevantlen);
    this->options = options;
    this->pi = pi;
    this->deliverAckToMe = deliverAckToMe;
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::getIdentifier()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pi)->getHandle());
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::getMessage()
{
    return getPayload();
}

java::util::Map* org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::getOptions()
{
    return options;
}

bool org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::cancel()
{
    return false;
}

void org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::sendComplete()
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(this);

}

void org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::sendFailed(::java::io::IOException* ioe)
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(this, ioe);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.OutgoingUserDataMessage", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage::getClass0()
{
    return class_();
}

