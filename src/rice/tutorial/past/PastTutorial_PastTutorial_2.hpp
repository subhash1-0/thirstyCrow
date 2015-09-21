// Generated from /pastry-2.1/src/rice/tutorial/past/PastTutorial.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/tutorial/past/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::past::PastTutorial_PastTutorial_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::p2p::past::PastContent* result);
    void receiveException(::java::lang::Exception* result) override;

    // Generated
    PastTutorial_PastTutorial_2(PastTutorial *PastTutorial_this, ::rice::p2p::commonapi::Id* lookupKey);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    PastTutorial *PastTutorial_this;
    ::rice::p2p::commonapi::Id* lookupKey;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastTutorial;
    friend class PastTutorial_PastTutorial_1;
    friend class PastTutorial_PastTutorial_3;
};
