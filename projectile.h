//Christopher Clarizio
//Interface for the Projectile class

class Projectile{
	public:
		Projectile();   //default constructor
		Projectile( float, float, int, int, bool );   //constructor takes args for x,y,r,s
		~Projectile();   //destructor
		void setx( float );   //setters for x,y,radius,speed
		void sety( float );
		void setr( float );
		void sets( float );
		void seta( bool );
		float getx();   //getters for x,y,radius,speed
		float gety();
		float getr();
		float gets();
		bool geta();
		void moveLeft();   //functions to move invader
		void moveRight();
		void moveDown();
		bool isHit( float, float, float );
		void draw();   //draws the Projectile
	private:
		float x;   //vars to store xpos,ypos,radius,speed
		float y;
		float r;
		float s;
		bool a;
};
