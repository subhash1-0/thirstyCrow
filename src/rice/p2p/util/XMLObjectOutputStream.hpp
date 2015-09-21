// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectOutputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/ObjectOutputStream.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AccessibleObject, ::java::lang::ObjectArray, AnnotatedElementArray > AccessibleObjectArray;
typedef ::SubArray< ::java::lang::reflect::Member, ::java::lang::ObjectArray > MemberArray;
typedef ::SubArray< ::java::lang::reflect::Field, AccessibleObjectArray, MemberArray > FieldArray;
        } // reflect
    } // lang
} // java

struct default_init_tag;

class rice::p2p::util::XMLObjectOutputStream
    : public ::java::io::ObjectOutputStream
{

public:
    typedef ::java::io::ObjectOutputStream super;

private:
    static SoftHashMap* WRITE_REPLACES_;
    static SoftHashMap* WRITE_OBJECTS_;
    static SoftHashMap* PERSISTENT_FIELDS_;

public: /* protected */
    XMLWriter* writer {  };
    ::java::util::Hashtable* references {  };
    int32_t next {  };
    ::java::util::Stack* currentObjects {  };
    ::java::util::Stack* currentClasses {  };
    ::java::util::Stack* currentPutFields {  };

private:
    ::java::lang::String* debugstr {  };
protected:
    void ctor(::java::io::OutputStream* out) /* throws(IOException) */;

public: /* protected */
    void writeStreamHeader() /* throws(IOException) */ override;

public:
    void flush() /* throws(IOException) */ override;
    void close() /* throws(IOException) */ override;
    void reset() /* throws(IOException) */ override;
    virtual void write(int8_t b) /* throws(IOException) */;
    void write(::int8_tArray* b) /* throws(IOException) */ override;
    void write(::int8_tArray* b, int32_t offset, int32_t length) /* throws(IOException) */ override;
    void writeInt(int32_t i) /* throws(IOException) */ override;
    void writeBoolean(bool b) /* throws(IOException) */ override;
    void writeByte(int32_t i) /* throws(IOException) */ override;
    virtual void writeByte(int8_t b) /* throws(IOException) */;
    void writeChar(int32_t i) /* throws(IOException) */ override;
    virtual void writeChar(char16_t c) /* throws(IOException) */;
    void writeDouble(double d) /* throws(IOException) */ override;
    void writeFloat(float f) /* throws(IOException) */ override;
    void writeLong(int64_t l) /* throws(IOException) */ override;
    void writeShort(int32_t i) /* throws(IOException) */ override;
    virtual void writeShort(int16_t s) /* throws(IOException) */;
    void writeUTF(::java::lang::String* s) /* throws(IOException) */ override;
    void writeChars(::java::lang::String* s) /* throws(IOException) */ override;
    void writeBytes(::java::lang::String* s) /* throws(IOException) */ override;
    void writeObjectOverride(::java::lang::Object* o) /* throws(IOException) */ override;
    void writeUnshared(::java::lang::Object* o) /* throws(IOException) */ override;
    void defaultWriteObject() /* throws(IOException) */ override;
    ::java::io::ObjectOutputStream_PutField* putFields() /* throws(IOException) */ override;
    void writeFields() /* throws(IOException) */ override;

private:
    ::java::lang::reflect::Method* getWriteReplace(::java::lang::Class* cl);
    static ::java::lang::reflect::Method* getWriteObject(::java::lang::Class* cl);

public: /* protected */
    virtual ::java::lang::reflect::FieldArray* getPersistentFields(::java::lang::Class* cl);
    virtual ::java::lang::reflect::FieldArray* getSerialPersistentFields(::java::lang::Class* c);
    virtual ::java::lang::Class* getComponentType(::java::lang::Class* array);
    virtual int32_t getDimension(::java::lang::Class* array);
    virtual ::java::lang::ClassArray* getSuperClasses(::java::lang::Class* c);
    virtual int32_t hash(::java::lang::Object* o);
    virtual void putReference(::java::lang::Object* o, ::java::lang::String* reference);
    virtual ::java::lang::String* getReference(::java::lang::Object* o);
    virtual ::java::lang::String* assignReference();
    virtual void writeReset() /* throws(IOException) */;
    virtual void writeObject(::java::lang::Object* o, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writeObjectUnshared(::java::lang::Object* o, ::java::lang::String* field, bool shared) /* throws(IOException) */;
    virtual void writeNull(::java::lang::String* field) /* throws(IOException) */;
    virtual void writeString(::java::lang::String* s, ::java::lang::String* field, bool shared) /* throws(IOException) */;
    virtual void writeArray_(::java::lang::Object* o, ::java::lang::String* field, bool shared) /* throws(IOException) */;
    virtual void writeReference(::java::lang::Object* o, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writeOrdinaryObject(::java::lang::Object* o, ::java::lang::String* field, bool shared) /* throws(IOException) */;
    virtual void writeClass(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException) */;
    virtual void writeFields(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException) */;
    virtual void writePutFields(XMLObjectOutputStream_PutField* p) /* throws(IOException) */;
    virtual void writePrimitiveField(::java::lang::Object* o, ::java::lang::reflect::Field* f) /* throws(IOException) */;
    virtual void writePrimitive(int32_t i, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writePrimitive(bool b, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writePrimitive(int8_t b, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writePrimitive(char16_t c, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writePrimitive(double d, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writePrimitive(float f, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writePrimitive(int64_t l, ::java::lang::String* field) /* throws(IOException) */;
    virtual void writePrimitive(int16_t s, ::java::lang::String* field) /* throws(IOException) */;

    // Generated

public:
    XMLObjectOutputStream(::java::io::OutputStream* out);
protected:
    XMLObjectOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    void write(int32_t arg0);
    void writeObject(::java::lang::Object* arg0);

public: /* protected */
    static SoftHashMap*& WRITE_REPLACES();
    static SoftHashMap*& WRITE_OBJECTS();
    static SoftHashMap*& PERSISTENT_FIELDS();

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectOutputStream_PutField;
    friend class XMLObjectOutputStream_Reference;
};
