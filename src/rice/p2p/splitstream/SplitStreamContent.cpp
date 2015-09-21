// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamContent.java
#include <rice/p2p/splitstream/SplitStreamContent.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::splitstream::SplitStreamContent::SplitStreamContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::SplitStreamContent::SplitStreamContent(::int8_tArray* data) 
    : SplitStreamContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(data);
}

rice::p2p::splitstream::SplitStreamContent::SplitStreamContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : SplitStreamContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

constexpr int16_t rice::p2p::splitstream::SplitStreamContent::TYPE;

void rice::p2p::splitstream::SplitStreamContent::ctor(::int8_tArray* data)
{
    super::ctor();
    this->data = data;
}

int8_tArray* rice::p2p::splitstream::SplitStreamContent::getData()
{
    return data;
}

int16_t rice::p2p::splitstream::SplitStreamContent::getType()
{
    return TYPE;
}

void rice::p2p::splitstream::SplitStreamContent::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeInt(npc(data)->length);
    npc(buf)->write(data, 0, npc(data)->length);
}

void rice::p2p::splitstream::SplitStreamContent::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        data = new ::int8_tArray(npc(buf)->readInt());
        npc(buf)->read(data);
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::SplitStreamContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.SplitStreamContent", 39);
    return c;
}

java::lang::Class* rice::p2p::splitstream::SplitStreamContent::getClass0()
{
    return class_();
}

