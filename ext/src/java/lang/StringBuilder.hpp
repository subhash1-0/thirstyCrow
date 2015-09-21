// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/AbstractStringBuilder.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/CharSequence.hpp>

struct default_init_tag;

class java::lang::StringBuilder final
    : public AbstractStringBuilder
    , public ::java::io::Serializable
    , public virtual CharSequence
{

public:
    typedef AbstractStringBuilder super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(4383685877147921099LL) };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(String* arg0);
    void ctor(CharSequence* arg0);

public:
    StringBuilder* append(Object* arg0) override;
    StringBuilder* append(String* arg0) override;
    StringBuilder* append(StringBuffer* arg0) override;
    StringBuilder* append(CharSequence* arg0) override;
    StringBuilder* append(::char16_tArray* arg0) override;
    StringBuilder* append(bool arg0) override;
    StringBuilder* append(char16_t arg0) override;
    StringBuilder* append(int32_t arg0) override;
    StringBuilder* append(int64_t arg0) override;
    StringBuilder* append(float arg0) override;
    StringBuilder* append(double arg0) override;
    StringBuilder* append(CharSequence* arg0, int32_t arg1, int32_t arg2) override;
    StringBuilder* append(::char16_tArray* arg0, int32_t arg1, int32_t arg2) override;
    StringBuilder* appendCodePoint(int32_t arg0) override;
    StringBuilder* delete_(int32_t arg0, int32_t arg1) override;
    StringBuilder* deleteCharAt(int32_t arg0) override;
    int32_t indexOf(String* arg0) override;
    int32_t indexOf(String* arg0, int32_t arg1) override;
    StringBuilder* insert(int32_t arg0, Object* arg1) override;
    StringBuilder* insert(int32_t arg0, String* arg1) override;
    StringBuilder* insert(int32_t arg0, ::char16_tArray* arg1) override;
    StringBuilder* insert(int32_t arg0, CharSequence* arg1) override;
    StringBuilder* insert(int32_t arg0, bool arg1) override;
    StringBuilder* insert(int32_t arg0, char16_t arg1) override;
    StringBuilder* insert(int32_t arg0, int32_t arg1) override;
    StringBuilder* insert(int32_t arg0, int64_t arg1) override;
    StringBuilder* insert(int32_t arg0, float arg1) override;
    StringBuilder* insert(int32_t arg0, double arg1) override;
    StringBuilder* insert(int32_t arg0, ::char16_tArray* arg1, int32_t arg2, int32_t arg3) override;
    StringBuilder* insert(int32_t arg0, CharSequence* arg1, int32_t arg2, int32_t arg3) override;
    int32_t lastIndexOf(String* arg0) override;
    int32_t lastIndexOf(String* arg0, int32_t arg1) override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    StringBuilder* replace(int32_t arg0, int32_t arg1, String* arg2) override;
    StringBuilder* reverse() override;
    String* toString() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    StringBuilder();
    StringBuilder(int32_t arg0);
    StringBuilder(String* arg0);
    StringBuilder(CharSequence* arg0);
protected:
    StringBuilder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual char16_t charAt(int32_t arg0);
    virtual int32_t length();
    virtual CharSequence* subSequence(int32_t arg0, int32_t arg1);

public: /* package */
    virtual AbstractStringBuilder* append(AbstractStringBuilder* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
