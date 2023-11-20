#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>

int check(int *a){
	if(scanf("%d", a) ==1){
		if(*a <0){
			return 0;
		}
		return 1;
	}
	else{
		printf("syntaxis error\n");
		while(getchar() != '\n');
		return 0;
	}
}

void write(struct video *arr, int n){
	if(n<=0)
		return;
	FILE *f=fopen("file.txt", "w");
	if(!f){
		printf("error");
		return;
	}
	fprintf(f, "%d\n", n);
	for(int i =0; i<n; i++)
		fprintf(f, "%s %d %d %d\n", arr[i].name, arr[i].views, arr[i].likes, arr[i].dislikes);
	fclose(f);

}



void read(struct video **arr, int *n){
	FILE *f=fopen("file.txt", "r");
	if(!f)
		return;
	if(fscanf(f, "%d", n)!=1)
		return;
	if(*n<=0) return;
	*arr=(struct video *)calloc(*n, sizeof(struct video));
	for(int i=0; i<*n;i++)
		fscanf(f, "%s %d %d %d",(*arr)[i].name, &(*arr)[i].views, &(*arr)[i].likes, &(*arr)[i].dislikes);
	fclose(f);
}

int create(struct video **arr, int *n){
	printf("n=");
	scanf("%d", n);
	//printf("%d\n", *n);
	if(*n <=0){
		n=0;
		while(getchar() != '\n');
		return 0;
	}
	*arr = (struct video *)calloc(*n, sizeof(struct video));
	for(int i=0; i<*n; i++){
		printf("name=");
		scanf("%41s",(*arr)[i].name);
		while(getchar() != '\n');
		printf("views=");
		if(!check(&(*arr)[i].views)) return 0;
		printf("likes=");
		if(!check(&(*arr)[i].likes)) return 0;
		printf("dislikes=");
		if(!check(&(*arr)[i].dislikes)) return 0;
	}
	return 1;
}


void search(struct video *arr, int n, int mode){
	int mn;
	int mx;
	switch(mode){
		case 1:
			char str[40];
			printf("name=");
			scanf("%41s", str);
			while(getchar() != '\n');
			for(int i=0; i<n; i++){
				if(!strcmp(arr[i].name, str)){
					printf("%s %d %d %d\n", arr[i].name, arr[i].views, arr[i].likes, arr[i].dislikes);
				}
			}
			break;
		case 2:
			printf("enter min value\n");
			if(!check(&mn)) return;
			printf("enter max value\n");
			if(!check(&mx)) return;
			for(int i=0; i<n;i++){
				//printf("%d %d %d", mn, arr[i].views, mx);
				if(mn <= arr[i].views && arr[i].views <= mx){
					printf("%s %d %d %d\n", arr[i].name, arr[i].views, arr[i].likes, arr[i].dislikes);
				}
			}
			break;
		case 3:
                        printf("enter min value\n");
                        if(!check(&mn)) return;
                        printf("enter max value\n");
                        if(!check(&mx)) return;
                        for(int i=0; i<n;i++){
                                if(mn<=arr[i].likes && arr[i].likes<=mx){
                                        printf("%s %d %d %d\n", arr[i].name, arr[i].views, arr[i].likes, arr[i].dislikes);
                                }
                        }
			break;
		case 4:
                        printf("enter min value\n");
                        if(!check(&mn)) return;
                        printf("enter max value\n");
                        if(!check(&mx)) return;
                        for(int i=0; i<n;i++){
                                if(mn<=arr[i].dislikes && arr[i].dislikes<=mx){
                                        printf("%s %d %d %d\n", arr[i].name, arr[i].views, arr[i].likes, arr[i].dislikes);
                                }
                        }
			break;
		default:
			printf("syntaxis error\n");
			return;
	}
}
