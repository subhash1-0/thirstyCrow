// Generated from /pastry-2.1/src/rice/pastry/leafset/testing/MergeTest.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/testing/fwd-pastry-2.1.hpp>
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

struct default_init_tag;

class rice::pastry::leafset::testing::MergeTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static ::rice::pastry::leafset::LeafSet* getLeafSet(::java::lang::String* str);
    static void flip(::rice::pastry::NodeHandleArray* nds);
    static ::rice::pastry::NodeHandleArray* getHandles(::java::lang::String* str);
    static void main(::java::lang::StringArray* args);

    // Generated
    MergeTest();
protected:
    MergeTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MergeTest_main_1;
    friend class MergeTest_main_2;
    friend class MergeTest_TestNodeHandle;
};
