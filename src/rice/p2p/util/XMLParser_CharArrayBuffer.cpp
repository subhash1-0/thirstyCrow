// Generated from /pastry-2.1/src/rice/p2p/util/XMLParser.java
#include <rice/p2p/util/XMLParser_CharArrayBuffer.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/util/XMLParser.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::XMLParser_CharArrayBuffer::XMLParser_CharArrayBuffer(XMLParser *XMLParser_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , XMLParser_this(XMLParser_this)
{
    clinit();
}

rice::p2p::util::XMLParser_CharArrayBuffer::XMLParser_CharArrayBuffer(XMLParser *XMLParser_this, ::char16_tArray* chars, int32_t length, int32_t off) 
    : XMLParser_CharArrayBuffer(XMLParser_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(chars,length,off);
}

constexpr int32_t rice::p2p::util::XMLParser_CharArrayBuffer::DEFAULT_CAPACITY;

void rice::p2p::util::XMLParser_CharArrayBuffer::ctor(::char16_tArray* chars, int32_t length, int32_t off)
{
    super::ctor();
    this->buffer = new ::char16_tArray(DEFAULT_CAPACITY);
    this->length = 0;
    append(chars, length, off);
}

char16_tArray* rice::p2p::util::XMLParser_CharArrayBuffer::getBuffer()
{
    return buffer;
}

int32_t rice::p2p::util::XMLParser_CharArrayBuffer::getLength()
{
    return length;
}

void rice::p2p::util::XMLParser_CharArrayBuffer::append(::char16_tArray* chars, int32_t off, int32_t len)
{
    while (length + len > npc(buffer)->length) 
                expandBuffer();

    ::java::lang::System::arraycopy(chars, off, buffer, length, len);
    length += len;
}

void rice::p2p::util::XMLParser_CharArrayBuffer::expandBuffer()
{
    auto newbuffer = new ::char16_tArray(npc(buffer)->length * int32_t(2));
    ::java::lang::System::arraycopy(buffer, 0, newbuffer, 0, length);
    this->buffer = newbuffer;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLParser_CharArrayBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLParser.CharArrayBuffer", 39);
    return c;
}

java::lang::Class* rice::p2p::util::XMLParser_CharArrayBuffer::getClass0()
{
    return class_();
}

