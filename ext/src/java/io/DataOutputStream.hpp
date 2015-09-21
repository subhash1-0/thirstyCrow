// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/FilterOutputStream.hpp>
#include <java/io/DataOutput.hpp>

struct default_init_tag;

class java::io::DataOutputStream
    : public FilterOutputStream
    , public virtual DataOutput
{

public:
    typedef FilterOutputStream super;

private:
    ::int8_tArray* bytearr {  };
    ::int8_tArray* writeBuffer {  };

public: /* protected */
    int32_t written {  };

protected:
    void ctor(OutputStream* arg0);

public:
    void flush() override;
    /*void incCount(int32_t arg0); (private) */
    int32_t size();
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    void writeBoolean(bool arg0) override;
    void writeByte(int32_t arg0) override;
    void writeBytes(::java::lang::String* arg0) override;
    void writeChar(int32_t arg0) override;
    void writeChars(::java::lang::String* arg0) override;
    void writeDouble(double arg0) override;
    void writeFloat(float arg0) override;
    void writeInt(int32_t arg0) override;
    void writeLong(int64_t arg0) override;
    void writeShort(int32_t arg0) override;
    void writeUTF(::java::lang::String* arg0) override;

public: /* package */
    static int32_t writeUTF(::java::lang::String* arg0, DataOutput* arg1);

    // Generated

public:
    DataOutputStream(OutputStream* arg0);
protected:
    DataOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
