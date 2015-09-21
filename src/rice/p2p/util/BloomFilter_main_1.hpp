// Generated from /pastry-2.1/src/rice/p2p/util/BloomFilter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

struct default_init_tag;

class rice::p2p::util::BloomFilter_main_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::OutputBuffer
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::io::DataOutputStream* dos {  };

public:
    void writeInt(int32_t v) /* throws(IOException) */ override;
    void writeByte(int8_t v) /* throws(IOException) */ override;
    virtual ::java::io::ByteArrayOutputStream* getBaos();
    int32_t bytesRemaining() override;
    void writeUTF(::java::lang::String* str) /* throws(IOException) */ override;
    void writeShort(int16_t v) /* throws(IOException) */ override;
    void writeLong(int64_t v) /* throws(IOException) */ override;
    void writeFloat(float v) /* throws(IOException) */ override;
    void writeDouble(double v) /* throws(IOException) */ override;
    void writeChar(char16_t v) /* throws(IOException) */ override;
    void writeBoolean(bool v) /* throws(IOException) */ override;
    void write(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ override;

    // Generated
    BloomFilter_main_1(::java::io::ByteArrayOutputStream* baos);
    static ::java::lang::Class *class_();

private:
    void init();
    ::java::io::ByteArrayOutputStream* baos;
    virtual ::java::lang::Class* getClass0();
    friend class BloomFilter;
    friend class BloomFilter_main_2;
};
