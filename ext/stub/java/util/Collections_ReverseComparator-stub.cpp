// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_ReverseComparator.hpp>

#include <java/lang/Comparable.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Collections_ReverseComparator::Collections_ReverseComparator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_ReverseComparator*& java::util::Collections_ReverseComparator::REVERSE_ORDER()
{
    clinit();
    return REVERSE_ORDER_;
}
java::util::Collections_ReverseComparator* java::util::Collections_ReverseComparator::REVERSE_ORDER_;
constexpr int64_t java::util::Collections_ReverseComparator::serialVersionUID;

/* private: void ::java::util::Collections_ReverseComparator::ctor() */
int32_t java::util::Collections_ReverseComparator::compare(::java::lang::Comparable* arg0, ::java::lang::Comparable* arg1)
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_ReverseComparator::compare(::java::lang::Comparable* arg0, ::java::lang::Comparable* arg1)");
    return 0;
}

int32_t java::util::Collections_ReverseComparator::compare(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ 
    return compare(dynamic_cast< ::java::lang::Comparable* >(arg0), dynamic_cast< ::java::lang::Comparable* >(arg1));
}

/* private: java::lang::Object* java::util::Collections_ReverseComparator::readResolve() */
java::util::Comparator* java::util::Collections_ReverseComparator::reversed()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::Collections_ReverseComparator::reversed()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_ReverseComparator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.ReverseComparator", 39);
    return c;
}

bool java::util::Collections_ReverseComparator::equals(::java::lang::Object* arg0)
{
    return Object::equals(arg0);
}

java::lang::Class* java::util::Collections_ReverseComparator::getClass0()
{
    return class_();
}

