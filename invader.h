//Christopher Clarizio cse20311 12-14-2016
//Interface for the Invader class

class Invader{
	public:
		Invader();   //default constructor
		Invader( float, float, float, float, bool );   //constructor takes args for x,y,r,s
		~Invader();   //destructor
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
		void move( int );   //functions to move invader
		void moveDown();
		bool isHit( float, float, float );
		void draw();   //draws the Invader
	private:
		float x;   //vars to store xpos,ypos,radius,speed,live status
		float y;
		float r;
		float s;
		bool a;
};
