//--------------------------------------------------------------------------------------
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "OnlineSubsystemPlayFab.h"
#include "Interfaces/OnlineExternalUIInterface.h"
#include "OnlineSubsystemTypes.h"
#include "OnlineSubsystemPlayFabPackage.h"

/// <summary>
/// The maximum allowed value for invited players.
/// </summary>
constexpr uint32_t c_PFInviteMaxPlayerCount = 32;

/**
 * Implementation for the Live external UIs
 */
class FOnlineExternalUIPlayFab
	: public IOnlineExternalUI
	, public TSharedFromThis<FOnlineExternalUIPlayFab, ESPMode::ThreadSafe>
{
PACKAGE_SCOPE:
	explicit FOnlineExternalUIPlayFab(FOnlineSubsystemPlayFab* InSubsystem);

	class FOnlineSubsystemPlayFab* OSSPlayFab = nullptr;

public:
	virtual ~FOnlineExternalUIPlayFab()
	{
	}

	// IOnlineExternalUI
	virtual bool ShowLoginUI(const int ControllerIndex, bool bShowOnlineOnly, bool bShowSkipButton, const FOnLoginUIClosedDelegate& Delegate = FOnLoginUIClosedDelegate()) override;
	virtual bool ShowAccountCreationUI(const int ControllerIndex, const FOnAccountCreationUIClosedDelegate& Delegate = FOnAccountCreationUIClosedDelegate()) override { /** NYI */ return false; }
	virtual bool ShowFriendsUI(int32 LocalUserNum) override;
	virtual bool ShowInviteUI(int32 LocalUserNum, FName SessionName = NAME_GameSession) override;
	virtual bool ShowAchievementsUI(int32 LocalUserNum) override;
	virtual bool ShowLeaderboardUI(const FString& LeaderboardName) override;
	virtual bool ShowWebURL(const FString& Url, const FShowWebUrlParams& ShowParams, const FOnShowWebUrlClosedDelegate& Delegate = FOnShowWebUrlClosedDelegate()) override;
	virtual bool CloseWebURL() override;
	virtual bool ShowProfileUI(const FUniqueNetId& Requestor, const FUniqueNetId& Requestee, const FOnProfileUIClosedDelegate& Delegate = FOnProfileUIClosedDelegate()) override;
	virtual bool ShowAccountUpgradeUI(const FUniqueNetId& UniqueId) override;
	virtual bool ShowStoreUI(int32 LocalUserNum, const FShowStoreParams& ShowParams, const FOnShowStoreUIClosedDelegate& Delegate = FOnShowStoreUIClosedDelegate()) override;
	virtual bool ShowSendMessageUI(int32 LocalUserNum, const FShowSendMessageParams& ShowParams, const FOnShowSendMessageUIClosedDelegate& Delegate = FOnShowSendMessageUIClosedDelegate()) override;
	virtual bool ShowSendMessageToUserUI(int32 LocalUserNum, const FUniqueNetId& Recipient, const FShowSendMessageParams& ShowParams, const FOnShowSendMessageUIClosedDelegate& Delegate = FOnShowSendMessageUIClosedDelegate()) override;
	virtual bool ShowPlatformMessageBox(const FUniqueNetId& UserId, EPlatformMessageType MessageType) override;
	virtual void ReportEnterInGameStoreUI() override;
	virtual void ReportExitInGameStoreUI() override;

private:
	void HandleShowInviteUIComplete(bool bIsSuccess);
};

typedef TSharedPtr<FOnlineExternalUIPlayFab, ESPMode::ThreadSafe> FOnlineExternalUIPlayFabPtr;
