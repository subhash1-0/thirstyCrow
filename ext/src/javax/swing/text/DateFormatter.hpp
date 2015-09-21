// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <javax/swing/text/InternationalFormatter.hpp>

struct default_init_tag;

class javax::swing::text::DateFormatter
    : public InternationalFormatter
{

public:
    typedef InternationalFormatter super;

protected:
    void ctor();
    void ctor(::java::text::DateFormat* arg0);

public: /* package */
    ::java::lang::Object* adjustValue(::java::lang::Object* arg0, ::java::util::Map* arg1, ::java::lang::Object* arg2, int32_t arg3) override;
    ::java::lang::Object* getAdjustField(int32_t arg0, ::java::util::Map* arg1) override;
    /*::java::util::Calendar* getCalendar(); (private) */
    bool getSupportsIncrement() override;

public:
    virtual void setFormat(::java::text::DateFormat* arg0);

    // Generated
    DateFormatter();
    DateFormatter(::java::text::DateFormat* arg0);
protected:
    DateFormatter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void setFormat(::java::text::Format* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
