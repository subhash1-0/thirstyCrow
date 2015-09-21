// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/awt/event/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <javax/swing/AbstractAction.hpp>

struct default_init_tag;

class javax::swing::text::InternationalFormatter_IncrementAction
    : public ::javax::swing::AbstractAction
{

public:
    typedef ::javax::swing::AbstractAction super;

private:
    int32_t direction {  };

public: /* package */
    InternationalFormatter* this$0 {  };

protected:
    void ctor(::java::lang::String* arg0, int32_t arg1);

public:
    void actionPerformed(::java::awt::event::ActionEvent* arg0) override;

    // Generated

public: /* package */
    InternationalFormatter_IncrementAction(InternationalFormatter *InternationalFormatter_this, ::java::lang::String* arg0, int32_t arg1);
protected:
    InternationalFormatter_IncrementAction(InternationalFormatter *InternationalFormatter_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    InternationalFormatter *InternationalFormatter_this;

private:
    virtual ::java::lang::Class* getClass0();
};
