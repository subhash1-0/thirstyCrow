// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtSendSign.java
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSendSign.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::EvtSendSign(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::EvtSendSign(::int8_tArray* signature, ::int8_tArray* restOfMessage) 
    : EvtSendSign(*static_cast< ::default_init_tag* >(0))
{
    ctor(signature,restOfMessage);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::EvtSendSign(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t signatureSize)  /* throws(IOException) */
    : EvtSendSign(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::ctor(::int8_tArray* signature, ::int8_tArray* restOfMessage)
{
    super::ctor();
    this->signature = signature;
    this->restOfMessage = restOfMessage;
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t signatureSize) /* throws(IOException) */
{
    super::ctor();
    signature = new ::int8_tArray(signatureSize);
    npc(buf)->read(signature);
    restOfMessage = new ::int8_tArray(npc(buf)->bytesRemaining());
    npc(buf)->read(restOfMessage);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->write(signature, 0, npc(signature)->length);
    npc(buf)->write(restOfMessage, 0, npc(restOfMessage)->length);
}

int16_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::getType()
{
    return EVT_SENDSIGN;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.logentry.EvtSendSign", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign::getClass0()
{
    return class_();
}

