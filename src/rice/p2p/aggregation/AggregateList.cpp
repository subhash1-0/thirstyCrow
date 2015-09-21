// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregateList.java
#include <rice/p2p/aggregation/AggregateList.hpp>

#include <java/io/BufferedReader.hpp>
#include <java/io/File.hpp>
#include <java/io/FileNotFoundException.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/FileReader.hpp>
#include <java/io/IOException.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Date.hpp>
#include <java/util/Enumeration.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationStatistics.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

namespace rice
{
    namespace p2p
    {
        namespace aggregation
        {
typedef ::SubArray< ::rice::p2p::aggregation::ObjectDescriptor, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > ObjectDescriptorArray;
        } // aggregation

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregateList::AggregateList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::AggregateList::AggregateList(::java::lang::String* configFileName, ::java::lang::String* label, ::rice::p2p::commonapi::IdFactory* factory, bool loggingEnabled, ::java::lang::String* instance, ::rice::environment::Environment* env)  /* throws(IOException) */
    : AggregateList(*static_cast< ::default_init_tag* >(0))
{
    ctor(configFileName,label,factory,loggingEnabled,instance,env);
}

void rice::p2p::aggregation::AggregateList::ctor(::java::lang::String* configFileName, ::java::lang::String* label, ::rice::p2p::commonapi::IdFactory* factory, bool loggingEnabled, ::java::lang::String* instance, ::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor();
    this->instance = instance;
    this->configFileName = configFileName;
    this->aggregateList = new ::java::util::Hashtable();
    this->factory = factory;
    this->label = label;
    this->rootKey = nullptr;
    this->nextSerial = 0;
    this->environment = env;
    this->logger = npc(npc(environment)->getLogManager())->getLogger(AggregateList::class_(), instance);
    this->wasReadOK = readFromDisk();
    this->loggingEnabled = loggingEnabled;
    this->logFileName = ::java::lang::StringBuilder().append(configFileName)->append(u".log"_j)->toString();
    if(loggingEnabled) {
        recoverLog();
        this->logFile = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(logFileName, true)));
    } else {
        this->logFile = nullptr;
    }
}

bool rice::p2p::aggregation::AggregateList::readOK()
{
    return wasReadOK;
}

java::util::Enumeration* rice::p2p::aggregation::AggregateList::elements()
{
    return npc(aggregateList)->elements();
}

void rice::p2p::aggregation::AggregateList::recoverLog()
{
    ::java::io::BufferedReader* logFile = nullptr;
    int64_t expectedSerial = -int32_t(1);
    auto entriesReplayed = int32_t(0);
    try {
        logFile = new ::java::io::BufferedReader(new ::java::io::FileReader(logFileName));
        while (true) {
            auto line = readLineSkipComments(logFile);
            if(line == nullptr) {
                npc(logFile)->close();
                break;
            }
            if(!npc(line)->startsWith(u"$"_j) || !npc(line)->endsWith(u"@"_j))
                throw new AggregationException(::java::lang::StringBuilder().append(u"Malformed log entry (expected $...@): "_j)->append(line)->toString());

            if((npc(line)->lastIndexOf(static_cast< int32_t >(u'$')) != 0) || (npc(line)->indexOf(static_cast< int32_t >(u'@')) != npc(line)->length() - int32_t(1)))
                throw new AggregationException(::java::lang::StringBuilder().append(u"Overlapping log entries: "_j)->append(line)->toString());

            auto parts = npc(line)->split(u"\\|"_j);
            auto thisSerial = ::java::lang::Long::parseLong((*parts)[int32_t(1)]);
            if((expectedSerial >= 0) && (thisSerial != expectedSerial))
                throw new AggregationException(::java::lang::StringBuilder().append(u"Malformed log entry (expected serial #"_j)->append(expectedSerial)
                    ->append(u"): "_j)
                    ->append(line)->toString());

            expectedSerial = thisSerial + int32_t(1);
            if(thisSerial > nextSerial)
                throw new AggregationException(::java::lang::StringBuilder().append(u"Entries "_j)->append(nextSerial)
                    ->append(u".."_j)
                    ->append((thisSerial - int32_t(1)))
                    ->append(u" missing from log... cannot recover!"_j)->toString());

            if(thisSerial == nextSerial) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Replaying log entry #"_j)->append(thisSerial)->toString());

                entriesReplayed++;
                if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"setRoot"_j))) {
                    if(npc((*parts)[int32_t(4)])->equals(static_cast< ::java::lang::Object* >(u"null"_j))) {
                        rootKey = nullptr;
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                            npc(logger)->log(u"  - rootKey = null"_j);

                    } else {
                        rootKey = npc(factory)->buildIdFromToString((*parts)[int32_t(4)]);
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"  - rootKey = "_j)->append(npc(rootKey)->toStringFull())->toString());

                    }
                } else if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"setAL"_j))) {
                    auto adcKey = npc(factory)->buildIdFromToString((*parts)[int32_t(4)]);
                    auto lifetime = ::java::lang::Long::parseLong((*parts)[int32_t(5)]);
                    auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(adcKey))));
                    if(adc == nullptr)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find aggregate ("_j)->append(npc(adcKey)->toStringFull())
                            ->append(u": "_j)
                            ->append(line)->toString());

                    npc(adc)->currentLifetime = lifetime;
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"  - lifetime="_j)->append(lifetime)
                            ->append(u" in ADC "_j)
                            ->append(npc(adcKey)->toStringFull())->toString());

                } else if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"setOCL"_j))) {
                    auto adcKey = npc(factory)->buildIdFromToString((*parts)[int32_t(4)]);
                    auto index = ::java::lang::Integer::parseInt((*parts)[int32_t(5)]);
                    auto lifetime = ::java::lang::Long::parseLong((*parts)[int32_t(6)]);
                    auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(adcKey))));
                    if(adc == nullptr)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find aggregate ("_j)->append(npc(adcKey)->toStringFull())
                            ->append(u": "_j)
                            ->append(line)->toString());

                    if(npc(npc(adc)->objects)->length <= index)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Object index mismatch ("_j)->append(index)
                            ->append(u"/"_j)
                            ->append(npc(npc(adc)->objects)->length)
                            ->append(u"): "_j)
                            ->append(line)->toString());

                    npc((*npc(adc)->objects)[index])->currentLifetime = lifetime;
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"  - currentLifetime="_j)->append(lifetime)
                            ->append(u" in ADC "_j)
                            ->append(npc(adcKey)->toStringFull())
                            ->append(u" index "_j)
                            ->append(index)->toString());

                } else if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"setORL"_j))) {
                    auto adcKey = npc(factory)->buildIdFromToString((*parts)[int32_t(4)]);
                    auto index = ::java::lang::Integer::parseInt((*parts)[int32_t(5)]);
                    auto lifetime = ::java::lang::Long::parseLong((*parts)[int32_t(6)]);
                    auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(adcKey))));
                    if(adc == nullptr)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find aggregate ("_j)->append(npc(adcKey)->toStringFull())
                            ->append(u": "_j)
                            ->append(line)->toString());

                    if(npc(npc(adc)->objects)->length <= index)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Object index mismatch ("_j)->append(index)
                            ->append(u"/"_j)
                            ->append(npc(npc(adc)->objects)->length)
                            ->append(u"): "_j)
                            ->append(line)->toString());

                    npc((*npc(adc)->objects)[index])->refreshedLifetime = lifetime;
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"  - refreshedLifetime="_j)->append(lifetime)
                            ->append(u" in ADC "_j)
                            ->append(npc(adcKey)->toStringFull())
                            ->append(u" index "_j)
                            ->append(index)->toString());

                } else if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"refresh"_j))) {
                    auto adcKey = npc(factory)->buildIdFromToString((*parts)[int32_t(4)]);
                    auto lifetime = ::java::lang::Long::parseLong((*parts)[int32_t(5)]);
                    auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(adcKey))));
                    if(adc == nullptr)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find aggregate ("_j)->append(npc(adcKey)->toStringFull())
                            ->append(u": "_j)
                            ->append(line)->toString());

                    npc(adc)->currentLifetime = lifetime;
                    for (auto i = int32_t(0); i < npc(npc(adc)->objects)->length; i++) 
                                                npc((*npc(adc)->objects)[i])->currentLifetime = npc((*npc(adc)->objects)[i])->refreshedLifetime;

                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u" - refresh="_j)->append(lifetime)
                            ->append(u" in ADC "_j)
                            ->append(npc(adcKey)->toStringFull())->toString());

                } else if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"removeAggregate"_j))) {
                    auto adcKey = npc(factory)->buildIdFromToString((*parts)[int32_t(4)]);
                    auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(adcKey))));
                    if(adc == nullptr)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find aggregate ("_j)->append(npc(adcKey)->toStringFull())
                            ->append(u": "_j)
                            ->append(line)->toString());

                    removeAggregateDescriptor(adc, false);
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u" - remove ADC "_j)->append(npc(adcKey)->toStringFull())->toString());

                } else if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"addAggregate"_j))) {
                    auto adcKey = npc(factory)->buildIdFromToString((*parts)[int32_t(4)]);
                    auto adc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(adcKey))));
                    if(adc != nullptr)
                        throw new AggregationException(::java::lang::StringBuilder().append(u"Aggregate already present ("_j)->append(npc(adcKey)->toStringFull())
                            ->append(u": "_j)
                            ->append(line)->toString());

                    adc = readAggregate(logFile, adcKey);
                    addAggregateDescriptor(adc, false);
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u" - add ADC "_j)->append(npc(adcKey)->toStringFull())->toString());

                } else {
                    throw new AggregationException(::java::lang::StringBuilder().append(u"Unknown command ("_j)->append((*parts)[int32_t(3)])
                        ->append(u"): "_j)
                        ->append(line)->toString());
                }
                nextSerial++;
            } else {
                if(npc((*parts)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(u"addAggregate"_j))) {
                    readAggregate(logFile, npc(factory)->buildIdFromToString((*parts)[int32_t(4)]));
                }
            }
        }
    } catch (::java::io::FileNotFoundException* fnfe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"No aggregate log found; using configuration file only"_j);

    } catch (::java::lang::Exception* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Exception while recovering aggregate log: "_j, e);

        ::java::lang::System::exit(1);
    }
    if(entriesReplayed > 0) {
        writeToDisk();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(entriesReplayed)->append(u" entries replayed from aggregate log"_j)->toString());

    }
}

rice::p2p::commonapi::Id* rice::p2p::aggregation::AggregateList::getRoot()
{
    return rootKey;
}

void rice::p2p::aggregation::AggregateList::logEntry(::java::lang::String* entry)
{
    if(loggingEnabled) {
        if(logFile != nullptr) {
            npc(logFile)->println(::java::lang::StringBuilder().append(u"$|"_j)->append((nextSerial++))
                ->append(u"|"_j)
                ->append(npc(npc(environment)->getTimeSource())->currentTimeMillis())
                ->append(u"|"_j)
                ->append(entry)
                ->append(u"|@"_j)->toString());
            npc(logFile)->flush();
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Aggregation cannot write to log: "_j)->append(entry)->toString());

        }
    }
}

void rice::p2p::aggregation::AggregateList::setRoot(::rice::p2p::commonapi::Id* root)
{
    rootKey = root;
    logEntry(::java::lang::StringBuilder().append(u"setRoot|"_j)->append(((root == nullptr) ? u"null"_j : npc(root)->toStringFull()))->toString());
}

bool rice::p2p::aggregation::AggregateList::isEmpty()
{
    return npc(aggregateList)->isEmpty();
}

void rice::p2p::aggregation::AggregateList::clear()
{
    npc(aggregateList)->clear();
    rootKey = nullptr;
}

rice::p2p::aggregation::AggregateDescriptor* rice::p2p::aggregation::AggregateList::getADC(::rice::p2p::commonapi::Id* id)
{
    return java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(id))));
}

void rice::p2p::aggregation::AggregateList::setAggregateLifetime(AggregateDescriptor* adc, int64_t lifetime)
{
    logEntry(::java::lang::StringBuilder().append(u"setAL|"_j)->append(npc(npc(adc)->key)->toStringFull())
        ->append(u"|"_j)
        ->append(lifetime)->toString());
    npc(adc)->currentLifetime = lifetime;
}

void rice::p2p::aggregation::AggregateList::setObjectCurrentLifetime(AggregateDescriptor* adc, int32_t index, int64_t lifetime)
{
    logEntry(::java::lang::StringBuilder().append(u"setOCL|"_j)->append(npc(npc(adc)->key)->toStringFull())
        ->append(u"|"_j)
        ->append(index)
        ->append(u"|"_j)
        ->append(lifetime)->toString());
    npc((*npc(adc)->objects)[index])->currentLifetime = lifetime;
}

void rice::p2p::aggregation::AggregateList::setObjectRefreshedLifetime(AggregateDescriptor* adc, int32_t index, int64_t lifetime)
{
    logEntry(::java::lang::StringBuilder().append(u"setORL|"_j)->append(npc(npc(adc)->key)->toStringFull())
        ->append(u"|"_j)
        ->append(index)
        ->append(u"|"_j)
        ->append(lifetime)->toString());
    npc((*npc(adc)->objects)[index])->refreshedLifetime = lifetime;
}

void rice::p2p::aggregation::AggregateList::resetMarkers()
{
    auto enumerationeration = npc(aggregateList)->elements();
    while (npc(enumerationeration)->hasMoreElements()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumerationeration)->nextElement()));
        npc(aggr)->marker = false;
    }
}

void rice::p2p::aggregation::AggregateList::refreshAggregate(AggregateDescriptor* adc, int64_t lifetime)
{
    logEntry(::java::lang::StringBuilder().append(u"refresh|"_j)->append(npc(npc(adc)->key)->toStringFull())
        ->append(u"|"_j)
        ->append(lifetime)->toString());
    npc(adc)->currentLifetime = lifetime;
    for (auto i = int32_t(0); i < npc(npc(adc)->objects)->length; i++) 
                npc((*npc(adc)->objects)[i])->currentLifetime = npc((*npc(adc)->objects)[i])->refreshedLifetime;

}

void rice::p2p::aggregation::AggregateList::addAggregateDescriptor(AggregateDescriptor* aggr)
{
    addAggregateDescriptor(aggr, true);
}

void rice::p2p::aggregation::AggregateList::addAggregateDescriptor(AggregateDescriptor* aggr, bool logThis)
{
    if((logFile != nullptr) && logThis && loggingEnabled) {
        logEntry(::java::lang::StringBuilder().append(u"addAggregate|"_j)->append(npc(npc(aggr)->key)->toStringFull())->toString());
        writeAggregate(logFile, aggr);
        npc(logFile)->flush();
    }
    npc(aggregateList)->put(static_cast< ::java::lang::Object* >(npc(aggr)->key), static_cast< ::java::lang::Object* >(aggr));
    for (auto i = int32_t(0); i < npc(npc(aggr)->objects)->length; i++) {
        npc(aggregateList)->put(static_cast< ::java::lang::Object* >(new ::rice::p2p::glacier::VersionKey(npc((*npc(aggr)->objects)[i])->key, npc((*npc(aggr)->objects)[i])->version)), static_cast< ::java::lang::Object* >(aggr));
        auto prevDesc = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(npc((*npc(aggr)->objects)[i])->key))));
        auto objDescIndex = (prevDesc == nullptr) ? -int32_t(1) : npc(prevDesc)->lookupNewest(npc((*npc(aggr)->objects)[i])->key);
        if((objDescIndex < 0) || (npc((*npc(prevDesc)->objects)[objDescIndex])->version <= npc((*npc(aggr)->objects)[i])->version)) {
            npc(aggregateList)->put(static_cast< ::java::lang::Object* >(npc((*npc(aggr)->objects)[i])->key), static_cast< ::java::lang::Object* >(aggr));
        }
    }
    for (auto i = int32_t(0); i < npc(npc(aggr)->pointers)->length; i++) {
        auto ref = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >((*npc(aggr)->pointers)[i]))));
        if(ref != nullptr)
            npc(ref)->addReference();

    }
}

void rice::p2p::aggregation::AggregateList::removeAggregateDescriptor(AggregateDescriptor* aggr)
{
    removeAggregateDescriptor(aggr, true);
}

void rice::p2p::aggregation::AggregateList::removeAggregateDescriptor(AggregateDescriptor* aggr, bool logThis)
{
    if(logThis)
        logEntry(::java::lang::StringBuilder().append(u"removeAggregate|"_j)->append(npc(npc(aggr)->key)->toStringFull())->toString());

    npc(aggregateList)->remove(static_cast< ::java::lang::Object* >(npc(aggr)->key));
    for (auto i = int32_t(0); i < npc(npc(aggr)->objects)->length; i++) {
        auto vkey = new ::rice::p2p::glacier::VersionKey(npc((*npc(aggr)->objects)[i])->key, npc((*npc(aggr)->objects)[i])->version);
        auto prevDesc1 = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(vkey))));
        if((prevDesc1 != nullptr) && npc(npc(prevDesc1)->key)->equals(npc(aggr)->key))
            npc(aggregateList)->remove(static_cast< ::java::lang::Object* >(vkey));

        auto prevDesc2 = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >(npc((*npc(aggr)->objects)[i])->key))));
        if((prevDesc2 != nullptr) && npc(npc(prevDesc2)->key)->equals(npc(aggr)->key))
            npc(aggregateList)->remove(static_cast< ::java::lang::Object* >(npc((*npc(aggr)->objects)[i])->key));

    }
    if(npc(aggregateList)->containsValue(static_cast< ::java::lang::Object* >(aggr)))
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Removal from aggregate list incomplete: "_j)->append(npc(npc(aggr)->key)->toStringFull())->toString());


}

void rice::p2p::aggregation::AggregateList::recalculateReferenceCounts(::rice::p2p::commonapi::IdArray* excludes)
{
    auto enumeration = npc(aggregateList)->elements();
    while (npc(enumeration)->hasMoreElements()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
        npc(aggr)->referenceCount = 0;
        npc(aggr)->marker = false;
        if(excludes != nullptr)
            for (auto i = int32_t(0); i < npc(excludes)->length; i++) 
                                if(npc((*excludes)[i])->equals(npc(aggr)->key))
                    npc(aggr)->marker = true;



    }
    enumeration = npc(aggregateList)->elements();
    while (npc(enumeration)->hasMoreElements()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
        if(!npc(aggr)->marker) {
            npc(aggr)->marker = true;
            for (auto i = int32_t(0); i < npc(npc(aggr)->pointers)->length; i++) {
                auto ref = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(aggregateList)->get(static_cast< ::java::lang::Object* >((*npc(aggr)->pointers)[i]))));
                if(ref != nullptr)
                    npc(ref)->addReference();

            }
        }
    }
}

java::lang::String* rice::p2p::aggregation::AggregateList::readLineSkipComments(::java::io::BufferedReader* br) /* throws(IOException) */
{
    while (true) {
        auto line = npc(br)->readLine();
        if((line != nullptr) && ((npc(line)->length() == 0) || (npc(line)->charAt(int32_t(0)) == u'#')))
            continue;

        return line;
    }
}

rice::p2p::aggregation::AggregateDescriptor* rice::p2p::aggregation::AggregateList::readAggregate(::java::io::BufferedReader* reader, ::rice::p2p::commonapi::Id* aggrKey) /* throws(AggregationException, IOException) */
{
    auto expiresS = npc(readLineSkipComments(reader))->split(u"="_j);
    if(!npc((*expiresS)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(u"expires"_j)))
        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find expiration date: "_j)->append((*expiresS)[int32_t(0)])->toString());

    auto expires = ::java::lang::Long::parseLong((*expiresS)[int32_t(1)]);
    auto objectNumS = npc(readLineSkipComments(reader))->split(u"="_j);
    if(!npc((*objectNumS)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(u"objects"_j)))
        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find number of objects: "_j)->append((*objectNumS)[int32_t(0)])->toString());

    auto numObjects = ::java::lang::Integer::parseInt((*objectNumS)[int32_t(1)]);
    auto objects = new ObjectDescriptorArray(numObjects);
    for (auto i = int32_t(0); i < numObjects; i++) {
        auto objS = npc(readLineSkipComments(reader))->split(u"="_j);
        auto objArgS = npc((*objS)[int32_t(1)])->split(u";"_j);
        auto objIdS = npc((*objArgS)[int32_t(0)])->split(u"v"_j);
        objects->set(i, new ObjectDescriptor(npc(factory)->buildIdFromToString((*objIdS)[int32_t(0)]), ::java::lang::Long::parseLong((*objIdS)[int32_t(1)]), ::java::lang::Long::parseLong((*objArgS)[int32_t(1)]), ::java::lang::Long::parseLong((*objArgS)[int32_t(2)]), ::java::lang::Integer::parseInt((*objArgS)[int32_t(3)])));
    }
    auto pointerNumS = npc(readLineSkipComments(reader))->split(u"="_j);
    if(!npc((*pointerNumS)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(u"pointers"_j)))
        throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot find number of pointers: "_j)->append((*pointerNumS)[int32_t(0)])->toString());

    auto numPointers = ::java::lang::Integer::parseInt((*pointerNumS)[int32_t(1)]);
    auto pointers = new ::rice::p2p::commonapi::IdArray(numPointers);
    for (auto i = int32_t(0); i < numPointers; i++) {
        auto ptrS = npc(readLineSkipComments(reader))->split(u"="_j);
        pointers->set(i, npc(factory)->buildIdFromToString((*ptrS)[int32_t(1)]));
    }
    return new AggregateDescriptor(aggrKey, expires, objects, pointers);
}

bool rice::p2p::aggregation::AggregateList::readFromDisk()
{
    rootKey = nullptr;
    npc(aggregateList)->clear();
    ::java::lang::String* fileName;
    if((new ::java::io::File(configFileName))->exists())
        fileName = configFileName;
    else if((new ::java::io::File(::java::lang::StringBuilder().append(configFileName)->append(u".new"_j)->toString()))->exists())
        fileName = ::java::lang::StringBuilder().append(configFileName)->append(u".new"_j)->toString();
    else {
        return false;
    }
    ::java::io::BufferedReader* configFile = nullptr;
    auto readSuccessful = false;
    try {
        configFile = new ::java::io::BufferedReader(new ::java::io::FileReader(fileName));
        auto root = npc(readLineSkipComments(configFile))->split(u"="_j);
        if(npc((*root)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(u"nextid"_j))) {
            nextSerial = ::java::lang::Long::parseLong((*root)[int32_t(1)]);
            root = npc(readLineSkipComments(configFile))->split(u"="_j);
        }
        if(!npc((*root)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(u"root"_j)))
            throw new AggregationException(::java::lang::StringBuilder().append(u"Cannot read root key: "_j)->append((*root)[int32_t(0)])->toString());

        rootKey = npc(factory)->buildIdFromToString((*root)[int32_t(1)]);
        while (true) {
            auto aggrKeyLine = readLineSkipComments(configFile);
            if(aggrKeyLine == nullptr) {
                readSuccessful = true;
                break;
            }
            auto aggrKeyS = npc(aggrKeyLine)->split(u"\\[|\\]"_j);
            auto aggrKey = npc(factory)->buildIdFromToString((*aggrKeyS)[int32_t(1)]);
            auto adc = readAggregate(configFile, aggrKey);
            addAggregateDescriptor(adc, false);
        }
    } catch (::java::lang::Exception* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Cannot read configuration file: "_j)->append(configFileName)
                ->append(u" (e="_j)
                ->append(static_cast< ::java::lang::Object* >(e))
                ->append(u")"_j)->toString(), e);

    }
    if(configFile != nullptr) {
        try {
            npc(configFile)->close();
        } catch (::java::lang::Exception* e) {
        }
    }
    if(!readSuccessful) {
        rootKey = nullptr;
        npc(aggregateList)->clear();
    }
    return readSuccessful;
}

void rice::p2p::aggregation::AggregateList::writeAggregate(::java::io::PrintStream* stream, AggregateDescriptor* adc)
{
    npc(stream)->println(::java::lang::StringBuilder().append(u"expires="_j)->append(npc(adc)->currentLifetime)->toString());
    npc(stream)->println(::java::lang::StringBuilder().append(u"objects="_j)->append(npc(npc(adc)->objects)->length)->toString());
    for (auto i = int32_t(0); i < npc(npc(adc)->objects)->length; i++) 
                npc(stream)->println(::java::lang::StringBuilder().append(u"obj"_j)->append(i)
            ->append(u"="_j)
            ->append(npc(npc((*npc(adc)->objects)[i])->key)->toStringFull())
            ->append(u"v"_j)
            ->append(npc((*npc(adc)->objects)[i])->version)
            ->append(u";"_j)
            ->append(npc((*npc(adc)->objects)[i])->currentLifetime)
            ->append(u";"_j)
            ->append(npc((*npc(adc)->objects)[i])->refreshedLifetime)
            ->append(u";"_j)
            ->append(npc((*npc(adc)->objects)[i])->size)->toString());

    npc(stream)->println(::java::lang::StringBuilder().append(u"pointers="_j)->append(npc(npc(adc)->pointers)->length)->toString());
    for (auto i = int32_t(0); i < npc(npc(adc)->pointers)->length; i++) 
                npc(stream)->println(::java::lang::StringBuilder().append(u"ptr"_j)->append(i)
            ->append(u"="_j)
            ->append(npc((*npc(adc)->pointers)[i])->toStringFull())->toString());

}

void rice::p2p::aggregation::AggregateList::writeToDisk()
{
    if(rootKey == nullptr)
        return;

    try {
        auto configFile = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(::java::lang::StringBuilder().append(configFileName)->append(u".new"_j)->toString())));
        auto enumeration = npc(aggregateList)->elements();
        resetMarkers();
        npc(configFile)->println(::java::lang::StringBuilder().append(u"# Aggregate list at "_j)->append(label)
            ->append(u" ("_j)
            ->append(static_cast< ::java::lang::Object* >((new ::java::util::Date())))
            ->append(u")"_j)->toString());
        npc(configFile)->println();
        npc(configFile)->println(::java::lang::StringBuilder().append(u"nextid="_j)->append(nextSerial)->toString());
        npc(configFile)->println(::java::lang::StringBuilder().append(u"root="_j)->append(npc(rootKey)->toStringFull())->toString());
        npc(configFile)->println();
        while (npc(enumeration)->hasMoreElements()) {
            auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
            if(!npc(aggr)->marker) {
                npc(configFile)->println(::java::lang::StringBuilder().append(u"["_j)->append(npc(npc(aggr)->key)->toStringFull())
                    ->append(u"]"_j)->toString());
                writeAggregate(configFile, aggr);
                npc(configFile)->println(u""_j);
                npc(aggr)->marker = true;
            }
        }
        npc(configFile)->close();
        (new ::java::io::File(configFileName))->delete_();
        (new ::java::io::File(::java::lang::StringBuilder().append(configFileName)->append(u".new"_j)->toString()))->renameTo(new ::java::io::File(configFileName));
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"AggregationImpl cannot write to its aggregate list: "_j)->append(configFileName)
                ->append(u" ("_j)
                ->append(static_cast< ::java::lang::Object* >(ioe))
                ->append(u")"_j)->toString(), ioe);

    }
}

rice::p2p::commonapi::IdArray* rice::p2p::aggregation::AggregateList::getSomePointers(int32_t referenceThreshold, int32_t max, ::rice::p2p::commonapi::IdArray* excludes)
{
    if(rootKey == nullptr)
        return new ::rice::p2p::commonapi::IdArray({});

    if(excludes != nullptr)
        recalculateReferenceCounts(excludes);

    auto pointers = new ::java::util::Vector();
    auto enumeration = elements();
    resetMarkers();
    while (npc(enumeration)->hasMoreElements()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
        if(!npc(aggr)->marker) {
            npc(aggr)->marker = true;
            auto isExcluded = false;
            if(excludes != nullptr)
                for (auto i = int32_t(0); i < npc(excludes)->length; i++) 
                                        if(npc((*excludes)[i])->equals(npc(aggr)->key))
                        isExcluded = true;



            if((npc(aggr)->referenceCount < referenceThreshold) && (npc(pointers)->size() < max) && !isExcluded)
                npc(pointers)->add(static_cast< ::java::lang::Object* >(npc(aggr)->key));

        }
    }
    return java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(pointers)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray({})))));
}

rice::p2p::aggregation::AggregationStatistics* rice::p2p::aggregation::AggregateList::getStatistics(int64_t granularity, int64_t range, int32_t nominalReferenceCount)
{
    auto const maxHistoIndex = static_cast< int32_t >((range / granularity));
    auto const now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    auto stats = new AggregationStatistics(int32_t(1) + maxHistoIndex, granularity, environment);
    auto enumeration = elements();
    recalculateReferenceCounts(nullptr);
    resetMarkers();
    while (npc(enumeration)->hasMoreElements()) {
        auto aggr = java_cast< AggregateDescriptor* >(java_cast< ::java::lang::Object* >(npc(enumeration)->nextElement()));
        if(!npc(aggr)->marker) {
            npc(aggr)->marker = true;
            npc(stats)->numAggregatesTotal++;
            npc(stats)->numObjectsTotal += npc(npc(aggr)->objects)->length;
            if(npc(npc(aggr)->objects)->length == 0)
                npc(stats)->numPointerArrays++;

            if(npc(aggr)->referenceCount < nominalReferenceCount)
                npc(stats)->criticalAggregates++;

            if(npc(aggr)->referenceCount < 1)
                npc(stats)->orphanedAggregates++;

            auto aggrPos = static_cast< int32_t >(((npc(aggr)->currentLifetime - now) / granularity));
            if(aggrPos < 0)
                aggrPos = 0;

            if(aggrPos > maxHistoIndex)
                aggrPos = maxHistoIndex;

            (*npc(stats)->aggregateLifetimeHisto)[aggrPos]++;
            for (auto i = int32_t(0); i < npc(npc(aggr)->objects)->length; i++) {
                npc(stats)->totalObjectsSize += npc((*npc(aggr)->objects)[i])->size;
                if(npc((*npc(aggr)->objects)[i])->isAliveAt(now)) {
                    npc(stats)->numObjectsAlive++;
                    npc(stats)->liveObjectsSize += npc((*npc(aggr)->objects)[i])->size;
                }
                auto objPos = static_cast< int32_t >(((npc((*npc(aggr)->objects)[i])->refreshedLifetime - now) / granularity));
                if(objPos < 0)
                    objPos = 0;

                if(objPos > maxHistoIndex)
                    objPos = maxHistoIndex;

                (*npc(stats)->objectLifetimeHisto)[objPos]++;
            }
        }
    }
    return stats;
}

java::lang::String* rice::p2p::aggregation::AggregateList::getLogPrefix()
{
    return ::java::lang::StringBuilder().append(u"COUNT: "_j)->append(npc(npc(environment)->getTimeSource())->currentTimeMillis())
        ->append(u" AL"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregateList::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.AggregateList", 34);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregateList::getClass0()
{
    return class_();
}

