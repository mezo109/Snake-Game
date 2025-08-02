//control and draw class 
#include<fstream>
#include<cmath>
#include <windows.h>
#include<iostream>
#include<conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class food {
public:
    int fruitx, fruity;//coordinates of food
    food() {  }//constructor
    int RandomPositionx(int width) {//generate eandom position of x
         srand(static_cast<unsigned int>(time(0)));
      
         return 1+ rand() % (width-1);  
     }

  int RandomPositiony( int height) {//generate random postion of y
         srand(static_cast<unsigned int>(time(0)));       
         return rand() %(height+1); 
     }
     
    void eat(int width, int height) {//generate random coordinates of fruit
      fruitx= RandomPositionx(width);
       fruity= RandomPositiony( height);
      
      
    }
};
class snake{
	public:
		int x, y;//coordinates of snake head
         int   ntail = 0;//variable indicating rail length
			int tailx[301]={-1};//xy one to one arrys of tail coordinates indicating coordinates of each tail part
			int taily[301]={-1};
			int prex ,prey;//used for swap and intiating the swap of the tail
			int prex2 ,prey2;//also used for swapping between variable pre and array for temporary values
	};
enum direction {STOP=0,UP,DOWN,LEFT,RIGHT,};

class game:protected snake,protected food{
private:
bool gameover=false;
public:
direction dir=STOP;
bool print=false;//ensures the grid doesn't get flawed by entering a tail character and space
const int width = 40;//two times larger than the expected grid
const int hight = 20;
int score;
int obsx[20]={0};//obscales coordinate arrays
int obsy[20]={0};
int nobs=1;//indcates number of obscales to appear

bool endofgame(){
    return gameover;
    }
 game () {
   eat(width,hight);//first fruit to be eaten ,fruit of life,it will generate a random position for fruit
	x=width/2;
    y=hight/2;
	gameover = false;//for main loop of the ge,it indicates the end of execution of the game
	score = 0; 
  obsx[0]=(1+(5+RandomPositionx(width))%(width-1));
obsy[0]=((5+RandomPositiony(hight))%hight);
     		}				
void draw(){
	gameover = false;
	system("cls");
	cout << "to pause game press p,to end game session press x" << endl;
    for (int i =0;i<width+2;i++)
  	cout<<"#";		
  	cout<<endl;
        for (int i =0;i<=hight;i++){
	       for (int j =0;j<=width;j++){
	       print=false;
			if (j==0 or j ==width)
				cout<<"#";		
			else if( j==x&& i==y){
						cout<<"O";
						print=true;
				}
			else if(j==fruitx&&i==fruity){
						cout<<"$";
						print=true;
				}
			else {
                    for(int c=1;c<=ntail;c++) {
                       if(j==tailx[c] &&i==taily[c]){
                            cout << "o";
                            print=true;
                            }                      
                       }
                   }    
                     for(int c=0;c<nobs;c++) {
                       if(!print){//making sure a tail was not printed in spot
                         if(j==obsx[c] &&i==obsy[c]){
                            cout << "#";
                            print=true;
                            }
                  }
                 }
			   if(!print){
                  cout<<" ";
			   }
			  }	
			cout<<"\n";
}	   		
			for (int i =0;i<width+2;i++){
				cout<<"#";
               }
              cout<<endl;
              cout << "score="<<score<<endl;
}
void input(){
if(_kbhit())
   switch(_getch()){//enumerating input
   case 'a':
   dir=LEFT;
   break;
   case 'w':
   dir=UP;
   break;
   case 's':
   dir=DOWN;
   break;
   case 'd':
   dir=RIGHT;
   break;
   case 'p':
   dir=STOP;
   break;
   case 'x':{
   gameover=true;
  cout<<"\n"<<"final score : "<<score;
   }
   break;
   }
  }
void logic(){//verify end of game condtions and excute change before drawing it
tailx[0] = x;
taily[0] = y;
prex=tailx[0];
prey=taily[0];
if(dir!=STOP)
         for(int i=1;i<=ntail;i++)
            {//setting up the tail parts from previous part positions
               prex2=tailx[i];
               prey2=taily[i];
               tailx[i]=prex;
               taily[i]=prey;
               prex=prex2;
               prey=prey2;
               }

switch(dir){//change postion of snake from input
   case LEFT:
   x--;
   break;
   case UP:
   y--;
   break;
   case DOWN:
   y++;
   break;
   case RIGHT:
   x++;
   break;
   case STOP://stops the game temporarily by change the status of enum
   cout << "game stopped 🛑" << endl;

}
//for wrapping around the map by reseting axis coordinate to start or end of grid ,depends on movement direction
if(x>=width)
x=1;
else if(x<=0)
x=width-1;
else if(y>hight)
y=0;
else if(y<0)
y=hight;

if(dir!=STOP)
       for(int i=1;i<=ntail;i++){
            if(x==tailx[i]&&y==taily[i]){
            	gameover = true;
			cout<<"\n"<<"final score : "<<score;
            	}
            }
			
		for(int i=0;i<nobs;i++){
			if(x==obsx[i]&&y==obsy[i]){
				gameover = true;
			cout<<"\n"<<"final score : "<<score;
			}
		}			
		  if(x== fruitx&& y ==fruity){			
		  score+=10;
			ntail =(ntail+1)%300;//making sure tail length varible doesn't get more than the expected tail length'
			eat( width,hight);
 if(ntail%3==0&&ntail!=0){
		       if(nobs<20)
		     nobs=nobs+1;
 }
		for(int i=0;i<nobs;i++){//to get a different random position for the obscale different than the fruit and bounded by the grid using mod and a factor of 3 and 5 and loop variable
  obsx[i]=(1+(3*(i+1)+(RandomPositionx(width)))%(width-1));
  obsy[i]=(((1+i)*5+(RandomPositiony(hight)))%hight);
       for(int j=0;j<ntail;j++){
	    if(obsx[i]==tailx[j]&&obsy[i]==taily[j]){
		    if(obsx[i]<width-1)
		        obsx[i]+=1;
		       else if(obsx[i]==width-1)
		       obsx[i]-=2;    
		      if(obsy[i]<hight)
		        obsy[i]+=1;
		       else if(obsy[i]==hight)
		       obsy[i]-=2; 
	      }
	    }
		    }  
		  }
}
};
int main(){
  
  char x='s';//to determine closure of game or continuing a new session 
   do{
    game *gg=new game();
       while (!gg->endofgame()){
    gg->draw();
    gg->input();
    gg->logic();
    Sleep(500+(250/gg->nobs));//increasing each time new obstacles appears
     }
     delete gg;
  ofstream file("score.txt",ios::app);
    if(gg->score >150)//ensuring only scores higher than150 to be written
    file<<" highest score of the session is "<<gg->score<<endl;
    file.close();
     cout<<"to close game press x,to restart press any other key:";
     cin>>x;}     
     while(x!='x');    
    return 0;
}