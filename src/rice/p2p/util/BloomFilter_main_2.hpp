// Generated from /pastry-2.1/src/rice/p2p/util/BloomFilter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>

struct default_init_tag;

class rice::p2p::util::BloomFilter_main_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::InputBuffer
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::io::DataInputStream* dis {  };

public:
    int32_t readInt() /* throws(IOException) */ override;
    int8_t readByte() /* throws(IOException) */ override;
    int32_t bytesRemaining() override;
    ::java::lang::String* readUTF() /* throws(IOException) */ override;
    int16_t readShort() /* throws(IOException) */ override;
    virtual int16_t peakShort() /* throws(IOException) */;
    int64_t readLong() /* throws(IOException) */ override;
    float readFloat() /* throws(IOException) */ override;
    double readDouble() /* throws(IOException) */ override;
    char16_t readChar() /* throws(IOException) */ override;
    bool readBoolean() /* throws(IOException) */ override;
    int32_t read(::int8_tArray* b) /* throws(IOException) */ override;
    int32_t read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ override;

    // Generated
    BloomFilter_main_2(::java::io::ByteArrayInputStream* bais);
    static ::java::lang::Class *class_();

private:
    void init();
    ::java::io::ByteArrayInputStream* bais;
    virtual ::java::lang::Class* getClass0();
    friend class BloomFilter;
    friend class BloomFilter_main_1;
};
