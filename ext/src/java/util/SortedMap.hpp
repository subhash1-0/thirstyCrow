// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Map.hpp>

struct java::util::SortedMap
    : public virtual Map
{

    virtual Comparator* comparator() = 0;
    /*Set* entrySet(); (already declared) */
    virtual ::java::lang::Object* firstKey() = 0;
    virtual SortedMap* headMap(::java::lang::Object* arg0) = 0;
    /*Set* keySet(); (already declared) */
    virtual ::java::lang::Object* lastKey() = 0;
    virtual SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1) = 0;
    virtual SortedMap* tailMap(::java::lang::Object* arg0) = 0;
    /*Collection* values(); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
};
