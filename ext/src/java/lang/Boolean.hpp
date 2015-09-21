// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class java::lang::Boolean final
    : public virtual Object
    , public ::java::io::Serializable
    , public Comparable
{

public:
    typedef Object super;

private:
    static Boolean* FALSE_;
    static Boolean* TRUE_;
    static Class* TYPE_;
    static constexpr int64_t serialVersionUID { int64_t(-3665804199014368530LL) };
    bool value {  };

protected:
    void ctor(bool arg0);
    void ctor(String* arg0);

public:
    bool booleanValue();
    static int32_t compare(bool arg0, bool arg1);
    int32_t compareTo(Boolean* arg0);
    bool equals(Object* arg0) override;
    static bool getBoolean(String* arg0);
    int32_t hashCode() override;
    static int32_t hashCode(bool arg0);
    static bool logicalAnd(bool arg0, bool arg1);
    static bool logicalOr(bool arg0, bool arg1);
    static bool logicalXor(bool arg0, bool arg1);
    static bool parseBoolean(String* arg0);
    String* toString() override;
    static String* toString(bool arg0);
    static Boolean* valueOf(bool arg0);
    static Boolean* valueOf(String* arg0);

    // Generated
    Boolean(bool arg0);
    Boolean(String* arg0);
protected:
    Boolean(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* arg0) override;
    static Boolean*& FALSE();
    static Boolean*& TRUE();
    static Class*& TYPE();

private:
    virtual ::java::lang::Class* getClass0();
};
