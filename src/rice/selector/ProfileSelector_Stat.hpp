// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::selector::ProfileSelector_Stat
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t num {  };
    ::java::lang::String* name {  };
    int64_t totalTime {  };
    int64_t maxTime {  };
protected:
    void ctor(::java::lang::String* name);

public:
    virtual void addTime(int64_t t);
    ::java::lang::String* toString() override;

    // Generated
    ProfileSelector_Stat(ProfileSelector *ProfileSelector_this, ::java::lang::String* name);
protected:
    ProfileSelector_Stat(ProfileSelector *ProfileSelector_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    ProfileSelector *ProfileSelector_this;
    virtual ::java::lang::Class* getClass0();
    friend class ProfileSelector;
    friend class ProfileSelector_ProfileSelector_1;
    friend class ProfileSelector_printStats_2;
};
