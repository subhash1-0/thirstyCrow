// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/LinkedHashMap_Entry.hpp>

extern void unimplemented_(const char16_t* name);
java::util::LinkedHashMap_Entry::LinkedHashMap_Entry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::LinkedHashMap_Entry::LinkedHashMap_Entry(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
    : LinkedHashMap_Entry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}


void ::java::util::LinkedHashMap_Entry::ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedHashMap_Entry::ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::LinkedHashMap_Entry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.LinkedHashMap.Entry", 29);
    return c;
}

java::lang::Class* java::util::LinkedHashMap_Entry::getClass0()
{
    return class_();
}

