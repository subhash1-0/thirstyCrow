// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/WeakHashMap_Entry.hpp>

extern void unimplemented_(const char16_t* name);
java::util::WeakHashMap_Entry::WeakHashMap_Entry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::WeakHashMap_Entry::WeakHashMap_Entry(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::ref::ReferenceQueue* arg2, int32_t arg3, WeakHashMap_Entry* arg4)
    : WeakHashMap_Entry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4);
}


void ::java::util::WeakHashMap_Entry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::ref::ReferenceQueue* arg2, int32_t arg3, WeakHashMap_Entry* arg4)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::WeakHashMap_Entry::ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::ref::ReferenceQueue* arg2, int32_t arg3, WeakHashMap_Entry* arg4)");
}

bool java::util::WeakHashMap_Entry::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::WeakHashMap_Entry::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::WeakHashMap_Entry::getKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::WeakHashMap_Entry::getKey()");
    return 0;
}

java::lang::Object* java::util::WeakHashMap_Entry::getValue()
{ /* stub */
return value ; /* getter */
}

int32_t java::util::WeakHashMap_Entry::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::WeakHashMap_Entry::hashCode()");
    return 0;
}

java::lang::Object* java::util::WeakHashMap_Entry::setValue(::java::lang::Object* arg0)
{ /* stub */
}

java::lang::String* java::util::WeakHashMap_Entry::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::WeakHashMap_Entry::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::WeakHashMap_Entry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.WeakHashMap.Entry", 27);
    return c;
}

java::lang::Class* java::util::WeakHashMap_Entry::getClass0()
{
    return class_();
}

