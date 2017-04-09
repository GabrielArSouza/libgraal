#include "graal.h"


namespace graal {

	using byte = unsigned char;
	
	void
	transform ( void *first, void *last, std::size_t size,
				Action p )
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

	void 
	* Find_If ( const void *first, const void *last, 
				std::size_t size, UnaryPredicate p  )
	{
		auto *f = ( byte * ) first;
		auto *l = ( byte * ) last;

		for (/*empty*/; f < l; f += size)
		{
			if ( p(f) ) return ( void * ) f;
		}

		return ( void * ) f;
	}	

	void
	* Min ( const void *first, const void *last,
	 		std::size_t size, Compare cmp)
	{

		auto *f = ( byte * ) first;
		auto *l = ( byte * ) last;

		auto m(f);

		for (/*empty*/; f < l; f += size)
		{
			if ( cmp(f, m) ) m = f;
		}

		return ( void * ) m;

	}

	void
	* Copy ( const void *first, const void *last,
			 std::size_t size, void *d_first )
	{

		auto *f = ( byte * ) first;
		auto *l = ( byte * ) last;
		auto *d_f = ( byte * ) d_first;

		auto d = std::distance( f, l );
		memcpy ( d_f, f, d );

		return ( void * ) d_f;
	}

	void 
	* Remove_IF ( const void *first, const void * last,
				  std::size_t size, UnaryPredicate p )
	{
		auto fast = ( byte * ) first;
		auto slow = ( byte * ) first;
		auto l = ( byte * ) last;

		byte aux[size];

		for (/*empty*/; fast < l; fast += size)
		{
			if ( p(fast) )
			{
				memcpy (aux, slow, size );
				memcpy (slow, fast, size );
				memcpy (fast, aux, size);
				slow += size;
			}
		}

		return ( void * ) slow;
	}

	void
	* Unique ( const void *first, const void * last,
			   std::size_t size, Compare cmp )
	{

		auto per = ( byte * ) first;
		auto l = ( byte * ) last;
		auto slow = per + size;
		auto f = per + size;

		byte aux[size];
		bool equal = false;

		for ( /*empty*/; f < l; f += size)
		{
			for ( auto i(per); i < slow && !equal; i += size)
			{
				if ( cmp(f, i) ) equal = true;
			}

			if ( !equal )
			{
				memcpy ( aux, slow, size );
				memcpy ( slow, f, size );
				memcpy ( f, aux, size );

				slow += size;
			}

			equal = false;
		}
		return ( void * ) slow;

	}

	void
	* BSearch ( const void *left, const void * right,
				std::size_t size, CompareTotal cmp,
				const void * target )
	{

		auto l = ( byte * ) left;
		auto r = ( byte * ) right;

		byte * m;

		while ( l <= r  )
		{
			auto d = std::distance(l, r);
			auto t = d/size;
			m = l + (t/2)*size;

			auto v = cmp(m, target);

			if ( v == 0 ) return ( void * ) m;
			else if ( v == -1 ) l = m + size;
			else if ( v == 1 ) r = m - size;
			
		}

		return ( void * ) r;

	}

}