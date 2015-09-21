// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/MessageInfoImpl.java
#include <org/mpisws/p2p/transport/priority/MessageInfoImpl.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::priority::MessageInfoImpl::MessageInfoImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::priority::MessageInfoImpl::MessageInfoImpl(::java::nio::ByteBuffer* message, ::java::util::Map* options, int32_t priority) 
    : MessageInfoImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(message,options,priority);
}

void org::mpisws::p2p::transport::priority::MessageInfoImpl::ctor(::java::nio::ByteBuffer* message, ::java::util::Map* options, int32_t priority)
{
    super::ctor();
    this->message = message;
    this->options = options;
    this->priority = priority;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::priority::MessageInfoImpl::getMessage()
{
    return message;
}

java::util::Map* org::mpisws::p2p::transport::priority::MessageInfoImpl::getOptions()
{
    return options;
}

int32_t org::mpisws::p2p::transport::priority::MessageInfoImpl::getPriroity()
{
    return priority;
}

int32_t org::mpisws::p2p::transport::priority::MessageInfoImpl::getSize()
{
    return npc(message)->remaining() + int32_t(4);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::MessageInfoImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.MessageInfoImpl", 49);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::MessageInfoImpl::getClass0()
{
    return class_();
}

