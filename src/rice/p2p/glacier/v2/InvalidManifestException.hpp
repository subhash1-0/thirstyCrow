// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/InvalidManifestException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::InvalidManifestException
    : public ::rice::p2p::glacier::GlacierException
{

public:
    typedef ::rice::p2p::glacier::GlacierException super;
protected:
    void ctor(::java::lang::String* msg);

    // Generated

public:
    InvalidManifestException(::java::lang::String* msg);
protected:
    InvalidManifestException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
