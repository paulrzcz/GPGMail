/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import <Message/RemoteStoreAccount.h>

@class IMAPConnectionPool, IMAPOperationCache, LibraryIMAPStore, NSArray, NSDictionary, NSLock, NSMutableArray, NSMutableDictionary, NSMutableSet, NSOperationQueue, NSString;

@interface IMAPAccount : RemoteStoreAccount
{
    double _lastUnreadCountsUpdateTime;
    double _lastUnreadCountsAndNewMessagesUpdateTime;
    double _lastMailboxListFetchTime;
    NSArray *_lastKnownCapabilities;
    NSMutableArray *_namespacePrefixes;
    NSString *_separatorChar;
    IMAPConnectionPool *_connectionPool;
    NSLock *_connectionPoolLock;
    IMAPOperationCache *_offlineCache;
    NSString *_serverPathPrefixWithFilesystemSeparator;
    NSString *_serverPathPrefixAsFilesystemPath;
    NSLock *_fsPrefixLock;
    NSLock *_mailboxListingLock;
    NSMutableSet *_mailboxURLsToSynchronize;
    NSMutableDictionary *_statusFlagCheckInfo;
    NSMutableDictionary *_IMAPMailboxes;
    NSMutableDictionary *_IMAPQuotaRoots;
    LibraryIMAPStore *_inboxStore;
    NSOperationQueue *_imapQueue;
    unsigned int _readBufferSize;
    BOOL _lastConnectionFailed;
    BOOL _shouldIncludePrefixInPath;
    BOOL _allowsInputForConnectionProblems;
    BOOL _isFetchingUnreadCountsForAllMailboxes;
    BOOL _isFetchingUnreadCountsAndCheckingNewMessagesForAllMailboxes;
    BOOL _recoveringFromConnectionLoss;
}

+ (void)initialize;
+ (id)accountTypeString;
+ (void)_deleteQueuedMailboxes:(id)arg1;
- (id)initWithAccountInfo:(id)arg1;
- (void)dealloc;
- (void)completeDeferredInitialization;
- (void)_readCustomInfoFromMailboxCache:(id)arg1;
- (void)_writeCustomInfoToMailboxCache:(id)arg1;
- (void)saveCache;
- (void)updateFromSyncedDictionary:(id)arg1;
- (void)doRoutineCleanup;
- (BOOL)isSyncable;
- (Class)storeClass;
- (id)mailboxPathExtension;
- (unsigned int)defaultPortNumber;
- (unsigned int)defaultSecurePortNumber;
- (id)serviceName;
- (id)secureServiceName;
- (id)saslProfileName;
- (BOOL)requiresAuthentication;
- (Class)connectionClass;
- (id)authenticatedConnection;
- (BOOL)compactWhenClosingMailboxes;
- (void)setCompactWhenClosingMailboxes:(BOOL)arg1;
- (BOOL)useIDLEIfAvailable;
- (void)setUseIDLEIfAvailable:(BOOL)arg1;
- (BOOL)_setChildren:(id)arg1 forMailboxUid:(id)arg2;
- (id)primaryMailboxUid;
- (id)iaServiceType;
- (BOOL)handleResponseCodeFromResponse:(id)arg1;
- (void)_handleAlertResponse:(id)arg1;
- (unsigned int)readBufferSize;
- (void)setReadBufferSize:(unsigned int)arg1;
- (void)synchronizeAllMailboxes;
- (BOOL)needToSynchronizeMailboxCaches;
- (void)didSynchronizeMailboxCachesAndFoundChanges:(BOOL)arg1;
- (void)_checkForNewMessagesInStore:(id)arg1;
- (id)_dataForTemporaryUid:(unsigned int)arg1;
- (unsigned long long)minimumPartialDownloadSize;
- (BOOL)allowsPartialDownloads;
- (void)setAllowsPartialDownloads:(BOOL)arg1;
- (void)_clearAllPathBasedCachesAndDelete:(BOOL)arg1;
@property long long gmailCapabilitiesSupport;
@property(copy) NSDictionary *serverID;
- (BOOL)_connectAndAuthenticate:(id)arg1;
- (void)handleOpenMailboxError:(id)arg1;
- (id)gatewayForStore:(id)arg1 options:(int)arg2;
- (id)gatewayForExistingConnectionToMailbox:(id)arg1;
- (void)recoverFromConnectionLoss;
- (void)invalidateMailboxWithName:(id)arg1 expunge:(BOOL)arg2 URLToCompact:(id)arg3;
- (void)_invalidateMailboxWithName:(id)arg1 expunge:(BOOL)arg2 URLToCompact:(id)arg3;
- (id)_gatewayForMailboxUid:(id)arg1 name:(id)arg2 options:(int)arg3;
- (id)_getPotentialGatewayForMailbox:(id)arg1 options:(int)arg2 createdNewConnection:(char *)arg3 needsSelect:(char *)arg4;
- (BOOL)_shouldRetryConnectionWithoutCertificateCheckingAfterError:(id)arg1;
- (BOOL)_recoverFromConnectionlessState;
- (void)_releaseAllConnectionsAndCallSuper:(BOOL)arg1 saveOfflineCache:(BOOL)arg2;
- (void)releaseAllConnections;
- (void)_validateConnections;
- (void)validateConnections;
- (void)filterMailboxList:(id)arg1 forMailbox:(id)arg2 options:(int)arg3;
- (void)_setHadUnreadCountMismatchForURL:(id)arg1;
- (long long)nextFlagCheckAllowedForMailboxUid:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)IMAPMailboxForMailboxUid:(id)arg1 createIfNeeded:(BOOL)arg2;
- (id)IMAPMailboxForMailboxName:(id)arg1 createIfNeeded:(BOOL)arg2;
- (id)_IMAPMailboxForMailboxUid:(id)arg1 name:(id)arg2 createIfNeeded:(BOOL)arg3;
- (id)_addIMAPMailboxForMailboxUid:(id)arg1 name:(id)arg2;
- (void)_renameIMAPMailboxWithMailboxUid:(id)arg1 fromName:(id)arg2 toName:(id)arg3;
- (void)_removeIMAPMailboxWithName:(id)arg1;
- (void)_startObserving:(BOOL)arg1 IMAPMailbox:(id)arg2;
- (id)quotaRootForName:(id)arg1 createIfNeeded:(BOOL)arg2;
- (void)clearQuotaRoots;
- (void)_setIsOffline:(BOOL)arg1;
- (void)setIsOffline:(BOOL)arg1;
- (void)_asynchronouslyFetchUnreadCountsCheckForNewMessages:(BOOL)arg1;
- (void)fetchSynchronouslyIsAuto:(id)arg1;
- (void)_setSeparatorChar:(id)arg1;
- (id)separatorChar;
- (id)lastKnownCapabilities;
- (BOOL)supportsIDLE;
- (id)additionalHeaderFields;
- (BOOL)_synchronizeMailboxListWithUserInput:(BOOL)arg1;
- (void)_synchronizeMailboxListDuringMailCheck;
- (id)_listingForMailboxUid:(id)arg1 listAllChildren:(BOOL)arg2 onlySubscribed:(BOOL)arg3 withUserInput:(BOOL)arg4;
- (id)_namespacePrefixesForPrivate:(BOOL)arg1 public:(BOOL)arg2 shared:(BOOL)arg3;
- (id)_recursivelyFilterMailboxList:(id)arg1 accordingToList:(id)arg2;
- (id)_listingForMailboxUid:(id)arg1 listAllChildren:(BOOL)arg2 withUserInput:(BOOL)arg3;
- (BOOL)_createMailbox:(id)arg1 withGateway:(id)arg2;
- (id)createMailboxWithParent:(id)arg1 name:(id)arg2 displayName:(id)arg3;
- (id)validNameForMailbox:(id)arg1 fromDisplayName:(id)arg2 error:(id *)arg3;
- (BOOL)_askToChangePathPrefixToCreateMailbox:(id)arg1 displayName:(id)arg2 withGateway:(id)arg3;
- (BOOL)_deleteMailbox:(id)arg1 reflectToServer:(BOOL)arg2;
- (id)_specialMailboxNameForType:(int)arg1;
- (id)_specialMailboxUidWithType:(int)arg1 create:(BOOL)arg2 isLocal:(BOOL)arg3;
- (void)_fetchUnreadCountsForMailboxUid:(id)arg1 recursively:(BOOL)arg2 gateway:(id)arg3 checkForNewMessages:(BOOL)arg4;
- (void)_fetchUnreadCountsForMailboxUid:(id)arg1 recursively:(BOOL)arg2 gateway:(id)arg3;
- (void)_fetchUnreadCountsCheckForNewMessages:(BOOL)arg1;
- (void)_synchronizeAccountWithServerWithUserInput:(id)arg1;
- (id)_copyMailboxUidWithParent:(id)arg1 name:(id)arg2 pathComponent:(id)arg3 attributes:(unsigned long long)arg4 existingMailboxUid:(id)arg5;
- (void)_synchronouslyLoadListingForParent:(id)arg1;
- (void)refreshMailboxListingRootedAtUid:(id)arg1;
- (void)_waitForMailboxListingLoadToComplete;
- (void)_mailboxesWereRemovedFromTree:(id)arg1 withFileSystemPaths:(id)arg2;
- (void)_recursivelyModifySubscriptions:(BOOL)arg1 forMailbox:(id)arg2 children:(id)arg3 withGateway:(id)arg4;
- (BOOL)renameMailbox:(id)arg1 newName:(id)arg2 parent:(id)arg3;
- (void)insertInMailboxes:(id)arg1 atIndex:(unsigned long long)arg2;
- (id)_pathComponentForUidName:(id)arg1;
- (id)_uidNameForPathComponent:(id)arg1;
- (id)_pathForMailboxName:(id)arg1 toCreateInMailboxUid:(id)arg2;
- (id)_nameForMailboxUid:(id)arg1;
- (id)nameForMailboxUid:(id)arg1;
- (id)_mailboxUidForName:(id)arg1;
- (BOOL)canMailboxBeDeleted:(id)arg1;
- (id)serverPathPrefix;
- (void)_setServerPathPrefix:(id)arg1 permanently:(BOOL)arg2 shouldSync:(BOOL)arg3;
- (void)setServerPathPrefix:(id)arg1 permanently:(BOOL)arg2;
- (id)_fileSystemServerPathPrefix:(BOOL)arg1;
- (void)_setFileSystemServerPathPrefix;
- (void)syncFileSystemWithServerPathPrefix;
- (id)_mailboxPathPrefix:(BOOL)arg1;
- (void)_loadEntriesFromFileSystemPath:(id)arg1 parent:(id)arg2;
- (void)deleteMessagesFromMailboxUid:(id)arg1 olderThanNumberOfDays:(unsigned long long)arg2;
- (id)offlineCacheIfOffline;
- (id)offlineCache;
- (void)_clearOfflineCache;
- (id)mailboxUidForRelativePath:(id)arg1 isFilesystemPath:(BOOL)arg2 create:(BOOL)arg3;
- (id)_URLPersistenceScheme;
- (id)_infoForMatchingURL:(id)arg1;
- (BOOL)storesUnseenCount;
- (id)remoteTaskQueue;
@property(retain) LibraryIMAPStore *inboxStore; // @synthesize inboxStore=_inboxStore;
@property BOOL recoveringFromConnectionLoss; // @synthesize recoveringFromConnectionLoss=_recoveringFromConnectionLoss;
@property(retain) IMAPConnectionPool *connectionPool; // @synthesize connectionPool=_connectionPool;
- (int)messageCaching;
- (void)setMessageCaching:(int)arg1;

@end

