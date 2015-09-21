// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <stddef.h>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/charset/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/CharSequence.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::ObjectStreamField, ::java::lang::ObjectArray, ::java::lang::ComparableArray > ObjectStreamFieldArray;
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class java::lang::String final
    : public virtual Object
    , public ::java::io::Serializable
    , public Comparable
    , public CharSequence
{

public:
    typedef Object super;

private:
    static ::java::util::Comparator* CASE_INSENSITIVE_ORDER_;
    int32_t hash {  };
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;
    static constexpr int64_t serialVersionUID { int64_t(-6849794470754667710LL) };
    ::char16_tArray* value {  };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(::char16_tArray* arg0);
    void ctor(::int8_tArray* arg0);
    void ctor(StringBuffer* arg0);
    void ctor(StringBuilder* arg0);
    void ctor(::int8_tArray* arg0, int32_t arg1);
    void ctor(::int8_tArray* arg0, String* arg1);
    void ctor(::int8_tArray* arg0, ::java::nio::charset::Charset* arg1);
    void ctor(::char16_tArray* arg0, bool arg1);
    void ctor(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    void ctor(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    void ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    void ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3);
    void ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2, String* arg3);
    void ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::java::nio::charset::Charset* arg3);

public:
    char16_t charAt(int32_t arg0) override;
    /*static void checkBounds(::int8_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    int32_t codePointAt(int32_t arg0);
    int32_t codePointBefore(int32_t arg0);
    int32_t codePointCount(int32_t arg0, int32_t arg1);
    int32_t compareTo(String* arg0);
    int32_t compareToIgnoreCase(String* arg0);
    String* concat(String* arg0);
    bool contains(CharSequence* arg0);
    bool contentEquals(StringBuffer* arg0);
    bool contentEquals(CharSequence* arg0);
    static String* copyValueOf(::char16_tArray* arg0);
    static String* copyValueOf(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    bool endsWith(String* arg0);
    bool equals(Object* arg0) override;
    bool equalsIgnoreCase(String* arg0);
    static String* format(String* arg0, ObjectArray* arg1);
    static String* format(::java::util::Locale* arg0, String* arg1, ObjectArray* arg2);
    ::int8_tArray* getBytes();
    ::int8_tArray* getBytes(String* arg0);
    ::int8_tArray* getBytes(::java::nio::charset::Charset* arg0);
    void getBytes(int32_t arg0, int32_t arg1, ::int8_tArray* arg2, int32_t arg3);

public: /* package */
    void getChars(::char16_tArray* arg0, int32_t arg1);

public:
    void getChars(int32_t arg0, int32_t arg1, ::char16_tArray* arg2, int32_t arg3);
    int32_t hashCode() override;
    int32_t indexOf(int32_t arg0);
    int32_t indexOf(String* arg0);
    int32_t indexOf(int32_t arg0, int32_t arg1);
    int32_t indexOf(String* arg0, int32_t arg1);

public: /* package */
    static int32_t indexOf(::char16_tArray* arg0, int32_t arg1, int32_t arg2, String* arg3, int32_t arg4);
    static int32_t indexOf(::char16_tArray* arg0, int32_t arg1, int32_t arg2, ::char16_tArray* arg3, int32_t arg4, int32_t arg5, int32_t arg6);
    /*int32_t indexOfSupplementary(int32_t arg0, int32_t arg1); (private) */

public:
    String* intern();
    bool isEmpty();
    static String* join(CharSequence* arg0, CharSequenceArray* arg1);
    static String* join(CharSequence* arg0, Iterable* arg1);
    int32_t lastIndexOf(int32_t arg0);
    int32_t lastIndexOf(String* arg0);
    int32_t lastIndexOf(int32_t arg0, int32_t arg1);
    int32_t lastIndexOf(String* arg0, int32_t arg1);

public: /* package */
    static int32_t lastIndexOf(::char16_tArray* arg0, int32_t arg1, int32_t arg2, String* arg3, int32_t arg4);
    static int32_t lastIndexOf(::char16_tArray* arg0, int32_t arg1, int32_t arg2, ::char16_tArray* arg3, int32_t arg4, int32_t arg5, int32_t arg6);
    /*int32_t lastIndexOfSupplementary(int32_t arg0, int32_t arg1); (private) */

public:
    int32_t length() override;
    bool matches(String* arg0);
    /*bool nonSyncContentEquals(AbstractStringBuilder* arg0); (private) */
    int32_t offsetByCodePoints(int32_t arg0, int32_t arg1);
    bool regionMatches(int32_t arg0, String* arg1, int32_t arg2, int32_t arg3);
    bool regionMatches(bool arg0, int32_t arg1, String* arg2, int32_t arg3, int32_t arg4);
    String* replace(char16_t arg0, char16_t arg1);
    String* replace(CharSequence* arg0, CharSequence* arg1);
    String* replaceAll(String* arg0, String* arg1);
    String* replaceFirst(String* arg0, String* arg1);
    StringArray* split(String* arg0);
    StringArray* split(String* arg0, int32_t arg1);
    bool startsWith(String* arg0);
    bool startsWith(String* arg0, int32_t arg1);
    CharSequence* subSequence(int32_t arg0, int32_t arg1) override;
    String* substring(int32_t arg0);
    String* substring(int32_t arg0, int32_t arg1);
    ::char16_tArray* toCharArray_();
    String* toLowerCase();
    String* toLowerCase(::java::util::Locale* arg0);
    String* toString() override;
    String* toUpperCase();
    String* toUpperCase(::java::util::Locale* arg0);
    String* trim();
    static String* valueOf(Object* arg0);
    static String* valueOf(::char16_tArray* arg0);
    static String* valueOf(bool arg0);
    static String* valueOf(char16_t arg0);
    static String* valueOf(int32_t arg0);
    static String* valueOf(int64_t arg0);
    static String* valueOf(float arg0);
    static String* valueOf(double arg0);
    static String* valueOf(::char16_tArray* arg0, int32_t arg1, int32_t arg2);

    // Generated
    String();
    String(String* arg0);
    String(::char16_tArray* arg0);
    String(::int8_tArray* arg0);
    String(StringBuffer* arg0);
    String(StringBuilder* arg0);
    String(::int8_tArray* arg0, int32_t arg1);
    String(::int8_tArray* arg0, String* arg1);
    String(::int8_tArray* arg0, ::java::nio::charset::Charset* arg1);

public: /* package */
    String(::char16_tArray* arg0, bool arg1);

public:
    String(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    String(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    String(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    String(::int8_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3);
    String(::int8_tArray* arg0, int32_t arg1, int32_t arg2, String* arg3);
    String(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::java::nio::charset::Charset* arg3);
protected:
    String(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* o) override;
    static ::java::util::Comparator*& CASE_INSENSITIVE_ORDER();

private:
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();
    virtual ::java::lang::Class* getClass0();
    friend String *operator"" _j(const char16_t *s, size_t n);
};
namespace java { namespace lang { String *operator "" _j(const char16_t *p, size_t n); } }
using java::lang::operator "" _j;

