//
//  QuartoBoardViewCell.h
//  QuartoAI
//
//  Created by Aung Moe on 8/25/16.
//  Copyright © 2016 Aung Moe. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface QuartoBoardViewCell : UIView

// Initialize using this. Size is determined by the super.
- (instancetype)init;

// Returns YES if a board piece is put. NO if there's already a board piece.
- (BOOL)canPutBoardPiece:(UIView *)boardPiece;

@end
