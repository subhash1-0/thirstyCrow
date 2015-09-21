// Generated from /pastry-2.1/src/rice/environment/params/simple/SimpleParameters.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/params/simple/fwd-pastry-2.1.hpp>
#include <java/util/Properties.hpp>

struct default_init_tag;

class rice::environment::params::simple::SimpleParameters_MyProperties
    : public ::java::util::Properties
{

public:
    typedef ::java::util::Properties super;
    ::java::util::Enumeration* keys() override;

    // Generated
    SimpleParameters_MyProperties(SimpleParameters *SimpleParameters_this);
protected:
    SimpleParameters_MyProperties(SimpleParameters *SimpleParameters_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    SimpleParameters *SimpleParameters_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimpleParameters;
    friend class SimpleParameters_MyProperties_keys_1;
};
