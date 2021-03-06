// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Appendable.hpp>
#include <java/lang/CharSequence.hpp>

struct default_init_tag;

class java::lang::AbstractStringBuilder
    : public virtual Object
    , public virtual Appendable
    , public virtual CharSequence
{

public:
    typedef Object super;

public: /* package */
    int32_t count {  };
    ::char16_tArray* value {  };

protected:
    void ctor();
    void ctor(int32_t arg0);

public:
    virtual AbstractStringBuilder* append(Object* arg0);
    virtual AbstractStringBuilder* append(String* arg0);
    virtual AbstractStringBuilder* append(StringBuffer* arg0);

public: /* package */
    virtual AbstractStringBuilder* append(AbstractStringBuilder* arg0);

public:
    AbstractStringBuilder* append(CharSequence* arg0) override;
    virtual AbstractStringBuilder* append(::char16_tArray* arg0);
    virtual AbstractStringBuilder* append(bool arg0);
    AbstractStringBuilder* append(char16_t arg0) override;
    virtual AbstractStringBuilder* append(int32_t arg0);
    virtual AbstractStringBuilder* append(int64_t arg0);
    virtual AbstractStringBuilder* append(float arg0);
    virtual AbstractStringBuilder* append(double arg0);
    AbstractStringBuilder* append(CharSequence* arg0, int32_t arg1, int32_t arg2) override;
    virtual AbstractStringBuilder* append(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    virtual AbstractStringBuilder* appendCodePoint(int32_t arg0);
    /*AbstractStringBuilder* appendNull(); (private) */
    virtual int32_t capacity();
    char16_t charAt(int32_t arg0) override;
    virtual int32_t codePointAt(int32_t arg0);
    virtual int32_t codePointBefore(int32_t arg0);
    virtual int32_t codePointCount(int32_t arg0, int32_t arg1);
    virtual AbstractStringBuilder* delete_(int32_t arg0, int32_t arg1);
    virtual AbstractStringBuilder* deleteCharAt(int32_t arg0);
    virtual void ensureCapacity(int32_t arg0);
    /*void ensureCapacityInternal(int32_t arg0); (private) */

public: /* package */
    virtual void expandCapacity(int32_t arg0);

public:
    virtual void getChars(int32_t arg0, int32_t arg1, ::char16_tArray* arg2, int32_t arg3);

public: /* package */
    ::char16_tArray* getValue();

public:
    virtual int32_t indexOf(String* arg0);
    virtual int32_t indexOf(String* arg0, int32_t arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, Object* arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, String* arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, ::char16_tArray* arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, CharSequence* arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, bool arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, char16_t arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, int32_t arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, int64_t arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, float arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, double arg1);
    virtual AbstractStringBuilder* insert(int32_t arg0, ::char16_tArray* arg1, int32_t arg2, int32_t arg3);
    virtual AbstractStringBuilder* insert(int32_t arg0, CharSequence* arg1, int32_t arg2, int32_t arg3);
    virtual int32_t lastIndexOf(String* arg0);
    virtual int32_t lastIndexOf(String* arg0, int32_t arg1);
    int32_t length() override;
    virtual int32_t offsetByCodePoints(int32_t arg0, int32_t arg1);
    virtual AbstractStringBuilder* replace(int32_t arg0, int32_t arg1, String* arg2);
    virtual AbstractStringBuilder* reverse();
    /*void reverseAllValidSurrogatePairs(); (private) */
    virtual void setCharAt(int32_t arg0, char16_t arg1);
    virtual void setLength(int32_t arg0);
    CharSequence* subSequence(int32_t arg0, int32_t arg1) override;
    virtual String* substring(int32_t arg0);
    virtual String* substring(int32_t arg0, int32_t arg1);
    /*String* toString(); (already declared) */
    virtual void trimToSize();

    // Generated

public: /* package */
    AbstractStringBuilder();
    AbstractStringBuilder(int32_t arg0);
protected:
    AbstractStringBuilder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
