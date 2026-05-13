#include "FriendsLeaderboardController.hpp"

#include <algorithm>
#include <sstream>

#include "beatsaber-hook/shared/utils/logging.hpp"

namespace blfs {

FriendsLeaderboardController::FriendsLeaderboardController(BeatLeaderService service)
    : service_(std::move(service)) {}

void FriendsLeaderboardController::OnSongStarted(const std::string& levelId) {
  levelId_ = levelId;
  state_ = service_.FetchFriendsForCurrentMap(levelId_);
  RefreshRightSideUI();
}

void FriendsLeaderboardController::OnScoreChanged(int newScore) {
  state_.myScore = newScore;
  DetectSnipes();
  RefreshRightSideUI();
}

void FriendsLeaderboardController::DetectSnipes() {
  for (const auto& friendScore : state_.friends) {
    if (state_.myScore > friendScore.score && lastSnipedFriend_ != friendScore.beatLeaderName) {
      lastSnipedFriend_ = friendScore.beatLeaderName;
      ShowSnipedPopup(friendScore.beatLeaderName);
      break;
    }
  }
}

void FriendsLeaderboardController::RefreshRightSideUI() {
  // TODO: Replace logs with world-space UI panel anchored to the right side of the player view.
  // Suggested stack:
  // - BSML for declarative UI
  // - HMUI::ViewController for lifecycle
  // - Position with anchored transform X > 0 (right side of camera)

  std::stringstream ss;
  ss << "[BLFS] Right UI Leaderboard\n";
  ss << "You: " << state_.myScore << "\n";
  for (const auto& friendScore : state_.friends) {
    ss << friendScore.beatLeaderName << ": " << friendScore.score << "\n";
  }

  getLogger().info("%s", ss.str().c_str());
}

void FriendsLeaderboardController::ShowSnipedPopup(const std::string& friendName) const {
  // TODO: Replace with in-game popup animation similar to HitScoreVisualizer style.
  getLogger().info("Sniped %s", friendName.c_str());
}

}  // namespace blfs
