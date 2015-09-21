// Generated from /pastry-2.1/src/rice/p2p/util/Base64.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::Base64
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t NO_OPTIONS { int32_t(0) };
    static constexpr int32_t ENCODE { int32_t(1) };
    static constexpr int32_t DECODE { int32_t(0) };
    static constexpr int32_t GZIP { int32_t(2) };
    static constexpr int32_t DONT_BREAK_LINES { int32_t(8) };

private:
    static constexpr int32_t MAX_LINE_LENGTH { int32_t(76) };
    static constexpr int8_t EQUALS_SIGN { int8_t(61) };
    static constexpr int8_t NEW_LINE { int8_t(10) };
    static ::java::lang::String* PREFERRED_ENCODING_;
    static ::int8_tArray* ALPHABET_;
    static ::int8_tArray* _NATIVE_ALPHABET_;
    static ::int8_tArray* DECODABET_;
    static constexpr int8_t BAD_ENCODING { int8_t(-9) };
    static constexpr int8_t WHITE_SPACE_ENC { int8_t(-5) };
    static constexpr int8_t EQUALS_SIGN_ENC { int8_t(-1) };
protected:
    void ctor();

private:
    static ::int8_tArray* encode3to4(::int8_tArray* threeBytes);
    static ::int8_tArray* encode3to4(::int8_tArray* threeBytes, int32_t numSigBytes);
    static ::int8_tArray* encode3to4(::int8_tArray* b4, ::int8_tArray* threeBytes, int32_t numSigBytes);
    static ::int8_tArray* encode3to4(::int8_tArray* source, int32_t srcOffset, int32_t numSigBytes, ::int8_tArray* destination, int32_t destOffset);

public:
    static ::java::lang::String* encodeObject(::java::io::Serializable* serializableObject);
    static ::java::lang::String* encodeObject(::java::io::Serializable* serializableObject, int32_t options);
    static ::java::lang::String* encodeBytes(::int8_tArray* source);
    static ::java::lang::String* encodeBytes(::int8_tArray* source, int32_t options);
    static ::java::lang::String* encodeBytes(::int8_tArray* source, int32_t off, int32_t len);
    static ::java::lang::String* encodeBytes(::int8_tArray* source, int32_t off, int32_t len, int32_t options);

private:
    static ::int8_tArray* decode4to3(::int8_tArray* fourBytes);
    static int32_t decode4to3(::int8_tArray* source, int32_t srcOffset, ::int8_tArray* destination, int32_t destOffset);

public:
    static ::int8_tArray* decode(::int8_tArray* source, int32_t off, int32_t len);
    static ::int8_tArray* decode(::java::lang::String* s);
    static ::java::lang::Object* decodeToObject(::java::lang::String* encodedObject);

    // Generated

private:
    Base64();
protected:
    Base64(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static ::java::lang::String*& PREFERRED_ENCODING();
    static ::int8_tArray*& ALPHABET();
    static ::int8_tArray*& _NATIVE_ALPHABET();
    static ::int8_tArray*& DECODABET();
    virtual ::java::lang::Class* getClass0();
    friend class Base64_InputStream;
    friend class Base64_OutputStream;
};
