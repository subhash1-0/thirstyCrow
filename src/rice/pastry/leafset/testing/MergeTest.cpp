// Generated from /pastry-2.1/src/rice/pastry/leafset/testing/MergeTest.java
#include <rice/pastry/leafset/testing/MergeTest.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Observable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/testing/MergeTest_main_1.hpp>
#include <rice/pastry/leafset/testing/MergeTest_main_2.hpp>
#include <rice/pastry/leafset/testing/MergeTest_TestNodeHandle.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
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

rice::pastry::leafset::testing::MergeTest::MergeTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::testing::MergeTest::MergeTest()
    : MergeTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::leafset::LeafSet* rice::pastry::leafset::testing::MergeTest::getLeafSet(::java::lang::String* str)
{
    clinit();
    auto a = npc(str)->split(u"\\["_j);
    /* assert((npc(a)->length == 2)) */ ;
    auto b = npc((*a)[int32_t(1)])->split(u"]"_j);
    /* assert((npc(b)->length == 2)) */ ;
    auto s_ccw = (*a)[int32_t(0)];
    auto s_cw = (*b)[int32_t(1)];
    auto s_base = (*b)[int32_t(0)];
    auto ccw = getHandles(s_ccw);
    flip(ccw);
    auto base = (*getHandles(s_base))[int32_t(0)];
    auto cw = getHandles(s_cw);
    auto ls = new ::rice::pastry::leafset::LeafSet(base, int32_t(24), true, cw, ccw);
    return ls;
}

void rice::pastry::leafset::testing::MergeTest::flip(::rice::pastry::NodeHandleArray* nds)
{
    clinit();
    for (auto a = int32_t(0); a < npc(nds)->length / int32_t(2); a++) {
        auto b = npc(nds)->length - a - int32_t(1);
        auto temp = (*nds)[a];
        nds->set(a, (*nds)[b]);
        nds->set(b, temp);
    }
}

rice::pastry::NodeHandleArray* rice::pastry::leafset::testing::MergeTest::getHandles(::java::lang::String* str)
{
    clinit();
    auto list = new ::java::util::ArrayList();
    auto a = npc(str)->split(u"[< ]"_j);
    for (auto ctr = int32_t(0); ctr < npc(a)->length; ctr++) {
        if(npc((*a)[ctr])->length() > 3) {
            /* assert((npc(npc((*a)[ctr])->substring(0, 2))->equals(static_cast< ::java::lang::Object* >(u"0x"_j)))) */ ;
            /* assert((npc(npc((*a)[ctr])->substring(npc((*a)[ctr])->length() - int32_t(3), npc((*a)[ctr])->length()))->equals(static_cast< ::java::lang::Object* >(u"..>"_j)))) */ ;
            a->set(ctr, npc((*a)[ctr])->substring(2, npc((*a)[ctr])->length() - int32_t(3)));
            npc(list)->add(static_cast< ::java::lang::Object* >(new MergeTest_TestNodeHandle(::rice::pastry::Id::build((*a)[ctr]))));
        }
    }
    return java_cast< ::rice::pastry::NodeHandleArray* >(npc(list)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::pastry::NodeHandleArray(int32_t(0)))));
}

void rice::pastry::leafset::testing::MergeTest::main(::java::lang::StringArray* args)
{
    clinit();
    auto env = new ::rice::environment::Environment();
    auto s_ls1 = u"<0xD74D4F..><0xD7B075..><0xD98A9D..><0xDAC7F0..><0xDB39A6..><0xDD5A73..><0xE050B3..><0xE0B735..><0xE33A04..><0xE48D40..><0xE678CB..><0xE73F09..> [ <0xEA5EAF..> ] <0xEBC2BB..><0xEBD2CB..><0xEF7F43..><0xF09044..><0xF10B96..><0xF33C36..><0xF64DA9..><0xF66CD9..><0xF9E251..><0xFB7F46..><0xFC1B02..><0xFC4718..>"_j;
    auto ls1 = getLeafSet(s_ls1);
    auto s_ls2 = u" [ <0xEA1020..> ] "_j;
    auto ls2 = getLeafSet(s_ls2);
    ::rice::pastry::PastryNode* pn = new MergeTest_main_1(java_cast< ::rice::pastry::Id* >(npc(npc(ls2)->get(0))->getId()), env);
    auto rt = new ::rice::pastry::routing::RoutingTable(npc(ls2)->get(0), int32_t(1), static_cast< int8_t >(int32_t(4)), pn);
    npc(ls2)->addNodeSetListener(new MergeTest_main_2());
    npc(ls2)->merge(ls1, npc(ls1)->get(0), rt, false, nullptr);
    npc(env)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::testing::MergeTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.testing.MergeTest", 37);
    return c;
}

java::lang::Class* rice::pastry::leafset::testing::MergeTest::getClass0()
{
    return class_();
}

