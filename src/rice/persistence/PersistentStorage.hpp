// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/persistence/Storage.hpp>

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

struct default_init_tag;

class rice::persistence::PersistentStorage
    : public virtual ::java::lang::Object
    , public virtual Storage
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::Object* statLock {  };
    int64_t statsLastWritten {  };
    int64_t statsWriteInterval {  };
    int64_t numWrites {  };
    int64_t numReads {  };
    int64_t numRenames {  };
    int64_t numDeletes {  };
    int64_t numMetadataWrites {  };

public:
    static constexpr int64_t PERSISTENCE_MAGIC_NUMBER { int64_t(8038844221LL) };
    static constexpr int64_t PERSISTENCE_VERSION_2 { int64_t(2LL) };
    static constexpr int64_t PERSISTENCE_REVISION_2_0 { int64_t(0LL) };
    static constexpr int64_t PERSISTENCE_REVISION_2_1 { int64_t(1LL) };

private:
    static ::java::lang::String* BACKUP_DIRECTORY_;
    static ::java::lang::String* LOST_AND_FOUND_DIRECTORY_;
    static ::java::lang::String* METADATA_FILENAME_;

public:
    static constexpr int32_t MAX_FILES { int32_t(256) };
    static constexpr int32_t MAX_DIRECTORIES { int32_t(32) };
    static constexpr int32_t METADATA_SYNC_TIME { int32_t(300000) };

private:
    static ::java::lang::String* ZERO_LENGTH_NAME_;
    ::rice::p2p::commonapi::IdFactory* factory {  };
    ::java::lang::String* name {  };
    ::java::io::File* rootDirectory {  };
    ::java::io::File* backupDirectory {  };
    ::java::io::File* appDirectory {  };
    ::java::io::File* lostDirectory {  };
    bool index {  };
    ::java::util::HashMap* directories {  };
    ::java::util::HashMap* prefixes {  };
    ::java::util::HashSet* dirty {  };
    ::rice::p2p::util::ReverseTreeMap* metadata {  };
    ::java::lang::String* rootDir {  };
    int64_t storageSize {  };
    int64_t usedSize {  };

public: /* package */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env) /* throws(IOException) */;
    void ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env) /* throws(IOException) */;
    void ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, bool index, ::rice::environment::Environment* env) /* throws(IOException) */;

private:
    void printStats();

public:
    virtual void setTimer(::rice::selector::Timer* timer);
    void rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c) override;
    void store(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c) override;
    void unstore(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    bool exists(::rice::p2p::commonapi::Id* id) override;
    ::java::io::Serializable* getMetadata(::rice::p2p::commonapi::Id* id) override;
    void setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* c) override;
    void getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdSet* scan() override;
    ::java::util::SortedMap* scanMetadata(::rice::p2p::commonapi::IdRange* range) override;
    ::java::util::SortedMap* scanMetadata() override;
    ::java::util::SortedMap* scanMetadataValuesHead(::java::lang::Object* value) override;
    ::java::util::SortedMap* scanMetadataValuesNull() override;
    int64_t getTotalSize() override;
    int32_t getSize() override;
    void flush(::rice::Continuation* c) override;

private:
    void init_() /* throws(IOException) */;
    void initDirectories() /* throws(IOException) */;
    void initDirectoryMap(::java::io::File* dir);
    void initFiles(::java::io::File* dir) /* throws(IOException) */;
    bool initTemporaryFile(::java::io::File* parent, ::java::lang::String* name) /* throws(IOException) */;
    void initFileMap(::java::io::File* dir) /* throws(IOException) */;
    void resolveConflict(::java::io::File* file1, ::java::io::File* file2, ::java::io::File* output) /* throws(IOException) */;
    void moveToLost(::java::io::File* file) /* throws(IOException) */;
    bool checkDirectory(::java::io::File* directory) /* throws(IOException) */;
    void pruneDirectory(::java::io::File* dir) /* throws(IOException) */;
    void reformatDirectory(::java::io::File* dir) /* throws(IOException) */;
    void reformatDirectory(::java::io::File* dir, ::java::lang::StringArray* newDirNames) /* throws(IOException) */;
    ::java::lang::StringArray* getMatchingDirectories(::java::lang::String* prefix, ::java::lang::StringArray* dirNames);
    void expandDirectory(::java::io::File* dir) /* throws(IOException) */;
    ::java::lang::StringArray* getDirectories(::java::lang::StringArray* names);
    int32_t getPrefixLength(::java::lang::StringArray* names);
    int32_t getPrefixLength(::java::lang::String* a, ::java::lang::String* b, int32_t max);
    void moveFileToCorrectDirectory(::java::io::File* parent, ::java::lang::String* name) /* throws(IOException) */;
    void flushDirectory(::java::io::File* dir) /* throws(IOException) */;
    static void createDirectory(::java::io::File* directory) /* throws(IOException) */;
    static void deleteDirectory(::java::io::File* directory) /* throws(IOException) */;
    static int64_t getFileLength(::java::io::File* file);
    static void renameFile(::java::io::File* oldFile, ::java::io::File* newFile) /* throws(IOException) */;
    static void deleteFile(::java::io::File* file) /* throws(IOException) */;
    bool isTemporaryFile(::java::lang::String* name);
    ::java::io::File* makeTemporaryFile(::rice::p2p::commonapi::Id* id) /* throws(IOException) */;
    bool isAncestor(::java::io::File* file, ::java::io::File* ancestor);
    ::java::io::File* getFile(::rice::p2p::commonapi::Id* id) /* throws(IOException) */;
    ::java::io::File* getDirectoryForId(::rice::p2p::commonapi::Id* id) /* throws(IOException) */;
    ::java::io::File* getDirectoryForName(::java::lang::String* name) /* throws(IOException) */;
    ::java::io::File* getDirectoryForName(::java::lang::String* name, ::java::io::File* dir) /* throws(IOException) */;
    ::java::lang::String* getPostfix(::rice::p2p::commonapi::Id* id, ::java::io::File* file);
    ::java::lang::String* getPrefix(::java::io::File* file);
    ::java::io::FileArray* append(::java::io::FileArray* files, ::java::io::File* file);
    int32_t numDirectoriesDir(::java::io::File* dir);
    int32_t numFilesDir(::java::io::File* dir);
    bool isFile(::java::io::File* parent, ::java::lang::String* name);
    bool isDirectory(::java::io::File* parent, ::java::lang::String* name);
    bool containsDir(::java::io::File* dir);

public: /* protected */
    virtual void writeDirty();

private:
    int64_t readMetadataFile(::java::io::File* file) /* throws(IOException) */;
    static void writeMetadataFile(::java::io::File* file, ::java::util::HashMap* map) /* throws(IOException) */;

public: /* protected */
    virtual ::rice::p2p::commonapi::IdRange* getRangeForDirectory(::java::io::File* dir);

private:
    static ::java::io::Serializable* readObject(::java::io::File* file, int32_t offset) /* throws(IOException) */;
    static ::java::io::Serializable* readData(::java::io::File* file) /* throws(IOException) */;
    ::java::io::Serializable* readMetadata(::java::io::File* file) /* throws(IOException) */;
    ::rice::p2p::commonapi::Id* readKey(::java::io::File* file);
    ::rice::p2p::commonapi::Id* readKeyFromFile(::java::io::File* file) /* throws(IOException) */;
    static int64_t readVersion(::java::io::File* file) /* throws(IOException) */;
    static int64_t writeObject(::java::io::Serializable* obj, ::java::io::Serializable* metadata, ::rice::p2p::commonapi::Id* key, int64_t version, ::java::io::File* file) /* throws(IOException) */;
    static void writeMetadata(::java::io::File* file, ::java::io::Serializable* metadata) /* throws(IOException) */;

public:
    virtual bool setRoot(::java::lang::String* dir);
    virtual ::java::lang::String* getRoot();
    virtual int64_t getStorageSize();
    virtual bool setStorageSize(int64_t size);

private:
    void increaseUsedSpace(int64_t i);
    void decreaseUsedSpace(int64_t i);
    int64_t getUsedSpace();

public:
    virtual ::java::lang::String* getName();

    // Generated
    PersistentStorage(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env);
    PersistentStorage(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, ::rice::environment::Environment* env);
    PersistentStorage(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name, ::java::lang::String* rootDir, int64_t size, bool index, ::rice::environment::Environment* env);
protected:
    PersistentStorage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::java::lang::String*& BACKUP_DIRECTORY();
    static ::java::lang::String*& LOST_AND_FOUND_DIRECTORY();
    static ::java::lang::String*& METADATA_FILENAME();
    static ::java::lang::String*& ZERO_LENGTH_NAME();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PersistentStorage_setTimer_1;
    friend class PersistentStorage_setTimer_1_run_1_1;
    friend class PersistentStorage_rename_2;
    friend class PersistentStorage_store_3;
    friend class PersistentStorage_unstore_4;
    friend class PersistentStorage_setMetadata_5;
    friend class PersistentStorage_getObject_6;
    friend class PersistentStorage_flush_7;
    friend class PersistentStorage_DirectoryFilter;
    friend class PersistentStorage_FileFilter;
    friend class PersistentStorage_CharacterHashSet;
    friend class PersistentStorage_PersistenceException;
    friend class PersistentStorage_OutofDiskSpaceException;
};
