// Generated from /pastry-2.1/src/rice/pastry/standard/PartitionHandler.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::standard::PartitionHandler_GoneSetEntry
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    ::rice::pastry::NodeHandle* nh {  };
    int64_t timestamp {  };
protected:
    void ctor(::rice::pastry::NodeHandle* nh, int64_t timestamp);

public:
    bool equals(::java::lang::Object* o) override;
    ::java::lang::String* toString() override;

    // Generated
    PartitionHandler_GoneSetEntry(::rice::pastry::NodeHandle* nh, int64_t timestamp);
protected:
    PartitionHandler_GoneSetEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PartitionHandler;
    friend class PartitionHandler_run_1;
};
