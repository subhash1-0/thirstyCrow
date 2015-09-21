// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_CheckedRandomAccessList.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Collections_CheckedRandomAccessList::Collections_CheckedRandomAccessList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_CheckedRandomAccessList::Collections_CheckedRandomAccessList(List* arg0, ::java::lang::Class* arg1)
    : Collections_CheckedRandomAccessList(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_CheckedRandomAccessList::serialVersionUID;

void ::java::util::Collections_CheckedRandomAccessList::ctor(List* arg0, ::java::lang::Class* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_CheckedRandomAccessList::ctor(List* arg0, ::java::lang::Class* arg1)");
}

java::util::List* java::util::Collections_CheckedRandomAccessList::subList(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"java::util::List* java::util::Collections_CheckedRandomAccessList::subList(int32_t arg0, int32_t arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_CheckedRandomAccessList::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.CheckedRandomAccessList", 45);
    return c;
}

java::lang::Class* java::util::Collections_CheckedRandomAccessList::getClass0()
{
    return class_();
}

