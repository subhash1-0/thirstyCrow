// Generated from /pastry-2.1/src/rice/pastry/standard/IPNodeIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeIdFactory.hpp>

struct default_init_tag;

class rice::pastry::standard::IPNodeIdFactory
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeIdFactory
{

public:
    typedef ::java::lang::Object super;

private:
    static int32_t nextInstance_;
    ::java::net::InetAddress* localIP {  };
    int32_t port {  };

public: /* package */
    ::rice::environment::Environment* environment {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env);

public:
    ::rice::pastry::Id* generateNodeId() override;

    // Generated
    IPNodeIdFactory(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env);
protected:
    IPNodeIdFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& nextInstance();
    virtual ::java::lang::Class* getClass0();
};
