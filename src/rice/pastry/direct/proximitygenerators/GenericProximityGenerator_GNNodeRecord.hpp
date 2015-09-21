// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/GenericProximityGenerator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/proximitygenerators/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>

struct default_init_tag;

class rice::pastry::direct::proximitygenerators::GenericProximityGenerator_GNNodeRecord
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::direct::NodeRecord
{

public:
    typedef ::java::lang::Object super;
    int32_t index {  };
protected:
    void ctor();

public:
    float proximity(::rice::pastry::direct::NodeRecord* that) override;
    float networkDelay(::rice::pastry::direct::NodeRecord* that) override;
    virtual int32_t getIndex();
    void markDead() override;

    // Generated
    GenericProximityGenerator_GNNodeRecord(GenericProximityGenerator *GenericProximityGenerator_this);
protected:
    GenericProximityGenerator_GNNodeRecord(GenericProximityGenerator *GenericProximityGenerator_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    GenericProximityGenerator *GenericProximityGenerator_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class GenericProximityGenerator;
};
