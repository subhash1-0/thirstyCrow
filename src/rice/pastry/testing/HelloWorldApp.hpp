// Generated from /pastry-2.1/src/rice/pastry/testing/HelloWorldApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>

struct default_init_tag;

class rice::pastry::testing::HelloWorldApp
    : public ::rice::pastry::client::PastryAppl
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

private:
    int32_t msgid {  };
    static int32_t addr_;
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    virtual void sendRndMsg(::rice::environment::random::RandomSource* rng);
    int32_t getAddress() override;
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    bool enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* key, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt) override;
    void leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void notifyReady() override;

    // Generated
    HelloWorldApp(::rice::pastry::PastryNode* pn);
protected:
    HelloWorldApp(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();
    static int32_t& addr();
    virtual ::java::lang::Class* getClass0();
    friend class HelloWorldApp_HelloAddress;
};
