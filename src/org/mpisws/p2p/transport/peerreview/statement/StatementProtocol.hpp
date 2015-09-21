// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/statement/StatementProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::statement::StatementProtocol
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    static constexpr int32_t MAX_INCOMPLETE_STATEMENTS { int32_t(250) };
    static constexpr int32_t PROGRESS_INTERVAL_MICROS { int32_t(1000000) };
    static constexpr int32_t STATEMENT_COMPLETION_TIMEOUT_MILLIS { int32_t(1000) };
    static constexpr int32_t TI_MAKE_PROGRESS { int32_t(5) };
    virtual void handleIncomingStatement(::java::lang::Object* source, Statement* statement, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
