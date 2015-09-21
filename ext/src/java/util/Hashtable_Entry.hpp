// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class java::util::Hashtable_Entry
    : public virtual ::java::lang::Object
    , public virtual Map_Entry
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t hash {  };
    ::java::lang::Object* key {  };
    Hashtable_Entry* next {  };
    ::java::lang::Object* value {  };

protected:
    void ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, Hashtable_Entry* arg3);

public: /* protected */
    ::java::lang::Object* clone() override;

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    int32_t hashCode() override;
    ::java::lang::Object* setValue(::java::lang::Object* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* protected */
    Hashtable_Entry(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, Hashtable_Entry* arg3);
protected:
    Hashtable_Entry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
