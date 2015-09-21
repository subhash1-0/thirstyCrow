// Generated from /pastry-2.1/src/rice/persistence/testing/PersistentStorageTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>

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

class rice::persistence::testing::PersistentStorageTest
    : public MemoryStorageTest
{

public:
    typedef MemoryStorageTest super;

private:
    static ::rice::p2p::commonapi::IdFactory* FACTORY_;
protected:
    void ctor(bool store, ::rice::environment::Environment* environment) /* throws(IOException) */;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    PersistentStorageTest(bool store, ::rice::environment::Environment* environment);
protected:
    PersistentStorageTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::rice::p2p::commonapi::IdFactory*& FACTORY();
    virtual ::java::lang::Class* getClass0();
};
