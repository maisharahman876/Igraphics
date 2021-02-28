# include "iGraphics.h"

char str[100], str2[100];
int len;
int mode;
int s=50;
 int x=600,x1,y=40;
int s1=s,s2=s,s3=s,s4=s,s5=s,s6=s,s7=s;
int i=0, r=255,g=255,b=255;
void drawsegment()
{

    iSetColor(r,g,b);
    iFilledRectangle(x+x1,y,4,s1);
      iFilledRectangle(x+x1,y,s2,4);
        iFilledRectangle(x+x1+50,y,4,s3);
          iFilledRectangle(x+x1,y+50,s4,4);
            iFilledRectangle(x+x1,y+50,4,s5);
              iFilledRectangle(x+x1+50,y+50,4,s6);
                iFilledRectangle(x+x1+4,y+100,s7,4);

}
void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(150, 400, 300, 50);
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
 x1=0;

	iClear();

	drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(155, 420, str);
	}
	for(i=0;str[i]!='\0';i++)
    {
        s1=s,s2=s,s3=s,s4=s,s5=s,s6=s,s7=s;
	if(str[i]=='0'||str[i]=='D')
    {
        s4=0;
        drawsegment();
    }
   else if(str[i]=='1')
    {
        s4=0,s1=0,s2=0,s5=0,s7=0;
        drawsegment();
    }
   else if(str[i]=='2')
    {
        s3=0,s5=0;
        drawsegment();
    }
    else if(str[i]=='3')
    {
        s1=0,s5=0;
        drawsegment();
    }
    else if(str[i]=='4')
    {
        s1=0,s2=0,s7=0;
        drawsegment();
    }
	else if(str[i]=='5')
    {
        s1=0,s6=0;
        drawsegment();
    }
    else if(str[i]=='6')
    {
        s6=0;
        drawsegment();
    }
    else if(str[i]=='7')
    {
        s1=0,s2=0,s4=0,s5=0;
        drawsegment();
    }
    else if(str[i]=='8'||str[i]=='B')
        {
        drawsegment();
    }
    else if(str[i]=='9')
    {
        s1=0;
        drawsegment();
    }
    else if(str[i]=='A')
    {
        s2=0;
        drawsegment();
    }
    else if(str[i]=='C')
    {
        s3=0,s6=0,s4=0;
        drawsegment();

    }
    else if(str[i]=='E')
    {
        s3=0,s6=0;
        drawsegment();

    }
    else if(str[i]=='F')
    {
        s2=0,s3=0,s6=0;
        drawsegment();

    }
    else if(str[i]=='b')
    {
        s6=0,s7=0;
        drawsegment();
    }
    x1+=60;
    }



    iSetColor(255,255,255);
	iText(10, 10, "Click to activate the box, enter to finish.");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= 150 && mx <= 550 && my >= 400 && my <= 450 && mode == 0)
		{
			mode = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void moving()
{

    x=x-30;
    if(x<=-60)
    {
        x=x+400;
    }

}
void colorchng()
{
     r-=10;
    g-=4;
    b-=5;
    if(r<-5)
    {
        r=r+255;
    }
    if(g<-2)
    {
        g=g+255;
    }
        if(b<-3)
    {
        b=+255;
    }
}

void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}

	if(key == 'x')
	{
		//do something with 'x'
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
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.

	iSetTimer(1000,moving);
	iSetTimer(50,colorchng);
	len = 0;
	mode = 0;
	str[0]= 0;
	iInitialize(600,600, "off2");
	return 0;
}
