//
//  Document.h
//  SKS4
//
//  Created by Ethan Laur on 8/28/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#ifndef document_h
#define document_h
#include "engine/engine.h"

_environment_data env;
intelligence *intel;

@interface Document : NSDocument
@property (assign) IBOutlet NSTextField *display;
@property (assign) IBOutlet NSTextFieldCell *displaytext;

- (IBAction)upaction:(id)sender;
@property (assign) IBOutlet NSButtonCell *upbutton;

- (IBAction)leftaction:(id)sender;
@property (assign) IBOutlet NSButtonCell *leftbutton;

- (IBAction)rightaction:(id)sender;
@property (assign) IBOutlet NSButtonCell *rightbutton;

- (IBAction)downaction:(id)sender;
@property (assign) IBOutlet NSButtonCell *downbutton;

- (IBAction)startaction:(id)sender;
@property (assign) IBOutlet NSButtonCell *startbutton;

@property (assign) IBOutlet NSProgressIndicator *timerbar;

- (IBAction)saveaction:(id)sender;
- (IBAction)restoreaction:(id)sender;

@property (assign) IBOutlet NSButton *savebutton;
@property (assign) IBOutlet NSButton *restorebutton;

@property (assign) IBOutlet NSProgressIndicator *hudkillbar;
@property (assign) IBOutlet NSProgressIndicator *hudhealthbar;

@property (assign) IBOutlet NSButtonCell *attackbool;

@end
#endif
