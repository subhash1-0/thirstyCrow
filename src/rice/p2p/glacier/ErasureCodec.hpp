// Generated from /pastry-2.1/src/rice/p2p/glacier/ErasureCodec.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
        } // glacier
    } // p2p
} // rice

namespace 
{
typedef ::SubArray< ::int64_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int64_tArrayArray;
} // 

struct default_init_tag;

class rice::p2p::glacier::ErasureCodec
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t numFragments {  };
    int32_t numSurvivors {  };

public: /* package */
    static constexpr int32_t Lfield { int32_t(10) };
    static constexpr int32_t MultField { int32_t(1023) };

private:
    static ::int32_tArray* ExpToFieldElt_;
    static ::int32_tArray* FieldEltToExp_;
    static bool isEltInitialized_;

public: /* protected */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(int32_t _numFragments, int32_t _numSurvivors, ::rice::environment::Environment* env);

public:
    virtual void dump(::int8_tArray* data);
    virtual FragmentArray* encodeObject(::rice::p2p::past::PastContent* obj, ::boolArray* generateFragment);
    virtual FragmentArray* encodeObject(::rice::p2p::past::rawserialization::RawPastContent* obj, ::boolArray* generateFragment);

public: /* protected */
    virtual void encodeChunk(::int32_tArray* buffer);

public:
    virtual FragmentArray* encode(::int8_tArray* bytes, int32_t length, ::boolArray* generateFragment);

public: /* protected */
    virtual void decodeChunk(::int32_tArray* buffer, int32_t nExtra, ::int32_tArray* RowInd, ::boolArray* haveFragment, ::int64_tArrayArray* InvMat, ::int32_tArray* ColInd);

public:
    virtual ::rice::p2p::past::PastContent* decode(FragmentArray* frag, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd);

public: /* protected */
    virtual ::rice::p2p::past::PastContent* deserialize(::int8_tArray* bytes, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException, ClassNotFoundException) */;
    virtual void initElt();

    // Generated

public:
    ErasureCodec(int32_t _numFragments, int32_t _numSurvivors, ::rice::environment::Environment* env);
protected:
    ErasureCodec(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

public: /* package */
    static ::int32_tArray*& ExpToFieldElt();
    static ::int32_tArray*& FieldEltToExp();
    static bool& isEltInitialized();

private:
    virtual ::java::lang::Class* getClass0();
};
