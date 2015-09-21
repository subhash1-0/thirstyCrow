// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/ObjectInputStream.hpp>

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

extern void unimplemented_(const char16_t* name);
java::io::ObjectInputStream::ObjectInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::ObjectInputStream::ObjectInputStream()
    : ObjectInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::io::ObjectInputStream::ObjectInputStream(InputStream* arg0)
    : ObjectInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int32_t java::io::ObjectInputStream::NULL_HANDLE;
java::util::HashMap*& java::io::ObjectInputStream::primClasses()
{
    clinit();
    return primClasses_;
}
java::util::HashMap* java::io::ObjectInputStream::primClasses_;
java::lang::Object*& java::io::ObjectInputStream::unsharedMarker()
{
    clinit();
    return unsharedMarker_;
}
java::lang::Object* java::io::ObjectInputStream::unsharedMarker_;

void ::java::io::ObjectInputStream::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectInputStream::ctor()");
}

void ::java::io::ObjectInputStream::ctor(InputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectInputStream::ctor(InputStream* arg0)");
}

/* private: bool java::io::ObjectInputStream::auditSubclass(::java::lang::Class* arg0) */
int32_t java::io::ObjectInputStream::available()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream::available()");
    return 0;
}

/* private: java::lang::Object* java::io::ObjectInputStream::checkResolve(::java::lang::Object* arg0) */
/* private: void java::io::ObjectInputStream::clear() */
/* private: java::lang::Object* java::io::ObjectInputStream::cloneArray_(::java::lang::Object* arg0) */
void java::io::ObjectInputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream::close()");
}

/* private: void java::io::ObjectInputStream::defaultReadFields(::java::lang::Object* arg0, ObjectStreamClass* arg1) */
void java::io::ObjectInputStream::defaultReadObject()
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream::defaultReadObject()");
}

bool java::io::ObjectInputStream::enableResolveObject(bool arg0)
{ /* stub */
    unimplemented_(u"bool java::io::ObjectInputStream::enableResolveObject(bool arg0)");
    return 0;
}

/* private: void java::io::ObjectInputStream::handleReset() */
/* private: bool java::io::ObjectInputStream::isCustomSubclass() */
/* private: java::lang::ClassLoader* java::io::ObjectInputStream::latestUserDefinedLoader() */
int32_t java::io::ObjectInputStream::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream::read()");
    return 0;
}

int32_t java::io::ObjectInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

/* private: java::lang::Object* java::io::ObjectInputStream::readArray_(bool arg0) */
bool java::io::ObjectInputStream::readBoolean()
{ /* stub */
    unimplemented_(u"bool java::io::ObjectInputStream::readBoolean()");
    return 0;
}

int8_t java::io::ObjectInputStream::readByte()
{ /* stub */
    unimplemented_(u"int8_t java::io::ObjectInputStream::readByte()");
    return 0;
}

char16_t java::io::ObjectInputStream::readChar()
{ /* stub */
    unimplemented_(u"char16_t java::io::ObjectInputStream::readChar()");
    return 0;
}

/* private: java::lang::Class* java::io::ObjectInputStream::readClass(bool arg0) */
/* private: java::io::ObjectStreamClass* java::io::ObjectInputStream::readClassDesc(bool arg0) */
java::io::ObjectStreamClass* java::io::ObjectInputStream::readClassDescriptor()
{ /* stub */
    unimplemented_(u"java::io::ObjectStreamClass* java::io::ObjectInputStream::readClassDescriptor()");
    return 0;
}

double java::io::ObjectInputStream::readDouble()
{ /* stub */
    unimplemented_(u"double java::io::ObjectInputStream::readDouble()");
    return 0;
}

/* private: java::lang::Enum* java::io::ObjectInputStream::readEnum(bool arg0) */
/* private: void java::io::ObjectInputStream::readExternalData(Externalizable* arg0, ObjectStreamClass* arg1) */
/* private: java::io::IOException* java::io::ObjectInputStream::readFatalException() */
java::io::ObjectInputStream_GetField* java::io::ObjectInputStream::readFields()
{ /* stub */
    unimplemented_(u"java::io::ObjectInputStream_GetField* java::io::ObjectInputStream::readFields()");
    return 0;
}

float java::io::ObjectInputStream::readFloat()
{ /* stub */
    unimplemented_(u"float java::io::ObjectInputStream::readFloat()");
    return 0;
}

void java::io::ObjectInputStream::readFully(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream::readFully(::int8_tArray* arg0)");
}

void java::io::ObjectInputStream::readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream::readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

/* private: java::lang::Object* java::io::ObjectInputStream::readHandle(bool arg0) */
int32_t java::io::ObjectInputStream::readInt()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream::readInt()");
    return 0;
}

java::lang::String* java::io::ObjectInputStream::readLine()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::ObjectInputStream::readLine()");
    return 0;
}

int64_t java::io::ObjectInputStream::readLong()
{ /* stub */
    unimplemented_(u"int64_t java::io::ObjectInputStream::readLong()");
    return 0;
}

/* private: java::io::ObjectStreamClass* java::io::ObjectInputStream::readNonProxyDesc(bool arg0) */
/* private: java::lang::Object* java::io::ObjectInputStream::readNull() */
java::lang::Object* java::io::ObjectInputStream::readObject()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::io::ObjectInputStream::readObject()");
    return 0;
}

/* private: java::lang::Object* java::io::ObjectInputStream::readObject0(bool arg0) */
java::lang::Object* java::io::ObjectInputStream::readObjectOverride()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::io::ObjectInputStream::readObjectOverride()");
    return 0;
}

/* private: java::lang::Object* java::io::ObjectInputStream::readOrdinaryObject(bool arg0) */
/* private: java::io::ObjectStreamClass* java::io::ObjectInputStream::readProxyDesc(bool arg0) */
/* private: void java::io::ObjectInputStream::readSerialData(::java::lang::Object* arg0, ObjectStreamClass* arg1) */
int16_t java::io::ObjectInputStream::readShort()
{ /* stub */
    unimplemented_(u"int16_t java::io::ObjectInputStream::readShort()");
    return 0;
}

void java::io::ObjectInputStream::readStreamHeader()
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream::readStreamHeader()");
}

/* private: java::lang::String* java::io::ObjectInputStream::readString(bool arg0) */
java::lang::String* java::io::ObjectInputStream::readTypeString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::ObjectInputStream::readTypeString()");
    return 0;
}

java::lang::String* java::io::ObjectInputStream::readUTF()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::ObjectInputStream::readUTF()");
    return 0;
}

java::lang::Object* java::io::ObjectInputStream::readUnshared()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::io::ObjectInputStream::readUnshared()");
    return 0;
}

int32_t java::io::ObjectInputStream::readUnsignedByte()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream::readUnsignedByte()");
    return 0;
}

int32_t java::io::ObjectInputStream::readUnsignedShort()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream::readUnsignedShort()");
    return 0;
}

void java::io::ObjectInputStream::registerValidation(ObjectInputValidation* arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream::registerValidation(ObjectInputValidation* arg0, int32_t arg1)");
}

java::lang::Class* java::io::ObjectInputStream::resolveClass(ObjectStreamClass* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::io::ObjectInputStream::resolveClass(ObjectStreamClass* arg0)");
    return 0;
}

java::lang::Object* java::io::ObjectInputStream::resolveObject(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::io::ObjectInputStream::resolveObject(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Class* java::io::ObjectInputStream::resolveProxyClass(::java::lang::StringArray* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::io::ObjectInputStream::resolveProxyClass(::java::lang::StringArray* arg0)");
    return 0;
}

int32_t java::io::ObjectInputStream::skipBytes(int32_t arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream::skipBytes(int32_t arg0)");
    return 0;
}

/* private: void java::io::ObjectInputStream::skipCustomData() */
/* private: void java::io::ObjectInputStream::verifySubclass() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::ObjectInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.ObjectInputStream", 25);
    return c;
}

int32_t java::io::ObjectInputStream::read(::int8_tArray* arg0)
{
    return InputStream::read(arg0);
}

int64_t java::io::ObjectInputStream::skip(int64_t arg0)
{
    return InputStream::skip(arg0);
}

java::lang::Class* java::io::ObjectInputStream::getClass0()
{
    return class_();
}

