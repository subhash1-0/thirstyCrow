// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/Continuation_StandardContinuation.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCPastImpl_fetch_9
    : public ::rice::Continuation_StandardContinuation
{

public:
    typedef ::rice::Continuation_StandardContinuation super;
    void receiveResult(::java::lang::Object* o) override;

    // Generated
    GCPastImpl_fetch_9(GCPastImpl *GCPastImpl_this, GCId* gcid, ::rice::Continuation* continuation);
    static ::java::lang::Class *class_();
    GCPastImpl *GCPastImpl_this;
    GCId* gcid;

private:
    virtual ::java::lang::Class* getClass0();
    friend class GCPastImpl;
    friend class GCPastImpl_GCPastDeserializer;
    friend class GCPastImpl_insert_1;
    friend class GCPastImpl_refresh_2;
    friend class GCPastImpl_refresh_3;
    friend class GCPastImpl_refresh_3_receiveResult_3_1;
    friend class GCPastImpl_refresh_3_receiveResult_3_2;
    friend class GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1;
    friend class GCPastImpl_deliver_4;
    friend class GCPastImpl_deliver_5;
    friend class GCPastImpl_deliver_5_receiveResult_5_1;
    friend class GCPastImpl_deliver_5_receiveResult_5_2;
    friend class GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1;
    friend class GCPastImpl_deliver_6;
    friend class GCPastImpl_deliver_7;
    friend class GCPastImpl_collect_8;
    friend class GCPastImpl_collect_8_receiveResult_8_1;
    friend class GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1;
    friend class GCPastImpl_fetch_10;
    friend class GCPastImpl_reInsert_11;
    friend class GCPastImpl_reInsert_11_receiveResult_11_1;
    friend class GCPastImpl_ReplicaMap;
};
