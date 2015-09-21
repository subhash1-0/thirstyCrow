// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNode.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectPastryNode
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::util::Hashtable* currentNode_;

public:
    static ::rice::pastry::PastryNode* setCurrentNode(::rice::pastry::PastryNode* dpn);
    static ::rice::pastry::PastryNode* getCurrentNode();

    // Generated
    DirectPastryNode();
protected:
    DirectPastryNode(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static ::java::util::Hashtable*& currentNode();
    virtual ::java::lang::Class* getClass0();
};
