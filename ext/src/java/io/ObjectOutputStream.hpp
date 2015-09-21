// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/ObjectOutput.hpp>
#include <java/io/ObjectStreamConstants.hpp>

struct default_init_tag;

class java::io::ObjectOutputStream
    : public OutputStream
    , public virtual ObjectOutput
    , public virtual ObjectStreamConstants
{

public:
    typedef OutputStream super;

private:
    ObjectOutputStream_BlockDataOutputStream* bout {  };
    SerialCallbackContext* curContext {  };
    ObjectOutputStream_PutFieldImpl* curPut {  };
    ObjectOutputStream_DebugTraceInfoStack* debugInfoStack {  };
    int32_t depth {  };
    bool enableOverride {  };
    bool enableReplace {  };
    static bool extendedDebugInfo_;
    ObjectOutputStream_HandleTable* handles {  };
    ::int8_tArray* primVals {  };
    int32_t protocol {  };
    ObjectOutputStream_ReplaceTable* subs {  };

protected:
    void ctor();
    void ctor(OutputStream* arg0);

public: /* protected */
    virtual void annotateClass(::java::lang::Class* arg0);
    virtual void annotateProxyClass(::java::lang::Class* arg0);
    /*static bool auditSubclass(::java::lang::Class* arg0); (private) */
    /*void clear(); (private) */

public:
    void close() override;
    /*void defaultWriteFields(::java::lang::Object* arg0, ObjectStreamClass* arg1); (private) */
    virtual void defaultWriteObject();
    /*static void doublesToBytes(::doubleArray* arg0, int32_t arg1, ::int8_tArray* arg2, int32_t arg3, int32_t arg4); (private) */

public: /* protected */
    virtual void drain();
    virtual bool enableReplaceObject(bool arg0);
    /*static void floatsToBytes(::floatArray* arg0, int32_t arg1, ::int8_tArray* arg2, int32_t arg3, int32_t arg4); (private) */

public:
    void flush() override;

public: /* package */
    virtual int32_t getProtocolVersion();
    /*bool isCustomSubclass(); (private) */

public:
    virtual ObjectOutputStream_PutField* putFields();

public: /* protected */
    virtual ::java::lang::Object* replaceObject(::java::lang::Object* arg0);

public:
    virtual void reset();
    virtual void useProtocolVersion(int32_t arg0);
    /*void verifySubclass(); (private) */
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*void writeArray_(::java::lang::Object* arg0, ObjectStreamClass* arg1, bool arg2); (private) */
    void writeBoolean(bool arg0) override;
    void writeByte(int32_t arg0) override;
    void writeBytes(::java::lang::String* arg0) override;
    void writeChar(int32_t arg0) override;
    void writeChars(::java::lang::String* arg0) override;
    /*void writeClass(::java::lang::Class* arg0, bool arg1); (private) */
    /*void writeClassDesc(ObjectStreamClass* arg0, bool arg1); (private) */

public: /* protected */
    virtual void writeClassDescriptor(ObjectStreamClass* arg0);

public:
    void writeDouble(double arg0) override;
    /*void writeEnum(::java::lang::Enum* arg0, ObjectStreamClass* arg1, bool arg2); (private) */
    /*void writeExternalData(Externalizable* arg0); (private) */
    /*void writeFatalException(IOException* arg0); (private) */
    virtual void writeFields();
    void writeFloat(float arg0) override;
    /*void writeHandle(int32_t arg0); (private) */
    void writeInt(int32_t arg0) override;
    void writeLong(int64_t arg0) override;
    /*void writeNonProxyDesc(ObjectStreamClass* arg0, bool arg1); (private) */
    /*void writeNull(); (private) */
    void writeObject(::java::lang::Object* arg0) override;
    /*void writeObject0(::java::lang::Object* arg0, bool arg1); (private) */

public: /* protected */
    virtual void writeObjectOverride(::java::lang::Object* arg0);
    /*void writeOrdinaryObject(::java::lang::Object* arg0, ObjectStreamClass* arg1, bool arg2); (private) */
    /*void writeProxyDesc(ObjectStreamClass* arg0, bool arg1); (private) */
    /*void writeSerialData(::java::lang::Object* arg0, ObjectStreamClass* arg1); (private) */

public:
    void writeShort(int32_t arg0) override;

public: /* protected */
    virtual void writeStreamHeader();
    /*void writeString(::java::lang::String* arg0, bool arg1); (private) */

public: /* package */
    virtual void writeTypeString(::java::lang::String* arg0);

public:
    void writeUTF(::java::lang::String* arg0) override;
    virtual void writeUnshared(::java::lang::Object* arg0);

    // Generated

public: /* protected */
    ObjectOutputStream();

public:
    ObjectOutputStream(OutputStream* arg0);
protected:
    ObjectOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static bool& extendedDebugInfo();
    virtual ::java::lang::Class* getClass0();
};
