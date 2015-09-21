// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage.hpp>

#include <java/io/BufferedInputStream.hpp>
#include <java/io/BufferedOutputStream.hpp>
#include <java/io/DataOutputStream.hpp>
#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/FileNotFoundException.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/FilenameFilter.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/RandomAccessFile.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <java/util/Vector.hpp>
#include <java/util/zip/GZIPInputStream.hpp>
#include <java/util/zip/GZIPOutputStream.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/util/ImmutableSortedMap.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>
#include <rice/p2p/util/ReverseTreeMap.hpp>
#include <rice/p2p/util/XMLObjectInputStream.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>
#include <rice/persistence/PersistentStorage_setTimer_1.hpp>
#include <rice/persistence/PersistentStorage_rename_2.hpp>
#include <rice/persistence/PersistentStorage_store_3.hpp>
#include <rice/persistence/PersistentStorage_unstore_4.hpp>
#include <rice/persistence/PersistentStorage_setMetadata_5.hpp>
#include <rice/persistence/PersistentStorage_getObject_6.hpp>
#include <rice/persistence/PersistentStorage_flush_7.hpp>
#include <rice/persistence/PersistentStorage_CharacterHashSet.hpp>
#include <rice/persistence/PersistentStorage_DirectoryFilter.hpp>
#include <rice/persistence/PersistentStorage_FileFilter.hpp>
#include <rice/selector/Timer.hpp>
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
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
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

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
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
rice::persistence::PersistentStorage::PersistentStorage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::PersistentStorage::PersistentStorage(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env)  /* throws(IOException) */
    : PersistentStorage(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory,rootDir,size,env);
}

rice::persistence::PersistentStorage::PersistentStorage(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env)  /* throws(IOException) */
    : PersistentStorage(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory,name,rootDir,size,env);
}

rice::persistence::PersistentStorage::PersistentStorage(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, bool index, ::rice::environment::Environment* env)  /* throws(IOException) */
    : PersistentStorage(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory,name,rootDir,size,index,env);
}

void rice::persistence::PersistentStorage::init()
{
    statLock = new ::java::lang::Object();
    statsWriteInterval = int32_t(60) * int32_t(1000);
    numWrites = int32_t(0);
    numReads = int32_t(0);
    numRenames = int32_t(0);
    numDeletes = int32_t(0);
    numMetadataWrites = int32_t(0);
}

constexpr int64_t rice::persistence::PersistentStorage::PERSISTENCE_MAGIC_NUMBER;

constexpr int64_t rice::persistence::PersistentStorage::PERSISTENCE_VERSION_2;

constexpr int64_t rice::persistence::PersistentStorage::PERSISTENCE_REVISION_2_0;

constexpr int64_t rice::persistence::PersistentStorage::PERSISTENCE_REVISION_2_1;

java::lang::String*& rice::persistence::PersistentStorage::BACKUP_DIRECTORY()
{
    clinit();
    return BACKUP_DIRECTORY_;
}
java::lang::String* rice::persistence::PersistentStorage::BACKUP_DIRECTORY_;

java::lang::String*& rice::persistence::PersistentStorage::LOST_AND_FOUND_DIRECTORY()
{
    clinit();
    return LOST_AND_FOUND_DIRECTORY_;
}
java::lang::String* rice::persistence::PersistentStorage::LOST_AND_FOUND_DIRECTORY_;

java::lang::String*& rice::persistence::PersistentStorage::METADATA_FILENAME()
{
    clinit();
    return METADATA_FILENAME_;
}
java::lang::String* rice::persistence::PersistentStorage::METADATA_FILENAME_;

constexpr int32_t rice::persistence::PersistentStorage::MAX_FILES;

constexpr int32_t rice::persistence::PersistentStorage::MAX_DIRECTORIES;

constexpr int32_t rice::persistence::PersistentStorage::METADATA_SYNC_TIME;

java::lang::String*& rice::persistence::PersistentStorage::ZERO_LENGTH_NAME()
{
    clinit();
    return ZERO_LENGTH_NAME_;
}
java::lang::String* rice::persistence::PersistentStorage::ZERO_LENGTH_NAME_;

void rice::persistence::PersistentStorage::ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env) /* throws(IOException) */
{
    ctor(factory, u"default"_j, rootDir, size, env);
}

void rice::persistence::PersistentStorage::ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env) /* throws(IOException) */
{
    ctor(factory, name, rootDir, size, true, env);
}

void rice::persistence::PersistentStorage::ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, bool index, ::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor();
    init();
    this->environment = env;
    logger = npc(npc(environment)->getLogManager())->getLogger(PersistentStorage::class_(), nullptr);
    this->factory = factory;
    this->name = name;
    this->rootDir = rootDir;
    this->storageSize = size;
    this->index = index;
    this->directories = new ::java::util::HashMap();
    this->prefixes = new ::java::util::HashMap();
    statsLastWritten = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    if(index) {
        this->dirty = new ::java::util::HashSet();
        this->metadata = new ::rice::p2p::util::ReverseTreeMap();
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Launching persistent storage in "_j)->append(rootDir)
            ->append(u" with name "_j)
            ->append(name)
            ->append(u" spliting factor "_j)
            ->append(MAX_FILES)->toString());

    init_();
}

void rice::persistence::PersistentStorage::printStats()
{
    {
        synchronized synchronized_0(statLock);
        {
            auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
            if((statsLastWritten / statsWriteInterval) != (now / statsWriteInterval)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"@L.PE name="_j)->append(name)
                        ->append(u" interval="_j)
                        ->append(statsLastWritten)
                        ->append(u"-"_j)
                        ->append(now)->toString());

                statsLastWritten = now;
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"@L.PE   objsTotal="_j)->append((index ? ::java::lang::StringBuilder().append(u""_j)->append(npc(npc(metadata)->keySet())->size())->toString() : u"?"_j))
                        ->append(u" objsBytesTotal="_j)
                        ->append(getTotalSize())->toString());

                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"@L.PE   numWrites="_j)->append(numWrites)
                        ->append(u" numReads="_j)
                        ->append(numReads)
                        ->append(u" numDeletes="_j)
                        ->append(numDeletes)->toString());

                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"@L.PE   numMetadataWrites="_j)->append(numMetadataWrites)
                        ->append(u" numRenames="_j)
                        ->append(numRenames)->toString());

            }
        }
    }
}

void rice::persistence::PersistentStorage::setTimer(::rice::selector::Timer* timer)
{
    if(index) {
        npc(timer)->scheduleAtFixedRate(new PersistentStorage_setTimer_1(this), npc(npc(environment)->getRandomSource())->nextInt(METADATA_SYNC_TIME), METADATA_SYNC_TIME);
    }
}

void rice::persistence::PersistentStorage::rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c)
{
    printStats();
    npc(npc(environment)->getProcessor())->processBlockingIO(new PersistentStorage_rename_2(this, oldId, newId, c, npc(environment)->getSelectorManager()));
}

void rice::persistence::PersistentStorage::store(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c)
{
    if(id == nullptr || obj == nullptr) {
        npc(c)->receiveResult(new ::java::lang::Boolean(false));
        return;
    }
    printStats();
    npc(npc(environment)->getProcessor())->processBlockingIO(new PersistentStorage_store_3(this, id, obj, metadata, c, npc(environment)->getSelectorManager()));
}

void rice::persistence::PersistentStorage::unstore(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    printStats();
    npc(npc(environment)->getProcessor())->processBlockingIO(new PersistentStorage_unstore_4(this, id, c, npc(environment)->getSelectorManager()));
}

bool rice::persistence::PersistentStorage::exists(::rice::p2p::commonapi::Id* id)
{
    if(index) {
        {
            synchronized synchronized_1(metadata);
            {
                return npc(metadata)->containsKey(id);
            }
        }
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"exists() not supported without indexing"_j);
    }
}

java::io::Serializable* rice::persistence::PersistentStorage::getMetadata(::rice::p2p::commonapi::Id* id)
{
    if(index) {
        {
            synchronized synchronized_2(metadata);
            {
                return java_cast< ::java::io::Serializable* >(npc(metadata)->get(id));
            }
        }
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"getMetadata() not supported without indexing"_j);
    }
}

void rice::persistence::PersistentStorage::setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* c)
{
    printStats();
    if(!exists(id)) {
        npc(c)->receiveResult(new ::java::lang::Boolean(false));
    } else {
        npc(npc(environment)->getProcessor())->processBlockingIO(new PersistentStorage_setMetadata_5(this, id, metadata, c, npc(environment)->getSelectorManager()));
    }
}

void rice::persistence::PersistentStorage::getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    printStats();
    if(index && (!exists(id))) {
        npc(c)->receiveResult(nullptr);
    } else {
        npc(npc(environment)->getProcessor())->processBlockingIO(new PersistentStorage_getObject_6(this, id, c, npc(environment)->getSelectorManager()));
    }
}

rice::p2p::commonapi::IdSet* rice::persistence::PersistentStorage::scan(::rice::p2p::commonapi::IdRange* range)
{
    if(index) {
        if(npc(range)->isEmpty())
            return npc(factory)->buildIdSet();
        else if(npc(npc(range)->getCCWId())->equals(npc(range)->getCWId()))
            return scan();
        else
            {
                synchronized synchronized_3(metadata);
                {
                    return npc(factory)->buildIdSet(new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->keySubMap(npc(range)->getCCWId(), npc(range)->getCWId())));
                }
            }
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"scan() not supported without indexing"_j);
    }
}

rice::p2p::commonapi::IdSet* rice::persistence::PersistentStorage::scan()
{
    if(index) {
        {
            synchronized synchronized_4(metadata);
            {
                return npc(factory)->buildIdSet(new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->keyMap()));
            }
        }
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"scan() not supported without indexing"_j);
    }
}

java::util::SortedMap* rice::persistence::PersistentStorage::scanMetadata(::rice::p2p::commonapi::IdRange* range)
{
    if(index) {
        if(npc(range)->isEmpty())
            return new ::rice::p2p::util::RedBlackMap();
        else if(npc(npc(range)->getCCWId())->equals(npc(range)->getCWId()))
            return scanMetadata();
        else
            {
                synchronized synchronized_5(metadata);
                {
                    return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->keySubMap(npc(range)->getCCWId(), npc(range)->getCWId()));
                }
            }
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"scanMetadata() not supported without indexing"_j);
    }
}

java::util::SortedMap* rice::persistence::PersistentStorage::scanMetadata()
{
    if(index) {
        return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->keyMap());
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"scanMetadata() not supported without indexing"_j);
    }
}

java::util::SortedMap* rice::persistence::PersistentStorage::scanMetadataValuesHead(::java::lang::Object* value)
{
    if(index) {
        return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->valueHeadMap(value));
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"scanMetadataValuesHead() not supported without indexing"_j);
    }
}

java::util::SortedMap* rice::persistence::PersistentStorage::scanMetadataValuesNull()
{
    if(index) {
        return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->valueNullMap());
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"scanMetadataValuesNull() not supported without indexing"_j);
    }
}

int64_t rice::persistence::PersistentStorage::getTotalSize()
{
    return usedSize;
}

int32_t rice::persistence::PersistentStorage::getSize()
{
    if(index) {
        return npc(metadata)->size();
    } else {
        throw new ::java::lang::UnsupportedOperationException(u"getSize() not supported without indexing"_j);
    }
}

void rice::persistence::PersistentStorage::flush(::rice::Continuation* c)
{
    npc(npc(environment)->getProcessor())->processBlockingIO(new PersistentStorage_flush_7(this, c, npc(environment)->getSelectorManager()));
}

void rice::persistence::PersistentStorage::init_() /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Initing directories"_j);

    initDirectories();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Initing directory map"_j);

    initDirectoryMap(appDirectory);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Initing files"_j);

    initFiles(appDirectory);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Initing file map"_j);

    initFileMap(appDirectory);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Syncing metadata"_j);

    if(index)
        writeDirty();

    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Done initing"_j);

}

void rice::persistence::PersistentStorage::initDirectories() /* throws(IOException) */
{
    rootDirectory = new ::java::io::File(rootDir);
    createDirectory(rootDirectory);
    backupDirectory = new ::java::io::File(rootDirectory, BACKUP_DIRECTORY_);
    createDirectory(backupDirectory);
    appDirectory = new ::java::io::File(backupDirectory, getName());
    createDirectory(appDirectory);
    lostDirectory = new ::java::io::File(backupDirectory, LOST_AND_FOUND_DIRECTORY_);
    createDirectory(lostDirectory);
}

void rice::persistence::PersistentStorage::initDirectoryMap(::java::io::File* dir)
{
    auto files = npc(dir)->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_DirectoryFilter(this)));
    npc(directories)->put(static_cast< ::java::lang::Object* >(dir), static_cast< ::java::lang::Object* >(files));
    for (auto i = int32_t(0); i < npc(files)->length; i++) 
                initDirectoryMap((*files)[i]);

}

void rice::persistence::PersistentStorage::initFiles(::java::io::File* dir) /* throws(IOException) */
{
    auto dirs = npc(dir)->list(new PersistentStorage_DirectoryFilter(this));
    auto files = npc(dir)->list(new PersistentStorage_FileFilter(this));
    for (auto i = int32_t(0); i < npc(files)->length; i++) {
        try {
            if(!initTemporaryFile(dir, (*files)[i])) {
                if(npc(dirs)->length > 0)
                    moveFileToCorrectDirectory(dir, (*files)[i]);

            }
        } catch (::java::lang::Exception* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"Got exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                    ->append(u" initting file "_j)
                    ->append((*files)[i])
                    ->append(u" - moving to lost+found."_j)->toString(), e);

            moveToLost(new ::java::io::File(dir, (*files)[i]));
        }
    }
    for (auto i = int32_t(0); i < npc(dirs)->length; i++) 
                initFiles(new ::java::io::File(dir, (*dirs)[i]));

    if(npc(dirs)->length > 0)
        deleteFile(new ::java::io::File(dir, METADATA_FILENAME_));

}

bool rice::persistence::PersistentStorage::initTemporaryFile(::java::io::File* parent, ::java::lang::String* name) /* throws(IOException) */
{
    if(!isTemporaryFile(name))
        return false;

    moveToLost(new ::java::io::File(parent, name));
    return true;
}

void rice::persistence::PersistentStorage::initFileMap(::java::io::File* dir) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Initting directory "_j)->append(static_cast< ::java::lang::Object* >(dir))->toString());

    checkDirectory(dir);
    if(!npc(dir)->exists())
        return;

    int64_t modified = int32_t(0);
    if(index) {
        try {
            modified = readMetadataFile(dir);
        } catch (::java::io::IOException* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"Got exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                    ->append(u" reading metadata file - regenerating"_j)->toString(), e);

        }
    }
    auto files = npc(dir)->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_FileFilter(this)));
    auto dirs = npc(dir)->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_DirectoryFilter(this)));
    for (auto i = int32_t(0); i < npc(files)->length; i++) {
        try {
            auto id = readKey((*files)[i]);
            auto len = getFileLength((*files)[i]);
            if(id == nullptr)
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"READING "_j)->append(static_cast< ::java::lang::Object* >((*files)[i]))
                        ->append(u" RETURNED NULL!"_j)->toString());


            if(len > 0) {
                increaseUsedSpace(len);
                if(index && ((!npc(metadata)->containsKey(id)) || (npc((*files)[i])->lastModified() > modified))) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Reading newer metadata out of file "_j)->append(static_cast< ::java::lang::Object* >((*files)[i]))
                            ->append(u" id "_j)
                            ->append(npc(id)->toStringFull())
                            ->append(u" "_j)
                            ->append(npc((*files)[i])->lastModified())
                            ->append(u" "_j)
                            ->append(modified)
                            ->append(u" "_j)
                            ->append(npc(metadata)->containsKey(id))->toString());

                    npc(metadata)->put(id, readMetadata((*files)[i]));
                    npc(dirty)->add(static_cast< ::java::lang::Object* >(dir));
                }
            } else {
                moveToLost((*files)[i]);
                if(index && npc(metadata)->containsKey(id)) {
                    npc(metadata)->remove(id);
                    npc(dirty)->add(static_cast< ::java::lang::Object* >(dir));
                }
            }
        } catch (::java::lang::Exception* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR: Received Exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                    ->append(u" while initing file "_j)
                    ->append(static_cast< ::java::lang::Object* >((*files)[i]))
                    ->append(u" - moving to lost+found."_j)->toString(), e);

            moveToLost((*files)[i]);
        }
    }
    for (auto i = int32_t(0); i < npc(dirs)->length; i++) 
                initFileMap((*dirs)[i]);

    checkDirectory(dir);
}

void rice::persistence::PersistentStorage::resolveConflict(::java::io::File* file1, ::java::io::File* file2, ::java::io::File* output) /* throws(IOException) */
{
    if(!npc(file2)->exists()) {
        renameFile(file1, output);
    } else if(!npc(file1)->exists()) {
        renameFile(file2, output);
    } else if(npc(file1)->equals(static_cast< ::java::lang::Object* >(file2))) {
        renameFile(file1, output);
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"resolving conflict between "_j)->append(static_cast< ::java::lang::Object* >(file1))
                ->append(u" and "_j)
                ->append(static_cast< ::java::lang::Object* >(file2))->toString());

        if(readVersion(file1) < readVersion(file2)) {
            moveToLost(file1);
            renameFile(file2, output);
        } else {
            moveToLost(file2);
            renameFile(file1, output);
        }
    }
}

void rice::persistence::PersistentStorage::moveToLost(::java::io::File* file) /* throws(IOException) */
{
    renameFile(file, new ::java::io::File(lostDirectory, ::java::lang::StringBuilder().append(getPrefix(npc(file)->getParentFile()))->append(npc(file)->getName())->toString()));
}

bool rice::persistence::PersistentStorage::checkDirectory(::java::io::File* directory) /* throws(IOException) */
{
    auto files = numFilesDir(directory);
    auto dirs = numDirectoriesDir(directory);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Checking directory "_j)->append(static_cast< ::java::lang::Object* >(directory))
            ->append(u" for oversize "_j)
            ->append(files)
            ->append(u"/"_j)
            ->append(dirs)->toString());

    if(files > MAX_FILES) {
        expandDirectory(directory);
        return true;
    } else if(dirs > MAX_DIRECTORIES) {
        reformatDirectory(directory);
        return true;
    } else if((files == 0) && (dirs == 0) && (!npc(directory)->equals(static_cast< ::java::lang::Object* >(appDirectory)))) {
        pruneDirectory(directory);
        return true;
    }
    return false;
}

void rice::persistence::PersistentStorage::pruneDirectory(::java::io::File* dir) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Pruning directory "_j)->append(static_cast< ::java::lang::Object* >(dir))
            ->append(u" due to emptiness"_j)->toString());

    deleteFile(new ::java::io::File(dir, METADATA_FILENAME_));
    deleteDirectory(dir);
    npc(directories)->remove(static_cast< ::java::lang::Object* >(dir));
    npc(prefixes)->remove(static_cast< ::java::lang::Object* >(dir));
    npc(this->directories)->put(static_cast< ::java::lang::Object* >(npc(dir)->getParentFile()), static_cast< ::java::lang::Object* >(npc(npc(dir)->getParentFile())->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_DirectoryFilter(this)))));
}

void rice::persistence::PersistentStorage::reformatDirectory(::java::io::File* dir) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Expanding directory "_j)->append(static_cast< ::java::lang::Object* >(dir))
            ->append(u" due to too many subdirectories"_j)->toString());

    auto newDirNames = getDirectories(npc(dir)->list(new PersistentStorage_DirectoryFilter(this)));
    reformatDirectory(dir, newDirNames);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Done expanding directory "_j)->append(static_cast< ::java::lang::Object* >(dir))->toString());

}

void rice::persistence::PersistentStorage::reformatDirectory(::java::io::File* dir, ::java::lang::StringArray* newDirNames) /* throws(IOException) */
{
    auto dirNames = npc(dir)->list(new PersistentStorage_DirectoryFilter(this));
    auto newDirs = new ::java::io::FileArray(npc(newDirNames)->length);
    for (auto i = int32_t(0); i < npc(newDirNames)->length; i++) {
        newDirs->set(i, new ::java::io::File(dir, (*newDirNames)[i]));
        createDirectory((*newDirs)[i]);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Creating directory "_j)->append((*newDirNames)[i])->toString());

        auto subDirNames = getMatchingDirectories((*newDirNames)[i], dirNames);
        auto newSubDirs = new ::java::io::FileArray(npc(subDirNames)->length);
        for (auto j = int32_t(0); j < npc(subDirNames)->length; j++) {
            auto oldDir = new ::java::io::File(dir, (*subDirNames)[j]);
            newSubDirs->set(j, new ::java::io::File((*newDirs)[i], npc((*subDirNames)[j])->substring(npc((*newDirNames)[i])->length())));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Moving the old direcotry "_j)->append(static_cast< ::java::lang::Object* >(oldDir))
                    ->append(u" to "_j)
                    ->append(static_cast< ::java::lang::Object* >((*newSubDirs)[j]))->toString());

            renameFile(oldDir, (*newSubDirs)[j]);
            npc(this->directories)->remove(static_cast< ::java::lang::Object* >(oldDir));
            npc(this->directories)->put(static_cast< ::java::lang::Object* >((*newSubDirs)[j]), static_cast< ::java::lang::Object* >(new ::java::io::FileArray(int32_t(0))));
        }
        npc(this->directories)->put(static_cast< ::java::lang::Object* >((*newDirs)[i]), static_cast< ::java::lang::Object* >(newSubDirs));
    }
    npc(this->directories)->put(static_cast< ::java::lang::Object* >(dir), static_cast< ::java::lang::Object* >(newDirs));
}

java::lang::StringArray* rice::persistence::PersistentStorage::getMatchingDirectories(::java::lang::String* prefix, ::java::lang::StringArray* dirNames)
{
    auto result = new ::java::util::Vector();
    for (auto i = int32_t(0); i < npc(dirNames)->length; i++) 
                if(npc((*dirNames)[i])->startsWith(prefix))
            npc(result)->add(static_cast< ::java::lang::Object* >((*dirNames)[i]));


    return java_cast< ::java::lang::StringArray* >(java_cast< ::java::lang::ObjectArray* >(npc(result)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::lang::StringArray(int32_t(0))))));
}

void rice::persistence::PersistentStorage::expandDirectory(::java::io::File* dir) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Expanding directory "_j)->append(static_cast< ::java::lang::Object* >(dir))
            ->append(u" due to too many files"_j)->toString());

    auto fileNames = npc(dir)->list(new PersistentStorage_FileFilter(this));
    auto dirNames = getDirectories(fileNames);
    auto dirs = new ::java::io::FileArray(npc(dirNames)->length);
    for (auto i = int32_t(0); i < npc(dirNames)->length; i++) {
        dirs->set(i, new ::java::io::File(dir, (*dirNames)[i]));
        npc(directories)->put(static_cast< ::java::lang::Object* >((*dirs)[i]), static_cast< ::java::lang::Object* >(new ::java::io::FileArray(int32_t(0))));
        if(npc((*dirs)[i])->exists() && npc((*dirs)[i])->isFile())
            renameFile((*dirs)[i], new ::java::io::File(dir, ::java::lang::StringBuilder().append(npc((*dirs)[i])->getName())->append(ZERO_LENGTH_NAME_)->toString()));

        createDirectory((*dirs)[i]);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Creating directory "_j)->append((*dirNames)[i])->toString());

        if(index)
            npc(dirty)->add(static_cast< ::java::lang::Object* >((*dirs)[i]));

    }
    npc(directories)->put(static_cast< ::java::lang::Object* >(dir), static_cast< ::java::lang::Object* >(dirs));
    auto files = npc(dir)->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_FileFilter(this)));
    for (auto i = int32_t(0); i < npc(files)->length; i++) {
        for (auto j = int32_t(0); j < npc(dirs)->length; j++) {
            if(npc(npc((*files)[i])->getName())->startsWith(npc((*dirs)[j])->getName())) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Renaming file "_j)->append(static_cast< ::java::lang::Object* >((*files)[i]))
                        ->append(u" to "_j)
                        ->append(static_cast< ::java::lang::Object* >(new ::java::io::File((*dirs)[j], npc(npc((*files)[i])->getName())->substring(npc(npc((*dirs)[j])->getName())->length()))))->toString());

                renameFile((*files)[i], new ::java::io::File((*dirs)[j], npc(npc((*files)[i])->getName())->substring(npc(npc((*dirs)[j])->getName())->length())));
                break;
            }
        }
    }
    deleteFile(new ::java::io::File(dir, METADATA_FILENAME_));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Done expanding directory "_j)->append(static_cast< ::java::lang::Object* >(dir))->toString());

}

java::lang::StringArray* rice::persistence::PersistentStorage::getDirectories(::java::lang::StringArray* names)
{
    auto length = getPrefixLength(names);
    auto prefix = npc((*names)[int32_t(0)])->substring(0, length);
    auto set = new PersistentStorage_CharacterHashSet(this);
    for (auto i = int32_t(0); i < npc(names)->length; i++) {
        if(npc((*names)[i])->length() > length)
            npc(set)->put(npc((*names)[i])->charAt(length));

    }
    auto splits = npc(set)->get();
    auto result = new ::java::lang::StringArray(npc(splits)->length);
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                result->set(i, ::java::lang::StringBuilder().append(prefix)->append((*splits)[i])->toString());

    return result;
}

int32_t rice::persistence::PersistentStorage::getPrefixLength(::java::lang::StringArray* names)
{
    auto length = npc((*names)[int32_t(0)])->length() - int32_t(1);
    for (auto i = int32_t(0); i < npc(names)->length; i++) 
                length = getPrefixLength((*names)[int32_t(0)], (*names)[i], length);

    return length;
}

int32_t rice::persistence::PersistentStorage::getPrefixLength(::java::lang::String* a, ::java::lang::String* b, int32_t max)
{
    auto i = int32_t(0);
    for (; (i < npc(a)->length() - int32_t(1)) && (i < npc(b)->length() - int32_t(1)) && (i < max); i++) 
                if(npc(a)->charAt(i) != npc(b)->charAt(i))
            return i;


    return i;
}

void rice::persistence::PersistentStorage::moveFileToCorrectDirectory(::java::io::File* parent, ::java::lang::String* name) /* throws(IOException) */
{
    auto file = new ::java::io::File(parent, name);
    auto id = readKeyFromFile(file);
    auto dest = getDirectoryForId(id);
    if(!npc(dest)->equals(static_cast< ::java::lang::Object* >(parent))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"moving file "_j)->append(static_cast< ::java::lang::Object* >(file))
                ->append(u" to correct directory "_j)
                ->append(static_cast< ::java::lang::Object* >(dest))
                ->append(u" from "_j)
                ->append(static_cast< ::java::lang::Object* >(parent))->toString());

        auto other = new ::java::io::File(dest, npc(npc(id)->toStringFull())->substring(npc(getPrefix(dest))->length()));
        resolveConflict(file, other, other);
        checkDirectory(dest);
    }
}

void rice::persistence::PersistentStorage::flushDirectory(::java::io::File* dir) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Flushing file "_j)->append(static_cast< ::java::lang::Object* >(dir))->toString());

    if(!npc(dir)->isDirectory()) {
        auto id = readKey(dir);
        if(index) {
            {
                synchronized synchronized_6(metadata);
                {
                    npc(metadata)->remove(id);
                }
            }
        }
        decreaseUsedSpace(npc(dir)->length());
        deleteFile(dir);
    } else {
        auto dirs = npc(dir)->listFiles();
        for (auto i = int32_t(0); i < npc(dirs)->length; i++) {
            flushDirectory((*dirs)[i]);
            npc(directories)->remove(static_cast< ::java::lang::Object* >((*dirs)[i]));
            npc(prefixes)->remove(static_cast< ::java::lang::Object* >((*dirs)[i]));
            deleteFile((*dirs)[i]);
        }
    }
}

void rice::persistence::PersistentStorage::createDirectory(::java::io::File* directory) /* throws(IOException) */
{
    clinit();
    if((directory == nullptr) || (npc(directory)->exists() && npc(directory)->isFile()) || (!(npc(directory)->exists()) && (!npc(directory)->mkdirs())))
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Creation of directory "_j)->append(static_cast< ::java::lang::Object* >(directory))
            ->append(u" failed!"_j)->toString());

}

void rice::persistence::PersistentStorage::deleteDirectory(::java::io::File* directory) /* throws(IOException) */
{
    clinit();
    if((directory != nullptr) && npc(directory)->exists()) {
        if(npc(npc(directory)->listFiles())->length > 0)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Cannot delete "_j)->append(static_cast< ::java::lang::Object* >(directory))
                ->append(u" - directory is not empty!"_j)->toString());

        if(!npc(directory)->delete_())
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Deletion of directory "_j)->append(static_cast< ::java::lang::Object* >(directory))
                ->append(u" failed!"_j)->toString());

    }
}

int64_t rice::persistence::PersistentStorage::getFileLength(::java::io::File* file)
{
    clinit();
    return (((file != nullptr) && npc(file)->exists()) ? npc(file)->length() : static_cast< int64_t >(int32_t(0)));
}

void rice::persistence::PersistentStorage::renameFile(::java::io::File* oldFile, ::java::io::File* newFile) /* throws(IOException) */
{
    clinit();
    if((oldFile != nullptr) && npc(oldFile)->exists() && (!npc(oldFile)->equals(static_cast< ::java::lang::Object* >(newFile)))) {
        deleteFile(newFile);
        if(!npc(oldFile)->renameTo(newFile))
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Rename of "_j)->append(static_cast< ::java::lang::Object* >(oldFile))
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(newFile))
                ->append(u" failed!"_j)->toString());

    }
}

void rice::persistence::PersistentStorage::deleteFile(::java::io::File* file) /* throws(IOException) */
{
    clinit();
    if((file != nullptr) && npc(file)->exists() && (!npc(file)->delete_()))
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Delete of "_j)->append(static_cast< ::java::lang::Object* >(file))
            ->append(u" failed!"_j)->toString());

}

bool rice::persistence::PersistentStorage::isTemporaryFile(::java::lang::String* name)
{
    return (npc(name)->indexOf(u"."_j) >= 0);
}

java::io::File* rice::persistence::PersistentStorage::makeTemporaryFile(::rice::p2p::commonapi::Id* id) /* throws(IOException) */
{
    auto directory = getDirectoryForId(id);
    auto file = new ::java::io::File(directory, ::java::lang::StringBuilder().append(npc(npc(id)->toStringFull())->substring(npc(getPrefix(directory))->length()))->append(u"."_j)
        ->append(npc(npc(environment)->getRandomSource())->nextInt() % int32_t(100))->toString());
    while (npc(file)->exists()) 
                file = new ::java::io::File(directory, ::java::lang::StringBuilder().append(npc(npc(id)->toStringFull())->substring(npc(getPrefix(directory))->length()))->append(u"."_j)
            ->append(npc(npc(environment)->getRandomSource())->nextInt() % int32_t(100))->toString());

    return file;
}

bool rice::persistence::PersistentStorage::isAncestor(::java::io::File* file, ::java::io::File* ancestor)
{
    while ((file != nullptr) && (!npc(file)->equals(static_cast< ::java::lang::Object* >(ancestor)))) {
        file = npc(file)->getParentFile();
    }
    return (file != nullptr);
}

java::io::File* rice::persistence::PersistentStorage::getFile(::rice::p2p::commonapi::Id* id) /* throws(IOException) */
{
    auto dir = getDirectoryForId(id);
    auto name = npc(npc(id)->toStringFull())->substring(npc(getPrefix(dir))->length());
    if(npc(name)->equals(static_cast< ::java::lang::Object* >(u""_j)))
        name = ZERO_LENGTH_NAME_;

    auto file = new ::java::io::File(dir, name);
    if(npc(file)->exists() && npc(file)->isDirectory())
        file = new ::java::io::File(file, ZERO_LENGTH_NAME_);

    return file;
}

java::io::File* rice::persistence::PersistentStorage::getDirectoryForId(::rice::p2p::commonapi::Id* id) /* throws(IOException) */
{
    return getDirectoryForName(npc(id)->toStringFull());
}

java::io::File* rice::persistence::PersistentStorage::getDirectoryForName(::java::lang::String* name) /* throws(IOException) */
{
    return getDirectoryForName(name, appDirectory);
}

java::io::File* rice::persistence::PersistentStorage::getDirectoryForName(::java::lang::String* name, ::java::io::File* dir) /* throws(IOException) */
{
    auto subDirs = java_cast< ::java::io::FileArray* >(java_cast< ::java::lang::Object* >(npc(directories)->get(static_cast< ::java::lang::Object* >(dir))));
    if(npc(subDirs)->length == 0) {
        return dir;
    } else {
        for (auto i = int32_t(0); i < npc(subDirs)->length; i++) 
                        if(npc(name)->startsWith(npc((*subDirs)[i])->getName()))
                return getDirectoryForName(npc(name)->substring(npc(npc((*subDirs)[i])->getName())->length()), (*subDirs)[i]);
            else if((npc(name)->length() == 0) && npc(npc((*subDirs)[i])->getName())->equals(static_cast< ::java::lang::Object* >(ZERO_LENGTH_NAME_)))
                return getDirectoryForName(name, (*subDirs)[i]);


        if((npc(name)->length() >= npc(npc((*subDirs)[int32_t(0)])->getName())->length()) || ((npc(name)->length() == 0) && (npc(npc((*subDirs)[int32_t(0)])->getName())->length() == 1))) {
            auto newDir = new ::java::io::File(dir, (npc(name)->length() == 0 ? ZERO_LENGTH_NAME_ : npc(name)->substring(0, npc(npc((*subDirs)[int32_t(0)])->getName())->length())));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Necessarily creating dir "_j)->append(npc(newDir)->getName())->toString());

            createDirectory(newDir);
            npc(this->directories)->put(static_cast< ::java::lang::Object* >(dir), static_cast< ::java::lang::Object* >(append(subDirs, newDir)));
            npc(this->directories)->put(static_cast< ::java::lang::Object* >(newDir), static_cast< ::java::lang::Object* >(new ::java::io::FileArray(int32_t(0))));
            if(checkDirectory(dir)) {
                return getDirectoryForName(name, dir);
            } else {
                return newDir;
            }
        } else {
            auto dirs = new ::java::lang::StringArray(npc(subDirs)->length + int32_t(1));
            for (auto i = int32_t(0); i < npc(subDirs)->length; i++) 
                                dirs->set(i, npc((*subDirs)[i])->getName());

            dirs->set(npc(subDirs)->length, (npc(name)->length() == 0 ? ZERO_LENGTH_NAME_ : name));
            reformatDirectory(dir, getDirectories(dirs));
            return getDirectoryForName(name, dir);
        }
    }
}

java::lang::String* rice::persistence::PersistentStorage::getPostfix(::rice::p2p::commonapi::Id* id, ::java::io::File* file)
{
    return npc(npc(id)->toStringFull())->substring(npc(getPrefix(file))->length());
}

java::lang::String* rice::persistence::PersistentStorage::getPrefix(::java::io::File* file)
{
    if(java_cast< ::java::lang::Object* >(npc(prefixes)->get(static_cast< ::java::lang::Object* >(file))) != nullptr)
        return java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(prefixes)->get(static_cast< ::java::lang::Object* >(file))));

    auto buffer = new ::java::lang::StringBuffer();
    while (!npc(file)->equals(static_cast< ::java::lang::Object* >(appDirectory))) {
        npc(buffer)->insert(int32_t(0), npc(npc(file)->getName())->replaceAll(ZERO_LENGTH_NAME_, u""_j));
        file = npc(file)->getParentFile();
    }
    npc(prefixes)->put(static_cast< ::java::lang::Object* >(file), static_cast< ::java::lang::Object* >(npc(buffer)->toString()));
    return getPrefix(file);
}

java::io::FileArray* rice::persistence::PersistentStorage::append(::java::io::FileArray* files, ::java::io::File* file)
{
    auto result = new ::java::io::FileArray(npc(files)->length + int32_t(1));
    for (auto i = int32_t(0); i < npc(files)->length; i++) 
                result->set(i, (*files)[i]);

    result->set(npc(files)->length, file);
    return result;
}

int32_t rice::persistence::PersistentStorage::numDirectoriesDir(::java::io::File* dir)
{
    return npc(npc(dir)->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_DirectoryFilter(this))))->length;
}

int32_t rice::persistence::PersistentStorage::numFilesDir(::java::io::File* dir)
{
    return npc(npc(dir)->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_FileFilter(this))))->length;
}

bool rice::persistence::PersistentStorage::isFile(::java::io::File* parent, ::java::lang::String* name)
{
    return ((!(new ::java::io::File(parent, name))->isDirectory()) && (!npc(name)->equals(static_cast< ::java::lang::Object* >(METADATA_FILENAME_))));
}

bool rice::persistence::PersistentStorage::isDirectory(::java::io::File* parent, ::java::lang::String* name)
{
    return (new ::java::io::File(parent, name))->isDirectory();
}

bool rice::persistence::PersistentStorage::containsDir(::java::io::File* dir)
{
    return (npc(npc(dir)->listFiles(static_cast< ::java::io::FilenameFilter* >(new PersistentStorage_DirectoryFilter(this))))->length != 0);
}

void rice::persistence::PersistentStorage::writeDirty()
{
    auto files = java_cast< ::java::io::FileArray* >(java_cast< ::java::lang::ObjectArray* >(npc(dirty)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::io::FileArray(int32_t(0))))));
    for (auto i = int32_t(0); i < npc(files)->length; i++) {
        auto map = new ::java::util::HashMap();
        auto range = getRangeForDirectory((*files)[i]);
        ::java::util::Iterator* keys = nullptr;
        if(npc(npc(range)->getCCWId())->compareTo(npc(range)->getCWId()) <= 0)
            keys = npc(npc(npc(metadata)->keySubMap(npc(range)->getCCWId(), npc(range)->getCWId()))->keySet())->iterator();
        else
            keys = npc(npc(npc(metadata)->keyTailMap(npc(range)->getCCWId()))->keySet())->iterator();
        while (npc(keys)->hasNext()) {
            auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(keys)->next()));
            npc(map)->put(static_cast< ::java::lang::Object* >(next), static_cast< ::java::lang::Object* >(npc(metadata)->get(next)));
        }
        try {
            writeMetadataFile((*files)[i], map);
            {
                synchronized synchronized_7(metadata);
                {
                    npc(dirty)->remove(static_cast< ::java::lang::Object* >((*files)[i]));
                }
            }
        } catch (::java::io::FileNotFoundException* f) {
            try {
                {
                    synchronized synchronized_8(metadata);
                    {
                        npc(dirty)->remove(static_cast< ::java::lang::Object* >((*files)[i]));
                    }
                }
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR: Could not find directory while writing out metadata in '"_j)->append(npc((*files)[i])->getCanonicalPath())
                        ->append(u"' - removing from dirty list and continuing!"_j)->toString(), f);

            } catch (::java::io::IOException* g) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"PANIC: Got IOException "_j)->append(static_cast< ::java::lang::Object* >(g))
                        ->append(u" trying to detail FNF exception "_j)
                        ->append(static_cast< ::java::lang::Object* >(f))
                        ->append(u" while writing out file "_j)
                        ->append(static_cast< ::java::lang::Object* >((*files)[i]))->toString(), g);

            }
        } catch (::java::io::IOException* e) {
            try {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR: Got error "_j)->append(static_cast< ::java::lang::Object* >(e))
                        ->append(u" while writing out metadata in '"_j)
                        ->append(npc((*files)[i])->getCanonicalPath())
                        ->append(u"' - aborting!"_j)->toString(), e);

            } catch (::java::io::IOException* f) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"PANIC: Got IOException "_j)->append(static_cast< ::java::lang::Object* >(f))
                        ->append(u" trying to detail exception "_j)
                        ->append(static_cast< ::java::lang::Object* >(e))
                        ->append(u" while writing out file "_j)
                        ->append(static_cast< ::java::lang::Object* >((*files)[i]))->toString(), f);

            }
        }
    }
}

int64_t rice::persistence::PersistentStorage::readMetadataFile(::java::io::File* file) /* throws(IOException) */
{
    auto metadata = new ::java::io::File(file, METADATA_FILENAME_);
    if(!npc(metadata)->exists())
        return -int64_t(1LL);

    ::java::io::FileInputStream* fin = nullptr;
    {
        auto finally0 = finally([&] {
            npc(fin)->close();
        });
        {
            fin = new ::java::io::FileInputStream(metadata);
            auto objin = new ::java::io::ObjectInputStream(new ::java::io::BufferedInputStream(fin));
            auto range = getRangeForDirectory(file);
            try {
                auto map = java_cast< ::java::util::HashMap* >(npc(objin)->readObject());
                auto keys = npc(npc(map)->keySet())->iterator();
                while (npc(keys)->hasNext()) {
                    auto id = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(keys)->next()));
                    if((npc(range)->containsId(id)) && ((new ::java::io::File(file, npc(npc(id)->toStringFull())->substring(npc(getPrefix(file))->length())))->exists()))
                        npc(this->metadata)->put(id, java_cast< ::java::lang::Object* >(npc(map)->get(static_cast< ::java::lang::Object* >(id))));
                    else
                        npc(dirty)->add(static_cast< ::java::lang::Object* >(file));
                }
                return npc(metadata)->lastModified();
            } catch (::java::lang::ClassNotFoundException* e) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR: Got exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                        ->append(u" while reading metadata file "_j)
                        ->append(static_cast< ::java::lang::Object* >(metadata))
                        ->append(u" - rebuilding file"_j)->toString(), e);

                deleteFile(metadata);
                return 0LL;
            } catch (::java::io::IOException* e) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR: Got exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                        ->append(u" while reading metadata file "_j)
                        ->append(static_cast< ::java::lang::Object* >(metadata))
                        ->append(u" - rebuilding file"_j)->toString(), e);

                deleteFile(metadata);
                return 0LL;
            }
        }
    }

}

void rice::persistence::PersistentStorage::writeMetadataFile(::java::io::File* file, ::java::util::HashMap* map) /* throws(IOException) */
{
    clinit();
    ::java::io::FileOutputStream* fout = nullptr;
    {
        auto finally1 = finally([&] {
            if(fout != nullptr)
                npc(fout)->close();

        });
        try {
            fout = new ::java::io::FileOutputStream(new ::java::io::File(file, METADATA_FILENAME_));
            auto objout = new ::java::io::ObjectOutputStream(new ::java::io::BufferedOutputStream(fout));
            npc(objout)->writeObject(static_cast< ::java::lang::Object* >(map));
            npc(objout)->close();
        } catch (::java::io::IOException* ioe) {
            throw new ::rice::p2p::util::rawserialization::JavaSerializationException(map, ioe);
        }
    }
}

rice::p2p::commonapi::IdRange* rice::persistence::PersistentStorage::getRangeForDirectory(::java::io::File* dir)
{
    auto result = u""_j;
    while (!npc(dir)->equals(static_cast< ::java::lang::Object* >(appDirectory))) {
        result = ::java::lang::StringBuilder().append(npc(dir)->getName())->append(result)->toString();
        dir = npc(dir)->getParentFile();
    }
    return npc(factory)->buildIdRangeFromPrefix(result);
}

java::io::Serializable* rice::persistence::PersistentStorage::readObject(::java::io::File* file, int32_t offset) /* throws(IOException) */
{
    clinit();
    ::java::io::FileInputStream* fin = nullptr;
    {
        auto finally2 = finally([&] {
            npc(fin)->close();
        });
        {
            try {
                fin = new ::java::io::FileInputStream(file);
                ::java::io::ObjectInputStream* objin = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(fin)));
                for (auto i = int32_t(0); i < offset; i++) 
                                        npc(objin)->readObject();

                return java_cast< ::java::io::Serializable* >(npc(objin)->readObject());
            } catch (::java::lang::ClassNotFoundException* e) {
                throw new ::java::io::IOException(npc(e)->getMessage());
            }
        }
    }

}

java::io::Serializable* rice::persistence::PersistentStorage::readData(::java::io::File* file) /* throws(IOException) */
{
    clinit();
    return readObject(file, 1);
}

java::io::Serializable* rice::persistence::PersistentStorage::readMetadata(::java::io::File* file) /* throws(IOException) */
{
    if(npc(file)->length() < 32)
        return nullptr;

    ::java::io::RandomAccessFile* ras = nullptr;
    {
        auto finally3 = finally([&] {
            npc(ras)->close();
        });
        {
            ras = new ::java::io::RandomAccessFile(file, u"r"_j);
            npc(ras)->seek(npc(file)->length() - int32_t(32));
            if(npc(ras)->readLong() != PERSISTENCE_MAGIC_NUMBER) {
                return nullptr;
            } else if(npc(ras)->readLong() != PERSISTENCE_VERSION_2) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Persistence version did not match - exiting!"_j);

                return nullptr;
            } else if(npc(ras)->readLong() > PERSISTENCE_REVISION_2_1) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Persistence revision did not match - exiting!"_j);

                return nullptr;
            }
            auto length = npc(ras)->readLong();
            npc(ras)->seek(npc(file)->length() - int32_t(32) - length);
            ::java::io::FileInputStream* fis = nullptr;
            {
                auto finally4 = finally([&] {
                    npc(fis)->close();
                });
                {
                    fis = new ::java::io::FileInputStream(npc(ras)->getFD());
                    ::java::io::ObjectInputStream* objin = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(fis)));
                    try {
                        return java_cast< ::java::io::Serializable* >(npc(objin)->readObject());
                    } catch (::java::lang::ClassNotFoundException* e) {
                        throw new ::java::io::IOException(npc(e)->getMessage());
                    }
                }
            }

        }
    }

}

rice::p2p::commonapi::Id* rice::persistence::PersistentStorage::readKey(::java::io::File* file)
{
    auto s = ::java::lang::StringBuilder().append(getPrefix(npc(file)->getParentFile()))->append(npc(npc(file)->getName())->replaceAll(ZERO_LENGTH_NAME_, u""_j))->toString();
    if(npc(s)->indexOf(u"."_j) >= 0) {
        return npc(factory)->buildIdFromToString(npc(s)->toCharArray_(), 0, npc(s)->indexOf(u"."_j));
    } else {
        return npc(factory)->buildIdFromToString(npc(s)->toCharArray_(), 0, npc(s)->length());
    }
}

rice::p2p::commonapi::Id* rice::persistence::PersistentStorage::readKeyFromFile(::java::io::File* file) /* throws(IOException) */
{
    return java_cast< ::rice::p2p::commonapi::Id* >(readObject(file, 0));
}

int64_t rice::persistence::PersistentStorage::readVersion(::java::io::File* file) /* throws(IOException) */
{
    clinit();
    auto temp = java_cast< ::java::lang::Long* >(readObject(file, 2));
    return (temp == nullptr ? static_cast< int64_t >(int32_t(0)) : npc(temp)->longValue());
}

int64_t rice::persistence::PersistentStorage::writeObject(::java::io::Serializable* obj, ::java::io::Serializable* metadata, ::rice::p2p::commonapi::Id* key, int64_t version, ::java::io::File* file) /* throws(IOException) */
{
    clinit();
    ::java::io::FileOutputStream* fout = nullptr;
    {
        auto finally5 = finally([&] {
            if(fout != nullptr)
                npc(fout)->close();

        });
        {
            fout = new ::java::io::FileOutputStream(file);
            ::java::io::ObjectOutputStream* objout = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(fout)));
            npc(objout)->writeObject(static_cast< ::java::lang::Object* >(key));
            npc(objout)->writeObject(static_cast< ::java::lang::Object* >(obj));
            npc(objout)->writeObject(static_cast< ::java::lang::Object* >(new ::java::lang::Long(version)));
            npc(objout)->close();
        }
    }

    auto len1 = npc(file)->length();
    {
        auto finally6 = finally([&] {
            npc(fout)->close();
        });
        {
            fout = new ::java::io::FileOutputStream(file, true);
            ::java::io::ObjectOutputStream* objout = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(fout)));
            npc(objout)->writeObject(static_cast< ::java::lang::Object* >(metadata));
            npc(objout)->close();
        }
    }

    auto len2 = npc(file)->length();
    {
        auto finally7 = finally([&] {
            npc(fout)->close();
        });
        {
            fout = new ::java::io::FileOutputStream(file, true);
            auto dos = new ::java::io::DataOutputStream(fout);
            npc(dos)->writeLong(PERSISTENCE_MAGIC_NUMBER);
            npc(dos)->writeLong(PERSISTENCE_VERSION_2);
            npc(dos)->writeLong(PERSISTENCE_REVISION_2_1);
            npc(dos)->writeLong(len2 - len1);
            npc(dos)->close();
        }
    }

    return npc(file)->length();
}

void rice::persistence::PersistentStorage::writeMetadata(::java::io::File* file, ::java::io::Serializable* metadata) /* throws(IOException) */
{
    clinit();
    ::java::io::RandomAccessFile* ras = nullptr;
    ::java::io::FileOutputStream* fout = nullptr;
    if(npc(file)->length() > 32) {
        {
            auto finally8 = finally([&] {
                npc(ras)->close();
            });
            {
                ras = new ::java::io::RandomAccessFile(file, u"rw"_j);
                npc(ras)->seek(npc(file)->length() - int32_t(32));
                if((npc(ras)->readLong() == PERSISTENCE_MAGIC_NUMBER) && (npc(ras)->readLong() == PERSISTENCE_VERSION_2) && (npc(ras)->readLong() <= PERSISTENCE_REVISION_2_1)) {
                    auto length = npc(ras)->readLong();
                    npc(ras)->setLength(npc(file)->length() - int32_t(32) - length);
                }
            }
        }

    }
    auto len1 = npc(file)->length();
    {
        auto finally9 = finally([&] {
            npc(fout)->close();
        });
        {
            fout = new ::java::io::FileOutputStream(file, true);
            ::java::io::ObjectOutputStream* objout = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(fout)));
            npc(objout)->writeObject(static_cast< ::java::lang::Object* >(metadata));
            npc(objout)->close();
        }
    }

    auto len2 = npc(file)->length();
    {
        auto finally10 = finally([&] {
            npc(fout)->close();
        });
        {
            fout = new ::java::io::FileOutputStream(file, true);
            auto dos = new ::java::io::DataOutputStream(fout);
            npc(dos)->writeLong(PERSISTENCE_MAGIC_NUMBER);
            npc(dos)->writeLong(PERSISTENCE_VERSION_2);
            npc(dos)->writeLong(PERSISTENCE_REVISION_2_1);
            npc(dos)->writeLong(len2 - len1);
            npc(dos)->close();
        }
    }

}

bool rice::persistence::PersistentStorage::setRoot(::java::lang::String* dir)
{
    rootDir = dir;
    return true;
}

java::lang::String* rice::persistence::PersistentStorage::getRoot()
{
    return rootDir;
}

int64_t rice::persistence::PersistentStorage::getStorageSize()
{
    if(storageSize > 0)
        return storageSize;
    else
        return ::java::lang::Long::MAX_VALUE;
}

bool rice::persistence::PersistentStorage::setStorageSize(int64_t size)
{
    if(storageSize <= size) {
        storageSize = size;
        return true;
    } else if(size > usedSize) {
        storageSize = size;
        return true;
    } else {
        return false;
    }
}

void rice::persistence::PersistentStorage::increaseUsedSpace(int64_t i)
{
    usedSize = usedSize + i;
}

void rice::persistence::PersistentStorage::decreaseUsedSpace(int64_t i)
{
    usedSize = usedSize - i;
}

int64_t rice::persistence::PersistentStorage::getUsedSpace()
{
    return usedSize;
}

java::lang::String* rice::persistence::PersistentStorage::getName()
{
    return name;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.PersistentStorage", 34);
    return c;
}

void rice::persistence::PersistentStorage::clinit()
{
struct string_init_ {
    string_init_() {
    BACKUP_DIRECTORY_ = u"/FreePastry-Storage-Root/"_j;
    LOST_AND_FOUND_DIRECTORY_ = u"lost+found"_j;
    METADATA_FILENAME_ = u"metadata.cache"_j;
    ZERO_LENGTH_NAME_ = u"!"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* rice::persistence::PersistentStorage::getClass0()
{
    return class_();
}

