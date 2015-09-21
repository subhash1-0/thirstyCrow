// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/proximitygenerators/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>

struct default_init_tag;

class rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::direct::NodeRecord
{

public:
    typedef ::java::lang::Object super;
    int32_t x {  }, y {  };
    bool alive {  };
protected:
    void ctor();

public:
    float proximity(::rice::pastry::direct::NodeRecord* that) override;
    float networkDelay(::rice::pastry::direct::NodeRecord* that) override;
    ::java::lang::String* toString() override;
    void markDead() override;

    // Generated
    EuclideanProximityGenerator_EuclideanNodeRecord(EuclideanProximityGenerator *EuclideanProximityGenerator_this);
protected:
    EuclideanProximityGenerator_EuclideanNodeRecord(EuclideanProximityGenerator *EuclideanProximityGenerator_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    EuclideanProximityGenerator *EuclideanProximityGenerator_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EuclideanProximityGenerator;
};
