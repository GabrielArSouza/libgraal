#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstdlib>
#include <cstring>
#include <iterator>

namespace graal {

	using Action = void ( * ) ( void * );
	using UnaryPredicate = bool (*) (const void * );
	using Compare = bool (*) (const void *, const void * );

	void transform ( void *first, void *last, std::size_t size, Action p );
	void * Find_If ( const void *first, const void *last, std::size_t size, UnaryPredicate p );
	void * Min ( const void *first, const void *last, std::size_t size, Compare cmp);
	void * Copy ( const void *first, const void *last, std::size_t size, void *d_first );
	void * Remove_IF ( const void *first, const void * last, std::size_t size, UnaryPredicate p );
	void * Unique ( const void *first, const void * last, std::size_t size, Compare cmp );

}


#endif