// Generated from /pastry-2.1/src/rice/environment/processing/simple/UnifiedProcessor.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Executable.hpp>

struct default_init_tag;

class rice::environment::processing::simple::UnifiedProcessor_processBlockingIO_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Executable
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::Object* execute() /* throws(Exception) */ override;

    // Generated
    UnifiedProcessor_processBlockingIO_2(UnifiedProcessor *UnifiedProcessor_this, ::rice::environment::processing::WorkRequest* workRequest);
    static ::java::lang::Class *class_();
    UnifiedProcessor *UnifiedProcessor_this;
    ::rice::environment::processing::WorkRequest* workRequest;

private:
    virtual ::java::lang::Class* getClass0();
    friend class UnifiedProcessor;
    friend class UnifiedProcessor_UnifiedProcessor_1;
};
