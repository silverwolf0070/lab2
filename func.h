struct video{
	char name[40];
	unsigned int views;
	unsigned int likes;
	unsigned int dislikes;
};

void write(struct video *arr, int n);
void read(struct video **arr, int *n);
int create(struct video **arr, int *n);
void search(struct video *arr, int n, char str[40]);
