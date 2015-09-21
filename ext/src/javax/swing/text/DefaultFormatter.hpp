// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/swing/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <javax/swing/JFormattedTextField_AbstractFormatter.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace javax
{
    namespace swing
    {
        namespace text
        {
typedef ::SubArray< ::javax::swing::text::Position_Bias, ::java::lang::ObjectArray > Position_BiasArray;
        } // text
    } // swing
} // javax

struct default_init_tag;

class javax::swing::text::DefaultFormatter
    : public ::javax::swing::JFormattedTextField_AbstractFormatter
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef ::javax::swing::JFormattedTextField_AbstractFormatter super;

private:
    bool allowsInvalid {  };
    bool commitOnEdit {  };
    DocumentFilter* documentFilter {  };
    NavigationFilter* navigationFilter {  };
    bool overwriteMode {  };

public: /* package */
    DefaultFormatter_ReplaceHolder* replaceHolder {  };

private:
    ::java::lang::Class* valueClass {  };

protected:
    void ctor();

public: /* package */
    virtual bool canReplace(DefaultFormatter_ReplaceHolder* arg0);

public:
    ::java::lang::Object* clone() override;

public: /* package */
    virtual void commitEdit();

public:
    virtual bool getAllowsInvalid();
    virtual bool getCommitsOnValidEdit();

public: /* protected */
    DocumentFilter* getDocumentFilter() override;

public: /* package */
    virtual int32_t getInitialVisualPosition();

public: /* protected */
    NavigationFilter* getNavigationFilter() override;

public: /* package */
    virtual int32_t getNextCursorPosition(int32_t arg0, int32_t arg1);
    /*int32_t getNextNavigatableChar(int32_t arg0, int32_t arg1); (private) */
    virtual int32_t getNextVisualPositionFrom(JTextComponent* arg0, int32_t arg1, Position_Bias* arg2, int32_t arg3, Position_BiasArray* arg4);

public:
    virtual bool getOverwriteMode();

public: /* package */
    virtual DefaultFormatter_ReplaceHolder* getReplaceHolder(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3, AttributeSet* arg4);
    virtual ::java::lang::String* getReplaceString(int32_t arg0, int32_t arg1, ::java::lang::String* arg2);

public:
    virtual ::java::lang::Class* getValueClass();
    void install(::javax::swing::JFormattedTextField* arg0) override;

public: /* package */
    virtual bool isLegalInsertText(::java::lang::String* arg0);
    virtual bool isNavigatable(int32_t arg0);
    virtual bool isValidEdit(DefaultFormatter_ReplaceHolder* arg0);
    virtual void moveDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2);
    virtual void positionCursorAtInitialLocation();
    virtual bool replace(DefaultFormatter_ReplaceHolder* arg0);
    virtual void replace(DocumentFilter_FilterBypass* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3, AttributeSet* arg4);
    virtual void repositionCursor(int32_t arg0, int32_t arg1);

public:
    virtual void setAllowsInvalid(bool arg0);
    virtual void setCommitsOnValidEdit(bool arg0);

public: /* package */
    virtual void setDot(NavigationFilter_FilterBypass* arg0, int32_t arg1, Position_Bias* arg2);

public:
    virtual void setOverwriteMode(bool arg0);
    virtual void setValueClass(::java::lang::Class* arg0);
    ::java::lang::Object* stringToValue(::java::lang::String* arg0) override;

public: /* package */
    virtual void updateValue();
    virtual void updateValue(::java::lang::Object* arg0);

public:
    ::java::lang::String* valueToString(::java::lang::Object* arg0) override;

    // Generated
    DefaultFormatter();
protected:
    DefaultFormatter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
