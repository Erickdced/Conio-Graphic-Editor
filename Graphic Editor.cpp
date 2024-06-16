#include <stdio.h>
#include <conio.h>
//marco void Marco (void)
{
	int x1 = 1, x2 = 79, cx, y1 = 1, y2 = 24, cy;    
	for(cx = 2; cx < x2; cx ++)    
	{        
		if(cx != 54)        
		{            
			gotoxy(cx, y1);            
			printf("%c", 205);            
			gotoxy(cx, y2);            
			printf("%c", 205);            
		}    
	}    
	for(cy = 2; cy < y2; cy ++)    
	{        
		gotoxy(x1, cy);        
		printf("%c", 186);        
		gotoxy(x2, cy);         
		printf("%c", 186);        
		gotoxy(54, cy);        
		printf("%c", 186);    
	}    
	//esquinas especiales    
	gotoxy(1,1);    
	printf("%c", 201);    
	gotoxy(54, 1);    
	printf("%c", 203);    
	gotoxy(79, 1);    
	printf("%c", 187);    
	gotoxy(1, 24);    
	printf("%c", 200);    
	gotoxy(79, 24);    
	printf("%c", 188);    
	gotoxy(54,24);    
	printf("%c", 202);    
	return ;
}
//menú del instrucciones
void Menu (void)
{    
	int c, x, l;    
	gotoxy(55, 2);    
	printf("Elecci%cn de colores [Q]", 162);    
	gotoxy(55,3);    
	printf("Insertar en decimal 1-15");     
	for(c = 1; c <= 15; c ++)    
	{        
		textcolor(c);        
		x = c + 54;        
		gotoxy(x, 4);        
		cprintf("%x", c);    
	}    
	gotoxy(55,5);   
	printf("Elecci%cn de pincel [E]", 162);    
	gotoxy(55, 6);    
	printf("1 = %c, 2 = %c, 3 = %c", 43, 42 , 35);    
	gotoxy(55, 7);    
	printf("Goma [R]");    
	gotoxy(55,8);    
	printf("Solo cursor [F]");    
	gotoxy(55,9);    
	printf("Arriba [W]");    
	gotoxy(55,10);    
	printf("Abajo [S]");    
	gotoxy(55,11);    
	printf("Derecha [D]");    
	gotoxy(55,12);    
	printf("Izquierda [A]");    
	gotoxy(55,13);    
	printf("Selector de lienzo [L]");    
	gotoxy(55, 14);    
	printf("Lienzos 1-4");    
	gotoxy(55, 15);    
	printf("Cambio todo color[enter]");    
	gotoxy(55, 16);    
	printf("Primero elegir el color");    
	gotoxy(55,17);    
	printf("Borrar lienzo [O]");    
	return;
}
//pincel 
char Pincel (int picp)
{	
	char sign;    
	if(picp == 1)    
	{		
		sign = '+';	
	}    
	else if(picp == 2)    
	{		
		sign = '*';	
	}
	else if(picp == 3)    
	{		
		sign = '#';	
	}    
	else if(picp == 5)    
	{        
	sign = 32;	
	}	
	return sign;
}
//PRINCIPAL
int main (void)
{    
	// definir variables    
	int x = 10, y = 10, color, picp = 1, memory[54][24][5], i, j, z = 0, k, sello[54][24], a1, b1, a2, b2;    
	for(k = 0; k < 5; k++)    
	{    	
		for(i = 0; i < 54; i++)    	
		{			
			for(j = 0; j < 24; j++)				
				memory[i][j][k] = ' ';		
		}	
	}	
	for(i = 0; i < 54; i++)    
	{		
		for(j = 0; j < 24; j++)			
			sello[i][j] = ' ';	
	}   
	char act = '1';    
	gotoxy(55, 23);    
	printf("Lienzo actual = %i", z + 1);    
	//funciones previas    
	Marco();    
	Menu();    
	//inicio del problema    
	while(act != '0')        
	{        
		act = getch();        
		//movimiento        
		if((act == 'd' || act == 'D') && x <= 52)        
		{            
			x++;            
			gotoxy(x,y);             
			memory[x][y][z] = Pincel(picp);            
			printf("%c", memory[x][y][z]);        
		}        
		else if((act == 'a' || act == 'A') && x >= 3)        
		{            
			x--;            
			gotoxy(x,y);             
			memory[x][y][z] = Pincel(picp);            
			printf("%c", memory[x][y][z]);  		
		}        
		else if((act == 's' || act == 'S') && y <= 22)        
		{            
			y++;            
			gotoxy(x,y);             
			memory[x][y][z] = Pincel(picp);            
			printf("%c", memory[x][y][z]);        
		}        
		else if((act == 'w' || act == 'W') && y >= 3)        
		{            
			y--;            
			gotoxy(x,y);             
			memory[x][y][z] = Pincel(picp);            
			printf("%c", memory[x][y][z]);        
		}        
		// cambio de color        
		else if(act == 'q' || act == 'Q')        
		{            
			gotoxy(76,23);            
			scanf("%i", &color);            
			while(color < 1 || color > 15)            
			{				
				gotoxy(55, 22);				
				printf("Entrada inv%clida", 160);				
				gotoxy(77,23);				
				scanf("%i", &color);			
			}			
			gotoxy(55, 22);			
			printf("                 ");            
			gotoxy(76,23);            
			printf("   ");            
			textcolor(color);        
		}
		//cambio pincel        
		else if (act == 'e' || act == 'E')        
		{            
			gotoxy(77,23);            
			scanf("%i", &picp);            
			//comprobacción de seguridad            
			while(picp < 1 || picp > 3)            
			{				
				gotoxy(55, 22);				
				printf("Entrada inv%clida", 160);				
				gotoxy(77,23);				
				scanf("%i", &picp);			
			}			
			gotoxy(55, 22);			
			printf("                 ");            
			gotoxy(77,23);            
			printf("  ");            
			gotoxy(x,y);             
			memory[x][y][z] = Pincel(picp);            
			printf("%c", memory[x][y][z]);        
			}          
			//goma        
			else if (act == 'r' || act == 'R')        
			{            
				picp = 5;            
				gotoxy(x,y);           
				printf(" ");		
			}        
			//cursor levantado        
			else if (act == 'f' || act == 'F')            
			picp = 0;        
			//cambio total de color        
			else if (act == 13)        
			{			
				for(i = 2; i < 54; i++)   			
				{				
					for(j = 2; j < 24; j++)				
					{					
						gotoxy(i,j);				
						printf("%c", memory[i][j][z]);				
					}			
				}		
			}        
			//cambio de lienzo		
			else if(act == 'l' || act == 'L')		
			{			
				gotoxy(71,23);			
				scanf("%i", &z);			
				z = z - 1;			
				//antierrores			
				while(z < 0 || z > 3)            
				{				
					gotoxy(55, 22);				
					printf("Entrada inv%clida", 160);				
					gotoxy(71,23);				
					scanf("%i", &z);			
				}			
				gotoxy(72, 23);			
				printf("  ");			
				gotoxy(55, 22);			
				printf("                 ");			
				//aparición en menú			
				gotoxy(55, 23);    		
				printf("Lienzo actual = %i", z + 1);			
				for(i = 2; i < 54; i++)   			
				{				
					for(j = 2; j < 24; j++)				
					{					
						gotoxy(i,j);					
						printf("%c", memory[i][j][4]);				
					}			
				}			
				for(i = 2; i < 54; i++)   			
				{				
					for(j = 2; j < 24; j++)				
					{					
						gotoxy(i,j);					
						printf("%c", memory[i][j][z]);				
					}			
				}		
			}		
			//borrar lienzo actual		
			else if(act == 'o' || act == 'O')		
			{			
				for(i = 2; i < 54; i++)   			
				{				
					for(j = 2; j < 24; j++)					
					memory[i][j][z] = ' ';			
				}			
				for(i = 2; i < 54; i++)   			
				{				
					for(j = 2; j < 24; j++)				
					{					
						gotoxy(i,j);					
						printf("%c", memory[i][j][z]);				
					}			
				}		
			}		
			//copiar sello		
			else if(act == 'c' || act == 'C')		
			{    		
				for(i = 0; i < 54; i++)    		
				{				
					for(j = 0; j < 24; j++)				
					{					
						if(memory[i][j][z] != ' ')					
						{						
							sello[i][j] = memory [i][j][z];						
							a2 = i, b2 = j;					
						}				
					}					
				}        
			}        
			//pegar sello        
			else if(act == 'v' || act == 'V')        
			{			
				a1 = x + a2;			
				if(a1 > 53)				
					a1 = 53;			
				b1 = y + b2;			
				if(b1 >23)				
					b1 = 23;			
				for(i = 0; i < 54; i++)    		
				{				
					for(j = 0; j < 24; j++)				
					{					
						if((i < 54 && j < 24) && sello[i][j] != ' ')					
						{						
							memory[i][j][z] = sello[i][j];					
						}			
					}					
				}			
				for(i = 2; i < 54; i++)   			
				{				
					for(j = 2; j < 24; j++)				
					{										
						gotoxy(i,j);					
						printf("%c", memory[i][j][z]);				
					}			
				}			
				/*a2 = 0, b2 = 0;			
				for(i = x; i < a1; i++)    		
				{				
					for(j = y; j < b1 ; j++)				
					{					
						if(( a2 < 54 && b2 < 24) && sello[a2][b2] != ' ')					
						{					
							memory[i][j][z] = sello[a2][b2];					
						}					
						b2++;				
					}					
				a2++;				
				}			
				for(i = x; i < a1; i++)			
				{				
					for(j = y; j < b1; j++)				
					{					
						gotoxy(i,j);					
						printf("%c", memory[i][j][z]);				
					}			
				}*/		
			}    
		}     
		getchar();    
		return 0;
	}