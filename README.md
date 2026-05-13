# BeatLeader Friends Sniper (Quest Standalone, Beat Saber 1.40.8)

This repository contains a starter Quest standalone QMod project for Beat Saber **1.40.8**.

## Features implemented in this starter

- Right-side leaderboard UI update pipeline (currently log-backed placeholder).
- Displays:
  - Your current score
  - Friends' BeatLeader scores for the current map
- Snipe detection logic:
  - When your score exceeds a friend's score, you move up the ranking logic.
  - Emits popup event text: `Sniped <BeatLeaderUsername>` (currently log-backed placeholder).

## What still needs to be wired

- Real BeatLeader REST calls in `BeatLeaderService`.
- In-game right-side world-space UI (BSML/HMUI).
- Hooks for:
  - Song start (fetch map leaderboard)
  - Score updates (live reorder + snipe popup)
- Popup visual style matching HitScoreVisualizer animation.

## Build in GitHub Actions

A workflow is included at `.github/workflows/build.yml`.
It uses QPM to restore dependencies, build, and package a `.qmod` artifact.

## Local build outline

```bash
qpm restore
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -j
qpm qmod zip
```
