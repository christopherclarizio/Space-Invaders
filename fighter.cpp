//Christopher Clarizio
//Implementation for the class fighter

#include <iostream>
#include <stdlib.h>
#include "gfxnew.h"
#include "fighter.h"

Fighter::Fighter(){ setx(0); sety(0); setr(1); sets(0); }
Fighter::~Fighter(){}
Fighter::Fighter( float xpos, float ypos, float radius, float speed, bool alive )
{
	setx( xpos );
	sety( ypos );
	setr( radius );
	sets( speed );
	seta( alive );
	std::cout << "created fighter at " << getx() << "," << gety() << " with radius: " 
	<< getr() << " and speed: " << gets() << std::endl;
}
void Fighter::setx( float xpos )
{
	x = xpos;
	std::cout << "set fighter's x to " << x << std::endl;
}
void Fighter::sety( float ypos )
{
	y = ypos;
	std::cout << "set fighter's y to " << y << std::endl;
}
void Fighter::setr( float rad )
{
	r = rad;
	std::cout << "set fighter's r to " << rad << std::endl;
}
void Fighter::sets( float speed )
{
	s = speed;
	std::cout << "set fighter's s to " << speed << std::endl;
}
void Fighter::seta( bool alive )
{
	a = alive;
	std::cout << "set fighter to alive " << std::endl;
}
float Fighter::getx(){ return x; }
float Fighter::gety(){ return y; }
float Fighter::getr(){ return r; }
float Fighter::gets(){ return s; }
bool Fighter::geta(){ return a; }
void Fighter::moveLeft()
{
	setx( getx() - gets() );
	if( x < 10 )
	{
		setx( 10 );
	}
}
void Fighter::moveRight()
{
	setx( getx() + gets() );
	if( x > 690 )
	{
		setx( 690 );
	}
}
bool Fighter::isHit( float x, float y, float r )
{
	if( abs( x - getx() ) < r + getr() && abs( y - gety() ) < r + getr() )
	{
		return true;
	}
	return false;
}
void Fighter::draw()
{
	gfx_color( 0, 255, 0 );
	gfx_fill_circle( getx(), gety(), getr() );
	gfx_color( 255, 255, 255 );

}
