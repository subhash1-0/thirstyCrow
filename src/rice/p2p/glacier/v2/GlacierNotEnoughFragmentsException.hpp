// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierNotEnoughFragmentsException.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::GlacierNotEnoughFragmentsException
    : public ::rice::p2p::glacier::GlacierException
{

public:
    typedef ::rice::p2p::glacier::GlacierException super;
    int32_t checked {  };
    int32_t found {  };
protected:
    void ctor(::java::lang::String* msg, int32_t checked, int32_t found);

    // Generated

public:
    GlacierNotEnoughFragmentsException(::java::lang::String* msg, int32_t checked, int32_t found);
protected:
    GlacierNotEnoughFragmentsException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
