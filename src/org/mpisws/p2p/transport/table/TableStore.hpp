// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableStore.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/table/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::table::TableStore
    : public virtual ::java::lang::Object
{
    virtual bool containsKey(::java::lang::Object* key) = 0;
    virtual ::java::lang::Object* put(::java::lang::Object* k, ::java::lang::Object* v) = 0;
    virtual ::java::lang::Object* get(::java::lang::Object* k) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
