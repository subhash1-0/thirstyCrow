// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/io/InputStream.hpp>
#include <java/io/ObjectInput.hpp>
#include <java/io/ObjectStreamConstants.hpp>

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

class java::io::ObjectInputStream
    : public InputStream
    , public virtual ObjectInput
    , public virtual ObjectStreamConstants
{

public:
    typedef InputStream super;

private:
    static constexpr int32_t NULL_HANDLE { int32_t(-1) };
    ObjectInputStream_BlockDataInputStream* bin {  };
    bool closed {  };
    SerialCallbackContext* curContext {  };
    bool defaultDataEnd {  };
    int32_t depth {  };
    bool enableOverride {  };
    bool enableResolve {  };
    ObjectInputStream_HandleTable* handles {  };
    int32_t passHandle {  };
    static ::java::util::HashMap* primClasses_;
    ::int8_tArray* primVals {  };
    static ::java::lang::Object* unsharedMarker_;
    ObjectInputStream_ValidationList* vlist {  };

protected:
    void ctor();
    void ctor(InputStream* arg0);
    /*static bool auditSubclass(::java::lang::Class* arg0); (private) */

public:
    int32_t available() override;
    /*static void bytesToDoubles(::int8_tArray* arg0, int32_t arg1, ::doubleArray* arg2, int32_t arg3, int32_t arg4); (private) */
    /*static void bytesToFloats(::int8_tArray* arg0, int32_t arg1, ::floatArray* arg2, int32_t arg3, int32_t arg4); (private) */
    /*::java::lang::Object* checkResolve(::java::lang::Object* arg0); (private) */
    /*void clear(); (private) */
    /*static ::java::lang::Object* cloneArray_(::java::lang::Object* arg0); (private) */
    void close() override;
    /*void defaultReadFields(::java::lang::Object* arg0, ObjectStreamClass* arg1); (private) */
    virtual void defaultReadObject();

public: /* protected */
    virtual bool enableResolveObject(bool arg0);
    /*void handleReset(); (private) */
    /*bool isCustomSubclass(); (private) */
    /*static ::java::lang::ClassLoader* latestUserDefinedLoader(); (private) */

public:
    int32_t read() override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*::java::lang::Object* readArray_(bool arg0); (private) */
    bool readBoolean() override;
    int8_t readByte() override;
    char16_t readChar() override;
    /*::java::lang::Class* readClass(bool arg0); (private) */
    /*ObjectStreamClass* readClassDesc(bool arg0); (private) */

public: /* protected */
    virtual ObjectStreamClass* readClassDescriptor();

public:
    double readDouble() override;
    /*::java::lang::Enum* readEnum(bool arg0); (private) */
    /*void readExternalData(Externalizable* arg0, ObjectStreamClass* arg1); (private) */
    /*IOException* readFatalException(); (private) */
    virtual ObjectInputStream_GetField* readFields();
    float readFloat() override;
    void readFully(::int8_tArray* arg0) override;
    void readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*::java::lang::Object* readHandle(bool arg0); (private) */
    int32_t readInt() override;
    ::java::lang::String* readLine() override;
    int64_t readLong() override;
    /*ObjectStreamClass* readNonProxyDesc(bool arg0); (private) */
    /*::java::lang::Object* readNull(); (private) */
    ::java::lang::Object* readObject() override;
    /*::java::lang::Object* readObject0(bool arg0); (private) */

public: /* protected */
    virtual ::java::lang::Object* readObjectOverride();
    /*::java::lang::Object* readOrdinaryObject(bool arg0); (private) */
    /*ObjectStreamClass* readProxyDesc(bool arg0); (private) */
    /*void readSerialData(::java::lang::Object* arg0, ObjectStreamClass* arg1); (private) */

public:
    int16_t readShort() override;

public: /* protected */
    virtual void readStreamHeader();
    /*::java::lang::String* readString(bool arg0); (private) */

public: /* package */
    virtual ::java::lang::String* readTypeString();

public:
    ::java::lang::String* readUTF() override;
    virtual ::java::lang::Object* readUnshared();
    int32_t readUnsignedByte() override;
    int32_t readUnsignedShort() override;
    virtual void registerValidation(ObjectInputValidation* arg0, int32_t arg1);

public: /* protected */
    virtual ::java::lang::Class* resolveClass(ObjectStreamClass* arg0);
    virtual ::java::lang::Object* resolveObject(::java::lang::Object* arg0);
    virtual ::java::lang::Class* resolveProxyClass(::java::lang::StringArray* arg0);

public:
    int32_t skipBytes(int32_t arg0) override;
    /*void skipCustomData(); (private) */
    /*void verifySubclass(); (private) */

    // Generated

public: /* protected */
    ObjectInputStream();

public:
    ObjectInputStream(InputStream* arg0);
protected:
    ObjectInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t read(::int8_tArray* arg0);
    virtual int64_t skip(int64_t arg0);

private:
    static ::java::util::HashMap*& primClasses();
    static ::java::lang::Object*& unsharedMarker();
    virtual ::java::lang::Class* getClass0();
};
