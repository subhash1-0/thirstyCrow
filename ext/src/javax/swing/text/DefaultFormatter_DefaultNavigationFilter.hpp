// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <javax/swing/text/NavigationFilter.hpp>
#include <java/io/Serializable.hpp>

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

class javax::swing::text::DefaultFormatter_DefaultNavigationFilter
    : public NavigationFilter
    , public virtual ::java::io::Serializable
{

public:
    typedef NavigationFilter super;

public: /* package */
    DefaultFormatter* this$0 {  };

    /*void ctor(); (private) */

public:
    int32_t getNextVisualPositionFrom(JTextComponent* arg0, int32_t arg1, Position_Bias* arg2, int32_t arg3, Position_BiasArray* arg4) override;
    void moveDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2) override;
    void setDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2) override;

    // Generated
    DefaultFormatter_DefaultNavigationFilter(DefaultFormatter *DefaultFormatter_this);
protected:
    DefaultFormatter_DefaultNavigationFilter(DefaultFormatter *DefaultFormatter_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    DefaultFormatter *DefaultFormatter_this;

private:
    virtual ::java::lang::Class* getClass0();
};
