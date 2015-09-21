// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Class_AnnotationData.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Class_AnnotationData::Class_AnnotationData(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Class_AnnotationData::Class_AnnotationData(::java::util::Map* arg0, ::java::util::Map* arg1, int32_t arg2)
    : Class_AnnotationData(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::lang::Class_AnnotationData::ctor(::java::util::Map* arg0, ::java::util::Map* arg1, int32_t arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Class_AnnotationData::ctor(::java::util::Map* arg0, ::java::util::Map* arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Class_AnnotationData::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Class.AnnotationData", 30);
    return c;
}

java::lang::Class* java::lang::Class_AnnotationData::getClass0()
{
    return class_();
}

