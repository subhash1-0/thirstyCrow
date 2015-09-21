// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/swing/JFormattedTextField_AbstractFormatter.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace util
    {
typedef ::SubArray< ::java::util::EventListener, ::java::lang::ObjectArray > EventListenerArray;
    } // util

    namespace awt
    {
        namespace event
        {
typedef ::SubArray< ::java::awt::event::ActionListener, ::java::lang::ObjectArray, ::java::util::EventListenerArray > ActionListenerArray;
        } // event
    } // awt
} // java

namespace javax
{
    namespace swing
    {
typedef ::SubArray< ::javax::swing::Action, ::java::lang::ObjectArray, ::java::awt::event::ActionListenerArray > ActionArray;
    } // swing
} // javax

extern void unimplemented_(const char16_t* name);
javax::swing::JFormattedTextField_AbstractFormatter::JFormattedTextField_AbstractFormatter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::swing::JFormattedTextField_AbstractFormatter::JFormattedTextField_AbstractFormatter()
    : JFormattedTextField_AbstractFormatter(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::javax::swing::JFormattedTextField_AbstractFormatter::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::swing::JFormattedTextField_AbstractFormatter::ctor()");
}

java::lang::Object* javax::swing::JFormattedTextField_AbstractFormatter::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* javax::swing::JFormattedTextField_AbstractFormatter::clone()");
    return 0;
}

javax::swing::ActionArray* javax::swing::JFormattedTextField_AbstractFormatter::getActions()
{ /* stub */
    unimplemented_(u"javax::swing::ActionArray* javax::swing::JFormattedTextField_AbstractFormatter::getActions()");
    return 0;
}

javax::swing::text::DocumentFilter* javax::swing::JFormattedTextField_AbstractFormatter::getDocumentFilter()
{ /* stub */
    unimplemented_(u"javax::swing::text::DocumentFilter* javax::swing::JFormattedTextField_AbstractFormatter::getDocumentFilter()");
    return 0;
}

javax::swing::JFormattedTextField* javax::swing::JFormattedTextField_AbstractFormatter::getFormattedTextField()
{ /* stub */
    unimplemented_(u"javax::swing::JFormattedTextField* javax::swing::JFormattedTextField_AbstractFormatter::getFormattedTextField()");
    return 0;
}

javax::swing::text::NavigationFilter* javax::swing::JFormattedTextField_AbstractFormatter::getNavigationFilter()
{ /* stub */
    unimplemented_(u"javax::swing::text::NavigationFilter* javax::swing::JFormattedTextField_AbstractFormatter::getNavigationFilter()");
    return 0;
}

void javax::swing::JFormattedTextField_AbstractFormatter::install(JFormattedTextField* arg0)
{ /* stub */
    unimplemented_(u"void javax::swing::JFormattedTextField_AbstractFormatter::install(JFormattedTextField* arg0)");
}

/* private: void javax::swing::JFormattedTextField_AbstractFormatter::installDocumentFilter(::javax::swing::text::DocumentFilter* arg0) */
void javax::swing::JFormattedTextField_AbstractFormatter::invalidEdit()
{ /* stub */
    unimplemented_(u"void javax::swing::JFormattedTextField_AbstractFormatter::invalidEdit()");
}

void javax::swing::JFormattedTextField_AbstractFormatter::setEditValid(bool arg0)
{ /* stub */
    unimplemented_(u"void javax::swing::JFormattedTextField_AbstractFormatter::setEditValid(bool arg0)");
}

void javax::swing::JFormattedTextField_AbstractFormatter::uninstall()
{ /* stub */
    unimplemented_(u"void javax::swing::JFormattedTextField_AbstractFormatter::uninstall()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::swing::JFormattedTextField_AbstractFormatter::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.swing.JFormattedTextField.AbstractFormatter", 49);
    return c;
}

java::lang::Class* javax::swing::JFormattedTextField_AbstractFormatter::getClass0()
{
    return class_();
}

