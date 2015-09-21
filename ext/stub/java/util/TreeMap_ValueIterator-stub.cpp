// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/TreeMap_ValueIterator.hpp>

#include <java/util/TreeMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::TreeMap_ValueIterator::TreeMap_ValueIterator(TreeMap *TreeMap_this, const ::default_init_tag&)
    : super(TreeMap_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::TreeMap_ValueIterator::TreeMap_ValueIterator(TreeMap *TreeMap_this, TreeMap_Entry* arg0)
    : TreeMap_ValueIterator(TreeMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::util::TreeMap_ValueIterator::ctor(TreeMap_Entry* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::TreeMap_ValueIterator::ctor(TreeMap_Entry* arg0)");
}

java::lang::Object* java::util::TreeMap_ValueIterator::next()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::TreeMap_ValueIterator::next()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::TreeMap_ValueIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.TreeMap.ValueIterator", 31);
    return c;
}

java::lang::Class* java::util::TreeMap_ValueIterator::getClass0()
{
    return class_();
}

