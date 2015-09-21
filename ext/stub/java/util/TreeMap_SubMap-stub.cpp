// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/TreeMap_SubMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Set.hpp>
#include <java/util/TreeMap.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

extern void unimplemented_(const char16_t* name);
java::util::TreeMap_SubMap::TreeMap_SubMap(TreeMap *TreeMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , TreeMap_this(TreeMap_this)
{
    clinit();
}

constexpr int64_t java::util::TreeMap_SubMap::serialVersionUID;

/* private: void ::java::util::TreeMap_SubMap::ctor() */
java::util::Comparator* java::util::TreeMap_SubMap::comparator()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::TreeMap_SubMap::comparator()");
    return 0;
}

java::util::Set* java::util::TreeMap_SubMap::entrySet()
{ /* stub */
    unimplemented_(u"java::util::Set* java::util::TreeMap_SubMap::entrySet()");
    return 0;
}

java::lang::Object* java::util::TreeMap_SubMap::firstKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::TreeMap_SubMap::firstKey()");
    return 0;
}

java::util::SortedMap* java::util::TreeMap_SubMap::headMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::TreeMap_SubMap::headMap(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::TreeMap_SubMap::lastKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::TreeMap_SubMap::lastKey()");
    return 0;
}

/* private: java::lang::Object* java::util::TreeMap_SubMap::readResolve() */
java::util::SortedMap* java::util::TreeMap_SubMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::TreeMap_SubMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

java::util::SortedMap* java::util::TreeMap_SubMap::tailMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::TreeMap_SubMap::tailMap(::java::lang::Object* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::TreeMap_SubMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.TreeMap.SubMap", 24);
    return c;
}

void java::util::TreeMap_SubMap::clear()
{
    AbstractMap::clear();
}

bool java::util::TreeMap_SubMap::containsKey(::java::lang::Object* arg0)
{
    return AbstractMap::containsKey(arg0);
}

bool java::util::TreeMap_SubMap::containsValue(::java::lang::Object* arg0)
{
    return AbstractMap::containsValue(arg0);
}

bool java::util::TreeMap_SubMap::equals(::java::lang::Object* arg0)
{
    return AbstractMap::equals(arg0);
}

java::lang::Object* java::util::TreeMap_SubMap::get(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(AbstractMap::get(arg0));
}

int32_t java::util::TreeMap_SubMap::hashCode()
{
    return AbstractMap::hashCode();
}

bool java::util::TreeMap_SubMap::isEmpty()
{
    return AbstractMap::isEmpty();
}

java::lang::Object* java::util::TreeMap_SubMap::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(AbstractMap::put(arg0, arg1));
}

void java::util::TreeMap_SubMap::putAll(Map* arg0)
{
    AbstractMap::putAll(arg0);
}

java::lang::Object* java::util::TreeMap_SubMap::remove(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(AbstractMap::remove(arg0));
}

int32_t java::util::TreeMap_SubMap::size()
{
    return AbstractMap::size();
}

java::util::Set* java::util::TreeMap_SubMap::keySet()
{
    return java_cast< Set* >(AbstractMap::keySet());
}

java::util::Collection* java::util::TreeMap_SubMap::values()
{
    return java_cast< Collection* >(AbstractMap::values());
}

bool java::util::TreeMap_SubMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return super::remove(arg0, arg1);
}

java::lang::Class* java::util::TreeMap_SubMap::getClass0()
{
    return class_();
}

