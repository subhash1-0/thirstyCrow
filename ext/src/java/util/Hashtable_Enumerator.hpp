// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Enumeration.hpp>
#include <java/util/Iterator.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace util
    {
typedef ::SubArray< ::java::util::Map_Entry, ::java::lang::ObjectArray > Map_EntryArray;
typedef ::SubArray< ::java::util::Hashtable_Entry, ::java::lang::ObjectArray, Map_EntryArray > Hashtable_EntryArray;
    } // util
} // java

struct default_init_tag;

class java::util::Hashtable_Enumerator
    : public virtual ::java::lang::Object
    , public virtual Enumeration
    , public virtual Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    Hashtable_Entry* entry {  };

public: /* protected */
    int32_t expectedModCount {  };

public: /* package */
    int32_t index {  };
    bool iterator {  };
    Hashtable_Entry* lastReturned {  };
    Hashtable_EntryArray* table {  };
    Hashtable* this$0 {  };
    int32_t type {  };

protected:
    void ctor(int32_t arg0, bool arg1);

public:
    bool hasMoreElements() override;
    bool hasNext() override;
    ::java::lang::Object* next() override;
    ::java::lang::Object* nextElement() override;
    void remove() override;

    // Generated

public: /* package */
    Hashtable_Enumerator(Hashtable *Hashtable_this, int32_t arg0, bool arg1);
protected:
    Hashtable_Enumerator(Hashtable *Hashtable_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    Hashtable *Hashtable_this;

private:
    virtual ::java::lang::Class* getClass0();
};
