// Generated from /pastry-2.1/src/rice/pastry/routing/NoLegalRouteToMakeProgressException.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class rice::pastry::routing::NoLegalRouteToMakeProgressException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* protected */
    ::rice::pastry::Id* target {  };
protected:
    void ctor(::rice::pastry::Id* target);

public:
    virtual ::rice::pastry::Id* getTarget();

    // Generated
    NoLegalRouteToMakeProgressException(::rice::pastry::Id* target);
protected:
    NoLegalRouteToMakeProgressException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
