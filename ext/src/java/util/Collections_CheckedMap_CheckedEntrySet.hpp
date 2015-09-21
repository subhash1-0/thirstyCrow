// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Set.hpp>

struct default_init_tag;

class java::util::Collections_CheckedMap_CheckedEntrySet
    : public virtual ::java::lang::Object
    , public virtual Set
{

public:
    typedef ::java::lang::Object super;

private:
    Set* s {  };
    ::java::lang::Class* valueType {  };

protected:
    void ctor(Set* arg0, ::java::lang::Class* arg1);

public:
    virtual bool add(Map_Entry* arg0);
    bool addAll(Collection* arg0) override;
    /*bool batchRemove(Collection* arg0, bool arg1); (private) */

public: /* package */
    static Collections_CheckedMap_CheckedEntrySet_CheckedEntry* checkedEntry(Map_Entry* arg0, ::java::lang::Class* arg1);

public:
    void clear() override;
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;
    bool equals(::java::lang::Object* arg0) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    Iterator* iterator() override;
    bool remove(::java::lang::Object* arg0) override;
    bool removeAll(Collection* arg0) override;
    bool retainAll(Collection* arg0) override;
    int32_t size() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    Collections_CheckedMap_CheckedEntrySet(Set* arg0, ::java::lang::Class* arg1);
protected:
    Collections_CheckedMap_CheckedEntrySet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool add(::java::lang::Object* arg0) override;

private:
    virtual ::java::lang::Class* getClass0();
};
