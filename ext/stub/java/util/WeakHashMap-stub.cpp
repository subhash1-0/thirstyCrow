// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/WeakHashMap.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace ref
        {
typedef ::SubArray< ::java::lang::ref::Reference, ::java::lang::ObjectArray > ReferenceArray;
typedef ::SubArray< ::java::lang::ref::WeakReference, ReferenceArray > WeakReferenceArray;
        } // ref
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Map_Entry, ::java::lang::ObjectArray > Map_EntryArray;
typedef ::SubArray< ::java::util::WeakHashMap_Entry, ::java::lang::ref::WeakReferenceArray, Map_EntryArray > WeakHashMap_EntryArray;
    } // util
} // java

extern void unimplemented_(const char16_t* name);
java::util::WeakHashMap::WeakHashMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::WeakHashMap::WeakHashMap()
    : WeakHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::WeakHashMap::WeakHashMap(int32_t arg0)
    : WeakHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::WeakHashMap::WeakHashMap(Map* arg0)
    : WeakHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::WeakHashMap::WeakHashMap(int32_t arg0, float arg1)
    : WeakHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int32_t java::util::WeakHashMap::DEFAULT_INITIAL_CAPACITY;
constexpr float java::util::WeakHashMap::DEFAULT_LOAD_FACTOR;
constexpr int32_t java::util::WeakHashMap::MAXIMUM_CAPACITY;
java::lang::Object*& java::util::WeakHashMap::NULL_KEY()
{
    clinit();
    return NULL_KEY_;
}
java::lang::Object* java::util::WeakHashMap::NULL_KEY_;

void ::java::util::WeakHashMap::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::WeakHashMap::ctor()");
}

void ::java::util::WeakHashMap::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::WeakHashMap::ctor(int32_t arg0)");
}

void ::java::util::WeakHashMap::ctor(Map* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::WeakHashMap::ctor(Map* arg0)");
}

void ::java::util::WeakHashMap::ctor(int32_t arg0, float arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::WeakHashMap::ctor(int32_t arg0, float arg1)");
}

void java::util::WeakHashMap::clear()
{ /* stub */
    unimplemented_(u"void java::util::WeakHashMap::clear()");
}

bool java::util::WeakHashMap::containsKey(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::WeakHashMap::containsKey(::java::lang::Object* arg0)");
    return 0;
}

/* private: bool java::util::WeakHashMap::containsNullValue() */
bool java::util::WeakHashMap::containsValue(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::WeakHashMap::containsValue(::java::lang::Object* arg0)");
    return 0;
}

java::util::Set* java::util::WeakHashMap::entrySet()
{ /* stub */
    unimplemented_(u"java::util::Set* java::util::WeakHashMap::entrySet()");
    return 0;
}

/* private: bool java::util::WeakHashMap::eq(::java::lang::Object* arg0, ::java::lang::Object* arg1) */
/* private: void java::util::WeakHashMap::expungeStaleEntries() */
void java::util::WeakHashMap::forEach(::java::util::function::BiConsumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::WeakHashMap::forEach(::java::util::function::BiConsumer* arg0)");
}

java::lang::Object* java::util::WeakHashMap::get(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::WeakHashMap::get(::java::lang::Object* arg0)");
    return 0;
}

java::util::WeakHashMap_Entry* java::util::WeakHashMap::getEntry(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::WeakHashMap_Entry* java::util::WeakHashMap::getEntry(::java::lang::Object* arg0)");
    return 0;
}

/* private: java::util::WeakHashMap_EntryArray* java::util::WeakHashMap::getTable() */
int32_t java::util::WeakHashMap::hash(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::WeakHashMap::hash(::java::lang::Object* arg0)");
    return 0;
}

/* private: int32_t java::util::WeakHashMap::indexFor(int32_t arg0, int32_t arg1) */
bool java::util::WeakHashMap::isEmpty()
{ /* stub */
    unimplemented_(u"bool java::util::WeakHashMap::isEmpty()");
    return 0;
}

java::util::Set* java::util::WeakHashMap::keySet()
{ /* stub */
    unimplemented_(u"java::util::Set* java::util::WeakHashMap::keySet()");
    return 0;
}

/* private: java::lang::Object* java::util::WeakHashMap::maskNull(::java::lang::Object* arg0) */
/* private: java::util::WeakHashMap_EntryArray* java::util::WeakHashMap::newTable(int32_t arg0) */
java::lang::Object* java::util::WeakHashMap::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::WeakHashMap::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

void java::util::WeakHashMap::putAll(Map* arg0)
{ /* stub */
    unimplemented_(u"void java::util::WeakHashMap::putAll(Map* arg0)");
}

java::lang::Object* java::util::WeakHashMap::remove(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::WeakHashMap::remove(::java::lang::Object* arg0)");
    return 0;
}

bool java::util::WeakHashMap::removeMapping(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::WeakHashMap::removeMapping(::java::lang::Object* arg0)");
    return 0;
}

void java::util::WeakHashMap::replaceAll(::java::util::function::BiFunction* arg0)
{ /* stub */
    unimplemented_(u"void java::util::WeakHashMap::replaceAll(::java::util::function::BiFunction* arg0)");
}

void java::util::WeakHashMap::resize(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::util::WeakHashMap::resize(int32_t arg0)");
}

int32_t java::util::WeakHashMap::size()
{ /* stub */
    unimplemented_(u"int32_t java::util::WeakHashMap::size()");
    return 0;
}

/* private: void java::util::WeakHashMap::transfer(WeakHashMap_EntryArray* arg0, WeakHashMap_EntryArray* arg1) */
java::lang::Object* java::util::WeakHashMap::unmaskNull(::java::lang::Object* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::util::WeakHashMap::unmaskNull(::java::lang::Object* arg0)");
    return 0;
}

java::util::Collection* java::util::WeakHashMap::values()
{ /* stub */
    unimplemented_(u"java::util::Collection* java::util::WeakHashMap::values()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::WeakHashMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.WeakHashMap", 21);
    return c;
}

bool java::util::WeakHashMap::equals(::java::lang::Object* arg0)
{
    return AbstractMap::equals(arg0);
}

int32_t java::util::WeakHashMap::hashCode()
{
    return AbstractMap::hashCode();
}

bool java::util::WeakHashMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return super::remove(arg0, arg1);
}

java::lang::Class* java::util::WeakHashMap::getClass0()
{
    return class_();
}

