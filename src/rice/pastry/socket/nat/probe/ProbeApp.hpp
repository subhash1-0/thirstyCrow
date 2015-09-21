// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/probe/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ProbeStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::probe::ProbeApp
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::org::mpisws::p2p::transport::networkinfo::ProbeStrategy
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

public: /* package */
    ::org::mpisws::p2p::transport::networkinfo::Prober* prober {  };
    ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::networkinfo::Prober* prober, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy);

public:
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    virtual void handleProbeRequestMessage(ProbeRequestMessage* prm);
    ::rice::p2p::commonapi::Cancellable* requestProbe(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* addr, int64_t uid, ::rice::Continuation* deliverResultToMe) override;
    ::java::util::Collection* getExternalAddresses() override;

    // Generated
    ProbeApp(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::networkinfo::Prober* prober, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy);
protected:
    ProbeApp(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProbeApp_ProbeApp_1;
    friend class ProbeApp_requestProbe_2;
};
