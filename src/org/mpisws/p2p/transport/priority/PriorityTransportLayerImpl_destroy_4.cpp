// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_destroy_4.hpp>

#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_destroy_4::PriorityTransportLayerImpl_destroy_4(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_this(PriorityTransportLayerImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_destroy_4::run()
{
    PriorityTransportLayerImpl_this->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_destroy_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_destroy_4::getClass0()
{
    return class_();
}

