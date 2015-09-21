// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/DebugContent.java
#include <rice/p2p/glacier/v2/DebugContent.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/DebugContentHandle.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
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

rice::p2p::glacier::v2::DebugContent::DebugContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::DebugContent::DebugContent(::rice::p2p::commonapi::Id* id, bool isMutable, int64_t version, ::int8_tArray* payload) 
    : DebugContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,isMutable,version,payload);
}

void rice::p2p::glacier::v2::DebugContent::ctor(::rice::p2p::commonapi::Id* id, bool isMutable, int64_t version, ::int8_tArray* payload)
{
    super::ctor();
    myId = id;
    this->isMutable_ = isMutable;
    this->version = version;
    this->payload = payload;
}

rice::p2p::past::PastContent* rice::p2p::glacier::v2::DebugContent::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    if(!isMutable_ || !(dynamic_cast< DebugContent* >(existingContent) != nullptr))
        return this;

    auto dc = java_cast< DebugContent* >(existingContent);
    return (this->version > npc(dc)->version) ? static_cast< ::rice::p2p::past::PastContent* >(this) : static_cast< ::rice::p2p::past::PastContent* >(dc);
}

int64_t rice::p2p::glacier::v2::DebugContent::getVersion()
{
    return version;
}

rice::p2p::past::PastContentHandle* rice::p2p::glacier::v2::DebugContent::getHandle(::rice::p2p::past::Past* local)
{
    return new DebugContentHandle(myId, version, ::rice::p2p::past::gc::GCPast::INFINITY_EXPIRATION, npc(local)->getLocalNodeHandle());
}

rice::p2p::past::gc::GCPastContentHandle* rice::p2p::glacier::v2::DebugContent::getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration)
{
    return new DebugContentHandle(myId, version, expiration, npc(local)->getLocalNodeHandle());
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::DebugContent::getId()
{
    return myId;
}

bool rice::p2p::glacier::v2::DebugContent::isMutable()
{
    return this->isMutable_;
}

int8_tArray* rice::p2p::glacier::v2::DebugContent::getPayload()
{
    return payload;
}

void rice::p2p::glacier::v2::DebugContent::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
    npc(oos)->defaultWriteObject();
    npc(oos)->writeInt(npc(payload)->length);
    npc(oos)->write(payload);
}

void rice::p2p::glacier::v2::DebugContent::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    npc(ois)->defaultReadObject();
    payload = new ::int8_tArray(npc(ois)->readInt());
    npc(ois)->readFully(payload, int32_t(0), npc(payload)->length);
}

rice::p2p::past::gc::GCPastMetadata* rice::p2p::glacier::v2::DebugContent::getMetadata(int64_t expiration)
{
    return new ::rice::p2p::past::gc::GCPastMetadata(expiration);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::DebugContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.DebugContent", 32);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::DebugContent::getClass0()
{
    return class_();
}

