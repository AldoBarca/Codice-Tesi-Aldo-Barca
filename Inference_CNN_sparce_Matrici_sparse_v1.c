// Versione orig

//weightS[i] peso diverso da zero
//Px[i], Py[i] posizione x, y dei pesi !=0

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

int img[ChNum][IXImgSize][IYImgSize] = { {{1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8}, /// img: .word 1,5,3,
																			//     .word 1,5, 
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


int ChannelSize[ChNum]={3,2,3,2};							



int WeightS[10]={ 3,2,7, 4,5, 6,7,8, 2,7};
int Px[10]=    { 0,1,2, 1,2, 0,1,2, 1,2};
int Py[10]=    { 0,1,2, 2,2, 2,0,0, 2,0};



int conv[OXImgSize][OYImgSize];


main() {

int first,pos;
int x,y, channel;
int conta=0;

 
 first=0;
 conta=0;	
	   
 // inizializziamo i valori della convoluzione 
 for(x=0;x<OXImgSize;x++)
	   for(y=0;y<OYImgSize;y++)
	   conv[x][y]=0;
// Per tutti i canali
for(channel=0;channel<ChNum;channel++)	      
 {  // Per tutti gli elementi dell'immagine di uscita da calcolare
	for(x=0;x<OXImgSize;x++)
	   for(y=0;y<OYImgSize;y++)
	       {
	       	
	       	for(pos=first;pos<first+ChannelSize[channel];pos++)
                 
			{
					conv[x][y]=conv[x][y]+WeightS[pos]*img[channel][x+Px[pos]][y+Py[pos]];
	       			conta++;
	       }
		   
		   }      
	   
	   first+=ChannelSize[channel];
}


	
	for(x=0;x<OXImgSize;x++)
	  {
	   
	   for(y=0;y<OYImgSize;y++)
       		printf("%d\t",conv[x][y]);
   
 	   printf("\n");
       }   
       
    printf("2) Numero convoluzioni=%d\n",conta);   
 printf("\n\n") ;
 
 
       
}
