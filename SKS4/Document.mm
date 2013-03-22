//
//  Document.m
//  SKS4
//
//  Created by Ethan Laur on 8/28/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#import "Document.h"

@implementation Document
@synthesize savebutton;
@synthesize restorebutton;
@synthesize hudkillbar;
@synthesize hudhealthbar;
@synthesize attackbool;
@synthesize startbutton;
@synthesize timerbar;
@synthesize leftbutton;
@synthesize rightbutton;
@synthesize downbutton;
@synthesize upbutton;
@synthesize displaytext;
@synthesize display;

- (id)init
{
    self = [super init];
    if (self) {
        intel = new intelligence;
        [NSThread detachNewThreadSelector:@selector(showmap) toTarget:self withObject:nil];
        [NSThread detachNewThreadSelector:@selector(setbuttonstate) toTarget:self withObject:nil];
        environment_init(env);
        [hudkillbar setMaxValue: env.kills_needed];
    }
    return self;
}

- (NSString *)windowNibName
{
    // Override returning the nib file name of the document
    // If you need to use a subclass of NSWindowController or if your document supports multiple NSWindowControllers, you should remove this method and override -makeWindowControllers instead.
    return @"Document";
}

- (void)windowControllerDidLoadNib:(NSWindowController *)aController
{
    [super windowControllerDidLoadNib:aController];
    // Add any code here that needs to be executed once the windowController has loaded the document's window.
}

+ (BOOL)autosavesInPlace
{
    return YES;
}

- (NSData *)dataOfType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to write your document to data of the specified type. If outError != NULL, ensure that you create and set an appropriate error when returning nil.
    // You can also choose to override -fileWrapperOfType:error:, -writeToURL:ofType:error:, or -writeToURL:ofType:forSaveOperation:originalContentsURL:error: instead.
    NSException *exception = [NSException exceptionWithName:@"UnimplementedMethod" reason:[NSString stringWithFormat:@"%@ is unimplemented", NSStringFromSelector(_cmd)] userInfo:nil];
    @throw exception;
    return nil;
}

- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to read your document from the given data of the specified type. If outError != NULL, ensure that you create and set an appropriate error when returning NO.
    // You can also choose to override -readFromFileWrapper:ofType:error: or -readFromURL:ofType:error: instead.
    // If you override either of these, you should also override -isEntireFileLoaded to return NO if the contents are lazily loaded.
    NSException *exception = [NSException exceptionWithName:@"UnimplementedMethod" reason:[NSString stringWithFormat:@"%@ is unimplemented", NSStringFromSelector(_cmd)] userInfo:nil];
    @throw exception;
    return YES;
}

bool mapthread_started = false;

- (void)showmap
{
    sleep(1);
    while (true)
    {
        [hudkillbar setMaxValue: env.kills_needed];
        [hudkillbar setDoubleValue: env.userdata.kills];
        [hudhealthbar setMaxValue: 100];
        [hudhealthbar setDoubleValue: env.userdata.health];
        if (env.needs_display && env.allow_refresh)
        {
            NSString *displaystring = [[NSString alloc] initWithCString:(const char *)env.map length:mapsize];
            //NSLog(displaystring);
            displaytext.stringValue = displaystring;
            cout << env.location << endl;
            env.needs_display = false;
        }
    }
}

- (void)endgame
{
    intel->stop();
    [startbutton setEnabled:NO];
    [hudkillbar stopAnimation: self];
    [hudhealthbar stopAnimation: self];
    env.game_over = true;
    env.buttonstate.up = false;
    env.buttonstate.down = false;
    env.buttonstate.left = false;
    env.buttonstate.right = false;
    env.buttonstate.save = false;
    env.buttonstate.restore = false;
    env.allow_refresh = false;
    env.userdata.score += env.userdata.health + env.time;
    ostringstream text;
    if (env.userdata.health <= 0)
    {
        text << "You are dead..\n";
    }
    else
    {
        text << "Game over..\n";
    }
    text << "Score: ";
    text << env.userdata.score;
    text << " Kills: ";
    text << env.userdata.totalkills;
    text << "\0";
    [displaytext setStringValue: [[NSString alloc] initWithCString:text.str().c_str()]];
}

- (void)timer
{
    [timerbar startAnimation: self];
    [timerbar setMaxValue: time_max];
    [timerbar setDoubleValue: env.time];
    while (timerbar.doubleValue > 0)
    {
        if (env.userdata.health <= 0)
            [self endgame];
        if (env.kills_needed == env.userdata.kills)
        {
            env.location = 0;
            env.userdata.kills = 0;
            nextlevel();
            env.needs_display = true;
        }
        sleep(1);
        [timerbar incrementBy: -1.0];
        env.time = [timerbar doubleValue];
        if ((int)env.time % 15 == 0)
        {
            if (env.userdata.health < 90)
                env.userdata.health += 10;
        }
    }
    [timerbar stopAnimation: self];
    [self endgame];
}

void move(int location)
{
    if (location > 0 && env.map[location] == ' ')
    {
        if (env.map[location] == ' ');
        {
            //cout << env.map[location] << endl;
            env.map[env.location] = ' ';
            env.location = location;
            env.map[env.location] = '@';
            env.needs_display = true;
        }
    }
}

- (IBAction)upaction:(id)sender
{
    int location = env.location - (width + 1);
    if (env.location > width && env.location < width * 2 + 4)
    {
        location = env.location - (width + 3);
    }
    if (attackbool.state)
    {
        attack(location);
        [attackbool setState: NO];
    }
    else
        move(location);
}

- (IBAction)leftaction:(id)sender
{
    int location = env.location - 1;
    if (attackbool.state)
    {
        attack(location);
        [attackbool setState: NO];
    }
    else
        move(location);
}

- (IBAction)rightaction:(id)sender
{
    int location = env.location + 1;
    if (attackbool.state)
    {
        attack(location);
        [attackbool setState: NO];
    }
    else
        move(location);
}

- (IBAction)downaction:(id)sender
{
    int location = env.location + width + 1;
    if (env.location >= 0 && env.location < width + 4)
    {
        location = env.location + width + 3;
    }
    if (attackbool.state)
    {
        attack(location);
        [attackbool setState: NO];
    }
    else
        move(location);
}

- (void) setbuttonstate
{
    while (true)
    {
        [upbutton setEnabled:env.buttonstate.up];
        [leftbutton setEnabled:env.buttonstate.left];
        [downbutton setEnabled:env.buttonstate.down];
        [rightbutton setEnabled:env.buttonstate.right];
        [savebutton setEnabled:env.buttonstate.save];
        [restorebutton setEnabled:env.buttonstate.restore];
        [attackbool setEnabled:env.buttonstate.attack];
    }
}

- (IBAction)startaction:(id)sender
{
    if (env.game_over)
    {
        env.game_over = false;
        environment_init(env);
    }
    env.needs_display = true;
    [startbutton setEnabled:NO];
    env.buttonstate.up = true;
    env.buttonstate.down = true;
    env.buttonstate.left = true;
    env.buttonstate.right = true;
    env.buttonstate.save = true;
    env.buttonstate.restore = true;
    env.buttonstate.attack = true;
    [NSThread detachNewThreadSelector:@selector(timer) toTarget:self withObject:nil];
    [hudkillbar startAnimation: self];
    [hudhealthbar startAnimation: self];
    intel->Run();
}
- (IBAction)saveaction:(id)sender
{
    save(env);
}

- (IBAction)restoreaction:(id)sender
{
    restore(env);
    env.needs_display = true;
    [timerbar setDoubleValue: env.time];
}
@end
