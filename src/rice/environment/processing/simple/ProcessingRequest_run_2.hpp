// Generated from /pastry-2.1/src/rice/environment/processing/simple/ProcessingRequest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::environment::processing::simple::ProcessingRequest_run_2
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;
    ::java::lang::String* toString() override;

    // Generated
    ProcessingRequest_run_2(ProcessingRequest *ProcessingRequest_this, ::java::lang::Exception* e);
    static ::java::lang::Class *class_();
    ProcessingRequest *ProcessingRequest_this;
    ::java::lang::Exception* e;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProcessingRequest;
    friend class ProcessingRequest_run_1;
};
