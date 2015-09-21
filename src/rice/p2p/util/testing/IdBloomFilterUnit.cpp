// Generated from /pastry-2.1/src/rice/p2p/util/testing/IdBloomFilterUnit.java
#include <rice/p2p/util/testing/IdBloomFilterUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdFactory.hpp>
#include <rice/p2p/util/IdBloomFilter.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <Array.hpp>

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

rice::p2p::util::testing::IdBloomFilterUnit::IdBloomFilterUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::IdBloomFilterUnit::IdBloomFilterUnit()
    : IdBloomFilterUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::IdBloomFilterUnit::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto n = int32_t(300);
    auto env = new ::rice::environment::Environment();
    auto random = npc(env)->getRandomSource();
    auto pFactory = new ::rice::pastry::commonapi::PastryIdFactory(env);
    ::rice::p2p::commonapi::IdFactory* factory = new ::rice::p2p::multiring::MultiringIdFactory(npc(pFactory)->buildRandomId(random), pFactory);
    auto gFactory = new ::rice::p2p::past::gc::GCIdFactory(factory);
    auto set = npc(gFactory)->buildIdSet();
    for (auto i = int32_t(0); i < n; i++) 
                npc(set)->addId(new ::rice::p2p::past::gc::GCId(npc(factory)->buildRandomId(random), ::java::lang::System::currentTimeMillis()));

    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Start: "_j)->append(::java::lang::System::currentTimeMillis())->toString());
    auto filter = new ::rice::p2p::util::IdBloomFilter(set);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Done1: "_j)->append(::java::lang::System::currentTimeMillis())->toString());
    auto i = npc(set)->getIterator();
    while (npc(i)->hasNext()) {
        if(!npc(filter)->check(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i)->next()))))
            npc(::java::lang::System::out())->println(u"FAILURE: Element did not exist!"_j);

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Done2: "_j)->append(::java::lang::System::currentTimeMillis())->toString());
    auto count = int32_t(0);
    for (auto j = int32_t(0); j < npc(set)->numElements(); j++) {
        if(npc(filter)->check(new ::rice::p2p::past::gc::GCId(npc(factory)->buildRandomId(random), ::java::lang::System::currentTimeMillis())))
            count++;

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Done3: "_j)->append(::java::lang::System::currentTimeMillis())->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"FALSE POSITIVE RATE: "_j)->append(count)
        ->append(u"/"_j)
        ->append(npc(set)->numElements())->toString());
    auto set2 = npc(pFactory)->buildIdSet();
    auto id = npc(pFactory)->buildRandomId(random);
    for (auto k = int32_t(0); k < 16; k++) {
        npc(set2)->addId(addToId(pFactory, id, k));
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Start: "_j)->append(::java::lang::System::currentTimeMillis())->toString());
    auto filter2 = new ::rice::p2p::util::IdBloomFilter(set2);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Done1: "_j)->append(::java::lang::System::currentTimeMillis())->toString());
    auto i2 = npc(set2)->getIterator();
    while (npc(i2)->hasNext()) {
        if(!npc(filter2)->check(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i2)->next()))))
            npc(::java::lang::System::out())->println(u"FAILURE: Element did not exist!"_j);

    }
    for (auto k = int32_t(16); k < 32; k++) {
        auto id2 = addToId(pFactory, id, k);
        if(npc(filter2)->check(id2))
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"WARNING: Element existed when it probably shouldn't! "_j)->append(k)->toString());

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Done2: "_j)->append(::java::lang::System::currentTimeMillis())->toString());
    npc(env)->destroy();
}

rice::p2p::commonapi::Id* rice::p2p::util::testing::IdBloomFilterUnit::addToId(::rice::p2p::commonapi::IdFactory* FACTORY, ::rice::p2p::commonapi::Id* id, int32_t num)
{
    clinit();
    auto bytes = npc(id)->toByteArray_();
    (*bytes)[int32_t(0)] += num;
    return npc(FACTORY)->buildId(bytes);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::IdBloomFilterUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.IdBloomFilterUnit", 39);
    return c;
}

java::lang::Class* rice::p2p::util::testing::IdBloomFilterUnit::getClass0()
{
    return class_();
}

