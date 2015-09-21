// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication
    : public ::rice::pastry::pns::PNSApplication
{

public:
    typedef ::rice::pastry::pns::PNSApplication super;

public: /* package */
    ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* contactDirectStrategy {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* contactDirectStrategy);

public: /* protected */
    virtual bool ignore(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c);
    virtual bool useHandle(::rice::pastry::NodeHandle* handle);
    ::java::util::List* getNearHandlesHelper(::java::util::List* handles) override;

public:
    ::rice::p2p::commonapi::Cancellable* getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe) override;
    ::rice::p2p::commonapi::Cancellable* getLeafSet(::rice::pastry::NodeHandle* input, ::rice::Continuation* c) override;
    ::rice::p2p::commonapi::Cancellable* getRouteRow(::rice::pastry::NodeHandle* input, int16_t row, ::rice::Continuation* c) override;
    ::rice::p2p::commonapi::Cancellable* getNearest(::rice::pastry::NodeHandle* seed, ::rice::Continuation* retToMe) override;
    ::rice::p2p::commonapi::Cancellable* getProximity(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c, int32_t timeout) override;

    // Generated
    RendezvousPNSApplication(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* contactDirectStrategy);
protected:
    RendezvousPNSApplication(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::rice::pastry::leafset::LeafSet* getLeafSet();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousPNSApplication_getLeafSet_1;
    friend class RendezvousPNSApplication_getRouteRow_2;
};
