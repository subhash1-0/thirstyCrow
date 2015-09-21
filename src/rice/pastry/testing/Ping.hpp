// Generated from /pastry-2.1/src/rice/pastry/testing/Ping.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>

struct default_init_tag;

class rice::pastry::testing::Ping
    : public ::rice::pastry::client::PastryAppl
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

private:
    static int32_t pingAddress_;
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    int32_t getAddress() override;
    virtual void sendPing(::rice::pastry::Id* nid);
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    bool enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* from, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt) override;
    void leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;

    // Generated
    Ping(::rice::pastry::PastryNode* pn);
protected:
    Ping(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& pingAddress();
    virtual ::java::lang::Class* getClass0();
};
