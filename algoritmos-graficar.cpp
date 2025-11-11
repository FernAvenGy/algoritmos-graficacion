// ENTREGA FINAL

#include <stdio.h>
#include <graphics.h>
#include <math.h>

//X=639  Y=479

// A1 - Linea
void linea(){
	float x1, y1, x2, y2, incr;
	int deltaX, deltaY, m, X, Y;
	bool ban1=true, ban2=true, banGrl=true, banIncr=true;
	
	//Solicitar las dos coordenadas (de incio y fin) y el incremento
	//Validacion de que las coordenadas sean diferentes
	while(banGrl==true){
		//Validacion de que la primera coordenada se encuentre dentro de los limites de la ventana grafica
		while(ban1==true){
			printf("Ingrese las coordenadas del primer punto\n");
			scanf("%f", &x1);
			scanf("%f", &y1);
			if((x1>0 && x1<=638) && (y1>0 && y1<=478)){
				ban1=false;
			}
			else{
				printf("Coordenadas fuera de los limites de la ventana\n");
			}
		}
		//Validacion de que la segunda coordenada se encuentre dentro de los limites de la ventana grafica
		while(ban2==true){
			printf("Ingrese las coordenadas del segundo punto\n");
			scanf("%f", &x2);
			scanf("%f", &y2);
			if((x2<0 || x2>=638) || (y2<0 || y2>=478)){
				printf("Coordenadas fuera de los limites de la ventana\n");
			}
			else{
				ban2=false;
			}

		}

		if(x1==x2 && y1==y2){
			printf("Las coordenadas son las mismas\n");
			ban1=true; 
			ban2=true;
		}
		else{
			banGrl=false;
		}
	}

	//Validacion de que el incremento sea positivo
	while(banIncr==true){
		printf("Ingrese el incremento\n");
		scanf("%f", &incr);
		if(incr<0){
			printf("El incremento no puede ser negativo\n");
		}
		else{
			banIncr=false;
		}
	}
	
	//Calculo de deltaX, deltaY y la pendiente
	deltaX = (x2-x1);
	deltaY = (y2-y1);

	// Caso particular de pendiente infinita (dibujar linea recta horizontal)
	if(deltaX==0){
		X = x1;Y = y1;
		int gd = DETECT, gm;
    	initgraph(&gd, &gm, (char *)"");
		while(Y<=y2){
			putpixel(X, Y, WHITE);
			Y = Y+incr;
		}
	}
	// Caso particular en el que la linea sea recta vertical
	else if(deltaY==0){
		X = x1;Y = y1;
		int gd = DETECT, gm;
    	initgraph(&gd, &gm, (char *)"");
		while(X<=x2){
			putpixel(X, Y, WHITE);
			X = X+incr;
		}
	}
	else{
		m = deltaY/deltaX;
	
		X = x1;
		Y = y1;
		
		int gd = DETECT, gm;
		initgraph(&gd, &gm, (char *)"");

		while(X<=x2){
			putpixel(X, Y, WHITE);
			X = X+incr;
			Y = Y+m;
		}
	}
	
	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");
	getch();
    closegraph();
}

// A2 - Linea con Punto medio 
void linea_pm(){
	float x1, y1, x2, y2, incr;
	float dX, dY, X, Y, incE, incNE, d;
	
	bool ban1=true, ban2=true, banGrl=true, banIncr=true;
	//Solicitar las dos coordenadas (de incio y fin) y el incremento
	//Validacion de que las coordenadas sean diferentes
	while(banGrl==true){
		//Validacion de que la primera coordenada se encuentre dentro de los limites de la ventana grafica
		while(ban1==true){
			printf("Ingrese las coordenadas del primer punto\n");
			scanf("%f", &x1);
			scanf("%f", &y1);
			if((x1<0 || x1>638) || (y1<0 || y1>478)){
				printf("Coordenadas fuera de los limites de la ventana\n");
			}
			else{
				ban1=false;
			}
		}
		//Validacion de que la segunda coordenada se encuentre dentro de los limites de la ventana grafica
		while(ban2==true){
			printf("Ingrese las coordenadas del segundo punto\n");
			scanf("%f", &x2);
			scanf("%f", &y2);
			if((x1<0 || x1>638) || (y1<0 || y1>478)){
				printf("Coordenadas fuera de los limites de la ventana\n");
			}
			else{
				ban2=false;
			}

		}

		if(x1==x2 && y1==y2){
			printf("Las coordenadas son las mismas\n");
			ban1=true; 
			ban2=true;
		}
		else{
			banGrl=false;
		}
	}

	//Validacion de que el incremento sea positivo
	while(banIncr==true){
		printf("Ingrese el incremento\n");
		scanf("%f", &incr);
		if(incr<0){
			printf("El incremento no puede ser negativo\n");
		}
		else{
			banIncr=false;
		}
	}
	
	
	dX = (x2-x1);
	dY = (y2-y1);

	// Caso particular de pendiente infinita (dibujar linea recta horizontal)
	if(dX==0){
		X = x1;Y = y1;
		int gd = DETECT, gm;
    	initgraph(&gd, &gm, (char *)"");
		while(Y<=y2){
			putpixel(X, Y, WHITE);
			Y = Y+incr;
		}
	}
	// Caso particular en el que la linea sea recta vertical
	else if(dY==0){
		X = x1;Y = y1;
		int gd = DETECT, gm;
    	initgraph(&gd, &gm, (char *)"");
		while(X<=x2){
			putpixel(X, Y, WHITE);
			X = X+incr;
		}
	}
	else{
		d = 2 * (dX-dY);
		incNE = 2*dY;
		incE = 2* (dY-dX);
		
		X = x1;
		Y = y1;
		
		int gd = DETECT, gm;
		initgraph(&gd, &gm, (char *)"");
		
		while(X < x2){
			if(d<0){
				d+=incE;
				X+=incr;
			}
			else{
				d+=incNE;
				X+=incr;
				Y+=incr;
			}
			
			putpixel(X, Y, 3);
		}
	}
	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");
	getch();
    closegraph();
	
}

// A3 - Circulo 
void circulo(){
	int gd = DETECT, gm;
	
	float r, x, y;
	float X = 320, Y=240; //centro del circulo
	bool banRad=true, banCen=true;

	//Pedir el rado y validar que sea positivo
	while(banRad==true){
		printf("Ingrese el radio\n");
		scanf("%f", &r);
		if(r<0){
			printf("El valor del radio debe ser positivo\n");
		}
		else if(r*2>=638 && r*2>=478){
			printf("El valor del radio supera los limites de la ventana\n");
		}
		else{
			banRad=false;
		}
	}
	while(banCen==true){
		//Pedir las coordenadas del centro y validarlas
		printf("Ingrese las coordenadas del centro del circulo\n");
		scanf("%f", &X);
		scanf("%f", &Y);
		if((X-r<0 || X+r>639) || (Y-r<0 || Y+r>479)){ 
			printf("Circulo fuera de los limites de la ventana\n");
		}
		else{
			banCen=false;
		}
	}

	x=r;
	y=0;
		
    initgraph(&gd, &gm, (char *)"");
	
	while(x >= y){
		y= sqrt((r*r) - (x*x));
		
		putpixel(X+x, Y+y, 3);
		putpixel(X-x, Y-y, 3);
		putpixel(X+x, Y-y, 3);
		putpixel(X-x, Y+y, 3);
		
		putpixel(X+y, Y+x, 3);
		putpixel(X-y, Y-x, 3);
		putpixel(X-y, Y+x, 3);
		putpixel(X+y, Y-x, 3);
		
		x--;
	}
  
	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");
	getch();
    closegraph();
	
}

// A4 - Circulo trigonometrico
void circulo_trig(){
	int gd = DETECT, gm;
	
	float r, x, y, theta=0;
	float X = 320, Y=240;
	
	bool banRad=true, banCen=true, banGrad=true;
	//Pedir el radio y validar que sea positivo
	while(banRad==true){
		printf("Ingrese el radio\n");
		scanf("%f", &r);
		if(r<0){
			printf("El valor del radio debe ser positivo\n");
		}
		else if(r*2>=638 && r*2>=478){
			printf("El valor del radio supera los limites de la ventana\n");
		}
		else{
			banRad=false;
		}
	}
	//Pedir las coordenadas del centro y validar que el círculo no salga de la ventana 
	while(banCen==true){
		printf("Ingrese las coordenadas del centro del circulo\n");
		scanf("%f", &X);
		scanf("%f", &Y);
		if((X-r<0 || X+r>639) || (Y-r<0 || Y+r>479)){ // ----------------------------------------------------------------- checar esta condicional
			printf("Circulo fuera de los limites de la ventana\n");
		}
		else{
			banCen=false;
		}
	}
	//Pedir los grados y validar que el valor este entre 0.1 y 15 
	while(banGrad==true){ // ---------------------------------------------------------------------------------------------- ver si esto sí funciona 
		int grados=0;
		printf("Ingrese los grados, valor recomendado:0\n");
		scanf("%f", &grados);
		if(grados>=0.1 || grados<=15.0){
			theta = (grados*M_PI)/180;
			banGrad=false;
		}
		else{
			printf("Los grados son invalidos\n");
		}
	}
	
	x=r*cos(theta);
	y=r*sin(theta);
	
    initgraph(&gd, &gm, (char *)""); 
    
	while(theta< M_PI/4){
		x=r*cos(theta);
		y=r*sin(theta);
		
		putpixel(X+x, Y+y, 3);
		putpixel(X+x, Y-y, 3);
		putpixel(X-x, Y-y, 3);
		putpixel(X-x, Y+y, 3);
		putpixel(X+y, Y+x, 3);
		putpixel(X-y, Y-x, 3);
		putpixel(X-y, Y+x, 3);
		putpixel(X+y, Y-x, 3);
				
		theta+= M_PI/100; // ---------------------------------------------------------------------------- cehcar fraccion de pi (que no sea tan pequeña)
	}

	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");
	getch();
    closegraph();
}

// A5 - Circulo punto medio
void circulo_pm(){
	int gd = DETECT, gm;
	
	float r, x, y, d;
	float X, Y; 
	
	bool banRad=true;
	//Pedir el radio y validar que sea positivo
	while(banRad==true){
		printf("Ingrese el radio\n");
		scanf("%f", &r);
		if(r<0){
			printf("El valor del radio debe ser positivo\n");
		}
		else{
			banRad=false;
		}
	}

	x=0;
	y=r;
	d=1-r;
	
    initgraph(&gd, &gm, (char *)""); 
    
    X=getmaxx()/2;
    Y=getmaxy()/2;

	putpixel(x, y, WHITE);
	while(x<=y){
		if(d<0){
			d+=2*x+3;
			x++;
		}
		else{
			d+=2*(x-y)+5;
			x++;
			y--;
		}
		
		putpixel(X+x, Y+y, WHITE);
		putpixel(X+x, Y-y, WHITE);
		putpixel(X-x, Y+y, WHITE);
		putpixel(X-x, Y-y, WHITE);
		putpixel(X+y, Y+x, WHITE);
		putpixel(X+y, Y-x, WHITE);
		putpixel(X-y, Y+x, WHITE);
		putpixel(X-y, Y-x, WHITE);				
	}
  	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");
	getch();
    closegraph();	
}

// A6 - Elipse
void elipse(){
	int gd=DETECT, gm;
	
	float h,k; //centro del elipse
	float x, y, r, R, raiz, incr;
	bool banCen=true, banIncr=true, banR=true, banr=true;;
	//Solicitar radio mayor y validacion de que sea positivo
	while(banR==true){
		printf("Ingrese el radio mayor\n");
		scanf("%f",&R);
		if(R<0){ printf("El radio mayor no puede ser negativo\n");}
		else{banR=false;}
	}
	//Solicitar radio menor y validacion de que sea positivo
	while(banr==true){
		printf("Ingrese el radio menor\n");
		scanf("%f",&r);
		if(r<0){ printf("El radio menor no puede ser negativo\n");}
		else{banr=false;}
	}

	//Solicitar incremento y validacion de que sea positivo
	while(banIncr==true){
		printf("Ingrese el incremento\n");
		scanf("%f", &incr);
		if(incr<0){ printf("El incremento no puede ser negativo\n");}
		else{banIncr=false;}
	}

	//solicitar las coordenadas del centro y validarlas
	while(banCen==true){
		printf("Ingrese las coordenadas del centro del elipse\n");
		scanf("%f", &h);
		scanf("%f", &k);
		if((h-R<0 || h+R>639) || (k-r<0 || k+r>479)){ // ----------------------------------------------------------------- checar esta condicional
			printf("Elipse fuera de los limites de la ventana\n");
		}
		else{
			banCen=false;
		}
	}
	
	x=R;
	y=0;
	
	
	initgraph(&gd, &gm, (char *)"");
	/*h=getmaxx()-1/2;
	k=getmaxy()-1/2;*/
	
	while(x<=R && x>=0)
	{
		y=sqrt((r*r)*(1-((x*x)/(R*R))));
		putpixel(h+x, k+y, WHITE);
		putpixel(h-x, k-y, WHITE);
		putpixel(h+x, k-y, WHITE);
		putpixel(h-x, k+y, WHITE);
		x-=incr;
	}
	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");
	getch();
	closegraph();
}

// A7 - Elipse trigonometrico 
void elipse_trig(){
	int gd=DETECT, gm;
	float x, y, r, R, raiz, theta=0;
	float h, k;
	
	bool banCen=true, banR=true, banr=true, banGrad=true;
	//Solicitar radio mayor y validacion de que sea positivo
	while(banR==true){
		printf("Ingrese el radio mayor\n");
		scanf("%f",&R);
		if(R<0){ printf("El radio mayor no puede ser negativo\n");}
		else{banR=false;}
	}
	//Solicitar radio menor y validacion de que sea positivo
	while(banr==true){
		printf("Ingrese el radio menor\n");
		scanf("%f",&r);
		if(r<0){ printf("El radio menor no puede ser negativo\n");}
		else{banr=false;}
	}

	//Pedir los grados y validar que el valor esté entre 0.1 y 15. Hacer conversión a radianes
	while(banGrad==true){ 
		int grados=0;
		printf("Ingrese los grados, valor recomendado:0\n");
		scanf("%f", &grados);
		if(grados>=0.1 || grados<=15.0){
			theta = (grados*M_PI)/180;
			banGrad=false;
		}
		else{
			printf("Los grados son invalidos\n");
		}
	}
	
	//Solicitar las coordenadas del centro y validarlas
	while(banCen==true){
		printf("Ingrese las coordenadas del centro del elipse\n");
		scanf("%f", &h);
		scanf("%f", &k);
		if((h-R<0 || h+R>639) || (k-r<0 || k+r>479)){
			printf("Elipse fuera de los limites de la ventana\n");
		}
		else{
			banCen=false;
		}
	}
	x=0;
	y=0;

	
	initgraph(&gd, &gm, (char *)"");
	/*h=getmaxx()-1/2;
	k=getmaxy()-1/2;*/
	
	while(theta <= M_PI*2)
	{
		x = R*cos(theta) + h;
		y = r*sin(theta) + k;
		putpixel(x, y, WHITE);

		theta+= M_PI/1000;
	}
	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");
	getch();
	closegraph();
}

// A8 - Elipse punto medio 
void elipse_pm(){
	int gd=DETECT, gm;
	
	float a, b, x, y, dl, dl2, dx, dy;
	float h,k;

	bool banCen=true, banA=true, banB=true;
	//Solicitar radio mayor y validacion de que sea positivo
	while(banA==true){
		printf("Ingrese el radio mayor\n");
		scanf("%f",&a);
		if(a<0){ printf("El radio mayor no puede ser negativo\n");}
		else{banA=false;}
	}
	//Solicitar radio menor y validacion de que sea positivo
	while(banB==true){
		printf("Ingrese el radio menor\n");
		scanf("%f",&b);
		if(b<0){ printf("El radio menor no puede ser negativo\n");}
		else{banB=false;}
	}
	//Solicitar las coordenadas del centro y validarlas
	while(banCen==true){
		printf("Ingrese las coordenadas del centro del elipse\n");
		scanf("%f", &h);
		scanf("%f", &k);
		if((h-a<0 || h+a>639) || (k-b<0 || k+b>479)){
			printf("Elipse fuera de los limites de la ventana\n");
		}
		else{
			banCen=false;
		}
	}
	
	x = 0; y = b;
	float a2, b2;
	a2= a*a; b2 = b*b;
	
	initgraph(&gd, &gm, (char *)"");
	dl = b2-a2*b+0.25*a;;
	putpixel(x, y, WHITE);
	
	/*h=getmaxx()-1/2;
	k=getmaxy()-1/2;*/
	
	dx = 2*b2*x;
	dy = 2*a2*y;
	
	while(dx < dy){
		if(dl < 0.00){
			dl +=2*(b*b)*x + 3*(b*b);
			dx += 2*b2;
			x++;
		}
		else{
			dl+= 2*(b*b)*x - 2*(a*a)*y + 5*(b*b);
			dx += 2*b2;
			dy -= 2*a2;
			x++;
			y--;	
		}
		putpixel(h+x,k+y, WHITE);
		putpixel(h+x,k-y, WHITE);
		putpixel(h-x,k+y, WHITE);
		putpixel(h-x,k-y, WHITE);
	}
	
	float x2, y2;
	x2 = (x+0.5)*(x+0.5);
	y2 = (y-1)*(y-1);
	
	dl2 = b2*x2 + a2*y2 - a2*b2;
	while(y>=0){
		if(dl2>0){
			dl2 += a2*(3-2*y);
			y--;
		}
		else{
			dl2 += a2*(3-2*y) + b2*(2*x+2);
			y--;
			x++;
		}
		putpixel(h+x,k+y, WHITE);
		putpixel(h+x,k-y, WHITE);
		putpixel(h-x,k+y, WHITE);
		putpixel(h-x,k-y, WHITE);
		
	}
	outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");

	getch();
	closegraph();
}

void linea_bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putpixel(x1, y1, 3); // Dibuja el pixel actual

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// A9- Rectangulo
void rectangulo(){
	int x1, y1, l, a;
	bool banC=true, banL=true, banA=true;
	while(banC==true){
		printf("Ingrese la coordenada de la esquina superior izquierda\n");
    	scanf("%d %d", &x1, &y1);
		if((x1<0 || x1>639) || (y1<0 || y1>479)){
			printf("Coordenada fuera de los limites de la ventana\n");
		}
		else{
			banC=false;
		}
	}
    while(banL==true){
		printf("Ingrese el largo del rectangulo\n");
    	scanf("%d", &l);
		if(l<0 || l>639){
			printf("Largo fuera de los limites de la ventana\n");
		}
		else{
			banL=false;
		}
	}

	while(banA==true){
		printf("Ingrese el ancho del rectangulo\n");
    	scanf("%d", &a);
		if(a<0 || a>479){
			printf("Ancho fuera de los limites de la ventana\n");
		}
		else{
			banA=false;
		}
	}
	
	int relleno int banRell=0;
	
	// -------------------------------------------------------------------------- CHECAR SI S� SIRVE Y AGREGAR EL RELLENO --------------------------------------------------------------------------
	while(banRell=0){
		printf("Selecciones una opci�n:\n 1. Rectangulo solido 2.ectangulo vacio\n")
		scanf("%d", &relleno);
	    
	    int gd = DETECT, gm;
	    initgraph(&gd, &gm, (char *)"");
	    
	    switch(relleno){
	    	case 1:
	    		banRell=1;
	    		linea_bresenham(x1, y1, x1 + l, y1); 
			    linea_bresenham(x1 + l, y1, x1 + l, y1 + a); 
			    linea_bresenham(x1 + l, y1 + a, x1, y1 + a); 
			    linea_bresenham(x1, y1 + a, x1, y1);
			    break;
			case 2:
				banRell=1;
				rectangulo_relleno();
				break;
			default:
				printf("Opci�n inv�lida\n");
		}
	}
	
    
    outtextxy(0, getmaxy()-1-100, "Presione cualquier tecla para continuar");

    getch();
    closegraph();
    
}

int main(){
	int opc=0, salir=0;
	
	
	while(salir == 0){
		printf("\n * * * * * * * * * * * * * *  MENU DE GRAFICOS * * * * * * * * * * * * * *  \nQue quieres graficar?\n");
		printf("1.Linea\n2.Linea con Punto medio\n3.Circulo\n4.Circulo (Trigonometrico)\n5.Circulo (Punto medio)\n6.Elipse\n7.Elipse (Trigonometrico)\n8.Elipse (Punto medio)\n9.Rectangulo\n10.Salir\n");
		printf("Selecciona una opcion: ");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				system("cls");
				printf(" ---------- LINEA ---------- \n");
				linea();
				system("cls");
				break;
			case 2:
				system("cls");
				printf(" ---------- LINEA POR PUNTO MEDIO ---------- \n");
				linea_pm();
				system("cls");
				break;
			case 3:
				system("cls");
				printf(" ---------- CIRCULO  ---------- \n");
				circulo();
				system("cls");
				break;
			case 4:
				system("cls");
				printf(" ---------- CIRCULO POR TRIGONOMETRIA ---------- \n");
				circulo_trig();
				system("cls");
				break;
			case 5:
				system("cls");
				printf(" ---------- CIRCULO POR PUNTO MEDIO ---------- \n");
				circulo_pm();
				system("cls");
				break;
			case 6:
				system("cls");
				printf(" ---------- ELIPSE ---------- \n");
				elipse();
				system("cls");
				break;
			case 7:
				system("cls");
				printf(" ---------- ELIPSE POR TRIGONOMETRIA ---------- \n");
				elipse_trig();
				system("cls");
				break;
			case 8:
				system("cls");
				printf(" ---------- ELIPSE POR PUNTO MEDIO ---------- \n");
				elipse_pm();
				system("cls");
				break;
			case 9:
				system("cls");
				printf(" ---------- RECTANGULO ---------- \n");
				rectangulo();
				system("cls");
				break;
			case 10:
				system("cls");
				printf("Saliendo...\n");
				salir =1;
				break;
			default:
				printf("Opcion no valida\n");
		}
	}
	printf("Salida Exitosa\n");
	return 1;
	
}


