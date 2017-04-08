#include <iostream>

#include "graal.h"

bool is_positive ( const void * value )
{
	auto v = ( const int * ) value;
	return (*v > 0);
}

void print_int ( void * e )
{
	auto *p = ( int * ) e;
	std::cout << *p << " ";
}

bool cmp_min ( const void *a, const void *b)
{

	auto *aa = ( int * ) a;
	auto *bb = ( int * ) b;

	return *aa < *bb;

}

bool cmp_equal ( const void * a, const void * b)
{
	auto *aa = ( int * ) a;
	auto *bb = ( int * ) b;

	return *aa == *bb;
}

int main ()
{

	int A[] = { 1, 3, 5, -9, 0, -4, -3, 2, 2, 4};

	std::cout << ">>> Array A [ ";
	graal::transform( std::begin(A), std::end(A), sizeof(int), print_int );
    std::cout << " ]\n";

    //testando Find_IF
    {
    	int B[] = {0, -1, -2, -7, 2, -3, 8, 9};
    	auto r = ( int * ) graal::Find_If( std::begin(B), std::end(B), sizeof(int), is_positive);

    	std::cout << " O primeiro número positivo encontrado foi: " <<
    				 *r << std::endl;
    }	

    //testando Min
    {
    	std::cout << ">>> O menor elemento do Arranjo A é: ";
    	auto m = ( int * ) graal::Min( std::begin(A), std::end(A), sizeof(int), cmp_min );
    	std::cout << *m << std::endl;
    }

    //testando Copy
    {
    	int O[] = { 1, 2, 3, 4, 5 };
    	int D[5];
    	graal::Copy( std::begin(O), std::end(O), sizeof(int), std::begin(D) );
    	std::cout << ">>>Array O [ ";
    	graal::transform( std::begin(O), std::end(O), sizeof(int), print_int);
    	std::cout << " ]\n";
    	std::cout << ">>>Copy Array O [ ";
    	graal::transform( std::begin(D), std::end(D), sizeof(int), print_int);
    	std::cout << " ]\n";
    }	

    //testando Remove_If
    {
    	std::cout << ">>> Removendo números positivos de A...\n";
    	auto lim = (int *) graal::Remove_IF(std::begin(A), std::end(A), sizeof(int), is_positive);
    	std::cout << ">>> Array A [ ";
		graal::transform( std::begin(A), lim, sizeof(int), print_int );
	    std::cout << " ]\n";
    }

    //testando o Unique
    {
    	int F[] = { 1, 1, 2, 2, 3, 4, 5, 4, 3, 10, 6, 7, 8, 6};
    	std::cout << ">>>Array F [ ";
    	graal::transform( std::begin(F), std::end(F), sizeof(int), print_int);
    	std::cout << " ]\n";
    	std::cout << ">>>Array F sem repetições [ ";
    	auto lim = (int *) graal::Unique ( std::begin(F), std::end(F), sizeof(int), cmp_equal );
    	graal::transform( std::begin(F), lim, sizeof(int), print_int);
    	std::cout << " ]\n";
    }


	return 0;
}