// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_SynchronizedSortedMap.hpp>

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
java::util::Collections_SynchronizedSortedMap::Collections_SynchronizedSortedMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_SynchronizedSortedMap::Collections_SynchronizedSortedMap(SortedMap* arg0)
    : Collections_SynchronizedSortedMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::Collections_SynchronizedSortedMap::Collections_SynchronizedSortedMap(SortedMap* arg0, ::java::lang::Object* arg1)
    : Collections_SynchronizedSortedMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_SynchronizedSortedMap::serialVersionUID;

void ::java::util::Collections_SynchronizedSortedMap::ctor(SortedMap* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedSortedMap::ctor(SortedMap* arg0)");
}

void ::java::util::Collections_SynchronizedSortedMap::ctor(SortedMap* arg0, ::java::lang::Object* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedSortedMap::ctor(SortedMap* arg0, ::java::lang::Object* arg1)");
}

java::util::Comparator* java::util::Collections_SynchronizedSortedMap::comparator()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::Collections_SynchronizedSortedMap::comparator()");
    return 0;
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::firstKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_SynchronizedSortedMap::firstKey()");
    return 0;
}

java::util::SortedMap* java::util::Collections_SynchronizedSortedMap::headMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_SynchronizedSortedMap::headMap(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::lastKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_SynchronizedSortedMap::lastKey()");
    return 0;
}

java::util::SortedMap* java::util::Collections_SynchronizedSortedMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_SynchronizedSortedMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

java::util::SortedMap* java::util::Collections_SynchronizedSortedMap::tailMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_SynchronizedSortedMap::tailMap(::java::lang::Object* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_SynchronizedSortedMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.SynchronizedSortedMap", 43);
    return c;
}

void java::util::Collections_SynchronizedSortedMap::clear()
{
    Collections_SynchronizedMap::clear();
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::compute(arg0, arg1));
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::computeIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::computeIfPresent(arg0, arg1));
}

bool java::util::Collections_SynchronizedSortedMap::containsKey(::java::lang::Object* arg0)
{
    return Collections_SynchronizedMap::containsKey(arg0);
}

bool java::util::Collections_SynchronizedSortedMap::containsValue(::java::lang::Object* arg0)
{
    return Collections_SynchronizedMap::containsValue(arg0);
}

bool java::util::Collections_SynchronizedSortedMap::equals(::java::lang::Object* arg0)
{
    return Collections_SynchronizedMap::equals(arg0);
}

void java::util::Collections_SynchronizedSortedMap::forEach(::java::util::function::BiConsumer* arg0)
{
    Collections_SynchronizedMap::forEach(arg0);
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::get(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::get(arg0));
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::getOrDefault(arg0, arg1));
}

int32_t java::util::Collections_SynchronizedSortedMap::hashCode()
{
    return Collections_SynchronizedMap::hashCode();
}

bool java::util::Collections_SynchronizedSortedMap::isEmpty()
{
    return Collections_SynchronizedMap::isEmpty();
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::merge(arg0, arg1, arg2));
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::put(arg0, arg1));
}

void java::util::Collections_SynchronizedSortedMap::putAll(Map* arg0)
{
    Collections_SynchronizedMap::putAll(arg0);
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::putIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::remove(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::remove(arg0));
}

bool java::util::Collections_SynchronizedSortedMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return Collections_SynchronizedMap::remove(arg0, arg1);
}

java::lang::Object* java::util::Collections_SynchronizedSortedMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_SynchronizedMap::replace(arg0, arg1));
}

bool java::util::Collections_SynchronizedSortedMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2)
{
    return Collections_SynchronizedMap::replace(arg0, arg1, arg2);
}

void java::util::Collections_SynchronizedSortedMap::replaceAll(::java::util::function::BiFunction* arg0)
{
    Collections_SynchronizedMap::replaceAll(arg0);
}

int32_t java::util::Collections_SynchronizedSortedMap::size()
{
    return Collections_SynchronizedMap::size();
}

java::util::Set* java::util::Collections_SynchronizedSortedMap::entrySet()
{
    return java_cast< Set* >(Collections_SynchronizedMap::entrySet());
}

java::util::Set* java::util::Collections_SynchronizedSortedMap::keySet()
{
    return java_cast< Set* >(Collections_SynchronizedMap::keySet());
}

java::util::Collection* java::util::Collections_SynchronizedSortedMap::values()
{
    return java_cast< Collection* >(Collections_SynchronizedMap::values());
}

java::lang::Class* java::util::Collections_SynchronizedSortedMap::getClass0()
{
    return class_();
}

