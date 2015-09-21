// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCNode.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Node.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCNode
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Node
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Node* node {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    ::rice::p2p::commonapi::Endpoint* registerApplication(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance) override;
    ::rice::p2p::commonapi::Endpoint* buildEndpoint(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance) override;
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::IdFactory* getIdFactory() override;
    ::java::lang::String* toString() override;
    ::rice::environment::Environment* getEnvironment() override;
    ::java::lang::String* printRouteState() override;

    // Generated
    GCNode(::rice::p2p::commonapi::Node* node);
protected:
    GCNode(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
