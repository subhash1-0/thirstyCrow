// Generated from /pastry-2.1/src/rice/p2p/util/testing/StringCacheUnit.java
#include <rice/p2p/util/testing/StringCacheUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/p2p/util/StringCache.hpp>
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

rice::p2p::util::testing::StringCacheUnit::StringCacheUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::StringCacheUnit::StringCacheUnit()
    : StringCacheUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::StringCacheUnit::main(::java::lang::StringArray* argv)
{
    clinit();
    npc(::java::lang::System::out())->println(u"StringCache Test Suite"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Initializing Tests"_j);
    npc(::java::lang::System::out())->print(u"    Generating string cache\t\t\t\t"_j);
    auto sc = new ::rice::p2p::util::StringCache();
    npc(::java::lang::System::out())->println(u"[ DONE ]"_j);
    npc(::java::lang::System::out())->print(u"    Generating random number generator\t\t\t"_j);
    ::rice::environment::random::RandomSource* rng = new ::rice::environment::random::simple::SimpleRandomSource(nullptr);
    npc(::java::lang::System::out())->println(u"[ DONE ]"_j);
    npc(::java::lang::System::out())->print(u"    Generating test strings\t\t\t\t"_j);
    auto test = new ::char16_tArray({
        u't'
        , u'e'
        , u's'
        , u't'
    });
    auto test_2 = new ::char16_tArray({
        u't'
        , u'e'
        , u's'
        , u't'
    });
    auto test_3 = new ::char16_tArray({
        u't'
        , u'e'
        , u's'
        , u't'
    });
    auto test2 = new ::char16_tArray({
        u't'
        , u'e'
        , u's'
        , u't'
        , u'2'
    });
    npc(::java::lang::System::out())->println(u"[ DONE ]"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Running Tests"_j);
    npc(::java::lang::System::out())->print(u"    Testing Simple Put\t\t\t\t"_j);
    auto s = npc(sc)->get(test);
    auto s2 = npc(sc)->get(test2);
    if(::java::util::Arrays::equals(test, npc(s)->toCharArray_())) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::java::lang::String::valueOf(test))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(s)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Double Put\t\t\t\t"_j);
    auto s_2 = npc(sc)->get(test_2);
    if(::java::util::Arrays::equals(test_2, npc(s)->toCharArray_()) && (s == s_2)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::java::lang::String::valueOf(test_2))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(s_2)
            ->append(u" "_j)
            ->append(npc(s_2)->hashCode())
            ->append(u" "_j)
            ->append(s)
            ->append(u" "_j)
            ->append(npc(s)->hashCode())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Loading 10000 4-char strings\t\t\t\t"_j);
    auto set = new ::java::util::HashSet();
    auto array = new ::char16_tArray(int32_t(4));
    ::java::lang::String* t = nullptr;
    for (auto i = int32_t(0); i < 10000; i++) {
        t = npc(sc)->get(randomize(rng, array));
        if(!npc(set)->contains(static_cast< ::java::lang::Object* >(t))) {
            npc(set)->add(static_cast< ::java::lang::Object* >(t));
        } else {
            auto j = npc(set)->iterator();
            while (npc(j)->hasNext()) {
                auto other = java_cast< ::java::lang::String* >(java_cast< ::java::lang::String* >(npc(j)->next()));
                if(npc(other)->equals(static_cast< ::java::lang::Object* >(t))) {
                    if(other != t) {
                        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(t)
                            ->append(u" "_j)
                            ->append(npc(t)->hashCode())
                            ->append(u" "_j)
                            ->append(other)
                            ->append(u" "_j)
                            ->append(npc(other)->hashCode())->toString());
                    } else {
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"MATCH! ("_j)->append(t)
                            ->append(u")"_j)->toString());
                    }
                }
            }
        }
    }
    npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
}

char16_tArray* rice::p2p::util::testing::StringCacheUnit::randomize(::rice::environment::random::RandomSource* rng, ::char16_tArray* text)
{
    clinit();
    auto data = new ::int8_tArray(npc(text)->length);
    npc(rng)->nextBytes(data);
    for (auto i = int32_t(0); i < npc(data)->length; i++) 
                (*text)[i] = static_cast< char16_t >(((static_cast< int8_t >(int32_t(127)) & (*data)[i]) | static_cast< int8_t >(int32_t(32))));

    return text;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::StringCacheUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.StringCacheUnit", 37);
    return c;
}

java::lang::Class* rice::p2p::util::testing::StringCacheUnit::getClass0()
{
    return class_();
}

