// Generated from /pastry-2.1/src/rice/p2p/past/PastContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::past::PastContent
    : public virtual ::java::io::Serializable
{
    virtual PastContent* checkInsert(::rice::p2p::commonapi::Id* id, PastContent* existingContent) /* throws(PastException) */ = 0;
    virtual PastContentHandle* getHandle(Past* local) = 0;
    virtual ::rice::p2p::commonapi::Id* getId() = 0;
    virtual bool isMutable() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
