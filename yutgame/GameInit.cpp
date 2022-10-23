#include "Player.h"
#include "GameInit.h"
#include <stdio.h>
#include <locale.h>
GameInit::GameInit()
{
	wchar_t Shape[3];
	setlocale(LC_ALL, "");
	Shape[0] = L'¡Û';
	Shape[1] = L'¡Ý';
	

	const wchar_t player_one_shape[3] = { L'¡Û',L'¡Ý',L'¡Ü'};
	const wchar_t player_two_shape[3] = { L'¡à',L'¢Ã',L'¡á' };
	player[0]->SetHorseShape(player_one_shape);
	player[1]->SetHorseShape(player_two_shape);
}
