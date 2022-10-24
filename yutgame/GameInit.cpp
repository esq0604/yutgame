#include "Player.h"
#include "GameInit.h"
#include <stdio.h>
#include <locale.h>
GameInit::GameInit(Player(&player)[2])
{
	wchar_t Shape[3];
	setlocale(LC_ALL, "");
	Shape[0] = L'○';
	Shape[1] = L'◎';
	
	//멀티바이트 -> 1바이트변환 or string 맵크기 늘리기
	const wchar_t player_one_shape[3] = { L'○',L'◎',L'●'};
	const wchar_t player_two_shape[3] = { L'□',L'▣',L'■' };
	player[0].SetHorseShape(player_one_shape);
	player[1].SetHorseShape(player_two_shape);
}
