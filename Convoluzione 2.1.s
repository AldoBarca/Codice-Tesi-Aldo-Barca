.data 

;Dati del primo canale dell'img 16*16, l'algoritmo funziona per qualsiasi dato numerico purche sia sempre una 16*16.
; sono presenti 4 canali.
;Mappa : variabili:       s0=numero del canale dell'img(in offset)
                                       ;s1= L'x della Convoluzione(14*14)
                                       ;s2=L'y della Conv e dell'Img visto che l'offset coicide per spostarsi su una stessa riga.
                                       ;s3= first
                                       ;s4= pos
                                       ;s5=L'x della img(in offset)
                                       ;s6=canale del channelsize.
                                       ;s7=channelSize[channel]                                                  

 riga1_1:  .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
riga2_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8   
  riga3_1: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8   
  riga4_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
 riga5_1: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
 riga6_1: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
 riga7_1: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
 riga8_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
riga9_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8   
 riga10_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
 riga11_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
riga12_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
 riga13_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
  riga14_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
 riga15_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  
  riga16_1: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8  

riga1_2:  .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga2_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8            
  riga3_2: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga4_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga5_2: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga6_2: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga7_2: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga8_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga9_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga10_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga11_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga12_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga13_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
  riga14_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga15_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8
  riga16_2: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga1_3:  .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga2_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga3_3: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga4_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga5_3: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga6_3: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga7_3: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga8_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga9_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga10_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga11_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8
riga12_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga13_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
  riga14_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga15_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
  riga16_3: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 

riga1_4:  .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga2_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga3_4: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga4_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga5_4: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga6_4: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga7_4: .word  1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga8_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga9_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga10_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga11_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
riga12_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8
 riga13_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
  riga14_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
 riga15_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 
  riga16_4: .word 1,5,3,2,4,7,1,8,1,5,3,2,4,7,1,8 

 channel_size: .word 3,2,3,2   ; numero di pesi !0 per ogni canale, in pratica scandisce dopo quanti byte in weightS si passa al canale successivo.

;sono previsti 4 canali

weightS: .word 3,2,7,4,5,6,7,8,2,7   ;        fulcro della versione 2.0 ora memorizziamo e consideriamo solo i pesi != 0  e la loro posizione.

Px: .word 0,1,2,1,2,0,1,2,1,2

Py: .word  0,1,2,2,2,2,0,0, 2,0

;channel_size:  .word 6,5,6,5 weightS: .word 3,2,7,4,5,6, 7,8,2,7,6, 1,2,3,4,5,6, 5,6,2,8,6 Px: .word 0,1,2,1,2,0, 1,2,1,2,0, 1,2,1,2,0,1, 2,1,2,0,1 Py: .word 0,1,2,1,2,0, 1,2,2,2,0, 1,2,1,2,0,1, 2,1,2,0,1





;matrice convoluzione 14*14, inizialmente con tutti gli elementi inizializzati a 0

riga1_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
 riga2_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga3_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga4_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga5_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga6_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga7_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga8_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga9_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga10_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
 riga11_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga12_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga13_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 
  riga14_conv: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0 



;parametri per delle eventuali syscall 5 
 mes1: .asciiz "%d"  
mes2: .asciiz "%d/n"
p1sys5: .space 8 
prova: .space 8 



 .code

;IMG:
;ogni 8 si passa dall' [1,1] allo [1,2] e cosi via
;dopo l'[1,16] aumentando di 8 si passa al [2,1. 
; per aumentare di una riga, ossia dallo [1,1] al [2,1] si aumenta di 128 .
;quindi se un indice j è multiplo di 128 vuol dire che si è passati alla riga successiva
;per passare al corrispettivo di un elemento nell'altro canale  matematicamente  si deve aumentare di aumentare di 2048,ossia 16*16*8 
;di conseguenza banalmente se un ipotetico indice i supera i 2048 si è passati al secondo canale e cosi via per i multipli nel caso di canali multipli(tipo 4).


daddi $s3,$0,0   ;inizializziamo la variabile first


;inizio for canale ipotizzando 4 canali                                                                                                                                                                                                        CANALE: S4 WEIGHT S0 IMG
daddi $s6,$0,0 ; channel di channelsize=0
daddi $s0,$0,0 ; channel=0 ,channel in s0  variabile per il canale dell'img



for_canale: slti $t0,$s0,8191 ; letterlamente i<nChannel=4 dove ogni canale dista 2048 byte l'uno dall'altro e dunque si faranno 4 iterazioni

beq $t0,$0,fine_for_canale

;inizio for che cambia indice di riga                                                                                                                                                                                                           RIGHE X : S1 CONV     S5 IMG


 daddi $s1,$0,0 ;x=0, x in s1 la riga della matrice 14 per 14
daddi $s5,$0,0 ;variabile per esprimere la riga della 16*16, scorro di 128 ogni volta
for_x: slti $t0,$s1,1567 ; equivale a s1<112*14  scorro tra le righe della 14 per 14, ad ogni ciclo aumento di 112 fino ad un massimo di 1456 ,dunque vi saranno 14 iterazioni.



beq $t0,$0,fine_for_x
;inizio for y cioe scorrendo nella riga                                                                                                                                                                                                          NELLA RIGA Y : S2 PER ENTRAMBI



 daddi $s2,$0,0 ; y=0 ,y in s2 
for_y: slti $t0,$s2,111  ; scorro nella stessa riga cambiando l'indice di colonna ,aumento ogni ciclo di 8 fino ad un massimo di 104,cioè faccio 14 iterazioni.
beq $t0,$0,fine_for_y 





;dsll $t0,$s3,3 ;
;daddi $s4,$t0,0   ;pos=first.
                 
dsll $s4,$s3,3    ;pos=first

dadd $t9,$s2,$s1  ; calcolo in $t9 x+y della conv ; 
ld $t8, riga1_conv($t9) ; carico in $t8 conv[x][y]  
daddi $t1,$t8,0;
for_pos: 

ld $s7,channel_size($s6)  ; carico channelSize[channel] in s7  ,sara un numero tipo 3 o 2
dadd $t2,$s7,$s3             ;pongo t2= first+channeSize[channel] 
dsra $t4,$s4,3  ; divido pos per 8
slt $t0,$t4,$t2  ; pos< first+ channelSize[channel] 
beq $t0,$0,fine_for_pos 


;nucleo 

ld $t2,weightS($s4) ;carico in t2 weightS[pos] 

ld $t3,Px($s4) ;t3=px[pos]   
dsll $t3,$t3,7  ; t3=t3*128, converto px[pos] all'offset di cambio di riga per la 16*16                           
dadd $t5,$t3,$s5   ;t5= [x+px[pos]] 


ld $t4,Py($s4)   ;t4= Py[pos]     ;è 0,1 o 2
dsll $t4,$t4,3 ;converto py[pos] da 0,1,o 2 al corrispettivo offsett per la 16*16 , t4=t4*8
dadd $t7,$s2,$t4 ; t7=y+py[pos]
dadd $t3,$t7,$t5     ;t3=y+py[pos]+ x+px[pos]
dadd $t3,$t3,$s0     ;t3=y+py[pos]+x+px[pos]+canale


ld $t6, riga1_1($t3)  ; img[channel][x+px[pos]][y+py[pos]] in t6 // 
dmult $t6,$t2              ;img... per weight...                                                                                                                                                                                                              ; ALGORITMO CONVOLUZIONE
mflo $t7;sposto in t7 i bit meno significativi 

dadd $t1,$t1,$t7 ;calcolo conv+ il prodotto come nell'algoritmo in c 

;a questo punto metto in store nella locazione di memoria di conv[x][y]  

daddi $t5,$t9,riga1_conv
                         

daddi $s4,$s4,8  ; pos++                                                                                                                                                                                          ;FINE POS
j for_pos 

fine_for_pos: 
sd $t1,0($t5)   
daddi $s2,$s2,8 ;aumento y di 8 cioe passo all'elemento successivo di una riga 
j  for_y 
fine_for_y:                                                                                                                                                                                                                   ; FINE Y
daddi $s1,$s1,112 ;aumento s1 di 112, cioe 14*8  una riga di una14 per 14 
daddi $s5,$s5,128 ; riga di una 16 per 16  
;dadd $s3,$s3,$s7 ;first=first+ channelSize[channel]

                                                                                                                                                                   ;   FINE 
j  for_x 
fine_for_x: 

daddi $s6,$s6,8  ;canale del channelsize
dadd $s3,$s3,$s7 ;first=first+ channelSize[channel]
daddi $s0,$s0,2048;canale   dell'img                                                                                                                                                               FINE CANALE

j for_canale  

fine_for_canale: 






syscall 0
