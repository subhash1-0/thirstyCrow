// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>
#include <rice/p2p/commonapi/exception/AppNotRegisteredException.hpp>
#include <rice/p2p/commonapi/exception/AppSocketException.hpp>
#include <rice/p2p/commonapi/exception/NoReceiverAvailableException.hpp>
#include <rice/pastry/PastryNode_connect_3.hpp>
#include <rice/pastry/PastryNode_connect_3_run_3_1.hpp>
#include <rice/pastry/PastryNode_connect_3_run_3_1_receiveResult_3_1_1.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/transport/SocketAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1::PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1(PastryNode_connect_3_run_3_1_receiveResult_3_1_1 *PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this, ::java::nio::ByteBuffer* answer, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe, ::rice::pastry::client::PastryAppl* appl)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this(PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this)
    , answer(answer)
    , deliverSocketToMe(deliverSocketToMe)
    , appl(appl)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(socket)->read(answer) == -int32_t(1)) {
        npc(deliverSocketToMe)->receiveException(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this->PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()), new ::org::mpisws::p2p::transport::ClosedChannelException(u"Remote node closed socket while opening.  Try again."_j));
        return;
    }
    ;
    if(npc(answer)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
    } else {
        npc(answer)->clear();
        auto connectResult = npc(answer)->get();
        switch (connectResult) {
        case PastryNode::CONNECTION_OK:
            npc(deliverSocketToMe)->receiveSocket(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this->PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()));
            return;
        case PastryNode::CONNECTION_NO_APP:
            npc(deliverSocketToMe)->receiveException(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this->PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()), new ::rice::p2p::commonapi::exception::AppNotRegisteredException(npc(appl)->getAddress()));
            return;
        case PastryNode::CONNECTION_NO_ACCEPTOR:
            npc(deliverSocketToMe)->receiveException(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this->PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()), new ::rice::p2p::commonapi::exception::NoReceiverAvailableException());
            return;
        default:
            npc(deliverSocketToMe)->receiveException(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this->PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()), new ::rice::p2p::commonapi::exception::AppSocketException(::java::lang::StringBuilder().append(u"Unknown error "_j)->append(connectResult)->toString()));
            return;
        }

    }
}

void rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverSocketToMe)->receiveException(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_receiveResult_3_1_1_this->PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()), ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1::getClass0()
{
    return class_();
}

