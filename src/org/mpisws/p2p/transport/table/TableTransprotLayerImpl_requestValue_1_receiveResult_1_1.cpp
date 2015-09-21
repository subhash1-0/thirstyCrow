// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1_receiveResult_1_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1.hpp>
#include <org/mpisws/p2p/transport/util/BufferReader.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1(TableTransprotLayerImpl_requestValue_1 *TableTransprotLayerImpl_requestValue_1_this, ::rice::Continuation* c, ::java::lang::Object* source, ::java::lang::Object* principal)
    : super(*static_cast< ::default_init_tag* >(0))
    , TableTransprotLayerImpl_requestValue_1_this(TableTransprotLayerImpl_requestValue_1_this)
    , c(c)
    , source(source)
    , principal(principal)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(c)->receiveException(exception);
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1::receiveResult(::org::mpisws::p2p::transport::P2PSocket* result)
{
    new ::org::mpisws::p2p::transport::util::BufferReader(result, new TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1(this, source, principal, c));
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1::getClass0()
{
    return class_();
}

