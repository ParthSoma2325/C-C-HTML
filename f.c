#include<stdio.h>
int main()
{
    FILE *file;
    char fileName[100];
    char content[800];
    int n;

    printf("Enter the file name to write\n");
    scanf("%s", fileName);
    //getch();

    file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Cannot open or create file");
        return 0;
    }

    printf("Enter the no of students\n");
    scanf("%d", &n);
    printf("Enter the name and marks of students\n");
    for (int i=0; i<=n; i++)
    {
        fgets(content, sizeof(content), stdin);
        fputs(content, file);
    }

    fclose(file);
    return 0;
}

