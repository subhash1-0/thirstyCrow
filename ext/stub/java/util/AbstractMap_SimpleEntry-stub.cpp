// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/AbstractMap_SimpleEntry.hpp>

extern void unimplemented_(const char16_t* name);
java::util::AbstractMap_SimpleEntry::AbstractMap_SimpleEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::AbstractMap_SimpleEntry::AbstractMap_SimpleEntry(Map_Entry* arg0)
    : AbstractMap_SimpleEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::AbstractMap_SimpleEntry::AbstractMap_SimpleEntry(::java::lang::Object* arg0, ::java::lang::Object* arg1)
    : AbstractMap_SimpleEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::AbstractMap_SimpleEntry::serialVersionUID;

void ::java::util::AbstractMap_SimpleEntry::ctor(Map_Entry* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::AbstractMap_SimpleEntry::ctor(Map_Entry* arg0)");
}

void ::java::util::AbstractMap_SimpleEntry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::AbstractMap_SimpleEntry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
}

bool java::util::AbstractMap_SimpleEntry::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractMap_SimpleEntry::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::AbstractMap_SimpleEntry::getKey()
{ /* stub */
return key ; /* getter */
}

java::lang::Object* java::util::AbstractMap_SimpleEntry::getValue()
{ /* stub */
return value ; /* getter */
}

int32_t java::util::AbstractMap_SimpleEntry::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::AbstractMap_SimpleEntry::hashCode()");
    return 0;
}

java::lang::Object* java::util::AbstractMap_SimpleEntry::setValue(::java::lang::Object* arg0)
{ /* stub */
}

java::lang::String* java::util::AbstractMap_SimpleEntry::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::AbstractMap_SimpleEntry::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::AbstractMap_SimpleEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.AbstractMap.SimpleEntry", 33);
    return c;
}

java::lang::Class* java::util::AbstractMap_SimpleEntry::getClass0()
{
    return class_();
}

