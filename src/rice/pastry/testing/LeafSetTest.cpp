// Generated from /pastry-2.1/src/rice/pastry/testing/LeafSetTest.java
#include <rice/pastry/testing/LeafSetTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Observable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/RangeCannotBeDeterminedException.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/pastry/IdRange.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/testing/LeafSetTest_MyObserver.hpp>
#include <rice/pastry/testing/LeafSetTest_TestNodeHandle.hpp>
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

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::commonapi::rawserialization::RawSerializable, ::java::lang::ObjectArray > RawSerializableArray;
            } // rawserialization
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeHandle, ::rice::p2p::commonapi::NodeHandleArray, ::rice::p2p::commonapi::rawserialization::RawSerializableArray > NodeHandleArray;
    } // pastry
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::LeafSetTest::LeafSetTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::LeafSetTest::LeafSetTest() 
    : LeafSetTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::LeafSetTest::ctor()
{
    super::ctor();
    auto env = new ::rice::environment::Environment();
    random = npc(env)->getRandomSource();
    factory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
}

void rice::pastry::testing::LeafSetTest::start()
{
    testCumulativeRange();
    testNonCumulativeRange();
    testObservers();
}

void rice::pastry::testing::LeafSetTest::testObservers()
{
    auto halfLeafSet = int32_t(3);
    auto leafset = generateLeafSet(halfLeafSet * int32_t(2), halfLeafSet * int32_t(2), false);
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(leafset));
    npc(leafset)->addNodeSetListener(new LeafSetTest_MyObserver(this, leafset));
    auto handle = npc(leafset)->get(halfLeafSet);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Removing "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());
    npc(leafset)->remove(handle);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Adding "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());
    npc(leafset)->put(handle);
    npc(::java::lang::System::out())->println();
    halfLeafSet = 6;
    leafset = generateLeafSet(halfLeafSet * int32_t(2), halfLeafSet, false);
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(leafset));
    npc(leafset)->addNodeSetListener(new LeafSetTest_MyObserver(this, leafset));
    for (auto j = int32_t(0); j < 10; j++) {
        npc(::java::lang::System::out())->println();
        for (auto i = int32_t(0); i < halfLeafSet * int32_t(5); i++) {
            handle = new LeafSetTest_TestNodeHandle(npc(factory)->generateNodeId());
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Adding "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());
            npc(leafset)->put(handle);
        }
        auto rightSide = false;
        while (npc(leafset)->size() > 2) {
            rightSide = !rightSide;
            int32_t r;
            if(rightSide) {
                r = npc(random)->nextInt(npc(leafset)->cwSize());
                if(r != 0) {
                    handle = npc(leafset)->get(r);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Removing "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());
                    npc(leafset)->remove(handle);
                }
            } else {
                r = npc(random)->nextInt(npc(leafset)->ccwSize());
                if(r != 0) {
                    handle = npc(leafset)->get(-r);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Removing "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());
                    npc(leafset)->remove(handle);
                }
            }
        }
    }
}

void rice::pastry::testing::LeafSetTest::assertTrue(::java::lang::String* intention, bool test)
{
    if(!test) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(intention)->append(u" - failed."_j)->toString());
        ::java::lang::System::exit(0);
    }
}

int32_t rice::pastry::testing::LeafSetTest::min(int32_t x, int32_t y)
{
    if(y < x)
        return y;
    else
        return x;
}

int32_t rice::pastry::testing::LeafSetTest::abs(int32_t x)
{
    if(x < 0)
        return -x;
    else
        return x;
}

void rice::pastry::testing::LeafSetTest::testCumulativeRange()
{
    for (auto nodes = int32_t(2); nodes < 20; nodes++) {
        for (auto size = int32_t(2); size < 17; size += 2) {
            auto leafset = generateLeafSet(size, nodes, false);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Testing cumulative ranges with "_j)->append(nodes)
                ->append(u" nodes and leafset size of "_j)
                ->append(size)->toString());
            for (auto pos = -min(size / int32_t(2), nodes / int32_t(2)); pos <= min(size / int32_t(2), nodes / int32_t(2)); pos++) {
                for (auto q = int32_t(0); q < size; q++) {
                    ::rice::pastry::IdRange* range = nullptr;
                    try {
                        range = npc(leafset)->range(npc(leafset)->get(pos), q);
                    } catch (::rice::p2p::commonapi::RangeCannotBeDeterminedException* rcbde) {
                    }
                    if((q < size / int32_t(2) - abs(pos)) || (size + int32_t(1) > nodes)) {
                        assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                            ->append(u" with q "_j)
                            ->append(q)
                            ->append(u" nodes "_j)
                            ->append(nodes)
                            ->append(u" size "_j)
                            ->append(size)
                            ->append(u" should be defined in leafset "_j)
                            ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), range != nullptr);
                        if(q >= nodes - int32_t(1)) {
                            assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                                ->append(u" with q "_j)
                                ->append(q)
                                ->append(u" nodes "_j)
                                ->append(nodes)
                                ->append(u" size "_j)
                                ->append(size)
                                ->append(u" should be full in leafset "_j)
                                ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), npc(range)->isFull());
                        } else {
                            assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                                ->append(u" with q "_j)
                                ->append(q)
                                ->append(u" nodes "_j)
                                ->append(nodes)
                                ->append(u" size "_j)
                                ->append(size)
                                ->append(u" should be full in leafset "_j)
                                ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), !npc(range)->isFull());
                        }
                    } else {
                        assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                            ->append(u" with q "_j)
                            ->append(q)
                            ->append(u" nodes "_j)
                            ->append(nodes)
                            ->append(u" size "_j)
                            ->append(size)
                            ->append(u" should be not defined in leafset "_j)
                            ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), range == nullptr);
                    }
                }
            }
        }
    }
}

void rice::pastry::testing::LeafSetTest::testNonCumulativeRange()
{
    for (auto nodes = int32_t(1); nodes < 20; nodes++) {
        for (auto size = int32_t(2); size < 17; size += 2) {
            auto leafset = generateLeafSet(size, nodes, false);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Testing non-cumulative ranges with "_j)->append(nodes)
                ->append(u" nodes and leafset size of "_j)
                ->append(size)->toString());
            for (auto pos = -min(size / int32_t(2), nodes / int32_t(2)); pos <= min(size / int32_t(2), nodes / int32_t(2)); pos++) {
                for (auto q = int32_t(0); q < size; q++) {
                    ::rice::pastry::IdRange* range = nullptr;
                    try {
                        range = npc(leafset)->range(npc(leafset)->get(pos), q, true);
                    } catch (::rice::p2p::commonapi::RangeCannotBeDeterminedException* rcbde) {
                    }
                    if((q < size / int32_t(2) - abs(pos)) || (size + int32_t(1) > nodes)) {
                        assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                            ->append(u" with q "_j)
                            ->append(q)
                            ->append(u" nodes "_j)
                            ->append(nodes)
                            ->append(u" size "_j)
                            ->append(size)
                            ->append(u" should not be null in leafset "_j)
                            ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), range != nullptr);
                        if(q >= nodes) {
                            assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                                ->append(u" with q "_j)
                                ->append(q)
                                ->append(u" nodes "_j)
                                ->append(nodes)
                                ->append(u" size "_j)
                                ->append(size)
                                ->append(u" should be empty in leafset "_j)
                                ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), npc(range)->isEmpty());
                        } else {
                            assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                                ->append(u" with q "_j)
                                ->append(q)
                                ->append(u" nodes "_j)
                                ->append(nodes)
                                ->append(u" size "_j)
                                ->append(size)
                                ->append(u" should be defined in leafset "_j)
                                ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), !npc(range)->isEmpty());
                        }
                    } else {
                        assertTrue(::java::lang::StringBuilder().append(u"Range of node "_j)->append(pos)
                            ->append(u" with q "_j)
                            ->append(q)
                            ->append(u" nodes "_j)
                            ->append(nodes)
                            ->append(u" size "_j)
                            ->append(size)
                            ->append(u" should be not defined in leafset "_j)
                            ->append(static_cast< ::java::lang::Object* >(leafset))->toString(), range == nullptr);
                    }
                }
            }
            if(size + int32_t(1) > nodes) {
                auto total = new ::rice::pastry::IdRange();
                for (auto q = int32_t(0); q < size; q++) {
                    total = npc(total)->merge(npc(leafset)->range(npc(leafset)->get(0), q, true));
                    total = npc(total)->merge(npc(leafset)->range(npc(leafset)->get(0), q, false));
                }
                assertTrue(::java::lang::StringBuilder().append(u"Sum of individual ranges should produce entire range with nodes "_j)->append(nodes)
                    ->append(u" size "_j)
                    ->append(size)
                    ->append(u" in leafset "_j)
                    ->append(static_cast< ::java::lang::Object* >(leafset))
                    ->append(u" with total "_j)
                    ->append(static_cast< ::java::lang::Object* >(total))->toString(), npc(total)->isFull());
            }
        }
    }
}

rice::pastry::leafset::LeafSet* rice::pastry::testing::LeafSetTest::generateLeafSet(int32_t size, int32_t nodes, bool crossover)
{
    auto handles = new ::rice::pastry::NodeHandleArray(nodes);
    for (auto i = int32_t(0); i < nodes; i++) {
        handles->set(i, new LeafSetTest_TestNodeHandle(npc(factory)->generateNodeId()));
    }
    ::java::util::Arrays::sort(static_cast< ::java::lang::ObjectArray* >(handles));
    auto i = int32_t(0);
    if(crossover) {
        i = (nodes - size + npc(random)->nextInt(size)) % nodes;
    } else {
        i = npc(random)->nextInt(nodes);
    }
    auto base = (i + size / int32_t(2)) % nodes;
    auto set = new ::rice::pastry::leafset::LeafSet((*handles)[base], size, static_cast< ::rice::pastry::routing::RoutingTable* >(nullptr));
    for (auto j = int32_t(0); j < nodes; j++) {
        npc(set)->put((*handles)[j]);
    }
    return set;
}

void rice::pastry::testing::LeafSetTest::main(::java::lang::StringArray* args)
{
    clinit();
    auto test = new LeafSetTest();
    npc(test)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::LeafSetTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.LeafSetTest", 31);
    return c;
}

java::lang::Class* rice::pastry::testing::LeafSetTest::getClass0()
{
    return class_();
}

