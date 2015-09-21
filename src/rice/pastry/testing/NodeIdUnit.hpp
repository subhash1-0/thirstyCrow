// Generated from /pastry-2.1/src/rice/pastry/testing/NodeIdUnit.java

#pragma once

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

class rice::pastry::testing::NodeIdUnit
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::pastry::Id* nid {  };
    ::rice::environment::random::RandomSource* rng {  };

public:
    virtual ::rice::pastry::Id* createNodeId();
    virtual void equalityTest();
    virtual void distanceTest();
    virtual void baseFiddlingTest();
    virtual void msdTest();
    virtual void alternateTest();
    virtual void domainPrefixTest();
protected:
    void ctor();

public:
    static void main(::java::lang::StringArray* args);

    // Generated
    NodeIdUnit();
protected:
    NodeIdUnit(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
