// Generated from /pastry-2.1/src/rice/environment/processing/WorkRequest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::environment::processing::WorkRequest_run_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;
    ::java::lang::String* toString() override;

    // Generated
    WorkRequest_run_1(WorkRequest *WorkRequest_this, ::java::lang::Object* result);
    static ::java::lang::Class *class_();
    WorkRequest *WorkRequest_this;
    ::java::lang::Object* result;

private:
    virtual ::java::lang::Class* getClass0();
    friend class WorkRequest;
    friend class WorkRequest_run_2;
};
