#pragma once

#include <string>
#include <vector>

namespace blfs {

struct FriendScore {
  std::string beatLeaderName;
  int score = 0;
};

struct LeaderboardState {
  int myScore = 0;
  std::vector<FriendScore> friends;
};

}  // namespace blfs
