#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <stdio.h>

//SSE
void dgemm( int m, int n, float *A, float *C )
{
	for( int i = 0; i < m; i++ ) {
		for( int k = 0; k < n; k++ ) {
			for( int j = 0; j < m; j+=4 ){
				__m128 primus = _mm_load_ps(A + (j + k * m));
				__m128 secundus = _mm_load_ps(A + (i + k * m));
				__m128 tertius = _mm_load_ps(C + (i + j * m));
				__m128 quartus = _mm_mul_ss(primus, secundus);
				__m128 quintus = _mm_add_ss(tertius, quartus);
				_mm_store_ss(C + (i + j * m), quintus);
			}
		}
	}
}


//Loop Unrolling
// void dgemm( int m, int n, float *A, float *C )
// {
// 	int i,j,k;
// 	for(i = 0; i < m; i++ )
// 	{
// 		for(k = 0; k < n; k++ ) 
// 		{		
// 			for(j = 0; j < m; j+=5 )
// 			{
// 				C[i+j*m] += A[i+k*m] * A[j+k*m];
// 				if(j + 4 < m){
// 					C[i+(j+4)*m] += A[i+k*m] * A[(j+4)+k*m];
// 					C[i+(j+3)*m] += A[i+k*m] * A[(j+3)+k*m];
// 					C[i+(j+2)*m] += A[i+k*m] * A[(j+2)+k*m];
// 					C[i+(j+1)*m] += A[i+k*m] * A[(j+1)+k*m];
// 				}
// 				else if(j + 3 < m){
// 					C[i+(j+3)*m] += A[i+k*m] * A[(j+3)+k*m];
// 					C[i+(j+2)*m] += A[i+k*m] * A[(j+2)+k*m];
// 					C[i+(j+1)*m] += A[i+k*m] * A[(j+1)+k*m];
// 				}
// 				else if(j + 2 < m){
// 					C[i+(j+2)*m] += A[i+k*m] * A[(j+2)+k*m];
// 					C[i+(j+1)*m] += A[i+k*m] * A[(j+1)+k*m];
// 				}
// 				else if(j + 1 < m){
// 					C[i+(j+1)*m] += A[i+k*m] * A[(j+1)+k*m];
// 				}
// 			}
// 		}
// 	}
// 	// switch(m-j){
// 	// 	case 3:
// 	// 	{
// 	// 		C[i+(j+3)*m] += A[i+k*m] * A[(j+3)+k*m];
// 	// 	}
// 	// 	case 2:
// 	// 	{
// 	// 		C[i+(j+2)*m] += A[i+k*m] * A[(j+2)+k*m];
// 	// 	}
// 	// 	case 1:
// 	// 	{
// 	// 		C[i+(j+1)*m] += A[i+k*m] * A[(j+1)+k*m];
// 	// 	}
// 	// }
		
// }

//Cache Blocking
// void dgemm( int m, int n, float *A, float *C )
// {
// 	const int BASE_BLOCK_SIZE = 10;
// 	int BLOCK_1;
// 	int BLOCK_2;
// 	int BLOCK_3;
// 	for( int i = 0; i < m; i+=BASE_BLOCK_SIZE ){
// 		for( int k = 0; k < n; k+=BASE_BLOCK_SIZE ) {
// 			for( int j = 0; j < m; j+=BASE_BLOCK_SIZE ) {
// 				(i + BASE_BLOCK_SIZE < m)? (BLOCK_1 = i + BASE_BLOCK_SIZE): (BLOCK_1 = m);
// 				for(int i2 = i; i2 < BLOCK_1; i2++){
// 					(k + BASE_BLOCK_SIZE < n)? (BLOCK_2 = k + BASE_BLOCK_SIZE): (BLOCK_2 = n);
// 					for(int k2 = k; k2 < BLOCK_2; k2++){
// 						(j + BASE_BLOCK_SIZE < m)? (BLOCK_3 =  j + BASE_BLOCK_SIZE): (BLOCK_3 = m);
// 						for(int j2 = j; j2 < BLOCK_3; j2++){
// 							C[i2+j2*m] += A[i2+k2*m] * A[j2+k2*m];
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// }

// void dgemm( int m, int n, float *A, float *C )
// {
// 	if(m % 2 != 0){
// 		for(int i = 0; i < m + 1; i++){
// 			A[i*m] = 0;
// 		}
// 	}
// 	for( int i = 0; i < m; i++ ){
// 		for( int k = 0; k < n; k++ ) {
// 			for( int j = 0; j < m; j++ ) {
// 				C[i+j*m] += A[i+k*m] * A[j+k*m];
// 			}
// 		}
// 	}
	
// }
