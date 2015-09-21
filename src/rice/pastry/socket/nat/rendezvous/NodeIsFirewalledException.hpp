// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/NodeIsFirewalledException.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::NodeIsFirewalledException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* package */
    ::rice::pastry::NodeHandle* handle {  };
protected:
    void ctor(::rice::pastry::NodeHandle* handle);

public:
    virtual ::rice::pastry::NodeHandle* getHandle();

    // Generated
    NodeIsFirewalledException(::rice::pastry::NodeHandle* handle);
protected:
    NodeIsFirewalledException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
