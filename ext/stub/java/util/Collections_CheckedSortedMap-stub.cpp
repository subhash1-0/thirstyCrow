// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_CheckedSortedMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Set.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

extern void unimplemented_(const char16_t* name);
java::util::Collections_CheckedSortedMap::Collections_CheckedSortedMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_CheckedSortedMap::Collections_CheckedSortedMap(SortedMap* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2)
    : Collections_CheckedSortedMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

constexpr int64_t java::util::Collections_CheckedSortedMap::serialVersionUID;

void ::java::util::Collections_CheckedSortedMap::ctor(SortedMap* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_CheckedSortedMap::ctor(SortedMap* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2)");
}

java::util::Comparator* java::util::Collections_CheckedSortedMap::comparator()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::Collections_CheckedSortedMap::comparator()");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedSortedMap::firstKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedSortedMap::firstKey()");
    return 0;
}

java::util::SortedMap* java::util::Collections_CheckedSortedMap::headMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_CheckedSortedMap::headMap(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedSortedMap::lastKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedSortedMap::lastKey()");
    return 0;
}

java::util::SortedMap* java::util::Collections_CheckedSortedMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_CheckedSortedMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

java::util::SortedMap* java::util::Collections_CheckedSortedMap::tailMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_CheckedSortedMap::tailMap(::java::lang::Object* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_CheckedSortedMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.CheckedSortedMap", 38);
    return c;
}

void java::util::Collections_CheckedSortedMap::clear()
{
    Collections_CheckedMap::clear();
}

java::lang::Object* java::util::Collections_CheckedSortedMap::compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::compute(arg0, arg1));
}

java::lang::Object* java::util::Collections_CheckedSortedMap::computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::computeIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::Collections_CheckedSortedMap::computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::computeIfPresent(arg0, arg1));
}

bool java::util::Collections_CheckedSortedMap::containsKey(::java::lang::Object* arg0)
{
    return Collections_CheckedMap::containsKey(arg0);
}

bool java::util::Collections_CheckedSortedMap::containsValue(::java::lang::Object* arg0)
{
    return Collections_CheckedMap::containsValue(arg0);
}

bool java::util::Collections_CheckedSortedMap::equals(::java::lang::Object* arg0)
{
    return Collections_CheckedMap::equals(arg0);
}

void java::util::Collections_CheckedSortedMap::forEach(::java::util::function::BiConsumer* arg0)
{
    Collections_CheckedMap::forEach(arg0);
}

java::lang::Object* java::util::Collections_CheckedSortedMap::get(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::get(arg0));
}

int32_t java::util::Collections_CheckedSortedMap::hashCode()
{
    return Collections_CheckedMap::hashCode();
}

bool java::util::Collections_CheckedSortedMap::isEmpty()
{
    return Collections_CheckedMap::isEmpty();
}

java::lang::Object* java::util::Collections_CheckedSortedMap::merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::merge(arg0, arg1, arg2));
}

java::lang::Object* java::util::Collections_CheckedSortedMap::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::put(arg0, arg1));
}

void java::util::Collections_CheckedSortedMap::putAll(Map* arg0)
{
    Collections_CheckedMap::putAll(arg0);
}

java::lang::Object* java::util::Collections_CheckedSortedMap::putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::putIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::Collections_CheckedSortedMap::remove(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::remove(arg0));
}

bool java::util::Collections_CheckedSortedMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return Collections_CheckedMap::remove(arg0, arg1);
}

java::lang::Object* java::util::Collections_CheckedSortedMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedMap::replace(arg0, arg1));
}

bool java::util::Collections_CheckedSortedMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2)
{
    return Collections_CheckedMap::replace(arg0, arg1, arg2);
}

void java::util::Collections_CheckedSortedMap::replaceAll(::java::util::function::BiFunction* arg0)
{
    Collections_CheckedMap::replaceAll(arg0);
}

int32_t java::util::Collections_CheckedSortedMap::size()
{
    return Collections_CheckedMap::size();
}

java::util::Set* java::util::Collections_CheckedSortedMap::entrySet()
{
    return java_cast< Set* >(Collections_CheckedMap::entrySet());
}

java::util::Set* java::util::Collections_CheckedSortedMap::keySet()
{
    return java_cast< Set* >(Collections_CheckedMap::keySet());
}

java::util::Collection* java::util::Collections_CheckedSortedMap::values()
{
    return java_cast< Collection* >(Collections_CheckedMap::values());
}

java::lang::Class* java::util::Collections_CheckedSortedMap::getClass0()
{
    return class_();
}

