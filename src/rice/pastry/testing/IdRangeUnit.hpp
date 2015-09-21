// Generated from /pastry-2.1/src/rice/pastry/testing/IdRangeUnit.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::IdRangeUnit
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::environment::random::RandomSource* rng {  };

public:
    virtual ::rice::pastry::IdRange* createRandomIdRange();
    virtual ::rice::pastry::IdRange* createFullIdRange();
    virtual ::rice::pastry::IdRange* createEmptyIdRange();
    virtual ::rice::pastry::IdRange* createIdRangeStartingWith(::rice::pastry::Id* ccw);
    virtual ::rice::pastry::IdRange* createIdRangeEndingIn(::rice::pastry::Id* cw);
    virtual ::rice::pastry::Id* createIdWithPrefix(int8_t b);
    virtual void halfTest();
    virtual void equalityTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2);
    virtual void mergeIntersectTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2);
    virtual void diffSubtractTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2);
    virtual void mergeTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2);
protected:
    void ctor();

public:
    static void main(::java::lang::StringArray* args);

    // Generated
    IdRangeUnit();
protected:
    IdRangeUnit(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
