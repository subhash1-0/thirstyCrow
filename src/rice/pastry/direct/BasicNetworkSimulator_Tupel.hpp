// Generated from /pastry-2.1/src/rice/pastry/direct/BasicNetworkSimulator.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::direct::BasicNetworkSimulator_Tupel
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::Object* i {  };
    ::org::mpisws::p2p::transport::direct::DirectTransportLayer* tl {  };
    NodeRecord* record {  };
protected:
    void ctor(::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* tl, NodeRecord* record);

    // Generated

public:
    BasicNetworkSimulator_Tupel(BasicNetworkSimulator *BasicNetworkSimulator_this, ::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* tl, NodeRecord* record);
protected:
    BasicNetworkSimulator_Tupel(BasicNetworkSimulator *BasicNetworkSimulator_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    BasicNetworkSimulator *BasicNetworkSimulator_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BasicNetworkSimulator;
};
