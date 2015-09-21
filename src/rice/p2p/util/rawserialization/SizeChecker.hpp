// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/SizeChecker.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/SizeCheckOutputBuffer.hpp>

struct default_init_tag;

class rice::p2p::util::rawserialization::SizeChecker
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::SizeCheckOutputBuffer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t count {  };
    /*void writeSpecial(::java::lang::Object* o); (already declared) */

public:
    int32_t bytesWritten() override;
    int32_t bytesRemaining() override;
    void write(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ override;
    void writeBoolean(bool v) /* throws(IOException) */ override;
    void writeByte(int8_t v) /* throws(IOException) */ override;
    void writeChar(char16_t v) /* throws(IOException) */ override;
    void writeDouble(double v) /* throws(IOException) */ override;
    void writeFloat(float v) /* throws(IOException) */ override;
    void writeInt(int32_t v) /* throws(IOException) */ override;
    void writeLong(int64_t v) /* throws(IOException) */ override;
    void writeShort(int16_t v) /* throws(IOException) */ override;
    void writeUTF(::java::lang::String* str) /* throws(IOException) */ override;

    // Generated
    SizeChecker();
protected:
    void ctor();
    SizeChecker(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
