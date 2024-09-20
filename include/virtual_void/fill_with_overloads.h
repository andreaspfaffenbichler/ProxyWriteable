#pragma once

#include "class_hierarchy/class_hierarchy.h"

namespace virtual_void
{

	template< typename CLASS, typename DEFINITION >
	void fill_with_overload( DEFINITION& method, const auto& wrapper )
	{
		static_assert( !std::is_const_v< DEFINITION > );
		if( !method.is_defined< CLASS >() )
			method.override_< CLASS >( wrapper );
	}

	template< typename CLASSES, typename DEFINITION >
	void fill_with_overloads( DEFINITION& method, const auto& wrapper )
	{
		class_hierarchy::visit_classes< CLASSES >( 
			overload
			{ [&]< typename C >				{ fill_with_overload< C >( method, wrapper ); }
			, [&]< typename C, typename B >	{}
			});
	}
}