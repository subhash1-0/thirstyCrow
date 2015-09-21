// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/EphemeralDB.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::EphemeralDB
    : public virtual ::java::lang::Object
{
    static constexpr int64_t NO_TAG { int64_t(-0x7fffffffffffffffLL-1) };
    virtual int64_t getTagForEphemeral(::java::lang::Object* addr) = 0;
    virtual ::java::lang::Object* getEphemeral(int64_t tag, ::java::lang::Object* i) = 0;
    virtual void mapHighToTag(::java::lang::Object* high, int64_t tag) = 0;
    virtual ::java::lang::Object* getEphemeral(::java::lang::Object* high) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
