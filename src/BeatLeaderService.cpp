#include "BeatLeaderService.hpp"

#include <algorithm>

namespace blfs {

BeatLeaderService::BeatLeaderService(std::string playerId) : playerId_(std::move(playerId)) {}

LeaderboardState BeatLeaderService::FetchFriendsForCurrentMap(const std::string& levelId) const {
  // TODO: Replace this with real BeatLeader API request for Quest standalone.
  // Endpoint idea: /player/{id}/scores?leaderboard={levelId}&friends=true
  (void)levelId;

  LeaderboardState state;
  state.myScore = 0;
  state.friends = {
      {.beatLeaderName = "FriendOne", .score = 934421},
      {.beatLeaderName = "FriendTwo", .score = 901200},
      {.beatLeaderName = "FriendThree", .score = 870002},
  };
  std::sort(state.friends.begin(), state.friends.end(), [](const FriendScore& a, const FriendScore& b) {
    return a.score > b.score;
  });

  return state;
}

}  // namespace blfs
