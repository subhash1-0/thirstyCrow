// Generated from /pastry-2.1/src/rice/p2p/util/MathUtils.java
#include <rice/p2p/util/MathUtils.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/util/Base64.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::MathUtils::MathUtils(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::MathUtils::MathUtils() 
    : MathUtils(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

char16_tArray*& rice::p2p::util::MathUtils::HEX_ARRAY()
{
    clinit();
    return HEX_ARRAY_;
}
char16_tArray* rice::p2p::util::MathUtils::HEX_ARRAY_;

void rice::p2p::util::MathUtils::ctor()
{
    super::ctor();
}

int32_t rice::p2p::util::MathUtils::mod(int32_t a, int32_t b)
{
    clinit();
    return ((a % b) + b) % b;
}

int8_tArray* rice::p2p::util::MathUtils::xor_(::int8_tArray* a, ::int8_tArray* b)
{
    clinit();
    auto result = new ::int8_tArray(npc(a)->length);
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                (*result)[i] = static_cast< int8_t >(((*a)[i] ^ (*b)[i]));

    return result;
}

int8_tArray* rice::p2p::util::MathUtils::randomBytes(int32_t len, ::rice::environment::random::RandomSource* random)
{
    clinit();
    auto result = new ::int8_tArray(len);
    npc(random)->nextBytes(result);
    return result;
}

int32_t rice::p2p::util::MathUtils::randomInt(::rice::environment::random::RandomSource* random)
{
    clinit();
    return npc(random)->nextInt();
}

java::lang::String* rice::p2p::util::MathUtils::toHex(::int8_tArray* text)
{
    clinit();
    auto buffer = new ::java::lang::StringBuffer();
    for (auto i = int32_t(0); i < npc(text)->length; i++) {
        npc(buffer)->append((*HEX_ARRAY_)[int32_t(15) & ((*text)[i] >> int32_t(4))]);
        npc(buffer)->append((*HEX_ARRAY_)[int32_t(15) & (*text)[i]]);
    }
    return npc(buffer)->toString();
}

int8_tArray* rice::p2p::util::MathUtils::fromHex(::java::lang::String* text)
{
    clinit();
    auto result = new ::int8_tArray(npc(text)->length() / int32_t(2));
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                (*result)[i] = static_cast< int8_t >((static_cast< int8_t >((static_cast< int8_t >(int32_t(240)) & ((getByte(npc(text)->charAt(int32_t(2) * i))) << int32_t(4)))) | getByte(npc(text)->charAt(int32_t(2) * i + int32_t(1)))));

    return result;
}

java::lang::String* rice::p2p::util::MathUtils::toBase64(::int8_tArray* text)
{
    clinit();
    return Base64::encodeBytes(text);
}

int8_tArray* rice::p2p::util::MathUtils::fromBase64(::java::lang::String* text)
{
    clinit();
    return Base64::decode(text);
}

int32_t rice::p2p::util::MathUtils::simpleHash(::int8_tArray* b)
{
    clinit();
    auto hash = int32_t(0);
    for (auto i = int32_t(0); i < npc(b)->length; i++) {
        hash += (*b)[i];
        hash += (hash << int32_t(10));
        hash ^= (hash >> int32_t(6));
    }
    hash += (hash << int32_t(3));
    hash ^= (hash >> int32_t(11));
    hash += (hash << int32_t(15));
    return hash;
}

int8_t rice::p2p::util::MathUtils::getByte(char16_t c)
{
    clinit();
    if((c >= u'0') && (c <= u'9'))
        return static_cast< int8_t >((c - u'0'));
    else if((c >= u'A') && (c <= u'F'))
        return static_cast< int8_t >((int32_t(10) + static_cast< int8_t >((c - u'A'))));
    else if((c >= u'a') && (c <= u'f'))
        return static_cast< int8_t >((int32_t(10) + static_cast< int8_t >((c - u'a'))));
    else
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Could not decode hex character '"_j)->append(c)
            ->append(u"'"_j)->toString());
}

int8_tArray* rice::p2p::util::MathUtils::intToByteArray_(int32_t input)
{
    clinit();
    auto output = new ::int8_tArray(int32_t(4));
    intToByteArray_(input, output, 0);
    return output;
}

void rice::p2p::util::MathUtils::intToByteArray_(int32_t input, ::int8_tArray* output, int32_t offset)
{
    clinit();
    (*output)[offset + int32_t(0)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(24))));
    (*output)[offset + int32_t(1)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(16))));
    (*output)[offset + int32_t(2)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(8))));
    (*output)[offset + int32_t(3)] = static_cast< int8_t >((int32_t(255) & input));
}

int32_t rice::p2p::util::MathUtils::byteArrayToInt(::int8_tArray* input)
{
    clinit();
    return byteArrayToInt(input, 0);
}

int32_t rice::p2p::util::MathUtils::byteArrayToInt(::int8_tArray* input, int32_t offset)
{
    clinit();
    input = correctLength(input, offset + int32_t(4));
    int32_t result;
    result = ((*input)[offset + int32_t(0)] & int32_t(255)) << int32_t(24);
    result |= ((*input)[offset + int32_t(1)] & int32_t(255)) << int32_t(16);
    result |= ((*input)[offset + int32_t(2)] & int32_t(255)) << int32_t(8);
    result |= ((*input)[offset + int32_t(3)] & int32_t(255));
    return result;
}

int16_t rice::p2p::util::MathUtils::byteArrayToShort(::int8_tArray* input)
{
    clinit();
    return byteArrayToShort(input, 0);
}

int16_t rice::p2p::util::MathUtils::byteArrayToShort(::int8_tArray* input, int32_t offset)
{
    clinit();
    input = correctLength(input, offset + int32_t(2));
    int16_t result;
    result = static_cast< int16_t >((((*input)[offset + int32_t(0)] & int32_t(255)) << int32_t(8)));
    result |= static_cast< int16_t >((((*input)[offset + int32_t(1)] & int32_t(255))));
    return result;
}

int8_tArray* rice::p2p::util::MathUtils::longToByteArray_(int64_t input)
{
    clinit();
    auto output = new ::int8_tArray(int32_t(8));
    longToByteArray_(input, output, 0);
    return output;
}

void rice::p2p::util::MathUtils::longToByteArray_(int64_t input, ::int8_tArray* output, int32_t offset)
{
    clinit();
    (*output)[offset + int32_t(0)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(56))));
    (*output)[offset + int32_t(1)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(48))));
    (*output)[offset + int32_t(2)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(40))));
    (*output)[offset + int32_t(3)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(32))));
    (*output)[offset + int32_t(4)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(24))));
    (*output)[offset + int32_t(5)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(16))));
    (*output)[offset + int32_t(6)] = static_cast< int8_t >((int32_t(255) & (input >> int32_t(8))));
    (*output)[offset + int32_t(7)] = static_cast< int8_t >((int32_t(255) & input));
}

int64_t rice::p2p::util::MathUtils::byteArrayToLong(::int8_tArray* input)
{
    clinit();
    return byteArrayToLong(input, 0);
}

int64_t rice::p2p::util::MathUtils::byteArrayToLong(::int8_tArray* input, int32_t offset)
{
    clinit();
    input = correctLength(input, offset + int32_t(8));
    int64_t result;
    result = (static_cast< int64_t >(((*input)[offset + int32_t(0)] & int32_t(255)))) << int32_t(56);
    result |= (static_cast< int64_t >(((*input)[offset + int32_t(1)] & int32_t(255)))) << int32_t(48);
    result |= (static_cast< int64_t >(((*input)[offset + int32_t(2)] & int32_t(255)))) << int32_t(40);
    result |= (static_cast< int64_t >(((*input)[offset + int32_t(3)] & int32_t(255)))) << int32_t(32);
    result |= (static_cast< int64_t >(((*input)[offset + int32_t(4)] & int32_t(255)))) << int32_t(24);
    result |= (static_cast< int64_t >(((*input)[offset + int32_t(5)] & int32_t(255)))) << int32_t(16);
    result |= (static_cast< int64_t >(((*input)[offset + int32_t(6)] & int32_t(255)))) << int32_t(8);
    result |= (static_cast< int64_t >(((*input)[offset + int32_t(7)] & int32_t(255))));
    return result;
}

int8_tArray* rice::p2p::util::MathUtils::correctLength(::int8_tArray* data, int32_t length)
{
    clinit();
    return correctLength(data, 0, length);
}

int8_tArray* rice::p2p::util::MathUtils::correctLength(::int8_tArray* data, int32_t offset, int32_t length)
{
    clinit();
    if(npc(data)->length >= length)
        return data;

    auto result = new ::int8_tArray(length);
    for (auto i = int32_t(0); (i < npc(data)->length) && (i < npc(result)->length); i++) 
                (*result)[i] = (*data)[i];

    return result;
}

int32_t rice::p2p::util::MathUtils::uByteToInt(int8_t b)
{
    clinit();
    return static_cast< int32_t >(b) & int32_t(255);
}

int32_t rice::p2p::util::MathUtils::uShortToInt(int16_t b)
{
    clinit();
    return static_cast< int32_t >(b) & int32_t(65535);
}

int8_t rice::p2p::util::MathUtils::intToUByte(int32_t i)
{
    clinit();
    if((i > 255) || (i < 0))
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"can't convert "_j)->append(i)
            ->append(u" to an unsigned byte"_j)->toString());

    return static_cast< int8_t >(i);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::MathUtils::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.MathUtils", 23);
    return c;
}

void rice::p2p::util::MathUtils::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        HEX_ARRAY_ = new ::char16_tArray({
            u'0'
            , u'1'
            , u'2'
            , u'3'
            , u'4'
            , u'5'
            , u'6'
            , u'7'
            , u'8'
            , u'9'
            , u'a'
            , u'b'
            , u'c'
            , u'd'
            , u'e'
            , u'f'
        });
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::MathUtils::getClass0()
{
    return class_();
}

