// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/text/DateFormat.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>

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

extern void unimplemented_(const char16_t* name);
java::text::DateFormat::DateFormat(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::text::DateFormat::DateFormat()
    : DateFormat(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t java::text::DateFormat::AM_PM_FIELD;
constexpr int32_t java::text::DateFormat::DATE_FIELD;
constexpr int32_t java::text::DateFormat::DAY_OF_WEEK_FIELD;
constexpr int32_t java::text::DateFormat::DAY_OF_WEEK_IN_MONTH_FIELD;
constexpr int32_t java::text::DateFormat::DAY_OF_YEAR_FIELD;
constexpr int32_t java::text::DateFormat::DEFAULT;
constexpr int32_t java::text::DateFormat::ERA_FIELD;
constexpr int32_t java::text::DateFormat::FULL;
constexpr int32_t java::text::DateFormat::HOUR0_FIELD;
constexpr int32_t java::text::DateFormat::HOUR1_FIELD;
constexpr int32_t java::text::DateFormat::HOUR_OF_DAY0_FIELD;
constexpr int32_t java::text::DateFormat::HOUR_OF_DAY1_FIELD;
constexpr int32_t java::text::DateFormat::LONG;
constexpr int32_t java::text::DateFormat::MEDIUM;
constexpr int32_t java::text::DateFormat::MILLISECOND_FIELD;
constexpr int32_t java::text::DateFormat::MINUTE_FIELD;
constexpr int32_t java::text::DateFormat::MONTH_FIELD;
constexpr int32_t java::text::DateFormat::SECOND_FIELD;
constexpr int32_t java::text::DateFormat::SHORT;
constexpr int32_t java::text::DateFormat::TIMEZONE_FIELD;
constexpr int32_t java::text::DateFormat::WEEK_OF_MONTH_FIELD;
constexpr int32_t java::text::DateFormat::WEEK_OF_YEAR_FIELD;
constexpr int32_t java::text::DateFormat::YEAR_FIELD;
constexpr int64_t java::text::DateFormat::serialVersionUID;

void ::java::text::DateFormat::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::DateFormat::ctor()");
}

java::lang::Object* java::text::DateFormat::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::text::DateFormat::clone()");
    return 0;
}

bool java::text::DateFormat::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::text::DateFormat::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::String* java::text::DateFormat::format(::java::util::Date* arg0)
{ /* stub */
    unimplemented_(u"java::lang::String* java::text::DateFormat::format(::java::util::Date* arg0)");
    return 0;
}

java::lang::StringBuffer* java::text::DateFormat::format(::java::lang::Object* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2)
{ /* stub */
    unimplemented_(u"java::lang::StringBuffer* java::text::DateFormat::format(::java::lang::Object* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2)");
    return 0;
}

/* private: java::text::DateFormat* java::text::DateFormat::get(int32_t arg0, int32_t arg1, int32_t arg2, ::java::util::Locale* arg3) */
/* private: java::text::DateFormat* java::text::DateFormat::get(::sun::util::locale::provider::LocaleProviderAdapter* arg0, int32_t arg1, int32_t arg2, ::java::util::Locale* arg3) */
java::util::LocaleArray* java::text::DateFormat::getAvailableLocales()
{ /* stub */
    clinit();
    unimplemented_(u"java::util::LocaleArray* java::text::DateFormat::getAvailableLocales()");
    return 0;
}

java::util::Calendar* java::text::DateFormat::getCalendar()
{ /* stub */
return calendar ; /* getter */
}

java::text::DateFormat* java::text::DateFormat::getDateInstance()
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getDateInstance()");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getDateInstance(int32_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getDateInstance(int32_t arg0)");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getDateInstance(int32_t arg0, ::java::util::Locale* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getDateInstance(int32_t arg0, ::java::util::Locale* arg1)");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getDateTimeInstance()
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getDateTimeInstance()");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getDateTimeInstance(int32_t arg0, int32_t arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getDateTimeInstance(int32_t arg0, int32_t arg1)");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getDateTimeInstance(int32_t arg0, int32_t arg1, ::java::util::Locale* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getDateTimeInstance(int32_t arg0, int32_t arg1, ::java::util::Locale* arg2)");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getInstance()
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getInstance()");
    return 0;
}

java::text::NumberFormat* java::text::DateFormat::getNumberFormat()
{ /* stub */
return numberFormat ; /* getter */
}

java::text::DateFormat* java::text::DateFormat::getTimeInstance()
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getTimeInstance()");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getTimeInstance(int32_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getTimeInstance(int32_t arg0)");
    return 0;
}

java::text::DateFormat* java::text::DateFormat::getTimeInstance(int32_t arg0, ::java::util::Locale* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat* java::text::DateFormat::getTimeInstance(int32_t arg0, ::java::util::Locale* arg1)");
    return 0;
}

java::util::TimeZone* java::text::DateFormat::getTimeZone()
{ /* stub */
    unimplemented_(u"java::util::TimeZone* java::text::DateFormat::getTimeZone()");
    return 0;
}

int32_t java::text::DateFormat::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::text::DateFormat::hashCode()");
    return 0;
}

bool java::text::DateFormat::isLenient()
{ /* stub */
    unimplemented_(u"bool java::text::DateFormat::isLenient()");
    return 0;
}

java::util::Date* java::text::DateFormat::parse(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::util::Date* java::text::DateFormat::parse(::java::lang::String* arg0)");
    return 0;
}

java::lang::Object* java::text::DateFormat::parseObject(::java::lang::String* arg0, ParsePosition* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::text::DateFormat::parseObject(::java::lang::String* arg0, ParsePosition* arg1)");
    return 0;
}

void java::text::DateFormat::setCalendar(::java::util::Calendar* arg0)
{ /* stub */
    this->calendar = arg0; /* setter */
}

void java::text::DateFormat::setLenient(bool arg0)
{ /* stub */
    unimplemented_(u"void java::text::DateFormat::setLenient(bool arg0)");
}

void java::text::DateFormat::setNumberFormat(NumberFormat* arg0)
{ /* stub */
    this->numberFormat = arg0; /* setter */
}

void java::text::DateFormat::setTimeZone(::java::util::TimeZone* arg0)
{ /* stub */
    unimplemented_(u"void java::text::DateFormat::setTimeZone(::java::util::TimeZone* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::text::DateFormat::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.text.DateFormat", 20);
    return c;
}

java::lang::String* java::text::DateFormat::format(::java::lang::Object* arg0)
{
    return super::format(arg0);
}

java::lang::Object* java::text::DateFormat::parseObject(::java::lang::String* arg0)
{
    return super::parseObject(arg0);
}

java::lang::Class* java::text::DateFormat::getClass0()
{
    return class_();
}

