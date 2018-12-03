//Loop Reordering

// void dgemm( int m, int n, float *A, float *C )
// {
// 	for( int k = 0; k < n; k++ ) 
// 		for( int i = 0; i < m; i++ )
// 			for( int j = 0; j < m; j++ ) 
// 				C[i+j*m] += A[i+k*m] * A[j+k*m];
	
// }


//Loop Unrolling
void dgemm( int m, int n, float *A, float *C )
{
	for( int i = 0; i < m; i++ )
	{
		for( int k = 0; k < n-3; k+=4 ) 
		{		
			for( int j = 0; j < m-3; j+=4 )
			{
				C[i+j*m] += A[i+k*m] * A[j+k*m];
				C[i+(j+1)*m] += A[i+(k+1)*m] * A[j+(k+1)*m];
				C[i+(j+2)*m] += A[i+(k+2)*m] * A[j+(k+2)*m];
				C[i+(j+3)*m] += A[i+(k+3)*m] * A[j+(k+3)*m];
			}
		}
	}
}

//Matrix Padding
/*void dgemm( int m, int n, float *A, float *C )
{
	if(m != n){
		if(m < n){
			for(i = m+1; i < n; i++){
				A[i*n] = 0;
			}
		}
		else{
			for(i = n+1; i < m; i++){
				A[i*m] = 0;
			}
		}
	}
	for( int i = 0; i < m; i++ )
		for( int k = 0; k < n; k++ ) 
			for( int j = 0; j < m; j++ ) 
				C[i+j*m] += A[i+k*m] * A[j+k*m];
	
}*/
