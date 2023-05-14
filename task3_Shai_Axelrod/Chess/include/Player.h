#pragma once

/**
 * @enum PlayerColor
 * @brief Represents the color of a player in chess.
 */
enum PlayerColor {
	pWhite,
	pBlack,
	pEmpty,
	MAX_PLAYERS_NUM = pEmpty
};

/**
 * Given a player color, this macro returns the color of the opposite player.
 * If the input color is pWhite, it returns pBlack, and vice versa.
 *
 * @param color The input player color.
 * @return The opposite player color.
 */
#define otherPlayer(color) (PlayerColor)(((int)color + 1) % MAX_PLAYERS_NUM)