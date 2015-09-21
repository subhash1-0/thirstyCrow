// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Math_RandomNumberGeneratorHolder.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Math_RandomNumberGeneratorHolder::Math_RandomNumberGeneratorHolder(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Random*& java::lang::Math_RandomNumberGeneratorHolder::randomNumberGenerator()
{
    clinit();
    return randomNumberGenerator_;
}
java::util::Random* java::lang::Math_RandomNumberGeneratorHolder::randomNumberGenerator_;

/* private: void ::java::lang::Math_RandomNumberGeneratorHolder::ctor() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Math_RandomNumberGeneratorHolder::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Math.RandomNumberGeneratorHolder", 42);
    return c;
}

java::lang::Class* java::lang::Math_RandomNumberGeneratorHolder::getClass0()
{
    return class_();
}

