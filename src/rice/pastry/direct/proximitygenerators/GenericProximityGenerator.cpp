// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/GenericProximityGenerator.java
#include <rice/pastry/direct/proximitygenerators/GenericProximityGenerator.hpp>

#include <java/io/BufferedReader.hpp>
#include <java/io/File.hpp>
#include <java/io/FileReader.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/HashMap.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/direct/proximitygenerators/GenericProximityGenerator_GNNodeRecord.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::floatArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > floatArrayArray;
} // 

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

rice::pastry::direct::proximitygenerators::GenericProximityGenerator::GenericProximityGenerator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::proximitygenerators::GenericProximityGenerator::GenericProximityGenerator(::rice::environment::Environment* env, ::java::io::File* inFile)  /* throws(IOException) */
    : GenericProximityGenerator(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,inFile);
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::init()
{
    MIN_DIST = 2.0f;
    assignedIndices = new ::java::util::HashMap();
    nodesPerStub = int32_t(1);
    numNodes = int32_t(0);
}

int32_t& rice::pastry::direct::proximitygenerators::GenericProximityGenerator::MAXOVERLAYSIZE()
{
    clinit();
    return MAXOVERLAYSIZE_;
}
int32_t rice::pastry::direct::proximitygenerators::GenericProximityGenerator::MAXOVERLAYSIZE_;

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::ctor(::rice::environment::Environment* env, ::java::io::File* inFile) /* throws(IOException) */
{
    super::ctor();
    init();
    MAXOVERLAYSIZE_ = npc(npc(env)->getParameters())->getInt(u"pastry_direct_gtitm_max_overlay_size"_j);
    MIN_DIST = npc(npc(env)->getParameters())->getFloat(u"pastry_direct_min_delay"_j);
    auto delayFactor = npc(npc(env)->getParameters())->getFloat(u"pastry_direct_gtitm_delay_factor"_j);
    inFile_Matrix = inFile;
    if(inFile_Matrix == nullptr) {
        inFile_Matrix = new ::java::io::File(npc(npc(env)->getParameters())->getString(u"pastry_direct_gtitm_matrix_file"_j));
    }
    setNodesPerStub(npc(npc(env)->getParameters())->getInt(u"pastry_direct_gtitm_nodes_per_stub"_j));
    readOverlayMatrix(delayFactor);
}

rice::pastry::direct::NodeRecord* rice::pastry::direct::proximitygenerators::GenericProximityGenerator::generateNodeRecord()
{
    return new GenericProximityGenerator_GNNodeRecord(this);
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::setNodesPerStub(int32_t numPerStub)
{
    this->nodesPerStub = numPerStub;
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::readOverlayMatrix(float delayFactor) /* throws(IOException) */
{
    ::java::io::FileReader* fr = nullptr;
    try {
        fr = new ::java::io::FileReader(inFile_Matrix);
    } catch (::java::lang::Exception* e) {
        npc(fr)->close();
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"ERROR: The required inter-host distance matrix for Generic Network not found:"_j)->append(npc(inFile_Matrix)->getAbsolutePath())->toString());
    }
    auto in = new ::java::io::BufferedReader(fr);
    auto lineCount = int32_t(0);
    ::java::lang::String* line = nullptr;
    try {
        while ((line = npc(in)->readLine()) != nullptr) {
            ::java::lang::StringArray* words;
            words = npc(line)->split(u"[ \t]+"_j);
            if(distance == nullptr) {
                if(npc(words)->length < MAXOVERLAYSIZE_)
                    MAXOVERLAYSIZE_ = npc(words)->length;

                distance = new ::floatArrayArray(MAXOVERLAYSIZE_);
            }
            auto nodeCount = int32_t(0);
            for (auto i = int32_t(0); i < MAXOVERLAYSIZE_; i++) {
                if(npc((*words)[i])->length() > 0) {
                    (*(*distance)[lineCount])[nodeCount] = delayFactor * ::java::lang::Float::parseFloat((*words)[i]);
                    nodeCount++;
                    if(nodeCount == MAXOVERLAYSIZE_)
                        break;

                }
            }
            lineCount++;
            if(lineCount == MAXOVERLAYSIZE_)
                break;

        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Size of Generic Network matrix= "_j)->append(lineCount)->toString());
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Exception"_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

bool rice::pastry::direct::proximitygenerators::GenericProximityGenerator::stubIsFull(int32_t index)
{
    if(!npc(assignedIndices)->containsKey(::java::lang::Integer::valueOf(index)))
        return false;

    return (npc(java_cast< ::java::lang::Integer* >(npc(assignedIndices)->get(::java::lang::Integer::valueOf(index)))))->intValue() >= nodesPerStub;
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::incrementStub(int32_t index)
{
    numNodes++;
    auto val = int32_t(0);
    if(npc(assignedIndices)->containsKey(::java::lang::Integer::valueOf(index))) {
        val = (npc(java_cast< ::java::lang::Integer* >(npc(assignedIndices)->get(::java::lang::Integer::valueOf(index)))))->intValue();
    }
    npc(assignedIndices)->put(::java::lang::Integer::valueOf(index), ::java::lang::Integer::valueOf(val + int32_t(1)));
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::decrementStub(int32_t index)
{
    numNodes--;
    int32_t val = (npc(java_cast< ::java::lang::Integer* >(npc(assignedIndices)->get(::java::lang::Integer::valueOf(index)))))->intValue();
    npc(assignedIndices)->put(::java::lang::Integer::valueOf(index), ::java::lang::Integer::valueOf(val - int32_t(1)));
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::setRandom(::rice::environment::random::RandomSource* random)
{
    this->random = random;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::proximitygenerators::GenericProximityGenerator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.proximitygenerators.GenericProximityGenerator", 64);
    return c;
}

void rice::pastry::direct::proximitygenerators::GenericProximityGenerator::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        MAXOVERLAYSIZE_ = int32_t(2000);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::direct::proximitygenerators::GenericProximityGenerator::getClass0()
{
    return class_();
}

