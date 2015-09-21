// Generated from /pastry-2.1/src/rice/pastry/standard/PartitionHandler.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::standard::PartitionHandler_run_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::pastry::NodeHandle* result);
    void receiveException(::java::lang::Exception* result) override;

    // Generated
    PartitionHandler_run_1(PartitionHandler *PartitionHandler_this);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    PartitionHandler *PartitionHandler_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PartitionHandler;
    friend class PartitionHandler_GoneSetEntry;
};
