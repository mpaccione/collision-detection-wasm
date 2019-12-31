// Due to dependency bug compile with command
// g++ c-code-test.cpp `simple2d --libs` -o c-code-test

#include <iostream>
#include <vector>
#include <simple2d.h>

#define HEIGHT  800
#define WIDTH  1024

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
	int const radius = b.size/2;

	if (b.posX > (WIDTH + radius)){ b.speedX = (rand() % 10 + 1) * -1; }; 
    if (b.posY > (HEIGHT + radius)){ b.speedY = (rand() % 10 + 1) * -1; };
    if ((b.posX - radius) < 0){ b.speedX = rand() % 10 + 1; };
    if ((b.posY - radius) < 0){ b.speedY = rand() % 10 + 1; };

    b.posX += b.speedX;
    b.posY += b.speedY;
}

void collisionCheck(Ball &b1, int n){
	for (int i = 0; i < bVector.size(); i++) {
		if (i != n){
  			// Improved Col Detection - Takes Larger Radius of the Two Balls
  			Ball& b2 = bVector[i];
  			int const colRadius = b2.size > b1.size ? b2.size*0.5 : b1.size*0.5;
  			// Only visible balls
  			if (colRadius > 1) {
				if (b1.posX <= b2.posX + colRadius && b1.posX >= b2.posX - colRadius
					&& b1.posY <= b2.posY + colRadius && b1.posY >= b2.posY - colRadius)
				{
					// Reverse Direction 
					b1.speedX *= -0.66;
					b1.speedY *= -0.66;
					b2.speedX *= -0.66;
					b2.speedY *= -0.66;

					// Make 2/3 Original Size
					b1.size *= 0.66;
					b2.size *= 0.66;

					// Add New Ball on Col
					Ball b3(b2.posX + b2.size, b2.posY + b2.size, 8.3, 8.3, b2.size);
					bVector.push_back(b3);
				}
			}
		} 
  	}
}

// DEBUGGING - LOGGING
std::ostream &operator<<(std::ostream &os, const Ball &b) { 
	return os << "pX: " << b.posX << "\npY: " << b.posY << "\nsX: " << b.speedX << "\nsY: " << b.speedY << "\n" << endl;
}

void update(){
	// Update Application State
	for (int i = 0; i < bVector.size(); ++i){
		Ball& b = bVector.at(i);
		moveBall(b);
		collisionCheck(b, i);
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
	Ball b1(10, 10, 5, 5, 100);
	Ball b2(1490, 740, 5, 5, 100);
	Ball b3(10, 740, 5, 5, 100); 
	Ball b4(1490, 10, 5, 5, 100); 

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