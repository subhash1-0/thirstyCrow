// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getLeafSet_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::pastry::leafset::LeafSet* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    RendezvousPNSApplication_getLeafSet_1(RendezvousPNSApplication *RendezvousPNSApplication_this, ::rice::pastry::NodeHandle* input, ::rice::Continuation* c);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    RendezvousPNSApplication *RendezvousPNSApplication_this;
    ::rice::pastry::NodeHandle* input;
    ::rice::Continuation* c;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousPNSApplication;
    friend class RendezvousPNSApplication_getRouteRow_2;
};
