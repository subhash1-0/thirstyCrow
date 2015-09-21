// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_VariableId.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::MemoryStorageTest_VariableId::MemoryStorageTest_VariableId(MemoryStorageTest *MemoryStorageTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
{
    clinit();
}

rice::persistence::testing::MemoryStorageTest_VariableId::MemoryStorageTest_VariableId(MemoryStorageTest *MemoryStorageTest_this, int32_t num) 
    : MemoryStorageTest_VariableId(MemoryStorageTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(num);
}

constexpr int16_t rice::persistence::testing::MemoryStorageTest_VariableId::TYPE;

java::lang::String*& rice::persistence::testing::MemoryStorageTest_VariableId::STRING()
{
    clinit();
    return STRING_;
}
java::lang::String* rice::persistence::testing::MemoryStorageTest_VariableId::STRING_;

void rice::persistence::testing::MemoryStorageTest_VariableId::ctor(int32_t num)
{
    super::ctor();
    this->num = num;
}

bool rice::persistence::testing::MemoryStorageTest_VariableId::isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw)
{
    return false;
}

bool rice::persistence::testing::MemoryStorageTest_VariableId::clockwise(::rice::p2p::commonapi::Id* nid)
{
    return false;
}

rice::p2p::commonapi::Id* rice::persistence::testing::MemoryStorageTest_VariableId::addToId(::rice::p2p::commonapi::Id_Distance* offset)
{
    return nullptr;
}

rice::p2p::commonapi::Id_Distance* rice::persistence::testing::MemoryStorageTest_VariableId::distanceFromId(::rice::p2p::commonapi::Id* nid)
{
    return nullptr;
}

rice::p2p::commonapi::Id_Distance* rice::persistence::testing::MemoryStorageTest_VariableId::longDistanceFromId(::rice::p2p::commonapi::Id* nid)
{
    return nullptr;
}

int8_tArray* rice::persistence::testing::MemoryStorageTest_VariableId::toByteArray_()
{
    return nullptr;
}

void rice::persistence::testing::MemoryStorageTest_VariableId::toByteArray_(::int8_tArray* array, int32_t offset)
{
}

int32_t rice::persistence::testing::MemoryStorageTest_VariableId::getByteArrayLength()
{
    return 0;
}

java::lang::String* rice::persistence::testing::MemoryStorageTest_VariableId::toStringFull()
{
    if(num <= npc(STRING_)->length())
        return npc(STRING_)->substring(0, num);
    else
        return ::java::lang::StringBuilder().append(STRING_)->append(num)->toString();
}

int32_t rice::persistence::testing::MemoryStorageTest_VariableId::compareTo(::rice::p2p::commonapi::Id* o)
{
    return 0;
}

int32_t rice::persistence::testing::MemoryStorageTest_VariableId::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< ::rice::p2p::commonapi::Id* >(arg0));
}

void rice::persistence::testing::MemoryStorageTest_VariableId::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(num);
}

int16_t rice::persistence::testing::MemoryStorageTest_VariableId::getType()
{
    return TYPE;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_VariableId::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.testing.MemoryStorageTest.VariableId", 53);
    return c;
}

void rice::persistence::testing::MemoryStorageTest_VariableId::clinit()
{
struct string_init_ {
    string_init_() {
    STRING_ = u"0123456789ABCDEF"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_VariableId::getClass0()
{
    return class_();
}

