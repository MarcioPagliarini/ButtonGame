#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define ANDAR 20

float xis = -30;
float yio = 0;
float xis2 = 30;
float yio2 = 0;
float mov1= 0;
float mov2= 0;
float apx= 0;
float apy= 0;
GLUquadricObj *quadObj;



void campo (void)
{  
     glClear (GL_COLOR_BUFFER_BIT);
     glPointSize(5);
     glBegin(GL_LINE_LOOP);  //campo geral
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2i(-100,-65);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-100,65);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(100,65);
     glVertex2f(100,-65);
     glEnd();
     
     glBegin(GL_QUADS);  //arquibancadas de baixo
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2i(110,-66);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(110,-75);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(-110,-75);
     glVertex2f(-110,-66);
     glEnd();
     
     glBegin(GL_QUADS);  //arquibancadas de cima
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2i(110,66);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(110,75);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(-110,75);
     glVertex2f(-110,66);
     glEnd();
     
     glBegin(GL_QUADS);  //arquibancadas da esquerda
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2i(-110,-75);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(-110,75);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(-101,75);
     glVertex2f(-101,-75);
     glEnd();
     
     glBegin(GL_QUADS);  //arquibancadas da direita
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2i(110,-75);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(110,75);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(101,75);
     glVertex2f(101,-75);
     glEnd();
     
     glBegin(GL_QUADS);  //inter i
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2i(40,68);
     glVertex2f(42,68);
     glVertex2f(42,74);
     glVertex2f(40,74);
     glEnd();
     
     glBegin(GL_QUADS);  //inter n1
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2i(44,68);
     glVertex2f(46,68);
     glVertex2f(46,74);
     glVertex2f(44,74);
     glEnd();
     
     glBegin(GL_QUADS);  //inter n2
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(44,72);
     glVertex2i(46,74);
     glVertex2f(48,68);
     glVertex2f(46,70);
     glEnd();
     
     glBegin(GL_QUADS);  //inter n3
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2i(47,68);
     glVertex2f(49,68);
     glVertex2f(49,74);
     glVertex2f(47,74);
     glEnd();
     
     glBegin(GL_QUADS);  //inter t
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2i(52,68);
     glVertex2f(54,68);
     glVertex2f(54,74);
     glVertex2f(52,74);
     glEnd();
     
     glBegin(GL_QUADS);  //inter t2
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2i(51,72);
     glVertex2f(55,72);
     glVertex2f(55,74);
     glVertex2f(51,74);
     glEnd();
     
     glBegin(GL_QUADS);  //listra verde claro
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2i(-90,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(-70,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(-70,-64);
     glVertex2f(-90,-64);
     glEnd();
     
     glBegin(GL_QUADS);  //listra verde claro
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2i(-50,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(-30,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(-30,-64);
     glVertex2f(-50,-64);
     glEnd();
     
     glBegin(GL_QUADS);  //listra verde claro
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2i(-10,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(10,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(10,-64);
     glVertex2f(-10,-64);
     glEnd();
     
     glBegin(GL_QUADS);  //listra verde claro
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2i(50,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(30,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(30,-64);
     glVertex2f(50,-64);
     glEnd();
     
     glBegin(GL_QUADS);  //listra verde claro
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2i(70,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(90,64);
     glColor3f(0.0f, 0.3f, 0.0f);
     glVertex2f(90,-64);
     glVertex2f(70,-64);
     glEnd();
   
     glColor3f(1.0f, 1.0f,1.0f); 
     glBegin(GL_LINES);  //risca central
     glVertex2f (0,-65);
     glVertex2f (0, 65);
     glEnd();
     
          glColor3f(1.0f, 0.0f,0.0f); 
     glBegin(GL_LINES);  //risco da bandeirinha da esquerda alto
     glVertex2f (-100,65);
     glVertex2f (-100,72);
     glEnd();
     
     glColor3f(1.0f, 0.0f,0.0f); 
     glBegin(GL_LINES);  //risco da bandeirinha da direita alto
     glVertex2f (100,65);
     glVertex2f (100,72);
     glEnd();
     
     glColor3f(1.0f, 0.0f,0.0f); 
     glBegin(GL_LINES);  //risco da bandeirinha da esquerda baixo
     glVertex2f (-100,-65);
     glVertex2f (-100,-72);
     glEnd();
       
              glColor3f(1.0f, 0.0f,0.0f); 
     glBegin(GL_LINES);  //risco da bandeirinha da direita baixo
     glVertex2f (100,-65);
     glVertex2f (100,-72);
     glEnd();
          
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_LINE_LOOP);  //área da esquerda
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2i(-100,-30);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-100,30);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-65,30);
     glVertex2f(-65,-30);
     glEnd();
     
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_LINE_LOOP);  //área da direita
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2i(100,-30);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(100,30);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(65,30);
     glVertex2f(65,-30);
     glEnd();
     
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_LINE_LOOP);  //área pequena da esquerda
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2i(-100,-20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-100,20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-80,20);
     glVertex2f(-80,-20);
     glEnd();
     
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_LINE_LOOP);  //área pequena da direita
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2i(100,-20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(100,20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(80,20);
     glVertex2f(80,-20);
     glEnd();
     
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_LINE_LOOP);  //goleira da esquerda
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2i(-105,-20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-105,20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-100,10);
     glVertex2f(-100,-10);
     glEnd();
      
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_LINE_LOOP);  //goleira da direita
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2i(105,-20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(105,20);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(100,10);
     glVertex2f(100,-10);
     glEnd(); 
     
     glBegin(GL_POINTS); //penalti,bola
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(0,0);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(87,0.0);
     glVertex2f(-87,0.0);
     glEnd();
     
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_QUADS);  //bandeirinha canto superior esquerdo
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2i(-100,72);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(-100,74);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(-98,74);
     glVertex2f(-98,72);
     glEnd(); 
     
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_QUADS);  //bandeirinha canto superior direito
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2i(100,72);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(100,74);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(98,74);
     glVertex2f(98,72);
     glEnd();
     
     glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_QUADS);  //bandeirinha canto inferior direito
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2i(100,-72);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(100,-74);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(98,-74);
     glVertex2f(98,-72);
     glEnd();
     
          glColor3f(1.0f, 1.0f,1.0f);
     glBegin(GL_QUADS);  //bandeirinha canto inferior esquerdo
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2i(-100,-72);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(-100,-74);
     glColor3f(1.0f, 1.0f, 0.0f);
     glVertex2f(-98,-74);
     glVertex2f(-98,-72);
     glEnd();
     
     //desenha o círculo do meio de campo
      glColor3f(1.0,1.0,1.0);
      gluDisk(quadObj, 15.0, 15.5, 100, 100 );  
  
      glPushMatrix();
      //semi circulo da área esquerda
      glColor3f(1.0,1.0,1.0);
      glTranslatef(-75.0, 0.0, 0.0);
      gluPartialDisk(quadObj, 15.0 , 15.5, 100, 100, 41.0, 98.0 );     
     //semi circulo da área direita
     glColor3f(1.0,1.0,1.0);
     glTranslatef(150.0, 0.0, 0.0);
     gluPartialDisk(quadObj, 15.0 , 15.5, 100, 100, 220.0, 98.0 );
     glPopMatrix();
     
     glPushMatrix();
     //botao 1
     glColor3f(1.0,0.0,0.0);
     glTranslatef(0.0+xis2, 0.0+yio2, 0.0);
     gluDisk(quadObj, 1.0, 7.5, 100, 100 );    
     glPopMatrix();
     
     glPushMatrix();
     //botao 2
     glColor3f(0.0,0.0,1.0);
     glTranslatef(0.0+xis, 0.0+yio, 0.0);
     gluDisk(quadObj, 1.0, 7.5, 100, 100 );    
     glPopMatrix();  
       
      glPushMatrix();
       //bola
     glColor3f(0.0,0.0,0.0);
     glTranslatef(0.0+mov1, 0.0+mov2, 0.0);
     gluDisk(quadObj, 0.0, 2.0, 100, 100 );
     glutSwapBuffers();
     glPopMatrix();
     
    
   /* while (xis != mov1); 
    {
     if(xis==mov1){          
          mov1=mov1-2;
          }
     }
         
    */
     
     
          
     

}

//mexendo botão 1
void mexendo(int tecla, int x, int y)
{
  if(tecla == GLUT_KEY_LEFT)
  { 
  xis2 -=1;
   if(xis2==mov1 && yio2==mov2){          
     mov1=mov1-ANDAR;
          }
  }
  
  if(tecla == GLUT_KEY_UP){
  yio2 +=1;  
  }
  
  if(tecla == GLUT_KEY_RIGHT){
  xis2 +=1;
  }
  
  if(tecla == GLUT_KEY_DOWN){
  yio2 -=1;}
   
  glutPostRedisplay();   
}   
    
//mexendo botão 2
void botao2(unsigned char tecla2, int x, int y)
{
  if(tecla2 == 'a')
  { 
  xis -=1;
  }
  if(tecla2 == 'w'){
  yio +=1;
  }
  if(tecla2 == 'd'){
  xis +=1;
     if(xis==mov1){          
     mov1=mov1+ANDAR;
          }
  }
  
  if(tecla2 == 's'){
  yio -=1;}
   
  glutPostRedisplay();   
}       
     

void inicializacao (void) 
{    
glClearColor (0.0, 0.2, 0.0, 0.0);
glMatrixMode(GL_MODELVIEW);//matrix de transformação
glLoadIdentity();
glOrtho(-110.0,110.0,-75.0,75.0,-1.0,1.0);
}

int main(int argc, char *argv[])
{      
    quadObj = gluNewQuadric(); 
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (800, 500);
    glutCreateWindow ("Jogo de Botão");
    glutDisplayFunc (campo);
    glutSpecialFunc (mexendo);
    glutKeyboardFunc (botao2);
    inicializacao();
    glutMainLoop();
    return 0;
}
