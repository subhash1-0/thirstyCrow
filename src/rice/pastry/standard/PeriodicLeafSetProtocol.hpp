// Generated from /pastry-2.1/src/rice/pastry/standard/PeriodicLeafSetProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/ReadyStrategy.hpp>
#include <rice/pastry/NodeSetListener.hpp>
#include <java/util/Observer.hpp>
#include <rice/pastry/leafset/LeafSetProtocol.hpp>

struct default_init_tag;

class rice::pastry::standard::PeriodicLeafSetProtocol
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::rice::pastry::ReadyStrategy
    , public virtual ::rice::pastry::NodeSetListener
    , public virtual ::java::util::Observer
    , public virtual ::rice::pastry::leafset::LeafSetProtocol
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

public: /* protected */
    ::rice::pastry::NodeHandle* localHandle {  };
    ::rice::pastry::PastryNode* localNode {  };
    ::rice::pastry::leafset::LeafSet* leafSet {  };
    ::rice::pastry::routing::RoutingTable* routeTable {  };
    ::java::util::Map* lastTimeReceivedBLS {  };
    ::java::util::Map* lastTimeSentBLS {  };

public:
    int32_t PING_NEIGHBOR_PERIOD {  };
    int32_t LEASE_PERIOD {  };
    int32_t BLS_THROTTLE {  };

public: /* package */
    ::rice::pastry::ScheduledMessage* pingNeighborMessage {  };
    ::rice::environment::random::RandomSource* random {  };
    ::rice::environment::time::TimeSource* timeSource {  };
protected:
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt);

private:
    void updateRecBLS(::rice::pastry::NodeHandle* from, int64_t time);

public:
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;

public: /* protected */
    virtual void broadcastAll();

public: /* package */
    bool hasSetStrategy {  };

public:
    void start() override;
    void stop() override;

public: /* package */
    ::rice::pastry::NodeHandle* lastLeft {  };
    ::rice::pastry::NodeHandle* lastRight {  };

public:
    void nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added) override;

public: /* package */
    bool ready {  };

public:
    void setReady(bool r) override;
    bool isReady() override;
    virtual bool shouldBeReady();
    virtual bool hasLease(::rice::pastry::NodeHandle* nh);

private:
    bool sendBLS(::rice::pastry::NodeHandle* sendTo, bool checkLiveness);

public: /* package */
    ::java::util::Map* lastTimeRenewedLease {  };

public:
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    bool deliverWhenNotReady() override;

public: /* package */
    bool destroyed {  };

public:
    void destroy() override;
    void leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void update(::java::util::Observable* o, ::java::lang::Object* arg) override;
    virtual void removeFromLeafsetIfPossible(::rice::pastry::NodeHandle* nh);

    // Generated
    PeriodicLeafSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* local, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt);
protected:
    PeriodicLeafSetProtocol(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class PeriodicLeafSetProtocol_PLSPMessageDeserializer;
    friend class PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1;
};
