#include "BeatLeaderService.hpp"
#include "FriendsLeaderboardController.hpp"

#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"

using namespace blfs;

static FriendsLeaderboardController* g_controller = nullptr;

extern "C" void setup(ModInfo& info) {
  info.id = "com.yourname.beatleaderfriendssniper";
  info.version = "0.1.0";
  getLogger().info("BeatLeader Friends Sniper setup complete");
}

extern "C" void load() {
  il2cpp_functions::Init();

  static BeatLeaderService service("YOUR_BEATLEADER_PLAYER_ID");
  static FriendsLeaderboardController controller(service);
  g_controller = &controller;

  // TODO:
  // Hook score controller updates and call g_controller->OnScoreChanged(score)
  // Hook song start and call g_controller->OnSongStarted(levelId)

  getLogger().info("BeatLeader Friends Sniper loaded");
}
