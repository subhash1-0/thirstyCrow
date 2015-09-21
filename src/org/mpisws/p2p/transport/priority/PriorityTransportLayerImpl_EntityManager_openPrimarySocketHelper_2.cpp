// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::java::lang::Object* i_, ::java::lang::Object* i, ::java::util::Map* options, ::rice::environment::logging::Logger* logger)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_this(PriorityTransportLayerImpl_EntityManager_this)
    , i(i_)
{
    clinit();
    ctor(i, options, logger);
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2::cancel()
{
    npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->getEntityManager(i))->receiveSocketException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Channel cancelled."_j));
    return super::cancel();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2::getClass0()
{
    return class_();
}

