// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/SecureRandom_StrongPatternHolder.hpp>

extern void unimplemented_(const char16_t* name);
java::security::SecureRandom_StrongPatternHolder::SecureRandom_StrongPatternHolder(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::regex::Pattern*& java::security::SecureRandom_StrongPatternHolder::pattern()
{
    clinit();
    return pattern_;
}
java::util::regex::Pattern* java::security::SecureRandom_StrongPatternHolder::pattern_;

/* private: void ::java::security::SecureRandom_StrongPatternHolder::ctor() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::SecureRandom_StrongPatternHolder::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.SecureRandom.StrongPatternHolder", 46);
    return c;
}

java::lang::Class* java::security::SecureRandom_StrongPatternHolder::getClass0()
{
    return class_();
}

