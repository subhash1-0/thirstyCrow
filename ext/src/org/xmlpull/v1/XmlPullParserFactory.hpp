// Generated from /pastry-2.1/lib/xmlpull_1_1_3_4a.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/xmlpull/v1/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::xmlpull::v1::XmlPullParserFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* PROPERTY_NAME_;
    static ::java::lang::String* RESOURCE_NAME_;

public: /* protected */
    ::java::lang::String* classNamesLocation {  };
    ::java::util::Hashtable* features {  };
    ::java::util::Vector* parserClasses {  };

private:
    static ::java::lang::Class* referenceContextClass_;

public: /* protected */
    ::java::util::Vector* serializerClasses {  };

protected:
    void ctor();

public:
    virtual bool getFeature(::java::lang::String* name);
    virtual bool isNamespaceAware();
    virtual bool isValidating();
    static XmlPullParserFactory* newInstance();
    static XmlPullParserFactory* newInstance(::java::lang::String* arg0, ::java::lang::Class* arg1);
    virtual XmlPullParser* newPullParser();
    virtual XmlSerializer* newSerializer();
    virtual void setFeature(::java::lang::String* name, bool state);
    virtual void setNamespaceAware(bool awareness);
    virtual void setValidating(bool validating);

    // Generated

public: /* protected */
    XmlPullParserFactory();
protected:
    XmlPullParserFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::java::lang::String*& PROPERTY_NAME();

private:
    static ::java::lang::String*& RESOURCE_NAME();

public: /* package */
    static ::java::lang::Class*& referenceContextClass();

private:
    virtual ::java::lang::Class* getClass0();
};
