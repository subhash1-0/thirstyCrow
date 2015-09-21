// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer_openSocket_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer_MySocket.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_openSocket_2::BandwidthMeasuringTransportLayer_openSocket_2(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthMeasuringTransportLayer_this(BandwidthMeasuringTransportLayer_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_openSocket_2::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(s, ex);
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_openSocket_2::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(deliverSocketToMe)->receiveResult(ret, new BandwidthMeasuringTransportLayer_MySocket(BandwidthMeasuringTransportLayer_this, i, sock, BandwidthMeasuringTransportLayer_this->logger, BandwidthMeasuringTransportLayer_this->errorHandler, options));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_openSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_openSocket_2::getClass0()
{
    return class_();
}

