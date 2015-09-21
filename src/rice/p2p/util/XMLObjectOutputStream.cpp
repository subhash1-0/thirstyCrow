// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectOutputStream.java
#include <rice/p2p/util/XMLObjectOutputStream.hpp>

#include <java/io/Externalizable.hpp>
#include <java/io/IOException.hpp>
#include <java/io/NotActiveException.hpp>
#include <java/io/NotSerializableException.hpp>
#include <java/io/ObjectOutputStream_PutField.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/ObjectStreamField.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Character.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/IllegalAccessException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NoClassDefFoundError.hpp>
#include <java/lang/NoSuchFieldException.hpp>
#include <java/lang/NoSuchMethodException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/lang/reflect/AccessibleObject.hpp>
#include <java/lang/reflect/AnnotatedElement.hpp>
#include <java/lang/reflect/Array_.hpp>
#include <java/lang/reflect/Field.hpp>
#include <java/lang/reflect/GenericDeclaration.hpp>
#include <java/lang/reflect/InvocationTargetException.hpp>
#include <java/lang/reflect/Member.hpp>
#include <java/lang/reflect/Method.hpp>
#include <java/lang/reflect/Modifier.hpp>
#include <java/lang/reflect/Type.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Stack.hpp>
#include <java/util/Vector.hpp>
#include <rice/p2p/util/SoftHashMap.hpp>
#include <rice/p2p/util/XMLObjectOutputStream_PutField.hpp>
#include <rice/p2p/util/XMLObjectOutputStream_Reference.hpp>
#include <rice/p2p/util/XMLWriter.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AccessibleObject, ::java::lang::ObjectArray, AnnotatedElementArray > AccessibleObjectArray;
typedef ::SubArray< ::java::lang::reflect::Member, ::java::lang::ObjectArray > MemberArray;
typedef ::SubArray< ::java::lang::reflect::Field, AccessibleObjectArray, MemberArray > FieldArray;
        } // reflect
    } // lang
} // java

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::p2p::util::XMLObjectOutputStream::XMLObjectOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::XMLObjectOutputStream::XMLObjectOutputStream(::java::io::OutputStream* out)  /* throws(IOException) */
    : XMLObjectOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(out);
}

void rice::p2p::util::XMLObjectOutputStream::init()
{
    next = int32_t(0);
}

rice::p2p::util::SoftHashMap*& rice::p2p::util::XMLObjectOutputStream::WRITE_REPLACES()
{
    clinit();
    return WRITE_REPLACES_;
}
rice::p2p::util::SoftHashMap* rice::p2p::util::XMLObjectOutputStream::WRITE_REPLACES_;

rice::p2p::util::SoftHashMap*& rice::p2p::util::XMLObjectOutputStream::WRITE_OBJECTS()
{
    clinit();
    return WRITE_OBJECTS_;
}
rice::p2p::util::SoftHashMap* rice::p2p::util::XMLObjectOutputStream::WRITE_OBJECTS_;

rice::p2p::util::SoftHashMap*& rice::p2p::util::XMLObjectOutputStream::PERSISTENT_FIELDS()
{
    clinit();
    return PERSISTENT_FIELDS_;
}
rice::p2p::util::SoftHashMap* rice::p2p::util::XMLObjectOutputStream::PERSISTENT_FIELDS_;

void rice::p2p::util::XMLObjectOutputStream::ctor(::java::io::OutputStream* out) /* throws(IOException) */
{
    super::ctor();
    init();
    try {
        this->writer = new XMLWriter(out);
        auto hash = int32_t(0);
        if(writer != nullptr)
            hash = npc(writer)->hashCode();

        this->debugstr = ::java::lang::StringBuilder().append(u"writer after new, in try: "_j)->append(static_cast< ::java::lang::Object* >(writer))
            ->append(u" "_j)
            ->append(hash)
            ->append(u"\n"_j)->toString();
    } catch (::java::lang::NoClassDefFoundError* ncdfe) {
        npc(::java::lang::System::err())->println(u"ERROR: Make sure to add xmlpull.jar to the classpath"_j);
        throw ncdfe;
    }
    auto hash = int32_t(0);
    if(writer != nullptr)
        hash = npc(writer)->hashCode();

    this->debugstr = ::java::lang::StringBuilder(this->debugstr).append(::java::lang::StringBuilder().append(u"writer after try: "_j)->append(static_cast< ::java::lang::Object* >(writer))
        ->append(u" "_j)
        ->append(hash)
        ->append(u"\n"_j)->toString())->toString();
    this->references = new ::java::util::Hashtable();
    this->currentObjects = new ::java::util::Stack();
    this->currentClasses = new ::java::util::Stack();
    this->currentPutFields = new ::java::util::Stack();
    hash = 0;
    if(writer != nullptr)
        hash = npc(writer)->hashCode();

    this->debugstr = ::java::lang::StringBuilder(this->debugstr).append(::java::lang::StringBuilder().append(u"writer before writeStreamHeader: "_j)->append(static_cast< ::java::lang::Object* >(writer))
        ->append(u" "_j)
        ->append(hash)
        ->append(u"\n"_j)->toString())->toString();
    writeStreamHeader();
}

void rice::p2p::util::XMLObjectOutputStream::writeStreamHeader() /* throws(IOException) */
{
    if(writer == nullptr) {
        npc(::java::lang::System::out())->println(u"FLUGLE writer is null in writeStreamHeader()..."_j);
        npc(::java::lang::System::out())->println(debugstr);
    }
    try {
        npc(writer)->writeHeader();
        npc(writer)->start(u"jsx"_j);
        npc(writer)->attribute(u"major"_j, int32_t(1));
        npc(writer)->attribute(u"minor"_j, int32_t(1));
        npc(writer)->attribute(u"format"_j, u"JSX.DataReader"_j);
    } catch (::java::lang::NullPointerException* npe) {
        npc(::java::lang::System::out())->println(u"FLUGLE writer NPE'd in writeStreamHeader()..."_j);
        auto hash = int32_t(0);
        if(writer != nullptr)
            hash = npc(writer)->hashCode();

        this->debugstr = ::java::lang::StringBuilder(this->debugstr).append(::java::lang::StringBuilder().append(u"writer in NPE handler: "_j)->append(static_cast< ::java::lang::Object* >(writer))
            ->append(u" "_j)
            ->append(hash)
            ->append(u"\n"_j)->toString())->toString();
        npc(::java::lang::System::out())->println(debugstr);
        throw npe;
    }
}

void rice::p2p::util::XMLObjectOutputStream::flush() /* throws(IOException) */
{
    npc(writer)->flush();
}

void rice::p2p::util::XMLObjectOutputStream::close() /* throws(IOException) */
{
    npc(writer)->end(u"jsx"_j);
    npc(writer)->close();
}

void rice::p2p::util::XMLObjectOutputStream::reset() /* throws(IOException) */
{
    if(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()) == nullptr) {
        references = new ::java::util::Hashtable();
        writeReset();
    } else {
        throw new ::java::io::IOException(u"Reset called during active write!"_j);
    }
}

void rice::p2p::util::XMLObjectOutputStream::write(int8_t b) /* throws(IOException) */
{
    writeByte(b);
}

void rice::p2p::util::XMLObjectOutputStream::write(::int8_tArray* b) /* throws(IOException) */
{
    write(b, int32_t(0), npc(b)->length);
}

void rice::p2p::util::XMLObjectOutputStream::write(::int8_tArray* b, int32_t offset, int32_t length) /* throws(IOException) */
{
    npc(writer)->start(u"base64"_j);
    npc(writer)->attribute(u"length"_j, length);
    npc(writer)->writeBase64(b, offset, length);
    npc(writer)->end(u"base64"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeInt(int32_t i) /* throws(IOException) */
{
    writePrimitive(i, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeBoolean(bool b) /* throws(IOException) */
{
    writePrimitive(b, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeByte(int32_t i) /* throws(IOException) */
{
    writeByte(static_cast< int8_t >(i));
}

void rice::p2p::util::XMLObjectOutputStream::writeByte(int8_t b) /* throws(IOException) */
{
    writePrimitive(b, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeChar(int32_t i) /* throws(IOException) */
{
    writeChar(static_cast< char16_t >(i));
}

void rice::p2p::util::XMLObjectOutputStream::writeChar(char16_t c) /* throws(IOException) */
{
    writePrimitive(c, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeDouble(double d) /* throws(IOException) */
{
    writePrimitive(d, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeFloat(float f) /* throws(IOException) */
{
    writePrimitive(f, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeLong(int64_t l) /* throws(IOException) */
{
    writePrimitive(l, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeShort(int32_t i) /* throws(IOException) */
{
    writeShort(static_cast< int16_t >(i));
}

void rice::p2p::util::XMLObjectOutputStream::writeShort(int16_t s) /* throws(IOException) */
{
    writePrimitive(s, static_cast< ::java::lang::String* >(nullptr));
}

void rice::p2p::util::XMLObjectOutputStream::writeUTF(::java::lang::String* s) /* throws(IOException) */
{
    writeObject(static_cast< ::java::lang::Object* >(s));
}

void rice::p2p::util::XMLObjectOutputStream::writeChars(::java::lang::String* s) /* throws(IOException) */
{
    auto chars = npc(s)->toCharArray_();
    for (auto i = int32_t(0); i < npc(chars)->length; i++) 
                writeChar((*chars)[i]);

}

void rice::p2p::util::XMLObjectOutputStream::writeBytes(::java::lang::String* s) /* throws(IOException) */
{
    auto bytes = npc(s)->getBytes();
    for (auto i = int32_t(0); i < npc(bytes)->length; i++) 
                writeByte((*bytes)[i]);

}

void rice::p2p::util::XMLObjectOutputStream::writeObjectOverride(::java::lang::Object* o) /* throws(IOException) */
{
    writeObject(o, nullptr);
}

void rice::p2p::util::XMLObjectOutputStream::writeUnshared(::java::lang::Object* o) /* throws(IOException) */
{
    writeObjectUnshared(o, nullptr, false);
}

void rice::p2p::util::XMLObjectOutputStream::defaultWriteObject() /* throws(IOException) */
{
    if(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()) != nullptr)
        writeFields(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()), java_cast< ::java::lang::Class* >(java_cast< ::java::lang::Object* >(npc(currentClasses)->peek())));
    else
        throw new ::java::io::NotActiveException();
}

java::io::ObjectOutputStream_PutField* rice::p2p::util::XMLObjectOutputStream::putFields() /* throws(IOException) */
{
    if(java_cast< ::java::lang::Object* >(npc(currentPutFields)->peek()) != nullptr)
        return java_cast< XMLObjectOutputStream_PutField* >(java_cast< ::java::lang::Object* >(npc(currentPutFields)->peek()));
    else
        throw new ::java::io::NotActiveException();
}

void rice::p2p::util::XMLObjectOutputStream::writeFields() /* throws(IOException) */
{
    if(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()) != nullptr)
        writePutFields(java_cast< XMLObjectOutputStream_PutField* >(putFields()));
    else
        throw new ::java::io::NotActiveException();
}

java::lang::reflect::Method* rice::p2p::util::XMLObjectOutputStream::getWriteReplace(::java::lang::Class* cl)
{
    if(npc(WRITE_REPLACES_)->containsKey(static_cast< ::java::lang::Object* >(cl)))
        return java_cast< ::java::lang::reflect::Method* >(npc(WRITE_REPLACES_)->get(static_cast< ::java::lang::Object* >(cl)));

    ::java::lang::reflect::Method* meth = nullptr;
    auto defCl = cl;
    while (defCl != nullptr) {
        try {
            meth = npc(defCl)->getDeclaredMethod(u"writeReplace"_j, new ::java::lang::ClassArray(int32_t(0)));
            break;
        } catch (::java::lang::NoSuchMethodException* ex) {
            defCl = npc(defCl)->getSuperclass();
        }
    }
    if(meth == nullptr) {
        npc(WRITE_REPLACES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(meth));
        return nullptr;
    }
    npc(meth)->setAccessible(true);
    auto mods = npc(meth)->getModifiers();
    if((mods & (::java::lang::reflect::Modifier::STATIC | ::java::lang::reflect::Modifier::ABSTRACT)) != 0) {
    } else if((mods & (::java::lang::reflect::Modifier::PUBLIC | ::java::lang::reflect::Modifier::PROTECTED)) != 0) {
        npc(WRITE_REPLACES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(meth));
        return meth;
    } else if((mods & ::java::lang::reflect::Modifier::PRIVATE) != 0) {
        if(cl == defCl) {
            npc(WRITE_REPLACES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(meth));
            return meth;
        }
    } else {
        npc(WRITE_REPLACES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(meth));
        return meth;
    }
    npc(WRITE_REPLACES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(nullptr));
    return nullptr;
}

java::lang::reflect::Method* rice::p2p::util::XMLObjectOutputStream::getWriteObject(::java::lang::Class* cl)
{
    clinit();
    {
        synchronized synchronized_0(WRITE_OBJECTS_);
        {
            if(npc(WRITE_OBJECTS_)->containsKey(static_cast< ::java::lang::Object* >(cl)))
                return java_cast< ::java::lang::reflect::Method* >(npc(WRITE_OBJECTS_)->get(static_cast< ::java::lang::Object* >(cl)));

            try {
                auto method = npc(cl)->getDeclaredMethod(u"writeObject"_j, new ::java::lang::ClassArray({static_cast< ::java::lang::Class* >(::java::io::ObjectOutputStream::class_())}));
                npc(method)->setAccessible(true);
                npc(WRITE_OBJECTS_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(method));
                return method;
            } catch (::java::lang::NoSuchMethodException* e) {
                npc(WRITE_OBJECTS_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(nullptr));
                return nullptr;
            }
        }
    }
}

java::lang::reflect::FieldArray* rice::p2p::util::XMLObjectOutputStream::getPersistentFields(::java::lang::Class* cl)
{
    {
        synchronized synchronized_1(PERSISTENT_FIELDS_);
        {
            if(npc(PERSISTENT_FIELDS_)->containsKey(static_cast< ::java::lang::Object* >(cl)))
                return java_cast< ::java::lang::reflect::FieldArray* >(npc(PERSISTENT_FIELDS_)->get(static_cast< ::java::lang::Object* >(cl)));

            auto fields = getSerialPersistentFields(cl);
            if(fields == nullptr) {
                fields = npc(cl)->getDeclaredFields();
            }
            npc(PERSISTENT_FIELDS_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(fields));
            return fields;
        }
    }
}

java::lang::reflect::FieldArray* rice::p2p::util::XMLObjectOutputStream::getSerialPersistentFields(::java::lang::Class* c)
{
    try {
        auto f = npc(c)->getDeclaredField(u"serialPersistentFields"_j);
        auto mask = ::java::lang::reflect::Modifier::PRIVATE | ::java::lang::reflect::Modifier::STATIC | ::java::lang::reflect::Modifier::FINAL;
        if((npc(f)->getModifiers() & mask) != mask) {
            return nullptr;
        }
        npc(f)->setAccessible(true);
        auto serialPersistentFields = java_cast< ::java::io::ObjectStreamFieldArray* >(npc(f)->get(nullptr));
        auto fields = new ::java::lang::reflect::FieldArray(npc(serialPersistentFields)->length);
        for (auto i = int32_t(0); i < npc(serialPersistentFields)->length; i++) {
            auto spf = (*serialPersistentFields)[i];
            auto thisf = npc(c)->getDeclaredField(npc(spf)->getName());
            if(!((static_cast< ::java::lang::Object* >(npc(thisf)->getType()) == static_cast< ::java::lang::Object* >(npc(spf)->getType())) && ((npc(thisf)->getModifiers() & ::java::lang::reflect::Modifier::STATIC) == 0))) {
                return nullptr;
            }
            fields->set(i, thisf);
        }
        return fields;
    } catch (::java::lang::NoSuchFieldException* ex) {
        return nullptr;
    } catch (::java::lang::IllegalAccessException* e) {
        return nullptr;
    }
}

java::lang::Class* rice::p2p::util::XMLObjectOutputStream::getComponentType(::java::lang::Class* array)
{
    if(npc(array)->isArray_())
        return getComponentType(npc(array)->getComponentType());

    return array;
}

int32_t rice::p2p::util::XMLObjectOutputStream::getDimension(::java::lang::Class* array)
{
    if(npc(array)->isArray_())
        return int32_t(1) + getDimension(npc(array)->getComponentType());

    return 0;
}

java::lang::ClassArray* rice::p2p::util::XMLObjectOutputStream::getSuperClasses(::java::lang::Class* c)
{
    auto v = new ::java::util::Vector();
    while (true) {
        if(npc(npc(c)->getSuperclass())->equals((new ::java::lang::Object())->getClass()))
            break;

        c = npc(c)->getSuperclass();
        npc(v)->addElement(c);
    }
    return java_cast< ::java::lang::ClassArray* >(java_cast< ::java::lang::ObjectArray* >(npc(v)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::lang::ClassArray(int32_t(0))))));
}

int32_t rice::p2p::util::XMLObjectOutputStream::hash(::java::lang::Object* o)
{
    return ::java::lang::System::identityHashCode(o) & int32_t(2147483647);
}

void rice::p2p::util::XMLObjectOutputStream::putReference(::java::lang::Object* o, ::java::lang::String* reference)
{
    auto ref = new XMLObjectOutputStream_Reference(this, o);
    if(java_cast< ::java::lang::Object* >(npc(references)->get(static_cast< ::java::lang::Object* >(ref))) == nullptr) {
        npc(references)->put(static_cast< ::java::lang::Object* >(ref), static_cast< ::java::lang::Object* >(reference));
    } else {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(u"SERIOUS ERROR: Attempt to re-store reference: "_j)->append(u"EXISTING: "_j)->toString())->append(static_cast< ::java::lang::Object* >(npc((java_cast< XMLObjectOutputStream_Reference* >(java_cast< ::java::lang::Object* >(npc(references)->get(static_cast< ::java::lang::Object* >(ref))))))->object))
            ->append(u" "_j)
            ->append(npc(java_cast< ::java::lang::Object* >(npc(references)->get(static_cast< ::java::lang::Object* >(ref))))->hashCode())
            ->append(u"NEW: "_j)
            ->append(static_cast< ::java::lang::Object* >(o))
            ->append(u" "_j)
            ->append(npc(o)->hashCode())->toString());
    }
}

java::lang::String* rice::p2p::util::XMLObjectOutputStream::getReference(::java::lang::Object* o)
{
    return java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(references)->get(static_cast< ::java::lang::Object* >(new XMLObjectOutputStream_Reference(this, o)))));
}

java::lang::String* rice::p2p::util::XMLObjectOutputStream::assignReference()
{
    return ::java::lang::StringBuilder().append(u"i"_j)->append((next++))->toString();
}

void rice::p2p::util::XMLObjectOutputStream::writeReset() /* throws(IOException) */
{
    npc(writer)->start(u"reset"_j);
    npc(writer)->end(u"reset"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeObject(::java::lang::Object* o, ::java::lang::String* field) /* throws(IOException) */
{
    if(o == nullptr) {
        writeNull(field);
    } else if(getReference(o) != nullptr) {
        writeReference(o, field);
    } else {
        writeObjectUnshared(o, field, true);
    }
}

void rice::p2p::util::XMLObjectOutputStream::writeObjectUnshared(::java::lang::Object* o, ::java::lang::String* field, bool shared) /* throws(IOException) */
{
    auto replace = getWriteReplace(npc(o)->getClass());
    if(replace != nullptr) {
        try {
            o = npc(replace)->invoke(o, new ::java::lang::ObjectArray(int32_t(0)));
            if(o == nullptr) {
                writeNull(field);
                return;
            } else if(getReference(o) != nullptr) {
                writeReference(o, field);
                return;
            }
        } catch (::java::lang::IllegalAccessException* e) {
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"IllegalAccessException thrown! "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        } catch (::java::lang::reflect::InvocationTargetException* e) {
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"InvocationTargetException thrown! "_j)->append(static_cast< ::java::lang::Object* >(npc(e)->getTargetException()))->toString());
        }
    }
    if(shared)
        putReference(o, assignReference());

    if(dynamic_cast< ::java::lang::String* >(o) != nullptr) {
        writeString(java_cast< ::java::lang::String* >(o), field, shared);
    } else if(npc(npc(o)->getClass())->isArray_()) {
        writeArray_(o, field, shared);
    } else {
        writeOrdinaryObject(o, field, shared);
    }
}

void rice::p2p::util::XMLObjectOutputStream::writeNull(::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"null"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->end(u"null"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeString(::java::lang::String* s, ::java::lang::String* field, bool shared) /* throws(IOException) */
{
    npc(writer)->start(u"string"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    if(shared && getReference(s) != nullptr)
        npc(writer)->attribute(u"id"_j, getReference(s));

    npc(writer)->attribute(u"value"_j, s);
    npc(writer)->end(u"string"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeArray_(::java::lang::Object* o, ::java::lang::String* field, bool shared) /* throws(IOException) */
{
    npc(writer)->start(u"array"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    if(shared && getReference(o) != nullptr)
        npc(writer)->attribute(u"id"_j, getReference(o));

    npc(writer)->attribute(u"base"_j, npc(npc(npc(o)->getClass())->getComponentType())->getName());
    npc(writer)->attribute(u"dim"_j, getDimension(npc(o)->getClass()));
    npc(writer)->attribute(u"length"_j, ::java::lang::reflect::Array_::getLength(o));
    if(npc(npc(npc(o)->getClass())->getComponentType())->isPrimitive()) {
        auto c = npc(npc(o)->getClass())->getComponentType();
        for (auto i = int32_t(0); i < ::java::lang::reflect::Array_::getLength(o); i++) {
            if(npc(c)->equals(::java::lang::Integer::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getInt(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else if(npc(c)->equals(::java::lang::Boolean::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getBoolean(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else if(npc(c)->equals(::java::lang::Byte::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getByte(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else if(npc(c)->equals(::java::lang::Character::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getChar(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else if(npc(c)->equals(::java::lang::Double::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getDouble(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else if(npc(c)->equals(::java::lang::Float::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getFloat(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else if(npc(c)->equals(::java::lang::Long::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getLong(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else if(static_cast< ::java::lang::Object* >(c) == static_cast< ::java::lang::Object* >(::java::lang::Short::TYPE())) {
                writePrimitive(::java::lang::reflect::Array_::getShort(o, i), static_cast< ::java::lang::String* >(nullptr));
            } else {
                throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Class "_j)->append(static_cast< ::java::lang::Object* >(c))
                    ->append(u" is not primitive!"_j)->toString());
            }
        }
    } else {
        for (auto i = int32_t(0); i < ::java::lang::reflect::Array_::getLength(o); i++) {
            if(dynamic_cast< ::java::io::Serializable* >(::java::lang::reflect::Array_::get(o, i)) != nullptr)
                writeObject(::java::lang::reflect::Array_::get(o, i), nullptr);
            else
                writeNull(nullptr);
        }
    }
    npc(writer)->end(u"array"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeReference(::java::lang::Object* o, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"reference"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"idref"_j, getReference(o));
    npc(writer)->end(u"reference"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeOrdinaryObject(::java::lang::Object* o, ::java::lang::String* field, bool shared) /* throws(IOException) */
{
    if(!npc(::java::io::Serializable::class_())->isAssignableFrom(npc(o)->getClass())) {
        if(field == nullptr)
            throw new ::java::io::NotSerializableException(::java::lang::StringBuilder().append(npc(npc(o)->getClass())->getName())->append(u" "_j)
                ->append(field)
                ->append(u" "_j)
                ->append(shared)->toString());
        else
            return;
    }
    npc(writer)->start(u"object"_j);
    if(shared && getReference(o) != nullptr)
        npc(writer)->attribute(u"id"_j, getReference(o));

    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"class"_j, npc(npc(o)->getClass())->getName());
    auto classes = new ::java::lang::StringBuffer();
    auto supers = getSuperClasses(npc(o)->getClass());
    for (auto i = int32_t(0); i < npc(supers)->length; i++) {
        npc(classes)->append(npc((*supers)[i])->getName());
        npc(classes)->append(u","_j);
    }
    npc(writer)->attribute(u"superclasses"_j, npc(classes)->toString());
    if(dynamic_cast< ::java::io::Externalizable* >(o) != nullptr) {
        npc((java_cast< ::java::io::Externalizable* >(o)))->writeExternal(this);
    } else {
        for (auto i = npc(supers)->length - int32_t(1); i >= 0; i--) {
            if(npc(::java::io::Serializable::class_())->isAssignableFrom((*supers)[i]))
                writeClass(o, (*supers)[i]);

        }
        writeClass(o, static_cast< ::java::lang::Class* >(npc(o)->getClass()));
    }
    npc(writer)->end(u"object"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeClass(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException) */
{
    npc(writer)->start(u"declaredClass"_j);
    npc(writer)->attribute(u"class"_j, npc(c)->getName());
    auto method = getWriteObject(c);
    if(method != nullptr) {
        try {
            npc(currentObjects)->push(o);
            npc(currentClasses)->push(c);
            npc(currentPutFields)->push(new XMLObjectOutputStream_PutField(this));
            npc(method)->invoke(o, new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(this)}));
            npc(currentObjects)->pop();
            npc(currentClasses)->pop();
            npc(currentPutFields)->pop();
        } catch (::java::lang::IllegalAccessException* e) {
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"IllegalAccessException thrown! "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        } catch (::java::lang::reflect::InvocationTargetException* e) {
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"InvocationTargetException thrown! "_j)->append(static_cast< ::java::lang::Object* >(npc(e)->getTargetException()))->toString());
        }
    } else {
        writeFields(o, c);
    }
    npc(writer)->end(u"declaredClass"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writeFields(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException) */
{
    npc(writer)->start(u"default"_j);
    auto fields = getPersistentFields(c);
    for (auto i = int32_t(0); i < npc(fields)->length; i++) {
        npc((*fields)[i])->setAccessible(true);
        if(!(::java::lang::reflect::Modifier::isStatic(npc((*fields)[i])->getModifiers()) || ::java::lang::reflect::Modifier::isTransient(npc((*fields)[i])->getModifiers()))) {
            if(npc(npc((*fields)[i])->getType())->isPrimitive()) {
                writePrimitiveField(o, (*fields)[i]);
            } else {
                try {
                    writeObject(npc((*fields)[i])->get(o), npc((*fields)[i])->getName());
                } catch (::java::lang::IllegalAccessException* e) {
                    throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"IllegalAccessException thrown "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
                }
            }
        }
    }
    npc(writer)->end(u"default"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePutFields(XMLObjectOutputStream_PutField* p) /* throws(IOException) */
{
    npc(writer)->start(u"default"_j);
    auto primitives = npc(p)->getPrimitives();
    for (auto i = int32_t(0); i < npc(primitives)->length; i++) {
        auto name = (*primitives)[i];
        auto primitive = npc(p)->getPrimitive(name);
        if(npc(npc(primitive)->getClass())->equals(::java::lang::Integer::class_())) {
            writePrimitive(npc(p)->getInt(name), name);
        } else if(npc(npc(primitive)->getClass())->equals(::java::lang::Boolean::class_())) {
            writePrimitive(npc(p)->getBoolean(name), name);
        } else if(npc(npc(primitive)->getClass())->equals(::java::lang::Byte::class_())) {
            writePrimitive(npc(p)->getByte(name), name);
        } else if(npc(npc(primitive)->getClass())->equals(::java::lang::Character::class_())) {
            writePrimitive(npc(p)->getChar(name), name);
        } else if(npc(npc(primitive)->getClass())->equals(::java::lang::Double::class_())) {
            writePrimitive(npc(p)->getDouble(name), name);
        } else if(npc(npc(primitive)->getClass())->equals(::java::lang::Float::class_())) {
            writePrimitive(npc(p)->getFloat(name), name);
        } else if(npc(npc(primitive)->getClass())->equals(::java::lang::Long::class_())) {
            writePrimitive(npc(p)->getLong(name), name);
        } else if(npc(npc(primitive)->getClass())->equals(::java::lang::Short::class_())) {
            writePrimitive(npc(p)->getShort(name), name);
        } else {
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Field "_j)->append(name)
                ->append(u" is not primitive!"_j)->toString());
        }
    }
    auto objects = npc(p)->getObjects();
    for (auto i = int32_t(0); i < npc(objects)->length; i++) {
        writeObject(npc(p)->getObject((*objects)[i]), (*objects)[i]);
    }
    npc(writer)->end(u"default"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitiveField(::java::lang::Object* o, ::java::lang::reflect::Field* f) /* throws(IOException) */
{
    try {
        if(npc(npc(f)->getType())->equals(::java::lang::Integer::TYPE())) {
            writePrimitive(npc(f)->getInt(o), npc(f)->getName());
        } else if(npc(npc(f)->getType())->equals(::java::lang::Boolean::TYPE())) {
            writePrimitive(npc(f)->getBoolean(o), npc(f)->getName());
        } else if(npc(npc(f)->getType())->equals(::java::lang::Byte::TYPE())) {
            writePrimitive(npc(f)->getByte(o), npc(f)->getName());
        } else if(npc(npc(f)->getType())->equals(::java::lang::Character::TYPE())) {
            writePrimitive(npc(f)->getChar(o), npc(f)->getName());
        } else if(npc(npc(f)->getType())->equals(::java::lang::Double::TYPE())) {
            writePrimitive(npc(f)->getDouble(o), npc(f)->getName());
        } else if(npc(npc(f)->getType())->equals(::java::lang::Float::TYPE())) {
            writePrimitive(npc(f)->getFloat(o), npc(f)->getName());
        } else if(npc(npc(f)->getType())->equals(::java::lang::Long::TYPE())) {
            writePrimitive(npc(f)->getLong(o), npc(f)->getName());
        } else if(npc(npc(f)->getType())->equals(::java::lang::Short::TYPE())) {
            writePrimitive(npc(f)->getShort(o), npc(f)->getName());
        } else {
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Field "_j)->append(static_cast< ::java::lang::Object* >(f))
                ->append(u" is not primitive!"_j)->toString());
        }
    } catch (::java::lang::IllegalAccessException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"IllegalAccessException thrown "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(int32_t i, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"int"_j);
    npc(writer)->attribute(u"value"_j, i);
    npc(writer)->end(u"primitive"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(bool b, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"boolean"_j);
    npc(writer)->attribute(u"value"_j, b);
    npc(writer)->end(u"primitive"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(int8_t b, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"byte"_j);
    npc(writer)->attribute(u"value"_j, static_cast< int32_t >(b));
    npc(writer)->end(u"primitive"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(char16_t c, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"char"_j);
    npc(writer)->attribute(u"value"_j, c);
    npc(writer)->end(u"primitive"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(double d, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"double"_j);
    npc(writer)->attribute(u"value"_j, d);
    npc(writer)->end(u"primitive"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(float f, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"float"_j);
    npc(writer)->attribute(u"value"_j, f);
    npc(writer)->end(u"primitive"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(int64_t l, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"long"_j);
    npc(writer)->attribute(u"value"_j, l);
    npc(writer)->end(u"primitive"_j);
}

void rice::p2p::util::XMLObjectOutputStream::writePrimitive(int16_t s, ::java::lang::String* field) /* throws(IOException) */
{
    npc(writer)->start(u"primitive"_j);
    if(field != nullptr)
        npc(writer)->attribute(u"field"_j, field);

    npc(writer)->attribute(u"type"_j, u"short"_j);
    npc(writer)->attribute(u"value"_j, static_cast< int32_t >(s));
    npc(writer)->end(u"primitive"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLObjectOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLObjectOutputStream", 35);
    return c;
}

void rice::p2p::util::XMLObjectOutputStream::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        WRITE_REPLACES_ = new SoftHashMap();
        WRITE_OBJECTS_ = new SoftHashMap();
        PERSISTENT_FIELDS_ = new SoftHashMap();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

void rice::p2p::util::XMLObjectOutputStream::write(int32_t arg0)
{
    super::write(arg0);
}

void rice::p2p::util::XMLObjectOutputStream::writeObject(::java::lang::Object* arg0)
{
    super::writeObject(arg0);
}

java::lang::Class* rice::p2p::util::XMLObjectOutputStream::getClass0()
{
    return class_();
}

