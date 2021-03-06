//
//  MenuView.h
//  SelectView
//
//  Created by Yuan on 16/7/3.
//  Copyright (c) 2016年 Yuan. All rights reserved.
//

#import <UIKit/UIKit.h>

#define collectionCellIdentifier   @"MenuViewCellIdentifier"    // cell Identifier

// MenuView 显示类型
typedef NS_ENUM(NSInteger, MenuViewStyle) {
    MenuViewStyleSingleRank = 0, // 单列显示
    MenuViewStyleMoreRank,       // 多列显示
};

// MenuView 箭头位置
typedef NS_ENUM(NSInteger, ArrowDirection) {
    ArrowDirectionDefault = 0,  // 无箭头
    ArrowDirectionLeft,
    ArrowDirectionRight,
    ArrowDirectionMiddle
};
@class MenuView;

#pragma mark - MenuViewDataSource

@protocol MenuViewDataSource <NSObject>

@required

- (NSInteger)numberOfRowsForMenuView:(MenuView *)menuView;
- (NSArray *)dataForMenuView:(MenuView *)menuView;

@optional

- (CGFloat)menuView:(MenuView *)menuView heightForRowAtIndexPath:(NSIndexPath *)indexPath;
- (CGSize)menuView:(MenuView *)menuView imageSizeForRowAtIndexPath:(NSIndexPath *)indexPath;

/*!
 *  选中后的cell 显示样式
 *
 *  @return UIImage/UIColor
 */
- (id)menuView:(MenuView *)menuView selectStyleForRowAtIndexPath:(NSIndexPath *)indexPath;

/*!
 *  自定义cell
 *  必须注册 cell 的 Identifier 为 collectionCellIdentifier
 */
- (UICollectionViewCell *)contentCellWithCollectionView:(UICollectionView *)collectionView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

@end

#pragma mark - MenuViewDelegate
@protocol MenuViewDelegate <NSObject>

@optional

- (void)menuView:(MenuView *)menuView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (UIEdgeInsets)menuView:(MenuView *)menuView imageEdgeInsetsAtIndexPath:(NSIndexPath *)indexPath;
- (UIEdgeInsets)menuView:(MenuView *)menuView titleEdgeInsetsAtIndexPath:(NSIndexPath *)indexPath;

@end


@interface MenuView : UIView

@property(nonatomic,assign) id<MenuViewDelegate> delegate;          // weak reference
@property(nonatomic,assign) id<MenuViewDataSource> dataSource;       // weak reference

/*!
 *  填充颜色
 *  默认 白色
 */
@property(nonatomic,strong) UIColor *fillColor;

/*!
 *  箭头方向
 *  默认 ArrowDirectionDefault
 */
@property(nonatomic,assign) ArrowDirection arrowDirection;

/**
 *  选中哪行
 *  默认 无选中
 */
@property (nonatomic, assign) NSIndexPath *selectedIndex;

// MenuViewStyle -style defaults to MenuViewStyleSingleRank
@property(nonatomic,assign) MenuViewStyle menuStyle;


// shows popup menu animated.
- (void)show;
- (void)showInView:(UIView *)view;
@end




