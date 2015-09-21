// Generated from /pastry-2.1/src/rice/Continuation.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/Continuation_ExternalContinuationRunnable.hpp>

struct default_init_tag;

class rice::Continuation_ExternalRunnable
    : public Continuation_ExternalContinuationRunnable
{

public:
    typedef Continuation_ExternalContinuationRunnable super;

public: /* protected */
    virtual ::java::lang::Object* execute() /* throws(Exception) */ = 0;
    void execute(Continuation* c) /* throws(Exception) */ override;

    // Generated

public:
    Continuation_ExternalRunnable();
protected:
    Continuation_ExternalRunnable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Continuation;
    friend class Continuation_StandardContinuation;
    friend class Continuation_ErrorContinuation;
    friend class Continuation_ListenerContinuation;
    friend class Continuation_SimpleContinuation;
    friend class Continuation_ExternalContinuation;
    friend class Continuation_ExternalContinuationRunnable;
    friend class Continuation_MultiContinuation;
    friend class Continuation_MultiContinuation_getSubContinuation_1;
    friend class Continuation_NamedContinuation;
};
