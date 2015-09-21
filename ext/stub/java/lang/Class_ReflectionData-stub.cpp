// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Class_ReflectionData.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Class_ReflectionData::Class_ReflectionData(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Class_ReflectionData::Class_ReflectionData(int32_t arg0)
    : Class_ReflectionData(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::lang::Class_ReflectionData::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Class_ReflectionData::ctor(int32_t arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Class_ReflectionData::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Class.ReflectionData", 30);
    return c;
}

java::lang::Class* java::lang::Class_ReflectionData::getClass0()
{
    return class_();
}

