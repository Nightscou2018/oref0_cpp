// The MIT License (MIT)
//
// Copyright (c) 2016-2017 Darrell Wright
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
//
// Adapted from algorithm found at https://raw.githubusercontent.com/Perceptus/iob/master/insulin_on_board_pct.js

#pragma once

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstdio>

#include <date/date.h>

#include "data_types.h"
#include "insulin_unit.h"

namespace ns {
	enum class insulin_duration_t: int16_t { t180 = 180, t210 = 210, t240 = 240, t300 = 300, t360 = 360 };
	real_t insulin_on_board_pct( ns::duration_minutes_t const time_from_bolus_min, ns::duration_minutes_t const insulin_duration ) noexcept;

	struct insulin_dose {
		insulin_t amount;	// Amount of insulin
		timestamp_t dose_time;
		ns::duration_minutes_t dose_dia;	// DIA in minutes, must be > 0
		
		insulin_dose( insulin_t how_much, insulin_duration_t dia = insulin_duration_t::t240, timestamp_t when = std::chrono::system_clock::now( ) );

		insulin_dose( ) = delete;
		~insulin_dose( ) = default;
		insulin_dose( insulin_dose const & ) = default;
		insulin_dose( insulin_dose && ) = default;
		insulin_dose & operator=( insulin_dose const & ) = default;
		insulin_dose & operator=( insulin_dose && ) = default;
	};	// insulin_dose

	std::ostream & operator<<( std::ostream & os, insulin_duration_t const & duration );
	std::istream & operator>>( std::istream & is, insulin_duration_t & duration );
}	// namespace ns

