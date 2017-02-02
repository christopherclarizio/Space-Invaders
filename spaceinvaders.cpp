//Christopher Clarizio
//Implementation for Spaceinvaders class
#include <vector>
#include <unistd.h>
#include "gfxnew.h"
#include "fighter.h"
#include "invader.h"
#include "projectile.h"
#include "spaceinvaders.h"

Spaceinvaders::Spaceinvaders()
{
	fighter = Fighter( 350, 625, 15, 10, true );
	for( int i = 0; i < 3; i++ )
	{
	std::vector<Invader> temp;
		for( int j = 0; j < 11; j++ )
		{
			Invader invader = Invader( 20+40*j, 170-40*i, 10, 5, true );
			temp.push_back( invader );
		}
	invaders.push_back( temp );
	}
	direction = 1;
	moves = 0;
}

Spaceinvaders::~Spaceinvaders(){}
void Spaceinvaders::play()
{
	while( !invaders[0].empty() && !invaders[1].empty() && !invaders[2].empty() && 	fighter.geta() && !tooclose() )
	{
		tick();
		usleep( 10000 );
	}
}
void Spaceinvaders::tick()
{
	char c;
	if( gfx_event_waiting() )
	{
		c = gfx_wait();
		std::cout << c << std::endl;
		if( c == 'a' )
		{
			fighter.moveLeft();
		}
		else if( c == 'd' )
		{
			fighter.moveRight();
		}
		else if( c == ' ' )
		{
			Projectile p = Projectile( fighter.getx(), fighter.gety()-25, 5, -35, true );
			projectiles.push_back( p );
		}
	}
	updateCollisions();
	std::cout << "updated collisions" << std::endl;
	updateMovement();
	std::cout << "updated movement" << std::endl;
	updateShoot();
	std::cout << "updated shoot" << std::endl;
	display();
	std::cout << "displayed" << std::endl;
	std::cout << projectiles.size() << std::endl;
}
void Spaceinvaders::updateCollisions()
{
	for( int i = 0; i < invaders.size(); i++ )
	{
		for( int j = 0; j < invaders.size(); j++ )
		{
			for( int k = 0; k < projectiles.size(); k++ )
			{
				if( invaders[i][j].isHit( projectiles[k].getx(), projectiles[k].gety(), projectiles[k].getr() ) )
				{
					invaders[i][j].seta( false );
					projectiles[k].seta( false );
				}
			}
		}
	}

	std::cout << "checked invader projectile collisions" << std::endl;

	for( int j = 0; j < projectiles.size(); j++ )
	{
		if( fighter.isHit( projectiles[j].getx(), projectiles[j].gety(), projectiles[j].getr() ) )
		{
			fighter.seta( false );
			projectiles[j].seta( false );
		}
	}

	std::cout << "checked fighter projectile collisions" << std::endl;

	for( int i = 0; i < invaders.size(); i++ )
	{
		for( auto it = invaders[i].begin(); it != invaders[i].end(); it++ )
		{
//			std::cout << i << std::endl;
			if( !(*it).geta() )
				invaders[i].erase( it );
		}
	}

	std::cout << "erased dead invaders" << std::endl;

	for( auto it = projectiles.begin(); it != projectiles.end(); it++ )
	{
//		std::cout << (*it).geta() << std::endl;
		if( !(*it).geta() )
			projectiles.erase( it );
	}

}
void Spaceinvaders::updateMovement()
{

	if( projectiles.size() > 60 )
	{
		projectiles.clear();
	}

	for( int i = 0; i < projectiles.size(); i++ )
	{
		projectiles[i].moveDown();
	}

	std::cout << "moved projectiles " << std::endl;

	for( int i = 0; i < invaders.size(); i++ )
	{
		for( int j = 0; j < invaders[i].size(); j++ )
		{
			invaders[i][j].move(direction);
			invaders[i][j].moveDown();
		}
	}

	std::cout << "moved invaders" << std::endl;

	moves++;
	if( moves % 50 == 0 )
	{
		direction = direction * -1;
	}

}
void Spaceinvaders::updateShoot()
{
	float prob = 600;
	srand(time(NULL));
	float random = rand() % 1000;
	if( random < prob )
	{
		if( !invaders[0].empty() )
		{
			int pos = rand() % (invaders[0].size() - 1) + 1;
			Projectile p = Projectile( invaders[0][pos].getx(),	invaders[0][pos].gety()+25, 5, 15, true );
			projectiles.push_back( p );
			std::cout << "the invader at index " << pos << " created a projectile at " << invaders[0][pos].getx() << "," << invaders[0][pos].gety()+25 << std::endl;
		}
		else if( !invaders[1].empty() )
		{
			int pos = rand() % invaders[1].size() + 1;
			Projectile p = Projectile( invaders[1][pos].getx(),	invaders[1][pos].gety()+25, 5, 15, true );
			projectiles.push_back( p );
		}
		else if( !invaders[2].empty() )
		{
			int pos = rand() % invaders[2].size() + 1;
			Projectile p = Projectile( invaders[2][pos].getx(),	invaders[2][pos].gety()+25, 5, 15, true );
			projectiles.push_back( p );
		}

	}

}
void Spaceinvaders::display()
{
	gfx_clear();
	fighter.draw();
	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < invaders[i].size(); j++ )
		{
			invaders[i][j].draw();
		}
	}
	for( int i = 0; i < projectiles.size(); i++ )
	{
		projectiles[i].draw();
	}
	gfx_flush();

}

bool Spaceinvaders::tooclose()
{
	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < invaders[i].size(); j++ )
		{
			if( invaders[i][j].gety() > 625 )
				return true;
		}
	}
	return false;
}

void Spaceinvaders::dispStart()
{
	gfx_color( 20, 255, 20 );
	for( int i = 0; i < 10; i++ )
	{
		gfx_text( 317, 300, "SPACE INVADERS" );
	}
	gfx_text( 300, 400, "PRESS SPACE TO START" );

	char c = gfx_wait();
	while( c != ' ' )
	{
		usleep(1000);
		c = gfx_wait();
	}

}

