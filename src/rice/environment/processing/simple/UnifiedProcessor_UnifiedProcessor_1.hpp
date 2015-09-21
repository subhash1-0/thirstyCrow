// Generated from /pastry-2.1/src/rice/environment/processing/simple/UnifiedProcessor.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::environment::processing::simple::UnifiedProcessor_UnifiedProcessor_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* result) override;
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    UnifiedProcessor_UnifiedProcessor_1(UnifiedProcessor *UnifiedProcessor_this);
    static ::java::lang::Class *class_();
    UnifiedProcessor *UnifiedProcessor_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class UnifiedProcessor;
    friend class UnifiedProcessor_processBlockingIO_2;
};
