// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <javax/swing/text/DocumentFilter.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class javax::swing::text::DefaultFormatter_DefaultDocumentFilter
    : public DocumentFilter
    , public virtual ::java::io::Serializable
{

public:
    typedef DocumentFilter super;

public: /* package */
    DefaultFormatter* this$0 {  };

    /*void ctor(); (private) */

public:
    void insertString(DocumentFilter_FilterBypass* arg0, int32_t arg1, ::java::lang::String* arg2, AttributeSet* arg3) override;
    void remove(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2) override;
    void replace(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3, AttributeSet* arg4) override;

    // Generated
    DefaultFormatter_DefaultDocumentFilter(DefaultFormatter *DefaultFormatter_this);
protected:
    DefaultFormatter_DefaultDocumentFilter(DefaultFormatter *DefaultFormatter_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    DefaultFormatter *DefaultFormatter_this;

private:
    virtual ::java::lang::Class* getClass0();
};
