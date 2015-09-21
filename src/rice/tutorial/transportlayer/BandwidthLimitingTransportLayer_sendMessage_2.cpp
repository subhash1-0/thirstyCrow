// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_sendMessage_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_sendMessage_2::BandwidthLimitingTransportLayer_sendMessage_2(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* returnMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthLimitingTransportLayer_this(BandwidthLimitingTransportLayer_this)
    , deliverAckToMe(deliverAckToMe)
    , returnMe(returnMe)
{
    clinit();
    ctor();
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_sendMessage_2::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(returnMe);

}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_sendMessage_2::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(returnMe, reason);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_sendMessage_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_sendMessage_2::getClass0()
{
    return class_();
}

