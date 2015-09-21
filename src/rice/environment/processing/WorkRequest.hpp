// Generated from /pastry-2.1/src/rice/environment/processing/WorkRequest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class rice::environment::processing::WorkRequest
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::Continuation* c {  };
    ::rice::selector::SelectorManager* selectorManager {  };

public: /* protected */
    bool cancelled {  };
    bool running {  };
protected:
    void ctor(::rice::Continuation* c, ::rice::selector::SelectorManager* sm);
    void ctor();

public:
    virtual void returnResult(::java::lang::Object* o);
    virtual void returnError(::java::lang::Exception* e);
    void run() override;
    bool cancel() override;
    virtual ::java::lang::Object* doWork() /* throws(Exception) */ = 0;

    // Generated
    WorkRequest(::rice::Continuation* c, ::rice::selector::SelectorManager* sm);
    WorkRequest();
protected:
    WorkRequest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class WorkRequest_run_1;
    friend class WorkRequest_run_2;
};
