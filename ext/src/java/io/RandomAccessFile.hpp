// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/DataOutput.hpp>
#include <java/io/DataInput.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::io::RandomAccessFile
    : public virtual ::java::lang::Object
    , public virtual DataOutput
    , public virtual DataInput
    , public virtual Closeable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t O_DSYNC { int32_t(8) };
    static constexpr int32_t O_RDONLY { int32_t(1) };
    static constexpr int32_t O_RDWR { int32_t(2) };
    static constexpr int32_t O_SYNC { int32_t(4) };
    ::java::nio::channels::FileChannel* channel {  };
    ::java::lang::Object* closeLock {  };
    std::atomic< bool > closed {  };
    FileDescriptor* fd {  };
    ::java::lang::String* path {  };
    bool rw {  };

protected:
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1);
    void ctor(File* arg0, ::java::lang::String* arg1);

public:
    void close() override;
    /*void close0(); (private) */
    ::java::nio::channels::FileChannel* getChannel();
    FileDescriptor* getFD();
    virtual int64_t getFilePointer();
    /*static void initIDs(); (private) */
    virtual int64_t length();
    /*void open(::java::lang::String* arg0, int32_t arg1); (private) */
    /*void open0(::java::lang::String* arg0, int32_t arg1); (private) */
    virtual int32_t read();
    virtual int32_t read(::int8_tArray* arg0);
    virtual int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    /*int32_t read0(); (private) */
    bool readBoolean() override;
    int8_t readByte() override;
    /*int32_t readBytes(::int8_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    char16_t readChar() override;
    double readDouble() override;
    float readFloat() override;
    void readFully(::int8_tArray* arg0) override;
    void readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    int32_t readInt() override;
    ::java::lang::String* readLine() override;
    int64_t readLong() override;
    int16_t readShort() override;
    ::java::lang::String* readUTF() override;
    int32_t readUnsignedByte() override;
    int32_t readUnsignedShort() override;
    virtual void seek(int64_t arg0);
    /*void seek0(int64_t arg0); (private) */
    virtual void setLength(int64_t arg0);
    int32_t skipBytes(int32_t arg0) override;
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*void write0(int32_t arg0); (private) */
    void writeBoolean(bool arg0) override;
    void writeByte(int32_t arg0) override;
    void writeBytes(::java::lang::String* arg0) override;
    /*void writeBytes(::int8_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    void writeChar(int32_t arg0) override;
    void writeChars(::java::lang::String* arg0) override;
    void writeDouble(double arg0) override;
    void writeFloat(float arg0) override;
    void writeInt(int32_t arg0) override;
    void writeLong(int64_t arg0) override;
    void writeShort(int32_t arg0) override;
    void writeUTF(::java::lang::String* arg0) override;

    // Generated
    RandomAccessFile(::java::lang::String* arg0, ::java::lang::String* arg1);
    RandomAccessFile(File* arg0, ::java::lang::String* arg1);
protected:
    RandomAccessFile(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
