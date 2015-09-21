// Generated from /pastry-2.1/src/rice/pastry/socket/nat/CantFindFirewallException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::CantFindFirewallException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;
protected:
    void ctor(::java::lang::String* msg);

    // Generated

public:
    CantFindFirewallException(::java::lang::String* msg);
protected:
    CantFindFirewallException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
