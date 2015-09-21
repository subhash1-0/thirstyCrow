// Generated from /pastry-2.1/src/rice/p2p/glacier/Fragment.java
#include <rice/p2p/glacier/Fragment.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::Fragment::Fragment(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::Fragment::Fragment(int32_t _size) 
    : Fragment(*static_cast< ::default_init_tag* >(0))
{
    ctor(_size);
}

rice::p2p::glacier::Fragment::Fragment(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : Fragment(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

constexpr int64_t rice::p2p::glacier::Fragment::serialVersionUID;

void rice::p2p::glacier::Fragment::ctor(int32_t _size)
{
    super::ctor();
    payload = new ::int8_tArray(_size);
}

int8_tArray* rice::p2p::glacier::Fragment::getPayload()
{
    return payload;
}

void rice::p2p::glacier::Fragment::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
    npc(oos)->defaultWriteObject();
    npc(oos)->writeInt(npc(payload)->length);
    npc(oos)->write(payload);
}

void rice::p2p::glacier::Fragment::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    npc(ois)->defaultReadObject();
    payload = new ::int8_tArray(npc(ois)->readInt());
    npc(ois)->readFully(payload, int32_t(0), npc(payload)->length);
}

void rice::p2p::glacier::Fragment::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    payload = new ::int8_tArray(npc(buf)->readInt());
    npc(buf)->read(payload, 0, npc(payload)->length);
}

void rice::p2p::glacier::Fragment::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(npc(payload)->length);
    npc(buf)->write(payload, 0, npc(payload)->length);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::Fragment::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.Fragment", 25);
    return c;
}

java::lang::Class* rice::p2p::glacier::Fragment::getClass0()
{
    return class_();
}

