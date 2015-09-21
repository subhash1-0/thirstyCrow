// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashSet.hpp>

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
java::util::HashSet::HashSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::HashSet::HashSet()
    : HashSet(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::HashSet::HashSet(Collection* arg0)
    : HashSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::HashSet::HashSet(int32_t arg0)
    : HashSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::HashSet::HashSet(int32_t arg0, float arg1)
    : HashSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::util::HashSet::HashSet(int32_t arg0, float arg1, bool arg2)
    : HashSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

java::lang::Object*& java::util::HashSet::PRESENT()
{
    clinit();
    return PRESENT_;
}
java::lang::Object* java::util::HashSet::PRESENT_;
constexpr int64_t java::util::HashSet::serialVersionUID;

void ::java::util::HashSet::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashSet::ctor()");
}

void ::java::util::HashSet::ctor(Collection* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashSet::ctor(Collection* arg0)");
}

void ::java::util::HashSet::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashSet::ctor(int32_t arg0)");
}

void ::java::util::HashSet::ctor(int32_t arg0, float arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashSet::ctor(int32_t arg0, float arg1)");
}

void ::java::util::HashSet::ctor(int32_t arg0, float arg1, bool arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashSet::ctor(int32_t arg0, float arg1, bool arg2)");
}

bool java::util::HashSet::add(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::HashSet::add(::java::lang::Object* arg0)");
    return 0;
}

void java::util::HashSet::clear()
{ /* stub */
    unimplemented_(u"void java::util::HashSet::clear()");
}

java::lang::Object* java::util::HashSet::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::HashSet::clone()");
    return 0;
}

bool java::util::HashSet::contains(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::HashSet::contains(::java::lang::Object* arg0)");
    return 0;
}

bool java::util::HashSet::isEmpty()
{ /* stub */
    unimplemented_(u"bool java::util::HashSet::isEmpty()");
    return 0;
}

java::util::Iterator* java::util::HashSet::iterator()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::util::HashSet::iterator()");
    return 0;
}

/* private: void java::util::HashSet::readObject(::java::io::ObjectInputStream* arg0) */
bool java::util::HashSet::remove(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::HashSet::remove(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::HashSet::size()
{ /* stub */
    unimplemented_(u"int32_t java::util::HashSet::size()");
    return 0;
}

java::util::Spliterator* java::util::HashSet::spliterator()
{ /* stub */
    unimplemented_(u"java::util::Spliterator* java::util::HashSet::spliterator()");
    return 0;
}

/* private: void java::util::HashSet::writeObject(::java::io::ObjectOutputStream* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashSet", 17);
    return c;
}

bool java::util::HashSet::addAll(Collection* arg0)
{
    return AbstractCollection::addAll(arg0);
}

bool java::util::HashSet::containsAll(Collection* arg0)
{
    return AbstractCollection::containsAll(arg0);
}

bool java::util::HashSet::equals(::java::lang::Object* arg0)
{
    return AbstractSet::equals(arg0);
}

int32_t java::util::HashSet::hashCode()
{
    return AbstractSet::hashCode();
}

bool java::util::HashSet::removeAll(Collection* arg0)
{
    return AbstractSet::removeAll(arg0);
}

bool java::util::HashSet::retainAll(Collection* arg0)
{
    return AbstractCollection::retainAll(arg0);
}

java::lang::ObjectArray* java::util::HashSet::toArray_()
{
    return AbstractCollection::toArray_();
}

java::lang::ObjectArray* java::util::HashSet::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(AbstractCollection::toArray_(arg0));
}

java::lang::Class* java::util::HashSet::getClass0()
{
    return class_();
}

