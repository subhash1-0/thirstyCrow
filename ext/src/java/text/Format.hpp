// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Cloneable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
    } // lang

    namespace text
    {
typedef ::SubArray< ::java::text::CharacterIterator, ::java::lang::ObjectArray, ::java::lang::CloneableArray > CharacterIteratorArray;
typedef ::SubArray< ::java::text::AttributedCharacterIterator, ::java::lang::ObjectArray, CharacterIteratorArray > AttributedCharacterIteratorArray;
    } // text
} // java

struct default_init_tag;

class java::text::Format
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
    , public virtual ::java::lang::Cloneable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-299282585814624189LL) };

protected:
    void ctor();

public:
    ::java::lang::Object* clone() override;

public: /* package */
    virtual AttributedCharacterIterator* createAttributedCharacterIterator(::java::lang::String* arg0);
    virtual AttributedCharacterIterator* createAttributedCharacterIterator(AttributedCharacterIteratorArray* arg0);
    virtual AttributedCharacterIterator* createAttributedCharacterIterator(::java::lang::String* arg0, AttributedCharacterIterator_Attribute* arg1, ::java::lang::Object* arg2);
    virtual AttributedCharacterIterator* createAttributedCharacterIterator(AttributedCharacterIterator* arg0, AttributedCharacterIterator_Attribute* arg1, ::java::lang::Object* arg2);

public:
    ::java::lang::String* format(::java::lang::Object* arg0);
    virtual ::java::lang::StringBuffer* format(::java::lang::Object* arg0, ::java::lang::StringBuffer* arg1, FieldPosition* arg2) = 0;
    virtual AttributedCharacterIterator* formatToCharacterIterator(::java::lang::Object* arg0);
    virtual ::java::lang::Object* parseObject(::java::lang::String* arg0);
    virtual ::java::lang::Object* parseObject(::java::lang::String* arg0, ParsePosition* arg1) = 0;

    // Generated

public: /* protected */
    Format();
protected:
    Format(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
