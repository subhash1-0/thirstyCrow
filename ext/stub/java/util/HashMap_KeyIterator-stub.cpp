// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashMap_KeyIterator.hpp>

#include <java/util/HashMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::HashMap_KeyIterator::HashMap_KeyIterator(HashMap *HashMap_this, const ::default_init_tag&)
    : super(HashMap_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::HashMap_KeyIterator::HashMap_KeyIterator(HashMap *HashMap_this)
    : HashMap_KeyIterator(HashMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::HashMap_KeyIterator::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashMap_KeyIterator::ctor()");
}

java::lang::Object* java::util::HashMap_KeyIterator::next()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::HashMap_KeyIterator::next()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashMap_KeyIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashMap.KeyIterator", 29);
    return c;
}

bool java::util::HashMap_KeyIterator::hasNext()
{
    return HashMap_HashIterator::hasNext();
}

void java::util::HashMap_KeyIterator::remove()
{
    HashMap_HashIterator::remove();
}

java::lang::Class* java::util::HashMap_KeyIterator::getClass0()
{
    return class_();
}

