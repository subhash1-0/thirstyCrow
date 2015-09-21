// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <javax/swing/text/DefaultFormatter_ReplaceHolder.hpp>

struct default_init_tag;

class javax::swing::text::InternationalFormatter_ExtendedReplaceHolder
    : public DefaultFormatter_ReplaceHolder
{

public:
    typedef DefaultFormatter_ReplaceHolder super;

public: /* package */
    int32_t endOffset {  };
    int32_t endTextLength {  };

protected:
    void ctor();

public: /* package */
    virtual void resetFromValue(InternationalFormatter* arg0);

    // Generated
    InternationalFormatter_ExtendedReplaceHolder();
protected:
    InternationalFormatter_ExtendedReplaceHolder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
