// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/MyApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/remotesocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::tutorial::remotesocket::MyApp
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::commonapi::Node* node {  };

public: /* package */
    ::java::nio::ByteBuffer* in {  };
    int32_t MSG_LENGTH {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::p2p::commonapi::IdFactory* factory);

public:
    virtual ::rice::p2p::commonapi::Node* getNode();
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    ::java::lang::String* toString() override;

    // Generated
    MyApp(::rice::p2p::commonapi::Node* node, ::rice::p2p::commonapi::IdFactory* factory);
protected:
    MyApp(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyApp_MyApp_1;
};
