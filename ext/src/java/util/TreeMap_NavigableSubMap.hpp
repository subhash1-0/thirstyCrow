// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/util/NavigableMap.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::TreeMap_NavigableSubMap
    : public AbstractMap
    , public virtual NavigableMap
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractMap super;

public: /* package */
    NavigableMap* descendingMapView {  };
    TreeMap_NavigableSubMap_EntrySetView* entrySetView {  };
    bool fromStart {  };
    ::java::lang::Object* hi {  };
    bool hiInclusive {  };
    ::java::lang::Object* lo {  };
    bool loInclusive {  };
    TreeMap* m {  };
    TreeMap_KeySet* navigableKeySetView {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(-2102997345730753016LL) };

public: /* package */
    bool toEnd {  };

protected:
    void ctor(TreeMap* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3, bool arg4, ::java::lang::Object* arg5, bool arg6);

public: /* package */
    TreeMap_Entry* absCeiling(::java::lang::Object* arg0);
    TreeMap_Entry* absFloor(::java::lang::Object* arg0);
    TreeMap_Entry* absHighFence();
    TreeMap_Entry* absHigher(::java::lang::Object* arg0);
    TreeMap_Entry* absHighest();
    TreeMap_Entry* absLowFence();
    TreeMap_Entry* absLower(::java::lang::Object* arg0);
    TreeMap_Entry* absLowest();

public:
    Map_Entry* ceilingEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* ceilingKey(::java::lang::Object* arg0) override;
    bool containsKey(::java::lang::Object* arg0) override;

public: /* package */
    virtual Iterator* descendingKeyIterator() = 0;

public:
    NavigableSet* descendingKeySet() override;
    Map_Entry* firstEntry() override;
    ::java::lang::Object* firstKey() override;
    Map_Entry* floorEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* floorKey(::java::lang::Object* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;
    SortedMap* headMap(::java::lang::Object* arg0) override;
    Map_Entry* higherEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* higherKey(::java::lang::Object* arg0) override;

public: /* package */
    bool inClosedRange(::java::lang::Object* arg0);
    bool inRange(::java::lang::Object* arg0);
    bool inRange(::java::lang::Object* arg0, bool arg1);

public:
    bool isEmpty() override;

public: /* package */
    virtual Iterator* keyIterator() = 0;

public:
    Set* keySet() override;

public: /* package */
    virtual Spliterator* keySpliterator() = 0;

public:
    Map_Entry* lastEntry() override;
    ::java::lang::Object* lastKey() override;
    Map_Entry* lowerEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* lowerKey(::java::lang::Object* arg0) override;
    NavigableSet* navigableKeySet() override;
    Map_Entry* pollFirstEntry() override;
    Map_Entry* pollLastEntry() override;
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;
    int32_t size() override;

public: /* package */
    virtual TreeMap_Entry* subCeiling(::java::lang::Object* arg0) = 0;
    virtual TreeMap_Entry* subFloor(::java::lang::Object* arg0) = 0;
    virtual TreeMap_Entry* subHigher(::java::lang::Object* arg0) = 0;
    virtual TreeMap_Entry* subHighest() = 0;
    virtual TreeMap_Entry* subLower(::java::lang::Object* arg0) = 0;
    virtual TreeMap_Entry* subLowest() = 0;

public:
    SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    SortedMap* tailMap(::java::lang::Object* arg0) override;

public: /* package */
    bool tooHigh(::java::lang::Object* arg0);
    bool tooLow(::java::lang::Object* arg0);

    // Generated
    TreeMap_NavigableSubMap(TreeMap* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3, bool arg4, ::java::lang::Object* arg5, bool arg6);
protected:
    TreeMap_NavigableSubMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void clear();
    virtual bool containsValue(::java::lang::Object* arg0);
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual void putAll(Map* arg0);
    Collection* values();
    virtual NavigableMap* headMap(::java::lang::Object* arg0, bool arg1) = 0;
    virtual NavigableMap* subMap(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) = 0;
    virtual NavigableMap* tailMap(::java::lang::Object* arg0, bool arg1) = 0;
    virtual bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1);

private:
    virtual ::java::lang::Class* getClass0();
};
