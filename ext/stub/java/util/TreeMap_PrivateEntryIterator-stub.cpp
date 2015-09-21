// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/TreeMap_PrivateEntryIterator.hpp>

#include <java/util/TreeMap.hpp>

extern void unimplemented_(const char16_t* name);
java::util::TreeMap_PrivateEntryIterator::TreeMap_PrivateEntryIterator(TreeMap *TreeMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , TreeMap_this(TreeMap_this)
{
    clinit();
}

java::util::TreeMap_PrivateEntryIterator::TreeMap_PrivateEntryIterator(TreeMap *TreeMap_this, TreeMap_Entry* arg0)
    : TreeMap_PrivateEntryIterator(TreeMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::util::TreeMap_PrivateEntryIterator::ctor(TreeMap_Entry* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::TreeMap_PrivateEntryIterator::ctor(TreeMap_Entry* arg0)");
}

bool java::util::TreeMap_PrivateEntryIterator::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::TreeMap_PrivateEntryIterator::hasNext()");
    return 0;
}

java::util::TreeMap_Entry* java::util::TreeMap_PrivateEntryIterator::nextEntry()
{ /* stub */
    unimplemented_(u"java::util::TreeMap_Entry* java::util::TreeMap_PrivateEntryIterator::nextEntry()");
    return 0;
}

java::util::TreeMap_Entry* java::util::TreeMap_PrivateEntryIterator::prevEntry()
{ /* stub */
    unimplemented_(u"java::util::TreeMap_Entry* java::util::TreeMap_PrivateEntryIterator::prevEntry()");
    return 0;
}

void java::util::TreeMap_PrivateEntryIterator::remove()
{ /* stub */
    unimplemented_(u"void java::util::TreeMap_PrivateEntryIterator::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::TreeMap_PrivateEntryIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.TreeMap.PrivateEntryIterator", 38);
    return c;
}

java::lang::Class* java::util::TreeMap_PrivateEntryIterator::getClass0()
{
    return class_();
}

