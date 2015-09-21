// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/GenericProximityGenerator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/proximitygenerators/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/direct/ProximityGenerator.hpp>

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

namespace 
{
typedef ::SubArray< ::floatArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > floatArrayArray;
} // 

struct default_init_tag;

class rice::pastry::direct::proximitygenerators::GenericProximityGenerator
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::direct::ProximityGenerator
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::environment::random::RandomSource* random {  };

public: /* package */
    float MIN_DIST {  };

private:
    ::floatArrayArray* distance {  };
    static int32_t MAXOVERLAYSIZE_;

public:
    ::java::util::HashMap* assignedIndices {  };
    ::java::io::File* inFile_Matrix {  };
protected:
    void ctor(::rice::environment::Environment* env, ::java::io::File* inFile) /* throws(IOException) */;

public:
    ::rice::pastry::direct::NodeRecord* generateNodeRecord() override;

public: /* package */
    int32_t nodesPerStub {  };

public:
    virtual void setNodesPerStub(int32_t numPerStub);
    virtual void readOverlayMatrix(float delayFactor) /* throws(IOException) */;

private:
    bool stubIsFull(int32_t index);

public: /* package */
    int32_t numNodes {  };

private:
    void incrementStub(int32_t index);
    void decrementStub(int32_t index);

public:
    void setRandom(::rice::environment::random::RandomSource* random) override;

    // Generated
    GenericProximityGenerator(::rice::environment::Environment* env, ::java::io::File* inFile);
protected:
    GenericProximityGenerator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static int32_t& MAXOVERLAYSIZE();

private:
    virtual ::java::lang::Class* getClass0();
    friend class GenericProximityGenerator_GNNodeRecord;
};
