// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/util/NavigableMap.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::TreeMap
    : public AbstractMap
    , public virtual NavigableMap
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractMap super;

private:
    static constexpr bool BLACK { true };
    static constexpr bool RED { false };
    static ::java::lang::Object* UNBOUNDED_;
    Comparator* comparator_ {  };
    NavigableMap* descendingMap_ {  };
    TreeMap_EntrySet* entrySet_ {  };
    int32_t modCount {  };
    TreeMap_KeySet* navigableKeySet_ {  };
    TreeMap_Entry* root {  };
    static constexpr int64_t serialVersionUID { int64_t(919286545866124006LL) };
    int32_t size_ {  };

protected:
    void ctor();
    void ctor(Comparator* arg0);
    void ctor(Map* arg0);
    void ctor(SortedMap* arg0);

public: /* package */
    virtual void addAllForTreeSet(SortedSet* arg0, ::java::lang::Object* arg1);
    /*void buildFromSorted(int32_t arg0, Iterator* arg1, ::java::io::ObjectInputStream* arg2, ::java::lang::Object* arg3); (private) */
    /*TreeMap_Entry* buildFromSorted(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, Iterator* arg4, ::java::io::ObjectInputStream* arg5, ::java::lang::Object* arg6); (private) */

public:
    Map_Entry* ceilingEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* ceilingKey(::java::lang::Object* arg0) override;
    void clear() override;
    ::java::lang::Object* clone() override;
    /*static bool colorOf(TreeMap_Entry* arg0); (private) */
    Comparator* comparator() override;

public: /* package */
    int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    /*static int32_t computeRedLevel(int32_t arg0); (private) */

public:
    bool containsKey(::java::lang::Object* arg0) override;
    bool containsValue(::java::lang::Object* arg0) override;
    /*void deleteEntry(TreeMap_Entry* arg0); (private) */

public: /* package */
    virtual Iterator* descendingKeyIterator();

public:
    NavigableSet* descendingKeySet() override;

public: /* package */
    Spliterator* descendingKeySpliterator();

public:
    NavigableMap* descendingMap() override;
    Set* entrySet() override;

public: /* package */
    static Map_Entry* exportEntry(TreeMap_Entry* arg0);

public:
    Map_Entry* firstEntry() override;
    ::java::lang::Object* firstKey() override;
    /*void fixAfterDeletion(TreeMap_Entry* arg0); (private) */
    /*void fixAfterInsertion(TreeMap_Entry* arg0); (private) */
    Map_Entry* floorEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* floorKey(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;

public: /* package */
    TreeMap_Entry* getCeilingEntry(::java::lang::Object* arg0);
    TreeMap_Entry* getEntry(::java::lang::Object* arg0);
    TreeMap_Entry* getEntryUsingComparator(::java::lang::Object* arg0);
    TreeMap_Entry* getFirstEntry();
    TreeMap_Entry* getFloorEntry(::java::lang::Object* arg0);
    TreeMap_Entry* getHigherEntry(::java::lang::Object* arg0);
    TreeMap_Entry* getLastEntry();
    TreeMap_Entry* getLowerEntry(::java::lang::Object* arg0);

public:
    SortedMap* headMap(::java::lang::Object* arg0) override;
    NavigableMap* headMap(::java::lang::Object* arg0, bool arg1) override;
    Map_Entry* higherEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* higherKey(::java::lang::Object* arg0) override;

public: /* package */
    static ::java::lang::Object* key(TreeMap_Entry* arg0);
    virtual Iterator* keyIterator();
    static ::java::lang::Object* keyOrNull(TreeMap_Entry* arg0);

public:
    Set* keySet() override;

public: /* package */
    Spliterator* keySpliterator();
    static Spliterator* keySpliteratorFor(NavigableMap* arg0);

public:
    Map_Entry* lastEntry() override;
    ::java::lang::Object* lastKey() override;
    /*static TreeMap_Entry* leftOf(TreeMap_Entry* arg0); (private) */
    Map_Entry* lowerEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* lowerKey(::java::lang::Object* arg0) override;
    NavigableSet* navigableKeySet() override;
    /*static TreeMap_Entry* parentOf(TreeMap_Entry* arg0); (private) */
    Map_Entry* pollFirstEntry() override;
    Map_Entry* pollLastEntry() override;

public: /* package */
    static TreeMap_Entry* predecessor(TreeMap_Entry* arg0);

public:
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    void putAll(Map* arg0) override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */

public: /* package */
    virtual void readTreeSet(int32_t arg0, ::java::io::ObjectInputStream* arg1, ::java::lang::Object* arg2);

public:
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;
    ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2) override;
    void replaceAll(::java::util::function::BiFunction* arg0) override;
    /*static TreeMap_Entry* rightOf(TreeMap_Entry* arg0); (private) */
    /*void rotateLeft(TreeMap_Entry* arg0); (private) */
    /*void rotateRight(TreeMap_Entry* arg0); (private) */
    /*static void setColor(TreeMap_Entry* arg0, bool arg1); (private) */
    int32_t size() override;
    SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    NavigableMap* subMap(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) override;

public: /* package */
    static TreeMap_Entry* successor(TreeMap_Entry* arg0);

public:
    SortedMap* tailMap(::java::lang::Object* arg0) override;
    NavigableMap* tailMap(::java::lang::Object* arg0, bool arg1) override;

public: /* package */
    static bool valEquals(::java::lang::Object* arg0, ::java::lang::Object* arg1);

public:
    Collection* values() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    TreeMap();
    TreeMap(Comparator* arg0);
    TreeMap(Map* arg0);
    TreeMap(SortedMap* arg0);
protected:
    TreeMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual bool isEmpty();
    virtual bool remove(::java::lang::Object* key, ::java::lang::Object* value);

private:
    static ::java::lang::Object*& UNBOUNDED();
    virtual ::java::lang::Class* getClass0();
};
