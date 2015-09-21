// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySocket.java
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySocket.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayVerifier.hpp>

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

org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::ReplaySocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::ReplaySocket(::java::lang::Object* identifier, int32_t socketId, ReplayVerifier* verifier, ::java::util::Map* options) 
    : ReplaySocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,socketId,verifier,options);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::init()
{
    closed = false;
    outputShutdown = false;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::ctor(::java::lang::Object* identifier, int32_t socketId, ReplayVerifier* verifier, ::java::util::Map* options)
{
    super::ctor();
    init();
    this->identifier = identifier;
    this->socketId = socketId;
    this->verifier = verifier;
    this->options = options;
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(identifier);
}

java::util::Map* org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::getOptions()
{
    return options;
}

int64_t org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::read(::java::nio::ByteBuffer* dst) /* throws(IOException) */
{
    return npc(verifier)->readSocket(socketId, dst);
}

int64_t org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::write(::java::nio::ByteBuffer* src) /* throws(IOException) */
{
    return npc(verifier)->writeSocket(socketId, src);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(closed) {
        npc(receiver)->receiveException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u" already closed."_j)->toString()));
        return;
    }
    if(wantToWrite && outputShutdown) {
        npc(receiver)->receiveException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u" already shutdown output."_j)->toString()));
        return;
    }
    if(wantToWrite) {
        if(writer != nullptr) {
            if(writer != receiver)
                throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Already registered "_j)->append(static_cast< ::java::lang::Object* >(writer))
                    ->append(u" for writing, you can't register "_j)
                    ->append(static_cast< ::java::lang::Object* >(receiver))
                    ->append(u" for writing as well!"_j)->toString());

        }
    }
    if(wantToRead) {
        if(reader != nullptr) {
            if(reader != receiver)
                throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Already registered "_j)->append(static_cast< ::java::lang::Object* >(reader))
                    ->append(u" for reading, you can't register "_j)
                    ->append(static_cast< ::java::lang::Object* >(receiver))
                    ->append(u" for reading as well!"_j)->toString());

        }
        reader = receiver;
    }
    if(wantToWrite) {
        writer = receiver;
    }
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::notifyIO(bool canRead, bool canWrite) /* throws(IOException) */
{
    if(!canRead && !canWrite) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"I can't read or write. canRead:"_j)->append(canRead)
            ->append(u" canWrite:"_j)
            ->append(canWrite)->toString());
    }
    if(canRead && canWrite) {
        if(writer != reader)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"weader != writer canRead:"_j)->append(canRead)
                ->append(u" canWrite:"_j)
                ->append(canWrite)->toString());

        auto temp = writer;
        writer = nullptr;
        reader = nullptr;
        npc(temp)->receiveSelectResult(this, canRead, canWrite);
        return;
    }
    if(canRead) {
        if(reader == nullptr)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"reader:"_j)->append(static_cast< ::java::lang::Object* >(reader))
                ->append(u" canRead:"_j)
                ->append(canRead)->toString());

        auto temp = reader;
        reader = nullptr;
        npc(temp)->receiveSelectResult(this, canRead, canWrite);
        return;
    }
    if(canWrite) {
        if(writer == nullptr)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"writer:"_j)->append(static_cast< ::java::lang::Object* >(writer))
                ->append(u" canWrite:"_j)
                ->append(canWrite)->toString());

        auto temp = writer;
        writer = nullptr;
        npc(temp)->receiveSelectResult(this, canRead, canWrite);
        return;
    }
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::close()
{
    closed = true;
    npc(verifier)->close(socketId);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::setDeliverSocketToMe(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe)
{
    this->deliverSocketToMe = deliverSocketToMe;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::socketOpened()
{
    npc(deliverSocketToMe)->receiveResult(this, this);
    deliverSocketToMe = nullptr;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::shutdownOutput()
{
    outputShutdown = true;
    npc(verifier)->shutdownOutput(socketId);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::receiveException(::java::io::IOException* ioe)
{
    if(deliverSocketToMe != nullptr) {
        npc(deliverSocketToMe)->receiveException(this, ioe);
        return;
    }
    if(writer != nullptr) {
        if(writer == reader) {
            npc(writer)->receiveException(this, ioe);
            writer = nullptr;
            reader = nullptr;
        } else {
            npc(writer)->receiveException(this, ioe);
            writer = nullptr;
        }
    }
    if(reader != nullptr) {
        npc(reader)->receiveException(this, ioe);
        reader = nullptr;
    }
}

bool org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::cancel()
{
    throw new ::java::lang::RuntimeException(u"Not implemented."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.playback.ReplaySocket", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySocket::getClass0()
{
    return class_();
}

