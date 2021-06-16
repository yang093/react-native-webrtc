#import <React/RCTConvert.h>
#import <CustomWebRTC/RTCDataChannelConfiguration.h>
#import <CustomWebRTC/RTCConfiguration.h>
#import <CustomWebRTC/RTCIceServer.h>
#import <CustomWebRTC/RTCSessionDescription.h>
#import <CustomWebRTC/RTCIceCandidate.h>

@interface RCTConvert (CustomWebRTC)

+ (RTCIceCandidate *)RTCIceCandidate:(id)json;
+ (RTCSessionDescription *)RTCSessionDescription:(id)json;
+ (RTCIceServer *)RTCIceServer:(id)json;
+ (RTCDataChannelConfiguration *)RTCDataChannelConfiguration:(id)json;
+ (RTCConfiguration *)RTCConfiguration:(id)json;

@end
