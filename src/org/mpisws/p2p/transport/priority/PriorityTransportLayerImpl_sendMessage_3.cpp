// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_sendMessage_3.hpp>

#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_sendMessage_3::PriorityTransportLayerImpl_sendMessage_3(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this, int32_t originalSize, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_this(PriorityTransportLayerImpl_this)
    , originalSize(originalSize)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_sendMessage_3::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    PriorityTransportLayerImpl_this->notifyListenersWrote(originalSize, i, options);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_sendMessage_3::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    PriorityTransportLayerImpl_this->notifyListenersDropped(originalSize, i, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_sendMessage_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_sendMessage_3::getClass0()
{
    return class_();
}

