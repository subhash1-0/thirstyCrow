// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupServiceTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
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

class rice::tutorial::lookup::LookupServiceTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
protected:
    void ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */;

public:
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    LookupServiceTest(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env);
protected:
    LookupServiceTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupServiceTest_LookupServiceTest_1;
};
