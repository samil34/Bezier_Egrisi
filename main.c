#include <stdio.h>
#include <windows.h>  
#include <GL/glut.h>  

float result; //x veya y noktas�n�n sonucu

float C(float u, int p0, int p1, int p2){
	
	result = p0*(1-u)*(1-u) + p1*2*u*(1-u) + p2*u*u; //Bezier e�risinin genel form�l�d�r
	
	return result; //fonksiyon x veya y noktas�n�n sonucunu d�ner
}
 
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}
 
void display() {
	
	glClear(GL_COLOR_BUFFER_BIT);   //ekran� temizler //koordinat sistemi
   
   glBegin(GL_LINES); //koordinat sisteminin x eksenini �izmeye ba�lar         
      glColor3f(1.0f, 1.0f, 1.0f); //koordinat �izgisinin rengini verir //beyazd�r
      glVertex2f(-1.0f, 0.0f);   //verilen koordinatlar x y d�zleminde bir �izgi olu�turur
      glVertex2f(1.0f, 0.0f);
      
   glEnd(); //�izme i�lemi biter
   
   
   glBegin(GL_LINES);  // koordinat sistemidir   
      glColor3f(1.0f, 1.0f, 1.0f); //koordinat �izgisinin rengini verir //beyazd�r
      glVertex2f(0.0f, 0.90f);		//verilen koordinatlar x y d�zleminde bir �izgi olu�turur
      glVertex2f(0.0f, -0.90f);
      
   glEnd();   //�izme i�lemi biter
   
   
   
   	float p[3][2] = {{0,0},{1,2},{4,0}}; //soruda verilen noktalar�n matris halinde yaz�lm�� �eklidir
   	
	float x,y;//x ve y eksenleridir
   	float a[3][3]; //verilen noktalar�n koordinatlar�n� ge�ici de�i�ken de tutuyoruz
   	
   	float i = 0;
   	glColor3f(1.0, 1.0, 0.0); //bezier e�risinin rengini olu�turuyoruz
   	
   	glBegin(GL_LINE_STRIP);
   	for(i=0.0; i <= 1.0; i+= 0.01 ){ //for d�ng�s� ile e�riyi �iziyoruz
   		
   		 x = C(i,p[0][0],p[1][0],p[2][0]); //fonksiyona g�nderilen e�rinin x koordinat�
		 y = C(i,p[0][1],p[1][1],p[2][1]); //fonksiyona g�nderilen e�rinin y koordinat�
		 
		 a[0][0] = x/10;
		 a[1][1] = y/10;
   		//printf("%f\n",a[0][0]);
   		glVertex2f(a[0][0], a[1][1]); //�izme i�lemi
	   }
   	glEnd();
   	
	
	float u = 0;
	 x = C(u,p[0][0],p[1][0],p[2][0]); //tekrar fonsiyona g�nderilir ve noktalar �izilir
	 y = C(u,p[0][1],p[1][1],p[2][1]); 
 
 	glPointSize(4.0f); //(0,0) noktas�
 	glBegin(GL_POINTS);//(x,y) -> (0,0) olacak           
      glColor3f(1.0f, 0.0f, 0.0f); //noktan�n rengini verir //k�rm�z� rengi veriri
      glVertex2f(x,y); //��genin x y koordinat noktalar� verilir
    
	glEnd();
   
   
    u = 1;
    x = C(u,p[0][0],p[1][0],p[2][0]);
	y = C(u,p[0][1],p[1][1],p[2][1]); //(x,y) -> (4,0) olacak
    
    a[0][0] = (float)x/10;
    
    glBegin(GL_POINTS);//(x,y) -> (4,0) olacak            
      glColor3f(1.0f, 0.0f, 0.0f); //noktan�n rengini verir //k�rm�z� rengi verir
      glVertex2f(a[0][0],0.0); //��genin x y koordinat noktalar� verilir
       
   glEnd();
   
   p[1][0] = (float)p[1][0] / 10;
   p[1][1] = (float)p[1][1] / 10;
   glBegin(GL_POINTS);// (x,y) -> (1,2)         
      glColor3f(1.0f, 0.0f, 0.0f); //noktan�n rengini verir 
      
	  glVertex2f(p[1][0],p[1][1]); //noktan�n x y koordinat noktalar�n� �izer
       
   glEnd();
   
   
 	glBegin(GL_POINTS);    
      glColor3f(0.0f, 1.0f, 0.0f); //noktan�n rengini verir 
      glVertex2f(0.1,0.0); //noktan�n x y koordinat noktalar�n� �izer
       
   glEnd();
   
    glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //��genin rengini verir //ye�il rengi veriri
      
	  glVertex2f(0.2,0.0); //noktan�n x y koordinat noktalar�n� �izer
       
   glEnd();
   
    glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //noktan�n rengini verir //ye�il rengi veriri
      
	  glVertex2f(0.3,0.0); //noktan�n x y koordinat noktalar�n� �izer
       
   glEnd();
   
   glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //noktan�n rengini verir //ye�il rengi veriri
      
	  glVertex2f(0.0,0.1); //noktan�n x y koordinat noktalar�n� �izer
       
   glEnd();
   
   
   glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //noktan�n rengini verir //ye�il rengi veriri
      
	  glVertex2f(0.0,0.2); //��genin x y koordinat noktalar�n� �izer
       
   glEnd();
 
 
   glFlush();  //�izimi s�f�rl�yor.
}
 

//olu�turulan pencerenin geni�li�i ve y�ksekli�i yeniden boyutland�r�ld�   
void reshape(GLsizei width, GLsizei height) {  
    // Yeni pencerenin en boy oran�n� hesaplar
   if (height == 0) height = 1;                // 0'a b�lmeyi �nlemek i�in
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // G�r�nt� alan�n� yeni pencereyi kaplayacak �ekilde ayarlanmas�
   glViewport(0, 0, width, height);
 
   // K�rpma alan�n�n en boy oran�n� g�r�nt� alan�na uyacak �ekilde ayarlar
   glMatrixMode(GL_PROJECTION);  // Projeksiyon matrisinde �al��mak i�in
   glLoadIdentity();             // Projeksiyon matrisini s�f�rlamak
   if (width >= height) {
     // en boy> = 1, y�ksekli�i -1'den 1'e, daha b�y�k geni�likle ayarlar
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // en boy oran� <1, geni�li�i -1'e 1'e ayarlar, daha b�y�k y�kseklik
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // glutu ba�latma fonksiyonu //glut g�rselle�tirme fonksiyonu
   glutInitWindowSize(600, 400);   //pencerenin  b�y�kl���
   glutInitWindowPosition(50, 50); //pencerenin ekran�n�z�n neresinde ��kaca��
   glOrtho(0.0, 10.0, 0.0 ,10.0,-1.0, 50.0);
   glutCreateWindow("Odev_2_1180505014_�amil_Akp�nar");  // pencereye bir ba�l�k verilir
   glutDisplayFunc(display);       // display fonsiyonu �a�r�l�r
   glutReshapeFunc(reshape);       // pencerenin yeniden boyutland�r�ld��� fonsiyon �a�r�l�r
   initGL();                       // OpenGl i ba�latmam�z
   glutMainLoop();                 // //d�ng� i�lemine al�yor
   return 0;
}
