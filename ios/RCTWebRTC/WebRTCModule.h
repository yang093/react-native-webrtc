//
//  CustomWebRTCModule.h
//
//  Created by one on 2015/9/24.
//  Copyright © 2015 One. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import <React/RCTBridgeModule.h>
#import <React/RCTConvert.h>
#import <React/RCTEventEmitter.h>

#import <CustomWebRTC/RTCMediaStream.h>
#import <CustomWebRTC/RTCPeerConnectionFactory.h>
#import <CustomWebRTC/RTCPeerConnection.h>
#import <CustomWebRTC/RTCAudioTrack.h>
#import <CustomWebRTC/RTCVideoTrack.h>
#import <CustomWebRTC/RTCVideoDecoderFactory.h>
#import <CustomWebRTC/RTCVideoEncoderFactory.h>

static NSString *const kEventPeerConnectionSignalingStateChanged = @"peerConnectionSignalingStateChanged";
static NSString *const kEventPeerConnectionStateChanged = @"peerConnectionStateChanged";
static NSString *const kEventPeerConnectionAddedStream = @"peerConnectionAddedStream";
static NSString *const kEventPeerConnectionRemovedStream = @"peerConnectionRemovedStream";
static NSString *const kEventPeerConnectionOnRenegotiationNeeded = @"peerConnectionOnRenegotiationNeeded";
static NSString *const kEventPeerConnectionIceConnectionChanged = @"peerConnectionIceConnectionChanged";
static NSString *const kEventPeerConnectionIceGatheringChanged = @"peerConnectionIceGatheringChanged";
static NSString *const kEventPeerConnectionGotICECandidate = @"peerConnectionGotICECandidate";
static NSString *const kEventPeerConnectionDidOpenDataChannel = @"peerConnectionDidOpenDataChannel";
static NSString *const kEventDataChannelStateChanged = @"dataChannelStateChanged";
static NSString *const kEventDataChannelReceiveMessage = @"dataChannelReceiveMessage";
static NSString *const kEventMediaStreamTrackMuteChanged = @"mediaStreamTrackMuteChanged";

@interface CustomWebRTCModule : RCTEventEmitter <RCTBridgeModule>

@property(nonatomic, strong) dispatch_queue_t workerQueue;

@property (nonatomic, strong) RTCPeerConnectionFactory *peerConnectionFactory;

@property (nonatomic, strong) NSMutableDictionary<NSNumber *, RTCPeerConnection *> *peerConnections;
@property (nonatomic, strong) NSMutableDictionary<NSString *, RTCMediaStream *> *localStreams;
@property (nonatomic, strong) NSMutableDictionary<NSString *, RTCMediaStreamTrack *> *localTracks;

- (instancetype)initWithEncoderFactory:(id<RTCVideoEncoderFactory>)encoderFactory
                        decoderFactory:(id<RTCVideoDecoderFactory>)decoderFactory;

- (RTCMediaStream*)streamForReactTag:(NSString*)reactTag;

@end
