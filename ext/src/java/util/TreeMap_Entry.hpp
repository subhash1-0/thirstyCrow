// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class java::util::TreeMap_Entry final
    : public virtual ::java::lang::Object
    , public Map_Entry
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool color {  };
    ::java::lang::Object* key {  };
    TreeMap_Entry* left {  };
    TreeMap_Entry* parent {  };
    TreeMap_Entry* right {  };
    ::java::lang::Object* value {  };

protected:
    void ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1, TreeMap_Entry* arg2);

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    int32_t hashCode() override;
    ::java::lang::Object* setValue(::java::lang::Object* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    TreeMap_Entry(::java::lang::Object* arg0, ::java::lang::Object* arg1, TreeMap_Entry* arg2);
protected:
    TreeMap_Entry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
