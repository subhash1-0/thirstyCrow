// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3 *PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this, ::org::mpisws::p2p::transport::P2PSocket* sock)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this)
    , sock(sock)
{
    clinit();
    ctor();
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1::cancel()
{
    npc(sock)->close();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1::getClass0()
{
    return class_();
}

