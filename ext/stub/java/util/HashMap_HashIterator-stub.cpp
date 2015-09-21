// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashMap_HashIterator.hpp>

#include <java/util/HashMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::HashMap_HashIterator::HashMap_HashIterator(HashMap *HashMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , HashMap_this(HashMap_this)
{
    clinit();
}

java::util::HashMap_HashIterator::HashMap_HashIterator(HashMap *HashMap_this)
    : HashMap_HashIterator(HashMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::HashMap_HashIterator::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashMap_HashIterator::ctor()");
}

bool java::util::HashMap_HashIterator::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::HashMap_HashIterator::hasNext()");
    return 0;
}

java::util::HashMap_Node* java::util::HashMap_HashIterator::nextNode()
{ /* stub */
    unimplemented_(u"java::util::HashMap_Node* java::util::HashMap_HashIterator::nextNode()");
    return 0;
}

void java::util::HashMap_HashIterator::remove()
{ /* stub */
    unimplemented_(u"void java::util::HashMap_HashIterator::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashMap_HashIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashMap.HashIterator", 30);
    return c;
}

java::lang::Class* java::util::HashMap_HashIterator::getClass0()
{
    return class_();
}

