//
//  PeerProxy.h
//  bluewoki
//
//  Created by Adrian on 5/21/11.
//  Copyright 2011 akosma software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>
#import "MessageBrokerDelegate.h"
#import "PeerProxyDelegate.h"

@interface PeerProxy : NSObject <NSNetServiceDelegate,
                                 MessageBrokerDelegate>

@property (nonatomic, retain) GKSession *chatSession;
@property (nonatomic, getter = isConnected) BOOL connected;
@property (nonatomic, assign) id<PeerProxyDelegate> delegate;
@property (nonatomic, readonly) NSString *serviceName;

+ (id)proxyWithService:(NSNetService *)service;
- (id)initWithService:(NSNetService *)service;
- (void)connect;
- (void)sendVoiceCallRequest;
- (void)answerToCallFromPeerID:(NSString *)peerID;

@end