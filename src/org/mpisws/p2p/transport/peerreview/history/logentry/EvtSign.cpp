// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtSign.java
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSign.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::EvtSign(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::EvtSign(::int8_tArray* hTopMinusOne, ::int8_tArray* signature) 
    : EvtSign(*static_cast< ::default_init_tag* >(0))
{
    ctor(hTopMinusOne,signature);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::EvtSign(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize)  /* throws(IOException) */
    : EvtSign(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,hashSize,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::ctor(::int8_tArray* hTopMinusOne, ::int8_tArray* signature)
{
    super::ctor();
    this->hTopMinusOne = hTopMinusOne;
    this->signature = signature;
}

int16_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::getType()
{
    return EVT_SIGN;
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */
{
    super::ctor();
    hTopMinusOne = new ::int8_tArray(hashSize);
    npc(buf)->read(hTopMinusOne);
    signature = new ::int8_tArray(signatureSize);
    npc(buf)->read(signature);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->write(hTopMinusOne, 0, npc(hTopMinusOne)->length);
    npc(buf)->write(signature, 0, npc(signature)->length);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.logentry.EvtSign", 60);
    return c;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::serialize()
{
    return super::serialize();
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign::getClass0()
{
    return class_();
}

