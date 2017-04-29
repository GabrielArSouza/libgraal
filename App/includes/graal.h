#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstdlib>
#include <cstring>
#include <iterator>

namespace graal {

	using Action = void ( * ) ( void * );
	using UnaryPredicate = bool (*) (const void * );
	using Compare = bool (*) (const void *, const void * );
	using CompareTotal = int (*) (const void *, const void * );

	void transform ( void *first, void *last, std::size_t size, Action p );
	void * Find_If ( const void *first, const void *last, std::size_t size, UnaryPredicate p );
	void * Min ( const void *first, const void *last, std::size_t size, Compare cmp);
	void * Copy ( const void *first, const void *last, std::size_t size, void *d_first );
	void * Remove_IF ( const void *first, const void *last, std::size_t size, UnaryPredicate p );
	void * Unique ( const void *first, const void *last, std::size_t size, Compare cmp );
	void * BSearch ( const void *left, const void *right, std::size_t size, CompareTotal cmp, const void * target);
	void * QSort ( const void *first, const void *last, std::size_t size, CompareTotal cmp);
	void * BSort ( const void *first, const void *last, std::size_t size, CompareTotal cmp);
	void * SSort ( const void *first, const void *last, std::size_t size, CompareTotal cmp);

	//<! Templates
	template <typename T>
	bool binary_search( T * first, T * last, T target);
	#include "../lib/libgraal.a"
}


#endif