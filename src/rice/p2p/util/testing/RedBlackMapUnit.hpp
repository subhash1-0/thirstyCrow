// Generated from /pastry-2.1/src/rice/p2p/util/testing/RedBlackMapUnit.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class rice::p2p::util::testing::RedBlackMapUnit
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static void main(::java::lang::StringArray* args);

public: /* protected */
    static void testRemove(::java::util::SortedMap* map);
    static void testRemove(::java::util::SortedMap* map, ::rice::p2p::commonapi::IdArray* sorted, ::rice::p2p::commonapi::Id* remove);
    static void printMap(::rice::p2p::commonapi::IdArray* id);
    static void printMap(::java::util::SortedMap* map);
    static void testSortedMap(int32_t iterations, ::java::util::SortedMap* map, ::rice::p2p::commonapi::IdFactory* factory, ::rice::environment::random::RandomSource* random, int32_t depth);
    static void testHeadMap(::rice::p2p::commonapi::Id* head, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub);
    static void testTailMap(::rice::p2p::commonapi::Id* tail, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub);
    static void testNormalSubMap(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub);
    static void testWrappedSubMap(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to, ::rice::p2p::commonapi::IdArray* sorted, ::java::util::SortedMap* sub);
    static int32_t getIndex(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::IdArray* sorted);

    // Generated

public:
    RedBlackMapUnit();
protected:
    RedBlackMapUnit(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
