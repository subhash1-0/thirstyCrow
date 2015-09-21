// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/util/Map.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

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

class java::util::HashMap
    : public AbstractMap
    , public virtual Map
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractMap super;

public: /* package */
    static constexpr int32_t DEFAULT_INITIAL_CAPACITY { int32_t(16) };
    static constexpr float DEFAULT_LOAD_FACTOR { 0.75f };
    static constexpr int32_t MAXIMUM_CAPACITY { int32_t(1073741824) };
    static constexpr int32_t MIN_TREEIFY_CAPACITY { int32_t(64) };
    static constexpr int32_t TREEIFY_THRESHOLD { int32_t(8) };
    static constexpr int32_t UNTREEIFY_THRESHOLD { int32_t(6) };
    Set* entrySet_ {  };
    float loadFactor_ {  };
    int32_t modCount {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(362498820763181265LL) };

public: /* package */
    int32_t size_ {  };
    HashMap_NodeArray* table {  };
    int32_t threshold {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(Map* arg0);
    void ctor(int32_t arg0, float arg1);

public: /* package */
    virtual void afterNodeAccess(HashMap_Node* arg0);
    virtual void afterNodeInsertion(bool arg0);
    virtual void afterNodeRemoval(HashMap_Node* arg0);
    int32_t capacity();

public:
    void clear() override;
    ::java::lang::Object* clone() override;

public: /* package */
    static ::java::lang::Class* comparableClassFor(::java::lang::Object* arg0);
    static int32_t compareComparables(::java::lang::Class* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2);

public:
    ::java::lang::Object* compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    ::java::lang::Object* computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1) override;
    ::java::lang::Object* computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    bool containsKey(::java::lang::Object* arg0) override;
    bool containsValue(::java::lang::Object* arg0) override;
    Set* entrySet() override;
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;

public: /* package */
    HashMap_Node* getNode(int32_t arg0, ::java::lang::Object* arg1);

public:
    ::java::lang::Object* getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;

public: /* package */
    static int32_t hash(::java::lang::Object* arg0);
    virtual void internalWriteEntries(::java::io::ObjectOutputStream* arg0);

public:
    bool isEmpty() override;
    Set* keySet() override;

public: /* package */
    float loadFactor();

public:
    ::java::lang::Object* merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2) override;

public: /* package */
    virtual HashMap_Node* newNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3);
    virtual HashMap_TreeNode* newTreeNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3);

public:
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    void putAll(Map* arg0) override;
    ::java::lang::Object* putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;

public: /* package */
    void putMapEntries(Map* arg0, bool arg1);
    ::java::lang::Object* putVal(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, bool arg3, bool arg4);
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    virtual void reinitialize();

public:
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;
    bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;

public: /* package */
    HashMap_Node* removeNode(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, bool arg3, bool arg4);

public:
    ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2) override;
    void replaceAll(::java::util::function::BiFunction* arg0) override;

public: /* package */
    virtual HashMap_Node* replacementNode(HashMap_Node* arg0, HashMap_Node* arg1);
    virtual HashMap_TreeNode* replacementTreeNode(HashMap_Node* arg0, HashMap_Node* arg1);
    HashMap_NodeArray* resize();

public:
    int32_t size() override;

public: /* package */
    static int32_t tableSizeFor(int32_t arg0);
    void treeifyBin(HashMap_NodeArray* arg0, int32_t arg1);

public:
    Collection* values() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    HashMap();
    HashMap(int32_t arg0);
    HashMap(Map* arg0);
    HashMap(int32_t arg0, float arg1);
protected:
    HashMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();

private:
    virtual ::java::lang::Class* getClass0();
};
