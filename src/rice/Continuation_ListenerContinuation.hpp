// Generated from /pastry-2.1/src/rice/Continuation.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::Continuation_ListenerContinuation
    : public virtual ::java::lang::Object
    , public virtual Continuation
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::String* name {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::java::lang::String* name, ::rice::environment::Environment* env);

public:
    void receiveResult(::java::lang::Object* result) override;
    void receiveException(::java::lang::Exception* result) override;

    // Generated
    Continuation_ListenerContinuation(::java::lang::String* name, ::rice::environment::Environment* env);
protected:
    Continuation_ListenerContinuation(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Continuation;
    friend class Continuation_StandardContinuation;
    friend class Continuation_ErrorContinuation;
    friend class Continuation_SimpleContinuation;
    friend class Continuation_ExternalContinuation;
    friend class Continuation_ExternalContinuationRunnable;
    friend class Continuation_ExternalRunnable;
    friend class Continuation_MultiContinuation;
    friend class Continuation_MultiContinuation_getSubContinuation_1;
    friend class Continuation_NamedContinuation;
};
