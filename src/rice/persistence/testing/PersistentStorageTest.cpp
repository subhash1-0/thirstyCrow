// Generated from /pastry-2.1/src/rice/persistence/testing/PersistentStorageTest.java
#include <rice/persistence/testing/PersistentStorageTest.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/persistence/PersistentStorage.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::PersistentStorageTest::PersistentStorageTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::testing::PersistentStorageTest::PersistentStorageTest(bool store, ::rice::environment::Environment* environment)  /* throws(IOException) */
    : PersistentStorageTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(store,environment);
}

rice::p2p::commonapi::IdFactory*& rice::persistence::testing::PersistentStorageTest::FACTORY()
{
    clinit();
    return FACTORY_;
}
rice::p2p::commonapi::IdFactory* rice::persistence::testing::PersistentStorageTest::FACTORY_;

void rice::persistence::testing::PersistentStorageTest::ctor(bool store, ::rice::environment::Environment* environment) /* throws(IOException) */
{
    super::ctor(store, environment);
    FACTORY_ = new ::rice::pastry::commonapi::PastryIdFactory(this->environment);
    storage = new ::rice::persistence::PersistentStorage(FACTORY_, u"PersistentStorageTest"_j, u"."_j, int32_t(20000000), environment);
}

void rice::persistence::testing::PersistentStorageTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto store = true;
    if(npc(args)->length > 0) {
        store = !npc((*args)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(u"-nostore"_j));
    }
    auto test = new PersistentStorageTest(store, new ::rice::environment::Environment());
    npc(test)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::PersistentStorageTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.testing.PersistentStorageTest", 46);
    return c;
}

java::lang::Class* rice::persistence::testing::PersistentStorageTest::getClass0()
{
    return class_();
}

