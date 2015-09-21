// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java
#include <rice/p2p/past/gc/GCIdFactory_GCEntrySet.hpp>

#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/past/gc/GCIdFactory_GCEntrySet_iterator_1.hpp>
#include <rice/p2p/past/gc/GCIdFactory.hpp>

rice::p2p::past::gc::GCIdFactory_GCEntrySet::GCIdFactory_GCEntrySet(GCIdFactory *GCIdFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCIdFactory_this(GCIdFactory_this)
{
    clinit();
}

rice::p2p::past::gc::GCIdFactory_GCEntrySet::GCIdFactory_GCEntrySet(GCIdFactory *GCIdFactory_this, ::java::util::Set* set) 
    : GCIdFactory_GCEntrySet(GCIdFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(set);
}

void rice::p2p::past::gc::GCIdFactory_GCEntrySet::ctor(::java::util::Set* set)
{
    super::ctor();
    this->set = set;
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::add(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"add not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::addAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"addAll not supported!"_j);
}

void rice::p2p::past::gc::GCIdFactory_GCEntrySet::clear()
{
    throw new ::java::lang::UnsupportedOperationException(u"clear not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::contains(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"contains not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::containsAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"containsAll not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::equals(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"equals not supported!"_j);
}

int32_t rice::p2p::past::gc::GCIdFactory_GCEntrySet::hashCode()
{
    throw new ::java::lang::UnsupportedOperationException(u"hashCode not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::isEmpty()
{
    throw new ::java::lang::UnsupportedOperationException(u"isEmpty not supported!"_j);
}

java::util::Iterator* rice::p2p::past::gc::GCIdFactory_GCEntrySet::iterator()
{
    return new GCIdFactory_GCEntrySet_iterator_1(this);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::remove(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"remove not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::removeAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"removeAll not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCEntrySet::retainAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"retainAll not supported!"_j);
}

int32_t rice::p2p::past::gc::GCIdFactory_GCEntrySet::size()
{
    throw new ::java::lang::UnsupportedOperationException(u"size not supported!"_j);
}

java::lang::ObjectArray* rice::p2p::past::gc::GCIdFactory_GCEntrySet::toArray_()
{
    throw new ::java::lang::UnsupportedOperationException(u"toArray not supported!"_j);
}

java::lang::ObjectArray* rice::p2p::past::gc::GCIdFactory_GCEntrySet::toArray_(::java::lang::ObjectArray* a)
{
    throw new ::java::lang::UnsupportedOperationException(u"toArray not supported!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCIdFactory_GCEntrySet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCIdFactory.GCEntrySet", 39);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCIdFactory_GCEntrySet::getClass0()
{
    return class_();
}

