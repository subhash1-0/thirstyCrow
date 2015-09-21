// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/LinkedHashMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

extern void unimplemented_(const char16_t* name);
java::util::LinkedHashMap::LinkedHashMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::LinkedHashMap::LinkedHashMap()
    : LinkedHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::LinkedHashMap::LinkedHashMap(int32_t arg0)
    : LinkedHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::LinkedHashMap::LinkedHashMap(Map* arg0)
    : LinkedHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::LinkedHashMap::LinkedHashMap(int32_t arg0, float arg1)
    : LinkedHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::util::LinkedHashMap::LinkedHashMap(int32_t arg0, float arg1, bool arg2)
    : LinkedHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

constexpr int64_t java::util::LinkedHashMap::serialVersionUID;

void ::java::util::LinkedHashMap::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedHashMap::ctor()");
}

void ::java::util::LinkedHashMap::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedHashMap::ctor(int32_t arg0)");
}

void ::java::util::LinkedHashMap::ctor(Map* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedHashMap::ctor(Map* arg0)");
}

void ::java::util::LinkedHashMap::ctor(int32_t arg0, float arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedHashMap::ctor(int32_t arg0, float arg1)");
}

void ::java::util::LinkedHashMap::ctor(int32_t arg0, float arg1, bool arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedHashMap::ctor(int32_t arg0, float arg1, bool arg2)");
}

void java::util::LinkedHashMap::afterNodeAccess(HashMap_Node* arg0)
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::afterNodeAccess(HashMap_Node* arg0)");
}

void java::util::LinkedHashMap::afterNodeInsertion(bool arg0)
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::afterNodeInsertion(bool arg0)");
}

void java::util::LinkedHashMap::afterNodeRemoval(HashMap_Node* arg0)
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::afterNodeRemoval(HashMap_Node* arg0)");
}

void java::util::LinkedHashMap::clear()
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::clear()");
}

bool java::util::LinkedHashMap::containsValue(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::LinkedHashMap::containsValue(::java::lang::Object* arg0)");
    return 0;
}

java::util::Set* java::util::LinkedHashMap::entrySet()
{ /* stub */
    unimplemented_(u"java::util::Set* java::util::LinkedHashMap::entrySet()");
    return 0;
}

void java::util::LinkedHashMap::forEach(::java::util::function::BiConsumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::forEach(::java::util::function::BiConsumer* arg0)");
}

java::lang::Object* java::util::LinkedHashMap::get(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::LinkedHashMap::get(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::LinkedHashMap::getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::LinkedHashMap::getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

void java::util::LinkedHashMap::internalWriteEntries(::java::io::ObjectOutputStream* arg0)
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::internalWriteEntries(::java::io::ObjectOutputStream* arg0)");
}

java::util::Set* java::util::LinkedHashMap::keySet()
{ /* stub */
    unimplemented_(u"java::util::Set* java::util::LinkedHashMap::keySet()");
    return 0;
}

/* private: void java::util::LinkedHashMap::linkNodeLast(LinkedHashMap_Entry* arg0) */
java::util::HashMap_Node* java::util::LinkedHashMap::newNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
{ /* stub */
    unimplemented_(u"java::util::HashMap_Node* java::util::LinkedHashMap::newNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)");
    return 0;
}

java::util::HashMap_TreeNode* java::util::LinkedHashMap::newTreeNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
{ /* stub */
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::LinkedHashMap::newTreeNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)");
    return 0;
}

void java::util::LinkedHashMap::reinitialize()
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::reinitialize()");
}

bool java::util::LinkedHashMap::removeEldestEntry(Map_Entry* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::LinkedHashMap::removeEldestEntry(Map_Entry* arg0)");
    return 0;
}

void java::util::LinkedHashMap::replaceAll(::java::util::function::BiFunction* arg0)
{ /* stub */
    unimplemented_(u"void java::util::LinkedHashMap::replaceAll(::java::util::function::BiFunction* arg0)");
}

java::util::HashMap_Node* java::util::LinkedHashMap::replacementNode(HashMap_Node* arg0, HashMap_Node* arg1)
{ /* stub */
    unimplemented_(u"java::util::HashMap_Node* java::util::LinkedHashMap::replacementNode(HashMap_Node* arg0, HashMap_Node* arg1)");
    return 0;
}

java::util::HashMap_TreeNode* java::util::LinkedHashMap::replacementTreeNode(HashMap_Node* arg0, HashMap_Node* arg1)
{ /* stub */
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::LinkedHashMap::replacementTreeNode(HashMap_Node* arg0, HashMap_Node* arg1)");
    return 0;
}

/* private: void java::util::LinkedHashMap::transferLinks(LinkedHashMap_Entry* arg0, LinkedHashMap_Entry* arg1) */
java::util::Collection* java::util::LinkedHashMap::values()
{ /* stub */
    unimplemented_(u"java::util::Collection* java::util::LinkedHashMap::values()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::LinkedHashMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.LinkedHashMap", 23);
    return c;
}

java::lang::Object* java::util::LinkedHashMap::compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(HashMap::compute(arg0, arg1));
}

java::lang::Object* java::util::LinkedHashMap::computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1)
{
    return java_cast< ::java::lang::Object* >(HashMap::computeIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::LinkedHashMap::computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1)
{
    return java_cast< ::java::lang::Object* >(HashMap::computeIfPresent(arg0, arg1));
}

bool java::util::LinkedHashMap::containsKey(::java::lang::Object* arg0)
{
    return HashMap::containsKey(arg0);
}

bool java::util::LinkedHashMap::equals(::java::lang::Object* arg0)
{
    return AbstractMap::equals(arg0);
}

int32_t java::util::LinkedHashMap::hashCode()
{
    return AbstractMap::hashCode();
}

bool java::util::LinkedHashMap::isEmpty()
{
    return HashMap::isEmpty();
}

java::lang::Object* java::util::LinkedHashMap::merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2)
{
    return java_cast< ::java::lang::Object* >(HashMap::merge(arg0, arg1, arg2));
}

java::lang::Object* java::util::LinkedHashMap::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(HashMap::put(arg0, arg1));
}

void java::util::LinkedHashMap::putAll(Map* arg0)
{
    HashMap::putAll(arg0);
}

java::lang::Object* java::util::LinkedHashMap::putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(HashMap::putIfAbsent(arg0, arg1));
}

java::lang::Object* java::util::LinkedHashMap::remove(::java::lang::Object* arg0)
{
    return java_cast< ::java::lang::Object* >(HashMap::remove(arg0));
}

bool java::util::LinkedHashMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return HashMap::remove(arg0, arg1);
}

java::lang::Object* java::util::LinkedHashMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< ::java::lang::Object* >(HashMap::replace(arg0, arg1));
}

bool java::util::LinkedHashMap::replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2)
{
    return HashMap::replace(arg0, arg1, arg2);
}

int32_t java::util::LinkedHashMap::size()
{
    return HashMap::size();
}

java::lang::Class* java::util::LinkedHashMap::getClass0()
{
    return class_();
}

