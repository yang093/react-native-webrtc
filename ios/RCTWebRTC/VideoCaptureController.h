
#import <Foundation/Foundation.h>
#import <CustomWebRTC/RTCCameraVideoCapturer.h>

#import "CaptureController.h"

@interface VideoCaptureController : CaptureController

-(instancetype)initWithCapturer:(RTCCameraVideoCapturer *)capturer
                 andConstraints:(NSDictionary *)constraints;
-(void)startCapture;
-(void)stopCapture;
-(void)switchCamera;

@end
