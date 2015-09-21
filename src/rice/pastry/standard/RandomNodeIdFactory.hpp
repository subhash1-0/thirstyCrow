// Generated from /pastry-2.1/src/rice/pastry/standard/RandomNodeIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeIdFactory.hpp>

struct default_init_tag;

class rice::pastry::standard::RandomNodeIdFactory
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeIdFactory
{

public:
    typedef ::java::lang::Object super;

private:
    int64_t next {  };

public: /* package */
    ::rice::environment::Environment* environment {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::Environment* env);

public:
    ::rice::pastry::Id* generateNodeId() override;

    // Generated
    RandomNodeIdFactory(::rice::environment::Environment* env);
protected:
    RandomNodeIdFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
