// Generated from /pastry-2.1/src/rice/p2p/util/Base64.java
#include <rice/p2p/util/Base64_InputStream.hpp>

#include <java/io/IOException.hpp>
#include <java/io/InputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/util/Base64.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::Base64_InputStream::Base64_InputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::Base64_InputStream::Base64_InputStream(::java::io::InputStream* in) 
    : Base64_InputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(in);
}

rice::p2p::util::Base64_InputStream::Base64_InputStream(::java::io::InputStream* in, int32_t options) 
    : Base64_InputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(in,options);
}

void rice::p2p::util::Base64_InputStream::ctor(::java::io::InputStream* in)
{
    ctor(in, Base64::DECODE);
}

void rice::p2p::util::Base64_InputStream::ctor(::java::io::InputStream* in, int32_t options)
{
    super::ctor(in);
    this->options = options;
    this->breakLines = (options & Base64::DONT_BREAK_LINES) != Base64::DONT_BREAK_LINES;
    this->encode = (options & Base64::ENCODE) == Base64::ENCODE;
    this->bufferLength = encode ? int32_t(4) : int32_t(3);
    this->buffer = new ::int8_tArray(bufferLength);
    this->position = -int32_t(1);
    this->lineLength = 0;
}

int32_t rice::p2p::util::Base64_InputStream::read() /* throws(java.io.IOException) */
{
    if(position < 0) {
        if(encode) {
            auto b3 = new ::int8_tArray(int32_t(3));
            auto numBinaryBytes = int32_t(0);
            for (auto i = int32_t(0); i < 3; i++) {
                try {
                    auto b = npc(in.load())->read();
                    if(b >= 0) {
                        (*b3)[i] = static_cast< int8_t >(b);
                        numBinaryBytes++;
                    }
                } catch (::java::io::IOException* e) {
                    if(i == 0)
                        throw e;

                }
            }
            if(numBinaryBytes > 0) {
                Base64::encode3to4(b3, 0, numBinaryBytes, buffer, 0);
                position = 0;
                numSigBytes = 4;
            } else {
                return -int32_t(1);
            }
        } else {
            auto b4 = new ::int8_tArray(int32_t(4));
            auto i = int32_t(0);
            for (i = 0; i < 4; i++) {
                auto b = int32_t(0);
                do {
                    b = npc(in.load())->read();
                } while (b >= 0 && (*Base64::DECODABET())[b & int32_t(127)] <= Base64::WHITE_SPACE_ENC);
                if(b < 0)
                    break;

                (*b4)[i] = static_cast< int8_t >(b);
            }
            if(i == 4) {
                numSigBytes = Base64::decode4to3(b4, 0, buffer, 0);
                position = 0;
            } else if(i == 0) {
                return -int32_t(1);
            } else {
                throw new ::java::io::IOException(u"Improperly padded Base64 input."_j);
            }
        }
    }
    if(position >= 0) {
        if(position >= numSigBytes)
            return -int32_t(1);

        if(encode && breakLines && lineLength >= Base64::MAX_LINE_LENGTH) {
            lineLength = 0;
            return u'\u000a';
        } else {
            lineLength++;
            int32_t b = (*buffer)[position++];
            if(position >= bufferLength)
                position = -int32_t(1);

            return b & int32_t(255);
        }
    } else {
        throw new ::java::io::IOException(u"Error in Base64 code reading stream."_j);
    }
}

int32_t rice::p2p::util::Base64_InputStream::read(::int8_tArray* dest, int32_t off, int32_t len) /* throws(java.io.IOException) */
{
    int32_t i;
    int32_t b;
    for (i = 0; i < len; i++) {
        b = read();
        if(b >= 0)
            (*dest)[off + i] = static_cast< int8_t >(b);
        else if(i == 0)
            return -int32_t(1);
        else
            break;
    }
    return i;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::Base64_InputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.Base64.InputStream", 32);
    return c;
}

int32_t rice::p2p::util::Base64_InputStream::read(::int8_tArray* arg0)
{
    return super::read(arg0);
}

java::lang::Class* rice::p2p::util::Base64_InputStream::getClass0()
{
    return class_();
}

