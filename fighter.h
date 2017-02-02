//Christopher Clarizio
//Interface for the Fighter class

class Fighter{
	public:
		Fighter();   //default constructor
		Fighter( float, float, float, float, bool );   //constructor takes args for	x,y,r,s
		~Fighter();   //destructor
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
		bool isHit( float, float, float );
		void draw();   //draws the fighter
	private:
		float x;   //vars to store xpos,ypos,radius,speed,live status
		float y;
		float r;
		float s;
		bool a;
};
