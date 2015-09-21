// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/proximitygenerators/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/direct/ProximityGenerator.hpp>

struct default_init_tag;

class rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::direct::ProximityGenerator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t side {  };
    ::rice::environment::random::RandomSource* random {  };
protected:
    void ctor(int32_t maxDiameter);

public:
    ::rice::pastry::direct::NodeRecord* generateNodeRecord() override;
    void setRandom(::rice::environment::random::RandomSource* random) override;

    // Generated
    EuclideanProximityGenerator(int32_t maxDiameter);
protected:
    EuclideanProximityGenerator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class EuclideanProximityGenerator_EuclideanNodeRecord;
};
