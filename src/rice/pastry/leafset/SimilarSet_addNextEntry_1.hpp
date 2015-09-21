// Generated from /pastry-2.1/src/rice/pastry/leafset/SimilarSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>

struct default_init_tag;

class rice::pastry::leafset::SimilarSet_addNextEntry_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Comparator
{

public:
    typedef ::java::lang::Object super;
    virtual int32_t compare(::rice::pastry::NodeHandle* a, ::rice::pastry::NodeHandle* b);

    // Generated
    SimilarSet_addNextEntry_1(SimilarSet *SimilarSet_this);
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    SimilarSet *SimilarSet_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimilarSet;
};
