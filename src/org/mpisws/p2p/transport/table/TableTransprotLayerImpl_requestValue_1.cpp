// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/BufferWriter.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1::TableTransprotLayerImpl_requestValue_1(TableTransprotLayerImpl *TableTransprotLayerImpl_this, ::java::lang::Object* principal, ::rice::Continuation* c, ::java::lang::Object* source)
    : super(*static_cast< ::default_init_tag* >(0))
    , TableTransprotLayerImpl_this(TableTransprotLayerImpl_this)
    , principal(principal)
    , c(c)
    , source(source)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(TableTransprotLayerImpl_this->keySerializer)->serialize(principal, sob);
        auto sob2 = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob2)->writeByte(TableTransprotLayerImpl::REQUEST);
        npc(sob2)->writeInt(npc(sob)->getWritten());
        npc(sob2)->write(npc(sob)->getBytes());
        new ::org::mpisws::p2p::transport::util::BufferWriter(npc(sob2)->getByteBuffer(), sock, new TableTransprotLayerImpl_requestValue_1_receiveResult_1_1(this, c, source, principal), false);
    } catch (::java::io::IOException* ioe) {
        npc(c)->receiveException(ioe);
    }
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(c)->receiveException(ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1::getClass0()
{
    return class_();
}

