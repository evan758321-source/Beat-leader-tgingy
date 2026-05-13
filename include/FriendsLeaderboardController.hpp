#pragma once

#include "BeatLeaderService.hpp"
#include <optional>
#include <string>

namespace blfs {

class FriendsLeaderboardController {
 public:
  explicit FriendsLeaderboardController(BeatLeaderService service);

  void OnSongStarted(const std::string& levelId);
  void OnScoreChanged(int newScore);

 private:
  void RefreshRightSideUI();
  void ShowSnipedPopup(const std::string& friendName) const;
  void DetectSnipes();

  BeatLeaderService service_;
  std::string levelId_;
  LeaderboardState state_;
  std::optional<std::string> lastSnipedFriend_;
};

}  // namespace blfs
