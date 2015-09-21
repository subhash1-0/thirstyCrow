// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashMap_EntryIterator.hpp>

#include <java/util/HashMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::HashMap_EntryIterator::HashMap_EntryIterator(HashMap *HashMap_this, const ::default_init_tag&)
    : super(HashMap_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::HashMap_EntryIterator::HashMap_EntryIterator(HashMap *HashMap_this)
    : HashMap_EntryIterator(HashMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::HashMap_EntryIterator::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashMap_EntryIterator::ctor()");
}

java::util::Map_Entry* java::util::HashMap_EntryIterator::next()
{ /* stub */
    unimplemented_(u"java::util::Map_Entry* java::util::HashMap_EntryIterator::next()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashMap_EntryIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashMap.EntryIterator", 31);
    return c;
}

bool java::util::HashMap_EntryIterator::hasNext()
{
    return HashMap_HashIterator::hasNext();
}

void java::util::HashMap_EntryIterator::remove()
{
    HashMap_HashIterator::remove();
}

java::lang::Class* java::util::HashMap_EntryIterator::getClass0()
{
    return class_();
}

