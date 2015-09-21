// Generated from /pastry-2.1/src/rice/p2p/util/testing/BloomFilterUnit.java
#include <rice/p2p/util/testing/BloomFilterUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/p2p/util/BloomFilter.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::BloomFilterUnit::BloomFilterUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::BloomFilterUnit::BloomFilterUnit()
    : BloomFilterUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::BloomFilterUnit::main(::java::lang::StringArray* args)
{
    clinit();
    ::rice::environment::random::RandomSource* rand = new ::rice::environment::random::simple::SimpleRandomSource(nullptr);
    auto k = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
    auto l = ::java::lang::Integer::parseInt((*args)[int32_t(1)]);
    auto m = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
    auto n = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
    auto elements = new ::int8_tArrayArray(n);
    auto filter = new ::rice::p2p::util::BloomFilter(k, m);
    for (auto i = int32_t(0); i < npc(elements)->length; i++) {
        elements->set(i, ::rice::p2p::util::MathUtils::randomBytes(l, rand));
        npc(filter)->add((*elements)[i]);
    }
    for (auto i = int32_t(0); i < npc(elements)->length; i++) {
        if(!npc(filter)->check((*elements)[i]))
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"FAILURE: Element "_j)->append(i)
                ->append(u" did not exist!"_j)->toString());

    }
    auto count = int32_t(0);
    for (auto i = int32_t(0); i < npc(elements)->length; i++) {
        if(npc(filter)->check(::rice::p2p::util::MathUtils::randomBytes(l, rand)))
            count++;

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"FALSE POSITIVE RATE: "_j)->append(count)
        ->append(u"/"_j)
        ->append(npc(elements)->length)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::BloomFilterUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.BloomFilterUnit", 37);
    return c;
}

java::lang::Class* rice::p2p::util::testing::BloomFilterUnit::getClass0()
{
    return class_();
}

