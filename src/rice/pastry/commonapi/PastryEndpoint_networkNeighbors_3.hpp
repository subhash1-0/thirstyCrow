// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>

struct default_init_tag;

class rice::pastry::commonapi::PastryEndpoint_networkNeighbors_3
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Comparator
{

public:
    typedef ::java::lang::Object super;
    virtual int32_t compare(::rice::p2p::commonapi::NodeHandle* a, ::rice::p2p::commonapi::NodeHandle* b);

    // Generated
    PastryEndpoint_networkNeighbors_3(PastryEndpoint *PastryEndpoint_this);
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    PastryEndpoint *PastryEndpoint_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryEndpoint;
    friend class PastryEndpoint_PEDeserializer;
    friend class PastryEndpoint_routeHelper_1;
    friend class PastryEndpoint_routeHelper_2;
};
