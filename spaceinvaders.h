//Christopher Clarizio
//Interface for the Spaceinvaders class

#include <iostream>
#include <vector>

class Spaceinvaders{
	public:
		Spaceinvaders();   //default constructor
		~Spaceinvaders();   //destructor
		void play();
		void tick();
		void updateCollisions();
		void updateMovement();
		void updateShoot();
		void display();
		bool tooclose();
		void dispStart();
	private:
		Fighter fighter;
		std::vector< std::vector<Invader> > invaders;
		std::vector< Projectile > projectiles;
		int direction;
		int moves;
};
