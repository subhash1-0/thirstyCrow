// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/Continuation_MultiContinuation.hpp>

struct default_init_tag;

class rice::p2p::past::PastImpl_doInsert_6_receiveResult_6_1
    : public ::rice::Continuation_MultiContinuation
{

public:
    typedef ::rice::Continuation_MultiContinuation super;
    bool isDone() /* throws(Exception) */ override;
    ::java::lang::Object* getResult() override;

    // Generated
    PastImpl_doInsert_6_receiveResult_6_1(PastImpl_doInsert_6 *PastImpl_doInsert_6_this, ::rice::Continuation* parent, int32_t num);
    static ::java::lang::Class *class_();
    PastImpl_doInsert_6 *PastImpl_doInsert_6_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastImpl;
    friend class PastImpl_PastDeserializer;
    friend class PastImpl_PastImpl_1;
    friend class PastImpl_getResponseContinuation_2;
    friend class PastImpl_getFetchResponseContinuation_3;
    friend class PastImpl_sendViaSocket_4;
    friend class PastImpl_getHandles_5;
    friend class PastImpl_doInsert_6;
    friend class PastImpl_insert_7;
    friend class PastImpl_insert_8;
    friend class PastImpl_insert_8_receiveResult_8_1;
    friend class PastImpl_lookup_9;
    friend class PastImpl_lookup_9_receiveResult_9_1;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1_receiveResult_9_1_2_1_1;
    friend class PastImpl_lookupHandles_10;
    friend class PastImpl_lookupHandles_10_receiveResult_10_1;
    friend class PastImpl_deliver_11;
    friend class PastImpl_deliver_11_receiveResult_11_1;
    friend class PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1;
    friend class PastImpl_deliver_12;
    friend class PastImpl_deliver_13;
    friend class PastImpl_fetch_14;
    friend class PastImpl_remove_15;
    friend class PastImpl_remove_15_receiveResult_15_1;
    friend class PastImpl_existsInOverlay_16;
    friend class PastImpl_reInsert_17;
    friend class PastImpl_reInsert_17_receiveResult_17_1;
    friend class PastImpl_MessageBuilder;
};
