// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/proximitygenerators/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>

struct default_init_tag;

class rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::direct::NodeRecord
{

public:
    typedef ::java::lang::Object super;
    double theta {  }, phi {  };

public: /* package */
    double radius {  };
protected:
    void ctor();
    void ctor(double theta, double phi);

public:
    float proximity(::rice::pastry::direct::NodeRecord* that) override;
    float networkDelay(::rice::pastry::direct::NodeRecord* that) override;
    void markDead() override;

    // Generated
    SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator *SphereNetworkProximityGenerator_this);
    SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator *SphereNetworkProximityGenerator_this, double theta, double phi);
protected:
    SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator *SphereNetworkProximityGenerator_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    SphereNetworkProximityGenerator *SphereNetworkProximityGenerator_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SphereNetworkProximityGenerator;
};
