// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/time/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/util/calendar/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>

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
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class java::util::Date
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

private:
    ::sun::util::calendar::BaseCalendar_Date* cdate {  };
    static int32_t defaultCenturyStart_;
    int64_t fastTime {  };
    static ::sun::util::calendar::BaseCalendar* gcal_;
    static ::sun::util::calendar::BaseCalendar* jcal_;
    static constexpr int64_t serialVersionUID { int64_t(7523967970034938905LL) };
    static ::int32_tArray* ttb_;
    static ::java::lang::StringArray* wtb_;

protected:
    void ctor();
    void ctor(int64_t arg0);
    void ctor(::java::lang::String* arg0);
    void ctor(int32_t arg0, int32_t arg1, int32_t arg2);
    void ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);
    void ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5);

public:
    static int64_t UTC(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5);
    virtual bool after(Date* arg0);
    virtual bool before(Date* arg0);
    ::java::lang::Object* clone() override;
    virtual int32_t compareTo(Date* arg0);
    /*static ::java::lang::StringBuilder* convertToAbbr(::java::lang::StringBuilder* arg0, ::java::lang::String* arg1); (private) */
    bool equals(::java::lang::Object* arg0) override;
    static Date* from(::java::time::Instant* arg0);
    /*::sun::util::calendar::BaseCalendar_Date* getCalendarDate(); (private) */
    /*static ::sun::util::calendar::BaseCalendar* getCalendarSystem(int32_t arg0); (private) */
    /*static ::sun::util::calendar::BaseCalendar* getCalendarSystem(int64_t arg0); (private) */
    /*static ::sun::util::calendar::BaseCalendar* getCalendarSystem(::sun::util::calendar::BaseCalendar_Date* arg0); (private) */
    virtual int32_t getDate();
    virtual int32_t getDay();
    virtual int32_t getHours();
    /*static ::sun::util::calendar::BaseCalendar* getJulianCalendar(); (private) */

public: /* package */
    static int64_t getMillisOf(Date* arg0);

public:
    virtual int32_t getMinutes();
    virtual int32_t getMonth();
    virtual int32_t getSeconds();
    virtual int64_t getTime();
    /*int64_t getTimeImpl(); (private) */
    virtual int32_t getTimezoneOffset();
    virtual int32_t getYear();
    int32_t hashCode() override;
    /*::sun::util::calendar::BaseCalendar_Date* normalize(); (private) */
    /*::sun::util::calendar::BaseCalendar_Date* normalize(::sun::util::calendar::BaseCalendar_Date* arg0); (private) */
    static int64_t parse(::java::lang::String* arg0);
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    virtual void setDate(int32_t arg0);
    virtual void setHours(int32_t arg0);
    virtual void setMinutes(int32_t arg0);
    virtual void setMonth(int32_t arg0);
    virtual void setSeconds(int32_t arg0);
    virtual void setTime(int64_t arg0);
    virtual void setYear(int32_t arg0);
    virtual ::java::lang::String* toGMTString();
    virtual ::java::time::Instant* toInstant();
    virtual ::java::lang::String* toLocaleString();
    ::java::lang::String* toString() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    Date();
    Date(int64_t arg0);
    Date(::java::lang::String* arg0);
    Date(int32_t arg0, int32_t arg1, int32_t arg2);
    Date(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);
    Date(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5);
protected:
    Date(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;

private:
    static int32_t& defaultCenturyStart();
    static ::sun::util::calendar::BaseCalendar*& gcal();
    static ::sun::util::calendar::BaseCalendar*& jcal();
    static ::int32_tArray*& ttb();
    static ::java::lang::StringArray*& wtb();
    virtual ::java::lang::Class* getClass0();
};
