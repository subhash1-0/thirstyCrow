// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Vector_ListItr.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Vector.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

extern void unimplemented_(const char16_t* name);
java::util::Vector_ListItr::Vector_ListItr(Vector *Vector_this, const ::default_init_tag&)
    : super(Vector_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Vector_ListItr::Vector_ListItr(Vector *Vector_this, int32_t arg0)
    : Vector_ListItr(Vector_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::util::Vector_ListItr::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Vector_ListItr::ctor(int32_t arg0)");
}

void java::util::Vector_ListItr::add(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Vector_ListItr::add(::java::lang::Object* arg0)");
}

bool java::util::Vector_ListItr::hasPrevious()
{ /* stub */
    unimplemented_(u"bool java::util::Vector_ListItr::hasPrevious()");
    return 0;
}

int32_t java::util::Vector_ListItr::nextIndex()
{ /* stub */
    unimplemented_(u"int32_t java::util::Vector_ListItr::nextIndex()");
    return 0;
}

java::lang::Object* java::util::Vector_ListItr::previous()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Vector_ListItr::previous()");
    return 0;
}

int32_t java::util::Vector_ListItr::previousIndex()
{ /* stub */
    unimplemented_(u"int32_t java::util::Vector_ListItr::previousIndex()");
    return 0;
}

void java::util::Vector_ListItr::set(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Vector_ListItr::set(::java::lang::Object* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Vector_ListItr::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Vector.ListItr", 24);
    return c;
}

void java::util::Vector_ListItr::forEachRemaining(::java::util::function::Consumer* arg0)
{
    Vector_Itr::forEachRemaining(arg0);
}

bool java::util::Vector_ListItr::hasNext()
{
    return Vector_Itr::hasNext();
}

java::lang::Object* java::util::Vector_ListItr::next()
{
    return java_cast< ::java::lang::Object* >(Vector_Itr::next());
}

void java::util::Vector_ListItr::remove()
{
    Vector_Itr::remove();
}

java::lang::Class* java::util::Vector_ListItr::getClass0()
{
    return class_();
}

