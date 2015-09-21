// Generated from /pastry-2.1/src/rice/pastry/standard/InitiatePingNeighbor.java

#pragma once

#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::pastry::standard::InitiatePingNeighbor
    : public ::rice::pastry::messaging::Message
    , public virtual ::java::io::Serializable
{

public:
    typedef ::rice::pastry::messaging::Message super;
protected:
    void ctor();

    // Generated

public:
    InitiatePingNeighbor();
protected:
    InitiatePingNeighbor(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
