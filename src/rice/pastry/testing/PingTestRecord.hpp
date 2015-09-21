// Generated from /pastry-2.1/src/rice/pastry/testing/PingTestRecord.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/TestRecord.hpp>

struct default_init_tag;

class rice::pastry::testing::PingTestRecord
    : public ::rice::pastry::direct::TestRecord
{

public:
    typedef ::rice::pastry::direct::TestRecord super;

private:
    int32_t nIndex {  };
    ::int32_tArray* nHops {  };
    ::doubleArray* fProb {  };
    double fHops {  };
    double fDistance {  };
protected:
    void ctor(int32_t n, int32_t k, int32_t baseBitLength);

public:
    void doneTest() override;
    virtual void addHops(int32_t index);
    virtual void addDistance(double rDistance);
    virtual double getAveHops();
    virtual double getAveDistance();
    virtual ::doubleArray* getProbability();

    // Generated
    PingTestRecord(int32_t n, int32_t k, int32_t baseBitLength);
protected:
    PingTestRecord(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
