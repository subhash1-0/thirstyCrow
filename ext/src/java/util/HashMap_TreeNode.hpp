// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/LinkedHashMap_Entry.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace util
    {
typedef ::SubArray< ::java::util::Map_Entry, ::java::lang::ObjectArray > Map_EntryArray;
typedef ::SubArray< ::java::util::HashMap_Node, ::java::lang::ObjectArray, Map_EntryArray > HashMap_NodeArray;
    } // util
} // java

struct default_init_tag;

class java::util::HashMap_TreeNode final
    : public LinkedHashMap_Entry
{

public:
    typedef LinkedHashMap_Entry super;

private:
    static bool $assertionsDisabled_;

public: /* package */
    HashMap_TreeNode* left {  };
    HashMap_TreeNode* parent {  };
    HashMap_TreeNode* prev {  };
    bool red {  };
    HashMap_TreeNode* right {  };

protected:
    void ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3);

public: /* package */
    static HashMap_TreeNode* balanceDeletion(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1);
    static HashMap_TreeNode* balanceInsertion(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1);
    static bool checkInvariants(HashMap_TreeNode* arg0);
    HashMap_TreeNode* find(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Class* arg2);
    HashMap_TreeNode* getTreeNode(int32_t arg0, ::java::lang::Object* arg1);
    static void moveRootToFront(HashMap_NodeArray* arg0, HashMap_TreeNode* arg1);
    HashMap_TreeNode* putTreeVal(HashMap* arg0, HashMap_NodeArray* arg1, int32_t arg2, ::java::lang::Object* arg3, ::java::lang::Object* arg4);
    void removeTreeNode(HashMap* arg0, HashMap_NodeArray* arg1, bool arg2);
    HashMap_TreeNode* root();
    static HashMap_TreeNode* rotateLeft(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1);
    static HashMap_TreeNode* rotateRight(HashMap_TreeNode* arg0, HashMap_TreeNode* arg1);
    void split(HashMap* arg0, HashMap_NodeArray* arg1, int32_t arg2, int32_t arg3);
    static int32_t tieBreakOrder(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    void treeify(HashMap_NodeArray* arg0);
    HashMap_Node* untreeify(HashMap* arg0);

    // Generated
    HashMap_TreeNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3);
protected:
    HashMap_TreeNode(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    virtual ::java::lang::Class* getClass0();
};
