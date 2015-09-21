// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/exception/NodeIsFaultyException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/exception/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::exception::NodeIsFaultyException
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
    void ctor(::java::lang::Object* identifier);

public:
    virtual ::java::lang::Object* getIdentifier();
    virtual ::java::lang::Object* getAttemptedMessage();
    ::java::lang::Throwable* getCause() override;

    // Generated
    NodeIsFaultyException(::java::lang::Object* identifier, ::java::lang::Object* message);
    NodeIsFaultyException(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::lang::Throwable* cause);
    NodeIsFaultyException(::java::lang::Object* identifier);
protected:
    NodeIsFaultyException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
