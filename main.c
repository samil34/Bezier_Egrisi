#include <stdio.h>
#include <windows.h>  
#include <GL/glut.h>  

float result; //x veya y noktasýnýn sonucu

float C(float u, int p0, int p1, int p2){
	
	result = p0*(1-u)*(1-u) + p1*2*u*(1-u) + p2*u*u; //Bezier eðrisinin genel formülüdür
	
	return result; //fonksiyon x veya y noktasýnýn sonucunu döner
}
 
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}
 
void display() {
	
	glClear(GL_COLOR_BUFFER_BIT);   //ekraný temizler //koordinat sistemi
   
   glBegin(GL_LINES); //koordinat sisteminin x eksenini çizmeye baþlar         
      glColor3f(1.0f, 1.0f, 1.0f); //koordinat çizgisinin rengini verir //beyazdýr
      glVertex2f(-1.0f, 0.0f);   //verilen koordinatlar x y düzleminde bir çizgi oluþturur
      glVertex2f(1.0f, 0.0f);
      
   glEnd(); //çizme iþlemi biter
   
   
   glBegin(GL_LINES);  // koordinat sistemidir   
      glColor3f(1.0f, 1.0f, 1.0f); //koordinat çizgisinin rengini verir //beyazdýr
      glVertex2f(0.0f, 0.90f);		//verilen koordinatlar x y düzleminde bir çizgi oluþturur
      glVertex2f(0.0f, -0.90f);
      
   glEnd();   //çizme iþlemi biter
   
   
   
   	float p[3][2] = {{0,0},{1,2},{4,0}}; //soruda verilen noktalarýn matris halinde yazýlmýþ þeklidir
   	
	float x,y;//x ve y eksenleridir
   	float a[3][3]; //verilen noktalarýn koordinatlarýný geçici deðiþken de tutuyoruz
   	
   	float i = 0;
   	glColor3f(1.0, 1.0, 0.0); //bezier eðrisinin rengini oluþturuyoruz
   	
   	glBegin(GL_LINE_STRIP);
   	for(i=0.0; i <= 1.0; i+= 0.01 ){ //for döngüsü ile eðriyi çiziyoruz
   		
   		 x = C(i,p[0][0],p[1][0],p[2][0]); //fonksiyona gönderilen eðrinin x koordinatý
		 y = C(i,p[0][1],p[1][1],p[2][1]); //fonksiyona gönderilen eðrinin y koordinatý
		 
		 a[0][0] = x/10;
		 a[1][1] = y/10;
   		//printf("%f\n",a[0][0]);
   		glVertex2f(a[0][0], a[1][1]); //çizme iþlemi
	   }
   	glEnd();
   	
	
	float u = 0;
	 x = C(u,p[0][0],p[1][0],p[2][0]); //tekrar fonsiyona gönderilir ve noktalar çizilir
	 y = C(u,p[0][1],p[1][1],p[2][1]); 
 
 	glPointSize(4.0f); //(0,0) noktasý
 	glBegin(GL_POINTS);//(x,y) -> (0,0) olacak           
      glColor3f(1.0f, 0.0f, 0.0f); //noktanýn rengini verir //kýrmýzý rengi veriri
      glVertex2f(x,y); //üçgenin x y koordinat noktalarý verilir
    
	glEnd();
   
   
    u = 1;
    x = C(u,p[0][0],p[1][0],p[2][0]);
	y = C(u,p[0][1],p[1][1],p[2][1]); //(x,y) -> (4,0) olacak
    
    a[0][0] = (float)x/10;
    
    glBegin(GL_POINTS);//(x,y) -> (4,0) olacak            
      glColor3f(1.0f, 0.0f, 0.0f); //noktanýn rengini verir //kýrmýzý rengi verir
      glVertex2f(a[0][0],0.0); //üçgenin x y koordinat noktalarý verilir
       
   glEnd();
   
   p[1][0] = (float)p[1][0] / 10;
   p[1][1] = (float)p[1][1] / 10;
   glBegin(GL_POINTS);// (x,y) -> (1,2)         
      glColor3f(1.0f, 0.0f, 0.0f); //noktanýn rengini verir 
      
	  glVertex2f(p[1][0],p[1][1]); //noktanýn x y koordinat noktalarýný çizer
       
   glEnd();
   
   
 	glBegin(GL_POINTS);    
      glColor3f(0.0f, 1.0f, 0.0f); //noktanýn rengini verir 
      glVertex2f(0.1,0.0); //noktanýn x y koordinat noktalarýný çizer
       
   glEnd();
   
    glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //üçgenin rengini verir //yeþil rengi veriri
      
	  glVertex2f(0.2,0.0); //noktanýn x y koordinat noktalarýný çizer
       
   glEnd();
   
    glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //noktanýn rengini verir //yeþil rengi veriri
      
	  glVertex2f(0.3,0.0); //noktanýn x y koordinat noktalarýný çizer
       
   glEnd();
   
   glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //noktanýn rengini verir //yeþil rengi veriri
      
	  glVertex2f(0.0,0.1); //noktanýn x y koordinat noktalarýný çizer
       
   glEnd();
   
   
   glBegin(GL_POINTS);      
      glColor3f(0.0f, 1.0f, 0.0f); //noktanýn rengini verir //yeþil rengi veriri
      
	  glVertex2f(0.0,0.2); //üçgenin x y koordinat noktalarýný çizer
       
   glEnd();
 
 
   glFlush();  //çizimi sýfýrlýyor.
}
 

//oluþturulan pencerenin geniþliði ve yüksekliði yeniden boyutlandýrýldý   
void reshape(GLsizei width, GLsizei height) {  
    // Yeni pencerenin en boy oranýný hesaplar
   if (height == 0) height = 1;                // 0'a bölmeyi önlemek için
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Görüntü alanýný yeni pencereyi kaplayacak þekilde ayarlanmasý
   glViewport(0, 0, width, height);
 
   // Kýrpma alanýnýn en boy oranýný görüntü alanýna uyacak þekilde ayarlar
   glMatrixMode(GL_PROJECTION);  // Projeksiyon matrisinde çalýþmak için
   glLoadIdentity();             // Projeksiyon matrisini sýfýrlamak
   if (width >= height) {
     // en boy> = 1, yüksekliði -1'den 1'e, daha büyük geniþlikle ayarlar
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // en boy oraný <1, geniþliði -1'e 1'e ayarlar, daha büyük yükseklik
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);          // glutu baþlatma fonksiyonu //glut görselleþtirme fonksiyonu
   glutInitWindowSize(600, 400);   //pencerenin  büyüklüðü
   glutInitWindowPosition(50, 50); //pencerenin ekranýnýzýn neresinde çýkacaðý
   glOrtho(0.0, 10.0, 0.0 ,10.0,-1.0, 50.0);
   glutCreateWindow("Odev_2_1180505014_Þamil_Akpýnar");  // pencereye bir baþlýk verilir
   glutDisplayFunc(display);       // display fonsiyonu çaðrýlýr
   glutReshapeFunc(reshape);       // pencerenin yeniden boyutlandýrýldýðý fonsiyon çaðrýlýr
   initGL();                       // OpenGl i baþlatmamýz
   glutMainLoop();                 // //döngü iþlemine alýyor
   return 0;
}
