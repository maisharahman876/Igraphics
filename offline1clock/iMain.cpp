# include "iGraphics.h"
#include<math.h>
#include<time.h>
int h=500,w=500;
int x=300,y=400;
float t2,t1,t3;
int hour,minute,second;

/*
	function iDraw() is called again and again by the system.

	*/

	void secondkata()
{
t1=t1-.10472;

}
	void minutekata()
{
t2=t2-.00174;


}
	void hourkata()
{

t3=t3-.000145;

}


void iDraw() {
	//place your drawing codes here
	iClear();
	iSetColor(60, 20, 100);
	iFilledCircle(h/2,w/2,210,200000);
	iSetColor(2,2,10);
	iFilledCircle(h/2,w/2,170,2000000);
    iSetColor(255,255, 255);
    iFilledCircle(h/2,w/2,10);
	iLine(h/2,w/2,250+160*cos(t1),250+160*sin(t1));
	iLine(h/2,w/2,250+130*cos(t2),250+130*sin(t2));
	iLine(h/2,w/2,250+90*cos(t3),250+90*sin(t3));
	iSetColor(255,255,255);
	iText(250,250+187,"12",GLUT_BITMAP_HELVETICA_18);
	iText(411.946,343.5,"2",GLUT_BITMAP_HELVETICA_18);
	iText(343.5,411.946,"1",GLUT_BITMAP_HELVETICA_18);
	iText(250+185,250,"3",GLUT_BITMAP_HELVETICA_18);
	iText(411.946,156.5,"4",GLUT_BITMAP_HELVETICA_18);
	iText(345.5,88.05,"5",GLUT_BITMAP_HELVETICA_18);
	iText(250,250-190,"6",GLUT_BITMAP_HELVETICA_18);
	iText(153.5,85.05,"7",GLUT_BITMAP_HELVETICA_18);
	iText(85.05,153.5,"8",GLUT_BITMAP_HELVETICA_18);
	iText(250-190,250,"9",GLUT_BITMAP_HELVETICA_18);

	iText(156.5,411.946,"11",GLUT_BITMAP_HELVETICA_18);
	iText(85.05,348.51,"10",GLUT_BITMAP_HELVETICA_18);
	//iFilledRectangle(10, 30, 20, 20);
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);

	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}

int main() {
	//place your own initialization codes here.
    time_t now;
    struct tm *timeinfo;
    time(&now);
    timeinfo=localtime(&now);
    hour=timeinfo->tm_hour;
    hour=hour%12;
    minute=timeinfo->tm_min;
    second=timeinfo->tm_sec;
     t1=1.570796-second*.10472;
 t2=1.570796-minute*.10472;
 t3=1.570796-hour*.5236;

	iSetTimer(1000,secondkata);
	iSetTimer(1000,minutekata);
	iSetTimer(1000,hourkata);
	iInitialize(h,w, "CLOCK");
	return 0;
}

