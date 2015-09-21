// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectTransportLayer.java
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer_CancelAndClose.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::direct::DirectTransportLayer_CancelAndClose::DirectTransportLayer_CancelAndClose(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::direct::DirectTransportLayer_CancelAndClose::DirectTransportLayer_CancelAndClose(DirectAppSocket* socket, ::rice::p2p::commonapi::CancellableTask* task) 
    : DirectTransportLayer_CancelAndClose(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,task);
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer_CancelAndClose::ctor(DirectAppSocket* socket, ::rice::p2p::commonapi::CancellableTask* task)
{
    super::ctor();
    this->closeMe = socket;
    this->cancelMe = task;
}

bool org::mpisws::p2p::transport::direct::DirectTransportLayer_CancelAndClose::cancel()
{
    npc(npc(closeMe)->connectorEndpoint)->close();
    return npc(cancelMe)->cancel();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectTransportLayer_CancelAndClose::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.DirectTransportLayer.CancelAndClose", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectTransportLayer_CancelAndClose::getClass0()
{
    return class_();
}

