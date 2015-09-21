// Generated from /pastry-2.1/src/rice/pastry/direct/TestRecord.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::direct::TestRecord
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t nNodes {  };
    int32_t nTests {  };
protected:
    void ctor(int32_t n, int32_t k);

public:
    virtual int32_t getNodeNumber();
    virtual int32_t getTestNumber();
    virtual void doneTest() = 0;

    // Generated
    TestRecord(int32_t n, int32_t k);
protected:
    TestRecord(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
