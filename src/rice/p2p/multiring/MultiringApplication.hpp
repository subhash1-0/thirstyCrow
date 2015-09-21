// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringApplication.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringApplication
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Application* application {  };
    ::rice::p2p::commonapi::Id* ringId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Application* application);

public:
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* protected */
    MultiringApplication(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Application* application);
protected:
    MultiringApplication(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
