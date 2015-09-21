// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java
#include <rice/p2p/multiring/MultiringIdFactory_MultiringEntrySet.hpp>

#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/multiring/MultiringIdFactory_MultiringEntrySet_iterator_1.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>

rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::MultiringIdFactory_MultiringEntrySet(MultiringIdFactory *MultiringIdFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringIdFactory_this(MultiringIdFactory_this)
{
    clinit();
}

rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::MultiringIdFactory_MultiringEntrySet(MultiringIdFactory *MultiringIdFactory_this, ::java::util::Set* set) 
    : MultiringIdFactory_MultiringEntrySet(MultiringIdFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(set);
}

void rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::ctor(::java::util::Set* set)
{
    super::ctor();
    this->set = set;
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::add(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"add not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::addAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"addAll not supported!"_j);
}

void rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::clear()
{
    throw new ::java::lang::UnsupportedOperationException(u"clear not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::contains(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"contains not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::containsAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"containsAll not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::equals(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"equals not supported!"_j);
}

int32_t rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::hashCode()
{
    throw new ::java::lang::UnsupportedOperationException(u"hashCode not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::isEmpty()
{
    throw new ::java::lang::UnsupportedOperationException(u"isEmpty not supported!"_j);
}

java::util::Iterator* rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::iterator()
{
    return new MultiringIdFactory_MultiringEntrySet_iterator_1(this);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::remove(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"remove not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::removeAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"removeAll not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::retainAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"retainAll not supported!"_j);
}

int32_t rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::size()
{
    throw new ::java::lang::UnsupportedOperationException(u"size not supported!"_j);
}

java::lang::ObjectArray* rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::toArray_()
{
    throw new ::java::lang::UnsupportedOperationException(u"toArray not supported!"_j);
}

java::lang::ObjectArray* rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::toArray_(::java::lang::ObjectArray* a)
{
    throw new ::java::lang::UnsupportedOperationException(u"toArray not supported!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringIdFactory.MultiringEntrySet", 55);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet::getClass0()
{
    return class_();
}

