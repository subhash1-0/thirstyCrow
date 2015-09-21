// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_SynchronizedRandomAccessList.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Collections_SynchronizedRandomAccessList::Collections_SynchronizedRandomAccessList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_SynchronizedRandomAccessList::Collections_SynchronizedRandomAccessList(List* arg0)
    : Collections_SynchronizedRandomAccessList(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::Collections_SynchronizedRandomAccessList::Collections_SynchronizedRandomAccessList(List* arg0, ::java::lang::Object* arg1)
    : Collections_SynchronizedRandomAccessList(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_SynchronizedRandomAccessList::serialVersionUID;

void ::java::util::Collections_SynchronizedRandomAccessList::ctor(List* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedRandomAccessList::ctor(List* arg0)");
}

void ::java::util::Collections_SynchronizedRandomAccessList::ctor(List* arg0, ::java::lang::Object* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedRandomAccessList::ctor(List* arg0, ::java::lang::Object* arg1)");
}

java::util::List* java::util::Collections_SynchronizedRandomAccessList::subList(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"java::util::List* java::util::Collections_SynchronizedRandomAccessList::subList(int32_t arg0, int32_t arg1)");
    return 0;
}

/* private: java::lang::Object* java::util::Collections_SynchronizedRandomAccessList::writeReplace() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_SynchronizedRandomAccessList::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.SynchronizedRandomAccessList", 50);
    return c;
}

java::lang::Class* java::util::Collections_SynchronizedRandomAccessList::getClass0()
{
    return class_();
}

