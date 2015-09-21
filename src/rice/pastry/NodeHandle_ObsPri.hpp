// Generated from /pastry-2.1/src/rice/pastry/NodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::pastry::NodeHandle_ObsPri
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Observer* obs {  };
    int32_t pri {  };
protected:
    void ctor(::java::util::Observer* o, int32_t priority);

public:
    virtual int32_t compareTo(NodeHandle_ObsPri* o);
    ::java::lang::String* toString() override;

    // Generated
    NodeHandle_ObsPri(::java::util::Observer* o, int32_t priority);
protected:
    NodeHandle_ObsPri(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class NodeHandle;
};
