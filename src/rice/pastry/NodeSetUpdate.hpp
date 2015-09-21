// Generated from /pastry-2.1/src/rice/pastry/NodeSetUpdate.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::NodeSetUpdate
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    NodeHandle* changed {  };
    bool added {  };
protected:
    void ctor(NodeHandle* which, bool how);

public:
    virtual NodeHandle* handle();
    virtual bool wasAdded();

    // Generated
    NodeSetUpdate(NodeHandle* which, bool how);
protected:
    NodeSetUpdate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
