// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/TreeMap_NavigableSubMap.hpp>

struct default_init_tag;

class java::util::TreeMap_AscendingSubMap final
    : public TreeMap_NavigableSubMap
{

public:
    typedef TreeMap_NavigableSubMap super;

private:
    static constexpr int64_t serialVersionUID { int64_t(912986545866124060LL) };

protected:
    void ctor(TreeMap* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3, bool arg4, ::java::lang::Object* arg5, bool arg6);

public:
    Comparator* comparator() override;

public: /* package */
    Iterator* descendingKeyIterator() override;

public:
    NavigableMap* descendingMap() override;
    Set* entrySet() override;
    NavigableMap* headMap(::java::lang::Object* arg0, bool arg1) override;

public: /* package */
    Iterator* keyIterator() override;
    Spliterator* keySpliterator() override;
    TreeMap_Entry* subCeiling(::java::lang::Object* arg0) override;
    TreeMap_Entry* subFloor(::java::lang::Object* arg0) override;
    TreeMap_Entry* subHigher(::java::lang::Object* arg0) override;
    TreeMap_Entry* subHighest() override;
    TreeMap_Entry* subLower(::java::lang::Object* arg0) override;
    TreeMap_Entry* subLowest() override;

public:
    NavigableMap* subMap(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) override;
    NavigableMap* tailMap(::java::lang::Object* arg0, bool arg1) override;

    // Generated

public: /* package */
    TreeMap_AscendingSubMap(TreeMap* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3, bool arg4, ::java::lang::Object* arg5, bool arg6);
protected:
    TreeMap_AscendingSubMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    SortedMap* headMap(::java::lang::Object* arg0);
    SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    SortedMap* tailMap(::java::lang::Object* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
