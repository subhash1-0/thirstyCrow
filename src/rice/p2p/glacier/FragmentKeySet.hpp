// Generated from /pastry-2.1/src/rice/p2p/glacier/FragmentKeySet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
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

class rice::p2p::glacier::FragmentKeySet
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::IdSet
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::SortedMap* idSet {  };
    FragmentKey* cachedHash {  };
    bool validHash {  };
protected:
    void ctor();
    void ctor(FragmentKeySet* o);
    void ctor(::java::util::SortedMap* s);

public:
    virtual bool isMember(::rice::p2p::commonapi::Id* id);
    ::java::util::Iterator* getIterator() override;
    virtual ::int8_tArray* getHash();
    bool isMemberId(::rice::p2p::commonapi::Id* id) override;
    int32_t numElements() override;
    virtual void addMember(::rice::p2p::commonapi::Id* id);
    virtual void removeMember(::rice::p2p::commonapi::Id* id);
    virtual FragmentKey* minMember();
    virtual FragmentKey* maxMember();
    virtual FragmentKeySet* subSet(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to);
    virtual FragmentKeySet* subSet(FragmentKeyRange* range);
    ::java::lang::String* toString() override;
    void addId(::rice::p2p::commonapi::Id* id) override;
    void removeId(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::IdSet* subSet(::rice::p2p::commonapi::IdRange* range) override;
    ::int8_tArray* hash() override;
    ::java::lang::Object* clone() override;
    ::rice::p2p::commonapi::IdSet* build() override;
    ::rice::p2p::commonapi::IdArray* asArray_() override;

    // Generated
    FragmentKeySet();
    FragmentKeySet(FragmentKeySet* o);

public: /* protected */
    FragmentKeySet(::java::util::SortedMap* s);
protected:
    FragmentKeySet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
