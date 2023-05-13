#pragma once
enum PlayerColor {
	pWhite,
	pBlack,
	pEmpty,
	MAX_PLAYERS_NUM = pEmpty
};

#define otherPlayer(color) (PlayerColor)(((int)color + 1) % MAX_PLAYERS_NUM)