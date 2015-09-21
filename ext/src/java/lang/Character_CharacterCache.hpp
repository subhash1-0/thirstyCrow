// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Character, ObjectArray, ::java::io::SerializableArray, ComparableArray > CharacterArray;
    } // lang
} // java

struct default_init_tag;

class java::lang::Character_CharacterCache
    : public virtual Object
{

public:
    typedef Object super;

private:
    static CharacterArray* cache_;

    /*void ctor(); (private) */

    // Generated

public:
    Character_CharacterCache();
protected:
    Character_CharacterCache(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static CharacterArray*& cache();

private:
    virtual ::java::lang::Class* getClass0();
};
