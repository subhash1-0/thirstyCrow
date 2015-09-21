// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ClassLoader_ParallelLoaders.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ClassLoader_ParallelLoaders::ClassLoader_ParallelLoaders(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Set*& java::lang::ClassLoader_ParallelLoaders::loaderTypes()
{
    clinit();
    return loaderTypes_;
}
java::util::Set* java::lang::ClassLoader_ParallelLoaders::loaderTypes_;

/* private: void ::java::lang::ClassLoader_ParallelLoaders::ctor() */
bool java::lang::ClassLoader_ParallelLoaders::isRegistered(Class* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::ClassLoader_ParallelLoaders::isRegistered(Class* arg0)");
    return 0;
}

bool java::lang::ClassLoader_ParallelLoaders::register_(Class* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::ClassLoader_ParallelLoaders::register_(Class* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ClassLoader_ParallelLoaders::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ClassLoader.ParallelLoaders", 37);
    return c;
}

java::lang::Class* java::lang::ClassLoader_ParallelLoaders::getClass0()
{
    return class_();
}

