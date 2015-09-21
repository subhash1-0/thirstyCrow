// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNodeHandleSet.java
#include <rice/p2p/multiring/MultiringNodeHandleSet.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/multiring/MultiringNodeHandle.hpp>
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

rice::p2p::multiring::MultiringNodeHandleSet::MultiringNodeHandleSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringNodeHandleSet::MultiringNodeHandleSet(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandleSet* set) 
    : MultiringNodeHandleSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,set);
}

rice::p2p::multiring::MultiringNodeHandleSet::MultiringNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : MultiringNodeHandleSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::multiring::MultiringNodeHandleSet::TYPE;

void rice::p2p::multiring::MultiringNodeHandleSet::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandleSet* set)
{
    super::ctor();
    this->ringId = ringId;
    this->set = set;
    if((dynamic_cast< RingId* >(ringId) != nullptr) || (dynamic_cast< MultiringNodeHandleSet* >(set) != nullptr))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Illegal creation of MRNodeHandleSet: "_j)->append(static_cast< ::java::lang::Object* >(npc(ringId)->getClass()))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(set)->getClass()))->toString());

}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::multiring::MultiringNodeHandleSet::getSet()
{
    return set;
}

bool rice::p2p::multiring::MultiringNodeHandleSet::putHandle(::rice::p2p::commonapi::NodeHandle* handle)
{
    return npc(set)->putHandle(npc((java_cast< MultiringNodeHandle* >(handle)))->getHandle());
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringNodeHandleSet::getHandle(::rice::p2p::commonapi::Id* id)
{
    auto handle = npc(set)->getHandle(npc((java_cast< RingId* >(id)))->getId());
    if(handle != nullptr)
        return new MultiringNodeHandle(ringId, handle);
    else
        return nullptr;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringNodeHandleSet::getHandle(int32_t i)
{
    auto handle = npc(set)->getHandle(i);
    if(handle != nullptr)
        return new MultiringNodeHandle(ringId, handle);
    else
        return nullptr;
}

bool rice::p2p::multiring::MultiringNodeHandleSet::memberHandle(::rice::p2p::commonapi::Id* id)
{
    return npc(set)->memberHandle(npc((java_cast< RingId* >(id)))->getId());
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringNodeHandleSet::removeHandle(::rice::p2p::commonapi::Id* id)
{
    auto handle = npc(set)->removeHandle(npc((java_cast< RingId* >(id)))->getId());
    if(handle != nullptr)
        return new MultiringNodeHandle(ringId, handle);
    else
        return nullptr;
}

int32_t rice::p2p::multiring::MultiringNodeHandleSet::size()
{
    return npc(set)->size();
}

int32_t rice::p2p::multiring::MultiringNodeHandleSet::getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */
{
    return npc(set)->getIndexHandle(npc((java_cast< RingId* >(id)))->getId());
}

bool rice::p2p::multiring::MultiringNodeHandleSet::equals(::java::lang::Object* o)
{
    auto other = java_cast< MultiringNodeHandleSet* >(o);
    return (npc(npc(other)->getSet())->equals(set) && npc(npc(other)->ringId)->equals(ringId));
}

int32_t rice::p2p::multiring::MultiringNodeHandleSet::hashCode()
{
    return (npc(set)->hashCode() + npc(ringId)->hashCode());
}

java::lang::String* rice::p2p::multiring::MultiringNodeHandleSet::toString()
{
    return ::java::lang::StringBuilder().append(u"{RingId "_j)->append(static_cast< ::java::lang::Object* >(ringId))
        ->append(u" "_j)
        ->append(npc(set)->toString())
        ->append(u"}"_j)->toString();
}

void rice::p2p::multiring::MultiringNodeHandleSet::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    ringId = npc(endpoint)->readId(buf, npc(buf)->readShort());
    auto type = npc(buf)->readShort();
    set = npc(endpoint)->readNodeHandleSet(buf, type);
}

void rice::p2p::multiring::MultiringNodeHandleSet::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(ringId)->getType());
    npc(ringId)->serialize(buf);
    npc(buf)->writeShort(npc(set)->getType());
    npc(set)->serialize(buf);
}

int16_t rice::p2p::multiring::MultiringNodeHandleSet::getType()
{
    return TYPE;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringNodeHandleSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringNodeHandleSet", 41);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringNodeHandleSet::getClass0()
{
    return class_();
}

