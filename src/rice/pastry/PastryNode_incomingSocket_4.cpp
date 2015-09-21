// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_incomingSocket_4.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/IntBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNode_incomingSocket_4_receiveSelectResult_4_1.hpp>
#include <rice/pastry/PastryNode.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_incomingSocket_4::PastryNode_incomingSocket_4(PastryNode *PastryNode_this, ::java::nio::ByteBuffer* appIdBuffer)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_this(PastryNode_this)
    , appIdBuffer(appIdBuffer)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_incomingSocket_4::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(socket)->read(appIdBuffer) == -int32_t(1)) {
        if(npc(PastryNode_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(PastryNode_this->logger)->log(::java::lang::StringBuilder().append(u"AppId Socket from "_j)->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u" closed unexpectedly."_j)->toString());

        return;
    }
    if(npc(appIdBuffer)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
    } else {
        npc(appIdBuffer)->clear();
        auto const appId = npc(npc(appIdBuffer)->asIntBuffer())->get();
        npc(socket)->register_(false, true, new PastryNode_incomingSocket_4_receiveSelectResult_4_1(this, appId));
    }
}

void rice::pastry::PastryNode_incomingSocket_4::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(npc(PastryNode_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(PastryNode_this->logger)->logException(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u")"_j)->toString(), ioe);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_incomingSocket_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_incomingSocket_4::getClass0()
{
    return class_();
}

