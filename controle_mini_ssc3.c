#include <stdio.h>
#include <stdlib.h>
#include <data.h>

char angles[5][12]
char message[4];
char sbd[4];

void main()
{
FILE *f;
int i;
int j;
int touche;
int vmin;
int vmax;
int delai;
//HEUREUX
angles[0][0] =40;
angles[0][1] =__;
angles[0][2] =220;
angles[0][3] =40;
angles[0][4] =220;
angles[0][5] =__;
angles[0][6] =__;
angles[0][7] =__;
angles[0][8] =190;
angles[0][9] =150;
angles[0][10] =__;
angles[0][11] =140;
//COLERE
angles[1][0] =120;
angles[1][1] =__;
angles[1][2] =120;
angles[1][3] =140;
angles[1][4] =40;
angles[1][5] =80;
angles[1][6] =__;
angles[1][7] =100;
angles[1][8] =190;
angles[1][9] =90;
angles[1][10] =100;
angles[1][11] =140;
//PEUR
angles[2][0] = 40;
angles[2][1] =__;
angles[2][2] =220;
angles[2][3] =140;
angles[2][4] =130;
angles[2][5] =__;
angles[2][6] =__;
angles[2][7] =180;
angles[2][8] =190;
angles[2][9] =90;
angles[2][10] =180;
angles[2][11] =140;
//ETONNEMENT
angles[3][0] = 220;
angles[3][1] =__;
angles[3][2] =20;
angles[3][3] =140;
angles[3][4] =220;
angles[3][5] =__;
angles[23[6] =__;
angles[2][7] =180;
angles[2][8] =190;
angles[2][9] =220;
angles[2][10] =180;
angles[2][11] =140;
//PEUR
angles[2][0] = __;
angles[2][1] =__;
angles[2][2] =__;
angles[2][3] =__;
angles[2][4] =__;
angles[2][5] =__;
angles[2][6] =__;
angles[2][7] =__;
angles[2][8] =__;
angles[2][9] =__;
angles[2][10] =__;
angles[2][11] =__;



  vmin=80;
  vmax=230;
  delai=100000;  
  
  message[0]=(unsigned char) 255;
  message[1]=(unsigned char)2;
  message[2]=220;
  sbd[0] =(unsigned char)255;
  sbd[1]=(unsigned char)2;
  sbd[2]=40;

/*  f=fopen("/dev/ttyUSB0","w");

      fwrite(sbd,1,3,f);
      fflush(f);
      usleep(delai);
      fclose(f);
*/
  do
  {
    scanf("%d",&touche);
    switch (touche)
    {
      case 1 :
        printf("servo1\n"); //'1'
        break;
      case 2 :
        printf("servo2\n"); //'2'
        break;
      case 3 :
        printf("servo3\n"); //'3'
        break;
      case 4 :
        printf("servo4\n"); //'4'
        break;
      default :
        printf("none\n");
   }
   while (touche != 5);
 // for(i=vmin;i<=vmax;i++)
   //{
      //message[2]=(unsigned char) i;
      //printf("%d \n",i);
     /* fwrite(message,1,3,f);
      fflush(f);
      usleep(delai);*/
  //} 
  // }
  
  /*for(i=vmax;i>vmin;i--)
   {
      message[2]=(unsigned char) i;
      printf("%d \n",i);
      fwrite(message,1,3,f);
      fflush(f);
      usleep(delai); 
   }

  for(j=0;j<12;j++)
  {
       message[1]=(unsigned char) j;
       message[2]=(unsigned char) 180;
       fwrite(message,1,3,f);
  }

      fflush(f);
   sleep(1);

 
    for(i=0;i<30;i++)
     {
      for(j=0;j<12;j++)
      {
       message[1]=(unsigned char) j;
       message[2]=(unsigned char) 180+i;
       fwrite(message,1,3,f);
      }
       fflush(f);
       usleep(delai); 
    }
   


 fclose(f);

 /* fprintf(f,"\xFF\x00\x10");
  printf("\xFF\x00\x10");
  sleep(1);
  fprintf(f,"\xFF\x00\xD0");
  sleep(1);
  fclose(f);*/









