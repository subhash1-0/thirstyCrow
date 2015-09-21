// Generated from /pastry-2.1/src/rice/pastry/client/NodeIsNotReadyException.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class rice::pastry::client::NodeIsNotReadyException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

public: /* package */
    ::rice::pastry::NodeHandle* handle {  };
protected:
    void ctor(::rice::pastry::NodeHandle* handle);

    // Generated

public:
    NodeIsNotReadyException(::rice::pastry::NodeHandle* handle);
protected:
    NodeIsNotReadyException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
