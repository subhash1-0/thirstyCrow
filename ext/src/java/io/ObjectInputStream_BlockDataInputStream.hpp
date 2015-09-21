// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/InputStream.hpp>
#include <java/io/DataInput.hpp>

struct default_init_tag;

class java::io::ObjectInputStream_BlockDataInputStream
    : public InputStream
    , public virtual DataInput
{

public:
    typedef InputStream super;

private:
    static constexpr int32_t CHAR_BUF_SIZE { int32_t(256) };
    static constexpr int32_t HEADER_BLOCKED { int32_t(-2) };
    static constexpr int32_t MAX_BLOCK_SIZE { int32_t(1024) };
    static constexpr int32_t MAX_HEADER_SIZE { int32_t(5) };
    bool blkmode {  };
    ::int8_tArray* buf {  };
    ::char16_tArray* cbuf {  };
    DataInputStream* din {  };
    int32_t end {  };
    ::int8_tArray* hbuf {  };
    ObjectInputStream_PeekInputStream* in {  };
    int32_t pos {  };

public: /* package */
    ObjectInputStream* this$0 {  };

private:
    int32_t unread {  };

protected:
    void ctor(InputStream* arg0);

public:
    int32_t available() override;
    void close() override;

public: /* package */
    virtual int32_t currentBlockRemaining();
    virtual bool getBlockDataMode();
    virtual int32_t peek();
    virtual int8_t peekByte();

public:
    int32_t read() override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

public: /* package */
    virtual int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2, bool arg3);
    /*int32_t readBlockHeader(bool arg0); (private) */

public:
    bool readBoolean() override;

public: /* package */
    virtual void readBooleans(::boolArray* arg0, int32_t arg1, int32_t arg2);

public:
    int8_t readByte() override;
    char16_t readChar() override;

public: /* package */
    virtual void readChars(::char16_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    double readDouble() override;

public: /* package */
    virtual void readDoubles(::doubleArray* arg0, int32_t arg1, int32_t arg2);

public:
    float readFloat() override;

public: /* package */
    virtual void readFloats(::floatArray* arg0, int32_t arg1, int32_t arg2);

public:
    void readFully(::int8_tArray* arg0) override;
    void readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    virtual void readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2, bool arg3);
    int32_t readInt() override;

public: /* package */
    virtual void readInts(::int32_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    ::java::lang::String* readLine() override;
    int64_t readLong() override;

public: /* package */
    virtual ::java::lang::String* readLongUTF();
    virtual void readLongs(::int64_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    int16_t readShort() override;

public: /* package */
    virtual void readShorts(::int16_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    ::java::lang::String* readUTF() override;
    /*::java::lang::String* readUTFBody(int64_t arg0); (private) */
    /*int32_t readUTFChar(::java::lang::StringBuilder* arg0, int64_t arg1); (private) */
    /*int64_t readUTFSpan(::java::lang::StringBuilder* arg0, int64_t arg1); (private) */
    int32_t readUnsignedByte() override;
    int32_t readUnsignedShort() override;
    /*void refill(); (private) */

public: /* package */
    virtual bool setBlockDataMode(bool arg0);

public:
    int64_t skip(int64_t arg0) override;

public: /* package */
    virtual void skipBlockData();

public:
    int32_t skipBytes(int32_t arg0) override;

    // Generated

public: /* package */
    ObjectInputStream_BlockDataInputStream(ObjectInputStream *ObjectInputStream_this, InputStream* arg0);
protected:
    ObjectInputStream_BlockDataInputStream(ObjectInputStream *ObjectInputStream_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t read(::int8_tArray* arg0);
    ObjectInputStream *ObjectInputStream_this;

private:
    virtual ::java::lang::Class* getClass0();
};
