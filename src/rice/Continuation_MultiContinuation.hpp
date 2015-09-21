// Generated from /pastry-2.1/src/rice/Continuation.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::Continuation_MultiContinuation
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::ObjectArray* result {  };
    ::boolArray* haveResult {  };
    Continuation* parent {  };
    bool done {  };
protected:
    void ctor(Continuation* parent, int32_t num);

public:
    virtual Continuation* getSubContinuation(int32_t index);

public: /* protected */
    virtual void receive(int32_t index, ::java::lang::Object* o);

public:
    virtual bool isDone() /* throws(Exception) */;
    virtual ::java::lang::Object* getResult();

    // Generated
    Continuation_MultiContinuation(Continuation* parent, int32_t num);
protected:
    Continuation_MultiContinuation(const ::default_init_tag&);


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
    friend class Continuation_ExternalRunnable;
    friend class Continuation_MultiContinuation_getSubContinuation_1;
    friend class Continuation_NamedContinuation;
};
