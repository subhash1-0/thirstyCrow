// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/swing/text/NavigationFilter.hpp>

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

extern void unimplemented_(const char16_t* name);
javax::swing::text::NavigationFilter::NavigationFilter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::swing::text::NavigationFilter::NavigationFilter()
    : NavigationFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::javax::swing::text::NavigationFilter::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::swing::text::NavigationFilter::ctor()");
}

int32_t javax::swing::text::NavigationFilter::getNextVisualPositionFrom(JTextComponent* arg0, int32_t arg1, Position_Bias* arg2, int32_t arg3, Position_BiasArray* arg4)
{ /* stub */
    unimplemented_(u"int32_t javax::swing::text::NavigationFilter::getNextVisualPositionFrom(JTextComponent* arg0, int32_t arg1, Position_Bias* arg2, int32_t arg3, Position_BiasArray* arg4)");
    return 0;
}

void javax::swing::text::NavigationFilter::moveDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2)
{ /* stub */
    unimplemented_(u"void javax::swing::text::NavigationFilter::moveDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2)");
}

void javax::swing::text::NavigationFilter::setDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2)
{ /* stub */
    unimplemented_(u"void javax::swing::text::NavigationFilter::setDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::swing::text::NavigationFilter::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.swing.text.NavigationFilter", 33);
    return c;
}

java::lang::Class* javax::swing::text::NavigationFilter::getClass0()
{
    return class_();
}

