#pragma once

const int PLAYER_HP = 20;
const int BOSS_DMG = 1;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int ARENA_WIDTH = 200;
const int ARENA_HEIGHT = 200;

const int ARENA_POS_Y_OFFSET = 100;

const int ARENA_POS_X = (WINDOW_WIDTH - ARENA_WIDTH) / 2;
const int ARENA_POS_Y = (WINDOW_HEIGHT - ARENA_HEIGHT) / 2 + ARENA_POS_Y_OFFSET;

const int PLAYER_SPEED = 2;

const int PLAYER_HEALTH_BAR_POS_X = ARENA_POS_X;
const int PLAYER_HEALTH_BAR_POS_Y = ARENA_POS_Y + ARENA_HEIGHT + 15;
const int PLAYER_HEALTH_BAR_WIDTH = 200 * 20 / 50.0f;

const int PLAYER_INIT_POSITION_X = ARENA_POS_X + ARENA_WIDTH / 2;
const int PLAYER_INIT_POSITION_Y = ARENA_POS_Y + ARENA_HEIGHT / 2;

const int EASY_MODE = 2;
const int NORMAL_MODE = 0;
const int HARD_MODE = 1;
const int CHAOS_MODE = 4;
const int DEBUG_MODE = 5;
const int SUPER_HARD_MODE = 6;

const float IFRAME_DURATION = 1.0f;

const double PI = 3.14159265358979323846;