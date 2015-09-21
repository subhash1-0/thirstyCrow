// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/beans/fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/swing/fwd-pastry-2.1.hpp>
#include <javax/swing/event/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <javax/swing/Action.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

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

struct default_init_tag;

class javax::swing::AbstractAction
    : public virtual ::java::lang::Object
    , public virtual Action
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::Boolean* RECONFIGURE_ON_NULL_;
    ArrayTable* arrayTable {  };

public: /* protected */
    ::javax::swing::event::SwingPropertyChangeSupport* changeSupport {  };
    bool enabled {  };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::String* arg0, Icon* arg1);

public:
    void addPropertyChangeListener(::java::beans::PropertyChangeListener* arg0) override;

public: /* protected */
    ::java::lang::Object* clone() override;
    virtual void firePropertyChange(::java::lang::String* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2);

public:
    virtual ::java::lang::ObjectArray* getKeys();
    virtual ::java::beans::PropertyChangeListenerArray* getPropertyChangeListeners();
    ::java::lang::Object* getValue(::java::lang::String* arg0) override;

public: /* package */
    static bool hasSelectedKey(Action* arg0);

public:
    bool isEnabled() override;

public: /* package */
    static bool isSelected(Action* arg0);

public:
    void putValue(::java::lang::String* arg0, ::java::lang::Object* arg1) override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    void removePropertyChangeListener(::java::beans::PropertyChangeListener* arg0) override;
    void setEnabled(bool arg0) override;

public: /* package */
    static void setEnabledFromAction(JComponent* arg0, Action* arg1);
    static void setToolTipTextFromAction(JComponent* arg0, Action* arg1);
    static bool shouldReconfigure(::java::beans::PropertyChangeEvent* arg0);
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated

public:
    AbstractAction();
    AbstractAction(::java::lang::String* arg0);
    AbstractAction(::java::lang::String* arg0, Icon* arg1);
protected:
    AbstractAction(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::lang::Boolean*& RECONFIGURE_ON_NULL();
    virtual ::java::lang::Class* getClass0();
};
