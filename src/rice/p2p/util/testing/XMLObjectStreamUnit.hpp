// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
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

class rice::p2p::util::testing::XMLObjectStreamUnit
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::util::XMLObjectOutputStream* xoos {  };
    ::rice::p2p::util::XMLObjectInputStream* xois {  };
    ::java::io::ByteArrayOutputStream* baos {  };
    ::java::io::ByteArrayInputStream* bais {  };
protected:
    void ctor() /* throws(IOException) */;

public: /* protected */
    virtual void reset() /* throws(IOException) */;
    virtual void flip() /* throws(IOException) */;
    virtual void testInt(int32_t i);
    virtual void testBoolean(bool b);
    virtual void testByte(int8_t i);
    virtual void testChar(char16_t i);
    virtual void testDouble(double i);
    virtual void testFloat(float i);
    virtual void testLong(int64_t i);
    virtual void testShort(int16_t i);
    virtual void testMultiplePrimitives();
    virtual bool compare(::java::lang::Object* o1, ::java::lang::Object* o2);
    virtual void test(::java::lang::Object* o);
    virtual void testHashtable();
    virtual void testMultipleObjects();
    virtual void testUnserializableObject();
    virtual void testByteCustomSerializer();
    virtual void testCustomSerializer();
    virtual void testBrokenCustomSerializer();
    virtual void testUnshared();
    virtual void testExternal();
    virtual void testSubExternal();
    virtual void testPutFields();
    virtual void testUnreadData();
    virtual void testWriteReplace();
    virtual void testReadResolve();
    virtual void testInheritedWriteReplace();
    virtual void testInheritedReadResolve();
    virtual void testSerialPersistentFields();

public:
    virtual void start();
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    XMLObjectStreamUnit();
protected:
    XMLObjectStreamUnit(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
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
    friend class XMLObjectStreamUnit_TestSerialPersistentFields;
};
