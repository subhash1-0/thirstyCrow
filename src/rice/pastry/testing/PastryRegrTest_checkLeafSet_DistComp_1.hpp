// Generated from /pastry-2.1/src/rice/pastry/testing/PastryRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>

struct default_init_tag;

class rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Comparator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::pastry::Id* id {  };
protected:
    void ctor(::rice::pastry::Id* id);

public:
    virtual int32_t compare(::rice::pastry::Id* o1, ::rice::pastry::Id* o2);

    // Generated
    PastryRegrTest_checkLeafSet_DistComp_1(PastryRegrTest *PastryRegrTest_this, ::rice::pastry::Id* id);
protected:
    PastryRegrTest_checkLeafSet_DistComp_1(PastryRegrTest *PastryRegrTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    PastryRegrTest *PastryRegrTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryRegrTest;
};
