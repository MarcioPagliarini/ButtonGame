//Desenvolvido por Nate Robins, modificado por Isabel Siqueira da Silva!
// MOdificado em 27/05/2009 por Mozart Lemos de Siqueira 
// adicionadas as funções ROLL, ELEVATION e AZIMUTH com as 
// Teclas ´r´, ´e´ e  ´a´ respectivamente
// Use as setas para mover os objetos!!!

//exemplo de programa para importar objetos 3D do Blender, 

// Para o trabalho com projeto, insira a linha:
// -lopengl32 -lglu32 -lglut32 
// no menu do DevCpp "Projeto" em "Opções de projeto" na aba "Parâmetro"
// no campo "Linker": 

#include <gl/glut.h>
#include "glm.h"

#define PI 3.1415926535897932384626433832795

GLMmodel* pmodelo = NULL;
GLMmodel* pmodelo2 = NULL;
GLint angulo1 = 0;
GLint angulo2 = 0;
GLfloat eyex=2.0, eyey=0.5, eyez=5.0;
//******************************************************************************
void Inicio(void) {
    glClearColor(0.8, 0.8, 0.8, 1.0);	
    
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50.0,1,1.0,30.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Chama a câmera, passando parâmetros
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);
}
//******************************************************************************
void LuzMaterial() {  
    //Definição das propriedades dos materiais
    float ambiente[] = {0.7f, 0.7f, 0.7f, 1.0f}; //Cinza
    float difusa[] = {0.6f, 0.6f, 0.6f, 1.0f}; 
    float especular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float brilho[] = {50.0f};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difusa);
    glMaterialfv(GL_FRONT, GL_SPECULAR, especular);
    glMaterialfv(GL_FRONT, GL_SHININESS, brilho);
    
    //Definição das propriedades das fontes de luz
    GLfloat intensidade_luz[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat posicao_luz[] = {2.0f, 6.0f, 3.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);
    glLightfv(GL_LIGHT0, GL_AMBIENT, intensidade_luz);
}

//******************************************************************************
void importaObj(void)
{
    if (!pmodelo) {
        pmodelo = glmReadOBJ("data/rose+vase.obj");
        if (!pmodelo) exit(0);
        glmUnitize(pmodelo);
        glmFacetNormals(pmodelo);
        glmVertexNormals(pmodelo, 90.0);
    }
    
    glmDraw(pmodelo, GLM_SMOOTH | GLM_MATERIAL);
}
//******************************************************************************
void importaObj2(char * objeto)
{
    if (!pmodelo2) {
        pmodelo2 = glmReadOBJ("data/f-16.obj");
        if (!pmodelo2) exit(0);
        glmUnitize(pmodelo2);
        glmFacetNormals(pmodelo2);
        glmVertexNormals(pmodelo2, 90.0);
    }
    
    glmDraw(pmodelo2, GLM_SMOOTH | GLM_MATERIAL);
}
//******************************************************************************
void DefineAmbiente(void)
{
    //Trata oclusão de superfícies
    glEnable(GL_DEPTH_TEST); 
    
    LuzMaterial();
    
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0); 
      
   	//Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    
    //Seta modelo de sombreamento
    glShadeModel(GL_SMOOTH);
    
    //Normaliza vetores para sombreamento
    glEnable(GL_NORMALIZE);      

}
//******************************************************************************
void DesenhaCena(void) {
    //Limpa a janela e habilita o teste para eliminar faces posteriores
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	DefineAmbiente();
	
    glBegin(GL_LINES);
       glColor3f(1.0,0.0,0.0); //eixo X vermelho
       glVertex3f(-500.0,0.0,0.0);
       glVertex3f(500.0,0.0,0.0);
       glColor3f(0.0,0.4,0.0); //eixo Y verde
       glVertex3f(0.0,-500.0,0.0);
       glVertex3f(0.0,500.0,0.0);
       glColor3f(0.0,0.0,1.0); //eixo Z azul
       glVertex3f(0.0,0.0,-500.0);
       glVertex3f(0.0,0.0,500.0);
    glEnd();
     
   
   
    glColor3f(0.0,0.4,0.0);
    glBegin(GL_QUADS);
        glVertex3f(3,-1,3);
        glVertex3f(3,-1,-3);
        glVertex3f(-3,-1,-3);
        glVertex3f(-3,-1,3);
    glEnd();
    
       
    glPushMatrix();
       glRotatef(angulo1,0,1,0);
       glRotatef(angulo2,1,0,0);
       //glScalef(2,2,2);
       importaObj();
    glPopMatrix();
    
    
    glPushMatrix();
       glRotatef(angulo1,1,0,0);
       glRotatef(angulo2,0,1,0);
       glTranslatef(1.0,0.0,0.0);
       importaObj2("data/f-16.obj");
    glPopMatrix();

    glPushMatrix();
       glRotatef(angulo1,1,0,0);
       glRotatef(angulo2,0,1,0);
       glTranslatef(-1.0,0.0,0.0);
       //importaObj2("data/al.obj");
    glPopMatrix();
    
    //Garante a execução dos comandos de desenho
    glutSwapBuffers();
}
//******************************************************************************
void TeclasEspeciais(int tecla, int x, int y) {
     if(tecla == GLUT_KEY_UP) { 
         angulo2 += 15;
     }
     if(tecla == GLUT_KEY_DOWN) {
         angulo2 -= 15;
     }
     if(tecla == GLUT_KEY_RIGHT) { //gira p direita
         angulo1 += 15;
     }
     if(tecla == GLUT_KEY_LEFT) { //gira p esquerda
         angulo1 -= 15;
     }
     glutPostRedisplay();          
}
//******************************************************************************
GLfloat angulo = 0;
void Teclado( unsigned char tecla, int x, int y )
{
     if(tecla == 'q')
     {
       eyex=2.0, eyey=0.5, eyez=5.0;
     }
     
     if (tecla == 'e') //elevation
     {
           eyez = 0;
           if (angulo <= (2*PI))
               angulo += PI/6; 
           else angulo = 0;
           
           eyex= 5 * cos(angulo);
           eyey= 5 * sin(angulo);
     }  
     if (tecla == 'r') //roll
     {
          eyex = 0;  
           if (angulo <= (2*PI))
               angulo += PI/6; 
           else angulo = 0;
           
           eyez= 5 * cos(angulo);
           eyey= 5 * sin(angulo);
     }        
     if (tecla == 'a') //azimuti
     {
          eyey = 0;  
           if (angulo <= (2*PI))
               angulo += PI/6; 
           else angulo = 0;
           
           eyex= 5 * cos(angulo);
           eyez= 5 * sin(angulo);
     }    
     if (tecla == 'x')
     {
           eyex += 1;
     }    
     if (tecla == 'X')
     {
           eyex -= 1;
     }    
     if (tecla == 'y')
     {
           eyey += 1;
     }    
     if (tecla == 'Y')
     {
           eyey -= 1;
     }    
     if (tecla == 'z')
     {
           eyez += 1;
     }    
     if (tecla == 'Z')
     {
           eyez -= 1;
     }    
     
     Inicio();
     glutPostRedisplay();   
}
//******************************************************************************
int main(int argc, char** argv)
{
    glutInit (&argc, argv);    
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700,600);
	glutCreateWindow("Importar Objetos 3D");
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(Teclado);
    glutDisplayFunc(DesenhaCena);
    Inicio();
 	glutMainLoop();	
}
