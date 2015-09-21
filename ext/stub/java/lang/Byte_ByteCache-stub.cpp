// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Byte_ByteCache.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Byte_ByteCache::Byte_ByteCache(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ByteArray*& java::lang::Byte_ByteCache::cache()
{
    clinit();
    return cache_;
}
java::lang::ByteArray* java::lang::Byte_ByteCache::cache_;

/* private: void ::java::lang::Byte_ByteCache::ctor() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Byte_ByteCache::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Byte.ByteCache", 24);
    return c;
}

java::lang::Class* java::lang::Byte_ByteCache::getClass0()
{
    return class_();
}

