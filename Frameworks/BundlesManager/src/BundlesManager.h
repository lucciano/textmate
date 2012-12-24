#import <updater/updater.h>

extern PUBLIC NSString* const BundlesManagerBundlesDidChangeNotification;

PUBLIC @interface BundlesManager : NSObject
@property (nonatomic, readonly)         BOOL      isBusy;
@property (nonatomic, retain, readonly) NSString* activityText;
@property (nonatomic, readonly)         double    progress;

- (NSUInteger)numberOfBundles;
- (bundles_db::bundle_ptr const&)bundleAtIndex:(NSUInteger)anIndex;
- (NSCellStateValue)installStateForBundle:(bundles_db::bundle_ptr const&)aBundle;

- (void)installBundle:(bundles_db::bundle_ptr const&)aBundle;
- (void)uninstallBundle:(bundles_db::bundle_ptr const&)aBundle;

- (void)updateSources:(id)sender;
- (void)updateBundles:(id)sender;

+ (BundlesManager*)sharedInstance;
@end

