// Generated from /pastry-2.1/src/rice/pastry/direct/GenericNetwork.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/NetworkSimulatorImpl.hpp>

struct default_init_tag;

class rice::pastry::direct::GenericNetwork
    : public NetworkSimulatorImpl
{

public:
    typedef NetworkSimulatorImpl super;
protected:
    void ctor(::rice::environment::Environment* env, ::java::lang::String* inFile) /* throws(IOException) */;
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;
    void ctor(::rice::environment::Environment* env, ::java::io::File* inFile) /* throws(IOException) */;

    // Generated

public:
    GenericNetwork(::rice::environment::Environment* env, ::java::lang::String* inFile);
    GenericNetwork(::rice::environment::Environment* env);
    GenericNetwork(::rice::environment::Environment* env, ::java::io::File* inFile);
protected:
    GenericNetwork(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
