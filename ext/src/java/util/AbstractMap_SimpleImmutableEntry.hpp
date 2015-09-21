// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::AbstractMap_SimpleImmutableEntry
    : public virtual ::java::lang::Object
    , public virtual Map_Entry
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::Object* key {  };
    static constexpr int64_t serialVersionUID { int64_t(7138329143949025153LL) };
    ::java::lang::Object* value {  };

protected:
    void ctor(Map_Entry* arg0);
    void ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1);

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    int32_t hashCode() override;
    ::java::lang::Object* setValue(::java::lang::Object* arg0) override;
    ::java::lang::String* toString() override;

    // Generated
    AbstractMap_SimpleImmutableEntry(Map_Entry* arg0);
    AbstractMap_SimpleImmutableEntry(::java::lang::Object* arg0, ::java::lang::Object* arg1);
protected:
    AbstractMap_SimpleImmutableEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
