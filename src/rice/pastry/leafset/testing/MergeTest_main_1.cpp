// Generated from /pastry-2.1/src/rice/pastry/leafset/testing/MergeTest.java
#include <rice/pastry/leafset/testing/MergeTest_main_1.hpp>

#include <rice/pastry/NodeHandle.hpp>

rice::pastry::leafset::testing::MergeTest_main_1::MergeTest_main_1(::rice::pastry::Id* id, ::rice::environment::Environment* e)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor(id, e);
}

rice::pastry::NodeHandle* rice::pastry::leafset::testing::MergeTest_main_1::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return nullptr;
}

rice::pastry::transport::PMessageReceipt* rice::pastry::leafset::testing::MergeTest_main_1::send(::rice::pastry::NodeHandle* handle, ::rice::pastry::messaging::Message* message, ::rice::pastry::transport::PMessageNotification* deliverAckToMe, ::java::util::Map* options)
{
    return nullptr;
}

rice::pastry::ScheduledMessage* rice::pastry::leafset::testing::MergeTest_main_1::scheduleMsgAtFixedRate(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period)
{
    return nullptr;
}

rice::pastry::ScheduledMessage* rice::pastry::leafset::testing::MergeTest_main_1::scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay)
{
    return nullptr;
}

rice::pastry::ScheduledMessage* rice::pastry::leafset::testing::MergeTest_main_1::scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period)
{
    return nullptr;
}

int32_t rice::pastry::leafset::testing::MergeTest_main_1::proximity(::rice::pastry::NodeHandle* nh)
{
    return 0;
}

int32_t rice::pastry::leafset::testing::MergeTest_main_1::proximity(::rice::pastry::NodeHandle* nh, ::java::util::Map* options)
{
    return 0;
}

int32_t rice::pastry::leafset::testing::MergeTest_main_1::proximity(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return proximity(dynamic_cast< ::rice::pastry::NodeHandle* >(i), options);
}

void rice::pastry::leafset::testing::MergeTest_main_1::nodeIsReady()
{
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::leafset::testing::MergeTest_main_1::connect(::rice::pastry::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, ::rice::pastry::client::PastryAppl* appl, int32_t timeout)
{
    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::leafset::testing::MergeTest_main_1::coalesce(::rice::pastry::NodeHandle* newHandle)
{
    return nullptr;
}

rice::pastry::boot::Bootstrapper* rice::pastry::leafset::testing::MergeTest_main_1::getBootstrapper()
{
    return nullptr;
}

void rice::pastry::leafset::testing::MergeTest_main_1::addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
}

bool rice::pastry::leafset::testing::MergeTest_main_1::checkLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options)
{
    return false;
}

bool rice::pastry::leafset::testing::MergeTest_main_1::checkLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return checkLiveness(dynamic_cast< ::rice::pastry::NodeHandle* >(i), options);
}

int32_t rice::pastry::leafset::testing::MergeTest_main_1::getLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options)
{
    return 0;
}

int32_t rice::pastry::leafset::testing::MergeTest_main_1::getLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return getLiveness(dynamic_cast< ::rice::pastry::NodeHandle* >(i), options);
}

bool rice::pastry::leafset::testing::MergeTest_main_1::removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    return false;
}

void rice::pastry::leafset::testing::MergeTest_main_1::clearState(::rice::pastry::NodeHandle* i)
{
}

void rice::pastry::leafset::testing::MergeTest_main_1::clearState(::java::lang::Object* i)
{ 
    clearState(dynamic_cast< ::rice::pastry::NodeHandle* >(i));
}

void rice::pastry::leafset::testing::MergeTest_main_1::addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
}

bool rice::pastry::leafset::testing::MergeTest_main_1::removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
    return false;
}

java::lang::String* rice::pastry::leafset::testing::MergeTest_main_1::printRouteState()
{
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::testing::MergeTest_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

int32_t rice::pastry::leafset::testing::MergeTest_main_1::getLiveness(::rice::pastry::NodeHandle* i)
{
    return super::getLiveness(i);
}

void rice::pastry::leafset::testing::MergeTest_main_1::nodeIsReady(bool state)
{
    super::nodeIsReady(state);
}

java::lang::Class* rice::pastry::leafset::testing::MergeTest_main_1::getClass0()
{
    return class_();
}

