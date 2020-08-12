/* 
**  ZACHARIAS PAPANASTASIS
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
void fillTable(int n,int m,char **table,int **visited,int level,int *x,int *y,int *banana);
void printTable(int n,int m,char name[],char **table,int **visited,int mode);
int checkMove(int n,int m,int x,int y,int banana,char move[],char **table,int **visited);
void help(int n,int m,int x,int y,char **table,int **visited,int *score);
int Move(int n,int m,int *x,int *y,int *banana,char move[],char **table,int **visited,int *life,int *score);
int main(){///////int main
     char wait[25];
     int i,j,n,m,level;
     int **visited;
     char name[25];
     char **table;
     char move[25];
     int x,y,banana;
     int chm,mv,rnd;
     int exit=0;
     int life=1;
     int score=1000,totalscore=0;
     printf("*************************\n\n");
     printf("   50 Shades Of Tarzan   \n\n");
     printf("*************************\n\n");
     printf("-- Enarxi Paixnidiou -- \n\n");
     
     printf("Dwse tis grammes N gia to tablo , apo 8 ews kai 30 :  ");
     scanf("%d",&n);
     while(n<8||n>30){
     printf("To N apo 8 ews kai 30! Prospathise xana:  ");
     scanf("%d",&n);                 
     }
     
     printf("Dwse tis Stiles  M gia to tablo , apo 8 ews kai 30 :  ");
     scanf("%d",&m);
     while(m<8||m>30){
     printf("To M apo 8 ews kai 30! Prospathise xana:  ");
     scanf("%d",&m);                 
     }
     
     printf("Dwse to onoma tou paixti: ");
     scanf("%s",&name);
     
     printf("Epelexe epipedo diskolias:\n");
     printf("\t1.eukolo     (1)\n");
     printf("\t2.metrio     (2)\n");
     printf("\t3.duskolo    (3)\n");
     printf("\t4.akatorthwto(4)\n\n");
     scanf("%d",&level);
     while(level<1||level>4){
     printf("La8os eisodos! 1,2,3 h 4 :  ");
     scanf("%d",&level);                 
     }
     
     table=(char**)malloc(n*sizeof(char*));                     //dhmiourgia pinaka table
     for(i=0;i<n;i++){
                      table[i]=(char*)malloc(m*sizeof(char));
     }
     for(i=0;i<n;i++){
             for(j=0;j<m;j++){
                              table[i][j]='.';                          
             }    
     }
     visited=(int**)malloc(n*sizeof(int*));                      
     for(i=0;i<n;i++){
                      visited[i]=(int*)malloc(m*sizeof(int));
     }
     for(i=0;i<n;i++){
             for(j=0;j<m;j++){
                              visited[i][j]=0;                          
             }    
     }
         
     fillTable(n,m,table,visited,level,&x,&y,&banana);
     printTable(n,m,name,table,visited,1);
     printf("Player %s press\na key when ready  \n",name);
     scanf("%s",&wait);
     printTable(n,m,name,table,visited,0);
     printf("Player %s make\nyour move(s):  ",name);
     while(exit!=1){                     ////rounds
                    
                    do{                                                                //diavasma kai elegxos kinisis
                        scanf("%s",move);
                        chm=checkMove(n,m,x,y,banana,move,table,visited);
                        if(chm==0){                                                    //diavase 'x' h 'X'   --> Exodos        
                                   printf("Total Score: %d",totalscore);
                                   printf("\nGame Over\n");
                                   exit=1;
                        }//if
                        if(chm==1){                                                    //swsth eisodos       --> kinisi tarzan
                                  mv=Move(n,m,&x,&y,&banana,move,table,visited,&life,&score);
                                  if(mv==0){                                                                 //liontari h Zulu
                                            exit=1;
                                            printf("Total Score: %d",totalscore);
                                            printf("\nGame Over\n");
                                  }//if
                                  if(mv==1){                                                                 //Jane
                                            //printscore
                                            printf("Round Score: %d\n",score);
                                            totalscore+=score;
                                            printf("Total Score: %d\n",totalscore);
                                            printf("\nPlayer %s press a key \nfor the next stage  \n",name);
                                            scanf("%s",&wait);
                                            for(i=0;i<n;i++){                                          
                                                             free(table[i]);
                                            }
                                            free(table);
                                            for(i=0;i<n;i++){                                          
                                            free(visited[i]);
                                            }
                                            free(visited);
     
                                            srand(time(NULL));
                                            rnd=rand()%2;
     
                                            if(n<30&&m<30){
                                                           if(rnd==0){n++;}
                                                           else{m++;}
                                            }//if
                                            if(n>29||m>29){
                                                           if(n<30){n++;}
                                                           if(m<30){m++;}
                                            }//if
                                            
                                            table=(char**)malloc(n*sizeof(char*));                     
                                            for(i=0;i<n;i++){
                                            table[i]=(char*)malloc(m*sizeof(char));
                                            }
                                            for(i=0;i<n;i++){
                                                                for(j=0;j<m;j++){
                                                                               table[i][j]='.';                          
                                                                }    
                                            }
                                            visited=(int**)malloc(n*sizeof(int*));                      
                                            for(i=0;i<n;i++){
                                                                visited[i]=(int*)malloc(m*sizeof(int));
                                            }
                                            for(i=0;i<n;i++){
                                                             for(j=0;j<m;j++){
                                                                              visited[i][j]=0;                          
                                                             }    
                                            }     
                                            fillTable(n,m,table,visited,level,&x,&y,&banana);
                                            life=1;                                            
                                            score=1000;
                                            printTable(n,m,name,table,visited,1);
                                            printf("Player %s press\na key when ready  \n",name);
                                            scanf("%s",&wait);
                                            
                                            printTable(n,m,name,table,visited,0);
                                            printf("Player %s make\nyour move(s):  ",name);
                                  }//if
                                  if(mv==2){                                                                 //Zulu 1i fora
                                            printTable(n,m,name,table,visited,0);
                                            printf("Tarzan is injured!\n  ");
                                            printf("Player %s make\nyour move(s):  ",name);
                                  }//if
                                  if(mv==3){                                                                        
                                            printTable(n,m,name,table,visited,0);
                                            printf("Player %s make\nyour move(s):  ",name);
                                  }//if
                                  
                        }//if
                        if(chm==2){                                                    //La8os eisodos                
                                   printf("\nLa8os kinisi!\nProspa8ise xana.\n");
                        }//if
                        
                        if(chm==3){                                                    //Voei8eia 8eou ougantougkou
                                   help(n,m,x,y,table,visited,&score);
                                   printTable(n,m,name,table,visited,0);
                        }//if
                        
                    }while(chm==2);
     
     }//while
     for(i=0;i<n;i++){                                          //apodesmeusi mnhmhs
                      free(table[i]);
     }
     free(table);
     for(i=0;i<n;i++){                                          //apodesmeusi mnhmhs
                      free(visited[i]);
     }
     free(visited);
     //scanf("%s",&wait); 
     return 0;
}
void printTable(int n,int m,char name[],char **table,int **visited,int mode){
     int i,j;
     if(mode==1){
                 printf("\n   ");
                 for(j=0;j<m;j++){                                                        //1h grammh
                       printf("%2d",j+1);                  
                 }
                 printf("\n");
                 printf("---");                                                           //2h grammh
                 for(j=0;j<m;j++){                                                      
                      printf("--");                  
                 }//for
                 for(i=0;i<n;i++){                                                        //upoloipos pinakas
                      printf("\n%2d|",i+1);   
                      for(j=0;j<m;j++){                           
                          printf(" %c",table[i][j]);                  
                      }//for
                 }//for
                 printf("\n\n ");
     }//if  !round->0 
     else{
                 printf("\n   ");
                 for(j=0;j<m;j++){                                                        //1h grammh
                       printf("%2d",j+1);                  
                 }
                 printf("\n");
                 printf("---");                                                           //2h grammh
                 for(j=0;j<m;j++){                                                      
                      printf("--");                  
                 }//for
                 for(i=0;i<n;i++){                                                        //upoloipos pinakas
                      printf("\n%2d|",i+1);   
                      for(j=0;j<m;j++){
                          if(visited[i][j]==1||visited[i][j]==2){                           
                              printf(" %c",table[i][j]);
                          }//if
                          else{
                              printf(" #"); 
                          }//else                  
                      }//for
                 }//for
                 printf("\n\n ");                     
     }//else
}//printTable
void fillTable(int n,int m,char **table,int **visited,int level,int *x,int *y,int *banana){
     int cells,lions,zulu,pos,i,j;
     cells=m*n;
     
     
     if(level==1){
                  lions=cells*2/100;
     }else if(level==2){
                        lions=cells*5/100;
     }else if(level==3){
                        lions=cells*10/100;
     }else{
                        lions=cells*20/100;
     }//if
     
     zulu=lions+(50/100)*lions;
     srand(time(NULL));
     
     while(lions>0){                                                                  //insert lions
                    pos=rand()%cells;
                    i=pos/m;
                    j=pos%m;
                    if(table[i][j]=='.'){
                                         table[i][j]='L';
                                         lions--;
                    } //if
     }//while
     
     while(zulu>0){                                                                   //insert zulu
                    pos=rand()%cells;
                    i=pos/m;
                    j=pos%m;
                    if(table[i][j]=='.'){
                                         table[i][j]='Z';
                                         zulu--;
                    } //if
     }//while
     
     do{                                                                           //insert Tarzan
        pos=rand()%cells;
        i=pos/m;
        j=pos%m;
        if(table[i][j]=='.'){
                            table[i][j]='T';
                            visited[i][j]=1;
                            *x=i;
                            *y=j;
                            *banana=1;
        }        
     }while(table[i][j]!='T');
     
     do{                                                         //insert Jane
        pos=rand()%cells;
        i=pos/m;
        j=pos%m;
        if(table[i][j]=='.'){
                            table[i][j]='J';                            
        }     
           
     }while(table[i][j]!='J');
     return;
}//fillTable
int checkMove(int n,int m,int x,int y,int banana,char move[],char **table,int **visited){
    int len,i;
    int exit=1;
    len=strlen(move);
    for(i=0;i<len;i++){
                       if(move[i]=='u'||move[i]=='U'){
                                                      if((x-1)<0){
                                                                  exit=2;
                                                      }else{
                                                                  x-=1;
                                                      }//if
                       }else if(move[i]=='d'||move[i]=='D'){
                                                            if((x+1)>(n-1) ){
                                                                              exit=2; 
                                                            }else{
                                                                              x+=1;
                                                            }//if
                       }else if(move[i]=='r'||move[i]=='R'){
                                                            if((y+1)>(m-1) ){
                                                                              exit=2; 
                                                            }else{
                                                                              y+=1;
                                                            }//if
                       }else if(move[i]=='l'||move[i]=='L'){
                                                            if((y-1)<0 ){
                                                                              exit=2; 
                                                            }else{
                                                                              y-=1;
                                                            }//if
                       }else if(move[i]=='x'||move[i]=='X'){
                                                           return 0;
                       }else if(move[i]=='h'||move[i]=='H'){
                                                           if(i==0&&len==1){
                                                                            return 3;
                                                           }else {
                                                                            exit=2;
                                                           }//if
                       }else if(move[i]=='b'||move[i]=='B'){                            
                                                           if((i+1)>(len-1)||banana!=1){
                                                                             exit=2;
                                                           }else{
                                                                 i++;
                                                                 banana=0;
                                                                 if(move[i]=='u'||move[i]=='U'){
                                                                                                if((x-2)<0){
                                                                                                exit=2;
                                                                                                }else{
                                                                                                      x-=2;
                                                                                                }//if
                                                                 }else if(move[i]=='d'||move[i]=='D'){
                                                                                                  if((x+2)>(n-1) ){
                                                                                                  exit=2; 
                                                                                                  }else{
                                                                                                  x+=2;
                                                                                                  }//if
                                                                 }else if(move[i]=='r'||move[i]=='R'){
                                                                                                  if((y+2)>(m-1) ){
                                                                                                  exit=2; 
                                                                                                  }else{
                                                                                                  y+=2;
                                                                                                  }//if
                                                                 }else if(move[i]=='l'||move[i]=='L'){
                                                                                                  if((y-2)<0 ){
                                                                                                  exit=2; 
                                                                                                  }else{
                                                                                                  y-=2;
                                                                                                  }//if
                                                                 }else if(move[i]=='x'||move[i]=='X'){
                                                                                                   return 0;
                                                                 }else{
                                                                       exit=2;
                                                                 }//if
                                                           }//if
                       }else{
                             exit=2;
                       }//if
                       if(visited[x][y]==1){
                                            exit=2;                   
                       }//if
    }//for
    return exit;
}//checkMove
void help(int n,int m,int x,int y,char **table,int **visited,int *score){
     
     int  loc_i[4];
     int  loc_j[4];
     int num1,num2;
     int counter=0;
     
     if(x>0&&visited[x-1][y]==0){
             loc_i[counter]=x-1;
             loc_j[counter]=y;
             counter++;
     }//if
     if(x<n-1&&visited[x+1][y]==0){
             loc_i[counter]=x+1;
             loc_j[counter]=y;
             counter++;
     }//if
     if(y>0&&visited[x][y-1]==0){
             loc_i[counter]=x;
             loc_j[counter]=y-1;
             counter++;
     }//if
     if(y<m-1&&visited[x][y+1]==0){
             loc_i[counter]=x;
             loc_j[counter]=y+1;
             counter++;
     }//if
     
     
     if(counter>0){
                   if(counter==1){
                                  if(visited[loc_i[0]][loc_j[0]]==0){
                                                                      visited[loc_i[0]][loc_j[0]]=2;
                                                                      *score-=40;
                                  }//if
                   }
                   else if(counter==2){
                                  if(visited[loc_i[0]][loc_j[0]]==0){
                                                                     visited[loc_i[0]][loc_j[0]]=2;
                                                                     *score-=40;
                                  }//if
                                  if(visited[loc_i[1]][loc_j[1]]==0){
                                                                     visited[loc_i[1]][loc_j[1]]=2;
                                                                     *score-=40;
                                  }//if
                   }else{
                         srand(time(NULL));
                         num1=rand()%counter;
                         
                         do{
                            num2=rand()%counter;
                         }while(num2==num1);
                         
                         if(visited[loc_i[num1]][loc_j[num1]]==0){
                                                                  visited[loc_i[num1]][loc_j[num1]]=2;
                                                                  *score-=40;
                         }//if
                         if(visited[loc_i[num2]][loc_j[num2]]==0){
                                                                  visited[loc_i[num2]][loc_j[num2]]=2;
                                                                  *score-=40;
                         }//if
                         
                   }//else
     
                         
     }else{
           return;
     }//else
     
     if(*score<0){
                  *score=0;
     }//if
     
     return;
}//help
int Move(int n,int m,int *x,int *y,int *banana,char move[],char **table,int **visited,int *life,int *score){
    int len,i,penalty;
    int hurt=0;
    len=strlen(move);
    
    if(len==1){penalty=50;} 
    else if(len==2){penalty=45;}
    else if(len==3){penalty=40;} 
    else if(len==4){penalty=35;} 
    else           {penalty=30;} 
    
    for(i=0;i<len;i++){ 
                        if(table[*x][*y]=='T'){
                                             table[*x][*y]='.';
                        }else{
                                             table[*x][*y]='Z';
                        }//if
                        
                        if(move[i]=='u'||move[i]=='U'){
                                                             *x-=1;
                        }else if(move[i]=='d'||move[i]=='D'){
                                                             *x+=1;
                        }else if(move[i]=='r'||move[i]=='R'){
                                                             *y+=1;
                        }else if(move[i]=='l'||move[i]=='L'){
                                                             *y-=1;
                        }else{
                              i++;
                              if(move[i]=='u'||move[i]=='U'){
                                                                  *x-=2;
                              }else if(move[i]=='d'||move[i]=='D'){
                                                                  *x+=2;
                              }else if(move[i]=='r'||move[i]=='R'){
                                                                   *y+=2;
                              }else{
                                                                  *y-=2;
                              }//if 
                        }//if                                                      
                        
                        if(table[*x][*y]=='L'){
                                             printf("\nEpeses se liontari.\n");
                                             return 0;
                        }else if(table[*x][*y]=='J'){
                                                   printf("\nEftases sth sphlia ths Jane!\n");
                                                   
                                                   if((*score)-(penalty*len)>=0){(*score)-=penalty*len;}
                                                   else {(*score)=0;}
                                                   
                                                   return 1;
                        }else if(table[*x][*y]=='Z'){
                              if(*life==0){
                                           printf("\nEpeses 2i fora se Zulu.\n");
                                           return 0;
                              }else{
                                           *life=0;
                                           table[*x][*y]='@';
                                           visited[*x][*y]=1;
                                           hurt=1;
                              }//if
                        }else{
                                           table[*x][*y]='T';
                                           visited[*x][*y]=1;
                        }//if
                        
    }//for
    
    if((*score)-(penalty*len)>=0){(*score)-=penalty*len;}
    else {(*score)=0;} 
    
    if(hurt==1){
                if((*score)-100>=0){(*score)-=100;}
                else{(*score)=0;}
                return 2;
    }//if    
    return 3;
}//move
