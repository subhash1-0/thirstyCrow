// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/AbstractMap_SimpleImmutableEntry.hpp>

extern void unimplemented_(const char16_t* name);
java::util::AbstractMap_SimpleImmutableEntry::AbstractMap_SimpleImmutableEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::AbstractMap_SimpleImmutableEntry::AbstractMap_SimpleImmutableEntry(Map_Entry* arg0)
    : AbstractMap_SimpleImmutableEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::AbstractMap_SimpleImmutableEntry::AbstractMap_SimpleImmutableEntry(::java::lang::Object* arg0, ::java::lang::Object* arg1)
    : AbstractMap_SimpleImmutableEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::AbstractMap_SimpleImmutableEntry::serialVersionUID;

void ::java::util::AbstractMap_SimpleImmutableEntry::ctor(Map_Entry* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::AbstractMap_SimpleImmutableEntry::ctor(Map_Entry* arg0)");
}

void ::java::util::AbstractMap_SimpleImmutableEntry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::AbstractMap_SimpleImmutableEntry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
}

bool java::util::AbstractMap_SimpleImmutableEntry::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::AbstractMap_SimpleImmutableEntry::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::AbstractMap_SimpleImmutableEntry::getKey()
{ /* stub */
return key ; /* getter */
}

java::lang::Object* java::util::AbstractMap_SimpleImmutableEntry::getValue()
{ /* stub */
return value ; /* getter */
}

int32_t java::util::AbstractMap_SimpleImmutableEntry::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::AbstractMap_SimpleImmutableEntry::hashCode()");
    return 0;
}

java::lang::Object* java::util::AbstractMap_SimpleImmutableEntry::setValue(::java::lang::Object* arg0)
{ /* stub */
}

java::lang::String* java::util::AbstractMap_SimpleImmutableEntry::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::AbstractMap_SimpleImmutableEntry::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::AbstractMap_SimpleImmutableEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.AbstractMap.SimpleImmutableEntry", 42);
    return c;
}

java::lang::Class* java::util::AbstractMap_SimpleImmutableEntry::getClass0()
{
    return class_();
}

