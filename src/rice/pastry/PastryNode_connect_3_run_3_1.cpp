// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_connect_3_run_3_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode_connect_3.hpp>
#include <rice/pastry/PastryNode_connect_3_run_3_1_receiveResult_3_1_1.hpp>
#include <rice/pastry/PastryNode.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_connect_3_run_3_1::PastryNode_connect_3_run_3_1(PastryNode_connect_3 *PastryNode_connect_3_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, NodeHandle* i, ::java::nio::ByteBuffer* b, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe, ::rice::pastry::client::PastryAppl* appl)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_connect_3_this(PastryNode_connect_3_this)
    , handle(handle)
    , i(i)
    , b(b)
    , deliverSocketToMe(deliverSocketToMe)
    , appl(appl)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_connect_3_run_3_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::org::mpisws::p2p::transport::P2PSocket* result)
{
    if(static_cast< ::rice::p2p::commonapi::Cancellable* >(c) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"c != handle.getSubCancellable() (indicates a bug in the code) c:"_j)->append(static_cast< ::java::lang::Object* >(c))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    if(npc(PastryNode_connect_3_this->PastryNode_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PastryNode_connect_3_this->PastryNode_this->logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u"):receiveResult("_j)
            ->append(static_cast< ::java::lang::Object* >(result))
            ->append(u")"_j)->toString());

    npc(result)->register_(false, true, new PastryNode_connect_3_run_3_1_receiveResult_3_1_1(this, b, deliverSocketToMe, appl));
}

void rice::pastry::PastryNode_connect_3_run_3_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(nullptr, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_connect_3_run_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_connect_3_run_3_1::getClass0()
{
    return class_();
}

