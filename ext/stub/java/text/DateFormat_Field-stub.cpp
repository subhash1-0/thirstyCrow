// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/text/DateFormat_Field.hpp>

extern void unimplemented_(const char16_t* name);
java::text::DateFormat_Field::DateFormat_Field(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::text::DateFormat_Field::DateFormat_Field(::java::lang::String* arg0, int32_t arg1)
    : DateFormat_Field(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::text::DateFormat_Field*& java::text::DateFormat_Field::AM_PM()
{
    clinit();
    return AM_PM_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::AM_PM_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::DAY_OF_MONTH()
{
    clinit();
    return DAY_OF_MONTH_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::DAY_OF_MONTH_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::DAY_OF_WEEK()
{
    clinit();
    return DAY_OF_WEEK_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::DAY_OF_WEEK_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::DAY_OF_WEEK_IN_MONTH()
{
    clinit();
    return DAY_OF_WEEK_IN_MONTH_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::DAY_OF_WEEK_IN_MONTH_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::DAY_OF_YEAR()
{
    clinit();
    return DAY_OF_YEAR_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::DAY_OF_YEAR_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::ERA()
{
    clinit();
    return ERA_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::ERA_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::HOUR0()
{
    clinit();
    return HOUR0_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::HOUR0_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::HOUR1()
{
    clinit();
    return HOUR1_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::HOUR1_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::HOUR_OF_DAY0()
{
    clinit();
    return HOUR_OF_DAY0_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::HOUR_OF_DAY0_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::HOUR_OF_DAY1()
{
    clinit();
    return HOUR_OF_DAY1_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::HOUR_OF_DAY1_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::MILLISECOND()
{
    clinit();
    return MILLISECOND_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::MILLISECOND_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::MINUTE()
{
    clinit();
    return MINUTE_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::MINUTE_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::MONTH()
{
    clinit();
    return MONTH_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::MONTH_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::SECOND()
{
    clinit();
    return SECOND_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::SECOND_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::TIME_ZONE()
{
    clinit();
    return TIME_ZONE_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::TIME_ZONE_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::WEEK_OF_MONTH()
{
    clinit();
    return WEEK_OF_MONTH_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::WEEK_OF_MONTH_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::WEEK_OF_YEAR()
{
    clinit();
    return WEEK_OF_YEAR_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::WEEK_OF_YEAR_;
java::text::DateFormat_Field*& java::text::DateFormat_Field::YEAR()
{
    clinit();
    return YEAR_;
}
java::text::DateFormat_Field* java::text::DateFormat_Field::YEAR_;
java::text::DateFormat_FieldArray*& java::text::DateFormat_Field::calendarToFieldMapping()
{
    clinit();
    return calendarToFieldMapping_;
}
java::text::DateFormat_FieldArray* java::text::DateFormat_Field::calendarToFieldMapping_;
java::util::Map*& java::text::DateFormat_Field::instanceMap()
{
    clinit();
    return instanceMap_;
}
java::util::Map* java::text::DateFormat_Field::instanceMap_;
constexpr int64_t java::text::DateFormat_Field::serialVersionUID;

void ::java::text::DateFormat_Field::ctor(::java::lang::String* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::DateFormat_Field::ctor(::java::lang::String* arg0, int32_t arg1)");
}

int32_t java::text::DateFormat_Field::getCalendarField()
{ /* stub */
return calendarField ; /* getter */
}

java::text::DateFormat_Field* java::text::DateFormat_Field::ofCalendarField(int32_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::text::DateFormat_Field* java::text::DateFormat_Field::ofCalendarField(int32_t arg0)");
    return 0;
}

java::lang::Object* java::text::DateFormat_Field::readResolve()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::text::DateFormat_Field::readResolve()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::text::DateFormat_Field::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.text.DateFormat.Field", 26);
    return c;
}

java::lang::Class* java::text::DateFormat_Field::getClass0()
{
    return class_();
}

