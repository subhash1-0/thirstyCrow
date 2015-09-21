// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/SortedMap.hpp>

struct java::util::NavigableMap
    : public virtual SortedMap
{

    virtual Map_Entry* ceilingEntry(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* ceilingKey(::java::lang::Object* arg0) = 0;
    virtual NavigableSet* descendingKeySet() = 0;
    virtual NavigableMap* descendingMap() = 0;
    virtual Map_Entry* firstEntry() = 0;
    virtual Map_Entry* floorEntry(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* floorKey(::java::lang::Object* arg0) = 0;
    /*SortedMap* headMap(::java::lang::Object* arg0); (already declared) */
    virtual NavigableMap* headMap(::java::lang::Object* arg0, bool arg1) = 0;
    virtual Map_Entry* higherEntry(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* higherKey(::java::lang::Object* arg0) = 0;
    virtual Map_Entry* lastEntry() = 0;
    virtual Map_Entry* lowerEntry(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* lowerKey(::java::lang::Object* arg0) = 0;
    virtual NavigableSet* navigableKeySet() = 0;
    virtual Map_Entry* pollFirstEntry() = 0;
    virtual Map_Entry* pollLastEntry() = 0;
    /*SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1); (already declared) */
    virtual NavigableMap* subMap(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) = 0;
    /*SortedMap* tailMap(::java::lang::Object* arg0); (already declared) */
    virtual NavigableMap* tailMap(::java::lang::Object* arg0, bool arg1) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual SortedMap* headMap(::java::lang::Object* arg0) = 0;
    virtual SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1) = 0;
    virtual SortedMap* tailMap(::java::lang::Object* arg0) = 0;
};
