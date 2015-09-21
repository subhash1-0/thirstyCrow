// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Long_LongCache.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Long_LongCache::Long_LongCache(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::LongArray*& java::lang::Long_LongCache::cache()
{
    clinit();
    return cache_;
}
java::lang::LongArray* java::lang::Long_LongCache::cache_;

/* private: void ::java::lang::Long_LongCache::ctor() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Long_LongCache::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Long.LongCache", 24);
    return c;
}

java::lang::Class* java::lang::Long_LongCache::getClass0()
{
    return class_();
}

