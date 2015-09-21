// Generated from /pastry-2.1/src/rice/pastry/leafset/InitiateLeafSetMaintenance.java

#pragma once

#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::pastry::leafset::InitiateLeafSetMaintenance
    : public ::rice::pastry::messaging::Message
    , public virtual ::java::io::Serializable
{

public:
    typedef ::rice::pastry::messaging::Message super;
protected:
    void ctor();

    // Generated

public:
    InitiateLeafSetMaintenance();
protected:
    InitiateLeafSetMaintenance(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
