// Generated from /pastry-2.1/src/rice/p2p/util/MathUtils.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::MathUtils
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::char16_tArray* HEX_ARRAY_;
protected:
    void ctor();

public:
    static int32_t mod(int32_t a, int32_t b);
    static ::int8_tArray* xor_(::int8_tArray* a, ::int8_tArray* b);
    static ::int8_tArray* randomBytes(int32_t len, ::rice::environment::random::RandomSource* random);
    static int32_t randomInt(::rice::environment::random::RandomSource* random);
    static ::java::lang::String* toHex(::int8_tArray* text);
    static ::int8_tArray* fromHex(::java::lang::String* text);
    static ::java::lang::String* toBase64(::int8_tArray* text);
    static ::int8_tArray* fromBase64(::java::lang::String* text);
    static int32_t simpleHash(::int8_tArray* b);

public: /* protected */
    static int8_t getByte(char16_t c);

public:
    static ::int8_tArray* intToByteArray_(int32_t input);
    static void intToByteArray_(int32_t input, ::int8_tArray* output, int32_t offset);
    static int32_t byteArrayToInt(::int8_tArray* input);
    static int32_t byteArrayToInt(::int8_tArray* input, int32_t offset);
    static int16_t byteArrayToShort(::int8_tArray* input);
    static int16_t byteArrayToShort(::int8_tArray* input, int32_t offset);
    static ::int8_tArray* longToByteArray_(int64_t input);
    static void longToByteArray_(int64_t input, ::int8_tArray* output, int32_t offset);
    static int64_t byteArrayToLong(::int8_tArray* input);
    static int64_t byteArrayToLong(::int8_tArray* input, int32_t offset);

private:
    static ::int8_tArray* correctLength(::int8_tArray* data, int32_t length);
    static ::int8_tArray* correctLength(::int8_tArray* data, int32_t offset, int32_t length);

public:
    static int32_t uByteToInt(int8_t b);
    static int32_t uShortToInt(int16_t b);
    static int8_t intToUByte(int32_t i);

    // Generated

private:
    MathUtils();
protected:
    MathUtils(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::char16_tArray*& HEX_ARRAY();

private:
    virtual ::java::lang::Class* getClass0();
};
