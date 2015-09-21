// Generated from /pastry-2.1/src/rice/pastry/testing/IdUnit.java
#include <rice/pastry/testing/IdUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/pastry/Id.hpp>

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

rice::pastry::testing::IdUnit::IdUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::IdUnit::IdUnit()
    : IdUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::IdUnit::main(::java::lang::StringArray* args)
{
    clinit();
    auto id0 = ::rice::pastry::Id::build(u"0"_j);
    auto id1 = ::rice::pastry::Id::build(u"1"_j);
    auto id2 = ::rice::pastry::Id::build(u"2"_j);
    auto id3 = ::rice::pastry::Id::build(u"3"_j);
    auto id4 = ::rice::pastry::Id::build(u"4"_j);
    auto id5 = ::rice::pastry::Id::build(u"5"_j);
    auto id6 = ::rice::pastry::Id::build(u"6"_j);
    auto id7 = ::rice::pastry::Id::build(u"7"_j);
    auto id8 = ::rice::pastry::Id::build(u"8"_j);
    auto id9 = ::rice::pastry::Id::build(u"9"_j);
    auto ida = ::rice::pastry::Id::build(u"A"_j);
    auto idb = ::rice::pastry::Id::build(u"B"_j);
    auto idc = ::rice::pastry::Id::build(u"C"_j);
    auto idd = ::rice::pastry::Id::build(u"D"_j);
    auto ide = ::rice::pastry::Id::build(u"E"_j);
    auto idf = ::rice::pastry::Id::build(u"F"_j);
    test(u"clockwise 0-1"_j, npc(id0)->clockwise(id1));
    test(u"clockwise 1-0"_j, !npc(id1)->clockwise(id0));
    test(u"clockwise 0-8"_j, npc(id0)->clockwise(id8));
    test(u"clockwise 8-0"_j, npc(id8)->clockwise(id0));
    test(u"clockwise 0-9"_j, !npc(id0)->clockwise(id9));
    test(u"clockwise 9-0"_j, npc(id9)->clockwise(id0));
    test(u"between 0-1-2"_j, npc(id1)->isBetween(id0, id2));
    test(u"between 2-1-0"_j, !npc(id1)->isBetween(id2, id0));
    test(u"between 0-4-2"_j, !npc(id4)->isBetween(id0, id2));
    test(u"between 2-4-0"_j, npc(id4)->isBetween(id2, id0));
    test(u"between F-0-1"_j, npc(id0)->isBetween(idf, id1));
    test(u"between 1-0-F"_j, !npc(id0)->isBetween(id1, idf));
}

void rice::pastry::testing::IdUnit::test(::java::lang::String* msg, bool result)
{
    clinit();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(msg)->append(u": "_j)
        ->append((result ? u"PASS"_j : u"FAIL"_j))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::IdUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.IdUnit", 26);
    return c;
}

java::lang::Class* rice::pastry::testing::IdUnit::getClass0()
{
    return class_();
}

