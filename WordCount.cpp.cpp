#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Node
{
	bool isC, isW, isL, isO;//记录传入的参数
	char fileName[50];//要统计的文件名字
	char outFile[50];//要输出的文件名字
	int charNum, wordNum, lineNum;//统计结果
}Node;
int main(int num, char* str[])

{
	Node node;
	node.isC = false;

	node.isW = false;

	node.isL = false;

	node.isO = false;

	strcpy(node.outFile, "result.txt");

	node.charNum = 0;

	node.wordNum = 0;

	node.lineNum = 1;

	if (strcmp(str[1], "-o") == 0)

	{

		printf("命令参数出错！");

		exit(0);

	}
	int i = 1;
	for (i = 1; i < num; i++)

	{

		if (str[i][0] == '-')

		{

			if (str[i][1] == 'c')

				node.isC = true;

			if (str[i][1] == 'w')

				node.isW = true;

			if (str[i][1] == 'l')

				node.isL = true;

			if (str[i][1] == 'o')

			{

				if (str[i + 1][0] != '-')

				{

					strcpy(node.outFile, str[i + 1]);

					i++;

				}

				else

				{

					printf("命令参数出错！");

					exit(0);

				}

				node.isO = true;

			}

		}

		else

		{

			if (strcmp(str[i - 1], "-c") == 0 || strcmp(str[i - 1], "-w") == 0 || strcmp(str[i - 1], "-l") == 0)

			{

				strcpy(node.fileName, str[i]);

			}

			else

			{

				printf("命令参数出错！");

				exit(0);

			}

		}

	}

}
