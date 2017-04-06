#include "graal.h"


namespace graal {

	using byte = unsigned char;

	void
	transform ( void *first, void *last, std::size_t size, Action p )
	{

		//convertendo para byte
		auto *f = ( byte * ) first; 
		auto *l = ( byte * ) last;

		while ( f < l )
		{
			p ( f );  //aplica função passada
			f += size; //avança para o proximo valor
		}
	}

	


}