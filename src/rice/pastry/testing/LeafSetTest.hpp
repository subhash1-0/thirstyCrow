// Generated from /pastry-2.1/src/rice/pastry/testing/LeafSetTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::LeafSetTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::NodeIdFactory* factory {  };
    ::rice::environment::random::RandomSource* random {  };
protected:
    void ctor();

public:
    virtual void start();
    virtual void testObservers();

public: /* protected */
    void assertTrue(::java::lang::String* intention, bool test);
    virtual int32_t min(int32_t x, int32_t y);
    virtual int32_t abs(int32_t x);

public:
    virtual void testCumulativeRange();
    virtual void testNonCumulativeRange();

public: /* protected */
    virtual ::rice::pastry::leafset::LeafSet* generateLeafSet(int32_t size, int32_t nodes, bool crossover);

public:
    static void main(::java::lang::StringArray* args);

    // Generated
    LeafSetTest();
protected:
    LeafSetTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LeafSetTest_MyObserver;
    friend class LeafSetTest_TestNodeHandle;
};
