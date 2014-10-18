//
//  FPDialogController.h
//  FPPicker
//
//  Created by Ruben Nine on 17/10/14.
//  Copyright (c) 2014 Filepicker.io. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class FPBaseSourceController;
@class FPRepresentedSource;
@class FPDialogController;

@protocol FPDialogControllerDelegate <NSObject>

- (void)dialogControllerPressedCancelButton:(FPDialogController *)dialogController;
- (void)dialogControllerPressedActionButton:(FPDialogController *)dialogController;

@optional

- (void)dialogControllerDidLoadWindow:(FPDialogController *)dialogController;

@end

@interface FPDialogController : NSWindowController

@property (nonatomic, weak) id <FPDialogControllerDelegate> delegate;

- (void)open;
- (void)close;

- (void)setupSourceListWithSourceNames:(NSArray *)sourceNames
                          andDataTypes:(NSArray *)dataTypes;

- (void)cancelAllOperations;
- (void)setupDialogForSavingWithDefaultFileName:(NSString *)filename;

- (NSString *)filenameFromSaveTextField;
- (NSString *)currentPath;
- (NSArray *)selectedItems;
- (FPBaseSourceController *)selectedSourceController;

@end
