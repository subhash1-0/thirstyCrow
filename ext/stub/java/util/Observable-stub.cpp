// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Observable.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Observable::Observable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Observable::Observable()
    : Observable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::util::Observable::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Observable::ctor()");
}

void java::util::Observable::addObserver(Observer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Observable::addObserver(Observer* arg0)");
}

void java::util::Observable::clearChanged()
{ /* stub */
    unimplemented_(u"void java::util::Observable::clearChanged()");
}

int32_t java::util::Observable::countObservers()
{ /* stub */
    unimplemented_(u"int32_t java::util::Observable::countObservers()");
    return 0;
}

void java::util::Observable::deleteObserver(Observer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Observable::deleteObserver(Observer* arg0)");
}

void java::util::Observable::deleteObservers()
{ /* stub */
    unimplemented_(u"void java::util::Observable::deleteObservers()");
}

bool java::util::Observable::hasChanged()
{ /* stub */
    unimplemented_(u"bool java::util::Observable::hasChanged()");
    return 0;
}

void java::util::Observable::notifyObservers()
{ /* stub */
    unimplemented_(u"void java::util::Observable::notifyObservers()");
}

void java::util::Observable::notifyObservers(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Observable::notifyObservers(::java::lang::Object* arg0)");
}

void java::util::Observable::setChanged()
{ /* stub */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Observable::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Observable", 20);
    return c;
}

java::lang::Class* java::util::Observable::getClass0()
{
    return class_();
}

