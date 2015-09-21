// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Hashtable_EntrySet.hpp>

#include <java/util/Hashtable.hpp>
#include <java/util/Map_Entry.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Hashtable_EntrySet::Hashtable_EntrySet(Hashtable *Hashtable_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , Hashtable_this(Hashtable_this)
{
    clinit();
}


/* private: void ::java::util::Hashtable_EntrySet::ctor() */
bool java::util::Hashtable_EntrySet::add(Map_Entry* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Hashtable_EntrySet::add(Map_Entry* arg0)");
    return 0;
}

bool java::util::Hashtable_EntrySet::add(::java::lang::Object* arg0)
{ 
    return add(dynamic_cast< Map_Entry* >(arg0));
}

void java::util::Hashtable_EntrySet::clear()
{ /* stub */
    unimplemented_(u"void java::util::Hashtable_EntrySet::clear()");
}

bool java::util::Hashtable_EntrySet::contains(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Hashtable_EntrySet::contains(::java::lang::Object* arg0)");
    return 0;
}

java::util::Iterator* java::util::Hashtable_EntrySet::iterator()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::util::Hashtable_EntrySet::iterator()");
    return 0;
}

bool java::util::Hashtable_EntrySet::remove(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Hashtable_EntrySet::remove(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::Hashtable_EntrySet::size()
{ /* stub */
    unimplemented_(u"int32_t java::util::Hashtable_EntrySet::size()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Hashtable_EntrySet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Hashtable.EntrySet", 28);
    return c;
}

java::lang::Class* java::util::Hashtable_EntrySet::getClass0()
{
    return class_();
}

