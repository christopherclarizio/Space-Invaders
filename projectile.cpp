//Christopher Clarizio cse20311 12-14-2016
//Implementation for the class Projectile

#include <iostream>
#include <stdlib.h>
#include "gfxnew.h"
#include "projectile.h"

Projectile::Projectile(){ setx(0); sety(0); setr(1); sets(0); }
Projectile::~Projectile(){}
Projectile::Projectile( float xpos, float ypos, int radius, int speed, bool alive )
{
	setx( xpos );
	sety( ypos );
	setr( radius );
	sets( speed );
	seta( alive );
	std::cout << "created Projectile at " << getx() << "," << gety() << " with radius: " 
	<< getr() << " and speed: " << gets() << std::endl;
}
void Projectile::setx( float xpos )
{
	x = xpos;
}
void Projectile::sety( float ypos )
{
	y = ypos;
}
void Projectile::setr( float rad )
{
	r = rad;
}
void Projectile::sets( float speed )
{
	s = speed;
}
void Projectile::seta( bool alive )
{
	a = alive;
}
float Projectile::getx(){ return x; }
float Projectile::gety(){ return y; }
float Projectile::getr(){ return r; }
float Projectile::gets(){ return s; }
bool Projectile::geta(){ return a; }
void Projectile::moveLeft(){ setx( getx() - gets() ); }
void Projectile::moveRight(){ setx( getx() + gets() ); }
void Projectile::moveDown(){ sety( gety() + gets() ); }
bool Projectile::isHit( float x, float y, float r )
{
	if( abs( x - getx() ) < r + getr() && abs( y - gety() ) < r + getr() )
	{
		return true;
	}
	return false;
}
void Projectile::draw()
{
	gfx_color( 255, 0, 0 );
	gfx_fill_circle( getx(), gety(), getr() );
	gfx_color( 255, 255, 255 );

}
