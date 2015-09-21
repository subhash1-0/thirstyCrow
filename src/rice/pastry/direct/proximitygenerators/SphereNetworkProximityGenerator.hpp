// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/proximitygenerators/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/direct/ProximityGenerator.hpp>

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

class rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::direct::ProximityGenerator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t maxDiameter {  };
    ::rice::environment::random::RandomSource* random {  };
protected:
    void ctor(int32_t maxDiameter);

public:
    ::rice::pastry::direct::NodeRecord* generateNodeRecord() override;
    virtual void test();
    static void main(::java::lang::StringArray* argz);
    void setRandom(::rice::environment::random::RandomSource* random) override;

    // Generated
    SphereNetworkProximityGenerator(int32_t maxDiameter);
protected:
    SphereNetworkProximityGenerator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SphereNetworkProximityGenerator_SphereNodeRecord;
};
