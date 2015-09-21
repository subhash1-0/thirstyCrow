// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdRange.java
#include <rice/p2p/past/gc/GCIdRange.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>

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

rice::p2p::past::gc::GCIdRange::GCIdRange(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCIdRange::GCIdRange(::rice::p2p::commonapi::IdRange* range) 
    : GCIdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(range);
}

rice::p2p::past::gc::GCIdRange::GCIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GCIdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

void rice::p2p::past::gc::GCIdRange::ctor(::rice::p2p::commonapi::IdRange* range)
{
    super::ctor();
    this->range = range;
    if(dynamic_cast< GCIdRange* >(range) != nullptr) {
        throw new ::java::lang::RuntimeException(u"SEVERE ERROR: Illegal creation of GCIdRange with GCIdRange!"_j);
    }
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCIdRange::getRange()
{
    return range;
}

bool rice::p2p::past::gc::GCIdRange::containsId(::rice::p2p::commonapi::Id* key)
{
    return npc(range)->containsId(npc((java_cast< GCId* >(key)))->getId());
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdRange::getCCWId()
{
    return new GCId(npc(range)->getCCWId(), GCPastImpl::DEFAULT_EXPIRATION);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdRange::getCWId()
{
    return new GCId(npc(range)->getCWId(), GCPastImpl::DEFAULT_EXPIRATION);
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCIdRange::getComplementRange()
{
    return new GCIdRange(npc(range)->getComplementRange());
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCIdRange::mergeRange(::rice::p2p::commonapi::IdRange* range)
{
    return new GCIdRange(npc(this->range)->mergeRange(npc((java_cast< GCIdRange* >(range)))->getRange()));
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCIdRange::diffRange(::rice::p2p::commonapi::IdRange* range)
{
    return new GCIdRange(npc(this->range)->diffRange(npc((java_cast< GCIdRange* >(range)))->getRange()));
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCIdRange::intersectRange(::rice::p2p::commonapi::IdRange* range)
{
    return new GCIdRange(npc(this->range)->intersectRange(npc((java_cast< GCIdRange* >(range)))->getRange()));
}

bool rice::p2p::past::gc::GCIdRange::isEmpty()
{
    return npc(range)->isEmpty();
}

java::lang::String* rice::p2p::past::gc::GCIdRange::toString()
{
    return ::java::lang::StringBuilder().append(u"{GC "_j)->append(static_cast< ::java::lang::Object* >(range))
        ->append(u"}"_j)->toString();
}

void rice::p2p::past::gc::GCIdRange::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    range = npc(endpoint)->readIdRange(buf);
}

void rice::p2p::past::gc::GCIdRange::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(range)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCIdRange::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCIdRange", 26);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCIdRange::getClass0()
{
    return class_();
}

