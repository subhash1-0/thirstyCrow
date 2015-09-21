// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit.hpp>

#include <java/io/BufferedOutputStream.hpp>
#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/NotSerializableException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/Character.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/reflect/Array_.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Vector.hpp>
#include <rice/p2p/util/XMLObjectInputStream.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_testCustomSerializer_1.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_testBrokenCustomSerializer_2.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestByteSerialization.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestExternalizable.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestPutFields.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestReplace2.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestReplace3.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestReplace.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestResolve2.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestResolve3.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestResolve.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestSerialPersistentFields.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestSubExternalizable.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestUnreadData.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::XMLObjectStreamUnit::XMLObjectStreamUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit::XMLObjectStreamUnit()  /* throws(IOException) */
    : XMLObjectStreamUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit::ctor() /* throws(IOException) */
{
    super::ctor();
    reset();
}

void rice::p2p::util::testing::XMLObjectStreamUnit::reset() /* throws(IOException) */
{
    baos = new ::java::io::ByteArrayOutputStream();
    xoos = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(baos));
    bais = nullptr;
    xois = nullptr;
}

void rice::p2p::util::testing::XMLObjectStreamUnit::flip() /* throws(IOException) */
{
    npc(xoos)->close();
    bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
    xois = new ::rice::p2p::util::XMLObjectInputStream(bais);
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testInt(int32_t i)
{
    try {
        npc(xoos)->writeInt(i);
        flip();
        auto j = npc(xois)->readInt();
        reset();
        if(i != j)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"int "_j)->append(j)
                ->append(u" was not equal to "_j)
                ->append(i)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testBoolean(bool b)
{
    try {
        npc(xoos)->writeBoolean(b);
        flip();
        auto c = npc(xois)->readBoolean();
        auto xml = new ::java::lang::String(npc(baos)->toByteArray_());
        reset();
        if(b != c)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"boolean "_j)->append(c)
                ->append(u" was not equal to "_j)
                ->append(b)
                ->append(u". XML: "_j)
                ->append(xml)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testByte(int8_t i)
{
    try {
        npc(xoos)->writeByte(i);
        flip();
        auto j = npc(xois)->readByte();
        reset();
        if(i != j)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"byte "_j)->append(j)
                ->append(u" was not equal to "_j)
                ->append(i)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testChar(char16_t i)
{
    try {
        npc(xoos)->writeChar(i);
        flip();
        auto j = npc(xois)->readChar();
        reset();
        if(i != j)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"char "_j)->append(j)
                ->append(u" was not equal to "_j)
                ->append(i)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testDouble(double i)
{
    try {
        npc(xoos)->writeDouble(i);
        flip();
        auto j = npc(xois)->readDouble();
        reset();
        if(i != j)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"double "_j)->append(j)
                ->append(u" was not equal to "_j)
                ->append(i)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testFloat(float i)
{
    try {
        npc(xoos)->writeFloat(i);
        flip();
        auto j = npc(xois)->readFloat();
        reset();
        if(i != j)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"float "_j)->append(j)
                ->append(u" was not equal to "_j)
                ->append(i)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testLong(int64_t i)
{
    try {
        npc(xoos)->writeLong(i);
        flip();
        auto j = npc(xois)->readLong();
        reset();
        if(i != j)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"long "_j)->append(j)
                ->append(u" was not equal to "_j)
                ->append(i)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testShort(int16_t i)
{
    try {
        npc(xoos)->writeShort(i);
        flip();
        auto j = npc(xois)->readShort();
        reset();
        if(i != j)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"short "_j)->append(j)
                ->append(u" was not equal to "_j)
                ->append(i)->toString());

    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testMultiplePrimitives()
{
    try {
        auto i = -int32_t(1029);
        auto d = 2939.22;
        auto l = int64_t(1929029389303LL);
        npc(xoos)->writeInt(i);
        npc(xoos)->writeDouble(d);
        npc(xoos)->writeLong(l);
        flip();
        if((npc(xois)->readInt() != i) || (npc(xois)->readDouble() != d) || (npc(xois)->readLong() != l))
            throw new ::java::io::IOException(u"Multiple primitives were not read correctly!"_j);

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

bool rice::p2p::util::testing::XMLObjectStreamUnit::compare(::java::lang::Object* o1, ::java::lang::Object* o2)
{
    if(npc(o1)->equals(o2))
        return true;

    if(npc(npc(o1)->getClass())->isArray_() && npc(npc(o2)->getClass())->isArray_() && npc(npc(npc(o1)->getClass())->getComponentType())->equals(npc(npc(o2)->getClass())->getComponentType())) {
        if(::java::lang::reflect::Array_::getLength(o1) != ::java::lang::reflect::Array_::getLength(o2))
            return false;

        if(npc(npc(npc(o2)->getClass())->getComponentType())->isPrimitive()) {
            auto c = npc(npc(o2)->getClass())->getComponentType();
            if(npc(c)->equals(::java::lang::Integer::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::int32_tArray* >(o1), java_cast< ::int32_tArray* >(o2));
            } else if(npc(c)->equals(::java::lang::Boolean::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::boolArray* >(o1), java_cast< ::boolArray* >(o2));
            } else if(npc(c)->equals(::java::lang::Byte::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::int8_tArray* >(o1), java_cast< ::int8_tArray* >(o2));
            } else if(npc(c)->equals(::java::lang::Character::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::char16_tArray* >(o1), java_cast< ::char16_tArray* >(o2));
            } else if(npc(c)->equals(::java::lang::Double::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::doubleArray* >(o1), java_cast< ::doubleArray* >(o2));
            } else if(npc(c)->equals(::java::lang::Float::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::floatArray* >(o1), java_cast< ::floatArray* >(o2));
            } else if(npc(c)->equals(::java::lang::Long::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::int64_tArray* >(o1), java_cast< ::int64_tArray* >(o2));
            } else if(static_cast< ::java::lang::Object* >(c) == static_cast< ::java::lang::Object* >(::java::lang::Short::TYPE())) {
                return ::java::util::Arrays::equals(java_cast< ::int16_tArray* >(o1), java_cast< ::int16_tArray* >(o2));
            } else {
                throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Class "_j)->append(static_cast< ::java::lang::Object* >(c))
                    ->append(u" is not primitive!"_j)->toString());
            }
        } else {
            for (auto i = int32_t(0); i < ::java::lang::reflect::Array_::getLength(o1); i++) 
                                if(!compare(::java::lang::reflect::Array_::get(o1, i), ::java::lang::reflect::Array_::get(o2, i)))
                    return false;


            return true;
        }
    }
    return false;
}

void rice::p2p::util::testing::XMLObjectStreamUnit::test(::java::lang::Object* o)
{
    try {
        auto start = ::java::lang::System::currentTimeMillis();
        npc(xoos)->writeObject(o);
        flip();
        auto mid = ::java::lang::System::currentTimeMillis();
        auto o2 = npc(xois)->readObject();
        auto end = ::java::lang::System::currentTimeMillis();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"WRITE: "_j)->append((mid - start))
            ->append(u" READ: "_j)
            ->append((end - mid))->toString());
        if(o == o2)
            throw new ::java::io::IOException(u"Returned object is identicial to first!"_j);

        if(!compare(o, o2)) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"XML IS: "_j)->append((new ::java::lang::String(npc(baos)->toByteArray_())))->toString());
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object "_j)->append(static_cast< ::java::lang::Object* >(o2))
                ->append(u" was not equal to "_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());
        }
        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testHashtable()
{
    try {
        auto table = new ::java::util::Hashtable();
        auto i = new ::java::lang::Integer(int32_t(1020));
        npc(table)->put(static_cast< ::java::lang::Object* >(u"monkey"_j), static_cast< ::java::lang::Object* >(i));
        npc(table)->put(static_cast< ::java::lang::Object* >(u"cat"_j), static_cast< ::java::lang::Object* >(i));
        npc(table)->put(static_cast< ::java::lang::Object* >(i), static_cast< ::java::lang::Object* >(i));
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(table));
        flip();
        auto table2 = java_cast< ::java::util::Hashtable* >(npc(xois)->readObject());
        if(table == table2)
            throw new ::java::io::IOException(u"Returned table is identicial to first!"_j);

        if(!(npc(table)->equals(static_cast< ::java::lang::Object* >(table2))))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object "_j)->append(static_cast< ::java::lang::Object* >(table2))
                ->append(u" was not equal to "_j)
                ->append(static_cast< ::java::lang::Object* >(table))->toString());

        if(!(java_cast< ::java::lang::Object* >(npc(table2)->get(static_cast< ::java::lang::Object* >(u"monkey"_j))) == java_cast< ::java::lang::Object* >(npc(table2)->get(static_cast< ::java::lang::Object* >(u"cat"_j)))))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(table2)->get(static_cast< ::java::lang::Object* >(u"monkey"_j)))))
                ->append(u" was not equal to "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(table2)->get(static_cast< ::java::lang::Object* >(u"cat"_j)))))->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testMultipleObjects()
{
    try {
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(int32_t(28))));
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(new ::java::util::Vector()));
        flip();
        if(!(npc(npc(xois)->readObject())->equals(new ::java::lang::Integer(int32_t(28))) || npc(npc(xois)->readObject())->equals(new ::java::util::Vector())))
            throw new ::java::io::IOException(u"Objects are not equal!"_j);

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testUnserializableObject()
{
    try {
        try {
            npc(xoos)->writeObject(new ::java::lang::Object());
        } catch (::java::io::NotSerializableException* e) {
            reset();
            return;
        }
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testByteCustomSerializer()
{
    try {
        auto object = new XMLObjectStreamUnit_TestByteSerialization();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"XML IS: "_j)->append((new ::java::lang::String(npc(baos)->toByteArray_())))->toString());
        auto object2 = java_cast< XMLObjectStreamUnit_TestByteSerialization* >(npc(xois)->readObject());
        if(object2 == nullptr)
            throw new ::java::io::IOException(u"Object was null!"_j);

        if(npc(object2)->bytes() == nullptr)
            throw new ::java::io::IOException(u"Object bytes was null!"_j);

        if(npc(npc(object2)->bytes())->length != 5)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct length "_j)->append(npc(npc(object2)->bytes())->length)->toString());

        for (auto i = int32_t(0); i < 4; i++) 
                        if((*npc(object)->bytes())[i] != (*npc(object2)->bytes())[i])
                throw new ::java::io::IOException(u"Object did not have correct byte!"_j);


        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testCustomSerializer()
{
    try {
        ::java::lang::Object* object = new XMLObjectStreamUnit_testCustomSerializer_1(this);
        npc(xoos)->writeObject(object);
        flip();
        auto object2 = npc(xois)->readObject();
        if(npc(object2)->hashCode() != 100)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct hashCode "_j)->append(npc(object2)->hashCode())->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testBrokenCustomSerializer()
{
    try {
        try {
            ::java::lang::Object* object = new XMLObjectStreamUnit_testBrokenCustomSerializer_2(this);
            npc(xoos)->writeObject(object);
            flip();
            npc(xois)->readObject();
        } catch (::java::io::IOException* e) {
            reset();
            return;
        } catch (::java::lang::ClassNotFoundException* e) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
            npc(e)->printStackTrace();
        }
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testUnshared()
{
    try {
        ::java::lang::Object* object = new ::java::lang::Integer(int32_t(3));
        npc(xoos)->writeObject(object);
        npc(xoos)->writeUnshared(object);
        npc(xoos)->writeObject(object);
        flip();
        auto object2 = npc(xois)->readObject();
        auto object3 = npc(xois)->readObject();
        auto object4 = npc(xois)->readObject();
        if((object2 == object3) || (object3 == object4) || (object2 != object4))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct equality "_j)->append(::java::lang::System::identityHashCode(object2))
                ->append(u" "_j)
                ->append(::java::lang::System::identityHashCode(object3))
                ->append(u" "_j)
                ->append(::java::lang::System::identityHashCode(object4))->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testExternal()
{
    try {
        auto object = new XMLObjectStreamUnit_TestExternalizable();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = java_cast< XMLObjectStreamUnit_TestExternalizable* >(npc(xois)->readObject());
        if(npc(object2)->getNum() != 299)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct num "_j)->append(npc(object2)->getNum())->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testSubExternal()
{
    try {
        auto object = new XMLObjectStreamUnit_TestSubExternalizable(nullptr);
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = java_cast< XMLObjectStreamUnit_TestSubExternalizable* >(npc(xois)->readObject());
        if(npc(object2)->getNum() != 1000)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct num "_j)->append(npc(object2)->getNum())->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testPutFields()
{
    try {
        auto object = new XMLObjectStreamUnit_TestPutFields();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = java_cast< XMLObjectStreamUnit_TestPutFields* >(npc(xois)->readObject());
        if((npc(object2)->getNum() != 10001) || (npc(object2)->getNum2() != 99))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct num "_j)->append(npc(object2)->getNum())
                ->append(u" "_j)
                ->append(npc(object2)->getNum2())->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testUnreadData()
{
    try {
        auto object = new XMLObjectStreamUnit_TestUnreadData();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = java_cast< XMLObjectStreamUnit_TestUnreadData* >(npc(xois)->readObject());
        if(npc(object2)->getNum() != npc(object)->getNum())
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct num "_j)->append(npc(object2)->getNum())
                ->append(u" "_j)
                ->append(npc(object)->getNum())->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testWriteReplace()
{
    try {
        auto object = new XMLObjectStreamUnit_TestReplace();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = npc(xois)->readObject();
        if(!(dynamic_cast< XMLObjectStreamUnit_TestReplace2* >(object2) != nullptr))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct class "_j)->append(static_cast< ::java::lang::Object* >(npc(object2)->getClass()))->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testReadResolve()
{
    try {
        auto object = new XMLObjectStreamUnit_TestResolve();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = npc(xois)->readObject();
        if(!(dynamic_cast< XMLObjectStreamUnit_TestResolve2* >(object2) != nullptr))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct class "_j)->append(static_cast< ::java::lang::Object* >(npc(object2)->getClass()))->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testInheritedWriteReplace()
{
    try {
        auto object = new XMLObjectStreamUnit_TestReplace3();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = npc(xois)->readObject();
        if(!(dynamic_cast< XMLObjectStreamUnit_TestReplace2* >(object2) != nullptr))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct class "_j)->append(static_cast< ::java::lang::Object* >(npc(object2)->getClass()))->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testInheritedReadResolve()
{
    try {
        auto object = new XMLObjectStreamUnit_TestResolve3();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = npc(xois)->readObject();
        if(!(dynamic_cast< XMLObjectStreamUnit_TestResolve2* >(object2) != nullptr))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct class "_j)->append(static_cast< ::java::lang::Object* >(npc(object2)->getClass()))->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::testSerialPersistentFields()
{
    try {
        auto object = new XMLObjectStreamUnit_TestSerialPersistentFields();
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(object));
        flip();
        auto object2 = java_cast< XMLObjectStreamUnit_TestSerialPersistentFields* >(npc(xois)->readObject());
        if(!(npc(npc(object2)->getNum1())->equals(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(int32_t(1)))) && (npc(object2)->getNum2() == nullptr)))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Object did not have correct nums "_j)->append(static_cast< ::java::lang::Object* >(npc(object2)->getNum1()))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(object2)->getNum2()))->toString());

        reset();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    } catch (::java::lang::ClassNotFoundException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"test produced exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::testing::XMLObjectStreamUnit::start()
{
    testInt(20930);
    testInt(0);
    testInt(-int32_t(29384));
    testBoolean(true);
    testBoolean(false);
    testByte(static_cast< int8_t >(int32_t(0)));
    testByte(static_cast< int8_t >(int32_t(10)));
    testByte(static_cast< int8_t >(int32_t(255)));
    testChar(u'A');
    testChar(u'B');
    testChar(u'z');
    testChar(u'1');
    testChar(u'.');
    testChar(u'&');
    testChar(u'<');
    testChar(u'>');
    testChar(u' ');
    testChar(u'"');
    testChar(u'\'');
    testDouble(static_cast< double >(int32_t(0)));
    testDouble(static_cast< double >(-1029.2));
    testDouble(static_cast< double >(int32_t(17)));
    testDouble(static_cast< double >(182.29938));
    testFloat(static_cast< float >(int32_t(0)));
    testFloat(static_cast< float >(29.239));
    testFloat(static_cast< float >(11.1029));
    testFloat(static_cast< float >(-1902.1));
    testLong(1920LL);
    testLong(0LL);
    testLong(192983783739892LL);
    testLong(-int64_t(1299LL));
    testLong(-int64_t(19282738339299LL));
    testShort(static_cast< int16_t >(int32_t(28)));
    testShort(static_cast< int16_t >(int32_t(1829)));
    testShort(static_cast< int16_t >(int32_t(0)));
    testMultiplePrimitives();
    test(new ::java::lang::Integer(int32_t(5)));
    test(new ::java::lang::Long(int64_t(2837LL)));
    test(new ::java::util::Vector());
    test(u"monkey"_j);
    test(u""_j);
    test(u"blah blah balh\n blah blah ablh"_j);
    test(u"blah blah balh\n\t\r\n\r\t\r blah blah ablh"_j);
    test(u"<monkey>"_j);
    test(u"<>&;'\""_j);
    testHashtable();
    testMultipleObjects();
    testUnserializableObject();
    testByteCustomSerializer();
    testCustomSerializer();
    testBrokenCustomSerializer();
    testSerialPersistentFields();
    testUnshared();
    testExternal();
    testSubExternal();
    testPutFields();
    testUnreadData();
    testWriteReplace();
    testReadResolve();
    testInheritedWriteReplace();
    testInheritedReadResolve();
    test(new ::int8_tArray(int32_t(7847)));
    test(new ::int8_tArrayArray(int32_t(4)));
}

void rice::p2p::util::testing::XMLObjectStreamUnit::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto test = new XMLObjectStreamUnit();
    npc(test)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit", 41);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit::getClass0()
{
    return class_();
}

