//Algoritmo de bresenham en devcpp
#include <iostream>
#include <cmath>
#include<Windows.h>
#include<time.h>
int end = 0;
using namespace std;

void calcularlinea(int x0, int y0, int x1, int y1,int array[100][2],int& size) {
    int dx = abs(x1 - x0); //diferencia entre los dos puntos (ej: 10-5 es igual a 5 puntos entremedio)
    int dy = abs(y1 - y0); //diferencia entre los dos puntos
    int sx = (x0 < x1) ? 1 : -1; //saber si hay que sumar o restar x, este valor siempre sera 1 o -1
    int sy = (y0 < y1) ? 1 : -1;//saber si hay que sumar o restar y, este valor siempre sera 1 o -1
    int err = dx - dy; //error acumulado, si la linea calculada se sale mucho de la linea dibujada, este numero aumentará
	int i=0;
    while (true) {     
		
		
		if (x0 == x1 && y0 == y1) break; //cuando hayan terminado todos los puntos intermedios se termina el bucle 
        int e2 = 2 * err; 
        if (e2 > -dy) { 
            err -= dy;
            x0 += sx; //avanza en el eje x
        }
        if (e2 < dx) {
            err += dx; 
            y0 += sy; //avanza en el eje y
        }
        
        array[size][0]=x0;
    	array[size][1]=y0;
    	
    	size++;
	}
}

int setpos(int x, int y) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}
/*
	Colores del texto (FOREGROUND_):
	FOREGROUND_BLUE
	FOREGROUND_GREEN
	FOREGROUND_RED	
	FOREGROUND_INTENSITY
	
	Colores del fondo (BACKGROUND_):
	BACKGROUND_BLUE
	BACKGROUND_GREEN
	BACKGROUND_RED
	BACKGROUND_INTENSITY
*/
int setcolor(WORD color) { //CAMBIAR COLOR	
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, color);
}
void hidecursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

int mostrarlinea(int array[100][2],int& size)
{
	
 	for(int i=0;i<size;i++)//y
	{
		for(int k=0;k<=60;k++)//x
		{
			setpos( array[i][0], array[i][1]);
		
			
				
				cout<<"#";
				
			
		}
		
	}
	
}


int main() {
srand(time(NULL));	

		//tamaño ventana
	    SMALL_RECT rect;
	    COORD coord;
	    coord.X = 60; // Define X
	    coord.Y = 30; // Define Y 
	
	    rect.Top = 0;
	    rect.Left = 0;
	    rect.Bottom = coord.Y-1; 
	    rect.Right = coord.X-1; 
	
	    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleScreenBufferSize(hwnd, coord); 
	    SetConsoleWindowInfo(hwnd, TRUE, &rect); 
	    SetConsoleTitle("");
  		hidecursor();

    int size=0;
    int a[]={12,20}; 
	int b[]={2,1}; 	
	int c[]={56,22}; //x,y
	
	int linea1[100][2];
	int linea2[100][2];
	int linea3[100][2];
	//calcular y mostrar punto a,b
	calcularlinea(a[0],a[1] , b[0], b[1],linea1,size); 
	mostrarlinea(linea1,size);
	//calcular y mostrar punto a,c
	size=0;
	calcularlinea(a[0],a[1], c[0], c[1],linea2,size);
	mostrarlinea(linea2,size); 
	//calcular y mostrar punto b,c
	size=0;
	calcularlinea(b[0],b[1], c[0], c[1],linea3,size);
	mostrarlinea(linea3,size); 
	
	
	
	
/*	
int size=sizeof(lineas)/sizeof(lineas[0]);
 	for(int i=0;i<=size-1;i++)//y
	{
		for(int k=0;k<=60;k++)//x
		{
			setpos( lineas[i][0], lineas[i][1]);
			if(lineas[i][0]!=0 and lineas[i][1]!=0)
			{
				
				cout<<"#";
				
			}
		}
		cout<<endl;
	}
	setpos(0,coord.Y-1);
	*/

	
    while (!end) 
	{
     

    }
    cin.get();
    return 0;
} 


