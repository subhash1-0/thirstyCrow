// Generated from /pastry-2.1/src/rice/pastry/client/CommonAPIAppl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>

struct default_init_tag;

class rice::pastry::client::CommonAPIAppl
    : public PastryAppl
{

public:
    typedef PastryAppl super;
protected:
    void ctor(::rice::pastry::PastryNode* pn);
    void ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance);

public:
    virtual void route(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* hint);
    virtual ::rice::pastry::NodeSet* localLookup(::rice::pastry::Id* key, int32_t num, bool safe);
    virtual ::rice::pastry::NodeSet* neighborSet(int32_t num);
    virtual ::rice::pastry::NodeSet* replicaSet(::rice::pastry::Id* key, int32_t max_rank);
    virtual ::rice::pastry::IdRange* range(::rice::pastry::NodeHandle* n, int32_t r, ::rice::pastry::Id* key, bool cumulative);
    virtual ::rice::pastry::IdRange* range(::rice::pastry::NodeHandle* n, int32_t r, ::rice::pastry::Id* key);
    virtual void deliver(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg) = 0;
    virtual void forward(::rice::pastry::routing::RouteMessage* msg);
    virtual void update(::rice::pastry::NodeHandle* nh, bool joined);
    void notifyReady() override;
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    void leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;

    // Generated
    CommonAPIAppl(::rice::pastry::PastryNode* pn);
    CommonAPIAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance);
protected:
    CommonAPIAppl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
