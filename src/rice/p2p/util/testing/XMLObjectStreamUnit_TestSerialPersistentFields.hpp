// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::ObjectStreamField, ::java::lang::ObjectArray, ::java::lang::ComparableArray > ObjectStreamFieldArray;
    } // io
} // java

struct default_init_tag;

class rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::Integer* num1 {  };
    ::java::lang::Integer* num2 {  };
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;

public:
    virtual ::java::lang::Integer* getNum1();
    virtual ::java::lang::Integer* getNum2();

    // Generated
    XMLObjectStreamUnit_TestSerialPersistentFields();
protected:
    void ctor();
    XMLObjectStreamUnit_TestSerialPersistentFields(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectStreamUnit;
    friend class XMLObjectStreamUnit_testCustomSerializer_1;
    friend class XMLObjectStreamUnit_testBrokenCustomSerializer_2;
    friend class XMLObjectStreamUnit_TestByteSerialization;
    friend class XMLObjectStreamUnit_TestExternalizable;
    friend class XMLObjectStreamUnit_TestSubExternalizable;
    friend class XMLObjectStreamUnit_TestPutFields;
    friend class XMLObjectStreamUnit_TestUnreadData;
    friend class XMLObjectStreamUnit_TestReplace;
    friend class XMLObjectStreamUnit_TestReplace2;
    friend class XMLObjectStreamUnit_TestReplace3;
    friend class XMLObjectStreamUnit_TestResolve;
    friend class XMLObjectStreamUnit_TestResolve2;
    friend class XMLObjectStreamUnit_TestResolve3;
};
