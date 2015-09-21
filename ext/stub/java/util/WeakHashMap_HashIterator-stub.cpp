// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/WeakHashMap_HashIterator.hpp>

#include <java/util/WeakHashMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::WeakHashMap_HashIterator::WeakHashMap_HashIterator(WeakHashMap *WeakHashMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , WeakHashMap_this(WeakHashMap_this)
{
    clinit();
}

java::util::WeakHashMap_HashIterator::WeakHashMap_HashIterator(WeakHashMap *WeakHashMap_this)
    : WeakHashMap_HashIterator(WeakHashMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::WeakHashMap_HashIterator::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::WeakHashMap_HashIterator::ctor()");
}

bool java::util::WeakHashMap_HashIterator::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::WeakHashMap_HashIterator::hasNext()");
    return 0;
}

java::util::WeakHashMap_Entry* java::util::WeakHashMap_HashIterator::nextEntry()
{ /* stub */
    unimplemented_(u"java::util::WeakHashMap_Entry* java::util::WeakHashMap_HashIterator::nextEntry()");
    return 0;
}

void java::util::WeakHashMap_HashIterator::remove()
{ /* stub */
    unimplemented_(u"void java::util::WeakHashMap_HashIterator::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::WeakHashMap_HashIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.WeakHashMap.HashIterator", 34);
    return c;
}

java::lang::Class* java::util::WeakHashMap_HashIterator::getClass0()
{
    return class_();
}

