// Generated from /pastry-2.1/src/rice/pastry/testing/RegrTestApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/CommonAPIAppl.hpp>

struct default_init_tag;

class rice::pastry::testing::RegrTestApp
    : public ::rice::pastry::client::CommonAPIAppl
{

public:
    typedef ::rice::pastry::client::CommonAPIAppl super;

private:
    static int32_t addr_;
    PastryRegrTest* prg {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, PastryRegrTest* prg);

public:
    int32_t getAddress() override;
    virtual void sendMsg(::rice::pastry::Id* nid);
    virtual void sendTrace(::rice::pastry::Id* nid);
    void deliver(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg) override;
    void forward(::rice::pastry::routing::RouteMessage* rm) override;
    void update(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void notifyReady() override;
    virtual ::rice::pastry::PastryNode* getPastryNode();

    // Generated
    RegrTestApp(::rice::pastry::PastryNode* pn, PastryRegrTest* prg);
protected:
    RegrTestApp(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& addr();
    virtual ::java::lang::Class* getClass0();
    friend class RegrTestApp_RTAddress;
    friend class RTMessage;
};
