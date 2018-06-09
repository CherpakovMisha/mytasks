#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h> 

char* ReadString(FILE* in)
{
	char symbol = 1;
	int i = 1, k = 0;
	char* line = NULL;
	while (symbol != '\n' && symbol != EOF)
	{
		line = (char*)realloc(line, i);
		symbol = (char)fgetc(in);
		if (line == NULL)
		{
			while (symbol != '\n' && symbol != EOF)
			{
				symbol = (char)fgetc(in);
				k++;
			}
			if (symbol != -1 || k != 0)
			free(line);
			if (symbol == '\n')
				return "";
			else
				return NULL;
		}
		line[i - 1] = symbol;
		i++;
		k = 0;
	}
	if (line[i - 2] == '\n')
		line[i - 2] = '\0';
	if (line[i - 2] == EOF)
	{
		line[i - 2] = '\0';
		if ((strlen(line)) > 0) {
			free(line);
			return NULL;
		}
		else
		{
			free(line);
			return NULL;
		}
	}
	return line;
}


int main(int argc, char const*argv[])
{
	FILE *file;
	FILE *in = stdin;
	fopen_s(&file, argv[1], "r");
	if(file == NULL)
	{
		printf("file is not open\n");
		return 0;
	}
	char *stdin_string = NULL;
	char *file_string = NULL;
	char *exit_ = "exit";
	
	while (1)
	{
		bool yes = false;
		stdin_string = ReadString(in);
		if (strcmp(stdin_string, exit_) == 0)
		{
			return 0;
		}
		while((file_string = ReadString(file)) != NULL)
		{
			if (strcmp(stdin_string, file_string) == 0){
				printf("YES\n");
				yes = true;
				break;
			}
		}
		if (!yes){
			printf("NO\n");
		}
		fseek(file, 0, SEEK_SET);
	}
	

	free(stdin_string);
	free(file_string);
	free(exit_);
	fclose(in);
	fclose(file);

	return 0;
}