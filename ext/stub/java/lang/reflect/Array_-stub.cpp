// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/reflect/Array_.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::reflect::Array_::Array_(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}


/* private: void ::java::lang::reflect::Array_::ctor() */
java::lang::Object* java::lang::reflect::Array_::newInstance(::java::lang::Class* arg0, int32_t arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::lang::reflect::Array_::newInstance(::java::lang::Class* arg0, int32_t arg1)");
    return 0;
}

java::lang::Object* java::lang::reflect::Array_::newInstance(::java::lang::Class* arg0, ::int32_tArray* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::lang::reflect::Array_::newInstance(::java::lang::Class* arg0, ::int32_tArray* arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::reflect::Array_::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.reflect.Array", 23);
    return c;
}

java::lang::Class* java::lang::reflect::Array_::getClass0()
{
    return class_();
}

