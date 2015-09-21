// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/util/locale/provider/fwd-pastry-2.1.hpp>
#include <java/text/Format.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Locale, ::java::lang::ObjectArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > LocaleArray;
    } // util
} // java

struct default_init_tag;

class java::text::DateFormat
    : public Format
{

public:
    typedef Format super;
    static constexpr int32_t AM_PM_FIELD { int32_t(14) };
    static constexpr int32_t DATE_FIELD { int32_t(3) };
    static constexpr int32_t DAY_OF_WEEK_FIELD { int32_t(9) };
    static constexpr int32_t DAY_OF_WEEK_IN_MONTH_FIELD { int32_t(11) };
    static constexpr int32_t DAY_OF_YEAR_FIELD { int32_t(10) };
    static constexpr int32_t DEFAULT { int32_t(2) };
    static constexpr int32_t ERA_FIELD { int32_t(0) };
    static constexpr int32_t FULL { int32_t(0) };
    static constexpr int32_t HOUR0_FIELD { int32_t(16) };
    static constexpr int32_t HOUR1_FIELD { int32_t(15) };
    static constexpr int32_t HOUR_OF_DAY0_FIELD { int32_t(5) };
    static constexpr int32_t HOUR_OF_DAY1_FIELD { int32_t(4) };
    static constexpr int32_t LONG { int32_t(1) };
    static constexpr int32_t MEDIUM { int32_t(2) };
    static constexpr int32_t MILLISECOND_FIELD { int32_t(8) };
    static constexpr int32_t MINUTE_FIELD { int32_t(6) };
    static constexpr int32_t MONTH_FIELD { int32_t(2) };
    static constexpr int32_t SECOND_FIELD { int32_t(7) };
    static constexpr int32_t SHORT { int32_t(3) };
    static constexpr int32_t TIMEZONE_FIELD { int32_t(17) };
    static constexpr int32_t WEEK_OF_MONTH_FIELD { int32_t(13) };
    static constexpr int32_t WEEK_OF_YEAR_FIELD { int32_t(12) };
    static constexpr int32_t YEAR_FIELD { int32_t(1) };

public: /* protected */
    ::java::util::Calendar* calendar {  };
    NumberFormat* numberFormat {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(7218322306649953788LL) };

protected:
    void ctor();

public:
    ::java::lang::Object* clone() override;
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::String* format(::java::util::Date* arg0);
    ::java::lang::StringBuffer* format(::java::lang::Object* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2) override;
    virtual ::java::lang::StringBuffer* format(::java::util::Date* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2) = 0;
    /*static DateFormat* get(int32_t arg0, int32_t arg1, int32_t arg2, ::java::util::Locale* arg3); (private) */
    /*static DateFormat* get(::sun::util::locale::provider::LocaleProviderAdapter* arg0, int32_t arg1, int32_t arg2, ::java::util::Locale* arg3); (private) */
    static ::java::util::LocaleArray* getAvailableLocales();
    virtual ::java::util::Calendar* getCalendar();
    static DateFormat* getDateInstance();
    static DateFormat* getDateInstance(int32_t arg0);
    static DateFormat* getDateInstance(int32_t arg0, ::java::util::Locale* arg1);
    static DateFormat* getDateTimeInstance();
    static DateFormat* getDateTimeInstance(int32_t arg0, int32_t arg1);
    static DateFormat* getDateTimeInstance(int32_t arg0, int32_t arg1, ::java::util::Locale* arg2);
    static DateFormat* getInstance();
    virtual NumberFormat* getNumberFormat();
    static DateFormat* getTimeInstance();
    static DateFormat* getTimeInstance(int32_t arg0);
    static DateFormat* getTimeInstance(int32_t arg0, ::java::util::Locale* arg1);
    virtual ::java::util::TimeZone* getTimeZone();
    int32_t hashCode() override;
    virtual bool isLenient();
    virtual ::java::util::Date* parse(::java::lang::String* arg0);
    virtual ::java::util::Date* parse(::java::lang::String* arg0, ParsePosition* arg1) = 0;
    ::java::lang::Object* parseObject(::java::lang::String* arg0, ParsePosition* arg1) override;
    virtual void setCalendar(::java::util::Calendar* arg0);
    virtual void setLenient(bool arg0);
    virtual void setNumberFormat(NumberFormat* arg0);
    virtual void setTimeZone(::java::util::TimeZone* arg0);

    // Generated

public: /* protected */
    DateFormat();
protected:
    DateFormat(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::java::lang::String* format(::java::lang::Object* arg0);
    virtual ::java::lang::Object* parseObject(::java::lang::String* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
