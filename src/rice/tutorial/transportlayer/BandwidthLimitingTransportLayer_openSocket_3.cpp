// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_openSocket_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_BandwidthLimitingSocket.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_openSocket_3::BandwidthLimitingTransportLayer_openSocket_3(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* returnMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthLimitingTransportLayer_this(BandwidthLimitingTransportLayer_this)
    , deliverSocketToMe(deliverSocketToMe)
    , returnMe(returnMe)
{
    clinit();
    ctor();
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_openSocket_3::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(deliverSocketToMe)->receiveResult(returnMe, new BandwidthLimitingTransportLayer_BandwidthLimitingSocket(BandwidthLimitingTransportLayer_this, sock));
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_openSocket_3::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(returnMe, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_openSocket_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_openSocket_3::getClass0()
{
    return class_();
}

