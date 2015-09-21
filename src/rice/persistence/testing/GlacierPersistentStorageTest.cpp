// Generated from /pastry-2.1/src/rice/persistence/testing/GlacierPersistentStorageTest.java
#include <rice/persistence/testing/GlacierPersistentStorageTest.hpp>

#include <java/io/BufferedInputStream.hpp>
#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/zip/GZIPInputStream.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/util/XMLObjectInputStream.hpp>
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
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::File, ::java::lang::ObjectArray, SerializableArray, ::java::lang::ComparableArray > FileArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
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

rice::persistence::testing::GlacierPersistentStorageTest::GlacierPersistentStorageTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::testing::GlacierPersistentStorageTest::GlacierPersistentStorageTest(::java::lang::String* root)  /* throws(IOException) */
    : GlacierPersistentStorageTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(root);
}

void rice::persistence::testing::GlacierPersistentStorageTest::ctor(::java::lang::String* root) /* throws(IOException) */
{
    super::ctor();
    this->root = new ::java::io::File(::java::lang::StringBuilder().append(u"FreePastry-Storage-Root/"_j)->append(root)->toString());
}

void rice::persistence::testing::GlacierPersistentStorageTest::start() /* throws(Exception) */
{
    process(root);
}

void rice::persistence::testing::GlacierPersistentStorageTest::process(::java::io::File* file) /* throws(Exception) */
{
    auto files = npc(file)->listFiles();
    for (auto i = int32_t(0); i < npc(files)->length; i++) {
        if(npc((*files)[i])->isFile() && (npc(npc((*files)[i])->getName())->length() > 20)) {
            ::java::io::ObjectInputStream* objin = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(new ::java::io::FileInputStream((*files)[i]))));
            npc(objin)->readObject();
            auto o = npc(objin)->readObject();
            if(dynamic_cast< ::rice::p2p::glacier::v2::FragmentAndManifest* >(o) != nullptr) {
                auto fm = java_cast< ::rice::p2p::glacier::v2::FragmentAndManifest* >(o);
                auto total = npc(npc(npc(fm)->fragment)->payload)->length + int32_t(24);
                total += npc(npc(npc(fm)->manifest)->getObjectHash())->length + npc(npc(npc(fm)->manifest)->getSignature())->length;
                total += npc(npc(npc(fm)->manifest)->getFragmentHashes())->length * npc((*npc(npc(fm)->manifest)->getFragmentHashes())[int32_t(0)])->length;
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc((*files)[i])->getName())->append(u"\t"_j)
                    ->append(total)
                    ->append(u"\t"_j)
                    ->append(npc((*files)[i])->length())->toString());
            } else {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: Found class "_j)->append(npc(npc(o)->getClass())->getName())->toString());
            }
            npc(objin)->close();
        } else if(npc((*files)[i])->isDirectory()) {
            process((*files)[i]);
        }
    }
}

void rice::persistence::testing::GlacierPersistentStorageTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto test = new GlacierPersistentStorageTest(u"sys08.cs.rice.edu-10001-glacier-immutable"_j);
    npc(test)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::GlacierPersistentStorageTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.testing.GlacierPersistentStorageTest", 53);
    return c;
}

java::lang::Class* rice::persistence::testing::GlacierPersistentStorageTest::getClass0()
{
    return class_();
}

