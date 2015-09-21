// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/AbstractSequentialList.hpp>

extern void unimplemented_(const char16_t* name);
java::util::AbstractSequentialList::AbstractSequentialList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::AbstractSequentialList::AbstractSequentialList()
    : AbstractSequentialList(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::AbstractSequentialList::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::AbstractSequentialList::ctor()");
}

void java::util::AbstractSequentialList::add(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::util::AbstractSequentialList::add(int32_t arg0, ::java::lang::Object* arg1)");
}

bool java::util::AbstractSequentialList::addAll(int32_t arg0, Collection* arg1)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractSequentialList::addAll(int32_t arg0, Collection* arg1)");
    return 0;
}

java::lang::Object* java::util::AbstractSequentialList::get(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::AbstractSequentialList::get(int32_t arg0)");
    return 0;
}

java::util::Iterator* java::util::AbstractSequentialList::iterator()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::util::AbstractSequentialList::iterator()");
    return 0;
}

java::lang::Object* java::util::AbstractSequentialList::remove(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::AbstractSequentialList::remove(int32_t arg0)");
    return 0;
}

java::lang::Object* java::util::AbstractSequentialList::set(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::AbstractSequentialList::set(int32_t arg0, ::java::lang::Object* arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::AbstractSequentialList::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.AbstractSequentialList", 32);
    return c;
}

bool java::util::AbstractSequentialList::add(::java::lang::Object* arg0)
{
    return super::add(arg0);
}

bool java::util::AbstractSequentialList::addAll(Collection* c)
{
    return super::addAll(c);
}

bool java::util::AbstractSequentialList::remove(::java::lang::Object* o)
{
    return super::remove(o);
}

java::lang::Class* java::util::AbstractSequentialList::getClass0()
{
    return class_();
}

