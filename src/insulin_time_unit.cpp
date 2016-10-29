
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

#include "insulin_time_unit.h"

ns::insulin_per_hour_t operator"" _U_hr( long double d ) noexcept {
	return ns::insulin_per_hour_t{ ns::insulin_t{ static_cast<double>(d) } };
}
ns::insulin_per_hour_t operator"" _U_hr( unsigned long long i ) noexcept {
	return ns::insulin_per_hour_t{ ns::insulin_t{ static_cast<double>(i) } };
}
ns::insulin_per_minute_t operator"" _U_min( long double d ) noexcept {
	return ns::insulin_per_minute_t{ ns::insulin_t{ static_cast<double>(d) } };
}
ns::insulin_per_minute_t operator"" _U_min( unsigned long long i ) noexcept {
	return ns::insulin_per_minute_t{ ns::insulin_t{ static_cast<double>(i) } };
}