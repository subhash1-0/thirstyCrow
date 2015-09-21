// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeRequestMessage.java
#include <rice/pastry/socket/nat/probe/ProbeRequestMessage.hpp>

#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::probe::ProbeRequestMessage::ProbeRequestMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::probe::ProbeRequestMessage::ProbeRequestMessage(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* probeRequestor, int64_t uid, int32_t appAddress) 
    : ProbeRequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(probeRequestor,uid,appAddress);
}

constexpr int16_t rice::pastry::socket::nat::probe::ProbeRequestMessage::TYPE;

void rice::pastry::socket::nat::probe::ProbeRequestMessage::ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* probeRequestor, int64_t uid, int32_t appAddress)
{
    super::ctor(appAddress);
    this->probeRequestor = probeRequestor;
    this->uid = uid;
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* rice::pastry::socket::nat::probe::ProbeRequestMessage::getProbeRequester()
{
    return probeRequestor;
}

int64_t rice::pastry::socket::nat::probe::ProbeRequestMessage::getUID()
{
    return uid;
}

int16_t rice::pastry::socket::nat::probe::ProbeRequestMessage::getType()
{
    return TYPE;
}

void rice::pastry::socket::nat::probe::ProbeRequestMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(probeRequestor)->serialize(buf);
    npc(buf)->writeLong(uid);
}

rice::pastry::socket::nat::probe::ProbeRequestMessage* rice::pastry::socket::nat::probe::ProbeRequestMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t appAddress) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    if(version != 0)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Unknown version: "_j)->append(version)->toString());

    auto addr = ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::build(buf);
    auto uid = npc(buf)->readLong();
    return new ProbeRequestMessage(addr, uid, appAddress);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::probe::ProbeRequestMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.probe.ProbeRequestMessage", 48);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::probe::ProbeRequestMessage::getClass0()
{
    return class_();
}

