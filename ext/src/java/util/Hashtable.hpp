// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Dictionary.hpp>
#include <java/util/Map.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace util
    {
typedef ::SubArray< ::java::util::Map_Entry, ::java::lang::ObjectArray > Map_EntryArray;
typedef ::SubArray< ::java::util::Hashtable_Entry, ::java::lang::ObjectArray, Map_EntryArray > Hashtable_EntryArray;
    } // util
} // java

struct default_init_tag;

class java::util::Hashtable
    : public Dictionary
    , public virtual Map
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef Dictionary super;

private:
    static constexpr int32_t ENTRIES { int32_t(2) };
    static constexpr int32_t KEYS { int32_t(0) };
    static constexpr int32_t MAX_ARRAY_SIZE { int32_t(2147483639) };
    static constexpr int32_t VALUES { int32_t(1) };
    int32_t count {  };
    std::atomic< Set* > entrySet_ {  };
    std::atomic< Set* > keySet_ {  };
    float loadFactor {  };
    int32_t modCount {  };
    static constexpr int64_t serialVersionUID { int64_t(1421746759512286392LL) };
    Hashtable_EntryArray* table {  };
    int32_t threshold {  };
    std::atomic< Collection* > values_ {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(Map* arg0);
    void ctor(int32_t arg0, float arg1);
    /*void addEntry(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, int32_t arg3); (private) */

public:
    void clear() override;
    ::java::lang::Object* clone() override;
    ::java::lang::Object* compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    ::java::lang::Object* computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1) override;
    ::java::lang::Object* computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    virtual bool contains(::java::lang::Object* arg0);
    bool containsKey(::java::lang::Object* arg0) override;
    bool containsValue(::java::lang::Object* arg0) override;
    Enumeration* elements() override;
    Set* entrySet() override;
    bool equals(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;
    /*Enumeration* getEnumeration(int32_t arg0); (private) */
    /*Iterator* getIterator(int32_t arg0); (private) */
    ::java::lang::Object* getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    Set* keySet() override;
    Enumeration* keys() override;
    ::java::lang::Object* merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2) override;
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    void putAll(Map* arg0) override;
    ::java::lang::Object* putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    /*void reconstitutionPut(Hashtable_EntryArray* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2); (private) */

public: /* protected */
    virtual void rehash();

public:
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;
    bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2) override;
    void replaceAll(::java::util::function::BiFunction* arg0) override;
    int32_t size() override;
    ::java::lang::String* toString() override;
    Collection* values() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    Hashtable();
    Hashtable(int32_t arg0);
    Hashtable(Map* arg0);
    Hashtable(int32_t arg0, float arg1);
protected:
    Hashtable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
