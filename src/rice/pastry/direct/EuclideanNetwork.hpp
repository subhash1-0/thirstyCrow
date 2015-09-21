// Generated from /pastry-2.1/src/rice/pastry/direct/EuclideanNetwork.java

#pragma once

#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/NetworkSimulatorImpl.hpp>

struct default_init_tag;

class rice::pastry::direct::EuclideanNetwork
    : public NetworkSimulatorImpl
{

public:
    typedef NetworkSimulatorImpl super;
protected:
    void ctor(::rice::environment::Environment* env);

    // Generated

public:
    EuclideanNetwork(::rice::environment::Environment* env);
protected:
    EuclideanNetwork(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
