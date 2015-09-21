// Generated from /pastry-2.1/src/rice/environment/processing/simple/ProcessingRequest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/Comparable.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class rice::environment::processing::simple::ProcessingRequest
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
    , public virtual ::java::lang::Comparable
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::Continuation* c {  };
    ::rice::Executable* r {  };

private:
    bool cancelled {  };
    bool running {  };

public: /* package */
    ::rice::environment::time::TimeSource* timeSource {  };
    ::rice::selector::SelectorManager* selectorManager {  };
    ::rice::environment::logging::Logger* logger {  };
    int32_t priority {  };
    int64_t seq {  };
protected:
    void ctor(::rice::Executable* r, ::rice::Continuation* c, int32_t priority, int64_t seq, ::rice::environment::logging::LogManager* logging, ::rice::environment::time::TimeSource* timeSource, ::rice::selector::SelectorManager* selectorManager);

public:
    virtual void returnResult(::java::lang::Object* o);
    virtual void returnError(::java::lang::Exception* e);
    virtual int32_t getPriority();
    virtual int32_t compareTo(ProcessingRequest* request);
    void run() override;
    bool cancel() override;

    // Generated
    ProcessingRequest(::rice::Executable* r, ::rice::Continuation* c, int32_t priority, int64_t seq, ::rice::environment::logging::LogManager* logging, ::rice::environment::time::TimeSource* timeSource, ::rice::selector::SelectorManager* selectorManager);
protected:
    ProcessingRequest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual int32_t compareTo(::java::lang::Object* arg0) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProcessingRequest_run_1;
    friend class ProcessingRequest_run_2;
};
