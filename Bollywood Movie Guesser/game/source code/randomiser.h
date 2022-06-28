/*this function gives a random number from 0 to n*/
#include<time.h>
int random()
{
	time_t seconds;
	int k=time(NULL);
	k=k%99;
	return k;	
}
