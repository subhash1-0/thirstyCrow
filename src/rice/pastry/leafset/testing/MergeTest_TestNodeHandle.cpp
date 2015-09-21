// Generated from /pastry-2.1/src/rice/pastry/leafset/testing/MergeTest.java
#include <rice/pastry/leafset/testing/MergeTest_TestNodeHandle.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::leafset::testing::MergeTest_TestNodeHandle::MergeTest_TestNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::testing::MergeTest_TestNodeHandle::MergeTest_TestNodeHandle(::rice::pastry::Id* id) 
    : MergeTest_TestNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void rice::pastry::leafset::testing::MergeTest_TestNodeHandle::ctor(::rice::pastry::Id* id)
{
    super::ctor();
    this->id = id;
}

rice::pastry::Id* rice::pastry::leafset::testing::MergeTest_TestNodeHandle::getNodeId()
{
    return id;
}

int32_t rice::pastry::leafset::testing::MergeTest_TestNodeHandle::getLiveness()
{
    return ::rice::pastry::NodeHandle::LIVENESS_ALIVE;
}

int32_t rice::pastry::leafset::testing::MergeTest_TestNodeHandle::proximity()
{
    return 1;
}

bool rice::pastry::leafset::testing::MergeTest_TestNodeHandle::ping()
{
    return true;
}

bool rice::pastry::leafset::testing::MergeTest_TestNodeHandle::equals(::java::lang::Object* obj)
{
    if(dynamic_cast< MergeTest_TestNodeHandle* >(obj) != nullptr) {
        return npc(npc((java_cast< MergeTest_TestNodeHandle* >(obj)))->id)->equals(id);
    }
    return false;
}

int32_t rice::pastry::leafset::testing::MergeTest_TestNodeHandle::hashCode()
{
    return npc(id)->hashCode();
}

void rice::pastry::leafset::testing::MergeTest_TestNodeHandle::receiveMessage(::rice::pastry::messaging::Message* m)
{
}

java::lang::String* rice::pastry::leafset::testing::MergeTest_TestNodeHandle::toString()
{
    return npc(id)->toString();
}

void rice::pastry::leafset::testing::MergeTest_TestNodeHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"not implemented."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::testing::MergeTest_TestNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.testing.MergeTest.TestNodeHandle", 52);
    return c;
}

java::lang::Class* rice::pastry::leafset::testing::MergeTest_TestNodeHandle::getClass0()
{
    return class_();
}

