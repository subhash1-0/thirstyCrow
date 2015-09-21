// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/awt/event/fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/swing/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <javax/swing/text/DefaultFormatter.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace util
    {
typedef ::SubArray< ::java::util::EventListener, ::java::lang::ObjectArray > EventListenerArray;
    } // util

    namespace awt
    {
        namespace event
        {
typedef ::SubArray< ::java::awt::event::ActionListener, ::java::lang::ObjectArray, ::java::util::EventListenerArray > ActionListenerArray;
        } // event
    } // awt

    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace text
    {
typedef ::SubArray< ::java::text::AttributedCharacterIterator_Attribute, ::java::lang::ObjectArray, ::java::io::SerializableArray > AttributedCharacterIterator_AttributeArray;
typedef ::SubArray< ::java::text::Format_Field, AttributedCharacterIterator_AttributeArray > Format_FieldArray;
    } // text
} // java

namespace javax
{
    namespace swing
    {
typedef ::SubArray< ::javax::swing::Action, ::java::lang::ObjectArray, ::java::awt::event::ActionListenerArray > ActionArray;
    } // swing
} // javax

struct default_init_tag;

class javax::swing::text::InternationalFormatter
    : public DefaultFormatter
{

public:
    typedef DefaultFormatter super;

private:
    static ::java::text::Format_FieldArray* EMPTY_FIELD_ARRAY_;
    ::java::text::Format* format {  };
    bool ignoreDocumentMutate {  };
    ::java::text::AttributedCharacterIterator* iterator {  };
    ::java::util::BitSet* literalMask {  };
    ::java::lang::Comparable* max {  };
    ::java::lang::Comparable* min {  };
    ::java::lang::String* string {  };
    bool validMask {  };

protected:
    void ctor();
    void ctor(::java::text::Format* arg0);

public: /* package */
    virtual ::java::lang::Object* adjustValue(::java::lang::Object* arg0, ::java::util::Map* arg1, ::java::lang::Object* arg2, int32_t arg3);
    virtual bool canIncrement(::java::lang::Object* arg0, int32_t arg1);
    bool canReplace(DefaultFormatter_ReplaceHolder* arg0) override;

public:
    ::java::lang::Object* clone() override;

public: /* protected */
    ::javax::swing::ActionArray* getActions() override;

public: /* package */
    virtual ::java::lang::Object* getAdjustField(int32_t arg0, ::java::util::Map* arg1);
    virtual int32_t getAttributeStart(::java::text::AttributedCharacterIterator_Attribute* arg0);
    virtual ::java::util::Map* getAttributes(int32_t arg0);
    virtual char16_t getBufferedChar(int32_t arg0);
    /*int32_t getFieldTypeCountTo(::java::lang::Object* arg0, int32_t arg1); (private) */

public:
    virtual ::java::text::Format_FieldArray* getFields(int32_t arg0);
    virtual ::java::text::Format* getFormat();

public: /* package */
    virtual ::java::text::AttributedCharacterIterator* getIterator();
    virtual char16_t getLiteral(int32_t arg0);
    virtual int32_t getLiteralCountTo(int32_t arg0);

public:
    virtual ::java::lang::Comparable* getMaximum();
    virtual ::java::lang::Comparable* getMinimum();
    /*int32_t getNextNonliteralIndex(int32_t arg0, int32_t arg1); (private) */

public: /* package */
    DefaultFormatter_ReplaceHolder* getReplaceHolder(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3, AttributeSet* arg4) override;
    virtual bool getSupportsIncrement();

public:
    void install(::javax::swing::JFormattedTextField* arg0) override;

public: /* package */
    virtual bool isLiteral(int32_t arg0);
    virtual bool isLiteral(::java::util::Map* arg0);
    bool isNavigatable(int32_t arg0) override;
    virtual bool isValidMask();
    virtual bool isValidValue(::java::lang::Object* arg0, bool arg1);
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    bool replace(DefaultFormatter_ReplaceHolder* arg0) override;
    void replace(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3, AttributeSet* arg4) override;
    /*void repositionCursor(int32_t arg0, int32_t arg1, int32_t arg2); (private) */
    virtual void resetValue(::java::lang::Object* arg0);
    virtual void selectField(::java::lang::Object* arg0, int32_t arg1);

public:
    virtual void setFormat(::java::text::Format* arg0);
    virtual void setMaximum(::java::lang::Comparable* arg0);
    virtual void setMinimum(::java::lang::Comparable* arg0);
    ::java::lang::Object* stringToValue(::java::lang::String* arg0) override;

public: /* package */
    virtual ::java::lang::Object* stringToValue(::java::lang::String* arg0, ::java::text::Format* arg1);
    virtual void updateMask();
    /*void updateMask(::java::text::AttributedCharacterIterator* arg0); (private) */
    virtual void updateMaskIfNecessary();
    void updateValue(::java::lang::Object* arg0) override;

public:
    ::java::lang::String* valueToString(::java::lang::Object* arg0) override;

    // Generated
    InternationalFormatter();
    InternationalFormatter(::java::text::Format* arg0);
protected:
    InternationalFormatter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    virtual void updateValue();

private:
    static ::java::text::Format_FieldArray*& EMPTY_FIELD_ARRAY();
    virtual ::java::lang::Class* getClass0();
};
