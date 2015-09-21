// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_ByteWriter.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, int8_t writeMe, ::rice::Continuation* callMeWhenDone) 
    : RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(writeMe,callMeWhenDone);
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::int8_tArray* writeMe, ::rice::Continuation* callMeWhenDone) 
    : RendezvousTransportLayerImpl_ByteWriter(RendezvousTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(writeMe,callMeWhenDone);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::ctor(int8_t writeMe, ::rice::Continuation* callMeWhenDone)
{
    ctor(RendezvousTransportLayerImpl::makeByteArray_(writeMe), callMeWhenDone);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::ctor(::int8_tArray* writeMe, ::rice::Continuation* callMeWhenDone)
{
    super::ctor();
    this->bytesToWrite = ::java::nio::ByteBuffer::wrap(writeMe);
    this->callMeWhenDone = callMeWhenDone;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto bytesWritten = npc(socket)->write(bytesToWrite);
    if(bytesWritten < 0) {
        npc(socket)->close();
        npc(callMeWhenDone)->receiveException(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u" closed."_j)->toString()));
        return;
    }
    if(npc(bytesToWrite)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    }
    npc(callMeWhenDone)->receiveResult(socket);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(socket)->close();
    npc(callMeWhenDone)->receiveException(ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rendezvous.RendezvousTransportLayerImpl.ByteWriter", 75);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_ByteWriter::getClass0()
{
    return class_();
}

