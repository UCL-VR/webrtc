/*
 *  Copyright 2019 pixiv Inc. All Rights Reserved.
 *
 *  Use of this source code is governed by a license that can be
 *  found in the LICENSE.pixiv file in the root of the source tree.
 */

#ifndef SDK_C_API_VIDEO_BUFFER_H_
#define SDK_C_API_VIDEO_BUFFER_H_

#include "sdk/c/api/video/video_frame.h"
#include "sdk/c/api/video/video_sink_interface.h"

#ifdef __cplusplus
#include "api/video/video_frame.h"
#include "api/video/video_sink_interface.h"
#include "rtc_base/system/rtc_export.h"

namespace webrtc {

class RTC_EXPORT VideoBufferInterface :
    public rtc::VideoSinkInterface<VideoFrame> {
  public:
    virtual std::unique_ptr<VideoFrame> MoveFrame() = 0;
};

RTC_EXPORT std::unique_ptr<VideoBufferInterface> CreateVideoBuffer();

}

extern "C" {
#endif

RTC_C_CLASS(webrtc::VideoBufferInterface, WebrtcVideoBufferInterface)

RTC_EXPORT WebrtcVideoBufferInterface* webrtcCreateVideoBuffer(void);

RTC_EXPORT WebrtcVideoFrame* webrtcVideoBufferInterfaceMoveFrame(
    WebrtcVideoBufferInterface* buffer);

RTC_EXPORT RtcVideoSinkInterface*
webrtcVideoBufferInterfaceToRtcVideoSinkInterface(
    WebrtcVideoBufferInterface* buffer);

#ifdef __cplusplus
}
#endif

#endif
