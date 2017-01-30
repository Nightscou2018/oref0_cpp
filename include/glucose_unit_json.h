// The MIT License (MIT)
//
// Copyright (c) 2017 Darrell Wright
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <daw/json/daw_json_link.h>

#include "glucose_unit.h"

namespace ns {
	template<typename ObjectPtr, typename Member>
	void json_link_glucose_t( boost::string_view json_name, ObjectPtr entries, Member & member ) {
		using json_int_t = daw::json::impl::value_t::integral_t;
		static auto const to_glucose = []( auto const & json_int ) {
			return ns::glucose_t{ static_cast<ns::real_t>( json_int ) };
		};
		static auto const from_glucose = []( auto const & g ) {
			return static_cast<json_int_t>( g.as_mg_dL( ) );
		};
		entries->link_jsonintegral( json_name, member, from_glucose, to_glucose );
	}

	template<typename ObjectPtr, typename Member>
	void json_link_glucose_t( boost::string_view json_name, ObjectPtr entries, boost::optional<Member> & member ) {
		using json_int_t = daw::json::impl::value_t::integral_t;
		static auto const to_glucose = []( auto const & json_int ) {
			return ns::glucose_t{ static_cast<double>( json_int ) };
		};
		static auto const from_glucose = []( auto const & g ) -> boost::optional<json_int_t> {
			if( !g ) {
				return boost::none;
			}
			return static_cast<json_int_t>( g->as_mg_dL( ) );
		};
		entries->link_jsonintegral( json_name, member, from_glucose, to_glucose );
	}
}	// namespace ns


