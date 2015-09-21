// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/AbstractStringBuilder.hpp>
#include <java/io/Serializable.hpp>
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
    } // io
} // java

struct default_init_tag;

class java::lang::StringBuffer final
    : public AbstractStringBuilder
    , public ::java::io::Serializable
    , public virtual CharSequence
{

public:
    typedef AbstractStringBuilder super;

private:
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(3388685877147921107LL) };

private:
    ::char16_tArray* toStringCache {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(String* arg0);
    void ctor(CharSequence* arg0);

public:
    StringBuffer* append(Object* arg0) override;
    StringBuffer* append(String* arg0) override;
    StringBuffer* append(StringBuffer* arg0) override;

public: /* package */
    StringBuffer* append(AbstractStringBuilder* arg0) override;

public:
    StringBuffer* append(CharSequence* arg0) override;
    StringBuffer* append(::char16_tArray* arg0) override;
    StringBuffer* append(bool arg0) override;
    StringBuffer* append(char16_t arg0) override;
    StringBuffer* append(int32_t arg0) override;
    StringBuffer* append(int64_t arg0) override;
    StringBuffer* append(float arg0) override;
    StringBuffer* append(double arg0) override;
    StringBuffer* append(CharSequence* arg0, int32_t arg1, int32_t arg2) override;
    StringBuffer* append(::char16_tArray* arg0, int32_t arg1, int32_t arg2) override;
    StringBuffer* appendCodePoint(int32_t arg0) override;
    int32_t capacity() override;
    char16_t charAt(int32_t arg0) override;
    int32_t codePointAt(int32_t arg0) override;
    int32_t codePointBefore(int32_t arg0) override;
    int32_t codePointCount(int32_t arg0, int32_t arg1) override;
    StringBuffer* delete_(int32_t arg0, int32_t arg1) override;
    StringBuffer* deleteCharAt(int32_t arg0) override;
    void ensureCapacity(int32_t arg0) override;
    void getChars(int32_t arg0, int32_t arg1, ::char16_tArray* arg2, int32_t arg3) override;
    int32_t indexOf(String* arg0) override;
    int32_t indexOf(String* arg0, int32_t arg1) override;
    StringBuffer* insert(int32_t arg0, Object* arg1) override;
    StringBuffer* insert(int32_t arg0, String* arg1) override;
    StringBuffer* insert(int32_t arg0, ::char16_tArray* arg1) override;
    StringBuffer* insert(int32_t arg0, CharSequence* arg1) override;
    StringBuffer* insert(int32_t arg0, bool arg1) override;
    StringBuffer* insert(int32_t arg0, char16_t arg1) override;
    StringBuffer* insert(int32_t arg0, int32_t arg1) override;
    StringBuffer* insert(int32_t arg0, int64_t arg1) override;
    StringBuffer* insert(int32_t arg0, float arg1) override;
    StringBuffer* insert(int32_t arg0, double arg1) override;
    StringBuffer* insert(int32_t arg0, ::char16_tArray* arg1, int32_t arg2, int32_t arg3) override;
    StringBuffer* insert(int32_t arg0, CharSequence* arg1, int32_t arg2, int32_t arg3) override;
    int32_t lastIndexOf(String* arg0) override;
    int32_t lastIndexOf(String* arg0, int32_t arg1) override;
    int32_t length() override;
    int32_t offsetByCodePoints(int32_t arg0, int32_t arg1) override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    StringBuffer* replace(int32_t arg0, int32_t arg1, String* arg2) override;
    StringBuffer* reverse() override;
    void setCharAt(int32_t arg0, char16_t arg1) override;
    void setLength(int32_t arg0) override;
    CharSequence* subSequence(int32_t arg0, int32_t arg1) override;
    String* substring(int32_t arg0) override;
    String* substring(int32_t arg0, int32_t arg1) override;
    String* toString() override;
    void trimToSize() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    StringBuffer();
    StringBuffer(int32_t arg0);
    StringBuffer(String* arg0);
    StringBuffer(CharSequence* arg0);
protected:
    StringBuffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();
    virtual ::java::lang::Class* getClass0();
};
