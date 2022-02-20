// Versione orig



// img immagine da processare
//XImgSize dimensione X dell'immagine
//YImgSize dimensione Y dell'immagine
// Dx dimensione x dell'array di MAC che processano in parallelo
// Dy dimensione y dell'array di MAC che processano in parallelo
// WSize Numero di pesi != 0
#include <stdio.h>
#define IXImgSize 16
#define IYImgSize 16
#define OXImgSize 14
#define OYImgSize 14

#define ChNum 4

#define Dx 4
#define Dy 4
#define WSize 4
#define DeltaX 3
#define Wx 3
#define Wy 3

int img[ChNum][IXImgSize][IYImgSize] = { {{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8}
								},
							   {{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8},
								{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8}
								}

								};



int Weight[4][3][3]={{ {3,0,0},{0,2,0},{0,0,7}},
				  { {0,0,0},{0,0,4},{0,0,5}},
				  { {0,0,6},{7,0,0},{8,0,0}},
				  { {0,0,0},{0,0,2},{7,0,0}}		

}  ;


int conv[OXImgSize][OYImgSize];


main() {

int p,q;
int x,y, channel;
int conta=0;


 
 // inizializziamo i valori della convoluzione 
 for(x=0;x<OXImgSize;x++)
	   for(y=0;y<OYImgSize;y++)
	   conv[x][y]=0;
conta=0;	   

// Per tutti i canali
for( channel=0;channel<ChNum;channel++)	      
 {  // Per tutti gli elementi dell'immagine di uscita da calcolare
    
   
	for(x=0;x<OXImgSize;x++)
	   for(y=0;y<OYImgSize;y++)
	       {
	       	
	       	for(p=0;p<3;p++)
               for(q=0;q<3;q++)  
					{
					conv[x][y]=conv[x][y]+Weight[channel][p][q]*img[channel][x+p][y+q];
	       			conta++;
				}
		  
		   }      
	  
}

	for(x=0;x<OXImgSize;x++)
	  {
	   
	   for(y=0;y<OYImgSize;y++)
         printf("%d\t",conv[x][y]);
   
 	   printf("\n");
     }        
       
    printf("3) Numero convoluzioni=%d\n",conta);   
       
}
