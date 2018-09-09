/*
Andres Rodart
110 is a mark numbrer, just to know when the pile has nothing
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int factoria(unsigned long long int num){
	if (num == 1 || num == 0)
		return 1;
	if (num > 1)
		return (num*(factoria(num-1)));
}
int serie_(int num){
	if (num==1 || num==0)
		return 0;
	if (num>1)
		return (num+(serie_(num-1)));
}
void push(int **hanoi, int num){
	for (int i = 0; i < 10; ++i)
			if ((*hanoi)[i]==0 || (*hanoi)[i]==110){
				(*hanoi)[i]=num;
				break;
			}
}
int pop(int **hanoi){
	for (int i = 9; i >= 0; --i){	
		if ((*hanoi)[i]!=0 && (*hanoi)[i]!=110){
			int our;
			our=(*hanoi)[i];
			(*hanoi)[i]=0;
			//printf("pop %i\n", our);
			return our;
		}
	}
}
int last_(int tower[]){ //Found Last position
	for (int i = 9; i >= 0; --i)
		if (tower[i]!=0 ){
			if (tower[i]==110)
				return 0;
			return i;
        }
}
void printor(int tower[], int id){ //To print the towers transitions
	int firstElement = last_(tower);
	printf("\nTower: %i\n",id);

	for (int j = firstElement; j > -1; --j){
		for (int i = 0; (i < tower[j]) && (tower[j]!=110); ++i)
			printf("=");
		printf("||");
		for (int i = 0; (i < tower[j]) && (tower[j]!=110); ++i)
			printf("=");
		//printf("%i\n", tower[j]);
		printf("\n");
	}
}

int algo(int num, int * tower1,int id1, int * tower3, int id3,int * tower2, int id2){
	int firstElement = last_(tower1), dos=last_(tower2), tres=last_(tower3);	

	if (num == 0){
		int disc = pop(&(tower1));
		push(&(tower3),disc);
		printor((tower1),id1);
		printor((tower2),id2);
		printor((tower3),id3);
		printf("***************************************************");
		return 0;
	}else{
		algo((num-1),tower1, id1, tower2, id2, tower3, id3);
		printor((tower1),id1);
		printor((tower2),id2);
		printor((tower3),id3);
		printf("***************************************************");
		int disc = pop(&(tower1));
		push(&(tower3) ,disc);
		printor((tower1),id1);
		printor((tower2),id2);
		printor((tower3),id3);
		printf("***************************************************");
		algo((num-1), tower2, id2, tower3, id3, tower1, id1);
		printor((tower1),id1);
		printor((tower2),id2);
		printor((tower3),id3);
		printf("***************************************************");

	}
}


int main(){
	int rep = 0, menu = 2, tower1[10], tower2[10], tower3[10], num, j = 0;
	
    while(rep != 1){
		printf("\nVisualize the resolve of the Hanoi Towers")
        //printf("\nIf you wish to calculate the factorial of a natural number type 1\nIf you whish to see the Hanoi towers type 2: ");
		//scanf("%i",&menu);

		if (menu == 1){	
            printf("\nEnter the number: ");
			scanf("%i",&num);
			printf("%d\n",(factoria(num)));
		}
		if (menu == 2){	
			for (int i = 0; i < 10; ++i){
				tower1[i]=0;
				tower2[i]=0;
				tower3[i]=0;
			}
			
            tower2[0]=110;
			tower3[0]=110;
			
            printf("\nEnter the number of discs from 1-10: ");
			scanf("%i",&num);
			
            for (int i = num; i > 0; --i){
				tower1[j] = i;
				j++;
			}
			printor((tower1),1);
			printor((tower2),2);
			printor((tower3),3);
			printf("***************************************************");
			algo(num, tower1, 1, tower2, 2, tower3, 3);
		}
		printf("\nWanna close? (1): ");
    	scanf("%i",&rep);
	}
	return 0;
}