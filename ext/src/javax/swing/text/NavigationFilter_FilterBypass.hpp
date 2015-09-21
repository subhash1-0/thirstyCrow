// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class javax::swing::text::NavigationFilter_FilterBypass
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    virtual Caret* getCaret() = 0;
    virtual void moveDot(int32_t arg0, Position_Bias* arg1) = 0;
    virtual void setDot(int32_t arg0, Position_Bias* arg1) = 0;

    // Generated
    NavigationFilter_FilterBypass();
protected:
    NavigationFilter_FilterBypass(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
