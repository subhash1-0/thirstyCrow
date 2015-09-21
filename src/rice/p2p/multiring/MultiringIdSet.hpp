// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
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

class rice::p2p::multiring::MultiringIdSet
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::IdSet
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-7675959536005571206LL) };

public: /* protected */
    ::rice::p2p::commonapi::IdSet* set {  };
    ::rice::p2p::commonapi::Id* ringId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdSet* set);

public: /* protected */
    virtual ::rice::p2p::commonapi::IdSet* getSet();

public:
    int32_t numElements() override;
    void addId(::rice::p2p::commonapi::Id* id) override;
    void removeId(::rice::p2p::commonapi::Id* id) override;
    bool isMemberId(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::IdSet* subSet(::rice::p2p::commonapi::IdRange* range) override;
    ::java::util::Iterator* getIterator() override;
    ::rice::p2p::commonapi::IdArray* asArray_() override;
    ::int8_tArray* hash() override;
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;
    ::java::lang::Object* clone() override;
    ::rice::p2p::commonapi::IdSet* build() override;

    // Generated

public: /* protected */
    MultiringIdSet(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdSet* set);
protected:
    MultiringIdSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiringIdSet_getIterator_1;
};
