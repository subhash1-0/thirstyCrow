// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/TreeMap_Entry.hpp>

extern void unimplemented_(const char16_t* name);
java::util::TreeMap_Entry::TreeMap_Entry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::TreeMap_Entry::TreeMap_Entry(::java::lang::Object* arg0, ::java::lang::Object* arg1, TreeMap_Entry* arg2)
    : TreeMap_Entry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::util::TreeMap_Entry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1, TreeMap_Entry* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::TreeMap_Entry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1, TreeMap_Entry* arg2)");
}

bool java::util::TreeMap_Entry::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::TreeMap_Entry::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::TreeMap_Entry::getKey()
{ /* stub */
return key ; /* getter */
}

java::lang::Object* java::util::TreeMap_Entry::getValue()
{ /* stub */
return value ; /* getter */
}

int32_t java::util::TreeMap_Entry::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::TreeMap_Entry::hashCode()");
    return 0;
}

java::lang::Object* java::util::TreeMap_Entry::setValue(::java::lang::Object* arg0)
{ /* stub */
}

java::lang::String* java::util::TreeMap_Entry::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::TreeMap_Entry::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::TreeMap_Entry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.TreeMap.Entry", 23);
    return c;
}

java::lang::Class* java::util::TreeMap_Entry::getClass0()
{
    return class_();
}

