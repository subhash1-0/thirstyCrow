// Generated from /pastry-2.1/src/rice/p2p/util/Base64.java
#include <rice/p2p/util/Base64_OutputStream.hpp>

#include <java/io/IOException.hpp>
#include <java/io/OutputStream.hpp>
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

rice::p2p::util::Base64_OutputStream::Base64_OutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::Base64_OutputStream::Base64_OutputStream(::java::io::OutputStream* out) 
    : Base64_OutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(out);
}

rice::p2p::util::Base64_OutputStream::Base64_OutputStream(::java::io::OutputStream* out, int32_t options) 
    : Base64_OutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(out,options);
}

void rice::p2p::util::Base64_OutputStream::ctor(::java::io::OutputStream* out)
{
    ctor(out, Base64::ENCODE);
}

void rice::p2p::util::Base64_OutputStream::ctor(::java::io::OutputStream* out, int32_t options)
{
    super::ctor(out);
    this->options = options;
    this->breakLines = (options & Base64::DONT_BREAK_LINES) != Base64::DONT_BREAK_LINES;
    this->encode = (options & Base64::ENCODE) == Base64::ENCODE;
    this->bufferLength = encode ? int32_t(3) : int32_t(4);
    this->buffer = new ::int8_tArray(bufferLength);
    this->position = 0;
    this->lineLength = 0;
    this->suspendEncoding_ = false;
    this->b4 = new ::int8_tArray(int32_t(4));
}

void rice::p2p::util::Base64_OutputStream::write(int32_t theByte) /* throws(java.io.IOException) */
{
    if(suspendEncoding_) {
        npc(super::out)->write(theByte);
        return;
    }
    if(encode) {
        (*buffer)[position++] = static_cast< int8_t >(theByte);
        if(position >= bufferLength) {
            npc(out)->write(Base64::encode3to4(b4, buffer, bufferLength));
            lineLength += 4;
            if(breakLines && lineLength >= Base64::MAX_LINE_LENGTH) {
                npc(out)->write(static_cast< int32_t >(Base64::NEW_LINE));
                lineLength = 0;
            }
            position = 0;
        }
    } else {
        if((*Base64::DECODABET())[theByte & int32_t(127)] > Base64::WHITE_SPACE_ENC) {
            (*buffer)[position++] = static_cast< int8_t >(theByte);
            if(position >= bufferLength) {
                auto len = Base64::decode4to3(buffer, 0, b4, 0);
                npc(out)->write(b4, 0, len);
                position = 0;
            }
        } else if((*Base64::DECODABET())[theByte & int32_t(127)] != Base64::WHITE_SPACE_ENC) {
            throw new ::java::io::IOException(u"Invalid character in Base64 data."_j);
        }
    }
}

void rice::p2p::util::Base64_OutputStream::write(::int8_tArray* theBytes, int32_t off, int32_t len) /* throws(java.io.IOException) */
{
    if(suspendEncoding_) {
        npc(super::out)->write(theBytes, off, len);
        return;
    }
    for (auto i = int32_t(0); i < len; i++) {
        write(static_cast< int32_t >((*theBytes)[off + i]));
    }
}

void rice::p2p::util::Base64_OutputStream::flushBase64() /* throws(java.io.IOException) */
{
    if(position > 0) {
        if(encode) {
            npc(out)->write(Base64::encode3to4(b4, buffer, position));
            position = 0;
        } else {
            throw new ::java::io::IOException(u"Base64 input not properly padded."_j);
        }
    }
}

void rice::p2p::util::Base64_OutputStream::close() /* throws(java.io.IOException) */
{
    flushBase64();
    super::close();
    buffer = nullptr;
    out = nullptr;
}

void rice::p2p::util::Base64_OutputStream::suspendEncoding() /* throws(java.io.IOException) */
{
    flushBase64();
    this->suspendEncoding_ = true;
}

void rice::p2p::util::Base64_OutputStream::resumeEncoding()
{
    this->suspendEncoding_ = false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::Base64_OutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.Base64.OutputStream", 33);
    return c;
}

void rice::p2p::util::Base64_OutputStream::write(::int8_tArray* arg0)
{
    super::write(arg0);
}

java::lang::Class* rice::p2p::util::Base64_OutputStream::getClass0()
{
    return class_();
}

