// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewConstants.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/StatusConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::PeerReviewConstants
    : public virtual StatusConstants
{
    static constexpr int16_t EVT_SEND { int16_t(0) };
    static constexpr int16_t EVT_RECV { int16_t(1) };
    static constexpr int16_t EVT_SIGN { int16_t(2) };
    static constexpr int16_t EVT_ACK { int16_t(3) };
    static constexpr int16_t EVT_CHECKPOINT { int16_t(4) };
    static constexpr int16_t EVT_INIT { int16_t(5) };
    static constexpr int16_t EVT_SENDSIGN { int16_t(6) };
    static constexpr int16_t EVT_VRF { int16_t(7) };
    static constexpr int16_t EVT_CHOOSE_Q { int16_t(8) };
    static constexpr int16_t EVT_CHOOSE_RAND { int16_t(9) };
    static constexpr int16_t EVT_MAX_RESERVED { int16_t(9) };
    static constexpr int16_t EVT_SOCKET_OPEN_INCOMING { int16_t(30) };
    static constexpr int16_t EVT_SOCKET_OPEN_OUTGOING { int16_t(31) };
    static constexpr int16_t EVT_SOCKET_OPENED_OUTGOING { int16_t(32) };
    static constexpr int16_t EVT_SOCKET_EXCEPTION { int16_t(33) };
    static constexpr int16_t EVT_SOCKET_CLOSE { int16_t(34) };
    static constexpr int16_t EVT_SOCKET_SHUTDOWN_OUTPUT { int16_t(35) };
    static constexpr int16_t EVT_SOCKET_CLOSED { int16_t(36) };
    static constexpr int16_t EVT_SOCKET_CAN_READ { int16_t(37) };
    static constexpr int16_t EVT_SOCKET_CAN_WRITE { int16_t(38) };
    static constexpr int16_t EVT_SOCKET_CAN_RW { int16_t(39) };
    static constexpr int16_t EVT_SOCKET_READ { int16_t(40) };
    static constexpr int16_t EVT_SOCKET_WRITE { int16_t(41) };
    static constexpr int16_t EVT_MIN_SOCKET_EVT { int16_t(30) };
    static constexpr int16_t EVT_MAX_SOCKET_EVT { int16_t(35) };
    static constexpr int16_t EX_TYPE_IO { int16_t(1) };
    static constexpr int16_t EX_TYPE_ClosedChannel { int16_t(2) };
    static constexpr int16_t EX_TYPE_Unknown { int16_t(0) };
    static constexpr int16_t MSG_USERDATA { int16_t(16) };
    static constexpr int16_t MSG_ACK { int16_t(17) };
    static constexpr int16_t MSG_ACCUSATION { int16_t(18) };
    static constexpr int16_t MSG_CHALLENGE { int16_t(19) };
    static constexpr int16_t MSG_RESPONSE { int16_t(20) };
    static constexpr int16_t MSG_AUTHPUSH { int16_t(21) };
    static constexpr int16_t MSG_AUTHREQ { int16_t(22) };
    static constexpr int16_t MSG_AUTHRESP { int16_t(23) };
    static constexpr int16_t MSG_USERDGRAM { int16_t(24) };
    static constexpr int8_t CHAL_AUDIT { int8_t(1) };
    static constexpr int8_t CHAL_SEND { int8_t(2) };
    static constexpr int8_t RESP_SEND { int8_t(2) };
    static constexpr int8_t RESP_AUDIT { int8_t(1) };
    static constexpr int8_t PROOF_INCONSISTENT { int8_t(3) };
    static constexpr int8_t PROOF_NONCONFORMANT { int8_t(4) };
    static constexpr int64_t DEFAULT_AUTH_PUSH_INTERVAL_MILLIS { int64_t(5000LL) };
    static constexpr int64_t DEFAULT_CHECKPOINT_INTERVAL_MILLIS { int64_t(10000LL) };
    static constexpr int64_t MAINTENANCE_INTERVAL_MILLIS { int64_t(10000LL) };
    static constexpr int64_t DEFAULT_TIME_TOLERANCE_MILLIS { int64_t(60000LL) };
    static constexpr int32_t TI_CHECKPOINT { int32_t(99) };
    static constexpr int32_t TI_MAINTENANCE { int32_t(6) };
    static constexpr int32_t TI_AUTH_PUSH { int32_t(7) };
    static constexpr int32_t TI_MAX_RESERVED { int32_t(7) };
    static constexpr int32_t TI_STATUS_INFO { int32_t(101) };
    static constexpr int32_t MAX_STATUS_INFO { int32_t(100) };
    static constexpr int8_t FLAG_INCLUDE_CHECKPOINT { int8_t(1) };
    static constexpr int8_t FLAG_FULL_MESSAGES_SENDER { int8_t(2) };
    static constexpr int8_t FLAG_FULL_MESSAGES_ALL { int8_t(4) };
    static constexpr int32_t VALID { int32_t(1) };
    static constexpr int32_t INVALID { int32_t(2) };
    static constexpr int32_t CERT_MISSING { int32_t(3) };
    static constexpr int64_t DEFAULT_AUDIT_INTERVAL_MILLIS { int64_t(10000LL) };
    static constexpr int32_t PROGRESS_INTERVAL_MILLIS { int32_t(100) };
    static constexpr int32_t INVESTIGATION_INTERVAL_MILLIS { int32_t(250) };
    static constexpr int32_t DEFAULT_LOG_DOWNLOAD_TIMEOUT { int32_t(2000) };
    static constexpr int32_t MAX_WITNESSED_NODES { int32_t(110) };
    static constexpr int32_t MAX_ACTIVE_AUDITS { int32_t(500) };
    static constexpr int32_t MAX_ACTIVE_INVESTIGATIONS { int32_t(10) };
    static constexpr int32_t MAX_ENTRIES_BETWEEN_CHECKPOINTS { int32_t(100) };
    static constexpr int32_t AUTH_CACHE_INTERVAL { int32_t(500000) };
    static constexpr int32_t TI_START_AUDITS { int32_t(3) };
    static constexpr int32_t TI_MAKE_PROGRESS { int32_t(4) };
    static constexpr int32_t STATE_SEND_AUDIT { int32_t(1) };
    static constexpr int32_t STATE_WAIT_FOR_LOG { int32_t(2) };
    static constexpr int32_t NO_CERTIFICATE { int32_t(-1) };
    static constexpr int32_t SIGNATURE_BAD { int32_t(0) };
    static constexpr int32_t SIGNATURE_OK { int32_t(1) };

    // Generated
    static ::java::lang::Class *class_();
};
