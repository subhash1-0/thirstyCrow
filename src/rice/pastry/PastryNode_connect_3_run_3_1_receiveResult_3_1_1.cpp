// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_connect_3_run_3_1_receiveResult_3_1_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>
#include <rice/pastry/PastryNode_connect_3.hpp>
#include <rice/pastry/PastryNode_connect_3_run_3_1.hpp>
#include <rice/pastry/PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/transport/SocketAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1::PastryNode_connect_3_run_3_1_receiveResult_3_1_1(PastryNode_connect_3_run_3_1 *PastryNode_connect_3_run_3_1_this, ::java::nio::ByteBuffer* b, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe, ::rice::pastry::client::PastryAppl* appl)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_connect_3_run_3_1_this(PastryNode_connect_3_run_3_1_this)
    , b(b)
    , deliverSocketToMe(deliverSocketToMe)
    , appl(appl)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead || !canWrite)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected to write! "_j)->append(canRead)
            ->append(u","_j)
            ->append(canWrite)->toString());

    if(npc(socket)->write(b) == -int32_t(1)) {
        npc(deliverSocketToMe)->receiveException(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()), new ::org::mpisws::p2p::transport::ClosedChannelException(u"Remote node closed socket while opening.  Try again."_j));
        return;
    }
    if(npc(b)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        auto const answer = ::java::nio::ByteBuffer::allocate(1);
        npc(socket)->register_(true, false, new PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1(this, answer, deliverSocketToMe, appl));
    }
}

void rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(deliverSocketToMe)->receiveException(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_connect_3_run_3_1_this->PastryNode_connect_3_this->PastryNode_this->getEnvironment()), e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_connect_3_run_3_1_receiveResult_3_1_1::getClass0()
{
    return class_();
}

