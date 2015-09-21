// Generated from /pastry-2.1/src/rice/pastry/IdSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>

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

class rice::pastry::IdSet final
    : public virtual ::java::lang::Object
    , public ::rice::p2p::commonapi::IdSet
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-1565571743719309172LL) };

private:
    ::java::util::SortedMap* idSet {  };
    ::int8_tArray* cachedHash {  };
    bool validHash {  };
protected:
    void ctor();
    void ctor(::java::util::SortedMap* s);

public:
    int32_t numElements() override;
    void addMember(Id* id);
    void removeMember(Id* id);
    bool isMember(Id* id);
    Id* minMember();
    Id* maxMember();
    ::rice::pastry::IdSet* subSet(Id* from, Id* to);
    ::rice::pastry::IdSet* subSet(IdRange* range);
    ::java::util::Iterator* getIterator() override;
    ::int8_tArray* getHash();
    ::java::lang::String* toString() override;
    void addId(::rice::p2p::commonapi::Id* id) override;
    void removeId(::rice::p2p::commonapi::Id* id) override;
    bool isMemberId(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::IdSet* build() override;
    ::rice::p2p::commonapi::IdSet* subSet(::rice::p2p::commonapi::IdRange* range) override;
    ::int8_tArray* hash() override;
    ::rice::p2p::commonapi::IdArray* asArray_() override;
    ::java::lang::Object* clone() override;

    // Generated
    IdSet();
    IdSet(::java::util::SortedMap* s);
protected:
    IdSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
