// Generated from /pastry-2.1/src/rice/pastry/dist/NodeIsDeadException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/dist/fwd-pastry-2.1.hpp>
#include <java/lang/RuntimeException.hpp>

struct default_init_tag;

class rice::pastry::dist::NodeIsDeadException
    : public ::java::lang::RuntimeException
{

public:
    typedef ::java::lang::RuntimeException super;
    ::java::lang::Exception* originalException {  };
protected:
    void ctor(::java::lang::Exception* e);

    // Generated

public:
    NodeIsDeadException(::java::lang::Exception* e);
protected:
    NodeIsDeadException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
