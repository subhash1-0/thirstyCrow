// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/LinkedHashMap_LinkedHashIterator.hpp>

#include <java/util/LinkedHashMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::LinkedHashMap_LinkedHashIterator::LinkedHashMap_LinkedHashIterator(LinkedHashMap *LinkedHashMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , LinkedHashMap_this(LinkedHashMap_this)
{
    clinit();
}

java::util::LinkedHashMap_LinkedHashIterator::LinkedHashMap_LinkedHashIterator(LinkedHashMap *LinkedHashMap_this)
    : LinkedHashMap_LinkedHashIterator(LinkedHashMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::LinkedHashMap_LinkedHashIterator::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedHashMap_LinkedHashIterator::ctor()");
}

bool java::util::LinkedHashMap_LinkedHashIterator::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::LinkedHashMap_LinkedHashIterator::hasNext()");
    return 0;
}

java::util::LinkedHashMap_Entry* java::util::LinkedHashMap_LinkedHashIterator::nextNode()
{ /* stub */
    unimplemented_(u"java::util::LinkedHashMap_Entry* java::util::LinkedHashMap_LinkedHashIterator::nextNode()");
    return 0;
}

void java::util::LinkedHashMap_LinkedHashIterator::remove()
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap_LinkedHashIterator::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::LinkedHashMap_LinkedHashIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.LinkedHashMap.LinkedHashIterator", 42);
    return c;
}

java::lang::Class* java::util::LinkedHashMap_LinkedHashIterator::getClass0()
{
    return class_();
}

