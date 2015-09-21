// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/AbstractCollection.hpp>

extern void unimplemented_(const char16_t* name);
java::util::AbstractCollection::AbstractCollection(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::AbstractCollection::AbstractCollection()
    : AbstractCollection(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t java::util::AbstractCollection::MAX_ARRAY_SIZE;

void ::java::util::AbstractCollection::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::AbstractCollection::ctor()");
}

bool java::util::AbstractCollection::add(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::add(::java::lang::Object* arg0)");
    return 0;
}

bool java::util::AbstractCollection::addAll(Collection* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::addAll(Collection* arg0)");
    return 0;
}

void java::util::AbstractCollection::clear()
{ /* stub */
    unimplemented_(u"void java::util::AbstractCollection::clear()");
}

bool java::util::AbstractCollection::contains(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::contains(::java::lang::Object* arg0)");
    return 0;
}

bool java::util::AbstractCollection::containsAll(Collection* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::containsAll(Collection* arg0)");
    return 0;
}

/* private: java::lang::ObjectArray* java::util::AbstractCollection::finishToArray_(::java::lang::ObjectArray* arg0, Iterator* arg1) */
/* private: int32_t java::util::AbstractCollection::hugeCapacity(int32_t arg0) */
bool java::util::AbstractCollection::isEmpty()
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::isEmpty()");
    return 0;
}

bool java::util::AbstractCollection::remove(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::remove(::java::lang::Object* arg0)");
    return 0;
}

bool java::util::AbstractCollection::removeAll(Collection* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::removeAll(Collection* arg0)");
    return 0;
}

bool java::util::AbstractCollection::retainAll(Collection* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractCollection::retainAll(Collection* arg0)");
    return 0;
}

java::lang::ObjectArray* java::util::AbstractCollection::toArray_()
{ /* stub */
    unimplemented_(u"java::lang::ObjectArray* java::util::AbstractCollection::toArray_()");
    return 0;
}

java::lang::ObjectArray* java::util::AbstractCollection::toArray_(::java::lang::ObjectArray* arg0)
{ /* stub */
    unimplemented_(u"java::lang::ObjectArray* java::util::AbstractCollection::toArray_(::java::lang::ObjectArray* arg0)");
    return 0;
}

java::lang::String* java::util::AbstractCollection::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::AbstractCollection::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::AbstractCollection::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.AbstractCollection", 28);
    return c;
}

bool java::util::AbstractCollection::equals(::java::lang::Object* arg0)
{
    return Object::equals(arg0);
}

int32_t java::util::AbstractCollection::hashCode()
{
    return Object::hashCode();
}

java::lang::Class* java::util::AbstractCollection::getClass0()
{
    return class_();
}

