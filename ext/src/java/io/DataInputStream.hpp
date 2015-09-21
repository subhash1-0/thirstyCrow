// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/FilterInputStream.hpp>
#include <java/io/DataInput.hpp>

struct default_init_tag;

class java::io::DataInputStream
    : public FilterInputStream
    , public virtual DataInput
{

public:
    typedef FilterInputStream super;

private:
    ::int8_tArray* bytearr {  };
    ::char16_tArray* chararr {  };
    ::char16_tArray* lineBuffer {  };
    ::int8_tArray* readBuffer {  };

protected:
    void ctor(InputStream* arg0);

public:
    int32_t read(::int8_tArray* arg0) override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    bool readBoolean() override;
    int8_t readByte() override;
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
    static ::java::lang::String* readUTF(DataInput* arg0);
    int32_t readUnsignedByte() override;
    int32_t readUnsignedShort() override;
    int32_t skipBytes(int32_t arg0) override;

    // Generated
    DataInputStream(InputStream* arg0);
protected:
    DataInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read();

private:
    virtual ::java::lang::Class* getClass0();
};
