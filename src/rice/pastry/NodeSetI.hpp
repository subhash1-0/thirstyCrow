// Generated from /pastry-2.1/src/rice/pastry/NodeSetI.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>

struct rice::pastry::NodeSetI
    : public virtual ::rice::p2p::commonapi::NodeHandleSet
{
    virtual bool put(NodeHandle* handle) = 0;
    virtual NodeHandle* get(Id* nid) = 0;
    virtual NodeHandle* get(int32_t i) = 0;
    virtual bool member(NodeHandle* nh) = 0;
    virtual NodeHandle* remove(NodeHandle* nh) = 0;
    /*int32_t size(); (already declared) */
    virtual int32_t getIndex(Id* nid) /* throws(NoSuchElementException) */ = 0;
    virtual int32_t getIndex(NodeHandle* nh) /* throws(NoSuchElementException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
