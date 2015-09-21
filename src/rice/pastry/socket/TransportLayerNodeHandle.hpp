// Generated from /pastry-2.1/src/rice/pastry/socket/TransportLayerNodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/NodeHandle.hpp>

struct default_init_tag;

class rice::pastry::socket::TransportLayerNodeHandle
    : public ::rice::pastry::NodeHandle
{

public:
    typedef ::rice::pastry::NodeHandle super;
    virtual ::java::lang::Object* getAddress() = 0;
    virtual int64_t getEpoch() = 0;

    // Generated
    TransportLayerNodeHandle();
protected:
    TransportLayerNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
