// Generated from /pastry-2.1/src/rice/Continuation.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::Continuation_ExternalContinuationRunnable
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;

private:
    Continuation_ExternalContinuation* e {  };
protected:
    void ctor();

public:
    void run() override;

public: /* protected */
    virtual void execute(Continuation* c) /* throws(Exception) */ = 0;

public:
    virtual ::java::lang::Object* invoke(::rice::selector::SelectorManager* sm) /* throws(Exception) */;
    virtual ::java::lang::Object* invoke(::rice::environment::Environment* env) /* throws(Exception) */;

    // Generated
    Continuation_ExternalContinuationRunnable();
protected:
    Continuation_ExternalContinuationRunnable(const ::default_init_tag&);


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
    friend class Continuation_ExternalRunnable;
    friend class Continuation_MultiContinuation;
    friend class Continuation_MultiContinuation_getSubContinuation_1;
    friend class Continuation_NamedContinuation;
};
