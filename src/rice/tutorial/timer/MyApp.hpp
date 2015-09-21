// Generated from /pastry-2.1/src/rice/tutorial/timer/MyApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/timer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::tutorial::timer::MyApp
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::CancellableTask* messageToSelfTask {  };

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    virtual void cancelTask();
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
    friend class MyApp_MessageToSelf;
};
