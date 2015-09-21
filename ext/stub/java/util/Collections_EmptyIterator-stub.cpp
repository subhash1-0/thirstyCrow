// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_EmptyIterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Collections_EmptyIterator::Collections_EmptyIterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_EmptyIterator*& java::util::Collections_EmptyIterator::EMPTY_ITERATOR()
{
    clinit();
    return EMPTY_ITERATOR_;
}
java::util::Collections_EmptyIterator* java::util::Collections_EmptyIterator::EMPTY_ITERATOR_;

/* private: void ::java::util::Collections_EmptyIterator::ctor() */
void java::util::Collections_EmptyIterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Collections_EmptyIterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

bool java::util::Collections_EmptyIterator::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::Collections_EmptyIterator::hasNext()");
    return 0;
}

java::lang::Object* java::util::Collections_EmptyIterator::next()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_EmptyIterator::next()");
    return 0;
}

void java::util::Collections_EmptyIterator::remove()
{ /* stub */
    unimplemented_(u"void java::util::Collections_EmptyIterator::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_EmptyIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.EmptyIterator", 35);
    return c;
}

java::lang::Class* java::util::Collections_EmptyIterator::getClass0()
{
    return class_();
}

