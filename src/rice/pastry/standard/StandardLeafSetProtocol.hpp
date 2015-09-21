// Generated from /pastry-2.1/src/rice/pastry/standard/StandardLeafSetProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/leafset/LeafSetProtocol.hpp>
#include <java/util/Observer.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardLeafSetProtocol
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::rice::pastry::leafset::LeafSetProtocol
    , public virtual ::java::util::Observer
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

public: /* protected */
    static constexpr bool failstop { true };
    ::rice::pastry::leafset::LeafSet* leafSet {  };
    ::rice::pastry::routing::RoutingTable* routeTable {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt);

public:
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;

public: /* package */
    ::java::util::HashSet* cachedSet {  };

public: /* protected */
    virtual bool checkLeafSet(::rice::pastry::leafset::LeafSet* remotels, ::rice::pastry::NodeHandle* from, bool notifyMissing);
    virtual bool mergeLeafSet(::rice::pastry::leafset::LeafSet* remotels, ::rice::pastry::NodeHandle* from);
    virtual void broadcast();
    virtual void broadcast(int32_t type);
    virtual void broadcast(::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::NodeHandle* from);

public:
    virtual void maintainLeafSet();

private:
    void requestLeafSet();

public:
    bool deliverWhenNotReady() override;
    void leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void update(::java::util::Observable* o, ::java::lang::Object* arg) override;

    // Generated
    StandardLeafSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt);
protected:
    StandardLeafSetProtocol(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
