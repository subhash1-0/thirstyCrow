// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::reflect::Modifier
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t ABSTRACT { int32_t(1024) };

public: /* package */
    static constexpr int32_t ACCESS_MODIFIERS { int32_t(7) };
    static constexpr int32_t ANNOTATION { int32_t(8192) };
    static constexpr int32_t BRIDGE { int32_t(64) };

private:
    static constexpr int32_t CLASS_MODIFIERS { int32_t(3103) };
    static constexpr int32_t CONSTRUCTOR_MODIFIERS { int32_t(7) };

public: /* package */
    static constexpr int32_t ENUM { int32_t(16384) };

private:
    static constexpr int32_t FIELD_MODIFIERS { int32_t(223) };

public:
    static constexpr int32_t FINAL { int32_t(16) };
    static constexpr int32_t INTERFACE { int32_t(512) };

private:
    static constexpr int32_t INTERFACE_MODIFIERS { int32_t(3087) };

public: /* package */
    static constexpr int32_t MANDATED { int32_t(32768) };

private:
    static constexpr int32_t METHOD_MODIFIERS { int32_t(3391) };

public:
    static constexpr int32_t NATIVE { int32_t(256) };

private:
    static constexpr int32_t PARAMETER_MODIFIERS { int32_t(16) };

public:
    static constexpr int32_t PRIVATE { int32_t(2) };
    static constexpr int32_t PROTECTED { int32_t(4) };
    static constexpr int32_t PUBLIC { int32_t(1) };
    static constexpr int32_t STATIC { int32_t(8) };
    static constexpr int32_t STRICT { int32_t(2048) };
    static constexpr int32_t SYNCHRONIZED { int32_t(32) };

public: /* package */
    static constexpr int32_t SYNTHETIC { int32_t(4096) };

public:
    static constexpr int32_t TRANSIENT { int32_t(128) };

public: /* package */
    static constexpr int32_t VARARGS { int32_t(128) };

public:
    static constexpr int32_t VOLATILE { int32_t(64) };

protected:
    void ctor();

public:
    static int32_t classModifiers();
    static int32_t constructorModifiers();
    static int32_t fieldModifiers();
    static int32_t interfaceModifiers();
    static bool isAbstract(int32_t arg0);
    static bool isFinal(int32_t arg0);
    static bool isInterface(int32_t arg0);

public: /* package */
    static bool isMandated(int32_t arg0);

public:
    static bool isNative(int32_t arg0);
    static bool isPrivate(int32_t arg0);
    static bool isProtected(int32_t arg0);
    static bool isPublic(int32_t arg0);
    static bool isStatic(int32_t arg0);
    static bool isStrict(int32_t arg0);
    static bool isSynchronized(int32_t arg0);

public: /* package */
    static bool isSynthetic(int32_t arg0);

public:
    static bool isTransient(int32_t arg0);
    static bool isVolatile(int32_t arg0);
    static int32_t methodModifiers();
    static int32_t parameterModifiers();
    static ::java::lang::String* toString(int32_t arg0);

    // Generated
    Modifier();
protected:
    Modifier(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
