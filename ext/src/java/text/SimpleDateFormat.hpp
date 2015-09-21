// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <java/text/DateFormat.hpp>

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
    } // lang

    namespace text
    {
typedef ::SubArray< ::java::text::AttributedCharacterIterator_Attribute, ::java::lang::ObjectArray, ::java::io::SerializableArray > AttributedCharacterIterator_AttributeArray;
typedef ::SubArray< ::java::text::Format_Field, AttributedCharacterIterator_AttributeArray > Format_FieldArray;
typedef ::SubArray< ::java::text::DateFormat_Field, Format_FieldArray > DateFormat_FieldArray;
    } // text

    namespace lang
    {
typedef ::SubArray< ::java::lang::StringArray, CloneableArray, ::java::io::SerializableArray > StringArrayArray;
    } // lang
} // java

struct default_init_tag;

class java::text::SimpleDateFormat
    : public DateFormat
{

public:
    typedef DateFormat super;

private:
    static bool $assertionsDisabled_;
    static ::java::lang::String* GMT_;
    static constexpr int32_t MILLIS_PER_MINUTE { int32_t(60000) };
    static ::int32_tArray* PATTERN_INDEX_TO_CALENDAR_FIELD_;
    static ::int32_tArray* PATTERN_INDEX_TO_DATE_FORMAT_FIELD_;
    static DateFormat_FieldArray* PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID_;
    static ::int32_tArray* REST_OF_STYLES_;
    static constexpr int32_t TAG_QUOTE_ASCII_CHAR { int32_t(100) };
    static constexpr int32_t TAG_QUOTE_CHARS { int32_t(101) };
    static ::java::util::concurrent::ConcurrentMap* cachedNumberFormatData_;
    ::char16_tArray* compiledPattern {  };

public: /* package */
    static constexpr int32_t currentSerialVersion { int32_t(1) };

private:
    ::java::util::Date* defaultCenturyStart {  };
    int32_t defaultCenturyStartYear {  };
    bool forceStandaloneForm {  };
    DateFormatSymbols* formatData {  };
    bool hasFollowingMinusSign {  };
    ::java::util::Locale* locale {  };
    char16_t minusSign {  };
    NumberFormat* originalNumberFormat {  };
    ::java::lang::String* originalNumberPattern {  };
    ::java::lang::String* pattern {  };
    int32_t serialVersionOnStream {  };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(4774881970558875024LL) };
    bool useDateFormatSymbols_ {  };

private:
    char16_t zeroDigit {  };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::String* arg0, ::java::util::Locale* arg1);
    void ctor(::java::lang::String* arg0, DateFormatSymbols* arg1);

public:
    virtual void applyLocalizedPattern(::java::lang::String* arg0);
    virtual void applyPattern(::java::lang::String* arg0);
    /*void applyPatternImpl(::java::lang::String* arg0); (private) */
    /*void checkNegativeNumberExpression(); (private) */
    ::java::lang::Object* clone() override;
    /*::char16_tArray* compile(::java::lang::String* arg0); (private) */
    /*static void encode(int32_t arg0, int32_t arg1, ::java::lang::StringBuilder* arg2); (private) */
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::StringBuffer* format(::java::util::Date* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2) override;
    /*::java::lang::StringBuffer* format(::java::util::Date* arg0, ::java::lang::StringBuffer* arg1, Format_FieldDelegate* arg2); (private) */
    AttributedCharacterIterator* formatToCharacterIterator(::java::lang::Object* arg0) override;
    virtual ::java::util::Date* get2DigitYearStart();
    virtual DateFormatSymbols* getDateFormatSymbols();
    /*::java::util::Map* getDisplayNamesMap(int32_t arg0, ::java::util::Locale* arg1); (private) */
    int32_t hashCode() override;
    /*void initialize(::java::util::Locale* arg0); (private) */
    /*void initializeCalendar(::java::util::Locale* arg0); (private) */
    /*void initializeDefaultCentury(); (private) */
    /*bool isDigit(char16_t arg0); (private) */
    /*bool matchDSTString(::java::lang::String* arg0, int32_t arg1, int32_t arg2, int32_t arg3, ::java::lang::StringArrayArray* arg4); (private) */
    /*int32_t matchString(::java::lang::String* arg0, int32_t arg1, int32_t arg2, ::java::lang::StringArray* arg3, CalendarBuilder* arg4); (private) */
    /*int32_t matchString(::java::lang::String* arg0, int32_t arg1, int32_t arg2, ::java::util::Map* arg3, CalendarBuilder* arg4); (private) */
    /*int32_t matchZoneString(::java::lang::String* arg0, int32_t arg1, ::java::lang::StringArray* arg2); (private) */
    ::java::util::Date* parse(::java::lang::String* arg0, ParsePosition* arg1) override;
    /*void parseAmbiguousDatesAsAfter(::java::util::Date* arg0); (private) */
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    virtual void set2DigitYearStart(::java::util::Date* arg0);
    virtual void setDateFormatSymbols(DateFormatSymbols* arg0);
    /*void subFormat(int32_t arg0, int32_t arg1, Format_FieldDelegate* arg2, ::java::lang::StringBuffer* arg3, bool arg4); (private) */
    /*int32_t subParse(::java::lang::String* arg0, int32_t arg1, int32_t arg2, int32_t arg3, bool arg4, ::boolArray* arg5, ParsePosition* arg6, bool arg7, CalendarBuilder* arg8); (private) */
    /*int32_t subParseNumericZone(::java::lang::String* arg0, int32_t arg1, int32_t arg2, int32_t arg3, bool arg4, CalendarBuilder* arg5); (private) */
    /*int32_t subParseZoneString(::java::lang::String* arg0, int32_t arg1, CalendarBuilder* arg2); (private) */
    virtual ::java::lang::String* toLocalizedPattern();
    virtual ::java::lang::String* toPattern();
    /*::java::lang::String* translatePattern(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2); (private) */
    /*bool useDateFormatSymbols(); (private) */
    /*void zeroPaddingNumber(int32_t arg0, int32_t arg1, int32_t arg2, ::java::lang::StringBuffer* arg3); (private) */

    // Generated
    SimpleDateFormat();
    SimpleDateFormat(::java::lang::String* arg0);
    SimpleDateFormat(::java::lang::String* arg0, ::java::util::Locale* arg1);
    SimpleDateFormat(::java::lang::String* arg0, DateFormatSymbols* arg1);
protected:
    SimpleDateFormat(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::java::lang::String* format(::java::util::Date* arg0);
    ::java::lang::StringBuffer* format(::java::lang::Object* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2);
    virtual ::java::util::Date* parse(::java::lang::String* arg0);
    ::java::lang::String* format(::java::lang::Object* arg0);

public: /* package */
    static bool& $assertionsDisabled();

private:
    static ::java::lang::String*& GMT();
    static ::int32_tArray*& PATTERN_INDEX_TO_CALENDAR_FIELD();
    static ::int32_tArray*& PATTERN_INDEX_TO_DATE_FORMAT_FIELD();
    static DateFormat_FieldArray*& PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID();
    static ::int32_tArray*& REST_OF_STYLES();
    static ::java::util::concurrent::ConcurrentMap*& cachedNumberFormatData();
    virtual ::java::lang::Class* getClass0();
};
