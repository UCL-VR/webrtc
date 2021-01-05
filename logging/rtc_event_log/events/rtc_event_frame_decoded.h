/*
 *  Copyright (c) 2019 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef LOGGING_RTC_EVENT_LOG_EVENTS_RTC_EVENT_FRAME_DECODED_H_
#define LOGGING_RTC_EVENT_LOG_EVENTS_RTC_EVENT_FRAME_DECODED_H_

#include <stdint.h>

#include <memory>

#include "api/rtc_event_log/rtc_event.h"
#include "api/video/video_codec_type.h"

namespace webrtc {

class RtcEventFrameDecoded final : public RtcEvent {
 public:
  static constexpr Type kType = Type::FrameDecoded;

  RtcEventFrameDecoded(int64_t render_time_ms,
                       uint32_t ssrc,
                       int width,
                       int height,
                       VideoCodecType codec,
                       uint8_t qp);
  ~RtcEventFrameDecoded() override = default;

  Type GetType() const override { return kType; }
  bool IsConfigEvent() const override { return false; }

  std::unique_ptr<RtcEventFrameDecoded> Copy() const;

  int64_t render_time_ms() const { return render_time_ms_; }
  uint32_t ssrc() const { return ssrc_; }
  int width() const { return width_; }
  int height() const { return height_; }
  VideoCodecType codec() const { return codec_; }
  uint8_t qp() const { return qp_; }

 private:
  RtcEventFrameDecoded(const RtcEventFrameDecoded& other);

  const int64_t render_time_ms_;
  const uint32_t ssrc_;
  const int width_;
  const int height_;
  const VideoCodecType codec_;
  const uint8_t qp_;
};

}  // namespace webrtc

#endif  // LOGGING_RTC_EVENT_LOG_EVENTS_RTC_EVENT_FRAME_DECODED_H_
