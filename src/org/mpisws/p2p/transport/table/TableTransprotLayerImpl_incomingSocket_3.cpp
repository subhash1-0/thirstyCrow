// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_incomingSocket_3.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::table::TableTransprotLayerImpl_incomingSocket_3::TableTransprotLayerImpl_incomingSocket_3(TableTransprotLayerImpl *TableTransprotLayerImpl_this, ::org::mpisws::p2p::transport::P2PSocket* sock)
    : super(*static_cast< ::default_init_tag* >(0))
    , TableTransprotLayerImpl_this(TableTransprotLayerImpl_this)
    , sock(sock)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_incomingSocket_3::receiveResult(::java::nio::ByteBuffer* result)
{
    auto type = npc(result)->get();
    if(npc(TableTransprotLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(TableTransprotLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket() from "_j)->append(static_cast< ::java::lang::Object* >(sock))
            ->append(u" "_j)
            ->append(type)->toString());

    switch (type) {
    case TableTransprotLayerImpl::PASSTHROUGH:
        try {
            npc(TableTransprotLayerImpl_this->callback)->incomingSocket(sock);
        } catch (::java::io::IOException* ioe) {
            npc(TableTransprotLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(sock)->getIdentifier()), ioe);
        }
        return;
    case TableTransprotLayerImpl::REQUEST:
        TableTransprotLayerImpl_this->handleValueRequest(sock);
        return;
    default:
        npc(TableTransprotLayerImpl_this->errorHandler)->receivedUnexpectedData(java_cast< ::java::lang::Object* >(npc(sock)->getIdentifier()), new ::int8_tArray({type}), 0, npc(sock)->getOptions());
        npc(sock)->close();
    }

}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_incomingSocket_3::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::nio::ByteBuffer* >(result));
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_incomingSocket_3::receiveException(::java::lang::Exception* exception)
{
    npc(TableTransprotLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(sock)->getIdentifier()), exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_incomingSocket_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_incomingSocket_3::getClass0()
{
    return class_();
}

