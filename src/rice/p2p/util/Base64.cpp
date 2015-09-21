// Generated from /pastry-2.1/src/rice/p2p/util/Base64.java
#include <rice/p2p/util/Base64.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/io/UnsupportedEncodingException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/zip/GZIPInputStream.hpp>
#include <java/util/zip/GZIPOutputStream.hpp>
#include <rice/p2p/util/Base64_OutputStream.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
}
rice::p2p::util::Base64::Base64(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::Base64::Base64() 
    : Base64(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::p2p::util::Base64::NO_OPTIONS;

constexpr int32_t rice::p2p::util::Base64::ENCODE;

constexpr int32_t rice::p2p::util::Base64::DECODE;

constexpr int32_t rice::p2p::util::Base64::GZIP;

constexpr int32_t rice::p2p::util::Base64::DONT_BREAK_LINES;

constexpr int32_t rice::p2p::util::Base64::MAX_LINE_LENGTH;

constexpr int8_t rice::p2p::util::Base64::EQUALS_SIGN;

constexpr int8_t rice::p2p::util::Base64::NEW_LINE;

java::lang::String*& rice::p2p::util::Base64::PREFERRED_ENCODING()
{
    clinit();
    return PREFERRED_ENCODING_;
}
java::lang::String* rice::p2p::util::Base64::PREFERRED_ENCODING_;

int8_tArray*& rice::p2p::util::Base64::ALPHABET()
{
    clinit();
    return ALPHABET_;
}
int8_tArray* rice::p2p::util::Base64::ALPHABET_;

int8_tArray*& rice::p2p::util::Base64::_NATIVE_ALPHABET()
{
    clinit();
    return _NATIVE_ALPHABET_;
}
int8_tArray* rice::p2p::util::Base64::_NATIVE_ALPHABET_;

int8_tArray*& rice::p2p::util::Base64::DECODABET()
{
    clinit();
    return DECODABET_;
}
int8_tArray* rice::p2p::util::Base64::DECODABET_;

constexpr int8_t rice::p2p::util::Base64::BAD_ENCODING;

constexpr int8_t rice::p2p::util::Base64::WHITE_SPACE_ENC;

constexpr int8_t rice::p2p::util::Base64::EQUALS_SIGN_ENC;

void rice::p2p::util::Base64::ctor()
{
    super::ctor();
}

int8_tArray* rice::p2p::util::Base64::encode3to4(::int8_tArray* threeBytes)
{
    clinit();
    return encode3to4(threeBytes, 3);
}

int8_tArray* rice::p2p::util::Base64::encode3to4(::int8_tArray* threeBytes, int32_t numSigBytes)
{
    clinit();
    auto dest = new ::int8_tArray(int32_t(4));
    encode3to4(threeBytes, 0, numSigBytes, dest, 0);
    return dest;
}

int8_tArray* rice::p2p::util::Base64::encode3to4(::int8_tArray* b4, ::int8_tArray* threeBytes, int32_t numSigBytes)
{
    clinit();
    encode3to4(threeBytes, 0, numSigBytes, b4, 0);
    return b4;
}

int8_tArray* rice::p2p::util::Base64::encode3to4(::int8_tArray* source, int32_t srcOffset, int32_t numSigBytes, ::int8_tArray* destination, int32_t destOffset)
{
    clinit();
    auto inBuff = (numSigBytes > 0 ? (static_cast<int32_t>(static_cast<uint32_t>(((*source)[srcOffset] << int32_t(24))) >> int32_t(8))) : int32_t(0)) | (numSigBytes > 1 ? (static_cast<int32_t>(static_cast<uint32_t>(((*source)[srcOffset + int32_t(1)] << int32_t(24))) >> int32_t(16))) : int32_t(0)) | (numSigBytes > 2 ? (static_cast<int32_t>(static_cast<uint32_t>(((*source)[srcOffset + int32_t(2)] << int32_t(24))) >> int32_t(24))) : int32_t(0));
    switch (numSigBytes) {
    case int32_t(3):
        (*destination)[destOffset] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(18)))];
        (*destination)[destOffset + int32_t(1)] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(12))) & int32_t(63)];
        (*destination)[destOffset + int32_t(2)] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(6))) & int32_t(63)];
        (*destination)[destOffset + int32_t(3)] = (*ALPHABET_)[(inBuff) & int32_t(63)];
        return destination;
    case int32_t(2):
        (*destination)[destOffset] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(18)))];
        (*destination)[destOffset + int32_t(1)] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(12))) & int32_t(63)];
        (*destination)[destOffset + int32_t(2)] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(6))) & int32_t(63)];
        (*destination)[destOffset + int32_t(3)] = EQUALS_SIGN;
        return destination;
    case int32_t(1):
        (*destination)[destOffset] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(18)))];
        (*destination)[destOffset + int32_t(1)] = (*ALPHABET_)[(static_cast<int32_t>(static_cast<uint32_t>(inBuff) >> int32_t(12))) & int32_t(63)];
        (*destination)[destOffset + int32_t(2)] = EQUALS_SIGN;
        (*destination)[destOffset + int32_t(3)] = EQUALS_SIGN;
        return destination;
    default:
        return destination;
    }

}

java::lang::String* rice::p2p::util::Base64::encodeObject(::java::io::Serializable* serializableObject)
{
    clinit();
    return encodeObject(serializableObject, NO_OPTIONS);
}

java::lang::String* rice::p2p::util::Base64::encodeObject(::java::io::Serializable* serializableObject, int32_t options)
{
    clinit();
    ::java::io::ByteArrayOutputStream* baos = nullptr;
    ::java::io::OutputStream* b64os = nullptr;
    ::java::io::ObjectOutputStream* oos = nullptr;
    ::java::util::zip::GZIPOutputStream* gzos = nullptr;
    auto gzip = (options & GZIP);
    auto dontBreakLines = (options & DONT_BREAK_LINES);
    {
        auto finally0 = finally([&] {
            try {
                npc(oos)->close();
            } catch (::java::lang::Exception* e) {
            }
            try {
                npc(gzos)->close();
            } catch (::java::lang::Exception* e) {
            }
            try {
                npc(b64os)->close();
            } catch (::java::lang::Exception* e) {
            }
            try {
                npc(baos)->close();
            } catch (::java::lang::Exception* e) {
            }
        });
        try {
            baos = new ::java::io::ByteArrayOutputStream();
            b64os = new Base64_OutputStream(baos, ENCODE | dontBreakLines);
            if(gzip == GZIP) {
                gzos = new ::java::util::zip::GZIPOutputStream(b64os);
                oos = new ::java::io::ObjectOutputStream(gzos);
            } else
                oos = new ::java::io::ObjectOutputStream(b64os);
            npc(oos)->writeObject(static_cast< ::java::lang::Object* >(serializableObject));
        } catch (::java::io::IOException* e) {
            npc(e)->printStackTrace();
            return nullptr;
        }
    }
    try {
        return new ::java::lang::String(npc(baos)->toByteArray_(), PREFERRED_ENCODING_);
    } catch (::java::io::UnsupportedEncodingException* uue) {
        return new ::java::lang::String(npc(baos)->toByteArray_());
    }
}

java::lang::String* rice::p2p::util::Base64::encodeBytes(::int8_tArray* source)
{
    clinit();
    return encodeBytes(source, 0, npc(source)->length, NO_OPTIONS);
}

java::lang::String* rice::p2p::util::Base64::encodeBytes(::int8_tArray* source, int32_t options)
{
    clinit();
    return encodeBytes(source, 0, npc(source)->length, options);
}

java::lang::String* rice::p2p::util::Base64::encodeBytes(::int8_tArray* source, int32_t off, int32_t len)
{
    clinit();
    return encodeBytes(source, off, len, NO_OPTIONS);
}

java::lang::String* rice::p2p::util::Base64::encodeBytes(::int8_tArray* source, int32_t off, int32_t len, int32_t options)
{
    clinit();
    auto dontBreakLines = (options & DONT_BREAK_LINES);
    auto gzip = (options & GZIP);
    if(gzip == GZIP) {
        ::java::io::ByteArrayOutputStream* baos = nullptr;
        ::java::util::zip::GZIPOutputStream* gzos = nullptr;
        Base64_OutputStream* b64os = nullptr;
        {
            auto finally1 = finally([&] {
                try {
                    npc(gzos)->close();
                } catch (::java::lang::Exception* e) {
                }
                try {
                    npc(b64os)->close();
                } catch (::java::lang::Exception* e) {
                }
                try {
                    npc(baos)->close();
                } catch (::java::lang::Exception* e) {
                }
            });
            try {
                baos = new ::java::io::ByteArrayOutputStream();
                b64os = new Base64_OutputStream(baos, ENCODE | dontBreakLines);
                gzos = new ::java::util::zip::GZIPOutputStream(b64os);
                npc(gzos)->write(source, off, len);
                npc(gzos)->close();
            } catch (::java::io::IOException* e) {
                npc(e)->printStackTrace();
                return nullptr;
            }
        }
        try {
            return new ::java::lang::String(npc(baos)->toByteArray_(), PREFERRED_ENCODING_);
        } catch (::java::io::UnsupportedEncodingException* uue) {
            return new ::java::lang::String(npc(baos)->toByteArray_());
        }
    } else {
        auto breakLines = dontBreakLines == 0;
        auto len43 = len * int32_t(4) / int32_t(3);
        auto outBuff = new ::int8_tArray((len43) + ((len % int32_t(3)) > 0 ? int32_t(4) : int32_t(0)) + (breakLines ? (len43 / MAX_LINE_LENGTH) : int32_t(0)));
        auto d = int32_t(0);
        auto e = int32_t(0);
        auto len2 = len - int32_t(2);
        auto lineLength = int32_t(0);
        for (; d < len2; d += 3, e += 4) {
            encode3to4(source, d + off, 3, outBuff, e);
            lineLength += 4;
            if(breakLines && lineLength == MAX_LINE_LENGTH) {
                (*outBuff)[e + int32_t(4)] = NEW_LINE;
                e++;
                lineLength = 0;
            }
        }
        if(d < len) {
            encode3to4(source, d + off, len - d, outBuff, e);
            e += 4;
        }
        try {
            return new ::java::lang::String(outBuff, int32_t(0), e, PREFERRED_ENCODING_);
        } catch (::java::io::UnsupportedEncodingException* uue) {
            return new ::java::lang::String(outBuff, int32_t(0), e);
        }
    }
}

int8_tArray* rice::p2p::util::Base64::decode4to3(::int8_tArray* fourBytes)
{
    clinit();
    auto outBuff1 = new ::int8_tArray(int32_t(3));
    auto count = decode4to3(fourBytes, 0, outBuff1, 0);
    auto outBuff2 = new ::int8_tArray(count);
    for (auto i = int32_t(0); i < count; i++) 
                (*outBuff2)[i] = (*outBuff1)[i];

    return outBuff2;
}

int32_t rice::p2p::util::Base64::decode4to3(::int8_tArray* source, int32_t srcOffset, ::int8_tArray* destination, int32_t destOffset)
{
    clinit();
    if((*source)[srcOffset + int32_t(2)] == EQUALS_SIGN) {
        auto outBuff = (((*DECODABET_)[(*source)[srcOffset]] & int32_t(255)) << int32_t(18)) | (((*DECODABET_)[(*source)[srcOffset + int32_t(1)]] & int32_t(255)) << int32_t(12));
        (*destination)[destOffset] = static_cast< int8_t >((static_cast<int32_t>(static_cast<uint32_t>(outBuff) >> int32_t(16))));
        return 1;
    } else if((*source)[srcOffset + int32_t(3)] == EQUALS_SIGN) {
        auto outBuff = (((*DECODABET_)[(*source)[srcOffset]] & int32_t(255)) << int32_t(18)) | (((*DECODABET_)[(*source)[srcOffset + int32_t(1)]] & int32_t(255)) << int32_t(12)) | (((*DECODABET_)[(*source)[srcOffset + int32_t(2)]] & int32_t(255)) << int32_t(6));
        (*destination)[destOffset] = static_cast< int8_t >((static_cast<int32_t>(static_cast<uint32_t>(outBuff) >> int32_t(16))));
        (*destination)[destOffset + int32_t(1)] = static_cast< int8_t >((static_cast<int32_t>(static_cast<uint32_t>(outBuff) >> int32_t(8))));
        return 2;
    } else {
        try {
            auto outBuff = (((*DECODABET_)[(*source)[srcOffset]] & int32_t(255)) << int32_t(18)) | (((*DECODABET_)[(*source)[srcOffset + int32_t(1)]] & int32_t(255)) << int32_t(12)) | (((*DECODABET_)[(*source)[srcOffset + int32_t(2)]] & int32_t(255)) << int32_t(6))| (((*DECODABET_)[(*source)[srcOffset + int32_t(3)]] & int32_t(255)));
            (*destination)[destOffset] = static_cast< int8_t >((outBuff >> int32_t(16)));
            (*destination)[destOffset + int32_t(1)] = static_cast< int8_t >((outBuff >> int32_t(8)));
            (*destination)[destOffset + int32_t(2)] = static_cast< int8_t >((outBuff));
            return 3;
        } catch (::java::lang::Exception* e) {
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u""_j)->append((*source)[srcOffset])
                ->append(u": "_j)
                ->append(((*DECODABET_)[(*source)[srcOffset]]))->toString());
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u""_j)->append((*source)[srcOffset + int32_t(1)])
                ->append(u": "_j)
                ->append(((*DECODABET_)[(*source)[srcOffset + int32_t(1)]]))->toString());
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u""_j)->append((*source)[srcOffset + int32_t(2)])
                ->append(u": "_j)
                ->append(((*DECODABET_)[(*source)[srcOffset + int32_t(2)]]))->toString());
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u""_j)->append((*source)[srcOffset + int32_t(3)])
                ->append(u": "_j)
                ->append(((*DECODABET_)[(*source)[srcOffset + int32_t(3)]]))->toString());
            return -int32_t(1);
        }
    }
}

int8_tArray* rice::p2p::util::Base64::decode(::int8_tArray* source, int32_t off, int32_t len)
{
    clinit();
    auto len34 = len * int32_t(3) / int32_t(4);
    auto outBuff = new ::int8_tArray(len34);
    auto outBuffPosn = int32_t(0);
    auto b4 = new ::int8_tArray(int32_t(4));
    auto b4Posn = int32_t(0);
    auto i = int32_t(0);
    int8_t sbiCrop = int32_t(0);
    int8_t sbiDecode = int32_t(0);
    for (i = off; i < off + len; i++) {
        sbiCrop = static_cast< int8_t >(((*source)[i] & int32_t(127)));
        sbiDecode = (*DECODABET_)[sbiCrop];
        if(sbiDecode >= WHITE_SPACE_ENC) {
            if(sbiDecode >= EQUALS_SIGN_ENC) {
                (*b4)[b4Posn++] = sbiCrop;
                if(b4Posn > 3) {
                    outBuffPosn += decode4to3(b4, 0, outBuff, outBuffPosn);
                    b4Posn = 0;
                    if(sbiCrop == EQUALS_SIGN)
                        break;

                }
            }
        } else {
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"Bad Base64 input character at "_j)->append(i)
                ->append(u": "_j)
                ->append((*source)[i])
                ->append(u"(decimal)"_j)->toString());
            return nullptr;
        }
    }
    auto out = new ::int8_tArray(outBuffPosn);
    ::java::lang::System::arraycopy(outBuff, 0, out, 0, outBuffPosn);
    return out;
}

int8_tArray* rice::p2p::util::Base64::decode(::java::lang::String* s)
{
    clinit();
    ::int8_tArray* bytes;
    try {
        bytes = npc(s)->getBytes(PREFERRED_ENCODING_);
    } catch (::java::io::UnsupportedEncodingException* uee) {
        bytes = npc(s)->getBytes();
    }
    bytes = decode(bytes, 0, npc(bytes)->length);
    if(npc(bytes)->length >= 2) {
        auto head = (static_cast< int32_t >((*bytes)[int32_t(0)]) & int32_t(255)) | (((*bytes)[int32_t(1)] << int32_t(8)) & int32_t(65280));
        if(bytes != nullptr && npc(bytes)->length >= 4 && ::java::util::zip::GZIPInputStream::GZIP_MAGIC == head) {
            ::java::io::ByteArrayInputStream* bais = nullptr;
            ::java::util::zip::GZIPInputStream* gzis = nullptr;
            ::java::io::ByteArrayOutputStream* baos = nullptr;
            auto buffer = new ::int8_tArray(int32_t(2048));
            auto length = int32_t(0);
            {
                auto finally2 = finally([&] {
                    try {
                        npc(baos)->close();
                    } catch (::java::lang::Exception* e) {
                    }
                    try {
                        npc(gzis)->close();
                    } catch (::java::lang::Exception* e) {
                    }
                    try {
                        npc(bais)->close();
                    } catch (::java::lang::Exception* e) {
                    }
                });
                try {
                    baos = new ::java::io::ByteArrayOutputStream();
                    bais = new ::java::io::ByteArrayInputStream(bytes);
                    gzis = new ::java::util::zip::GZIPInputStream(bais);
                    while ((length = npc(gzis)->read(buffer)) >= 0) {
                        npc(baos)->write(buffer, int32_t(0), length);
                    }
                    bytes = npc(baos)->toByteArray_();
                } catch (::java::io::IOException* e) {
                }
            }
        }
    }
    return bytes;
}

java::lang::Object* rice::p2p::util::Base64::decodeToObject(::java::lang::String* encodedObject)
{
    clinit();
    auto objBytes = decode(encodedObject);
    ::java::io::ByteArrayInputStream* bais = nullptr;
    ::java::io::ObjectInputStream* ois = nullptr;
    ::java::lang::Object* obj = nullptr;
    {
        auto finally3 = finally([&] {
            try {
                npc(bais)->close();
            } catch (::java::lang::Exception* e) {
            }
            try {
                npc(ois)->close();
            } catch (::java::lang::Exception* e) {
            }
        });
        try {
            bais = new ::java::io::ByteArrayInputStream(objBytes);
            ois = new ::java::io::ObjectInputStream(bais);
            obj = npc(ois)->readObject();
        } catch (::java::io::IOException* e) {
            npc(e)->printStackTrace();
            obj = nullptr;
        } catch (::java::lang::ClassNotFoundException* e) {
            npc(e)->printStackTrace();
            obj = nullptr;
        }
    }
    return obj;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::Base64::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.Base64", 20);
    return c;
}

void rice::p2p::util::Base64::clinit()
{
struct string_init_ {
    string_init_() {
    PREFERRED_ENCODING_ = u"UTF-8"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        _NATIVE_ALPHABET_ = (new ::int8_tArray({
            static_cast< int8_t >(u'A')
            , static_cast< int8_t >(u'B')
            , static_cast< int8_t >(u'C')
            , static_cast< int8_t >(u'D')
            , static_cast< int8_t >(u'E')
            , static_cast< int8_t >(u'F')
            , static_cast< int8_t >(u'G')
            , static_cast< int8_t >(u'H')
            , static_cast< int8_t >(u'I')
            , static_cast< int8_t >(u'J')
            , static_cast< int8_t >(u'K')
            , static_cast< int8_t >(u'L')
            , static_cast< int8_t >(u'M')
            , static_cast< int8_t >(u'N')
            , static_cast< int8_t >(u'O')
            , static_cast< int8_t >(u'P')
            , static_cast< int8_t >(u'Q')
            , static_cast< int8_t >(u'R')
            , static_cast< int8_t >(u'S')
            , static_cast< int8_t >(u'T')
            , static_cast< int8_t >(u'U')
            , static_cast< int8_t >(u'V')
            , static_cast< int8_t >(u'W')
            , static_cast< int8_t >(u'X')
            , static_cast< int8_t >(u'Y')
            , static_cast< int8_t >(u'Z')
            , static_cast< int8_t >(u'a')
            , static_cast< int8_t >(u'b')
            , static_cast< int8_t >(u'c')
            , static_cast< int8_t >(u'd')
            , static_cast< int8_t >(u'e')
            , static_cast< int8_t >(u'f')
            , static_cast< int8_t >(u'g')
            , static_cast< int8_t >(u'h')
            , static_cast< int8_t >(u'i')
            , static_cast< int8_t >(u'j')
            , static_cast< int8_t >(u'k')
            , static_cast< int8_t >(u'l')
            , static_cast< int8_t >(u'm')
            , static_cast< int8_t >(u'n')
            , static_cast< int8_t >(u'o')
            , static_cast< int8_t >(u'p')
            , static_cast< int8_t >(u'q')
            , static_cast< int8_t >(u'r')
            , static_cast< int8_t >(u's')
            , static_cast< int8_t >(u't')
            , static_cast< int8_t >(u'u')
            , static_cast< int8_t >(u'v')
            , static_cast< int8_t >(u'w')
            , static_cast< int8_t >(u'x')
            , static_cast< int8_t >(u'y')
            , static_cast< int8_t >(u'z')
            , static_cast< int8_t >(u'0')
            , static_cast< int8_t >(u'1')
            , static_cast< int8_t >(u'2')
            , static_cast< int8_t >(u'3')
            , static_cast< int8_t >(u'4')
            , static_cast< int8_t >(u'5')
            , static_cast< int8_t >(u'6')
            , static_cast< int8_t >(u'7')
            , static_cast< int8_t >(u'8')
            , static_cast< int8_t >(u'9')
            , static_cast< int8_t >(u'+')
            , static_cast< int8_t >(u'/')
        }));
        {
            ::int8_tArray* j__bytes;
            try {
                j__bytes = (new ::java::lang::String(u"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"_j))->getBytes(PREFERRED_ENCODING_);
            } catch (::java::io::UnsupportedEncodingException* use) {
                j__bytes = _NATIVE_ALPHABET_;
            }
            ALPHABET_ = j__bytes;
        }
        DECODABET_ = (new ::int8_tArray({
            static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(5))
            , static_cast< int8_t >(-int32_t(5))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(5))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(5))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(int32_t(62))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(int32_t(63))
            , static_cast< int8_t >(int32_t(52))
            , static_cast< int8_t >(int32_t(53))
            , static_cast< int8_t >(int32_t(54))
            , static_cast< int8_t >(int32_t(55))
            , static_cast< int8_t >(int32_t(56))
            , static_cast< int8_t >(int32_t(57))
            , static_cast< int8_t >(int32_t(58))
            , static_cast< int8_t >(int32_t(59))
            , static_cast< int8_t >(int32_t(60))
            , static_cast< int8_t >(int32_t(61))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(1))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(int32_t(0))
            , static_cast< int8_t >(int32_t(1))
            , static_cast< int8_t >(int32_t(2))
            , static_cast< int8_t >(int32_t(3))
            , static_cast< int8_t >(int32_t(4))
            , static_cast< int8_t >(int32_t(5))
            , static_cast< int8_t >(int32_t(6))
            , static_cast< int8_t >(int32_t(7))
            , static_cast< int8_t >(int32_t(8))
            , static_cast< int8_t >(int32_t(9))
            , static_cast< int8_t >(int32_t(10))
            , static_cast< int8_t >(int32_t(11))
            , static_cast< int8_t >(int32_t(12))
            , static_cast< int8_t >(int32_t(13))
            , static_cast< int8_t >(int32_t(14))
            , static_cast< int8_t >(int32_t(15))
            , static_cast< int8_t >(int32_t(16))
            , static_cast< int8_t >(int32_t(17))
            , static_cast< int8_t >(int32_t(18))
            , static_cast< int8_t >(int32_t(19))
            , static_cast< int8_t >(int32_t(20))
            , static_cast< int8_t >(int32_t(21))
            , static_cast< int8_t >(int32_t(22))
            , static_cast< int8_t >(int32_t(23))
            , static_cast< int8_t >(int32_t(24))
            , static_cast< int8_t >(int32_t(25))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(int32_t(26))
            , static_cast< int8_t >(int32_t(27))
            , static_cast< int8_t >(int32_t(28))
            , static_cast< int8_t >(int32_t(29))
            , static_cast< int8_t >(int32_t(30))
            , static_cast< int8_t >(int32_t(31))
            , static_cast< int8_t >(int32_t(32))
            , static_cast< int8_t >(int32_t(33))
            , static_cast< int8_t >(int32_t(34))
            , static_cast< int8_t >(int32_t(35))
            , static_cast< int8_t >(int32_t(36))
            , static_cast< int8_t >(int32_t(37))
            , static_cast< int8_t >(int32_t(38))
            , static_cast< int8_t >(int32_t(39))
            , static_cast< int8_t >(int32_t(40))
            , static_cast< int8_t >(int32_t(41))
            , static_cast< int8_t >(int32_t(42))
            , static_cast< int8_t >(int32_t(43))
            , static_cast< int8_t >(int32_t(44))
            , static_cast< int8_t >(int32_t(45))
            , static_cast< int8_t >(int32_t(46))
            , static_cast< int8_t >(int32_t(47))
            , static_cast< int8_t >(int32_t(48))
            , static_cast< int8_t >(int32_t(49))
            , static_cast< int8_t >(int32_t(50))
            , static_cast< int8_t >(int32_t(51))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
            , static_cast< int8_t >(-int32_t(9))
        }));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::Base64::getClass0()
{
    return class_();
}

