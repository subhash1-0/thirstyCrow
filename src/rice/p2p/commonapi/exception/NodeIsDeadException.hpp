// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/NodeIsDeadException.java

#pragma once

#include <rice/p2p/commonapi/exception/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/exception/AppSocketException.hpp>

struct default_init_tag;

class rice::p2p::commonapi::exception::NodeIsDeadException
    : public AppSocketException
{

public:
    typedef AppSocketException super;
protected:
    void ctor();

    // Generated

public:
    NodeIsDeadException();
protected:
    NodeIsDeadException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
