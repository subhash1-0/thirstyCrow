// Generated from /pastry-2.1/src/rice/pastry/testing/SinglePingTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::testing::SinglePingTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::pastry::direct::DirectPastryNodeFactory* factory {  };
    ::rice::pastry::direct::NetworkSimulator* simulator {  };
    ::rice::pastry::direct::TestRecord* testRecord {  };
    ::java::util::Vector* pastryNodes {  };
    ::java::util::Vector* pingClients {  };
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::pastry::direct::TestRecord* tr, ::rice::environment::Environment* env);

private:
    ::rice::pastry::NodeHandle* getBootstrap();

public:
    virtual ::rice::pastry::PastryNode* makePastryNode();
    virtual void sendPings(int32_t k);
    virtual bool simulate();
    virtual void checkRoutingTable();
    virtual void test();

    // Generated
    SinglePingTest(::rice::pastry::direct::TestRecord* tr, ::rice::environment::Environment* env);
protected:
    SinglePingTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
