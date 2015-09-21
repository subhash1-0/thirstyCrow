// Generated from /pastry-2.1/src/rice/pastry/testing/PingAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::testing::PingAddress
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static int32_t myCode_;

public:
    static int32_t getCode();

    // Generated
    PingAddress();
protected:
    PingAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& myCode();
    virtual ::java::lang::Class* getClass0();
};
