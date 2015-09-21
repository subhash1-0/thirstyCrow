// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdRange.java
#include <rice/p2p/multiring/MultiringIdRange.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
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

rice::p2p::multiring::MultiringIdRange::MultiringIdRange(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringIdRange::MultiringIdRange(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdRange* range) 
    : MultiringIdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,range);
}

rice::p2p::multiring::MultiringIdRange::MultiringIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : MultiringIdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

void rice::p2p::multiring::MultiringIdRange::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdRange* range)
{
    super::ctor();
    this->ringId = ringId;
    this->range = range;
    if((dynamic_cast< RingId* >(ringId) != nullptr) || (dynamic_cast< MultiringIdRange* >(range) != nullptr))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Illegal creation of MRIdRange: "_j)->append(static_cast< ::java::lang::Object* >(npc(ringId)->getClass()))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(range)->getClass()))->toString());

}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringIdRange::getRange()
{
    return range;
}

bool rice::p2p::multiring::MultiringIdRange::containsId(::rice::p2p::commonapi::Id* key)
{
    if(dynamic_cast< RingId* >(key) != nullptr) {
        auto rkey = java_cast< RingId* >(key);
        if(!npc(npc(rkey)->getRingId())->equals(this->ringId)) {
            return false;
        }
        return npc(range)->containsId(npc(rkey)->getId());
    } else
        throw new ::java::lang::IllegalArgumentException(u"Cannot test membership for keys other than RingId"_j);
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdRange::getCCWId()
{
    return RingId::build(ringId, npc(range)->getCCWId());
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdRange::getCWId()
{
    return RingId::build(ringId, npc(range)->getCWId());
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringIdRange::getComplementRange()
{
    return new MultiringIdRange(ringId, npc(range)->getComplementRange());
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringIdRange::mergeRange(::rice::p2p::commonapi::IdRange* merge)
{
    return new MultiringIdRange(ringId, npc(range)->mergeRange(npc((java_cast< MultiringIdRange* >(merge)))->getRange()));
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringIdRange::diffRange(::rice::p2p::commonapi::IdRange* diff)
{
    return new MultiringIdRange(ringId, npc(range)->diffRange(npc((java_cast< MultiringIdRange* >(diff)))->getRange()));
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringIdRange::intersectRange(::rice::p2p::commonapi::IdRange* intersect)
{
    return new MultiringIdRange(ringId, npc(range)->intersectRange(npc((java_cast< MultiringIdRange* >(intersect)))->getRange()));
}

bool rice::p2p::multiring::MultiringIdRange::isEmpty()
{
    return npc(range)->isEmpty();
}

bool rice::p2p::multiring::MultiringIdRange::equals(::java::lang::Object* o)
{
    auto other = java_cast< MultiringIdRange* >(o);
    return (npc(npc(other)->getRange())->equals(range) && npc(npc(other)->ringId)->equals(ringId));
}

int32_t rice::p2p::multiring::MultiringIdRange::hashCode()
{
    return (npc(range)->hashCode() + npc(ringId)->hashCode());
}

java::lang::String* rice::p2p::multiring::MultiringIdRange::toString()
{
    return ::java::lang::StringBuilder().append(u"{RingId "_j)->append(static_cast< ::java::lang::Object* >(ringId))
        ->append(u" "_j)
        ->append(npc(range)->toString())
        ->append(u"}"_j)->toString();
}

void rice::p2p::multiring::MultiringIdRange::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    ringId = npc(endpoint)->readId(buf, npc(buf)->readShort());
    range = npc(endpoint)->readIdRange(buf);
}

void rice::p2p::multiring::MultiringIdRange::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(ringId)->getType());
    npc(ringId)->serialize(buf);
    npc(range)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdRange::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringIdRange", 35);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdRange::getClass0()
{
    return class_();
}

