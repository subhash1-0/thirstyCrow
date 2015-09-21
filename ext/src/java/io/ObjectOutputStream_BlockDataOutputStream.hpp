// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/DataOutput.hpp>

struct default_init_tag;

class java::io::ObjectOutputStream_BlockDataOutputStream
    : public OutputStream
    , public virtual DataOutput
{

public:
    typedef OutputStream super;

private:
    static constexpr int32_t CHAR_BUF_SIZE { int32_t(256) };
    static constexpr int32_t MAX_BLOCK_SIZE { int32_t(1024) };
    static constexpr int32_t MAX_HEADER_SIZE { int32_t(5) };
    bool blkmode {  };
    ::int8_tArray* buf {  };
    ::char16_tArray* cbuf {  };
    DataOutputStream* dout {  };
    ::int8_tArray* hbuf {  };
    OutputStream* out {  };
    int32_t pos {  };

protected:
    void ctor(OutputStream* arg0);

public:
    void close() override;

public: /* package */
    virtual void drain();

public:
    void flush() override;

public: /* package */
    virtual bool getBlockDataMode();
    virtual int64_t getUTFLength(::java::lang::String* arg0);
    virtual bool setBlockDataMode(bool arg0);

public:
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

public: /* package */
    virtual void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2, bool arg3);
    /*void writeBlockHeader(int32_t arg0); (private) */

public:
    void writeBoolean(bool arg0) override;

public: /* package */
    virtual void writeBooleans(::boolArray* arg0, int32_t arg1, int32_t arg2);

public:
    void writeByte(int32_t arg0) override;
    void writeBytes(::java::lang::String* arg0) override;
    void writeChar(int32_t arg0) override;
    void writeChars(::java::lang::String* arg0) override;

public: /* package */
    virtual void writeChars(::char16_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    void writeDouble(double arg0) override;

public: /* package */
    virtual void writeDoubles(::doubleArray* arg0, int32_t arg1, int32_t arg2);

public:
    void writeFloat(float arg0) override;

public: /* package */
    virtual void writeFloats(::floatArray* arg0, int32_t arg1, int32_t arg2);

public:
    void writeInt(int32_t arg0) override;

public: /* package */
    virtual void writeInts(::int32_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    void writeLong(int64_t arg0) override;

public: /* package */
    virtual void writeLongUTF(::java::lang::String* arg0);
    virtual void writeLongUTF(::java::lang::String* arg0, int64_t arg1);
    virtual void writeLongs(::int64_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    void writeShort(int32_t arg0) override;

public: /* package */
    virtual void writeShorts(::int16_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    void writeUTF(::java::lang::String* arg0) override;

public: /* package */
    virtual void writeUTF(::java::lang::String* arg0, int64_t arg1);
    /*void writeUTFBody(::java::lang::String* arg0); (private) */

    // Generated
    ObjectOutputStream_BlockDataOutputStream(OutputStream* arg0);
protected:
    ObjectOutputStream_BlockDataOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
