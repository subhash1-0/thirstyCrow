// Generated from /pastry-2.1/src/rice/tutorial/rawserialization2/MyApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/rawserialization2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::tutorial::rawserialization2::MyApp
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::commonapi::Node* node {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    virtual ::rice::p2p::commonapi::Node* getNode();
    virtual void routeMyMsg(::rice::p2p::commonapi::Id* id);
    virtual void routeMyMsgDirect(::rice::p2p::commonapi::NodeHandle* nh);
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    ::java::lang::String* toString() override;

    // Generated
    MyApp(::rice::p2p::commonapi::Node* node);
protected:
    MyApp(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
