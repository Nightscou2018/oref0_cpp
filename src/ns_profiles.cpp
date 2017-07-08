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

#include <string>
#include <vector>

#include <daw/json/daw_json_link.h>
#include <daw/json/daw_json_link_datetime.h>
#include <daw/json/daw_json_link_fixes.h>

#include "ns_profiles.h"

namespace ns {
	namespace data {
		namespace profiles {
			void carb_ratio_element_t::json_link_map( ) {
				link_json_quoted_integer_optional( "timeAsSeconds", time_as_seconds, boost::none );
				link_json_quoted_real( "value", value );
				link_json_string( "time", time );
			}

			void sens_element_t::json_link_map( ) {
				link_json_quoted_integer_optional( "timeAsSeconds", time_as_seconds, boost::none );
				link_json_quoted_real( "value", value );
				link_json_string( "time", time );
			}

			void basal_element_t::json_link_map( ) {
				link_json_quoted_integer_optional( "timeAsSeconds", time_as_seconds, boost::none );
				link_json_quoted_real( "value", value );
				link_json_string( "time", time );
			}

			void target_low_element_t::json_link_map( ) {
				link_json_quoted_integer_optional( "timeAsSeconds", time_as_seconds, boost::none );
				link_json_quoted_real( "value", value );
				link_json_string( "time", time );
			}

			void target_high_element_t::json_link_map( ) {
				link_json_quoted_integer_optional( "timeAsSeconds", time_as_seconds, boost::none );
				link_json_quoted_real( "value", value );
				link_json_string( "time", time );
			}

			void Default_t::json_link_map( ) {
				link_json_string( "units", units );
				link_json_quoted_integer( "delay", delay );
				link_json_object_array( "basal", basal );
				link_json_object_array( "target_low", target_low );
				link_json_object_array( "target_high", target_high );
				link_json_quoted_real( "carbs_hr", carbs_hr );
				link_json_object_array( "carbratio", carb_ratio );
				link_json_string( "timezone", timezone );
				link_json_real_duration( "dia", dia );
				link_json_object_array( "sens", sens );
				link_json_iso8601_timestamp( "startDate", start_date );
			}

			void store_t::json_link_map( ) {
				link_json_object( "Default", Default );
			}

			void ns_profiles_t::json_link_map( ) {
				link_json_iso8601_timestamp( "created_at", created_at );
				link_json_quoted_integer_optional( "mills", mills, boost::none );
				link_json_string( "_id", _id );
				link_json_string_optional( "defaultProfile", default_profile, boost::none );
				link_json_object_optional( "store", store, boost::none );
				link_json_iso8601_timestamp( "startDate", start_date );
			}
		}	// namespace profiles
	}	// namespace data
}	// namespace ns
