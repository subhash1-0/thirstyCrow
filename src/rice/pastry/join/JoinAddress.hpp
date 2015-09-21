// Generated from /pastry-2.1/src/rice/pastry/join/JoinAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::join::JoinAddress
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t myCode { int32_t(-401860632) };

public:
    static int32_t getCode();

    // Generated
    JoinAddress();
protected:
    JoinAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
