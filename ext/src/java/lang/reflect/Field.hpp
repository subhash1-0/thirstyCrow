// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/annotation/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/reflect/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/factory/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/repository/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/AccessibleObject.hpp>
#include <java/lang/reflect/Member.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace annotation
        {
typedef ::SubArray< ::java::lang::annotation::Annotation, ::java::lang::ObjectArray > AnnotationArray;
        } // annotation
    } // lang
} // java

struct default_init_tag;

class java::lang::reflect::Field final
    : public AccessibleObject
    , public Member
{

public:
    typedef AccessibleObject super;

private:
    ::int8_tArray* annotations {  };
    ::java::lang::Class* clazz {  };
    ::java::util::Map* declaredAnnotations_ {  };
    ::sun::reflect::FieldAccessor* fieldAccessor {  };
    ::sun::reflect::generics::repository::FieldRepository* genericInfo {  };
    int32_t modifiers {  };
    ::java::lang::String* name {  };
    ::sun::reflect::FieldAccessor* overrideFieldAccessor {  };
    Field* root {  };
    ::java::lang::String* signature {  };
    int32_t slot {  };
    ::java::lang::Class* type {  };

protected:
    void ctor(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::Class* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6);
    /*::sun::reflect::FieldAccessor* acquireFieldAccessor(bool arg0); (private) */

public: /* package */
    Field* copy();
    /*::java::util::Map* declaredAnnotations(); (private) */

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0);
    AnnotatedType* getAnnotatedType();
    ::java::lang::annotation::Annotation* getAnnotation(::java::lang::Class* arg0) override;
    ::java::lang::annotation::AnnotationArray* getAnnotationsByType(::java::lang::Class* arg0) override;
    bool getBoolean(::java::lang::Object* arg0);
    int8_t getByte(::java::lang::Object* arg0);
    char16_t getChar(::java::lang::Object* arg0);
    ::java::lang::annotation::AnnotationArray* getDeclaredAnnotations() override;
    ::java::lang::Class* getDeclaringClass() override;
    double getDouble(::java::lang::Object* arg0);
    /*::sun::reflect::generics::factory::GenericsFactory* getFactory(); (private) */
    /*::sun::reflect::FieldAccessor* getFieldAccessor(::java::lang::Object* arg0); (private) */
    /*::sun::reflect::FieldAccessor* getFieldAccessor(bool arg0); (private) */
    float getFloat(::java::lang::Object* arg0);
    /*::sun::reflect::generics::repository::FieldRepository* getGenericInfo(); (private) */
    /*::java::lang::String* getGenericSignature(); (private) */
    Type* getGenericType();
    int32_t getInt(::java::lang::Object* arg0);
    int64_t getLong(::java::lang::Object* arg0);
    int32_t getModifiers() override;
    ::java::lang::String* getName() override;
    int16_t getShort(::java::lang::Object* arg0);
    ::java::lang::Class* getType();
    /*::int8_tArray* getTypeAnnotationBytes0(); (private) */
    int32_t hashCode() override;
    bool isEnumConstant();
    bool isSynthetic() override;
    void set(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    void setBoolean(::java::lang::Object* arg0, bool arg1);
    void setByte(::java::lang::Object* arg0, int8_t arg1);
    void setChar(::java::lang::Object* arg0, char16_t arg1);
    void setDouble(::java::lang::Object* arg0, double arg1);
    /*void setFieldAccessor(::sun::reflect::FieldAccessor* arg0, bool arg1); (private) */
    void setFloat(::java::lang::Object* arg0, float arg1);
    void setInt(::java::lang::Object* arg0, int32_t arg1);
    void setLong(::java::lang::Object* arg0, int64_t arg1);
    void setShort(::java::lang::Object* arg0, int16_t arg1);
    ::java::lang::String* toGenericString();
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    Field(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::Class* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6);
protected:
    Field(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
