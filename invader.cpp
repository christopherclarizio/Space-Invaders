//Christopher Clarizio
//Implementation for the class Invader

#include <iostream>
#include <stdlib.h>
#include "gfxnew.h"
#include "invader.h"

Invader::Invader(){ setx(0); sety(0); setr(1); sets(0); seta(true); }
Invader::~Invader(){}
Invader::Invader( float xpos, float ypos, float radius, float speed, bool alive )
{
	setx( xpos );
	sety( ypos );
	setr( radius );
	sets( speed );
	seta( alive );
}
void Invader::setx( float xpos )
{
	x = xpos;
}
void Invader::sety( float ypos )
{
	y = ypos;
}
void Invader::setr( float rad )
{
	r = rad;
}
void Invader::sets( float speed )
{
	s = speed;
}
void Invader::seta( bool alive )
{
	a = alive;
}
float Invader::getx(){ return x; }
float Invader::gety(){ return y; }
float Invader::getr(){ return r; }
float Invader::gets(){ return s; }
bool Invader::geta(){ return a; }
void Invader::move( int dir )
{
	setx( getx() + dir * gets() );
}
void Invader::moveDown()
{
	sety( gety() + .25 );
}
bool Invader::isHit( float x, float y, float r )
{
	if( abs( x - getx() ) < r + getr() + 10 && abs( y - gety() ) < r + getr() + 10 )
	{
		return true;
	}
	return false;
}
void Invader::draw()
{
	gfx_color( 255, 0, 255 );
	gfx_fill_circle( getx(), gety(), getr() );
	gfx_color( 255, 255, 255 );

}
