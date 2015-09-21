// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardJoinProtocol_handleInitiateJoin_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::pastry::join::JoinRequest* jr);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    StandardJoinProtocol_handleInitiateJoin_1(StandardJoinProtocol *StandardJoinProtocol_this, ::rice::pastry::NodeHandle* nh);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    StandardJoinProtocol *StandardJoinProtocol_this;
    ::rice::pastry::NodeHandle* nh;

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardJoinProtocol;
    friend class StandardJoinProtocol_SJPDeserializer;
    friend class StandardJoinProtocol_handleIntermediateHop_2;
    friend class StandardJoinProtocol_respondToJoiner_3;
};
