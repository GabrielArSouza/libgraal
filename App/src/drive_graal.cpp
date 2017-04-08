#include <iostream>

#include "graal.h"

bool is_positive ( const void * value )
{
	auto *v = ( const int * ) value;
	return *v > 0;
}

void print_int ( void * e )
{
	auto *p = ( int * ) e;
	std::cout << *p << " ";
}

int main ()
{

	int A[] = { 1, 3, 5, 9, 0, -4, -3, 2, 2, 4};

	std::cout << ">>> Array A [ ";
	graal::transform( std::begin(A), std::end(A), sizeof(int), print_int );
    std::cout << " ]\n";	

	return 0;
}