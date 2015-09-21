// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableMap_UnmodifiableEntrySet_UnmodifiableEntry
    : public virtual ::java::lang::Object
    , public virtual Map_Entry
{

public:
    typedef ::java::lang::Object super;

private:
    Map_Entry* e {  };

protected:
    void ctor(Map_Entry* arg0);

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    int32_t hashCode() override;
    ::java::lang::Object* setValue(::java::lang::Object* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    Collections_UnmodifiableMap_UnmodifiableEntrySet_UnmodifiableEntry(Map_Entry* arg0);
protected:
    Collections_UnmodifiableMap_UnmodifiableEntrySet_UnmodifiableEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
