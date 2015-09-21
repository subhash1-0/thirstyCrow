// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Integer_IntegerCache.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Integer_IntegerCache::Integer_IntegerCache(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

bool& java::lang::Integer_IntegerCache::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::lang::Integer_IntegerCache::$assertionsDisabled_;
java::lang::IntegerArray*& java::lang::Integer_IntegerCache::cache()
{
    clinit();
    return cache_;
}
java::lang::IntegerArray* java::lang::Integer_IntegerCache::cache_;
int32_t& java::lang::Integer_IntegerCache::high()
{
    clinit();
    return high_;
}
int32_t java::lang::Integer_IntegerCache::high_;
constexpr int32_t java::lang::Integer_IntegerCache::low;

/* private: void ::java::lang::Integer_IntegerCache::ctor() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Integer_IntegerCache::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Integer.IntegerCache", 30);
    return c;
}

java::lang::Class* java::lang::Integer_IntegerCache::getClass0()
{
    return class_();
}

