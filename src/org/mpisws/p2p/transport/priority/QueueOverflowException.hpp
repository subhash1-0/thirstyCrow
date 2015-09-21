// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/QueueOverflowException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::QueueOverflowException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* package */
    ::java::lang::Object* identifier {  };
    ::java::lang::Object* message {  };
    ::java::lang::Throwable* cause {  };
protected:
    void ctor(::java::lang::Object* identifier, ::java::lang::Object* message);
    void ctor(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::lang::Throwable* cause);

public:
    virtual ::java::lang::Object* getIdentifier();
    virtual ::java::lang::Object* getAttemptedMessage();
    ::java::lang::Throwable* getCause() override;

    // Generated
    QueueOverflowException(::java::lang::Object* identifier, ::java::lang::Object* message);
    QueueOverflowException(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::lang::Throwable* cause);
protected:
    QueueOverflowException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
