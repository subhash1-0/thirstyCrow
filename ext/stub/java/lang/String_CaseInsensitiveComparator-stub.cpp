// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/String_CaseInsensitiveComparator.hpp>

#include <java/lang/String.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::String_CaseInsensitiveComparator::String_CaseInsensitiveComparator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

constexpr int64_t java::lang::String_CaseInsensitiveComparator::serialVersionUID;

/* private: void ::java::lang::String_CaseInsensitiveComparator::ctor() */
int32_t java::lang::String_CaseInsensitiveComparator::compare(String* arg0, String* arg1)
{ /* stub */
    unimplemented_(u"int32_t java::lang::String_CaseInsensitiveComparator::compare(String* arg0, String* arg1)");
    return 0;
}

int32_t java::lang::String_CaseInsensitiveComparator::compare(Object* arg0, Object* arg1)
{ 
    return compare(dynamic_cast< String* >(arg0), dynamic_cast< String* >(arg1));
}

/* private: java::lang::Object* java::lang::String_CaseInsensitiveComparator::readResolve() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::String_CaseInsensitiveComparator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.String.CaseInsensitiveComparator", 42);
    return c;
}

bool java::lang::String_CaseInsensitiveComparator::equals(Object* arg0)
{
    return Object::equals(arg0);
}

java::lang::Class* java::lang::String_CaseInsensitiveComparator::getClass0()
{
    return class_();
}

