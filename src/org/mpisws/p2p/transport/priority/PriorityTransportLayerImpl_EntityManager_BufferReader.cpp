// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_BufferReader.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/channels/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_SizeReader.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::PriorityTransportLayerImpl_EntityManager_BufferReader(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_this(PriorityTransportLayerImpl_EntityManager_this)
{
    clinit();
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::PriorityTransportLayerImpl_EntityManager_BufferReader(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, int32_t size, ::org::mpisws::p2p::transport::P2PSocket* socket) 
    : PriorityTransportLayerImpl_EntityManager_BufferReader(PriorityTransportLayerImpl_EntityManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(size,socket);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::ctor(int32_t size, ::org::mpisws::p2p::transport::P2PSocket* socket)
{
    super::ctor();
    buf = ::java::nio::ByteBuffer::allocate(size);
    npc(socket)->register_(true, false, this);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canWrite || !canRead)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(PriorityTransportLayerImpl_EntityManager_this))->append(u" Expected only to read. canRead:"_j)
            ->append(canRead)
            ->append(u" canWrite:"_j)
            ->append(canWrite)
            ->append(u" socket:"_j)
            ->append(static_cast< ::java::lang::Object* >(socket))->toString());

    try {
        if(npc(socket)->read(buf) == -int32_t(1)) {
            PriorityTransportLayerImpl_EntityManager_this->closeMe(socket);
            return;
        }
    } catch (::java::io::IOException* ioe) {
        receiveException(socket, static_cast< ::java::lang::Exception* >(ioe));
        return;
    }
    if(npc(buf)->remaining() == 0) {
        npc(buf)->flip();
        done(socket);
    } else {
        npc(socket)->register_(true, false, this);
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    if(dynamic_cast< ::java::nio::channels::ClosedChannelException* >(e) != nullptr) {
        return;
    }
    auto printError = true;
    if(dynamic_cast< ::org::mpisws::p2p::transport::exception::NodeIsFaultyException* >(e) != nullptr) {
        printError = false;
    }
    if(dynamic_cast< ::java::io::IOException* >(e) != nullptr) {
        if(npc(npc(e)->getMessage())->equals(static_cast< ::java::lang::Object* >(u"An established connection was aborted by the software in your host machine"_j))) {
            printError = false;
        }
    }
    if(printError) {
        npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), e);
    }
    PriorityTransportLayerImpl_EntityManager_this->closeMe(socket);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::done(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(PriorityTransportLayerImpl_EntityManager_this))->append(u" read message of size "_j)
            ->append(npc(buf)->capacity())
            ->append(u" from "_j)
            ->append(static_cast< ::java::lang::Object* >(socket))->toString());

    PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->notifyListenersRead(npc(buf)->capacity(), java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), npc(socket)->getOptions());
    npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->callback)->messageReceived(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), buf, npc(socket)->getOptions());
    new PriorityTransportLayerImpl_EntityManager_SizeReader(PriorityTransportLayerImpl_EntityManager_this, socket);
}

java::lang::String* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::toString()
{
    return ::java::lang::StringBuilder().append(u"BufferReader{"_j)->append(static_cast< ::java::lang::Object* >(buf))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayerImpl.EntityManager.BufferReader", 87);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader::getClass0()
{
    return class_();
}

