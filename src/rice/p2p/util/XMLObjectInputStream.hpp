// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectInputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <sun/reflect/fwd-pastry-2.1.hpp>
#include <java/io/ObjectInputStream.hpp>

struct default_init_tag;

class rice::p2p::util::XMLObjectInputStream
    : public ::java::io::ObjectInputStream
{

public:
    typedef ::java::io::ObjectInputStream super;

private:
    static SoftHashMap* READ_RESOLVES_;
    static SoftHashMap* READ_OBJECTS_;
    static SoftHashMap* CONSTRUCTORS_;

public: /* protected */
    XMLReader* reader {  };
    ::java::util::Hashtable* references {  };
    ::java::util::Stack* currentObjects {  };
    ::java::util::Stack* currentClasses {  };
    ::sun::reflect::ReflectionFactory* reflFactory {  };
    XMLObjectInputStream_ValidationList* vlist {  };
    int32_t depth {  };
protected:
    void ctor(::java::io::InputStream* in) /* throws(IOException) */;

public: /* protected */
    void readStreamHeader() /* throws(IOException) */ override;

public:
    void close() /* throws(IOException) */ override;
    void reset() /* throws(IOException) */ override;
    int32_t read() /* throws(IOException) */ override;
    int32_t read(::int8_tArray* b, int32_t offset, int32_t length) /* throws(IOException) */ override;
    void readFully(::int8_tArray* b) /* throws(IOException) */ override;
    void readFully(::int8_tArray* b, int32_t offset, int32_t length) /* throws(IOException) */ override;
    int32_t readUnsignedByte() /* throws(IOException) */ override;
    int32_t readUnsignedShort() /* throws(IOException) */ override;
    int32_t readInt() /* throws(IOException) */ override;
    bool readBoolean() /* throws(IOException) */ override;
    int8_t readByte() /* throws(IOException) */ override;
    char16_t readChar() /* throws(IOException) */ override;
    double readDouble() /* throws(IOException) */ override;
    float readFloat() /* throws(IOException) */ override;
    int64_t readLong() /* throws(IOException) */ override;
    int16_t readShort() /* throws(IOException) */ override;
    ::java::lang::String* readUTF() /* throws(IOException) */ override;

public: /* protected */
    ::java::lang::Object* readObjectOverride() /* throws(IOException, ClassNotFoundException) */ override;

public:
    ::java::lang::Object* readUnshared() /* throws(IOException, ClassNotFoundException) */ override;
    void defaultReadObject() /* throws(IOException, ClassNotFoundException) */ override;
    ::java::io::ObjectInputStream_GetField* readFields() /* throws(IOException, ClassNotFoundException) */ override;
    void registerValidation(::java::io::ObjectInputValidation* obj, int32_t prio) /* throws(NotActiveException, InvalidObjectException) */ override;

private:
    static ::java::lang::reflect::Method* getReadResolve(::java::lang::Class* cl);
    static ::java::lang::reflect::Method* getReadObject(::java::lang::Class* cl);

public: /* protected */
    virtual ::java::lang::reflect::Constructor* getSerializableConstructor(::java::lang::Class* c) /* throws(IOException, NoSuchMethodException) */;
    virtual ::java::lang::Object* newInstance(::java::lang::Class* c) /* throws(IOException) */;
    virtual ::java::lang::Class* getClass(::java::lang::String* name) /* throws(ClassNotFoundException) */;
    virtual void putReference(::java::lang::String* reference, ::java::lang::Object* o);
    virtual ::java::lang::Object* getReference(::java::lang::String* reference);
    virtual ::java::lang::String* readPrimitive(::java::lang::String* type) /* throws(IOException) */;
    virtual int32_t readIntHelper() /* throws(IOException) */;
    virtual bool readBooleanHelper() /* throws(IOException) */;
    virtual int8_t readByteHelper() /* throws(IOException) */;
    virtual char16_t readCharHelper() /* throws(IOException) */;
    virtual double readDoubleHelper() /* throws(IOException) */;
    virtual float readFloatHelper() /* throws(IOException) */;
    virtual int64_t readLongHelper() /* throws(IOException) */;
    virtual int16_t readShortHelper() /* throws(IOException) */;
    virtual ::java::lang::Object* readObjectHelper() /* throws(IOException, ClassNotFoundException) */;
    virtual ::java::lang::Object* readUnsharedHelper(bool shared) /* throws(IOException, ClassNotFoundException) */;
    virtual ::java::lang::Object* readReference() /* throws(IOException, ClassNotFoundException) */;
    virtual ::java::lang::Object* readNull() /* throws(IOException, ClassNotFoundException) */;
    virtual ::java::lang::Object* readString(bool shared) /* throws(IOException, ClassNotFoundException) */;
    virtual ::java::lang::Object* readOrdinaryObject(bool shared) /* throws(IOException, ClassNotFoundException) */;
    virtual ::java::lang::Object* readClass(::java::lang::Object* o) /* throws(IOException, ClassNotFoundException) */;
    virtual void readUnreadOptionalData() /* throws(IOException, ClassNotFoundException) */;
    virtual XMLObjectInputStream_GetField* readGetFields() /* throws(IOException, ClassNotFoundException) */;
    virtual void readGetField(XMLObjectInputStream_GetField* g) /* throws(IOException, ClassNotFoundException) */;
    virtual void readPrimitiveGetField(XMLObjectInputStream_GetField* g) /* throws(IOException, ClassNotFoundException) */;
    virtual void readFields(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException, ClassNotFoundException) */;
    virtual void readField(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException, ClassNotFoundException) */;
    virtual void readPrimitiveField(::java::lang::Object* o, ::java::lang::reflect::Field* f) /* throws(IOException, IllegalAccessException) */;
    virtual ::java::lang::Object* readArray_(bool shared) /* throws(IOException, ClassNotFoundException) */;

    // Generated

public:
    XMLObjectInputStream(::java::io::InputStream* in);
protected:
    XMLObjectInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    virtual int32_t read(::int8_tArray* b);
    ::java::lang::Class* getClass();

public: /* protected */
    static SoftHashMap*& READ_RESOLVES();
    static SoftHashMap*& READ_OBJECTS();
    static SoftHashMap*& CONSTRUCTORS();

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectInputStream_GetField;
    friend class XMLObjectInputStream_ValidationList;
    friend class XMLObjectInputStream_ValidationList_Callback;
};
