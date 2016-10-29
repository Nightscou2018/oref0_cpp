
// The MIT License (MIT)
//
// Copyright (c) 2016 Darrell Wright
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

#include <string>

namespace ns {
	struct carb_t{
		double value;

		explicit carb_t( double d ) noexcept;
		~carb_t( );
		explicit operator double( ) noexcept;

		carb_t( ) = default;
		carb_t( carb_t const & ) = default;
		carb_t( carb_t && ) = default;
		carb_t & operator=( carb_t const & ) = default;
		carb_t & operator=( carb_t && ) = default;
		friend void swap( carb_t & lhs, carb_t & rhs ) noexcept;
		std::string to_string( ) const;

		carb_t & operator+=( carb_t const & rhs ) noexcept;
		carb_t & operator-=( carb_t const & rhs ) noexcept;

		carb_t & scale( double factor ) noexcept;
		carb_t scale( double factor ) const noexcept;
	};	// carb_t

	void swap( carb_t & lhs, carb_t & rhs ) noexcept;
	std::ostream & operator<<( std::ostream & os, carb_t const & glucose );	

	carb_t operator+( carb_t const & lhs, carb_t const & rhs ) noexcept;
	carb_t operator-( carb_t const & lhs, carb_t const & rhs ) noexcept;
	carb_t operator-( carb_t rhs ) noexcept;
	bool operator==( carb_t const & lhs, carb_t const & rhs ) noexcept;
	bool operator!=( carb_t const & lhs, carb_t const & rhs ) noexcept;
	bool operator<( carb_t const & lhs, carb_t const & rhs ) noexcept;
	bool operator>( carb_t const & lhs, carb_t const & rhs ) noexcept;
	bool operator<=( carb_t const & lhs, carb_t const & rhs ) noexcept;
	bool operator>=( carb_t const & lhs, carb_t const & rhs ) noexcept;
}    // namespace ns

ns::carb_t operator"" _g( long double d ) noexcept;
ns::carb_t operator"" _g( unsigned long long i ) noexcept;