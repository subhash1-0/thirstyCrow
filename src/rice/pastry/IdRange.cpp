// Generated from /pastry-2.1/src/rice/pastry/IdRange.java
#include <rice/pastry/IdRange.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>

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

rice::pastry::IdRange::IdRange(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::IdRange::IdRange(Id* ccw, Id* cw) 
    : IdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(ccw,cw);
}

rice::pastry::IdRange::IdRange() 
    : IdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::IdRange::IdRange(bool type) 
    : IdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(type);
}

rice::pastry::IdRange::IdRange(::rice::pastry::IdRange* o) 
    : IdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(o);
}

rice::pastry::IdRange::IdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : IdRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

constexpr int64_t rice::pastry::IdRange::serialVersionUID;

void rice::pastry::IdRange::ctor(Id* ccw, Id* cw)
{
    super::ctor();
    empty = false;
    this->ccw = ccw;
    this->cw = cw;
}

void rice::pastry::IdRange::ctor()
{
    super::ctor();
    empty = true;
    ccw = Id::build();
    cw = ccw;
}

void rice::pastry::IdRange::ctor(bool type)
{
    super::ctor();
    empty = type;
    ccw = Id::build();
    cw = ccw;
}

void rice::pastry::IdRange::ctor(::rice::pastry::IdRange* o)
{
    super::ctor();
    this->empty = npc(o)->empty;
    this->ccw = npc(o)->ccw;
    this->cw = npc(o)->cw;
}

int32_t rice::pastry::IdRange::hashCode()
{
    if(empty)
        return 0;

    if(isFull())
        return 1;

    return npc(ccw)->hashCode() ^ npc(cw)->hashCode();
}

bool rice::pastry::IdRange::equals(::java::lang::Object* obj)
{
    if(obj == nullptr)
        return false;

    if(!(dynamic_cast< ::rice::pastry::IdRange* >(obj) != nullptr))
        return false;

    auto o = java_cast< ::rice::pastry::IdRange* >(obj);
    if(empty && npc(o)->empty)
        return true;

    if(isFull() && npc(o)->isFull())
        return true;

    if(empty == npc(o)->empty && npc(ccw)->equals(npc(o)->ccw) && npc(cw)->equals(npc(o)->cw))
        return true;
    else
        return false;
}

rice::pastry::Id_Distance* rice::pastry::IdRange::size()
{
    if(npc(ccw)->clockwise(cw))
        return npc(ccw)->distance(cw);
    else
        return npc(ccw)->longDistance(cw);
}

bool rice::pastry::IdRange::isEmpty()
{
    return empty;
}

bool rice::pastry::IdRange::isFull()
{
    return npc(ccw)->equals(cw) && !empty;
}

bool rice::pastry::IdRange::isAdjacent(::rice::pastry::IdRange* o)
{
    return (npc(ccw)->equals(npc(o)->cw) || npc(npc(o)->ccw)->equals(cw)) && !empty && !npc(o)->empty&& !isFull()&& !npc(o)->isFull();
}

bool rice::pastry::IdRange::contains(Id* key)
{
    if(npc(ccw)->equals(cw) && !empty)
        return true;
    else
        return npc(key)->isBetween(ccw, cw);
}

rice::pastry::Id* rice::pastry::IdRange::getCCW()
{
    return ccw;
}

rice::pastry::Id* rice::pastry::IdRange::getCW()
{
    return cw;
}

rice::pastry::IdRange* rice::pastry::IdRange::merge(::rice::pastry::IdRange* o)
{
    if(npc(o)->empty || (npc(ccw)->equals(cw) && !empty))
        return this;

    if(empty || (npc(npc(o)->ccw)->equals(npc(o)->cw) && !npc(o)->empty))
        return o;

    auto ccwIn = npc(ccw)->isBetween(npc(o)->ccw, npc(o)->cw) || npc(ccw)->equals(npc(o)->cw);
    auto cwIn = npc(cw)->isBetween(npc(o)->ccw, npc(o)->cw);
    auto occwIn = npc(npc(o)->ccw)->isBetween(ccw, cw) || npc(npc(o)->ccw)->equals(cw);
    auto ocwIn = npc(npc(o)->cw)->isBetween(ccw, cw);
    if(ccwIn && cwIn && occwIn&& ocwIn) {
        return new ::rice::pastry::IdRange(ccw, ccw);
    }
    if(ccwIn) {
        if(cwIn)
            return o;
        else
            return new ::rice::pastry::IdRange(npc(o)->ccw, cw);
    }
    if(cwIn) {
        return new ::rice::pastry::IdRange(ccw, npc(o)->cw);
    }
    if(occwIn) {
        return this;
    }
    return this;
}

rice::pastry::IdRange* rice::pastry::IdRange::complement()
{
    if(npc(ccw)->equals(cw) && !empty)
        return new ::rice::pastry::IdRange();
    else
        return new ::rice::pastry::IdRange(cw, ccw);
}

rice::pastry::IdRange* rice::pastry::IdRange::intersect(::rice::pastry::IdRange* o)
{
    if(empty || npc(o)->empty)
        return new ::rice::pastry::IdRange();

    if(npc(ccw)->equals(cw))
        return o;

    if(npc(npc(o)->ccw)->equals(npc(o)->cw))
        return this;

    auto ccwIn = npc(ccw)->isBetween(npc(o)->ccw, npc(o)->cw);
    auto cwIn = npc(cw)->isBetween(npc(o)->ccw, npc(o)->cw) && !npc(cw)->equals(npc(o)->ccw);
    auto occwIn = npc(npc(o)->ccw)->isBetween(ccw, cw);
    auto ocwIn = npc(npc(o)->cw)->isBetween(ccw, cw) && !npc(npc(o)->cw)->equals(ccw);
    if(ccwIn && cwIn && occwIn&& ocwIn) {
        return new ::rice::pastry::IdRange(ccw, npc(o)->cw);
    }
    if(ccwIn) {
        if(cwIn)
            return this;
        else
            return new ::rice::pastry::IdRange(ccw, npc(o)->cw);
    }
    if(cwIn) {
        return new ::rice::pastry::IdRange(npc(o)->ccw, cw);
    }
    if(occwIn) {
        return o;
    }
    return new ::rice::pastry::IdRange();
}

rice::pastry::IdRange* rice::pastry::IdRange::diff(::rice::pastry::IdRange* o)
{
    auto res = intersect(npc(o)->complement());
    if(npc(res)->isEmpty())
        res = npc(complement())->intersect(o);

    return res;
}

rice::pastry::IdRange* rice::pastry::IdRange::subtract(::rice::pastry::IdRange* o, bool cwPart)
{
    if(!cwPart)
        return intersect(npc(o)->complement());
    else
        return npc(npc(o)->complement())->intersect(this);
}

rice::pastry::IdRange* rice::pastry::IdRange::ccwHalf()
{
    if(empty)
        return new ::rice::pastry::IdRange();

    if(isFull())
        return new ::rice::pastry::IdRange(Id::build(Id::Null()), Id::build(Id::Half()));

    auto newCW = npc(ccw)->add(npc(size())->shift(1, 0, true));
    return new ::rice::pastry::IdRange(ccw, newCW);
}

rice::pastry::IdRange* rice::pastry::IdRange::cwHalf()
{
    if(empty)
        return new ::rice::pastry::IdRange();

    if(isFull())
        return new ::rice::pastry::IdRange(Id::build(Id::Half()), Id::build(Id::Null()));

    auto newCCW = npc(ccw)->add(npc(size())->shift(1, 0, true));
    return new ::rice::pastry::IdRange(newCCW, cw);
}

java::lang::String* rice::pastry::IdRange::toString()
{
    if(empty)
        return u"IdRange: empty"_j;
    else
        return ::java::lang::StringBuilder().append(u"IdRange: from:"_j)->append(static_cast< ::java::lang::Object* >(ccw))
            ->append(u" to:"_j)
            ->append(static_cast< ::java::lang::Object* >(cw))->toString();
}

bool rice::pastry::IdRange::containsId(::rice::p2p::commonapi::Id* key)
{
    return contains(java_cast< Id* >(key));
}

rice::p2p::commonapi::Id* rice::pastry::IdRange::getCCWId()
{
    return getCCW();
}

rice::p2p::commonapi::Id* rice::pastry::IdRange::getCWId()
{
    return getCW();
}

rice::p2p::commonapi::IdRange* rice::pastry::IdRange::getComplementRange()
{
    return complement();
}

rice::p2p::commonapi::IdRange* rice::pastry::IdRange::mergeRange(::rice::p2p::commonapi::IdRange* range)
{
    return merge(java_cast< ::rice::pastry::IdRange* >(range));
}

rice::p2p::commonapi::IdRange* rice::pastry::IdRange::diffRange(::rice::p2p::commonapi::IdRange* range)
{
    return diff(java_cast< ::rice::pastry::IdRange* >(range));
}

rice::p2p::commonapi::IdRange* rice::pastry::IdRange::intersectRange(::rice::p2p::commonapi::IdRange* range)
{
    return intersect(java_cast< ::rice::pastry::IdRange* >(range));
}

void rice::pastry::IdRange::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    cw = Id::build(buf);
    ccw = Id::build(buf);
    empty = npc(buf)->readBoolean();
}

void rice::pastry::IdRange::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(cw)->serialize(buf);
    npc(ccw)->serialize(buf);
    npc(buf)->writeBoolean(empty);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::IdRange::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.IdRange", 19);
    return c;
}

java::lang::Class* rice::pastry::IdRange::getClass0()
{
    return class_();
}

