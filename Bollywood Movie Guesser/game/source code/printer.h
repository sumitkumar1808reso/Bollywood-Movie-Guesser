
print(char movie[50])
{
int i;

for(i=0;movie[i]!='\0';i++)
{

if(movie[i]<97)
printf("%c",movie[i]);
else
printf("_");
}

}
