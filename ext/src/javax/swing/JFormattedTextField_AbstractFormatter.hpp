// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/awt/event/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/swing/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

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
} // java

namespace javax
{
    namespace swing
    {
typedef ::SubArray< ::javax::swing::Action, ::java::lang::ObjectArray, ::java::awt::event::ActionListenerArray > ActionArray;
    } // swing
} // javax

struct default_init_tag;

class javax::swing::JFormattedTextField_AbstractFormatter
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    JFormattedTextField* ftf {  };

protected:
    void ctor();

public: /* protected */
    ::java::lang::Object* clone() override;
    virtual ActionArray* getActions();
    virtual ::javax::swing::text::DocumentFilter* getDocumentFilter();
    virtual JFormattedTextField* getFormattedTextField();
    virtual ::javax::swing::text::NavigationFilter* getNavigationFilter();

public:
    virtual void install(JFormattedTextField* arg0);
    /*void installDocumentFilter(::javax::swing::text::DocumentFilter* arg0); (private) */

public: /* protected */
    virtual void invalidEdit();
    virtual void setEditValid(bool arg0);

public:
    virtual ::java::lang::Object* stringToValue(::java::lang::String* arg0) = 0;
    virtual void uninstall();
    virtual ::java::lang::String* valueToString(::java::lang::Object* arg0) = 0;

    // Generated
    JFormattedTextField_AbstractFormatter();
protected:
    JFormattedTextField_AbstractFormatter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
