// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace javax
{
    namespace swing
    {
        namespace text
        {
typedef ::SubArray< ::javax::swing::text::Position_Bias, ::java::lang::ObjectArray > Position_BiasArray;
        } // text
    } // swing
} // javax

struct default_init_tag;

class javax::swing::text::NavigationFilter
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    virtual int32_t getNextVisualPositionFrom(JTextComponent* arg0, int32_t arg1, Position_Bias* arg2, int32_t arg3, Position_BiasArray* arg4);
    virtual void moveDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2);
    virtual void setDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2);

    // Generated
    NavigationFilter();
protected:
    NavigationFilter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
