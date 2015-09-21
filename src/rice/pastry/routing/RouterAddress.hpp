// Generated from /pastry-2.1/src/rice/pastry/routing/RouterAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::routing::RouterAddress
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t myCode { int32_t(-1396834793) };

public:
    static int32_t getCode();

    // Generated
    RouterAddress();
protected:
    RouterAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
