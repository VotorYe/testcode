#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

int main() {
	int length[5] = {10, 100, 1000, 10000, 100000};
	const int count = 5;
	FILE *file;
	if ((file = fopen("data.txt", "wt+")) == NULL) {
		printf("fail to open file\n");
		return 0;
	}

	for (int k = 0; k < count; ++k)
	{
		int size = length[k]+1;
		char buffer[size];
		bzero(buffer, size);
		for (int i = 0; i < size; ++i)
		{
			buffer[i] = ' ' + (int)(95.0*rand()/(RAND_MAX+1.0));
		}
		buffer[size] = '\0';
		fputs(buffer, file);
		fputs("\n",file);
		//fwrite(buffer, 1, length[k]+1, file);
	}
	fclose(file);
	return 0;
}
