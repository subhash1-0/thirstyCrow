// Generated from /pastry-2.1/src/rice/Continuation.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::Continuation_ExternalContinuation
    : public virtual ::java::lang::Object
    , public virtual Continuation
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Exception* exception {  };
    ::java::lang::Object* result {  };
    bool done {  };

public:
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;
    virtual ::java::lang::Object* getResult();
    virtual ::java::lang::Exception* getException();
    virtual void sleep();
    virtual bool exceptionThrown();

    // Generated
    Continuation_ExternalContinuation();
protected:
    void ctor();
    Continuation_ExternalContinuation(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class Continuation;
    friend class Continuation_StandardContinuation;
    friend class Continuation_ErrorContinuation;
    friend class Continuation_ListenerContinuation;
    friend class Continuation_SimpleContinuation;
    friend class Continuation_ExternalContinuationRunnable;
    friend class Continuation_ExternalRunnable;
    friend class Continuation_MultiContinuation;
    friend class Continuation_MultiContinuation_getSubContinuation_1;
    friend class Continuation_NamedContinuation;
};
