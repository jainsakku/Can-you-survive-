
#include <GL/glut.h>///#include <glut.h>
#include <stdio.h>
#include <GL/gl.h>///#include <glut.h>
#include <GL/glu.h>///#include <glut.h>
#include<bits/stdc++.h>
using namespace std;

 
int WINDOW_WIDTH ,WINDOW_HEIGHT;

int playerResult=0;
float Xspeed,Yspeed=1; 
float delta=1; 




struct RECTA
{ 
        float left,top,right,bottom; 
};

RECTA ball={-700,40,-680,60};
RECTA ball2={-800,70,-820,90};
RECTA wall ;
RECTA player_1 ={0,490,40,500}; 
int main_count=3;
int check;

double x1, x2, y3, y2,x1_prev,x2_prev,y1_prev,y2_prev;
double count1=0;
double count2=0;

double tx,san,tej,l1,l2,l3,l4,l5,l6,p1,man_y,man_y_duck;
int flag,flag2,flag3,flag_ball=1,flag_man_2=0,flag_man=0,flag_man_3=0,flag_man_duck=0;

//FUNCTION TO DRAW THE OBJECT (BALL)

void DrawRectangle(RECTA  rect) 
{ 
        glBegin(GL_QUADS); 
        glVertex2f(rect.left,rect.bottom);     
        glVertex2f(rect.right,rect.bottom); 
        glVertex2f(rect.right,rect.top); 
        glVertex2f(rect.left,rect.top); 
        glEnd(); 
}
//PROCESS KEYS FOR MOVEMENT
//F FOR JUMP
//G FOR DUCK
//S AND D FOR HAND MOVEMENTS


void processKeys(unsigned char key, int x, int y)
{
  switch(key)
  {
    case 'f':
      //cout<<"ho";
      flag_man=1;
      glutPostRedisplay();
      break;
    
    case 'g':
      flag_man_duck=1;
      glutPostRedisplay();
      break;
    case 's': //if s pressed than right hand movement
    // DrawRectangle(ball);
    if(flag2)
    {
      l4=-250;
      flag2=0;
    }
    else
    {
      l4=-100;
      flag2=1;
    }
    glutPostRedisplay();
    break;

    case 'd': //if d pressed than left hand movement
    if(flag2)
    {
      l5=-250;
      flag2=0;
    }
    else
    {
      l5=-100;
      flag2=1;
    }
    glutPostRedisplay();
    break;
  }
}
//ARROW KEYS FOR THE MOVEMENT OF BODY
//LEFT ARROW FOR THE LEFT MOVEMENT
//ROGHT ARROW KEY FOR THE RIGHT MOVEMENT
void specialkey(int key,int x,int y)
{
  switch(key)
  {
    
    case GLUT_KEY_RIGHT:  // left arrow is pressed
    flag3=1;

    if(flag==0){
      l1=l1+20; //l1 is left pivot l2 is middle pivot and l3 is right pivot 
      
      l2=l2+10;

        if(abs(l3-l1)>=150)
        {
          
          flag=1;
        }
      }
    else if(flag==1)
    {
      l3=l3+20;
      l2=l2+10;
      if(abs(l3-l1)>=150)
      {
        
        flag=0;
      }
    }

    glutPostRedisplay();
    break;
    case GLUT_KEY_LEFT:  // left arrow is pressed
      flag3=0;
      if(flag==0){
      l1=l1-20;
      
      l2=l2-10;

        if(abs(l3-l1)>=150)
        {
          
          flag=1;
        }
      }
    else if(flag==1)
    {
      l3=l3-20;
      //l5=l5-30;
      l2=l2-10;
      if(abs(l3-l1)>=150)
      {
        
        flag=0;
      }
    }

    glutPostRedisplay();
    break;
    
    
    
  }
}
//FUNCTION TO DRAW THE CIRCLE

void draw_circle(double r)
{

  double x, y, a, b;
  double h;
  double x_prev;
  double y_prev;

  h = 1-r;
  x=0;
  y=r;
  double shift = 250;
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  while(y > x)  
  {
    x_prev = x;
    y_prev = y;
    if(h<0)
    {
      x++;
      h = h + 2*x_prev + 3;
    }
    
    else
    {
      x++;
      y--;
      h = h + 2*(x_prev - y_prev) + 5;
    }
    glVertex2f(x+l2-p1, y+man_y+man_y_duck);
    
    
    glVertex2f(y+l2-p1, x+man_y+man_y_duck);
    
    
    glVertex2f(y+l2-p1, -x+man_y+man_y_duck);
    
    
    glVertex2f(x+l2-p1, -y+man_y+man_y_duck);
    
    
    glVertex2f(-x+l2-p1, -y+man_y+man_y_duck);
    
    
    glVertex2f(-y+l2-p1, -x+man_y+man_y_duck);
    
    
    glVertex2f(-y+l2-p1, x+man_y+man_y_duck);
    
    
    glVertex2f(-x+l2-p1, y+man_y+man_y_duck);
    
  }
  glEnd();
  glFlush();
}

//FUNCTION TO DRAW THE MAN 

void man_drawing(void)
{

  //glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(1);
  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 0.2);
  ////////circle drawing////////////////////
  draw_circle(100);
  glEnd();
  
  

  
  ////////////////main body/////////////////////////////////
  glBegin(GL_LINES);
  glColor3f(0.0, 1.0, 1.0);
  glVertex2f(l2-p1, -100+man_y);
  glVertex2f(l2-p1, -200+man_y);
  glEnd();
  ////////////////////arms drawing////////////////////////////////
  glBegin(GL_LINES);
  glColor3f(1.0, 0.5, 0.0);
  glVertex2f(l2-p1, -150+man_y);
  glVertex2f(l1-p1, l4+man_y);
  glEnd();
  glBegin(GL_LINES);

  glVertex2f(l2-p1, -150+man_y);
  glVertex2f(l3-p1, l5+man_y);
  glEnd();
  ////////////////////legs drawing///////////////////
  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(l2-p1, -200+man_y);
  glVertex2f(l1-p1, y3+man_y);
  
   
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.2, 0.2, 1.0);
  glVertex2f(l2-p1, -200+man_y);
  glVertex2f(l3-p1, y2+man_y);


     
  glEnd();
  if(flag3==1)
  { 
    ////////////////for foot///////////////////////

    glBegin(GL_POLYGON);  
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(4.0);

    glVertex2d(l3-p1, y2+man_y);
    glVertex2d(l3+40-p1,y2+man_y);
    glVertex2d(l3-p1, y2+10+man_y);
    glVertex2d(l3+40-p1, y2+10+man_y);

  
    glEnd();

    glBegin(GL_POLYGON);  
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(4.0);

    glVertex2d(l1-p1, y2+man_y);
    glVertex2d(l1+40-p1,y2 +man_y);
    glVertex2d(l1-p1, y2+10+man_y);
    glVertex2d(l1+40-p1, y2+10+man_y);
    
    
    glEnd();

    /////////////for eyes///////////////////
    glBegin(GL_LINES);
  
    glVertex2f(-20+l2-p1, 20+man_y+man_y_duck);
    glVertex2f(0+l2-p1, 20+man_y+man_y_duck);
    glEnd();


    glBegin(GL_LINES);

    glVertex2f(30+l2-p1, 20+man_y+man_y_duck);
    glVertex2f(50+l2-p1, 20+man_y+man_y_duck);
    glEnd();
    //////////////////////////////////////for nose///////////////////////
    glBegin(GL_LINES);

    glVertex2f(l2+20-p1, -30+man_y+man_y_duck);
    glVertex2f(l2+20-p1, -50+man_y+man_y_duck);
    glEnd();}

  

    
    //for foot left or right
  if(flag3==0){  
    glBegin(GL_POLYGON);  
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(4.0);

    glVertex2d(l3-p1, y2+man_y);
    glVertex2d(l3-40-p1,y2 +man_y);
    glVertex2d(l3-p1, y2+10+man_y);
    glVertex2d(l3-40-p1, y2+10+man_y);

  
    glEnd();

    glBegin(GL_POLYGON);  
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(4.0);

    glVertex2d(l1-p1, y2+man_y);
    glVertex2d(l1-40-p1,y2 +man_y);
    glVertex2d(l1-p1, y2+10+man_y);
    glVertex2d(l1-40-p1, y2+10+man_y);
    
    
    glEnd();


    glBegin(GL_LINES);
    /////////////////for eyes/////////////////////
    glVertex2f(-60+l2-p1, 20+man_y+man_y_duck);
    glVertex2f(-40+l2-p1, 20+man_y+man_y_duck);
    glEnd();


    glBegin(GL_LINES);

    glVertex2f(0+l2-p1, 20+man_y+man_y_duck);
    glVertex2f(-20+l2-p1, 20+man_y+man_y_duck);
    glEnd();
    ////////////////for nose///////////////////////////
    glBegin(GL_LINES);

    glVertex2f(l2-20-p1, -30+man_y+man_y_duck);
    glVertex2f(l2-20-p1, -50+man_y+man_y_duck);
    glEnd();

  } 
  ////////////////bottom path//////////////////////////
  glBegin(GL_POLYGON);  
  glColor3f(1.0f,0.0f,0.0f);
  glPointSize(4.0);

  glVertex2d(-1000, -300);
  glVertex2d(-1000, -500);
  glVertex2d(1000, -500);
  glVertex2d(1000, -300);
  
  
  glEnd();
  

  glFlush();
}





//TIMER FUNCTION TO AUTOMATICALLY MOVE OBJECTS WITHOUT PROCESS KEYS

void Timer(int v) 
{ 
  if(flag_man==1)
        {
          if(man_y<700 && flag_man_2==0)
            {
              man_y+=20;
            }
          if(man_y>=700)
            flag_man_2=1;
          if(flag_man_2==1 && man_y>0)
            man_y-=20;
          if(man_y<=0)
            {
              flag_man_2=0;
              flag_man=0;
            }
        }
    if(flag_man_duck==1)
    {
      if(man_y_duck>-250 && flag_man_3==0)
      {
        man_y_duck-=7;
      }
      if(man_y_duck<=-250)
        flag_man_3=1;
      if(man_y_duck<=0 && flag_man_3==1)
      {
        man_y_duck+=7;
      }
      if(man_y_duck>=0)
      {
        flag_man_3=0;
        flag_man_duck=0;
      }
    }
        if(ball.right>=wall.right)
        {
          flag_ball=0;
        }
        if(ball.left<=wall.left)
        {
          flag_ball=1;
        }
        //cout<<"br "<<ball.right<<" wr "<<wall.right<<endl;
        //cout<<flag_ball<<endl;
        if(flag_ball==1){

                ball.left+=Xspeed; 
                ball.right+=Xspeed;

          }
        else
        {
          //cout<<"flag 0 hua"<<endl;
            ball.left-=Xspeed; 
                ball.right-=Xspeed;
        } 
        //ball.top+=Xspeed; 
        //ball.bottom+=Xspeed; 
 
        glutTimerFunc(1,Timer,1);
}


int check_collision()
{
 if((100+l2-p1)>(ball.left) && (ball.left)>(-100+l2-p1))
  {
    if(ball.top<100+man_y+man_y_duck && ball.top>-200+man_y+man_y_duck)
    {
      return 1;
    }
    else
      return 0;
  }
  else
    return 0;


    

}
 
// OpenGL Setting
void Setting(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

// OnWindowResize 
void reshape (int w, int h)
{
  WINDOW_WIDTH =w ;
  WINDOW_HEIGHT =h ;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (-1000, 1000, -1000, 1000);


   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity ();

}

string str;

//RENDER FUNCTION THAT WILL BE CALLED AGAIN AND AGAIN
void Render()
{
  count2+=0.05;
	glClear(GL_COLOR_BUFFER_BIT );
	glLoadIdentity();
  glColor3f( 1, 1, 1 );
  glRasterPos2f(-900, 900);

  if(main_count==3)
    {
    str="3 lives left";
    for (int i = 0; i < str.length(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
  }
  }

  if(main_count==2)
    {
    str="2 lives left";
    for (int i = 0; i < str.length(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
    }
  }
  if(main_count==1)
    {
    str="1 lives left";
    for (int i = 0; i < str.length(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
    }
    }
  if(main_count==0)
    {
      cout<<"**********************GAME OVER******************"<<endl;
      cout<<"___________YOUR SCORE_____________ "<<count2<<" __________________"<<endl;
      exit(0);
    }



	wall.left=wall.top=-1000;
	wall.right=1000;
	wall.bottom=1000;

	DrawRectangle(ball);
 
  man_drawing();
  //check_collision();
  if(check_collision())
  {
    count1++;

  }
  if(count1>check)
  {
    main_count--;
    count1=0;
  }
  
	glutSwapBuffers();
}

//MAIN FUNCTION THAT WILL BE EXECUTED FIRST
int main(int argc, char** argv)
{

  man_y_duck=0;
  man_y=0;
  p1=-700;
    flag3=0;
  l4=-250;
  l5=-250;
  flag2=0;
  l1=-60;
  l2=0;
  l3=60;
  
  flag=0;
  san=tej=0;
  
  y3=-300;

  y2=-300;
  int in;
  cout<<"-------------------Welcome to Survival Game----------------------------"<<endl;
  cout<<"Choose difficulty :-"<<endl;
  cout<<"1. Easy"<<endl;
  cout<<"2. Medium"<<endl;
  cout<<"3. Hard"<<endl;
  cout<<"4. Extreme"<<endl;
  cin>>in;
  Xspeed=in*10;
  if(in==1)
  {
    check=13;
  }
  if(in==2)
  {
    check=7;
  }
  if(in==3)
  {
    check=5;
  }
  if(in==4)
  {
    check=2;
  }

  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (795, 500); 
  glutInitWindowPosition (0, 0);
  glutCreateWindow ("Game");


  Setting ();



  glutDisplayFunc(Render); 
  glutIdleFunc(Render);

  glutTimerFunc(1,Timer,1);
  glutKeyboardFunc( processKeys );
  glutSpecialFunc(specialkey);
  glutReshapeFunc(reshape);




  glutMainLoop();
  return 0;
}
