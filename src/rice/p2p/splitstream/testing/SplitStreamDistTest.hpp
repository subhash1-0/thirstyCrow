// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamDistTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
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

struct default_init_tag;

class rice::p2p::splitstream::testing::SplitStreamDistTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t DEFAULT_PORT { int32_t(53245) };
    static constexpr int32_t WAIT_TO_JOIN_DELAY { int32_t(3000) };
    static constexpr int32_t WAIT_TO_SUBSCRIBE_DELAY { int32_t(3000) };
    static constexpr int32_t IM_ALIVE_PERIOD { int32_t(5000) };

private:
    static ::java::lang::String* INSTANCE_;
    static ::java::lang::String* BOOTNODE_;

public:
    static constexpr bool nameSelf { true };
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

private:
    static ::rice::pastry::Id* generateId();

    // Generated

public:
    SplitStreamDistTest();
protected:
    SplitStreamDistTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& INSTANCE();
    static ::java::lang::String*& BOOTNODE();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamDistTest_main_1;
    friend class SplitStreamDistTest_main_2;
};
