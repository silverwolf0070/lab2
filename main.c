#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(){

	struct video *arr = NULL;
	int n=0;
	int stop=0;
	int i = 0;
	while(stop!=1){
		int key=0;
		printf("attemp %d\n", i);
		i=i+1;
		printf("1-create, 2-read, 3-print, 4-search by name, 5-quit\n");
		printf("key=");
		scanf("%d", &key);
		switch(key){
			case 1:
				int b = create(&arr, &n);
				if(arr && b!=0)
					write(arr,n);
				else{
					printf("syntaxis error\n");
				}
				break;
			case 2:
				read(&arr, &n);
				if(!arr)
					printf("read error");
				else
					printf("loaded %d\n",n);
				break;
			case 3:
				read(&arr, &n);
				for(int i=0; i<n; i++)
					printf("%s %d %d %d\n", arr[i].name, arr[i].views, arr[i].likes, arr[i].dislikes);
				break;
			case 4:
				read(&arr, &n);
				if(!arr) printf("read error");
				else{
					char str[40];
					printf("name=");
					scanf("%41s", str);
					while(getchar()!='\n');
					search(arr, n, str);
				}
				break;
			case 5:
				stop = 1;
				break;
			default:
				while(getchar() != '\n');
				break;
		}
	}
	if(arr)
		free(arr);
	return 0;
}
