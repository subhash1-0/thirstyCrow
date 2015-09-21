// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_UnmodifiableSortedMap.hpp>

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
java::util::Collections_UnmodifiableSortedMap::Collections_UnmodifiableSortedMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_UnmodifiableSortedMap::Collections_UnmodifiableSortedMap(SortedMap* arg0)
    : Collections_UnmodifiableSortedMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::util::Collections_UnmodifiableSortedMap::serialVersionUID;

void ::java::util::Collections_UnmodifiableSortedMap::ctor(SortedMap* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_UnmodifiableSortedMap::ctor(SortedMap* arg0)");
}

java::util::Comparator* java::util::Collections_UnmodifiableSortedMap::comparator()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::Collections_UnmodifiableSortedMap::comparator()");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::firstKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableSortedMap::firstKey()");
    return 0;
}

java::util::SortedMap* java::util::Collections_UnmodifiableSortedMap::headMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_UnmodifiableSortedMap::headMap(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::lastKey()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableSortedMap::lastKey()");
    return 0;
}

java::util::SortedMap* java::util::Collections_UnmodifiableSortedMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_UnmodifiableSortedMap::subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

java::util::SortedMap* java::util::Collections_UnmodifiableSortedMap::tailMap(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedMap* java::util::Collections_UnmodifiableSortedMap::tailMap(::java::lang::Object* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_UnmodifiableSortedMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.UnmodifiableSortedMap", 43);
    return c;
}

void java::util::Collections_UnmodifiableSortedMap::clear()
{
    Collections_UnmodifiableMap::clear();
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::compute(arg0, arg1));
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::computeIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::computeIfPresent(arg0, arg1));
}

bool java::util::Collections_UnmodifiableSortedMap::containsKey(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableMap::containsKey(arg0);
}

bool java::util::Collections_UnmodifiableSortedMap::containsValue(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableMap::containsValue(arg0);
}

bool java::util::Collections_UnmodifiableSortedMap::equals(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableMap::equals(arg0);
}

void java::util::Collections_UnmodifiableSortedMap::forEach(::java::util::function::BiConsumer* arg0)
{
    Collections_UnmodifiableMap::forEach(arg0);
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::get(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::get(arg0));
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::getOrDefault(arg0, arg1));
}

int32_t java::util::Collections_UnmodifiableSortedMap::hashCode()
{
    return Collections_UnmodifiableMap::hashCode();
}

bool java::util::Collections_UnmodifiableSortedMap::isEmpty()
{
    return Collections_UnmodifiableMap::isEmpty();
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::merge(arg0, arg1, arg2));
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::put(arg0, arg1));
}

void java::util::Collections_UnmodifiableSortedMap::putAll(Map* arg0)
{
    Collections_UnmodifiableMap::putAll(arg0);
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::putIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::remove(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::remove(arg0));
}

bool java::util::Collections_UnmodifiableSortedMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return Collections_UnmodifiableMap::remove(arg0, arg1);
}

java::lang::Object* java::util::Collections_UnmodifiableSortedMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableMap::replace(arg0, arg1));
}

bool java::util::Collections_UnmodifiableSortedMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2)
{
    return Collections_UnmodifiableMap::replace(arg0, arg1, arg2);
}

void java::util::Collections_UnmodifiableSortedMap::replaceAll(::java::util::function::BiFunction* arg0)
{
    Collections_UnmodifiableMap::replaceAll(arg0);
}

int32_t java::util::Collections_UnmodifiableSortedMap::size()
{
    return Collections_UnmodifiableMap::size();
}

java::util::Set* java::util::Collections_UnmodifiableSortedMap::entrySet()
{
    return java_cast< Set* >(Collections_UnmodifiableMap::entrySet());
}

java::util::Set* java::util::Collections_UnmodifiableSortedMap::keySet()
{
    return java_cast< Set* >(Collections_UnmodifiableMap::keySet());
}

java::util::Collection* java::util::Collections_UnmodifiableSortedMap::values()
{
    return java_cast< Collection* >(Collections_UnmodifiableMap::values());
}

java::lang::Class* java::util::Collections_UnmodifiableSortedMap::getClass0()
{
    return class_();
}

