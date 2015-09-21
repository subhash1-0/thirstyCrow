// Generated from /pastry-2.1/src/rice/p2p/util/SoftHashMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/util/HashMap.hpp>

struct default_init_tag;

class rice::p2p::util::SoftHashMap
    : public ::java::util::HashMap
{

public:
    typedef ::java::util::HashMap super;
    bool containsKey(::java::lang::Object* key) override;
    bool containsValue(::java::lang::Object* value) override;
    ::java::lang::Object* get(::java::lang::Object* key) override;
    ::java::lang::Object* put(::java::lang::Object* key, ::java::lang::Object* value) override;

    // Generated
    SoftHashMap();
protected:
    SoftHashMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
