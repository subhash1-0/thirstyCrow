// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class javax::swing::text::DefaultFormatter_ReplaceHolder
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    AttributeSet* attrs {  };
    int32_t cursorPosition {  };
    DocumentFilter_FilterBypass* fb {  };
    int32_t length {  };
    int32_t offset {  };
    ::java::lang::String* text {  };
    ::java::lang::Object* value {  };

protected:
    void ctor();

public: /* package */
    virtual void reset(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3, AttributeSet* arg4);

    // Generated
    DefaultFormatter_ReplaceHolder();
protected:
    DefaultFormatter_ReplaceHolder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
