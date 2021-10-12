/*

                   |---|  |--\  |---  |\   |  /---\  |
                   |   |  |__|  |___  | \  |  |      |
                   |   |  |     |     |  \ |  |  -+- |
                   \---/  |     |---  |   \|  \---|  \----

                            Aula 01 - OpenGl: Janelas  

 PrimeiroPrograma - Prof. Leandro Alves Neves
 Um programa OpenGL simples que abre uma janela GLUT
 Este c�digo est� baseado no Simple.c, exemplo 
 dispon�vel no livro "OpenGL SuperBible" e "OpenGl: uma abordagem pr�tica e objetiva" , 
 2nd Edition, de Richard S. e Wright Jr.*/

#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

void DISPLAY ();
//void Desenha();


// Inicializa par�metros de rendering
void DISPLAY ()
{   
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(1, 0, 0, 0);
    glMatrixMode(GL_PROJECTION); //Ativa matriz de proje��o
    glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo poss�veis erros.    
    gluOrtho2D(-200,200,-200,200);//Define tipo de proje��o (2D) e o tamanho
    glMatrixMode(GL_MODELVIEW);//Ativa matriz de visualiza��o
    glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo poss�veis erros.
	//Limpa a janela de visualiza��o com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combina��es de buffers, 
                                                         onde buffer � uma �rea de armazenamento para informa��es da imagem. 
                                                        Nesse caso, est� "limpando os buffers para suportarem anima��es */
   //Chamada para Fun��o  ou fun��es para desenhar o objeto/cena...
   //---------------------------------------------------------------- 
   //Desenha(); 
   glutSwapBuffers();

    
}
/*void Desenha()
{  int x=5, y=5;
   
  glColor3f(1,1,1);//Define uma cor para a primitiva	
  do{
      glBegin(GL_POINTS);
	   glVertex3f(x,y,0);
           glVertex3f(-x,y,0);
           glVertex3f(-x,-y,0);
	   glVertex3f(x,-y,0);
        glEnd();	//Executa os comandos OpenGL 
      x+=5; y+=5;
   }while(x<=200);
}
*/
int main(int argc,char **argv)
{
   glutInit(&argc, argv); // Initializes glut
    
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   /*Avisa a GLUT que modo de exibi��o deve ser usado quando a janela � criada. 
   //  Nesse caso, permite: uma �nica janela; cores compostas por Verm. Verde e Azul; e, */
   glutInitWindowSize(400,400);
   glutInitWindowPosition(100,100);
   glutCreateWindow("Aula 01 (OpenGL) - Meu Primeiro Programa");
   glutDisplayFunc(DISPLAY);
   glutMainLoop();
   return 0;
}
