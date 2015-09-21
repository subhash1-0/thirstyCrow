// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Vector_Itr.hpp>

#include <java/util/Vector.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Vector_Itr::Vector_Itr(Vector *Vector_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , Vector_this(Vector_this)
{
    clinit();
}


/* private: void ::java::util::Vector_Itr::ctor() */
void java::util::Vector_Itr::checkForComodification()
{ /* stub */
    unimplemented_(u"void java::util::Vector_Itr::checkForComodification()");
}

void java::util::Vector_Itr::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Vector_Itr::forEachRemaining(::java::util::function::Consumer* arg0)");
}

bool java::util::Vector_Itr::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::Vector_Itr::hasNext()");
    return 0;
}

java::lang::Object* java::util::Vector_Itr::next()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Vector_Itr::next()");
    return 0;
}

void java::util::Vector_Itr::remove()
{ /* stub */
    unimplemented_(u"void java::util::Vector_Itr::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Vector_Itr::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Vector.Itr", 20);
    return c;
}

java::lang::Class* java::util::Vector_Itr::getClass0()
{
    return class_();
}

