// Generated from /pastry-2.1/src/rice/pastry/leafset/testing/MergeTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/PastryNode.hpp>

struct default_init_tag;

class rice::pastry::leafset::testing::MergeTest_main_1
    : public ::rice::pastry::PastryNode
{

public:
    typedef ::rice::pastry::PastryNode super;
    ::rice::pastry::NodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    ::rice::pastry::transport::PMessageReceipt* send(::rice::pastry::NodeHandle* handle, ::rice::pastry::messaging::Message* message, ::rice::pastry::transport::PMessageNotification* deliverAckToMe, ::java::util::Map* options) override;
    ::rice::pastry::ScheduledMessage* scheduleMsgAtFixedRate(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period) override;
    ::rice::pastry::ScheduledMessage* scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay) override;
    ::rice::pastry::ScheduledMessage* scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period) override;
    int32_t proximity(::rice::pastry::NodeHandle* nh) override;
    int32_t proximity(::rice::pastry::NodeHandle* nh, ::java::util::Map* options) override;
    void nodeIsReady() override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* connect(::rice::pastry::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, ::rice::pastry::client::PastryAppl* appl, int32_t timeout) override;
    ::rice::pastry::NodeHandle* coalesce(::rice::pastry::NodeHandle* newHandle) override;
    ::rice::pastry::boot::Bootstrapper* getBootstrapper() override;
    void addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    bool checkLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options) override;
    int32_t getLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options) override;
    bool removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    void clearState(::rice::pastry::NodeHandle* i) override;
    void addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    bool removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    ::java::lang::String* printRouteState() override;

    // Generated
    MergeTest_main_1(::rice::pastry::Id* id, ::rice::environment::Environment* e);
    static ::java::lang::Class *class_();
    virtual bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void clearState(::java::lang::Object* i) override;
    virtual int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual int32_t proximity(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual int32_t getLiveness(::rice::pastry::NodeHandle* i);
    virtual void nodeIsReady(bool state);

private:
    virtual ::java::lang::Class* getClass0();
    friend class MergeTest;
    friend class MergeTest_main_2;
    friend class MergeTest_TestNodeHandle;
};
