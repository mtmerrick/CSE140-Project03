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
	int i,j,k;
	for(i = 0; i < m; i++ )
	{
		for(k = 0; k < n; k++ ) 
		{		
			for(j = 0; j < m; j+=2 )
			{
				C[i+j*m] += A[i+k*m] * A[j+k*m];
				// if(j + 3 < m){
				// 	C[i+(j+3)*m] += A[i+k*m] * A[(j+3)+k*m];
				// }
				// if(j + 2 < m){
				// 	C[i+(j+2)*m] += A[i+k*m] * A[(j+2)+k*m];
				// }
				if(j + 1 < m){
					C[i+(j+1)*m] += A[i+k*m] * A[(j+1)+k*m];
				}
			}
		}
	}
	// switch(m-j){
	// 	case 3:
	// 	{
	// 		C[i+(j+3)*m] += A[i+k*m] * A[(j+3)+k*m];
	// 	}
	// 	case 2:
	// 	{
	// 		C[i+(j+2)*m] += A[i+k*m] * A[(j+2)+k*m];
	// 	}
	// 	case 1:
	// 	{
	// 		C[i+(j+1)*m] += A[i+k*m] * A[(j+1)+k*m];
	// 	}
	// }
		
}

//Matrix Padding
// void dgemm( int m, int n, float *A, float *C )
// {
// 	if(m != n){
// 		if(m < n){
// 			for(int i = m+1; i < n; i++){
// 				for(int j = 0; j < m; j++){
// 		 			A[i*j] = 0;
// 				}
// 			}
// 			//m = n;
// 		}
// 		else{
// 			for(int i = n+1; i < m; i++){
// 				for(int j = 0; j < n; j++){
// 		 			A[i*j] = 0;
// 				}
// 			}
// 			//n = m;
// 		}
// 	}
// 	// if(n % 2 != 0){
// 	// 	for(int i = 0; i < m; i++){
// 	// 		A[i*n] = 0;
// 	// 	}
// 	// }
	
// 	// else if(m % 2 != 0){
// 	// 	for(int i = 0; i < n; i++){
// 	// 		A[i*m] = 0;
// 	// 	}
// 	// }
// 	for( int i = 0; i < m; i++ ){
// 		for( int k = 0; k < n; k++ ) {
// 			for( int j = 0; j < m; j++ ) {
// 				C[i+j*m] += A[i+k*m] * A[j+k*m];
// 			}
// 		}
// 	}
	
// }
