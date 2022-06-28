int changer(char a[],char ch){
	int i,k=0;
	for(i=0;a[i]!='(';i++)
{
	if(a[i]==ch)
	{
	a[i]=a[i]-32;
	k++;
	}
}
if(k!=0)
return 0;
else
return 1;	
}
