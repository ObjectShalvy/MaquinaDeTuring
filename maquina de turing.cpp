/* Maquina de Turing simple que se encarga de duplicar cadena con demostracion grafica 
es necesario tener instalada la libreria graphics.h y manejjar el ide en 32-bis Release
*/
#include<conio.h>
#include<stdio.h>
#include <windows.h>
#include <graphics.h>
void arrg(int p,int q,int c, int f);
void gotoxy(int x,int y);
void archivo();
void diagrama();
void funcionamiento();
int estado_q0(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[]);
void estado_q1(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[],int acarreo);
void estado_q2(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[],int acarreo);
void estado_q3(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[],int acarreo);
void dibujarMarco();
int main(){
	int opc;
dibujarMarco();
	gotoxy(40,4);
      printf("Maquina de Turing");
      	gotoxy(40,6);
      printf("Suma de numeros binarios");
      	gotoxy(40,8);
      printf("Teoria de automatas");
      	gotoxy(40,10);
      printf("Salvador Sanchez Luengas 312-A");
	   	gotoxy(60,29); system("pause");
	system("cls");
	do{
		dibujarMarco();
	gotoxy(1,9);	printf("--------------------------------------------------------------------------------------------------");
        gotoxy(10,10);
        printf("1. Lenguaje formal");
        
        gotoxy(30,10);
        printf("2.Maquina de Turing");
        
        gotoxy(55,10);
        printf("3. Salir");
       	gotoxy(1,13);	printf("--------------------------------------------------------------------------------------------------");
        gotoxy(30,12);
        printf("Opcion:");
		scanf("%d%*c",&opc);
		system("cls");
		
		switch(opc){
			case 1:
				//Pantalla 2
	    		archivo();
				initwindow(1600, 900);
				diagrama();
				gotoxy(42,28);system("pause");
	    		closegraph();
	    		break;
	    	case 2: 
	    		//Pantalla 3
				funcionamiento();
	    		gotoxy(40,28); system("pause");
	    		break;
		}
		system("cls");
	}while(opc!=3);
	return 0;  
 }  

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 


void arrg(int p,int q ,int c, int f){
	int i,x;
	
	for(x=0; x<q; x++){
		gotoxy(c,f); printf("%c",218);  
		gotoxy(c,f+(x*2)+1); printf("%c",179);
		gotoxy(c,f+(x*2)+2); printf("%c",195);
		for(i=0; i<p-1; i++){
			gotoxy(c+((i+1)*4),f); printf("%c",194);
			gotoxy(c+(i*4)+1,f+(x*2)); printf("%c%c%c",196,196,196);
			gotoxy(c+(i*4)+1,f+(x*2)+1); printf("   %c",179);
			gotoxy(c+(i*4)+1,f+(x*2)+2); printf("%c%c%c",196,196,196,197);
			gotoxy(c+((i+1)*4),f+(x*2)+2); printf("%c",197);
		}
		gotoxy(c+(i*4)+1,f); printf("%c%c%c%c",196,196,196,191);
		gotoxy(c+(i*4)+1,f+(x*2)+1); printf("   %c",179);
		gotoxy(c+(i*4)+1,f+(x*2)+2); printf("%c%c%c%c",196,196,196,180);
	}
	gotoxy(c,f+(x*2)); printf("%c",192);
	gotoxy(c+(i*4)+4,f+(x*2)); printf("%c",217);
	for(i=0; i<p-1; i++){
		gotoxy(c+((i+1)*4),f+(x*2)); printf("%c",193);
	}
}
void archivo(){
  FILE *archivoTexto;
    char caracter;
   archivoTexto = fopen("C:\\Users\\Salvador\\Desktop\\multiplicacion binaria\\analisis.txt", "r");


    if (archivoTexto == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    while ((caracter = fgetc(archivoTexto)) != EOF) {
        putchar(caracter);
    }
    
    
    gotoxy(56,27);printf("Diagrama: ");
    gotoxy(42,28);system("pause"); 
      fclose(archivoTexto);
}

void diagrama(){
	circle(400,150,25); 
	circle(700,150,25); 
	circle(1000,150,25); 
	circle(850,450,25); 
	circle(850,450,20); 
	ellipse(400, 130, 0, 180, 15, 30); 
	ellipse(700, 130, 0, 180, 15, 30); 
	ellipse(1000, 130, 0, 180, 15, 30); 
	line(380, 125, 385, 130);
	line(390,125,385,130); 	
	line(680, 125, 685, 130);
	line(690, 125, 685, 130);
	line(980, 125, 985, 130);
	line(990,125,985,130); 	
	line(425,150,675,150);
	line(722,140,977,140);
	line(977,160,722,160);
	line(700,175,835,428);
	line(1000,175,865,428);
	line(665,155,675,150);
	line(665,145,675,150);
	line(967,145,977,140);
	line(967,135,977,140);
	line(732,165,722,160);
	line(732,155,722,160);
outtextxy(395, 145, const_cast<char *>("q0"));
outtextxy(695, 145, const_cast<char *>("q1"));
outtextxy(995, 145, const_cast<char *>("q2"));
outtextxy(845, 445, const_cast<char *>("q3"));
	line(365,155,375,150);
	line(365,145,375,150);
	line(300,150,375,150);
	
}

void funcionamiento(){
	int cabezal=1,i,j,band;
    char cad_1[20], cad_2[20], cad_3[20], cad_4[20], aux_1[20],aux_2[20];
    do{
    	i=0;
    	
    	cad_3[1]='\0';
    	cad_4[1]='\0';
    	band=0;
    	gotoxy(71,4);printf("                             ");
    	gotoxy(45,4);printf("Ingrese la cadena 1: ");
    	gets(aux_1);
    	gotoxy(45,5);printf("Ingrese la cadena 2: ");
    	gets(aux_2);
    	cad_1[0]='x';
		cad_2[0]='x';
		for(i=0; aux_1[i]!='\0'; i++){
			cad_1[i+1]=aux_1[i];
			cad_2[i+1]=aux_2[i];
		}
		cad_1[i+1]='\0';
		cad_2[i+1]='\0';
		
		for(i=0; i<2; i++){
			arrg(12,1,1,7+(i*4));
			for(j=0; j<12; j++){
				gotoxy(3+(j*4),8+(i*4));printf("%c",231);
			}		
		}
		for(i=0; i<2; i++){
			arrg(12,1,60,7+(i*4));
			for(j=0; j<12; j++){
				gotoxy(62+(j*4),8+(i*4));printf("%c",231);
			}		
		}
		
		for(i=0; cad_1[i]!='\0'; i++){
			gotoxy(7+((i+1)*4),8);printf("%c",aux_1[i]);
		}
		j=2;
		for(i=0; cad_2[i]!='\0'; i++){
			gotoxy(74+((i+1)*4),8);printf("%c",aux_2[i]);
		}
		
		gotoxy(11,10); printf("%c",94);
		gotoxy(78,10); printf("%c",94);
		gotoxy(11,10+4); printf("%c",94);
		gotoxy(78,10+4); printf("%c",94);
		gotoxy(10,4); printf("Estado Actual: ");
		band=estado_q0(cabezal,cad_1,cad_2,cad_3,cad_4);
	}while(band!=0);
}

int estado_q0(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[]){
	int band,acarreo;
	do{
;
		Sleep(1500);
		band=0;
		if(cad_1[cabezal]=='0' && cad_2[cabezal] == '0' && cad_3[cabezal]=='\0' && cad_4[cabezal]=='\0'){
			cad_3[cabezal+1]='\0';
			cad_4[cabezal+1]='\0';
			
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			gotoxy(74+(cabezal*4),10+4); printf(" ");
			cabezal++;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			gotoxy(74+(cabezal*4),10+4); printf("%c",94);
			band=1;
			
		}
		else if(cad_1[cabezal]=='0' && cad_2[cabezal] == '1' && cad_3[cabezal]=='\0' && cad_4[cabezal]=='\0'){
			cad_3[cabezal+1]='\0';
			cad_4[cabezal+1]='\0';
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			gotoxy(74+(cabezal*4),10+4); printf(" ");
			cabezal++;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			gotoxy(74+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}
		else if(cad_1[cabezal]=='1' && cad_2[cabezal] == '0' && cad_3[cabezal]=='\0' && cad_4[cabezal]=='\0'){
			cad_3[cabezal+1]='\0';
			cad_4[cabezal+1]='\0';
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			gotoxy(74+(cabezal*4),10+4); printf(" ");
			cabezal++;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			gotoxy(74+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}
		else if(cad_1[cabezal]=='1' && cad_2[cabezal] == '1' && cad_3[cabezal]=='\0' && cad_4[cabezal]=='\0'){
			cad_3[cabezal+1]='\0';
			cad_4[cabezal+1]='\0';
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			gotoxy(74+(cabezal*4),10+4); printf(" ");
			cabezal++;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			gotoxy(74+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}else if(cad_1[cabezal]=='\0' && cad_2[cabezal] == '\0' && cad_3[cabezal]=='\0' && cad_4[cabezal]=='\0'){
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			acarreo=cabezal;
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			estado_q1(cabezal,cad_1,cad_2,cad_3,cad_4,acarreo);
		}else{
			gotoxy(45,25); printf("La cadena no fue Aceptada\n");
		}
	}while(band!=0);
	return 0;
}


void estado_q1(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[],int acarreo){
	int band;
	do{
		Sleep(1500);
		gotoxy(25,4); printf("q1");
		band=0;
		if(cad_1[cabezal]=='0' && cad_2[cabezal] == '0' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='\0'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='0';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			band=1;
			
		}
		else if(cad_1[cabezal]=='0' && cad_2[cabezal] == '1' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='\0'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='1';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}
		else if(cad_1[cabezal]=='1' && cad_2[cabezal] == '0' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='\0'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='1';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}
		else if(cad_1[cabezal]=='1' && cad_2[cabezal] == '1' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='\0'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='0';
			cad_4[acarreo]='1';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(74+(acarreo*4),8+4);printf("%c",cad_4[acarreo]);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			estado_q2(cabezal,cad_1,cad_2,cad_3,cad_4,acarreo);
		}else if(cad_1[cabezal]=='x' && cad_2[cabezal] == 'x' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='\0'){
			estado_q3(cabezal,cad_1,cad_2,cad_3,cad_4,acarreo);
		}else{
			gotoxy(45,25); printf("La cadena no fue Aceptada\n");
		}
	}while(band!=0);
}

void estado_q2(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[],int acarreo){
	int band;
	do{
		gotoxy(25,4); printf("q2");
		Sleep(1500);
		band=0;
		if(cad_1[cabezal]=='0' && cad_2[cabezal] == '0' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='1'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='1';
			cad_4[acarreo]='\0';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(74+(acarreo*4),8+4);printf("%c",231);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			estado_q1(cabezal,cad_1,cad_2,cad_3,cad_4,acarreo);
			
		}
		else if(cad_1[cabezal]=='0' && cad_2[cabezal] == '1' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='1'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='0';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}
		else if(cad_1[cabezal]=='1' && cad_2[cabezal] == '0' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='1'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='0';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}
		else if(cad_1[cabezal]=='1' && cad_2[cabezal] == '1' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='1'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='1';
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(7+(cabezal*4),10); printf(" ");
			gotoxy(74+(cabezal*4),10); printf(" ");
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10); printf("%c",94);
			gotoxy(74+(cabezal*4),10); printf("%c",94);
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			band=1;
		}else if(cad_1[cabezal]=='x' && cad_2[cabezal] == 'x' && cad_3[cabezal]=='\0' && cad_4[acarreo]=='1'){
			cad_3[cabezal-1]='\0';
			cad_3[cabezal]='1';
			cad_4[acarreo]='\0';
			gotoxy(74+(acarreo*4),8+4);printf("%c",231);
			gotoxy(7+(cabezal*4),8+4);printf("%c",cad_3[cabezal]);
			gotoxy(7+(cabezal*4),10+4); printf(" ");
			cabezal--;
			gotoxy(7+(cabezal*4),10+4); printf("%c",94);
			estado_q3(cabezal,cad_1,cad_2,cad_3,cad_4,acarreo);
		}else{
			gotoxy(45,25); printf("La cadena no Aceptada\n");
		}
	}while(band!=0);
}

void estado_q3(int cabezal,char cad_1[],char cad_2[],char cad_3[],char cad_4[],int acarreo){
	gotoxy(25,4); printf("q3");
	gotoxy(45,25);printf("\n Suma de binarios finalizadad");
}
void dibujarMarco() {
    int i, j;

    for (i = 0; i < 100; i++) {
        printf("+");
    }
    printf("\n");

    for (i = 0; i < 27; i++) {
        printf("|");
        for (j = 0; j < 98; j++) {
            printf(" ");
        }
        printf("|\n");
    }

    for (i = 0; i < 100; i++) {
        printf("+");
    }
    printf("\n");
}

