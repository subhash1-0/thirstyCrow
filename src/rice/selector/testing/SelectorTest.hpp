// Generated from /pastry-2.1/src/rice/selector/testing/SelectorTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/selector/testing/fwd-pastry-2.1.hpp>
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

class rice::selector::testing::SelectorTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static bool logAll_;
    static bool logIssues_;
    static ::rice::environment::Environment* environment_;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;
    static void scheduleRepeated(::rice::selector::Timer* timer, ::rice::selector::SelectorManager* sman);
    static void scheduleStuff(::rice::selector::Timer* timer, ::rice::selector::SelectorManager* sman);

    // Generated
    SelectorTest();
protected:
    SelectorTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static bool& logAll();
    static bool& logIssues();
    static ::rice::environment::Environment*& environment();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SelectorTest_scheduleRepeated_1;
    friend class SelectorTest_scheduleStuff_2;
    friend class SelectorTest_scheduleStuff_3;
};
