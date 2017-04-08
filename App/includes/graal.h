#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstdlib>

namespace graal {

	using Action = void ( * ) ( void * );

	void transform ( void *first, void *last, std::size_t size, Action p );

}


#endif