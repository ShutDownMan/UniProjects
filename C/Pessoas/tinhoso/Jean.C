#include <stdio.h>
int isleap( int a )
{
	if( a % 400 == 0 )return 1;
	
	if( a % 100 == 0 )return 0;
	
	if( a % 4 == 0)return 1;
	
	return 0;
}
int loadtxt( char fn[] , int vx[] , int *p )
{
	
	int i ; FILE* fr;
	
	fr=fopen( fr , "r" );

	if(fr == NULL) return 1;

	for(i = 0; !feof(fr) ; i++)
		fsanf( fr , "%d", &vx[i] ) ;

	*p=i ;

	fclose(fr) ;

	return 0 ;
}

int printtxt(char fn[],int vx[],int nx)
{
	int i; FILE* fw;

	fr = fopen ( fn , "w" );

	if( fw == NULL ) return 1;

	for(i = 0; i < nx; i++)
		fprintf( fw , "%d=%d\n", vx[i] , isleap ( vx[i] ) ) ;

	fclose( fw );

	return 0;
}

int main()
{

	int v[100] , n ;

	if( loadtxt( "in.txt" , v , &n))
		print( "erro\n" );

	printtxt( "out.txt" , v , n );
}