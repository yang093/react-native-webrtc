#import "CustomWebRTCModule.h"
#import <CustomWebRTC/RTCDataChannel.h>

@interface RTCDataChannel (React)

@property (nonatomic, strong) NSNumber *peerConnectionId;
@property (nonatomic, strong) NSNumber *originDataChannelId;

@end

@interface CustomWebRTCModule (RTCDataChannel) <RTCDataChannelDelegate>

@end
