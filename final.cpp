//Christopher Clarizio
//Implementation for the driver class

#include <iostream>
#include <unistd.h>
#include "gfxnew.h"
#include "fighter.h"
#include "invader.h"
#include "projectile.h"
#include "spaceinvaders.h"
//#include <stdlib.h>

int main()
{
	gfx_open( 700, 650, "Space Invaders" );
	Spaceinvaders game = Spaceinvaders();
	game.dispStart();
	game.play();
	return 1;
}
