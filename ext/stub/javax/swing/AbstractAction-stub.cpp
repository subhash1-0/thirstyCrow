// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/swing/AbstractAction.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace util
    {
typedef ::SubArray< ::java::util::EventListener, ::java::lang::ObjectArray > EventListenerArray;
    } // util

    namespace beans
    {
typedef ::SubArray< ::java::beans::PropertyChangeListener, ::java::lang::ObjectArray, ::java::util::EventListenerArray > PropertyChangeListenerArray;
    } // beans
} // java

extern void unimplemented_(const char16_t* name);
javax::swing::AbstractAction::AbstractAction(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::swing::AbstractAction::AbstractAction()
    : AbstractAction(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

javax::swing::AbstractAction::AbstractAction(::java::lang::String* arg0)
    : AbstractAction(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

javax::swing::AbstractAction::AbstractAction(::java::lang::String* arg0, Icon* arg1)
    : AbstractAction(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::Boolean*& javax::swing::AbstractAction::RECONFIGURE_ON_NULL()
{
    clinit();
    return RECONFIGURE_ON_NULL_;
}
java::lang::Boolean* javax::swing::AbstractAction::RECONFIGURE_ON_NULL_;

void ::javax::swing::AbstractAction::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::swing::AbstractAction::ctor()");
}

void ::javax::swing::AbstractAction::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::swing::AbstractAction::ctor(::java::lang::String* arg0)");
}

void ::javax::swing::AbstractAction::ctor(::java::lang::String* arg0, Icon* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::swing::AbstractAction::ctor(::java::lang::String* arg0, Icon* arg1)");
}

void javax::swing::AbstractAction::addPropertyChangeListener(::java::beans::PropertyChangeListener* arg0)
{ /* stub */
    unimplemented_(u"void javax::swing::AbstractAction::addPropertyChangeListener(::java::beans::PropertyChangeListener* arg0)");
}

java::lang::Object* javax::swing::AbstractAction::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* javax::swing::AbstractAction::clone()");
    return 0;
}

void javax::swing::AbstractAction::firePropertyChange(::java::lang::String* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2)
{ /* stub */
    unimplemented_(u"void javax::swing::AbstractAction::firePropertyChange(::java::lang::String* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2)");
}

java::lang::ObjectArray* javax::swing::AbstractAction::getKeys()
{ /* stub */
    unimplemented_(u"java::lang::ObjectArray* javax::swing::AbstractAction::getKeys()");
    return 0;
}

java::beans::PropertyChangeListenerArray* javax::swing::AbstractAction::getPropertyChangeListeners()
{ /* stub */
    unimplemented_(u"java::beans::PropertyChangeListenerArray* javax::swing::AbstractAction::getPropertyChangeListeners()");
    return 0;
}

java::lang::Object* javax::swing::AbstractAction::getValue(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* javax::swing::AbstractAction::getValue(::java::lang::String* arg0)");
    return 0;
}

bool javax::swing::AbstractAction::hasSelectedKey(Action* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool javax::swing::AbstractAction::hasSelectedKey(Action* arg0)");
    return 0;
}

bool javax::swing::AbstractAction::isEnabled()
{ /* stub */
    unimplemented_(u"bool javax::swing::AbstractAction::isEnabled()");
    return 0;
}

bool javax::swing::AbstractAction::isSelected(Action* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool javax::swing::AbstractAction::isSelected(Action* arg0)");
    return 0;
}

void javax::swing::AbstractAction::putValue(::java::lang::String* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void javax::swing::AbstractAction::putValue(::java::lang::String* arg0, ::java::lang::Object* arg1)");
}

/* private: void javax::swing::AbstractAction::readObject(::java::io::ObjectInputStream* arg0) */
void javax::swing::AbstractAction::removePropertyChangeListener(::java::beans::PropertyChangeListener* arg0)
{ /* stub */
    unimplemented_(u"void javax::swing::AbstractAction::removePropertyChangeListener(::java::beans::PropertyChangeListener* arg0)");
}

void javax::swing::AbstractAction::setEnabled(bool arg0)
{ /* stub */
    this->enabled = arg0; /* setter */
}

void javax::swing::AbstractAction::setEnabledFromAction(JComponent* arg0, Action* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void javax::swing::AbstractAction::setEnabledFromAction(JComponent* arg0, Action* arg1)");
}

void javax::swing::AbstractAction::setToolTipTextFromAction(JComponent* arg0, Action* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void javax::swing::AbstractAction::setToolTipTextFromAction(JComponent* arg0, Action* arg1)");
}

bool javax::swing::AbstractAction::shouldReconfigure(::java::beans::PropertyChangeEvent* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool javax::swing::AbstractAction::shouldReconfigure(::java::beans::PropertyChangeEvent* arg0)");
    return 0;
}

/* private: void javax::swing::AbstractAction::writeObject(::java::io::ObjectOutputStream* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::swing::AbstractAction::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.swing.AbstractAction", 26);
    return c;
}

java::lang::Class* javax::swing::AbstractAction::getClass0()
{
    return class_();
}

