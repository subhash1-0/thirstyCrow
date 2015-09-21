// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashMap_TreeNode.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace util
    {
typedef ::SubArray< ::java::util::Map_Entry, ::java::lang::ObjectArray > Map_EntryArray;
typedef ::SubArray< ::java::util::HashMap_Node, ::java::lang::ObjectArray, Map_EntryArray > HashMap_NodeArray;
    } // util
} // java

extern void unimplemented_(const char16_t* name);
java::util::HashMap_TreeNode::HashMap_TreeNode(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::HashMap_TreeNode::HashMap_TreeNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
    : HashMap_TreeNode(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}

bool& java::util::HashMap_TreeNode::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::util::HashMap_TreeNode::$assertionsDisabled_;

void ::java::util::HashMap_TreeNode::ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashMap_TreeNode::ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)");
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::balanceDeletion(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::balanceDeletion(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)");
    return 0;
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::balanceInsertion(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::balanceInsertion(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)");
    return 0;
}

bool java::util::HashMap_TreeNode::checkInvariants(HashMap_TreeNode* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::util::HashMap_TreeNode::checkInvariants(HashMap_TreeNode* arg0)");
    return 0;
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::find(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Class* arg2)
{ /* stub */
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::find(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Class* arg2)");
    return 0;
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::getTreeNode(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::getTreeNode(int32_t arg0, ::java::lang::Object* arg1)");
    return 0;
}

void java::util::HashMap_TreeNode::moveRootToFront(HashMap_NodeArray* arg0, HashMap_TreeNode* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void java::util::HashMap_TreeNode::moveRootToFront(HashMap_NodeArray* arg0, HashMap_TreeNode* arg1)");
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::putTreeVal(HashMap* arg0, HashMap_NodeArray* arg1, int32_t arg2, ::java::lang::Object* arg3, ::java::lang::Object* arg4)
{ /* stub */
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::putTreeVal(HashMap* arg0, HashMap_NodeArray* arg1, int32_t arg2, ::java::lang::Object* arg3, ::java::lang::Object* arg4)");
    return 0;
}

void java::util::HashMap_TreeNode::removeTreeNode(HashMap* arg0, HashMap_NodeArray* arg1, bool arg2)
{ /* stub */
    unimplemented_(u"void java::util::HashMap_TreeNode::removeTreeNode(HashMap* arg0, HashMap_NodeArray* arg1, bool arg2)");
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::root()
{ /* stub */
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::root()");
    return 0;
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::rotateLeft(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::rotateLeft(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)");
    return 0;
}

java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::rotateRight(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::util::HashMap_TreeNode* java::util::HashMap_TreeNode::rotateRight(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1)");
    return 0;
}

void java::util::HashMap_TreeNode::split(HashMap* arg0, HashMap_NodeArray* arg1, int32_t arg2, int32_t arg3)
{ /* stub */
    unimplemented_(u"void java::util::HashMap_TreeNode::split(HashMap* arg0, HashMap_NodeArray* arg1, int32_t arg2, int32_t arg3)");
}

int32_t java::util::HashMap_TreeNode::tieBreakOrder(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::util::HashMap_TreeNode::tieBreakOrder(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

void java::util::HashMap_TreeNode::treeify(HashMap_NodeArray* arg0)
{ /* stub */
    unimplemented_(u"void java::util::HashMap_TreeNode::treeify(HashMap_NodeArray* arg0)");
}

java::util::HashMap_Node* java::util::HashMap_TreeNode::untreeify(HashMap* arg0)
{ /* stub */
    unimplemented_(u"java::util::HashMap_Node* java::util::HashMap_TreeNode::untreeify(HashMap* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashMap_TreeNode::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashMap.TreeNode", 26);
    return c;
}

java::lang::Class* java::util::HashMap_TreeNode::getClass0()
{
    return class_();
}

