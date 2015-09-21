// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/rendezvous/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::rendezvous::VerifyConnectivity
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    VerifyConnectivity();
protected:
    VerifyConnectivity(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class VerifyConnectivity_main_1;
    friend class VerifyConnectivity_main_1_receiveResult_1_1;
    friend class VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1;
};
