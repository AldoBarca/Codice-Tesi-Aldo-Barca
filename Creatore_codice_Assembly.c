#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int numCasuale(int, int); 
int numCasuale(int minimo,int massimo)
{
	int numero;
	numero = rand() %(massimo-minimo + 1)+minimo;
	return numero;
}


void main()
{
	FILE * fp;
	fp = fopen("Codice_Assembly_conv.s", "w");
	int n_canali;
	int filtro;
	int img;
	filtro = 3;
	printf("Digitare la dimensione dell'img: ");
	scanf("%d", &img);
        n_canali=4;

	
	printf("%d,%d,%d", img, n_canali, filtro);
	// modalità con 22 pesi diversi da 0
	fprintf(fp, ".data \n channel_size: .word 6,5,6,5 \n weightS: .word 3,2,7,4,5,6, 7,8,2,7,6, 1,2,3,4,5,6, 5,6,2,8,6 \n Px: .word 0,1,2,1,2,0, 1,2,1,2,0, 1,2,1,2,0,1, 2,1,2,0,1 \n Py: .word 0,1,2,1,2,0, 1,2,2,2,0, 1,2,1,2,0,1, 2,1,2,0,1 \n");
    //modalità con 10 pesi diversi da 0
	//fprintf(fp, ".data \n channel_size: .word 3,2,3,2 \n weightS:.word 3,2,7,4,5,6,7,8,2,7 \n Px: .word 0,1,2,1,2,0,1,2,1,2 \n Py: .word  0,1,2,2,2,2,0,0, 2,0 \n");

	for (int canale = 0; canale < n_canali; canale++) {
		for (int riga = 0; riga < img; riga++) {
			fprintf(fp, "riga%d_%d: .word ", riga+1, canale+1);
			for (int colonna = 0; colonna < img; colonna++) {
				int casuale = numCasuale(1,9);
				fprintf(fp, "%d", casuale);
				if (colonna < img-1) {fprintf(fp, ",");
			}
				else fprintf(fp, "\n");
			}
		}fprintf(fp, "\n");
	}

	int filtro_menouno = filtro-1;
	int conv = img - filtro_menouno;
	printf(" %d", conv);
	for (int riga = 0; riga < conv; riga++) {
		fprintf(fp, "riga%d_conv: .word ", riga+1);
		for (int colonna = 0; colonna < conv; colonna++) {
			fprintf(fp, "%d", 0);
			if (colonna < conv-1) { fprintf(fp, ","); }
			else if(riga==0){ fprintf(fp, " ;inizio matrice di convoluzione \n"); }
		    else fprintf(fp, "\n");

		}
		




	}
	fprintf(fp, "\n");
	int salto_c_img = img * img; 
	salto_c_img = salto_c_img * 8;
	int spazio_totale_canali = salto_c_img * n_canali;
	fprintf(fp, ".code \n daddi $s3,$0,0  \n daddi $s6,$0,0 \n daddi $s0,$0,0 \n\n ;inizio for canale \n\n for_canale: slti $t0,$s0,%d \n", spazio_totale_canali);
	int salto_conv = conv * conv * 8;
	fprintf(fp, "beq $t0,$0,fine_for_canale \n  daddi $s1,$0,0 \n daddi $s5,$0,0 \n\n ;inizio for asse x \n\n for_assex: slti $t0,$s1,%d \n", salto_conv);
	int salto_riga_conv = conv * 8;
	fprintf(fp, "beq $t0,$0,fine_for_assex \n daddi $s2,$0,0 \n ; inizio for asse y \n for_assey: slti $t0,$s2,%d \n", salto_riga_conv);
	fprintf(fp, "beq $t0,$0,fine_for_assey \n dsll $s4,$s3,3 \n dadd $t9,$s2,$s1 \n ld $t8, riga1_conv($t9) \n daddi $t1,$t8,0 \n\n ;inizio for posizione\n \n for_pos:  \n ld $s7, channel_size($s6) \n");
	fprintf(fp, "dadd $t2,$s7,$s3 \n dsra $t4,$s4,3 \n slt $t0,$t4,$t2 \n beq $t0,$0,fine_for_pos \n\n ;inizio algoritmo\n\n ld $t2,weightS($s4) \n ld $t3,Px($s4) \n dsll $t3,$t3,7 \n");
	fprintf(fp, "dadd $t5,$t3,$s5  \n ld $t4,Py($s4) \n  dsll $t4,$t4,3 \n dadd $t7,$s2,$t4 \n dadd $t3,$t7,$t5 \n dadd $t3,$t3,$s0 \n ld $t6, riga1_1($t3)  \n");
	fprintf(fp, "dmult $t6,$t2 \n mflo $t7 \n dadd $t1,$t1,$t7 \n daddi $t5,$t9,riga1_conv \n daddi $s4,$s4,8 \n j for_pos  \n\n ;fine algoritmo \n\n fine_for_pos: \n sd $t1,0($t5)\n ");
	int salto_riga_img = img * 8;
	fprintf(fp, "daddi $s2,$s2,8 \n j for_assey \n ;fine for che scorre la riga\n\n fine_for_assey: \n daddi $s1,$s1,%d \n daddi $s5,$s5,%d \n ", salto_riga_conv, salto_riga_img);
	fprintf(fp, "j  for_assex \n\n ;fine for che scorre tra le diverse righe \n\n fine_for_assex: \n daddi $s6,$s6,8 \n dadd $s3,$s3,$s7 \n daddi $s0,$s0,%d \n j for_canale \n\n ;fine for che scorre tra i canali\n\n fine_for_canale: \n syscall 0", salto_c_img);











	printf("Tutto ok");
	fclose(fp);
}
