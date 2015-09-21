// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/BogusUDPLayerImpl.java
#include <org/mpisws/p2p/transport/wire/BogusUDPLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::BogusUDPLayerImpl::BogusUDPLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::wire::BogusUDPLayerImpl::BogusUDPLayerImpl()
    : BogusUDPLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::wire::BogusUDPLayerImpl::sendMessage(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    ::org::mpisws::p2p::transport::MessageRequestHandle* ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(destination, m, options);
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(ret, new ::java::io::IOException(u"UDP is disabled.  To use this feature, enable UDP in the WireTransportLayer constructor."_j));

    return ret;
}

void org::mpisws::p2p::transport::wire::BogusUDPLayerImpl::destroy()
{
}

void org::mpisws::p2p::transport::wire::BogusUDPLayerImpl::acceptMessages(bool b)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::BogusUDPLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.BogusUDPLayerImpl", 47);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::BogusUDPLayerImpl::getClass0()
{
    return class_();
}

