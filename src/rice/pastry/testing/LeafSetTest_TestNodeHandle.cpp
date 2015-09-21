// Generated from /pastry-2.1/src/rice/pastry/testing/LeafSetTest.java
#include <rice/pastry/testing/LeafSetTest_TestNodeHandle.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/Id.hpp>

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

rice::pastry::testing::LeafSetTest_TestNodeHandle::LeafSetTest_TestNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::LeafSetTest_TestNodeHandle::LeafSetTest_TestNodeHandle(::rice::pastry::Id* id) 
    : LeafSetTest_TestNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void rice::pastry::testing::LeafSetTest_TestNodeHandle::ctor(::rice::pastry::Id* id)
{
    super::ctor();
    this->id = id;
}

rice::pastry::Id* rice::pastry::testing::LeafSetTest_TestNodeHandle::getNodeId()
{
    return id;
}

int32_t rice::pastry::testing::LeafSetTest_TestNodeHandle::getLiveness()
{
    return LIVENESS_ALIVE;
}

int32_t rice::pastry::testing::LeafSetTest_TestNodeHandle::proximity()
{
    return 1;
}

bool rice::pastry::testing::LeafSetTest_TestNodeHandle::ping()
{
    return true;
}

bool rice::pastry::testing::LeafSetTest_TestNodeHandle::equals(::java::lang::Object* obj)
{
    if(dynamic_cast< LeafSetTest_TestNodeHandle* >(obj) != nullptr) {
        return npc(npc((java_cast< LeafSetTest_TestNodeHandle* >(obj)))->id)->equals(id);
    }
    return false;
}

int32_t rice::pastry::testing::LeafSetTest_TestNodeHandle::hashCode()
{
    return npc(id)->hashCode();
}

void rice::pastry::testing::LeafSetTest_TestNodeHandle::receiveMessage(::rice::pastry::messaging::Message* m)
{
}

int32_t rice::pastry::testing::LeafSetTest_TestNodeHandle::compareTo(LeafSetTest_TestNodeHandle* o)
{
    return npc(id)->compareTo(static_cast< ::rice::p2p::commonapi::Id* >(npc((java_cast< LeafSetTest_TestNodeHandle* >(o)))->id));
}

int32_t rice::pastry::testing::LeafSetTest_TestNodeHandle::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< LeafSetTest_TestNodeHandle* >(o));
}

java::lang::String* rice::pastry::testing::LeafSetTest_TestNodeHandle::toString()
{
    return npc(id)->toString();
}

void rice::pastry::testing::LeafSetTest_TestNodeHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"not implemented."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::LeafSetTest_TestNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.LeafSetTest.TestNodeHandle", 46);
    return c;
}

java::lang::Class* rice::pastry::testing::LeafSetTest_TestNodeHandle::getClass0()
{
    return class_();
}

