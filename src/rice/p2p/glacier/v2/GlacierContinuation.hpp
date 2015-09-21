// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierContinuation.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::GlacierContinuation
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t myUID {  };
    bool terminated {  };

public:
    virtual void receiveResult(::java::lang::Object* result) = 0;
    virtual void receiveException(::java::lang::Exception* exception) = 0;
    virtual void timeoutExpired() = 0;
    virtual int64_t getTimeout() = 0;
    virtual void init_();
    virtual void syncReceiveResult(::java::lang::Object* result);
    virtual void syncReceiveException(::java::lang::Exception* exception);
    virtual void syncTimeoutExpired();
    virtual void setup(int32_t uid);
    virtual int32_t getMyUID();
    virtual bool hasTerminated();
    virtual void terminate();
    ::java::lang::String* toString() override;

    // Generated
    GlacierContinuation();
protected:
    GlacierContinuation(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
