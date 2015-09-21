// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/beans/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/fwd-pastry-2.1.hpp>
#include <java/awt/event/ActionListener.hpp>

struct javax::swing::Action
    : public virtual ::java::awt::event::ActionListener
{

private:
    static ::java::lang::String* ACCELERATOR_KEY_;
    static ::java::lang::String* ACTION_COMMAND_KEY_;
    static ::java::lang::String* DEFAULT_;
    static ::java::lang::String* DISPLAYED_MNEMONIC_INDEX_KEY_;
    static ::java::lang::String* LARGE_ICON_KEY_;
    static ::java::lang::String* LONG_DESCRIPTION_;
    static ::java::lang::String* MNEMONIC_KEY_;
    static ::java::lang::String* NAME_;
    static ::java::lang::String* SELECTED_KEY_;
    static ::java::lang::String* SHORT_DESCRIPTION_;
    static ::java::lang::String* SMALL_ICON_;


public:
    virtual void addPropertyChangeListener(::java::beans::PropertyChangeListener* arg0) = 0;
    virtual ::java::lang::Object* getValue(::java::lang::String* arg0) = 0;
    virtual bool isEnabled() = 0;
    virtual void putValue(::java::lang::String* arg0, ::java::lang::Object* arg1) = 0;
    virtual void removePropertyChangeListener(::java::beans::PropertyChangeListener* arg0) = 0;
    virtual void setEnabled(bool arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
    static ::java::lang::String*& ACCELERATOR_KEY();
    static ::java::lang::String*& ACTION_COMMAND_KEY();
    static ::java::lang::String*& DEFAULT();
    static ::java::lang::String*& DISPLAYED_MNEMONIC_INDEX_KEY();
    static ::java::lang::String*& LARGE_ICON_KEY();
    static ::java::lang::String*& LONG_DESCRIPTION();
    static ::java::lang::String*& MNEMONIC_KEY();
    static ::java::lang::String*& NAME();
    static ::java::lang::String*& SELECTED_KEY();
    static ::java::lang::String*& SHORT_DESCRIPTION();
    static ::java::lang::String*& SMALL_ICON();
};
