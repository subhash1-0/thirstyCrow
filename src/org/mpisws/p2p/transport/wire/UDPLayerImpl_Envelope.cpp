// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayerImpl.java
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl_Envelope.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::UDPLayerImpl_Envelope(UDPLayerImpl *UDPLayerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , UDPLayerImpl_this(UDPLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::UDPLayerImpl_Envelope(UDPLayerImpl *UDPLayerImpl_this, ::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) 
    : UDPLayerImpl_Envelope(UDPLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(destination,msg,deliverAckToMe,options);
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::ctor(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    super::ctor();
    this->destination = destination;
    this->msg = msg;
    this->continuation = deliverAckToMe;
    this->options = options;
}

bool org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::cancel()
{
    if(npc(UDPLayerImpl_this->pendingMsgs)->remove(static_cast< ::java::lang::Object* >(this))) {
        return true;
    }
    return false;
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::getIdentifier()
{
    return destination;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::getMessage()
{
    return msg;
}

java::util::Map* org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::getOptions()
{
    return options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.UDPLayerImpl.Envelope", 51);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope::getClass0()
{
    return class_();
}

