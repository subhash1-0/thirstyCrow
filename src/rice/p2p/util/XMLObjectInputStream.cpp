// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectInputStream.java
#include <rice/p2p/util/XMLObjectInputStream.hpp>

#include <java/io/Externalizable.hpp>
#include <java/io/IOException.hpp>
#include <java/io/InputStreamReader.hpp>
#include <java/io/NotActiveException.hpp>
#include <java/io/NotSerializableException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/Character.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/IllegalAccessException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/InstantiationException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NoSuchFieldException.hpp>
#include <java/lang/NoSuchMethodException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/lang/reflect/AnnotatedElement.hpp>
#include <java/lang/reflect/Array_.hpp>
#include <java/lang/reflect/Constructor.hpp>
#include <java/lang/reflect/Field.hpp>
#include <java/lang/reflect/GenericDeclaration.hpp>
#include <java/lang/reflect/InvocationTargetException.hpp>
#include <java/lang/reflect/Method.hpp>
#include <java/lang/reflect/Modifier.hpp>
#include <java/lang/reflect/Type.hpp>
#include <java/security/AccessController.hpp>
#include <java/security/PrivilegedAction.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Stack.hpp>
#include <rice/p2p/util/SoftHashMap.hpp>
#include <rice/p2p/util/XMLObjectInputStream_GetField.hpp>
#include <rice/p2p/util/XMLObjectInputStream_ValidationList.hpp>
#include <rice/p2p/util/XMLReader.hpp>
#include <sun/reflect/ReflectionFactory_GetReflectionFactoryAction.hpp>
#include <sun/reflect/ReflectionFactory.hpp>
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
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;
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
rice::p2p::util::XMLObjectInputStream::XMLObjectInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::XMLObjectInputStream::XMLObjectInputStream(::java::io::InputStream* in)  /* throws(IOException) */
    : XMLObjectInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(in);
}

void rice::p2p::util::XMLObjectInputStream::init()
{
    reflFactory = java_cast< ::sun::reflect::ReflectionFactory* >(java_cast< ::sun::reflect::ReflectionFactory* >(::java::security::AccessController::doPrivileged(static_cast< ::java::security::PrivilegedAction* >(new ::sun::reflect::ReflectionFactory_GetReflectionFactoryAction()))));
}

rice::p2p::util::SoftHashMap*& rice::p2p::util::XMLObjectInputStream::READ_RESOLVES()
{
    clinit();
    return READ_RESOLVES_;
}
rice::p2p::util::SoftHashMap* rice::p2p::util::XMLObjectInputStream::READ_RESOLVES_;

rice::p2p::util::SoftHashMap*& rice::p2p::util::XMLObjectInputStream::READ_OBJECTS()
{
    clinit();
    return READ_OBJECTS_;
}
rice::p2p::util::SoftHashMap* rice::p2p::util::XMLObjectInputStream::READ_OBJECTS_;

rice::p2p::util::SoftHashMap*& rice::p2p::util::XMLObjectInputStream::CONSTRUCTORS()
{
    clinit();
    return CONSTRUCTORS_;
}
rice::p2p::util::SoftHashMap* rice::p2p::util::XMLObjectInputStream::CONSTRUCTORS_;

void rice::p2p::util::XMLObjectInputStream::ctor(::java::io::InputStream* in) /* throws(IOException) */
{
    super::ctor();
    init();
    this->reader = new XMLReader(new ::java::io::InputStreamReader(in));
    this->currentObjects = new ::java::util::Stack();
    this->currentClasses = new ::java::util::Stack();
    this->references = new ::java::util::Hashtable();
    this->vlist = new XMLObjectInputStream_ValidationList();
    this->depth = 0;
    readStreamHeader();
}

void rice::p2p::util::XMLObjectInputStream::readStreamHeader() /* throws(IOException) */
{
    npc(reader)->readHeader();
}

void rice::p2p::util::XMLObjectInputStream::close() /* throws(IOException) */
{
    npc(reader)->close();
}

void rice::p2p::util::XMLObjectInputStream::reset() /* throws(IOException) */
{
    references = new ::java::util::Hashtable();
    npc(vlist)->clear();
}

int32_t rice::p2p::util::XMLObjectInputStream::read() /* throws(IOException) */
{
    return readByte();
}

int32_t rice::p2p::util::XMLObjectInputStream::read(::int8_tArray* b, int32_t offset, int32_t length) /* throws(IOException) */
{
    npc(reader)->readStartTag(u"base64"_j);
    auto bytes = npc(reader)->readBase64();
    auto written = (length < npc(bytes)->length ? length : npc(bytes)->length);
    ::java::lang::System::arraycopy(bytes, 0, b, offset, written);
    return written;
}

void rice::p2p::util::XMLObjectInputStream::readFully(::int8_tArray* b) /* throws(IOException) */
{
    readFully(b, int32_t(0), npc(b)->length);
}

void rice::p2p::util::XMLObjectInputStream::readFully(::int8_tArray* b, int32_t offset, int32_t length) /* throws(IOException) */
{
    read(b, offset, length);
}

int32_t rice::p2p::util::XMLObjectInputStream::readUnsignedByte() /* throws(IOException) */
{
    return readByte();
}

int32_t rice::p2p::util::XMLObjectInputStream::readUnsignedShort() /* throws(IOException) */
{
    return readShort();
}

int32_t rice::p2p::util::XMLObjectInputStream::readInt() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readIntHelper();
}

bool rice::p2p::util::XMLObjectInputStream::readBoolean() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readBooleanHelper();
}

int8_t rice::p2p::util::XMLObjectInputStream::readByte() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readByteHelper();
}

char16_t rice::p2p::util::XMLObjectInputStream::readChar() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readCharHelper();
}

double rice::p2p::util::XMLObjectInputStream::readDouble() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readDoubleHelper();
}

float rice::p2p::util::XMLObjectInputStream::readFloat() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readFloatHelper();
}

int64_t rice::p2p::util::XMLObjectInputStream::readLong() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readLongHelper();
}

int16_t rice::p2p::util::XMLObjectInputStream::readShort() /* throws(IOException) */
{
    npc(reader)->readStartTag(u"primitive"_j);
    return readShortHelper();
}

java::lang::String* rice::p2p::util::XMLObjectInputStream::readUTF() /* throws(IOException) */
{
    try {
        return java_cast< ::java::lang::String* >(readObject());
    } catch (::java::lang::ClassNotFoundException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"ReadUTF caused "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readObjectOverride() /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->readStartTag();
    auto result = readObjectHelper();
    if(depth == 0) {
        npc(vlist)->doCallbacks();
    }
    return result;
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readUnshared() /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->readStartTag();
    auto result = readUnsharedHelper(false);
    if(depth == 0) {
        npc(vlist)->doCallbacks();
    }
    return result;
}

void rice::p2p::util::XMLObjectInputStream::defaultReadObject() /* throws(IOException, ClassNotFoundException) */
{
    if(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()) != nullptr)
        readFields(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()), java_cast< ::java::lang::Class* >(java_cast< ::java::lang::Object* >(npc(currentClasses)->peek())));
    else
        throw new ::java::io::NotActiveException(u"defaultReadObject called with empty stack!"_j);
}

java::io::ObjectInputStream_GetField* rice::p2p::util::XMLObjectInputStream::readFields() /* throws(IOException, ClassNotFoundException) */
{
    if(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()) != nullptr)
        return readGetFields();
    else
        throw new ::java::io::NotActiveException(u"readFields called with empty stack!"_j);
}

void rice::p2p::util::XMLObjectInputStream::registerValidation(::java::io::ObjectInputValidation* obj, int32_t prio) /* throws(NotActiveException, InvalidObjectException) */
{
    if(java_cast< ::java::lang::Object* >(npc(currentObjects)->peek()) == nullptr)
        throw new ::java::io::NotActiveException(u"registerValidation called with empty stack!"_j);

    npc(vlist)->register_(obj, prio);
}

java::lang::reflect::Method* rice::p2p::util::XMLObjectInputStream::getReadResolve(::java::lang::Class* cl)
{
    clinit();
    {
        synchronized synchronized_0(READ_RESOLVES_);
        {
            if(npc(READ_RESOLVES_)->containsKey(static_cast< ::java::lang::Object* >(cl)))
                return java_cast< ::java::lang::reflect::Method* >(npc(READ_RESOLVES_)->get(static_cast< ::java::lang::Object* >(cl)));

            ::java::lang::reflect::Method* meth = nullptr;
            auto defCl = cl;
            while (defCl != nullptr) {
                try {
                    meth = npc(defCl)->getDeclaredMethod(u"readResolve"_j, new ::java::lang::ClassArray(int32_t(0)));
                    break;
                } catch (::java::lang::NoSuchMethodException* ex) {
                    defCl = npc(defCl)->getSuperclass();
                }
            }
            if(meth == nullptr) {
                npc(READ_RESOLVES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(nullptr));
                return nullptr;
            }
            npc(meth)->setAccessible(true);
            auto mods = npc(meth)->getModifiers();
            if((mods & (::java::lang::reflect::Modifier::STATIC | ::java::lang::reflect::Modifier::ABSTRACT)) != 0) {
                npc(READ_RESOLVES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(nullptr));
                return nullptr;
            } else if((mods & (::java::lang::reflect::Modifier::PUBLIC | ::java::lang::reflect::Modifier::PROTECTED)) != 0) {
                npc(READ_RESOLVES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(meth));
                return meth;
            } else if((mods & ::java::lang::reflect::Modifier::PRIVATE) != 0) {
                if(cl == defCl) {
                    npc(READ_RESOLVES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(meth));
                    return meth;
                } else {
                    npc(READ_RESOLVES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(nullptr));
                    return nullptr;
                }
            } else {
                npc(READ_RESOLVES_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(meth));
                return meth;
            }
        }
    }
}

java::lang::reflect::Method* rice::p2p::util::XMLObjectInputStream::getReadObject(::java::lang::Class* cl)
{
    clinit();
    {
        synchronized synchronized_1(READ_OBJECTS_);
        {
            if(npc(READ_OBJECTS_)->containsKey(static_cast< ::java::lang::Object* >(cl)))
                return java_cast< ::java::lang::reflect::Method* >(npc(READ_OBJECTS_)->get(static_cast< ::java::lang::Object* >(cl)));

            try {
                auto method = npc(cl)->getDeclaredMethod(u"readObject"_j, new ::java::lang::ClassArray({static_cast< ::java::lang::Class* >(::java::io::ObjectInputStream::class_())}));
                npc(method)->setAccessible(true);
                npc(READ_OBJECTS_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(method));
                return method;
            } catch (::java::lang::NoSuchMethodException* e) {
                npc(READ_OBJECTS_)->put(static_cast< ::java::lang::Object* >(cl), static_cast< ::java::lang::Object* >(nullptr));
                return nullptr;
            }
        }
    }
}

java::lang::reflect::Constructor* rice::p2p::util::XMLObjectInputStream::getSerializableConstructor(::java::lang::Class* c) /* throws(IOException, NoSuchMethodException) */
{
    auto initCl = c;
    while (npc(::java::io::Serializable::class_())->isAssignableFrom(initCl)) 
                initCl = npc(initCl)->getSuperclass();

    auto cons = npc(initCl)->getDeclaredConstructor(new ::java::lang::ClassArray(int32_t(0)));
    cons = npc(reflFactory)->newConstructorForSerialization(c, cons);
    npc(cons)->setAccessible(true);
    return cons;
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::newInstance(::java::lang::Class* c) /* throws(IOException) */
{
    try {
        auto cons = java_cast< ::java::lang::reflect::Constructor* >(npc(CONSTRUCTORS_)->get(static_cast< ::java::lang::Object* >(c)));
        if(cons == nullptr) {
            if(npc(::java::io::Externalizable::class_())->isAssignableFrom(c)) {
                cons = npc(c)->getDeclaredConstructor(new ::java::lang::ClassArray(int32_t(0)));
            } else {
                cons = getSerializableConstructor(c);
            }
            npc(cons)->setAccessible(true);
            npc(CONSTRUCTORS_)->put(static_cast< ::java::lang::Object* >(c), static_cast< ::java::lang::Object* >(cons));
        }
        return java_cast< ::java::lang::Object* >(npc(cons)->newInstance(new ::java::lang::ObjectArray(int32_t(0))));
    } catch (::java::lang::InstantiationException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not instanciate new class "_j)->append(static_cast< ::java::lang::Object* >(c))->toString());
    } catch (::java::lang::IllegalAccessException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not instanciate new class "_j)->append(static_cast< ::java::lang::Object* >(c))->toString());
    } catch (::java::lang::reflect::InvocationTargetException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not instanciate new class "_j)->append(static_cast< ::java::lang::Object* >(c))->toString());
    } catch (::java::lang::NoSuchMethodException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not instanciate new class "_j)->append(static_cast< ::java::lang::Object* >(c))->toString());
    }
}

java::lang::Class* rice::p2p::util::XMLObjectInputStream::getClass(::java::lang::String* name) /* throws(ClassNotFoundException) */
{
    if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"int"_j)))
        return ::java::lang::Integer::TYPE();
    else if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"boolean"_j)))
        return ::java::lang::Boolean::TYPE();
    else if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"byte"_j)))
        return ::java::lang::Byte::TYPE();
    else if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"char"_j)))
        return ::java::lang::Character::TYPE();
    else if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"double"_j)))
        return ::java::lang::Double::TYPE();
    else if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"float"_j)))
        return ::java::lang::Float::TYPE();
    else if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"long"_j)))
        return ::java::lang::Long::TYPE();
    else if(npc(name)->equals(static_cast< ::java::lang::Object* >(u"short"_j)))
        return ::java::lang::Short::TYPE();
    else
        return ::java::lang::Class::forName(name);
}

void rice::p2p::util::XMLObjectInputStream::putReference(::java::lang::String* reference, ::java::lang::Object* o)
{
    npc(references)->put(static_cast< ::java::lang::Object* >(reference), static_cast< ::java::lang::Object* >(o));
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::getReference(::java::lang::String* reference)
{
    return java_cast< ::java::lang::Object* >(npc(references)->get(static_cast< ::java::lang::Object* >(reference)));
}

java::lang::String* rice::p2p::util::XMLObjectInputStream::readPrimitive(::java::lang::String* type) /* throws(IOException) */
{
    npc(reader)->assertStartTag(u"primitive"_j);
    npc(reader)->assertAttribute(u"type"_j, type);
    auto value = npc(reader)->getAttribute(u"value"_j);
    npc(reader)->readEndTag(u"primitive"_j);
    return value;
}

int32_t rice::p2p::util::XMLObjectInputStream::readIntHelper() /* throws(IOException) */
{
    return ::java::lang::Integer::parseInt(readPrimitive(u"int"_j));
}

bool rice::p2p::util::XMLObjectInputStream::readBooleanHelper() /* throws(IOException) */
{
    return npc(readPrimitive(u"boolean"_j))->equals(static_cast< ::java::lang::Object* >(u"true"_j));
}

int8_t rice::p2p::util::XMLObjectInputStream::readByteHelper() /* throws(IOException) */
{
    return ::java::lang::Byte::parseByte(readPrimitive(u"byte"_j));
}

char16_t rice::p2p::util::XMLObjectInputStream::readCharHelper() /* throws(IOException) */
{
    return npc(readPrimitive(u"char"_j))->charAt(int32_t(0));
}

double rice::p2p::util::XMLObjectInputStream::readDoubleHelper() /* throws(IOException) */
{
    return ::java::lang::Double::parseDouble(readPrimitive(u"double"_j));
}

float rice::p2p::util::XMLObjectInputStream::readFloatHelper() /* throws(IOException) */
{
    return ::java::lang::Float::parseFloat(readPrimitive(u"float"_j));
}

int64_t rice::p2p::util::XMLObjectInputStream::readLongHelper() /* throws(IOException) */
{
    return ::java::lang::Long::parseLong(readPrimitive(u"long"_j));
}

int16_t rice::p2p::util::XMLObjectInputStream::readShortHelper() /* throws(IOException) */
{
    return ::java::lang::Short::parseShort(readPrimitive(u"short"_j));
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readObjectHelper() /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag();
    depth++;
    ::java::lang::Object* result = nullptr;
    if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"reference"_j))) {
        result = readReference();
    } else if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"null"_j))) {
        result = readNull();
    } else {
        result = readUnsharedHelper(true);
    }
    depth--;
    return result;
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readUnsharedHelper(bool shared) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag();
    if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"string"_j))) {
        return readString(shared);
    } else if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"array"_j))) {
        return readArray_(shared);
    } else if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"object"_j))) {
        return readOrdinaryObject(shared);
    } else {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown element name "_j)->append(npc(reader)->getStartTag())->toString());
    }
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readReference() /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag(u"reference"_j);
    auto result = getReference(npc(reader)->getAttribute(u"idref"_j));
    if(result == nullptr)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Invalid reference "_j)->append(npc(reader)->getAttribute(u"idref"_j))
            ->append(u" found."_j)->toString());

    npc(reader)->readEndTag(u"reference"_j);
    return result;
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readNull() /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag(u"null"_j);
    npc(reader)->readEndTag(u"null"_j);
    return nullptr;
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readString(bool shared) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag(u"string"_j);
    auto result = new ::java::lang::String(npc(reader)->getAttribute(u"value"_j));
    if(shared && (npc(reader)->getAttribute(u"id"_j) != nullptr))
        putReference(npc(reader)->getAttribute(u"id"_j), result);

    npc(reader)->readEndTag(u"string"_j);
    return result;
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readOrdinaryObject(bool shared) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag(u"object"_j);
    auto c = ::java::lang::Class::forName(npc(reader)->getAttribute(u"class"_j));
    auto id = npc(reader)->getAttribute(u"id"_j);
    if(!npc(::java::io::Serializable::class_())->isAssignableFrom(c))
        throw new ::java::io::NotSerializableException(npc(c)->getName());

    auto o = newInstance(c);
    if(shared && (id != nullptr))
        putReference(id, o);

    if(npc(::java::io::Externalizable::class_())->isAssignableFrom(c)) {
        npc((java_cast< ::java::io::Externalizable* >(o)))->readExternal(this);
        npc(reader)->step();
    } else {
        npc(reader)->step();
        while (!npc(reader)->isEndTag()) {
            readClass(o);
            npc(reader)->step();
        }
    }
    npc(reader)->assertEndTag(u"object"_j);
    auto method = getReadResolve(c);
    try {
        if(method != nullptr) {
            o = npc(method)->invoke(o, new ::java::lang::ObjectArray(int32_t(0)));
            if(shared && (id != nullptr))
                putReference(id, o);

        }
    } catch (::java::lang::IllegalAccessException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"ReadResolve caused "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::java::lang::reflect::InvocationTargetException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"ReadResolve caused "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
    return o;
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readClass(::java::lang::Object* o) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag(u"declaredClass"_j);
    auto c = ::java::lang::Class::forName(npc(reader)->getAttribute(u"class"_j));
    auto method = getReadObject(c);
    if(method != nullptr) {
        try {
            npc(currentObjects)->push(o);
            npc(currentClasses)->push(c);
            npc(method)->invoke(o, new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(this)}));
            npc(currentObjects)->pop();
            npc(currentClasses)->pop();
            readUnreadOptionalData();
        } catch (::java::lang::reflect::InvocationTargetException* e) {
            npc(::java::lang::System::out())->println(npc(npc(e)->getTargetException())->getMessage());
            npc(npc(e)->getTargetException())->printStackTrace();
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"InvocationTargetException thrown! "_j)->append(static_cast< ::java::lang::Object* >(npc(e)->getTargetException()))->toString());
        } catch (::java::lang::IllegalAccessException* e) {
            npc(::java::lang::System::out())->println(npc(e)->getMessage());
            npc(e)->printStackTrace();
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"IllegalAccessException thrown! "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        }
    } else {
        readFields(o, c);
        readUnreadOptionalData();
    }
    npc(reader)->assertEndTag(u"declaredClass"_j);
    return o;
}

void rice::p2p::util::XMLObjectInputStream::readUnreadOptionalData() /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->step();
    while (!npc(reader)->isEndTag()) {
        if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"primitive"_j))) {
            npc(reader)->readEndTag(u"primitive"_j);
        } else if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"base64"_j))) {
            npc(reader)->readEndTag(u"base64"_j);
        } else {
            readObjectHelper();
        }
        npc(reader)->step();
    }
}

rice::p2p::util::XMLObjectInputStream_GetField* rice::p2p::util::XMLObjectInputStream::readGetFields() /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->readStartTag(u"default"_j);
    auto g = new XMLObjectInputStream_GetField(this);
    npc(reader)->step();
    while (!npc(reader)->isEndTag()) {
        readGetField(g);
        npc(reader)->step();
    }
    npc(reader)->assertEndTag(u"default"_j);
    return g;
}

void rice::p2p::util::XMLObjectInputStream::readGetField(XMLObjectInputStream_GetField* g) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag();
    auto name = npc(reader)->getAttribute(u"field"_j);
    if(name == nullptr)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not read field "_j)->append(npc(reader)->getStartTag())
            ->append(u", as field attribute was null!"_j)->toString());

    if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"primitive"_j))) {
        readPrimitiveGetField(g);
    } else {
        npc(g)->put(name, readObjectHelper());
    }
}

void rice::p2p::util::XMLObjectInputStream::readPrimitiveGetField(XMLObjectInputStream_GetField* g) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag(u"primitive"_j);
    auto name = npc(reader)->getAttribute(u"field"_j);
    if(name == nullptr)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not read primitive field "_j)->append(npc(reader)->getAttribute(u"type"_j))
            ->append(u", as field attribute was null!"_j)->toString());

    auto c = getClass(npc(reader)->getAttribute(u"type"_j));
    if(npc(c)->equals(::java::lang::Integer::TYPE())) {
        npc(g)->put(name, readIntHelper());
    } else if(npc(c)->equals(::java::lang::Boolean::TYPE())) {
        npc(g)->put(name, readBooleanHelper());
    } else if(npc(c)->equals(::java::lang::Byte::TYPE())) {
        npc(g)->put(name, readByteHelper());
    } else if(npc(c)->equals(::java::lang::Character::TYPE())) {
        npc(g)->put(name, readCharHelper());
    } else if(npc(c)->equals(::java::lang::Double::TYPE())) {
        npc(g)->put(name, readDoubleHelper());
    } else if(npc(c)->equals(::java::lang::Float::TYPE())) {
        npc(g)->put(name, readFloatHelper());
    } else if(npc(c)->equals(::java::lang::Long::TYPE())) {
        npc(g)->put(name, readLongHelper());
    } else if(npc(c)->equals(::java::lang::Short::TYPE())) {
        npc(g)->put(name, readShortHelper());
    } else {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Field "_j)->append(name)
            ->append(u" is not primitive!"_j)->toString());
    }
}

void rice::p2p::util::XMLObjectInputStream::readFields(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->readStartTag(u"default"_j);
    npc(reader)->step();
    while (!npc(reader)->isEndTag()) {
        readField(o, c);
        npc(reader)->step();
    }
    npc(reader)->assertEndTag(u"default"_j);
}

void rice::p2p::util::XMLObjectInputStream::readField(::java::lang::Object* o, ::java::lang::Class* c) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag();
    auto field = npc(reader)->getAttribute(u"field"_j);
    try {
        auto f = npc(c)->getDeclaredField(npc(reader)->getAttribute(u"field"_j));
        npc(f)->setAccessible(true);
        auto mask = ::java::lang::reflect::Modifier::STATIC;
        if((npc(f)->getModifiers() & mask) != 0)
            throw new ::java::lang::NoSuchFieldException(u"Field read was static!"_j);

        if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"primitive"_j))) {
            readPrimitiveField(o, f);
        } else {
            npc(f)->set(o, readObjectHelper());
        }
    } catch (::java::lang::NoSuchFieldException* e) {
        if(npc(npc(reader)->getStartTag())->equals(static_cast< ::java::lang::Object* >(u"primitive"_j))) {
            npc(reader)->readEndTag(u"primitive"_j);
        } else {
            readObjectHelper();
        }
    } catch (::java::lang::IllegalAccessException* e) {
    } catch (::java::lang::IllegalArgumentException* e) {
        npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"COULD NOT SET FIELD "_j)->append(field)
            ->append(u" OF "_j)
            ->append(npc(npc(o)->getClass())->getName())
            ->append(u" - SKIPPING.  THIS SHOULD NOT HAPPEN!"_j)
            ->append(static_cast< ::java::lang::Object* >(e))->toString());
        npc(e)->printStackTrace();
    }
}

void rice::p2p::util::XMLObjectInputStream::readPrimitiveField(::java::lang::Object* o, ::java::lang::reflect::Field* f) /* throws(IOException, IllegalAccessException) */
{
    npc(reader)->assertStartTag(u"primitive"_j);
    if(npc(npc(f)->getType())->equals(::java::lang::Integer::TYPE())) {
        npc(f)->setInt(o, readIntHelper());
    } else if(npc(npc(f)->getType())->equals(::java::lang::Boolean::TYPE())) {
        npc(f)->setBoolean(o, readBooleanHelper());
    } else if(npc(npc(f)->getType())->equals(::java::lang::Byte::TYPE())) {
        npc(f)->setByte(o, readByteHelper());
    } else if(npc(npc(f)->getType())->equals(::java::lang::Character::TYPE())) {
        npc(f)->setChar(o, readCharHelper());
    } else if(npc(npc(f)->getType())->equals(::java::lang::Double::TYPE())) {
        npc(f)->setDouble(o, readDoubleHelper());
    } else if(npc(npc(f)->getType())->equals(::java::lang::Float::TYPE())) {
        npc(f)->setFloat(o, readFloatHelper());
    } else if(npc(npc(f)->getType())->equals(::java::lang::Long::TYPE())) {
        npc(f)->setLong(o, readLongHelper());
    } else if(npc(npc(f)->getType())->equals(::java::lang::Short::TYPE())) {
        npc(f)->setInt(o, readShortHelper());
    } else {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Field "_j)->append(static_cast< ::java::lang::Object* >(f))
            ->append(u" is not primitive!"_j)->toString());
    }
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream::readArray_(bool shared) /* throws(IOException, ClassNotFoundException) */
{
    npc(reader)->assertStartTag(u"array"_j);
    auto c = getClass(npc(reader)->getAttribute(u"base"_j));
    auto length = npc(::java::lang::Integer::valueOf(npc(reader)->getAttribute(u"length"_j)))->intValue();
    auto dim = npc(::java::lang::Integer::valueOf(npc(reader)->getAttribute(u"dim"_j)))->intValue();
    auto result = ::java::lang::reflect::Array_::newInstance(static_cast< ::java::lang::Class* >(c), length);
    if(shared && (npc(reader)->getAttribute(u"id"_j) != nullptr))
        putReference(npc(reader)->getAttribute(u"id"_j), result);

    for (auto i = int32_t(0); i < length; i++) {
        if(npc(c)->equals(::java::lang::Integer::TYPE()))
            ::java::lang::reflect::Array_::setInt(result, i, readInt());
        else if(npc(c)->equals(::java::lang::Boolean::TYPE()))
            ::java::lang::reflect::Array_::setBoolean(result, i, readBoolean());
        else if(npc(c)->equals(::java::lang::Byte::TYPE()))
            ::java::lang::reflect::Array_::setByte(result, i, readByte());
        else if(npc(c)->equals(::java::lang::Character::TYPE()))
            ::java::lang::reflect::Array_::setChar(result, i, readChar());
        else if(npc(c)->equals(::java::lang::Double::TYPE()))
            ::java::lang::reflect::Array_::setDouble(result, i, readDouble());
        else if(npc(c)->equals(::java::lang::Float::TYPE()))
            ::java::lang::reflect::Array_::setFloat(result, i, readFloat());
        else if(npc(c)->equals(::java::lang::Long::TYPE()))
            ::java::lang::reflect::Array_::setLong(result, i, readLong());
        else if(npc(c)->equals(::java::lang::Short::TYPE()))
            ::java::lang::reflect::Array_::setShort(result, i, readShort());
        else
            ::java::lang::reflect::Array_::set(result, i, readObject());
    }
    npc(reader)->readEndTag(u"array"_j);
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLObjectInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLObjectInputStream", 34);
    return c;
}

void rice::p2p::util::XMLObjectInputStream::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        READ_RESOLVES_ = new SoftHashMap();
        READ_OBJECTS_ = new SoftHashMap();
        CONSTRUCTORS_ = new SoftHashMap();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

int32_t rice::p2p::util::XMLObjectInputStream::read(::int8_tArray* b)
{
    return super::read(b);
}

java::lang::Class* rice::p2p::util::XMLObjectInputStream::getClass()
{
    return super::getClass();
}

java::lang::Class* rice::p2p::util::XMLObjectInputStream::getClass0()
{
    return class_();
}

