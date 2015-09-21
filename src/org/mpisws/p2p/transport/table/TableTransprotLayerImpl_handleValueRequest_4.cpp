// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_handleValueRequest_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/table/TableStore.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/BufferWriter.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>

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

org::mpisws::p2p::transport::table::TableTransprotLayerImpl_handleValueRequest_4::TableTransprotLayerImpl_handleValueRequest_4(TableTransprotLayerImpl *TableTransprotLayerImpl_this, ::org::mpisws::p2p::transport::P2PSocket* sock)
    : super(*static_cast< ::default_init_tag* >(0))
    , TableTransprotLayerImpl_this(TableTransprotLayerImpl_this)
    , sock(sock)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_handleValueRequest_4::receiveResult(::java::nio::ByteBuffer* result)
{
    try {
        auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(result);
        auto principal = java_cast< ::java::lang::Object* >(npc(TableTransprotLayerImpl_this->keySerializer)->deserialize(sib));
        ::java::nio::ByteBuffer* writeMe;
        if(npc(TableTransprotLayerImpl_this->knownValues)->containsKey(principal)) {
            auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
            npc(sob)->writeByte(TableTransprotLayerImpl::RESPONSE_SUCCESS);
            npc(TableTransprotLayerImpl_this->valueSerializer)->serialize(java_cast< ::java::lang::Object* >(npc(TableTransprotLayerImpl_this->knownValues)->get(principal)), sob);
            writeMe = npc(sob)->getByteBuffer();
        } else {
            writeMe = ::java::nio::ByteBuffer::allocate(1);
            npc(writeMe)->put(TableTransprotLayerImpl::RESPONSE_FAILED);
            npc(writeMe)->clear();
        }
        new ::org::mpisws::p2p::transport::util::BufferWriter(writeMe, sock, nullptr);
    } catch (::java::lang::Exception* ioe) {
        npc(TableTransprotLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(sock)->getIdentifier()), ioe);
        npc(sock)->close();
    }
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_handleValueRequest_4::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::nio::ByteBuffer* >(result));
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_handleValueRequest_4::receiveException(::java::lang::Exception* exception)
{
    npc(TableTransprotLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(sock)->getIdentifier()), exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_handleValueRequest_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_handleValueRequest_4::getClass0()
{
    return class_();
}

