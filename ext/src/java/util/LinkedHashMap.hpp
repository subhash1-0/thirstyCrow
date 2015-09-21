// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>

struct default_init_tag;

class java::util::LinkedHashMap
    : public HashMap
    , public virtual Map
{

public:
    typedef HashMap super;

public: /* package */
    bool accessOrder {  };
    LinkedHashMap_Entry* head {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(3801124242820219131LL) };

public: /* package */
    LinkedHashMap_Entry* tail {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(Map* arg0);
    void ctor(int32_t arg0, float arg1);
    void ctor(int32_t arg0, float arg1, bool arg2);

public: /* package */
    void afterNodeAccess(HashMap_Node* arg0) override;
    void afterNodeInsertion(bool arg0) override;
    void afterNodeRemoval(HashMap_Node* arg0) override;

public:
    void clear() override;
    bool containsValue(::java::lang::Object* arg0) override;
    Set* entrySet() override;
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;
    ::java::lang::Object* getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;

public: /* package */
    void internalWriteEntries(::java::io::ObjectOutputStream* arg0) override;

public:
    Set* keySet() override;
    /*void linkNodeLast(LinkedHashMap_Entry* arg0); (private) */

public: /* package */
    HashMap_Node* newNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3) override;
    HashMap_TreeNode* newTreeNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3) override;
    void reinitialize() override;

public: /* protected */
    virtual bool removeEldestEntry(Map_Entry* arg0);

public:
    void replaceAll(::java::util::function::BiFunction* arg0) override;

public: /* package */
    HashMap_Node* replacementNode(HashMap_Node* arg0, HashMap_Node* arg1) override;
    HashMap_TreeNode* replacementTreeNode(HashMap_Node* arg0, HashMap_Node* arg1) override;
    /*void transferLinks(LinkedHashMap_Entry* arg0, LinkedHashMap_Entry* arg1); (private) */

public:
    Collection* values() override;

    // Generated
    LinkedHashMap();
    LinkedHashMap(int32_t arg0);
    LinkedHashMap(Map* arg0);
    LinkedHashMap(int32_t arg0, float arg1);
    LinkedHashMap(int32_t arg0, float arg1, bool arg2);
protected:
    LinkedHashMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1);
    virtual ::java::lang::Object* computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1);
    virtual ::java::lang::Object* computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1);
    virtual bool containsKey(::java::lang::Object* arg0);
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual bool isEmpty();
    virtual ::java::lang::Object* merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2);
    virtual ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual void putAll(Map* arg0);
    virtual ::java::lang::Object* putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual ::java::lang::Object* remove(::java::lang::Object* arg0);
    virtual bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2);
    virtual int32_t size();

private:
    virtual ::java::lang::Class* getClass0();
};
