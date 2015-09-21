// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/PingMessage.java
#include <org/mpisws/p2p/transport/liveness/PingMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::liveness::PingMessage::PingMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::liveness::PingMessage::PingMessage(int64_t sentTime) 
    : PingMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(sentTime);
}

org::mpisws::p2p::transport::liveness::PingMessage::PingMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : PingMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

void org::mpisws::p2p::transport::liveness::PingMessage::ctor(int64_t sentTime)
{
    super::ctor();
    this->sentTime = sentTime;
}

void org::mpisws::p2p::transport::liveness::PingMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    ctor(npc(buf)->readLong());
}

java::lang::String* org::mpisws::p2p::transport::liveness::PingMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"PingMessage<"_j)->append(sentTime)
        ->append(u">"_j)->toString();
}

void org::mpisws::p2p::transport::liveness::PingMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(sentTime);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::PingMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.PingMessage", 45);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::PingMessage::getClass0()
{
    return class_();
}

