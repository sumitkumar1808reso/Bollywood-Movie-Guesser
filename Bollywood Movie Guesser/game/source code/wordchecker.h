int checker(char a[]){
	int i,k=0;
	for(i=0;a[i]!='(';i++)
{
	if(a[i]>96&&a[i]<173)
	{
	k++;
	}
}
if(k==0)
return 0;
else
return 1;	
}
