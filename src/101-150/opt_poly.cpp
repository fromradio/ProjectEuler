#include <iostream>
#include <vector>
#include <cmath>


void swap(long i,long j, long m, long n, double* A)
{
	double temp;
	for (long r = 0; r < n; ++ r)
	{
		temp = A[i+r*m];
		A[i+r*m] = A[j+r*m];
		A[j+r*m] = temp;
	}
}

void gaussElimination(long m, long n, double* A, double* b, double* x)
{
	for (long k = 0 ; k < std::min(m,n) ; ++ k)
	{
		/** find i_max */
		long i_max = -1;
		double mval = 0.0;
		for(long i = k ; i < m ; ++ i)
		{
			if(std::abs(A[i+k*m]) > mval)
			{
				mval = std::abs(A[i+k*m]);
				i_max = i;
			}
		}
		swap(i_max,k,m,n,A);
		swap(i_max,k,m,1,b);
		for(long i = k+1 ; i < m ; ++ i)
		{
			double c = A[i+k*m]/A[k+k*m];
			for(long j = k+1 ; j < n ; ++ j)
			{
				A[i+j*m] = A[i+j*m]-A[k+j*m]*c;
			}
			b[i] = b[i] - b[k]*c;
			A[i+k*m] = 0;
		}
	}
	/** back */

	for(long i = n-1  ; i >= 0; -- i)
	{
		double sum = 0;
		for(long j = i+1; j<n ; ++ j)
		{
			sum += A[i+j*m]*x[j];
		}
		x[i] = (b[i]-sum)/A[i+i*m];
	}
}


class Poly
{
	std::vector<long> __coeff;
public:
	Poly(const std::vector<long> c)
		:__coeff(c)
	{

	}

	long operator()(long n) const
	{
		long k = 1;
		long r = 0;
		for(auto i=0; i<__coeff.size(); ++ i)
		{
			r += __coeff[i]*k;
			k *= n;
		}
		return r;
	}
};

double* generateCoeff(long n)
{
	double *A = new double[n*n];
	for (long i = 0 ; i < n; ++i )
	{
		long k = 1;
		for(long j = 0 ; j < n ; ++ j)
		{
			A[i+j*n] = k;
			k*=(i+1);
		}
	}
	return A;
}

double* generateObservation(const Poly& p,long n)
{
	double *b = new double[n];
	for(long i = 0 ; i < n ; ++ i)
	{
		b[i] = p(i+1);
	}
	return b;
}

int main(int argc, char *argv[])
{
	Poly poly({1,-1,1,-1,1,-1,1,-1,1,-1,1});
	long sum = 0;
	for (long i= 0 ;i  < 10; ++ i)
	{
		double *A = generateCoeff(i+1);
		double *b = generateObservation(poly,i+1);
		double *x = new double[i+1];
		gaussElimination(i+1,i+1,A,b,x);
		std::vector<long> coeff(i+1);
		for(long k = 0 ; k < i+1 ; ++ k)
		{
			coeff[k] = static_cast<long>(x[k]);
		}
		Poly p(coeff);
		sum += p(i+2);
		std::cout<<i+2<<' '<<p(i+2)<<std::endl;
		delete[]A;
		delete[]b;
		delete[]x;
	}
	std::cout<<sum<<std::endl;
}