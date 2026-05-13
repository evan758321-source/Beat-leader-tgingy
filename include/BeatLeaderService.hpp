#pragma once

#include "BeatLeaderTypes.hpp"
#include <string>

namespace blfs {

class BeatLeaderService {
 public:
  explicit BeatLeaderService(std::string playerId);
  LeaderboardState FetchFriendsForCurrentMap(const std::string& levelId) const;

 private:
  std::string playerId_;
};

}  // namespace blfs
