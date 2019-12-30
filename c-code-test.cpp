#include <iostream>
#include <queue>

#define HEIGHT 600
#define WIDTH  800

using namespace std;

struct Ball {

	public:
	int posX;
	int posY;
	int speedX;
	int speedY;
	int size;

	// Parameterized Constructor
	Ball(int pX, int pY, int sX, int sY, int s){
		posX = pX;
		posY = pY;
		speedX = sX;
		speedY = sY;
		size = s;
	}

};


void moveBall(Ball obj){
	if (obj.posX > WIDTH){ obj.speedX = (rand() % 10 + 1) * -1; }; 
    if (obj.posY > HEIGHT){ obj.speedY = (rand() % 10 + 1) * -1; };
    if (obj.posX < 0){ obj.speedX = rand() % 10 + 1; };
    if (obj.posY < 0){ obj.speedY = rand() % 10 + 1; };

    obj.posX += obj.speedX;
  	obj.posY += obj.speedY;
}

void updatePos(Ball obj){

}

void collisionCheck(){

}

std::ostream &operator<<(std::ostream &os, const Ball &b) { 
	return os << "pX: " << b.posX << "\npY: " << b.posY << "\nsX: " << b.speedX << "\nsY: " << b.speedY << "\n" << endl;
}

int main(){
	queue<Ball> objQueue;

	Ball obj1(10, 10, 5, 5, 150);
	Ball obj2(1490, 740, 5, 5, 150);
	Ball obj3(10, 740, 5, 5, 150); 
	Ball obj4(1490, 10, 5, 5, 150); 

	objQueue.push( obj1 );
	objQueue.push( obj2 );
	objQueue.push( obj3 );
	objQueue.push( obj4 );

	// TEST
	while (!objQueue.empty()){
		cout << objQueue.front();
		objQueue.pop();
	}

	return 0;
}