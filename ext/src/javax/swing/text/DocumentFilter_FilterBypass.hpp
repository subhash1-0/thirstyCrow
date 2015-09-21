// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class javax::swing::text::DocumentFilter_FilterBypass
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    virtual Document* getDocument() = 0;
    virtual void insertString(int32_t arg0, ::java::lang::String* arg1, AttributeSet* arg2) = 0;
    virtual void remove(int32_t arg0, int32_t arg1) = 0;
    virtual void replace(int32_t arg0, int32_t arg1, ::java::lang::String* arg2, AttributeSet* arg3) = 0;

    // Generated
    DocumentFilter_FilterBypass();
protected:
    DocumentFilter_FilterBypass(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
