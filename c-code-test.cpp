// Due to dependency bug compile with command
// g++ c-code-test.cpp `simple2d --libs` -o c-code-test

#include <iostream>
#include <vector>
#include <simple2d.h>

#define HEIGHT 1920
#define WIDTH  1680

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

// GLOBALS
vector<Ball> bVector;

void moveBall(Ball &b){
	if (b.posX > WIDTH){ b.speedX = (rand() % 10 + 1) * -1; }; 
    if (b.posY > HEIGHT){ b.speedY = (rand() % 10 + 1) * -1; };
    if (b.posX < 0){ b.speedX = rand() % 10 + 1; };
    if (b.posY < 0){ b.speedY = rand() % 10 + 1; };

    b.posX += b.speedX;
  	b.posY += b.speedY;
}

//void collisionCheck(Ball &b){
	// Javascript Code to be converted to C++

	// for (var i = 0; i < a; i++) {

 //  		//Improved Col Detection - Takes Larger Radius of the Two Balls
 //  		var colRadius = ballArray[i].size > this.size ? ballArray[i].size*0.5 : this.size*0.5;

 //  		if (colRadius > 1) {
		// 		if (this.posX <= posArray[i][0] + colRadius && this.posX >= posArray[i][0] - colRadius
		// 			&& this.posY <= posArray[i][1] + colRadius && this.posY >= posArray[i][1] - colRadius)
		// 		{
		// 			//Reverse Direction 
		// 			this.speedX *= -0.66;
		// 			this.speedY *= -0.66;
		// 			ballArray[i].speedX *= -0.66;
		// 			ballArray[i].speedY *= -0.66;

		// 			//Make 2/3 Original Size
		// 			this.size *= 0.66;
		// 			ballArray[i].size *= 0.66;

		// 			//Add New Ball on Col
		// 			var newBall = new ball(ballArray[i].posX + ballArray[i].size, ballArray[i].posY + ballArray[i].size, 8.3, 8.3, ballArray[i].size);
		// 			ballArray.push(newBall);
		// 		}
		// 	} 
 //  	}
//}

// DEBUGGING - LOGGING
std::ostream &operator<<(std::ostream &os, const Ball &b) { 
	return os << "pX: " << b.posX << "\npY: " << b.posY << "\nsX: " << b.speedX << "\nsY: " << b.speedY << "\n" << endl;
}

void update(){
	// Update Application State
	for (int i = 0; i < bVector.size(); ++i){
		Ball& b = bVector.at(i);
		moveBall(b);
		// cout << "posX " << b.posX << " posY " << b.posY << endl;
	}
}

void render(){
	// Draw Balls
	for (int i = 0; i < bVector.size(); ++i){
		Ball& b = bVector.at(i);
		S2D_DrawCircle( b.posX, b.posY, b.size, 360, 255, 255, 255, 1 );
	}
}

int main(){
	Ball b1(10, 10, 5, 5, 150);
	Ball b2(1490, 740, 5, 5, 150);
	Ball b3(10, 740, 5, 5, 150); 
	Ball b4(1490, 10, 5, 5, 150); 

	bVector.push_back(b1);
	bVector.push_back(b2);
	bVector.push_back(b3);
	bVector.push_back(b4);

	// 2D Drawing 
	S2D_Window *window = S2D_CreateWindow(
		"2D Collision Detection", WIDTH, HEIGHT, update, render, 0
	);

	S2D_Show(window);
	return 0;
}