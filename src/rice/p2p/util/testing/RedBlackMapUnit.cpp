// Generated from /pastry-2.1/src/rice/p2p/util/testing/RedBlackMapUnit.java
#include <rice/p2p/util/testing/RedBlackMapUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
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
typedef ::SubArray< ::java::lang::Number, ObjectArray, ::java::io::SerializableArray > NumberArray;
typedef ::SubArray< ::java::lang::Long, NumberArray, ComparableArray > LongArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

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

rice::p2p::util::testing::RedBlackMapUnit::RedBlackMapUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::RedBlackMapUnit::RedBlackMapUnit()
    : RedBlackMapUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::RedBlackMapUnit::main(::java::lang::StringArray* args)
{
    clinit();
    auto n = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
    auto t = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
    auto env = new ::rice::environment::Environment();
    auto random = npc(env)->getRandomSource();
    auto pFactory = new ::rice::pastry::commonapi::PastryIdFactory(env);
    ::rice::p2p::commonapi::IdFactory* factory = pFactory;
    auto array = new ::rice::p2p::commonapi::IdArray(n);
    auto values = new ::java::lang::LongArray(n);
    auto map = new ::rice::p2p::util::RedBlackMap();
    for (auto i = int32_t(0); i < npc(array)->length; i++) {
        array->set(i, npc(factory)->buildRandomId(random));
        npc(map)->put(static_cast< ::java::lang::Object* >((*array)[i]), static_cast< ::java::lang::Object* >((*values)[i]));
    }
    npc(::java::lang::System::out())->print(u"MAIN MAP: "_j);
    printMap(static_cast< ::java::util::SortedMap* >(map));
    testRemove(map);
    testSortedMap(t, map, factory, random, 2);
}

void rice::p2p::util::testing::RedBlackMapUnit::testRemove(::java::util::SortedMap* map)
{
    clinit();
    auto sorted = java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(map)->keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray(int32_t(0))))));
    ::java::util::Arrays::sort(static_cast< ::java::lang::ObjectArray* >(sorted));
    for (auto i = int32_t(0); i < npc(sorted)->length; i++) 
                testRemove(map, sorted, (*sorted)[i]);

}

void rice::p2p::util::testing::RedBlackMapUnit::testRemove(::java::util::SortedMap* map, ::rice::p2p::commonapi::IdArray* sorted, ::rice::p2p::commonapi::Id* remove)
{
    clinit();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"REMOVING "_j)->append(static_cast< ::java::lang::Object* >(remove))->toString());
    npc(map)->remove(remove);
    auto i = npc(npc(map)->keySet())->iterator();
    auto count = int32_t(0);
    while (npc(i)->hasNext()) {
        if(npc((*sorted)[count])->equals(remove))
            count++;

        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        if(!npc(next)->equals((*sorted)[count]))
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Remove did not expect element "_j)->append(static_cast< ::java::lang::Object* >(next))
                ->append(u" expected "_j)
                ->append(static_cast< ::java::lang::Object* >((*sorted)[count]))->toString());

        count++;
    }
    if((count < npc(sorted)->length) && (!npc((*sorted)[count])->equals(remove)))
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Remove did not receive element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))->toString());

    npc(map)->put(remove, nullptr);
}

void rice::p2p::util::testing::RedBlackMapUnit::printMap(::rice::p2p::commonapi::IdArray* id)
{
    clinit();
    for (auto i = int32_t(0); i < npc(id)->length; i++) 
                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >((*id)[i]))
            ->append(u","_j)->toString());

    npc(::java::lang::System::out())->println();
}

void rice::p2p::util::testing::RedBlackMapUnit::printMap(::java::util::SortedMap* map)
{
    clinit();
    auto i = npc(npc(map)->keySet())->iterator();
    while (npc(i)->hasNext()) 
                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(i)->next())))
            ->append(u","_j)->toString());

    npc(::java::lang::System::out())->println();
}

void rice::p2p::util::testing::RedBlackMapUnit::testSortedMap(int32_t iterations, ::java::util::SortedMap* map, ::rice::p2p::commonapi::IdFactory* factory, ::rice::environment::random::RandomSource* random, int32_t depth)
{
    clinit();
    auto sorted = java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(map)->keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray(int32_t(0))))));
    ::java::util::Arrays::sort(static_cast< ::java::lang::ObjectArray* >(sorted));
    for (auto i = int32_t(0); i < iterations; i++) {
        auto id1 = npc(factory)->buildRandomId(random);
        auto id2 = npc(factory)->buildRandomId(random);
        testHeadMap(id1, sorted, npc(map)->headMap(id1));
        testTailMap(id2, sorted, npc(map)->tailMap(id2));
        if(npc(id1)->compareTo(id2) <= 0) {
            testNormalSubMap(id1, id2, sorted, npc(map)->subMap(id1, id2));
            try {
                testWrappedSubMap(id2, id1, sorted, npc(map)->subMap(id2, id1));
            } catch (::java::lang::RuntimeException* e) {
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"Testing map "_j)->append(npc(npc(map)->keySet())->size())->toString());
                printMap(map);
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Testing  "_j)->append(static_cast< ::java::lang::Object* >(id1))
                    ->append(u" "_j)
                    ->append(static_cast< ::java::lang::Object* >(id2))->toString());
                throw e;
            }
        } else {
            testNormalSubMap(id2, id1, sorted, npc(map)->subMap(id2, id1));
            try {
                testWrappedSubMap(id1, id2, sorted, npc(map)->subMap(id1, id2));
            } catch (::java::lang::RuntimeException* e) {
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"Testing map "_j)->append(npc(npc(map)->keySet())->size())->toString());
                printMap(map);
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Testing  "_j)->append(static_cast< ::java::lang::Object* >(id1))
                    ->append(u" "_j)
                    ->append(static_cast< ::java::lang::Object* >(id2))->toString());
                throw e;
            }
        }
        if(depth > 0) {
            try {
                testSortedMap(iterations, npc(map)->headMap(id1), factory, random, depth - int32_t(1));
            } catch (::java::lang::RuntimeException* e) {
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"Testing headMap to "_j)->append(static_cast< ::java::lang::Object* >(id1))
                    ->append(u" "_j)->toString());
                printMap(npc(map)->headMap(id1));
                throw e;
            }
            try {
                testSortedMap(iterations, npc(map)->tailMap(id2), factory, random, depth - int32_t(1));
            } catch (::java::lang::RuntimeException* e) {
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"Testing tailMap from "_j)->append(static_cast< ::java::lang::Object* >(id2))
                    ->append(u" "_j)->toString());
                printMap(npc(map)->tailMap(id2));
                throw e;
            }
            try {
                testSortedMap(iterations, npc(map)->subMap(id1, id2), factory, random, depth - int32_t(1));
            } catch (::java::lang::RuntimeException* e) {
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"Testing subMap from "_j)->append(static_cast< ::java::lang::Object* >(id1))
                    ->append(u" to "_j)
                    ->append(static_cast< ::java::lang::Object* >(id2))
                    ->append(u" "_j)->toString());
                printMap(npc(map)->subMap(id1, id2));
                throw e;
            }
            try {
                testSortedMap(iterations, npc(map)->subMap(id2, id1), factory, random, depth - int32_t(1));
            } catch (::java::lang::RuntimeException* e) {
                for (auto j = int32_t(0); j < int32_t(2) - depth; j++) 
                                        npc(::java::lang::System::out())->print(u"  "_j);

                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"Testing subMap from "_j)->append(static_cast< ::java::lang::Object* >(id2))
                    ->append(u" to "_j)
                    ->append(static_cast< ::java::lang::Object* >(id1))
                    ->append(u" "_j)->toString());
                printMap(npc(map)->subMap(id2, id1));
                throw e;
            }
        }
    }
}

void rice::p2p::util::testing::RedBlackMapUnit::testHeadMap(::rice::p2p::commonapi::Id* head, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub)
{
    clinit();
    auto it = npc(npc(sub)->keySet())->iterator();
    auto count = int32_t(0);
    while (npc(it)->hasNext()) {
        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
        if(next != (*sorted)[count])
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Head test expected element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))
                ->append(u" got "_j)
                ->append(static_cast< ::java::lang::Object* >(next))->toString());

        if(npc(next)->compareTo(head) > 0)
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Head test did not expect element "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

        count++;
    }
    if((count < npc(sorted)->length) && (npc((*sorted)[count])->compareTo(head) < 0))
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Head test did not receive element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))->toString());

}

void rice::p2p::util::testing::RedBlackMapUnit::testTailMap(::rice::p2p::commonapi::Id* tail, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub)
{
    clinit();
    auto it = npc(npc(sub)->keySet())->iterator();
    auto count = getIndex(tail, sorted);
    while (npc(it)->hasNext()) {
        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
        if(next != (*sorted)[count])
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Tail test expected element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))
                ->append(u" got "_j)
                ->append(static_cast< ::java::lang::Object* >(next))->toString());

        if(npc(next)->compareTo(tail) < 0)
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Tail test did not expect element "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

        count++;
    }
    if(count < npc(sorted)->length)
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Tail test did not receive element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))->toString());

}

void rice::p2p::util::testing::RedBlackMapUnit::testNormalSubMap(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub)
{
    clinit();
    auto it = npc(npc(sub)->keySet())->iterator();
    auto count = getIndex(from, sorted);
    while (npc(it)->hasNext()) {
        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
        if(next != (*sorted)[count])
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Normal subMap test expected element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))
                ->append(u" got "_j)
                ->append(static_cast< ::java::lang::Object* >(next))->toString());

        if((npc(next)->compareTo(from) < 0) || (npc(next)->compareTo(to) >= 0))
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Normal subMap test did not expect element "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

        count++;
    }
    if((count < npc(sorted)->length) && (npc((*sorted)[count])->compareTo(to) < 0))
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Normal subMap test did not receive element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))->toString());

}

void rice::p2p::util::testing::RedBlackMapUnit::testWrappedSubMap(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub)
{
    clinit();
    try {
        auto it = npc(npc(sub)->keySet())->iterator();
        auto count = (npc(sorted)->length > 0 ? (npc((*sorted)[int32_t(0)])->compareTo(to) < 0 ? int32_t(0) : getIndex(from, sorted)) : int32_t(0));
        while (npc(it)->hasNext()) {
            auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
            if(next != (*sorted)[count])
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Wrapped subMap test expected element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))
                    ->append(u" got "_j)
                    ->append(static_cast< ::java::lang::Object* >(next))->toString());

            if((npc(next)->compareTo(from) < 0) && (npc(next)->compareTo(to) >= 0))
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Wrapped subMap test did not expect element "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

            count++;
            if((count < npc(sorted)->length) && (npc((*sorted)[count])->compareTo(to) >= 0) && (npc((*sorted)[count])->compareTo(from) < 0))
                count = getIndex(from, sorted);

        }
        if(count < npc(sorted)->length)
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"FAILURE: Wrapped subMap test did not receive element "_j)->append(static_cast< ::java::lang::Object* >((*sorted)[count]))->toString());

    } catch (::java::lang::RuntimeException* e) {
        npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"--> Testing wrapped from "_j)->append(static_cast< ::java::lang::Object* >(from))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(to))
            ->append(u" in map "_j)->toString());
        printMap(sorted);
        npc(::java::lang::System::out())->print(u"--> In map "_j);
        printMap(sub);
        throw e;
    }
}

int32_t rice::p2p::util::testing::RedBlackMapUnit::getIndex(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::IdArray* sorted)
{
    clinit();
    for (auto i = int32_t(0); i < npc(sorted)->length; i++) 
                if(npc(id)->compareTo((*sorted)[i]) <= 0)
            return i;


    return npc(sorted)->length;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::RedBlackMapUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.RedBlackMapUnit", 37);
    return c;
}

java::lang::Class* rice::p2p::util::testing::RedBlackMapUnit::getClass0()
{
    return class_();
}

