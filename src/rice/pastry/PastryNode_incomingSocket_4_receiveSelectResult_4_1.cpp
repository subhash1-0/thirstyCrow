// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_incomingSocket_4_receiveSelectResult_4_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/exception/AppNotRegisteredException.hpp>
#include <rice/p2p/commonapi/exception/NoReceiverAvailableException.hpp>
#include <rice/pastry/PastryNode_incomingSocket_4.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/messaging/MessageDispatch.hpp>
#include <rice/pastry/transport/SocketAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::PastryNode_incomingSocket_4_receiveSelectResult_4_1::PastryNode_incomingSocket_4_receiveSelectResult_4_1(PastryNode_incomingSocket_4 *PastryNode_incomingSocket_4_this, int32_t appId)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_incomingSocket_4_this(PastryNode_incomingSocket_4_this)
    , appId(appId)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_incomingSocket_4_receiveSelectResult_4_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto acceptorAppl = npc(PastryNode_incomingSocket_4_this->PastryNode_this->getMessageDispatch())->getDestinationByAddress(appId);
    auto toWrite = ::java::nio::ByteBuffer::allocate(1);
    auto success = false;
    if(acceptorAppl == nullptr) {
        if(npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->log(::java::lang::StringBuilder().append(u"Sending error to connecter "_j)->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(new ::rice::p2p::commonapi::exception::AppNotRegisteredException(appId)))->toString());

        npc(toWrite)->put(PastryNode::CONNECTION_NO_APP);
        npc(toWrite)->clear();
        npc(socket)->write(toWrite);
        npc(socket)->close();
    } else {
        {
            synchronized synchronized_0(acceptorAppl);
            {
                if(npc(acceptorAppl)->canReceiveSocket()) {
                    npc(toWrite)->put(PastryNode::CONNECTION_OK);
                    npc(toWrite)->clear();
                    success = true;
                } else {
                    if(npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->log(::java::lang::StringBuilder().append(u"Sending error to connecter "_j)->append(static_cast< ::java::lang::Object* >(socket))
                            ->append(u" "_j)
                            ->append(static_cast< ::java::lang::Object* >(new ::rice::p2p::commonapi::exception::NoReceiverAvailableException()))->toString());

                    npc(toWrite)->put(PastryNode::CONNECTION_NO_ACCEPTOR);
                    npc(toWrite)->clear();
                }
                npc(socket)->write(toWrite);
                if(npc(toWrite)->hasRemaining()) {
                    if(npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->log(::java::lang::StringBuilder().append(u"couldn't write 1 bite!!! "_j)->append(static_cast< ::java::lang::Object* >(toWrite))->toString());

                    npc(socket)->close();
                    return;
                }
                if(success) {
                    npc(acceptorAppl)->finishReceiveSocket(new ::rice::pastry::transport::SocketAdapter(socket, PastryNode_incomingSocket_4_this->PastryNode_this->getEnvironment()));
                }
            }
        }
    }
}

void rice::pastry::PastryNode_incomingSocket_4_receiveSelectResult_4_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(PastryNode_incomingSocket_4_this->PastryNode_this->logger)->logException(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u")"_j)->toString(), ioe);

    return;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_incomingSocket_4_receiveSelectResult_4_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_incomingSocket_4_receiveSelectResult_4_1::getClass0()
{
    return class_();
}

