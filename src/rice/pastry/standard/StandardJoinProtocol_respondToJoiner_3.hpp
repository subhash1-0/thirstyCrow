// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardJoinProtocol_respondToJoiner_3
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::transport::PMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sent(::rice::pastry::transport::PMessageReceipt* msg) override;
    void sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason2) override;

    // Generated
    StandardJoinProtocol_respondToJoiner_3(StandardJoinProtocol *StandardJoinProtocol_this, ::rice::pastry::join::JoinRequest* jr);
    static ::java::lang::Class *class_();
    StandardJoinProtocol *StandardJoinProtocol_this;
    ::rice::pastry::join::JoinRequest* jr;

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardJoinProtocol;
    friend class StandardJoinProtocol_SJPDeserializer;
    friend class StandardJoinProtocol_handleInitiateJoin_1;
    friend class StandardJoinProtocol_handleIntermediateHop_2;
};
