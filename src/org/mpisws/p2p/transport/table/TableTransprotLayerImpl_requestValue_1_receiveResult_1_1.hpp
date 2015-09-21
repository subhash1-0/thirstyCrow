// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/table/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::org::mpisws::p2p::transport::P2PSocket* result);

    // Generated
    TableTransprotLayerImpl_requestValue_1_receiveResult_1_1(TableTransprotLayerImpl_requestValue_1 *TableTransprotLayerImpl_requestValue_1_this, ::rice::Continuation* c, ::java::lang::Object* source, ::java::lang::Object* principal);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    TableTransprotLayerImpl_requestValue_1 *TableTransprotLayerImpl_requestValue_1_this;
    ::rice::Continuation* c;
    ::java::lang::Object* source;
    ::java::lang::Object* principal;

private:
    virtual ::java::lang::Class* getClass0();
    friend class TableTransprotLayerImpl;
    friend class TableTransprotLayerImpl_requestValue_1;
    friend class TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1;
    friend class TableTransprotLayerImpl_openSocket_2;
    friend class TableTransprotLayerImpl_openSocket_2_receiveResult_2_1;
    friend class TableTransprotLayerImpl_incomingSocket_3;
    friend class TableTransprotLayerImpl_handleValueRequest_4;
};
