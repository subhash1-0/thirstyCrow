// Generated from /pastry-2.1/src/rice/Continuation.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::Continuation_ErrorContinuation
    : public virtual ::java::lang::Object
    , public virtual Continuation
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    Continuation* parent {  };
protected:
    void ctor(Continuation* continuation);

public:
    void receiveResult(::java::lang::Object* result) override;

    // Generated
    Continuation_ErrorContinuation(Continuation* continuation);
protected:
    Continuation_ErrorContinuation(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Continuation;
    friend class Continuation_StandardContinuation;
    friend class Continuation_ListenerContinuation;
    friend class Continuation_SimpleContinuation;
    friend class Continuation_ExternalContinuation;
    friend class Continuation_ExternalContinuationRunnable;
    friend class Continuation_ExternalRunnable;
    friend class Continuation_MultiContinuation;
    friend class Continuation_MultiContinuation_getSubContinuation_1;
    friend class Continuation_NamedContinuation;
};
