namespace PROFILE {
    
    enum class VisibilityLevel : std::uint8_t {
        Public = 0,
        Friend = 1,
        CloseFriend = 2,
        OnlyMe = 3,
        Nobody = 4
    };

    struct VisibilitySettings {
        VisibilityLevel ShowOnlineStatus = VisibilityLevel::Public;
        VisibilityLevel ShowLastSeen = VisibilityLevel::Public;
        VisibilityLevel ShowProfileIcon = VisibilityLevel::Public;
        VisibilityLevel ShowProfileHeader = VisibilityLevel::Public;
        VisibilityLevel ShowBirthDate  = VisibilityLevel::Public;
        VisibilityLevel ShowPosts = VisibilityLevel::Public;
        VisibilityLevel ShowPhone = VisibilityLevel::OnlyMe;
        VisibilityLevel ShowFriendList = VisibilityLevel::Friend;
        VisibilityLevel ShowQuote  = VisibilityLevel::Public;
    }

    struct PrivacySettings {
        bool AllowSearchByPhone = {true};
        bool AllowMessageFromAnyone = {true};
        bool AllowFriendRequests = {true};
        bool NotificationPermission = {true};
    };
    
} // namespace PROFILE
