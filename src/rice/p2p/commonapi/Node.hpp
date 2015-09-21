// Generated from /pastry-2.1/src/rice/p2p/commonapi/Node.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::Node
    : public virtual ::java::lang::Object
{
    virtual Endpoint* registerApplication(Application* application, ::java::lang::String* instance) = 0;
    virtual Id* getId() = 0;
    virtual IdFactory* getIdFactory() = 0;
    virtual NodeHandle* getLocalNodeHandle() = 0;
    virtual ::rice::environment::Environment* getEnvironment() = 0;
    virtual Endpoint* buildEndpoint(Application* application, ::java::lang::String* instance) = 0;
    virtual ::java::lang::String* printRouteState() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
