void save(int n)
{
	FILE *ft;
	ft=fopen("score.dat","w");
	fprintf(ft,"%d",n);
	fclose(ft);
}
