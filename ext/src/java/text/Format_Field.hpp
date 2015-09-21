// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/text/AttributedCharacterIterator_Attribute.hpp>

struct default_init_tag;

class java::text::Format_Field
    : public AttributedCharacterIterator_Attribute
{

public:
    typedef AttributedCharacterIterator_Attribute super;

private:
    static constexpr int64_t serialVersionUID { int64_t(276966692217360283LL) };

protected:
    void ctor(::java::lang::String* arg0);

    // Generated

public: /* protected */
    Format_Field(::java::lang::String* arg0);
protected:
    Format_Field(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
