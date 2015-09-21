// Generated from /pastry-2.1/src/rice/pastry/direct/DirectNodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <java/util/Observer.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectNodeHandle
    : public ::rice::pastry::socket::TransportLayerNodeHandle
    , public virtual ::java::util::Observer
{

public:
    typedef ::rice::pastry::socket::TransportLayerNodeHandle super;
    NetworkSimulator* simulator {  };
protected:
    void ctor(::rice::pastry::PastryNode* ln, NetworkSimulator* sim);

public:
    virtual ::rice::pastry::PastryNode* getRemote();
    ::rice::pastry::Id* getNodeId() override;
    int32_t getLiveness() override;
    virtual NetworkSimulator* getSimulator();
    void notifyObservers(::java::lang::Object* arg) override;
    bool ping() override;
    void assertLocalNode() override;
    int32_t proximity() override;
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;
    bool equals(::java::lang::Object* obj) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;
    void update(::java::util::Observable* arg0, ::java::lang::Object* arg1) override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    NodeRecord* getAddress() override;
    int64_t getEpoch() override;

    // Generated

public: /* protected */
    DirectNodeHandle(::rice::pastry::PastryNode* ln, NetworkSimulator* sim);
protected:
    DirectNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void update(::java::lang::Object* update);
    virtual void notifyObservers();

private:
    virtual ::java::lang::Class* getClass0();
};
