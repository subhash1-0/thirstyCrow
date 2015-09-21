// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNodeHandle.java
#include <rice/p2p/multiring/MultiringNodeHandle.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/multiring/RingId.hpp>

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

rice::p2p::multiring::MultiringNodeHandle::MultiringNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringNodeHandle::MultiringNodeHandle(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandle* handle) 
    : MultiringNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,handle);
}

rice::p2p::multiring::MultiringNodeHandle::MultiringNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : MultiringNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int64_t rice::p2p::multiring::MultiringNodeHandle::serialVersionUID;

void rice::p2p::multiring::MultiringNodeHandle::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandle* handle)
{
    super::ctor();
    this->handle = handle;
    this->ringId = ringId;
    npc(handle)->addObserver(this);
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringNodeHandle::getHandle()
{
    return handle;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNodeHandle::getRingId()
{
    return ringId;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNodeHandle::getId()
{
    return RingId::build(ringId, npc(handle)->getId());
}

bool rice::p2p::multiring::MultiringNodeHandle::isAlive()
{
    return npc(handle)->isAlive();
}

int32_t rice::p2p::multiring::MultiringNodeHandle::proximity()
{
    return npc(handle)->proximity();
}

void rice::p2p::multiring::MultiringNodeHandle::update(::java::util::Observable* o, ::java::lang::Object* obj)
{
    setChanged();
    notifyObservers(obj);
}

java::lang::String* rice::p2p::multiring::MultiringNodeHandle::toString()
{
    return ::java::lang::StringBuilder().append(u"{MNH "_j)->append(npc(handle)->toString())
        ->append(u"@"_j)
        ->append(static_cast< ::java::lang::Object* >(ringId))
        ->append(u"}"_j)->toString();
}

bool rice::p2p::multiring::MultiringNodeHandle::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< MultiringNodeHandle* >(o) != nullptr))
        return false;

    return (npc(npc((java_cast< MultiringNodeHandle* >(o)))->handle)->equals(handle) && npc(npc((java_cast< MultiringNodeHandle* >(o)))->ringId)->equals(ringId));
}

int32_t rice::p2p::multiring::MultiringNodeHandle::hashCode()
{
    return (npc(handle)->hashCode() + npc(ringId)->hashCode());
}

void rice::p2p::multiring::MultiringNodeHandle::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    npc(ois)->defaultReadObject();
    npc(handle)->addObserver(this);
}

bool rice::p2p::multiring::MultiringNodeHandle::checkLiveness()
{
    return npc(handle)->checkLiveness();
}

void rice::p2p::multiring::MultiringNodeHandle::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    ringId = npc(endpoint)->readId(buf, npc(buf)->readShort());
    handle = npc(endpoint)->readNodeHandle(buf);
    npc(handle)->addObserver(this);
}

void rice::p2p::multiring::MultiringNodeHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(ringId)->getType());
    npc(ringId)->serialize(buf);
    npc(handle)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringNodeHandle", 38);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringNodeHandle::getClass0()
{
    return class_();
}

