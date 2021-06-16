//
//  CustomWebRTCModule+RTCPeerConnection.h
//
//  Created by one on 2015/9/24.
//  Copyright © 2015 One. All rights reserved.
//

#import "CustomWebRTCModule.h"
#import <CustomWebRTC/RTCDataChannel.h>
#import <CustomWebRTC/RTCPeerConnection.h>

@interface RTCPeerConnection (React)

@property (nonatomic, strong) NSMutableDictionary<NSNumber *, RTCDataChannel *> *dataChannels;
@property (nonatomic, strong) NSNumber *reactTag;
@property (nonatomic, strong) NSMutableDictionary<NSString *, RTCMediaStream *> *remoteStreams;
@property (nonatomic, strong) NSMutableDictionary<NSString *, RTCMediaStreamTrack *> *remoteTracks;
@property (nonatomic, weak) id webRTCModule;

@end

@interface CustomWebRTCModule (RTCPeerConnection) <RTCPeerConnectionDelegate>

@end
