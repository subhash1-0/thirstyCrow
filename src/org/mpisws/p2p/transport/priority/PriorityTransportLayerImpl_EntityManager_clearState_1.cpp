// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_clearState_1.hpp>

#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_clearState_1::PriorityTransportLayerImpl_EntityManager_clearState_1(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_this(PriorityTransportLayerImpl_EntityManager_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_clearState_1::run()
{
    PriorityTransportLayerImpl_EntityManager_this->clearState();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_clearState_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_clearState_1::getClass0()
{
    return class_();
}

