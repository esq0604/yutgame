#include "Player.h"
#include "GameInit.h"

GameInit::GameInit()
{
	const string player_one_shape[3] = { "¡Û","¡Ý","¡Ü" };
	const string player_two_shape[3] = { "¡à","¢Ã","¡á" };
	player[0]->SetHorseShape(player_one_shape);
	player[1]->SetHorseShape(player_two_shape);
}
