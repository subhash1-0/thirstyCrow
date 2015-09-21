// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashMap_ValueIterator.hpp>

#include <java/util/HashMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::HashMap_ValueIterator::HashMap_ValueIterator(HashMap *HashMap_this, const ::default_init_tag&)
    : super(HashMap_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::HashMap_ValueIterator::HashMap_ValueIterator(HashMap *HashMap_this)
    : HashMap_ValueIterator(HashMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::HashMap_ValueIterator::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashMap_ValueIterator::ctor()");
}

java::lang::Object* java::util::HashMap_ValueIterator::next()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::HashMap_ValueIterator::next()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashMap_ValueIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashMap.ValueIterator", 31);
    return c;
}

bool java::util::HashMap_ValueIterator::hasNext()
{
    return HashMap_HashIterator::hasNext();
}

void java::util::HashMap_ValueIterator::remove()
{
    HashMap_HashIterator::remove();
}

java::lang::Class* java::util::HashMap_ValueIterator::getClass0()
{
    return class_();
}

