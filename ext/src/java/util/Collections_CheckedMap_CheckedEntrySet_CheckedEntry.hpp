// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class java::util::Collections_CheckedMap_CheckedEntrySet_CheckedEntry
    : public virtual ::java::lang::Object
    , public virtual Map_Entry
{

public:
    typedef ::java::lang::Object super;

private:
    Map_Entry* e {  };
    ::java::lang::Class* valueType {  };

protected:
    void ctor(Map_Entry* arg0, ::java::lang::Class* arg1);
    /*::java::lang::String* badValueMsg(::java::lang::Object* arg0); (private) */

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    int32_t hashCode() override;
    ::java::lang::Object* setValue(::java::lang::Object* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    Collections_CheckedMap_CheckedEntrySet_CheckedEntry(Map_Entry* arg0, ::java::lang::Class* arg1);
protected:
    Collections_CheckedMap_CheckedEntrySet_CheckedEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
