// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/text/SimpleDateFormat.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/util/Date.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
typedef ::SubArray< ::java::lang::StringArray, CloneableArray, ::java::io::SerializableArray > StringArrayArray;
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
java::text::SimpleDateFormat::SimpleDateFormat(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::text::SimpleDateFormat::SimpleDateFormat()
    : SimpleDateFormat(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::text::SimpleDateFormat::SimpleDateFormat(::java::lang::String* arg0)
    : SimpleDateFormat(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::text::SimpleDateFormat::SimpleDateFormat(::java::lang::String* arg0, ::java::util::Locale* arg1)
    : SimpleDateFormat(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::text::SimpleDateFormat::SimpleDateFormat(::java::lang::String* arg0, DateFormatSymbols* arg1)
    : SimpleDateFormat(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

bool& java::text::SimpleDateFormat::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::text::SimpleDateFormat::$assertionsDisabled_;
java::lang::String*& java::text::SimpleDateFormat::GMT()
{
    clinit();
    return GMT_;
}
java::lang::String* java::text::SimpleDateFormat::GMT_;
constexpr int32_t java::text::SimpleDateFormat::MILLIS_PER_MINUTE;
int32_tArray*& java::text::SimpleDateFormat::PATTERN_INDEX_TO_CALENDAR_FIELD()
{
    clinit();
    return PATTERN_INDEX_TO_CALENDAR_FIELD_;
}
int32_tArray* java::text::SimpleDateFormat::PATTERN_INDEX_TO_CALENDAR_FIELD_;
int32_tArray*& java::text::SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD()
{
    clinit();
    return PATTERN_INDEX_TO_DATE_FORMAT_FIELD_;
}
int32_tArray* java::text::SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD_;
java::text::DateFormat_FieldArray*& java::text::SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID()
{
    clinit();
    return PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID_;
}
java::text::DateFormat_FieldArray* java::text::SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID_;
int32_tArray*& java::text::SimpleDateFormat::REST_OF_STYLES()
{
    clinit();
    return REST_OF_STYLES_;
}
int32_tArray* java::text::SimpleDateFormat::REST_OF_STYLES_;
constexpr int32_t java::text::SimpleDateFormat::TAG_QUOTE_ASCII_CHAR;
constexpr int32_t java::text::SimpleDateFormat::TAG_QUOTE_CHARS;
java::util::concurrent::ConcurrentMap*& java::text::SimpleDateFormat::cachedNumberFormatData()
{
    clinit();
    return cachedNumberFormatData_;
}
java::util::concurrent::ConcurrentMap* java::text::SimpleDateFormat::cachedNumberFormatData_;
constexpr int32_t java::text::SimpleDateFormat::currentSerialVersion;
constexpr int64_t java::text::SimpleDateFormat::serialVersionUID;

void ::java::text::SimpleDateFormat::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::SimpleDateFormat::ctor()");
}

void ::java::text::SimpleDateFormat::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::SimpleDateFormat::ctor(::java::lang::String* arg0)");
}

void ::java::text::SimpleDateFormat::ctor(::java::lang::String* arg0, ::java::util::Locale* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::SimpleDateFormat::ctor(::java::lang::String* arg0, ::java::util::Locale* arg1)");
}

void ::java::text::SimpleDateFormat::ctor(::java::lang::String* arg0, DateFormatSymbols* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::SimpleDateFormat::ctor(::java::lang::String* arg0, DateFormatSymbols* arg1)");
}

void java::text::SimpleDateFormat::applyLocalizedPattern(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"void java::text::SimpleDateFormat::applyLocalizedPattern(::java::lang::String* arg0)");
}

void java::text::SimpleDateFormat::applyPattern(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"void java::text::SimpleDateFormat::applyPattern(::java::lang::String* arg0)");
}

/* private: void java::text::SimpleDateFormat::applyPatternImpl(::java::lang::String* arg0) */
/* private: void java::text::SimpleDateFormat::checkNegativeNumberExpression() */
java::lang::Object* java::text::SimpleDateFormat::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::text::SimpleDateFormat::clone()");
    return 0;
}

/* private: char16_tArray* java::text::SimpleDateFormat::compile(::java::lang::String* arg0) */
/* private: void java::text::SimpleDateFormat::encode(int32_t arg0, int32_t arg1, ::java::lang::StringBuilder* arg2) */
bool java::text::SimpleDateFormat::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::text::SimpleDateFormat::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::StringBuffer* java::text::SimpleDateFormat::format(::java::util::Date* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2)
{ /* stub */
    unimplemented_(u"java::lang::StringBuffer* java::text::SimpleDateFormat::format(::java::util::Date* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2)");
    return 0;
}

/* private: java::lang::StringBuffer* java::text::SimpleDateFormat::format(::java::util::Date* arg0, ::java::lang::StringBuffer* arg1, Format_FieldDelegate* arg2) */
java::text::AttributedCharacterIterator* java::text::SimpleDateFormat::formatToCharacterIterator(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::text::AttributedCharacterIterator* java::text::SimpleDateFormat::formatToCharacterIterator(::java::lang::Object* arg0)");
    return 0;
}

java::util::Date* java::text::SimpleDateFormat::get2DigitYearStart()
{ /* stub */
    unimplemented_(u"java::util::Date* java::text::SimpleDateFormat::get2DigitYearStart()");
    return 0;
}

java::text::DateFormatSymbols* java::text::SimpleDateFormat::getDateFormatSymbols()
{ /* stub */
    unimplemented_(u"java::text::DateFormatSymbols* java::text::SimpleDateFormat::getDateFormatSymbols()");
    return 0;
}

/* private: java::util::Map* java::text::SimpleDateFormat::getDisplayNamesMap(int32_t arg0, ::java::util::Locale* arg1) */
int32_t java::text::SimpleDateFormat::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::text::SimpleDateFormat::hashCode()");
    return 0;
}

/* private: void java::text::SimpleDateFormat::initialize(::java::util::Locale* arg0) */
/* private: void java::text::SimpleDateFormat::initializeCalendar(::java::util::Locale* arg0) */
/* private: void java::text::SimpleDateFormat::initializeDefaultCentury() */
/* private: bool java::text::SimpleDateFormat::isDigit(char16_t arg0) */
/* private: bool java::text::SimpleDateFormat::matchDSTString(::java::lang::String* arg0, int32_t arg1, int32_t arg2, int32_t arg3, ::java::lang::StringArrayArray* arg4) */
/* private: int32_t java::text::SimpleDateFormat::matchString(::java::lang::String* arg0, int32_t arg1, int32_t arg2, ::java::lang::StringArray* arg3, CalendarBuilder* arg4) */
/* private: int32_t java::text::SimpleDateFormat::matchString(::java::lang::String* arg0, int32_t arg1, int32_t arg2, ::java::util::Map* arg3, CalendarBuilder* arg4) */
/* private: int32_t java::text::SimpleDateFormat::matchZoneString(::java::lang::String* arg0, int32_t arg1, ::java::lang::StringArray* arg2) */
java::util::Date* java::text::SimpleDateFormat::parse(::java::lang::String* arg0, ParsePosition* arg1)
{ /* stub */
    unimplemented_(u"java::util::Date* java::text::SimpleDateFormat::parse(::java::lang::String* arg0, ParsePosition* arg1)");
    return 0;
}

/* private: void java::text::SimpleDateFormat::parseAmbiguousDatesAsAfter(::java::util::Date* arg0) */
/* private: void java::text::SimpleDateFormat::readObject(::java::io::ObjectInputStream* arg0) */
void java::text::SimpleDateFormat::set2DigitYearStart(::java::util::Date* arg0)
{ /* stub */
    unimplemented_(u"void java::text::SimpleDateFormat::set2DigitYearStart(::java::util::Date* arg0)");
}

void java::text::SimpleDateFormat::setDateFormatSymbols(DateFormatSymbols* arg0)
{ /* stub */
    unimplemented_(u"void java::text::SimpleDateFormat::setDateFormatSymbols(DateFormatSymbols* arg0)");
}

/* private: void java::text::SimpleDateFormat::subFormat(int32_t arg0, int32_t arg1, Format_FieldDelegate* arg2, ::java::lang::StringBuffer* arg3, bool arg4) */
/* private: int32_t java::text::SimpleDateFormat::subParse(::java::lang::String* arg0, int32_t arg1, int32_t arg2, int32_t arg3, bool arg4, ::boolArray* arg5, ParsePosition* arg6, bool arg7, CalendarBuilder* arg8) */
/* private: int32_t java::text::SimpleDateFormat::subParseNumericZone(::java::lang::String* arg0, int32_t arg1, int32_t arg2, int32_t arg3, bool arg4, CalendarBuilder* arg5) */
/* private: int32_t java::text::SimpleDateFormat::subParseZoneString(::java::lang::String* arg0, int32_t arg1, CalendarBuilder* arg2) */
java::lang::String* java::text::SimpleDateFormat::toLocalizedPattern()
{ /* stub */
    unimplemented_(u"java::lang::String* java::text::SimpleDateFormat::toLocalizedPattern()");
    return 0;
}

java::lang::String* java::text::SimpleDateFormat::toPattern()
{ /* stub */
    unimplemented_(u"java::lang::String* java::text::SimpleDateFormat::toPattern()");
    return 0;
}

/* private: java::lang::String* java::text::SimpleDateFormat::translatePattern(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2) */
/* private: bool java::text::SimpleDateFormat::useDateFormatSymbols() */
/* private: void java::text::SimpleDateFormat::zeroPaddingNumber(int32_t arg0, int32_t arg1, int32_t arg2, ::java::lang::StringBuffer* arg3) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::text::SimpleDateFormat::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.text.SimpleDateFormat", 26);
    return c;
}

java::lang::String* java::text::SimpleDateFormat::format(::java::util::Date* arg0)
{
    return super::format(arg0);
}

java::lang::StringBuffer* java::text::SimpleDateFormat::format(::java::lang::Object* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2)
{
    return super::format(arg0, arg1, arg2);
}

java::util::Date* java::text::SimpleDateFormat::parse(::java::lang::String* arg0)
{
    return super::parse(arg0);
}

java::lang::String* java::text::SimpleDateFormat::format(::java::lang::Object* arg0)
{
    return super::format(arg0);
}

java::lang::Class* java::text::SimpleDateFormat::getClass0()
{
    return class_();
}

