// Generated from /pastry-2.1/src/rice/environment/params/simple/SimpleParameters.java
#include <rice/environment/params/simple/SimpleParameters.hpp>

#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/InputStream.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassLoader.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/NumberFormatException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/net/URL.hpp>
#include <java/net/UnknownHostException.hpp>
#include <java/util/Enumeration.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/params/ParameterChangeListener.hpp>
#include <rice/environment/params/simple/ParamsNotPresentException.hpp>
#include <rice/environment/params/simple/SimpleParameters_MyProperties.hpp>
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

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

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

rice::environment::params::simple::SimpleParameters::SimpleParameters(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::params::simple::SimpleParameters::SimpleParameters(::java::lang::StringArray* orderedDefaults, ::java::lang::String* mutableConfigFileName) 
    : SimpleParameters(*static_cast< ::default_init_tag* >(0))
{
    ctor(orderedDefaults,mutableConfigFileName);
}

java::lang::String*& rice::environment::params::simple::SimpleParameters::FILENAME_EXTENSION()
{
    clinit();
    return FILENAME_EXTENSION_;
}
java::lang::String* rice::environment::params::simple::SimpleParameters::FILENAME_EXTENSION_;

java::lang::String*& rice::environment::params::simple::SimpleParameters::ARRAY_SPACER()
{
    clinit();
    return ARRAY_SPACER_;
}
java::lang::String* rice::environment::params::simple::SimpleParameters::ARRAY_SPACER_;

java::lang::String*& rice::environment::params::simple::SimpleParameters::defaultParamsFile()
{
    clinit();
    return defaultParamsFile_;
}
java::lang::String* rice::environment::params::simple::SimpleParameters::defaultParamsFile_;

void rice::environment::params::simple::SimpleParameters::ctor(::java::lang::StringArray* orderedDefaults, ::java::lang::String* mutableConfigFileName)
{
    super::ctor();
    if(mutableConfigFileName != nullptr) {
        this->configFileName = ::java::lang::StringBuilder().append(mutableConfigFileName)->append(FILENAME_EXTENSION_)->toString();
    } else {
        try {
            auto f = new ::java::io::File(defaultParamsFile_);
            if(npc(f)->exists()) {
                this->configFileName = defaultParamsFile_;
            }
        } catch (::java::lang::Exception* e) {
            npc(e)->printStackTrace();
        }
    }
    this->properties = new SimpleParameters_MyProperties(this);
    this->defaults = new SimpleParameters_MyProperties(this);
    this->changeListeners = new ::java::util::HashSet();
    for (auto ctr = int32_t(0); ctr < npc(orderedDefaults)->length; ctr++) {
        try {
            auto loader = npc(this->getClass())->getClassLoader();
            if(loader == nullptr)
                loader = ::java::lang::ClassLoader::getSystemClassLoader();

            npc(this->defaults)->load(npc(npc(loader)->getResource(::java::lang::StringBuilder().append((*orderedDefaults)[ctr])->append(FILENAME_EXTENSION_)->toString()))->openStream());
        } catch (::java::lang::Exception* ioe) {
            auto errorString = ::java::lang::StringBuilder().append(u"Warning, couldn't load param file:"_j)->append((::java::lang::StringBuilder().append((*orderedDefaults)[ctr])->append(FILENAME_EXTENSION_)->toString()))->toString();
            throw new ParamsNotPresentException(errorString, ioe);
        }
    }
    if(this->configFileName != nullptr) {
        auto f = new ::java::io::File(this->configFileName);
        if(npc(f)->exists()) {
            try {
                npc(properties)->load(static_cast< ::java::io::InputStream* >(new ::java::io::FileInputStream(this->configFileName)));
            } catch (::java::lang::Exception* e) {
                throw new ParamsNotPresentException(::java::lang::StringBuilder().append(u"Error loading "_j)->append(static_cast< ::java::lang::Object* >(f))->toString(), e);
            }
        } else {
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"Configuration file "_j)->append(npc(f)->getAbsolutePath())
                ->append(u" not present.  Using defaults."_j)->toString());
        }
    }
}

java::util::Enumeration* rice::environment::params::simple::SimpleParameters::enumerateDefaults()
{
    return npc(defaults)->keys();
}

java::util::Enumeration* rice::environment::params::simple::SimpleParameters::enumerateNonDefaults()
{
    return npc(properties)->keys();
}

java::net::InetSocketAddress* rice::environment::params::simple::SimpleParameters::parseInetSocketAddress(::java::lang::String* name) /* throws(UnknownHostException) */
{
    auto host = npc(name)->substring(0, npc(name)->indexOf(u":"_j));
    auto port = npc(name)->substring(npc(name)->indexOf(u":"_j) + int32_t(1));
    try {
        return new ::java::net::InetSocketAddress(::java::net::InetAddress::getByName(host), ::java::lang::Integer::parseInt(port));
    } catch (::java::net::UnknownHostException* uhe) {
        npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"ERROR: Unable to find IP for ISA "_j)->append(name)
            ->append(u" - returning null."_j)->toString());
        return nullptr;
    }
}

java::lang::String* rice::environment::params::simple::SimpleParameters::getProperty(::java::lang::String* name)
{
    auto result = npc(properties)->getProperty(name);
    if(result == nullptr)
        result = npc(defaults)->getProperty(name);

    if(result == nullptr) {
        npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"WARNING: The parameter '"_j)->append(name)
            ->append(u"' was not found - this is likely going to cause an error."_j)->toString());
    } else {
        result = npc(result)->trim();
    }
    return result;
}

void rice::environment::params::simple::SimpleParameters::setProperty(::java::lang::String* name, ::java::lang::String* value)
{
    if((npc(defaults)->getProperty(name) != nullptr) && (npc(npc(defaults)->getProperty(name))->equals(static_cast< ::java::lang::Object* >(value)))) {
        if(npc(properties)->getProperty(name) != nullptr) {
            npc(properties)->remove(static_cast< ::java::lang::Object* >(name));
            fireChangeEvent(name, value);
        }
    } else {
        if((npc(properties)->getProperty(name) == nullptr) || (!npc(npc(properties)->getProperty(name))->equals(static_cast< ::java::lang::Object* >(value)))) {
            npc(properties)->setProperty(name, value);
            fireChangeEvent(name, value);
        }
    }
}

void rice::environment::params::simple::SimpleParameters::remove(::java::lang::String* name)
{
    npc(properties)->remove(static_cast< ::java::lang::Object* >(name));
    fireChangeEvent(name, nullptr);
}

bool rice::environment::params::simple::SimpleParameters::contains(::java::lang::String* name)
{
    if(npc(defaults)->containsKey(static_cast< ::java::lang::Object* >(name)))
        return true;

    return npc(properties)->containsKey(static_cast< ::java::lang::Object* >(name));
}

int32_t rice::environment::params::simple::SimpleParameters::getInt(::java::lang::String* name)
{
    try {
        return ::java::lang::Integer::parseInt(getProperty(name));
    } catch (::java::lang::NumberFormatException* nfe) {
        throw new ::java::lang::NumberFormatException(::java::lang::StringBuilder().append(npc(nfe)->getMessage())->append(u" for parameter "_j)
            ->append(name)->toString());
    }
}

double rice::environment::params::simple::SimpleParameters::getDouble(::java::lang::String* name)
{
    try {
        return ::java::lang::Double::parseDouble(getProperty(name));
    } catch (::java::lang::NumberFormatException* nfe) {
        throw new ::java::lang::NumberFormatException(::java::lang::StringBuilder().append(npc(nfe)->getMessage())->append(u" for parameter "_j)
            ->append(name)->toString());
    }
}

float rice::environment::params::simple::SimpleParameters::getFloat(::java::lang::String* name)
{
    try {
        return ::java::lang::Float::parseFloat(getProperty(name));
    } catch (::java::lang::NumberFormatException* nfe) {
        throw new ::java::lang::NumberFormatException(::java::lang::StringBuilder().append(npc(nfe)->getMessage())->append(u" for parameter "_j)
            ->append(name)->toString());
    }
}

int64_t rice::environment::params::simple::SimpleParameters::getLong(::java::lang::String* name)
{
    try {
        return ::java::lang::Long::parseLong(getProperty(name));
    } catch (::java::lang::NumberFormatException* nfe) {
        throw new ::java::lang::NumberFormatException(::java::lang::StringBuilder().append(npc(nfe)->getMessage())->append(u" for parameter "_j)
            ->append(name)->toString());
    }
}

bool rice::environment::params::simple::SimpleParameters::getBoolean(::java::lang::String* name)
{
    return (new ::java::lang::Boolean(getProperty(name)))->booleanValue();
}

java::net::InetAddress* rice::environment::params::simple::SimpleParameters::getInetAddress(::java::lang::String* name) /* throws(UnknownHostException) */
{
    return ::java::net::InetAddress::getByName(getString(name));
}

java::net::InetSocketAddress* rice::environment::params::simple::SimpleParameters::getInetSocketAddress(::java::lang::String* name) /* throws(UnknownHostException) */
{
    return parseInetSocketAddress(getString(name));
}

java::net::InetSocketAddressArray* rice::environment::params::simple::SimpleParameters::getInetSocketAddressArray_(::java::lang::String* name) /* throws(UnknownHostException) */
{
    if(npc(getString(name))->length() == 0)
        return new ::java::net::InetSocketAddressArray(int32_t(0));

    auto addresses = npc(getString(name))->split(ARRAY_SPACER_);
    ::java::util::List* result = new ::java::util::LinkedList();
    for (auto i = int32_t(0); i < npc(addresses)->length; i++) {
        auto address = parseInetSocketAddress((*addresses)[i]);
        if(address != nullptr)
            npc(result)->add(static_cast< ::java::lang::Object* >(address));

    }
    return java_cast< ::java::net::InetSocketAddressArray* >(java_cast< ::java::net::InetSocketAddressArray* >(npc(result)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::net::InetSocketAddressArray(int32_t(0))))));
}

java::lang::String* rice::environment::params::simple::SimpleParameters::getString(::java::lang::String* name)
{
    return getProperty(name);
}

java::lang::StringArray* rice::environment::params::simple::SimpleParameters::getStringArray_(::java::lang::String* name)
{
    auto list = getProperty(name);
    if(list != nullptr)
        return (npc(list)->equals(static_cast< ::java::lang::Object* >(u""_j)) ? new ::java::lang::StringArray(int32_t(0)) : npc(list)->split(ARRAY_SPACER_));
    else
        return nullptr;
}

void rice::environment::params::simple::SimpleParameters::setInt(::java::lang::String* name, int32_t value)
{
    setProperty(name, ::java::lang::Integer::toString(value));
}

void rice::environment::params::simple::SimpleParameters::setDouble(::java::lang::String* name, double value)
{
    setProperty(name, ::java::lang::Double::toString(value));
}

void rice::environment::params::simple::SimpleParameters::setFloat(::java::lang::String* name, float value)
{
    setProperty(name, ::java::lang::Float::toString(value));
}

void rice::environment::params::simple::SimpleParameters::setLong(::java::lang::String* name, int64_t value)
{
    setProperty(name, ::java::lang::Long::toString(value));
}

void rice::environment::params::simple::SimpleParameters::setBoolean(::java::lang::String* name, bool value)
{
    setProperty(name, ::java::lang::StringBuilder().append(u""_j)->append(value)->toString());
}

void rice::environment::params::simple::SimpleParameters::setInetAddress(::java::lang::String* name, ::java::net::InetAddress* value)
{
    setProperty(name, npc(value)->getHostAddress());
}

void rice::environment::params::simple::SimpleParameters::setInetSocketAddress(::java::lang::String* name, ::java::net::InetSocketAddress* value)
{
    setProperty(name, ::java::lang::StringBuilder().append(npc(npc(value)->getAddress())->getHostAddress())->append(u":"_j)
        ->append(npc(value)->getPort())->toString());
}

void rice::environment::params::simple::SimpleParameters::setInetSocketAddressArray_(::java::lang::String* name, ::java::net::InetSocketAddressArray* value)
{
    auto buffer = new ::java::lang::StringBuffer();
    for (auto i = int32_t(0); i < npc(value)->length; i++) {
        npc(buffer)->append(::java::lang::StringBuilder().append(npc(npc((*value)[i])->getAddress())->getHostAddress())->append(u":"_j)
            ->append(npc((*value)[i])->getPort())->toString());
        if(i < npc(value)->length - int32_t(1))
            npc(buffer)->append(ARRAY_SPACER_);

    }
    setProperty(name, npc(buffer)->toString());
}

void rice::environment::params::simple::SimpleParameters::setString(::java::lang::String* name, ::java::lang::String* value)
{
    setProperty(name, value);
}

void rice::environment::params::simple::SimpleParameters::setStringArray_(::java::lang::String* name, ::java::lang::StringArray* value)
{
    auto buffer = new ::java::lang::StringBuffer();
    for (auto i = int32_t(0); i < npc(value)->length; i++) {
        npc(buffer)->append((*value)[i]);
        if(i < npc(value)->length - int32_t(1))
            npc(buffer)->append(ARRAY_SPACER_);

    }
    setProperty(name, npc(buffer)->toString());
}

void rice::environment::params::simple::SimpleParameters::store() /* throws(IOException) */
{
    if(configFileName == nullptr)
        return;

    try {
        auto current = new ::java::io::File(configFileName);
        auto next = new ::java::io::File(::java::lang::StringBuilder().append(configFileName)->append(u".new"_j)->toString());
        auto old = new ::java::io::File(::java::lang::StringBuilder().append(configFileName)->append(u".old"_j)->toString());
        npc(properties)->store(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(next)), static_cast< ::java::lang::String* >(nullptr));
        npc(current)->renameTo(old);
        npc(next)->renameTo(current);
        npc(old)->delete_();
    } catch (::java::io::IOException* ioe) {
        npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"[Loader       ]: Unable to store properties file "_j)->append(configFileName)
            ->append(u", got error "_j)
            ->append(static_cast< ::java::lang::Object* >(ioe))->toString());
        throw ioe;
    }
}

void rice::environment::params::simple::SimpleParameters::addChangeListener(::rice::environment::params::ParameterChangeListener* p)
{
    npc(changeListeners)->add(static_cast< ::java::lang::Object* >(p));
}

void rice::environment::params::simple::SimpleParameters::removeChangeListener(::rice::environment::params::ParameterChangeListener* p)
{
    npc(changeListeners)->remove(static_cast< ::java::lang::Object* >(p));
}

void rice::environment::params::simple::SimpleParameters::fireChangeEvent(::java::lang::String* name, ::java::lang::String* val)
{
    auto i = npc(changeListeners)->iterator();
    while (npc(i)->hasNext()) {
        auto p = java_cast< ::rice::environment::params::ParameterChangeListener* >(java_cast< ::rice::environment::params::ParameterChangeListener* >(npc(i)->next()));
        npc(p)->parameterChange(name, val);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::params::simple::SimpleParameters::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.params.simple.SimpleParameters", 47);
    return c;
}

void rice::environment::params::simple::SimpleParameters::clinit()
{
struct string_init_ {
    string_init_() {
    FILENAME_EXTENSION_ = u".params"_j;
    ARRAY_SPACER_ = u","_j;
    defaultParamsFile_ = ::java::lang::StringBuilder().append(u"user"_j)->append(FILENAME_EXTENSION_)->toString();
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* rice::environment::params::simple::SimpleParameters::getClass0()
{
    return class_();
}

