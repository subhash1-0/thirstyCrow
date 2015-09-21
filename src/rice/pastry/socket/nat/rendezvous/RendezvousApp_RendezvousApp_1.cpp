// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp_RendezvousApp_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/nat/rendezvous/ByteBufferMsg.hpp>
#include <rice/pastry/socket/nat/rendezvous/OpenChannelMsg.hpp>
#include <rice/pastry/socket/nat/rendezvous/PilotForwardMsg.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <Array.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousApp_RendezvousApp_1::RendezvousApp_RendezvousApp_1(RendezvousApp *RendezvousApp_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousApp_this(RendezvousApp_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::pastry::socket::nat::rendezvous::RendezvousApp_RendezvousApp_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    int8_t version;
    switch (type) {
    case ByteBufferMsg::TYPE:
        version = npc(buf)->readByte();
        if(version == 0) {
            ::rice::p2p::commonapi::NodeHandle* originalSender = npc(RendezvousApp_this->thePastryNode)->readNodeHandle(buf);
            auto length = npc(buf)->readInt();
            auto msg = new ::int8_tArray(length);
            npc(buf)->read(msg);
            return new ByteBufferMsg(::java::nio::ByteBuffer::wrap(msg), originalSender, priority, RendezvousApp_this->getAddress());
        } else {
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown version for ByteBufferMsg: "_j)->append(version)->toString());
        }
    case PilotForwardMsg::TYPE:
        version = npc(buf)->readByte();
        if(version == 0) {
            auto target = java_cast< RendezvousSocketNodeHandle* >(npc(RendezvousApp_this->thePastryNode)->readNodeHandle(buf));
            auto subMsg = java_cast< ByteBufferMsg* >(deserialize(buf, ByteBufferMsg::TYPE, priority, sender));
            return new PilotForwardMsg(RendezvousApp_this->getAddress(), subMsg, target);
        } else {
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown version for PilotForwardMsg: "_j)->append(version)->toString());
        }
    case OpenChannelMsg::TYPE:
        version = npc(buf)->readByte();
        if(version == 0) {
            auto rendezvous = java_cast< RendezvousSocketNodeHandle* >(npc(RendezvousApp_this->thePastryNode)->readNodeHandle(buf));
            auto source = java_cast< RendezvousSocketNodeHandle* >(npc(RendezvousApp_this->thePastryNode)->readNodeHandle(buf));
            auto uid = npc(buf)->readInt();
            return new OpenChannelMsg(RendezvousApp_this->getAddress(), rendezvous, source, uid);
        } else {
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown version for PilotForwardMsg: "_j)->append(version)->toString());
        }
    default:
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type: "_j)->append(type)->toString());
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_RendezvousApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousApp_RendezvousApp_1::getClass0()
{
    return class_();
}

