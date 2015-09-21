// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/util/Properties.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class java::security::Provider
    : public ::java::util::Properties
{

public:
    typedef ::java::util::Properties super;

private:
    static int32_t ALIAS_LENGTH_;
    static ::java::lang::String* ALIAS_PREFIX_;
    static ::java::lang::String* ALIAS_PREFIX_LOWER_;
    static ::sun::security::util::Debug* debug_;
    ::java::util::Set* entrySet_ {  };
    int32_t entrySetCallCount {  };
    ::java::lang::String* info {  };
    bool initialized {  };
    static ::java::util::Map* knownEngines_;
    bool legacyChanged {  };
    ::java::util::Map* legacyMap {  };
    ::java::util::Map* legacyStrings {  };
    ::java::lang::String* name {  };
    static std::atomic< Provider_ServiceKey* > previousKey_;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-4298000515446427739LL) };

private:
    ::java::util::Map* serviceMap {  };
    ::java::util::Set* serviceSet {  };
    bool servicesChanged {  };
    double version {  };

protected:
    void ctor(::java::lang::String* arg0, double arg1, ::java::lang::String* arg2);
    /*static void addEngine(::java::lang::String* arg0, bool arg1, ::java::lang::String* arg2); (private) */
    /*void check(::java::lang::String* arg0); (private) */
    /*void checkInitialized(); (private) */
    /*bool checkLegacy(::java::lang::Object* arg0); (private) */

public:
    void clear() override;
    ::java::lang::Object* compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    ::java::lang::Object* computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1) override;
    ::java::lang::Object* computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    ::java::util::Enumeration* elements() override;
    /*void ensureLegacyParsed(); (private) */
    ::java::util::Set* entrySet() override;
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;
    /*static ::java::lang::String* getEngineName(::java::lang::String* arg0); (private) */
    virtual ::java::lang::String* getInfo();
    virtual ::java::lang::String* getName();
    ::java::lang::Object* getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    ::java::lang::String* getProperty(::java::lang::String* arg0) override;
    virtual Provider_Service* getService(::java::lang::String* arg0, ::java::lang::String* arg1);
    virtual ::java::util::Set* getServices();
    /*::java::lang::StringArray* getTypeAndAlgorithm(::java::lang::String* arg0); (private) */
    virtual double getVersion();
    /*void implClear(); (private) */
    /*::java::lang::Object* implCompute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1); (private) */
    /*::java::lang::Object* implComputeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1); (private) */
    /*::java::lang::Object* implComputeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1); (private) */
    /*::java::lang::Object* implMerge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2); (private) */
    /*::java::lang::Object* implPut(::java::lang::Object* arg0, ::java::lang::Object* arg1); (private) */
    /*void implPutAll(::java::util::Map* arg0); (private) */
    /*::java::lang::Object* implPutIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1); (private) */
    /*::java::lang::Object* implRemove(::java::lang::Object* arg0); (private) */
    /*bool implRemove(::java::lang::Object* arg0, ::java::lang::Object* arg1); (private) */
    /*void implRemoveService(Provider_Service* arg0); (private) */
    /*::java::lang::Object* implReplace(::java::lang::Object* arg0, ::java::lang::Object* arg1); (private) */
    /*bool implReplace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2); (private) */
    /*void implReplaceAll(::java::util::function::BiFunction* arg0); (private) */
    ::java::util::Set* keySet() override;
    ::java::util::Enumeration* keys() override;
    void load(::java::io::InputStream* arg0) override;
    ::java::lang::Object* merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2) override;
    /*void parseLegacyPut(::java::lang::String* arg0, ::java::lang::String* arg1); (private) */
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    void putAll(::java::util::Map* arg0) override;
    /*void putId(); (private) */
    ::java::lang::Object* putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    /*void putPropertyStrings(Provider_Service* arg0); (private) */

public: /* protected */
    virtual void putService(Provider_Service* arg0);
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */

public:
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;
    bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    /*void removeInvalidServices(::java::util::Map* arg0); (private) */
    /*void removePropertyStrings(Provider_Service* arg0); (private) */

public: /* protected */
    virtual void removeService(Provider_Service* arg0);

public:
    ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2) override;
    void replaceAll(::java::util::function::BiFunction* arg0) override;
    ::java::lang::String* toString() override;
    ::java::util::Collection* values() override;

    // Generated

public: /* protected */
    Provider(::java::lang::String* arg0, double arg1, ::java::lang::String* arg2);
protected:
    Provider(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::String* getProperty(::java::lang::String* arg0, ::java::lang::String* arg1);
    virtual void load(::java::io::Reader* arg0);

private:
    static int32_t& ALIAS_LENGTH();
    static ::java::lang::String*& ALIAS_PREFIX();
    static ::java::lang::String*& ALIAS_PREFIX_LOWER();
    static ::sun::security::util::Debug*& debug();
    static ::java::util::Map*& knownEngines();
    static std::atomic< Provider_ServiceKey* >& previousKey();
    virtual ::java::lang::Class* getClass0();
};
