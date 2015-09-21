// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_store_3.hpp>

#include <java/io/File.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashSet.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/util/ReverseTreeMap.hpp>
#include <rice/persistence/PersistentStorage_OutofDiskSpaceException.hpp>
#include <rice/persistence/PersistentStorage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::persistence::PersistentStorage_store_3::PersistentStorage_store_3(PersistentStorage *PersistentStorage_this, ::rice::p2p::commonapi::Id* id, ::java::io::Serializable* obj, ::java::io::Serializable* metadata, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
    , id(id)
    , obj(obj)
    , metadata(metadata)
{
    clinit();
    ctor(c, sm);
}

rice::persistence::PersistentStorage_store_3::PersistentStorage_store_3(PersistentStorage *PersistentStorage_this, ::rice::p2p::commonapi::Id* id, ::java::io::Serializable* obj, ::java::io::Serializable* metadata)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
    , id(id)
    , obj(obj)
    , metadata(metadata)
{
    clinit();
    ctor();
}

java::lang::String* rice::persistence::PersistentStorage_store_3::toString()
{
    return ::java::lang::StringBuilder().append(u"store "_j)->append(static_cast< ::java::lang::Object* >(id))->toString();
}

java::lang::Object* rice::persistence::PersistentStorage_store_3::doWork() /* throws(Exception) */
{
    {
        synchronized synchronized_0(PersistentStorage_this->statLock);
        {
            PersistentStorage_this->numWrites++;
        }
    }
    if(npc(PersistentStorage_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PersistentStorage_this->logger)->log(::java::lang::StringBuilder().append(u"Storing object "_j)->append(static_cast< ::java::lang::Object* >(obj))
            ->append(u" under id "_j)
            ->append(npc(id)->toStringFull())
            ->append(u" in root "_j)
            ->append(static_cast< ::java::lang::Object* >(PersistentStorage_this->appDirectory))->toString());

    auto objFile = PersistentStorage_this->getFile(id);
    auto transcFile = PersistentStorage_this->makeTemporaryFile(id);
    if(npc(PersistentStorage_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PersistentStorage_this->logger)->log(::java::lang::StringBuilder().append(u"Writing object "_j)->append(static_cast< ::java::lang::Object* >(obj))
            ->append(u" to temporary file "_j)
            ->append(static_cast< ::java::lang::Object* >(transcFile))
            ->append(u" and renaming to "_j)
            ->append(static_cast< ::java::lang::Object* >(objFile))->toString());

    try {
        PersistentStorage::writeObject(obj, metadata, id, npc(npc(PersistentStorage_this->environment)->getTimeSource())->currentTimeMillis(), transcFile);
        if(npc(PersistentStorage_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(PersistentStorage_this->logger)->log(::java::lang::StringBuilder().append(u"Done writing object "_j)->append(static_cast< ::java::lang::Object* >(obj))
                ->append(u" under id "_j)
                ->append(npc(id)->toStringFull())
                ->append(u" in root "_j)
                ->append(static_cast< ::java::lang::Object* >(PersistentStorage_this->appDirectory))->toString());

        if(PersistentStorage_this->getUsedSpace() + PersistentStorage::getFileLength(transcFile) > PersistentStorage_this->getStorageSize())
            throw new PersistentStorage_OutofDiskSpaceException();

    } catch (::java::lang::Exception* e) {
        if(npc(PersistentStorage_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(PersistentStorage_this->logger)->logException(u""_j, e);

        PersistentStorage::deleteFile(transcFile);
        throw e;
    }
    if(npc(PersistentStorage_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PersistentStorage_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: Storing data of class "_j)->append(npc(npc(obj)->getClass())->getName())
            ->append(u" under "_j)
            ->append(npc(id)->toStringFull())
            ->append(u" of size "_j)
            ->append(npc(transcFile)->length())
            ->append(u" in "_j)
            ->append(PersistentStorage_this->name)->toString());

    PersistentStorage_this->decreaseUsedSpace(PersistentStorage::getFileLength(objFile));
    PersistentStorage_this->increaseUsedSpace(PersistentStorage::getFileLength(transcFile));
    PersistentStorage::renameFile(transcFile, objFile);
    if(PersistentStorage_this->index) {
        {
            synchronized synchronized_1(PersistentStorage_this->metadata);
            {
                npc(PersistentStorage_this->metadata)->put(id, metadata);
                npc(PersistentStorage_this->dirty)->add(static_cast< ::java::lang::Object* >(npc(objFile)->getParentFile()));
            }
        }
    }
    PersistentStorage_this->checkDirectory(npc(objFile)->getParentFile());
    return ::java::lang::Boolean::TRUE();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_store_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_store_3::getClass0()
{
    return class_();
}

