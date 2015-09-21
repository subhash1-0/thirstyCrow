// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocketViaPilot_3.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3::RendezvousTransportLayerImpl_openSocketViaPilot_3(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::java::nio::ByteBuffer* writeBuffer, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, int32_t uid, RendezvousContact* dest, RendezvousContact* middleMan, ::java::nio::ByteBuffer* readBuffer, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
    , writeBuffer(writeBuffer)
    , deliverSocketToMe(deliverSocketToMe)
    , handle(handle)
    , uid(uid)
    , dest(dest)
    , middleMan(middleMan)
    , readBuffer(readBuffer)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    try {
        (new RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1(this, writeBuffer, deliverSocketToMe, handle, uid, dest, middleMan, readBuffer, options))->receiveSelectResult(sock, false, true);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(handle, ioe);
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(handle, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3::getClass0()
{
    return class_();
}

