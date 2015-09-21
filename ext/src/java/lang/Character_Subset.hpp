// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::Character_Subset
    : public virtual Object
{

public:
    typedef Object super;

private:
    String* name {  };

protected:
    void ctor(String* arg0);

public:
    bool equals(Object* arg0) override;
    int32_t hashCode() override;
    String* toString() override;

    // Generated

public: /* protected */
    Character_Subset(String* arg0);
protected:
    Character_Subset(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
