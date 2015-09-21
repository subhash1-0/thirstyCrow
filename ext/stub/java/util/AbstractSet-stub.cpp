// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/AbstractSet.hpp>

#include <java/lang/ClassCastException.hpp>
#include <ObjectArray.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

extern void unimplemented_(const char16_t* name);
java::util::AbstractSet::AbstractSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::AbstractSet::AbstractSet()
    : AbstractSet(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::AbstractSet::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::AbstractSet::ctor()");
}

bool java::util::AbstractSet::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractSet::equals(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::AbstractSet::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::AbstractSet::hashCode()");
    return 0;
}

bool java::util::AbstractSet::removeAll(Collection* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractSet::removeAll(Collection* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::AbstractSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.AbstractSet", 21);
    return c;
}

bool java::util::AbstractSet::add(::java::lang::Object* arg0)
{
    return AbstractCollection::add(arg0);
}

bool java::util::AbstractSet::addAll(Collection* arg0)
{
    return AbstractCollection::addAll(arg0);
}

void java::util::AbstractSet::clear()
{
    AbstractCollection::clear();
}

bool java::util::AbstractSet::contains(::java::lang::Object* arg0)
{
    return AbstractCollection::contains(arg0);
}

bool java::util::AbstractSet::containsAll(Collection* arg0)
{
    return AbstractCollection::containsAll(arg0);
}

bool java::util::AbstractSet::isEmpty()
{
    return AbstractCollection::isEmpty();
}

bool java::util::AbstractSet::remove(::java::lang::Object* arg0)
{
    return AbstractCollection::remove(arg0);
}

bool java::util::AbstractSet::retainAll(Collection* arg0)
{
    return AbstractCollection::retainAll(arg0);
}

java::lang::ObjectArray* java::util::AbstractSet::toArray_()
{
    return AbstractCollection::toArray_();
}

java::lang::ObjectArray* java::util::AbstractSet::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(AbstractCollection::toArray_(arg0));
}

java::lang::Class* java::util::AbstractSet::getClass0()
{
    return class_();
}

