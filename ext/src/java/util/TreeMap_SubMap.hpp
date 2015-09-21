// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/util/SortedMap.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::TreeMap_SubMap
    : public AbstractMap
    , public virtual SortedMap
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractMap super;

private:
    ::java::lang::Object* fromKey {  };
    bool fromStart {  };
    static constexpr int64_t serialVersionUID { int64_t(-6520786458950516097LL) };

public: /* package */
    TreeMap* this$0 {  };

private:
    bool toEnd {  };
    ::java::lang::Object* toKey {  };

    /*void ctor(); (private) */

public:
    Comparator* comparator() override;
    Set* entrySet() override;
    ::java::lang::Object* firstKey() override;
    SortedMap* headMap(::java::lang::Object* arg0) override;
    ::java::lang::Object* lastKey() override;
    /*::java::lang::Object* readResolve(); (private) */
    SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    SortedMap* tailMap(::java::lang::Object* arg0) override;

    // Generated
    TreeMap_SubMap(TreeMap *TreeMap_this);
protected:
    TreeMap_SubMap(TreeMap *TreeMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void clear();
    virtual bool containsKey(::java::lang::Object* arg0);
    virtual bool containsValue(::java::lang::Object* arg0);
    virtual bool equals(::java::lang::Object* arg0);
    virtual ::java::lang::Object* get(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual bool isEmpty();
    virtual ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual void putAll(Map* arg0);
    virtual ::java::lang::Object* remove(::java::lang::Object* arg0);
    virtual int32_t size();
    Set* keySet();
    Collection* values();
    virtual bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    TreeMap *TreeMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
