// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class javax::swing::text::DocumentFilter
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    virtual void insertString(DocumentFilter_FilterBypass* arg0, int32_t arg1, ::java::lang::String* arg2, AttributeSet* arg3);
    virtual void remove(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2);
    virtual void replace(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3, AttributeSet* arg4);

    // Generated
    DocumentFilter();
protected:
    DocumentFilter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
