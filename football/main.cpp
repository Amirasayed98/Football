#define STB_IMAGE_IMPLEMENTATION
#include <windows.h>  
#include <GL/glut.h> 
#include <iostream>
#include <stdlib.h>
#include <gl/stb_image.h>
using namespace std;

int refreshMills = 15; 
GLfloat angleRotat = 0.0f;
bool fullScreen;

float xSpeed = 3.0f;
float zSpeed = 0.0f;


float p2=-0.5f;
static int flag=1;

unsigned int texture;
int width, height, nrChannels;
unsigned char *data = NULL;

float matamb [] = {0.53f,0.76f,0.46f,1.0f},
	lightamb [] = {0.53f,0.76f,0.46f,1.0f};


void check (unsigned char *data);
void load ( int imgnum );
void circle1(GLfloat x,GLfloat y,GLfloat radius);

void circle1(GLfloat x, GLfloat y, GLfloat radius) 
  { 
    float angle;   
    glBegin(GL_POLYGON); 
	glColor3f(1.0,1.0,1.0);
    for(int i=0;i<100;i++) 
	{ 
        angle = i*2*(3.14/100); 
        glVertex2f(x+(cos(angle)*radius),y+(sin(angle)*radius)); 
    } 
    glEnd(); 
  }  

void drawBall()
{
	
    glColor3f(1.0f,1.0f,1.0f);
	

    glPushMatrix();
    glTranslatef(xSpeed, 0.5f, zSpeed);
	
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
}

void player(float z ,float x1  ,float x2 ,float y1 ,float y2,float toz)
{
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, toz);
	glBegin(GL_QUADS);
	//Goal 1
	  //back 
	
	  glColor3f(0.0f, 1.0f, 0.0f);     
      glVertex3f( x2,  y1, -z);
      glVertex3f( x2,  y2, -z);
      glVertex3f( x2,  y2, z);
      glVertex3f( x2,  y1,z);

	  //front
	  glColor3f(0.0f, 1.0f, 0.0f);     // Red
      glVertex3f( x1,  y1, -z);
      glVertex3f( x1,  y2,  -z);
      glVertex3f( x1,  y2,  z);
      glVertex3f( x1,  y1, z);
	  //top
	  glColor3f(0.0f, 1.0f, 0.0f);      //yellow
	  glVertex3f( x2, y2, -z);
      glVertex3f( x2, y2, z);
	  glVertex3f( x1, y2, z);
      glVertex3f( x1, y2, -z);

	  //left
	  glColor3f(0.0f, 1.0f, 0.0f);      //bule
	  glVertex3f( x2,  y1, -z);
      glVertex3f( x2,  y2, -z);
	  glVertex3f( x1,  y2, -z);
      glVertex3f( x1,  y1, -z);

	  //Right
	  glColor3f(0.0f, 1.0f, 0.0f);      //bule
	  glVertex3f( x2, y1, z);
      glVertex3f( x2, y2, z);
	  glVertex3f( x1, y2, z);
      glVertex3f( x1, y1, z);
    glEnd();
    glPopMatrix();
}

void update()
{
    if(flag)
        {
          
            if(zSpeed==0.0f||xSpeed==0.5f){
				xSpeed=3.0f;
				zSpeed==0.0f;
                flag=0;
			cout <<"game over";
        }
}
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);     
   glLoadIdentity();                 
   glTranslatef(1.5f, 0.0f, -7.0f);  
   glRotatef(angleRotat, 0.0f, 1.0f, 0.0f); 
   load(1);
   glBegin(GL_QUADS);  

   // Top face    
	  glTexCoord2d(0.0f,0.0f);
      glVertex3f( -3.5f, 0.25f,  2.5f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( 3.5f, 0.25f,  2.5f);
	  glTexCoord2d(1.0f,1.0f);
      glVertex3f( 3.5f, 0.25f, -2.5f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( -3.5f, 0.25f,-2.5f);
	  glEnd();
 
	  glBegin(GL_QUADS); 
      // Bottom face 
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f( 3.5f, -0.25f,  2.5f);
      glVertex3f(-3.5f, -0.25f,  2.5f);
      glVertex3f(-3.5f, -0.25f, -2.5f);
      glVertex3f( 3.5f, -0.25f, -2.5f);
 
       // Front face
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f( 3.5f,  0.25f, 2.5f);
      glVertex3f(-3.5f,  0.25f, 2.5f);
      glVertex3f(-3.5f, -0.25f, 2.5f);
      glVertex3f( 3.5f, -0.25f, 2.5f);
	 


 
      // Back face 
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f( 3.5f, -0.25f, -2.5f);
      glVertex3f(-3.5f, -0.25f, -2.5f);
      glVertex3f(-3.5f,  0.25f, -2.5f);
      glVertex3f( 3.5f,  0.25f, -2.5f);
 
      // Left face 
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f(-3.5f,  0.25f,  2.5f);
      glVertex3f(-3.5f,  0.25f, -2.5f);
      glVertex3f(-3.5f, -0.25f, -2.5f);
      glVertex3f(-3.5f, -0.25f,  2.5f);
 
      // Right face 
      glColor3f(1.0f, 1.0f, 1.0f);     
      glVertex3f(3.5f,  0.25f, -2.5f);
      glVertex3f(3.5f,  0.25f,  2.5f);
      glVertex3f(3.5f, -0.25f,  2.5f);
      glVertex3f(3.5f, -0.25f, -2.5f);

	  glEnd();

	   load(2);
	   glBegin(GL_QUADS);
	  //Goal 1
	  //back
	  glColor3f(0.4f,0.7f,1.0f);     
	  glTexCoord2d(0.0f,0.0f);
      glVertex3f( 3.5f,  0.25f, -1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( 3.5f,  1.0f, -1.0f);
	  glTexCoord2d(1.0f,1.0f);
      glVertex3f( 3.5f,  1.0f, 1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( 3.5f,  0.25f,1.0f);
 
	  //top
	  glColor3f(0.4f,0.7f,1.0f);
	  glTexCoord2d(0.0f,0.0f);
	  glVertex3f( 3.5f,  1.0f, -1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( 3.5f,  1.0f, 1.0f);
	  glTexCoord2d(1.0f,1.0f);
	  glVertex3f( 3.25f, 1.0f, 1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( 3.25f, 1.0f, -1.0f);

	  //left
	  glColor3f(0.4f,0.7f,1.0f);      
	  glTexCoord2d(0.0f,0.0f);
	  glVertex3f( 3.5f,  0.25f, -1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( 3.5f,  1.0f, -1.0f);
	  glTexCoord2d(1.0f,1.0f);
	  glVertex3f( 3.25f, 1.0f,-1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( 3.25f, 0.25f, -1.0f);

	  //Right
	  glColor3f(0.4f,0.7f,1.0f);     
	  glTexCoord2d(0.0f,0.0f);
	  glVertex3f( 3.5f,  0.25f, 1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( 3.5f,  1.0f, 1.0f);
	  glTexCoord2d(1.0f,1.0f);
	  glVertex3f( 3.25f, 1.0f,1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( 3.25f, 0.25f, 1.0f);
	  glEnd();   


	   load(2);
	   glBegin(GL_QUADS);

	  //Goal 2

	  //back
	  glColor3f(0.4f,0.7f,1.0f);     
	  glTexCoord2d(0.0f,0.0f);
      glVertex3f( -3.5f,  0.25f, -1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( -3.5f,  1.0f, -1.0f);
	  glTexCoord2d(1.0f,1.0f);
      glVertex3f( -3.5f,  1.0f, 1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( -3.5f,  0.25f,1.0f);
 
	  //top
	  glColor3f(0.4f,0.7f,1.0f);
	  glTexCoord2d(0.0f,0.0f);
	  glVertex3f( -3.5f,  1.0f, -1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( -3.5f,  1.0f, 1.0f);
	  glTexCoord2d(1.0f,1.0f);
	  glVertex3f( -3.25f, 1.0f, 1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( -3.25f, 1.0f, -1.0f);

	  //left
	  glColor3f(0.4f,0.7f,1.0f);      
	  glTexCoord2d(0.0f,0.0f);
	  glVertex3f( -3.5f,  0.25f, -1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( -3.5f,  1.0f, -1.0f);
	  glTexCoord2d(1.0f,1.0f);
	  glVertex3f( -3.25f, 1.0f,-1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( -3.25f, 0.25f, -1.0f);

	  //Right
	  glColor3f(0.4f,0.7f,1.0f);     
	  glTexCoord2d(0.0f,0.0f);
	  glVertex3f( -3.5f,  0.25f, 1.0f);
	  glTexCoord2d(1.0f,0.0f);
      glVertex3f( -3.5f,  1.0f, 1.0f);
	  glTexCoord2d(1.0f,1.0f);
	  glVertex3f( -3.25f, 1.0f,1.0f);
	  glTexCoord2d(0.0f,1.0f);
      glVertex3f( -3.25f, 0.25f, 1.0f);
	  glEnd();   


	  player(0.05f ,-1.25f  ,-1.125f ,0.25f,1.0f,2.0f);
	  player(0.05f , 0.25f  ,0.125f  ,0.25f ,1.0f,2.0f);
	  player(0.05f , 1.75f  ,1.875f  ,0.25f ,1.0f,0.0f);
	  player(0.05f , -1.125f,-1.25f  ,0.25f ,1.0f,-0.5f);
	  player(0.05f , 0.75f ,0.875f   ,0.25f  ,1.0f,-1.0f);
	  player(0.05f ,-2.75f ,-2.875f  ,0.25f ,1.0f,0.0f);
	  player(0.05f ,-3.0f  ,-3.125f  ,0.25f ,1.0f,1.4f);
	  player(0.05f , 2.25f , 2.125f  ,0.25f ,1.0f,1.5f);
	  player(0.05f , 0.0f  ,0.125f  ,0.25f  ,1.0f,-0.3f);
	  player(0.05f , 1.25f ,1.125f ,0.25f  ,1.0f,-2.0f);
	  player(0.05f ,-2.75f ,-2.875f ,0.25f ,1.0f,-2.0f);
	  player(0.05f , 0.75f ,0.875f ,0.25f  ,1.0f, 1.0f);
	  player(0.05f ,-0.75f ,-0.875f ,0.25f ,1.0f,0.75f);
	  player(0.05f ,-1.5f  ,-1.625f ,0.25f ,1.0f,1.25f);
	  player(0.05f ,-2.0f  ,-2.125f ,0.25f ,1.0f,-1.0f);
	  player(0.05f ,-1.0f  ,-1.125f ,0.25f ,1.0f,-1.5f);
	  player(0.05f , 1.25f ,1.125f ,0.25f  ,1.0f,-2.0f);
	  drawBall();
	  update();
 
	
	circle1(3.0,3.5,0.2);
	circle1(3.25,3.5,0.2);
	circle1(2.75,3.5,0.2);
	circle1(3.0,3.75,0.2);



	circle1(-3.0,3.5,0.2);
	circle1(-3.25,3.5,0.2);
	circle1(-2.75,3.5,0.2);
	circle1(-3.0,3.75,0.2);
	
	

   glutSwapBuffers();
   

   
}

void specialKeys(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_RIGHT: 
		  if(zSpeed>=-2.0001f)
          zSpeed -= 0.5f; break;
      case GLUT_KEY_LEFT: 
		  if(zSpeed<=2.0001f)
         zSpeed += 0.5f; break;
      case GLUT_KEY_UP:   
		  if(xSpeed<3.0f)
         xSpeed += 0.5f; break;
      case GLUT_KEY_DOWN:
		  if(xSpeed>=-2.9f)
         xSpeed -= 0.5f; break;
   }
	  if( key == GLUT_KEY_F1){
		fullScreen = !fullScreen;
		if(fullScreen)
			glutFullScreen();
		else{
			glutPositionWindow(10,30);
			glutReshapeWindow(1100, 700);
		}
	  }
   
}
void KeyPress(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
	if (key== ' '){
		angleRotat += 1.0f;
		}
	switch (key)
	{
	case 'a':
	case 'A':
		if(zSpeed>=-2.0001f)
		zSpeed -= 0.5f;
		break;
	case 'd':
	case 'D':
		if(zSpeed<=2.0001f)
		zSpeed += 0.5f;
		break;
	case 'w':
	case 'W':
		if(xSpeed>=-2.9f)
		xSpeed -= 0.5;
		break;
	case 'g':
	case 'G':
		if(xSpeed<3.0f)
		xSpeed += 0.5;
		break;

		  
	};
}




void timer(int value) {
   glutPostRedisplay();      
   glutTimerFunc(refreshMills, timer, 0); 
}

void reshape(GLsizei width, GLsizei height) {  
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();
   gluPerspective(35.0f, aspect, 0.1f, 100.0f);
   gluLookAt(
	    4,3.5,3,
	   0.5,0.0,-10,
	   0,5,0
	   );
   glMatrixMode(GL_MODELVIEW);
}

void initGL() {
   glClearColor(0.4f,0.7f,1.0f, 1.0f); 
   glEnable(GL_DEPTH_TEST);   
   glEnable(GL_TEXTURE_2D);
   glLightfv(GL_LIGHT0,GL_AMBIENT,lightamb);
	glMaterialfv(GL_FRONT,GL_AMBIENT,matamb);
   glShadeModel(GL_SMOOTH);   
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);            
   glutInitDisplayMode(GLUT_DOUBLE); 
   glutInitWindowSize(1100, 700);    
   glutCreateWindow("Football");          
   glutDisplayFunc(display); 
   glutSpecialFunc(specialKeys);
   glutKeyboardFunc(KeyPress);
   glutReshapeFunc(reshape);       
   initGL();                      
   glutTimerFunc(0, timer, 0);     
   glutMainLoop();                
   return 0;
}


void load ( int imgnum ){
	if( imgnum == 1){
		
		data= stbi_load("dd.bmp", &width, &height, &nrChannels, 0);
		check(data);
	}
	else if( imgnum == 2){
		
		data= stbi_load("555.bmp", &width, &height, &nrChannels, 0);
		check(data);
	}
}

void check (unsigned char *data){
	if (data)
		{
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
}
