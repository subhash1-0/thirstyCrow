// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregateList.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::aggregation::AggregateList
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::Hashtable* aggregateList {  };
    ::java::lang::String* configFileName {  };
    ::java::lang::String* logFileName {  };
    ::java::lang::String* label {  };
    ::rice::p2p::commonapi::IdFactory* factory {  };
    ::java::io::PrintStream* logFile {  };
    bool loggingEnabled {  };
    ::rice::p2p::commonapi::Id* rootKey {  };
    bool wasReadOK {  };
    int64_t nextSerial {  };
    ::java::lang::String* instance {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::java::lang::String* configFileName, ::java::lang::String* label, ::rice::p2p::commonapi::IdFactory* factory, bool loggingEnabled, ::java::lang::String* instance, ::rice::environment::Environment* env) /* throws(IOException) */;

public:
    virtual bool readOK();
    virtual ::java::util::Enumeration* elements();
    virtual void recoverLog();
    virtual ::rice::p2p::commonapi::Id* getRoot();
    virtual void logEntry(::java::lang::String* entry);
    virtual void setRoot(::rice::p2p::commonapi::Id* root);
    virtual bool isEmpty();
    virtual void clear();
    virtual AggregateDescriptor* getADC(::rice::p2p::commonapi::Id* id);
    virtual void setAggregateLifetime(AggregateDescriptor* adc, int64_t lifetime);
    virtual void setObjectCurrentLifetime(AggregateDescriptor* adc, int32_t index, int64_t lifetime);
    virtual void setObjectRefreshedLifetime(AggregateDescriptor* adc, int32_t index, int64_t lifetime);
    virtual void resetMarkers();
    virtual void refreshAggregate(AggregateDescriptor* adc, int64_t lifetime);
    virtual void addAggregateDescriptor(AggregateDescriptor* aggr);

private:
    void addAggregateDescriptor(AggregateDescriptor* aggr, bool logThis);

public:
    virtual void removeAggregateDescriptor(AggregateDescriptor* aggr);

private:
    void removeAggregateDescriptor(AggregateDescriptor* aggr, bool logThis);

public:
    virtual void recalculateReferenceCounts(::rice::p2p::commonapi::IdArray* excludes);

private:
    ::java::lang::String* readLineSkipComments(::java::io::BufferedReader* br) /* throws(IOException) */;
    AggregateDescriptor* readAggregate(::java::io::BufferedReader* reader, ::rice::p2p::commonapi::Id* aggrKey) /* throws(AggregationException, IOException) */;

public:
    virtual bool readFromDisk();

private:
    void writeAggregate(::java::io::PrintStream* stream, AggregateDescriptor* adc);

public:
    virtual void writeToDisk();
    virtual ::rice::p2p::commonapi::IdArray* getSomePointers(int32_t referenceThreshold, int32_t max, ::rice::p2p::commonapi::IdArray* excludes);
    virtual AggregationStatistics* getStatistics(int64_t granularity, int64_t range, int32_t nominalReferenceCount);

private:
    ::java::lang::String* getLogPrefix();

    // Generated

public:
    AggregateList(::java::lang::String* configFileName, ::java::lang::String* label, ::rice::p2p::commonapi::IdFactory* factory, bool loggingEnabled, ::java::lang::String* instance, ::rice::environment::Environment* env);
protected:
    AggregateList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
