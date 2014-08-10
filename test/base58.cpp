/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "precompile.hpp"
#include "command.hpp"

#define BASE58_ENCODED_A "vYxp6yFC7qiVtK1RcGQQt3L6EqTc8YhEDLnSMLqDvp8D"
#define BASE58_DECODED_A \
{{ \
    0x03, 0x1b, 0xab, 0x84, 0xe6, 0x87, 0xe3, 0x65, 0x14, 0xee, 0xaf, 0x5a, \
    0x01, 0x7c, 0x30, 0xd3, 0x2c, 0x1f, 0x59, 0xdd, 0x4e, 0xa6, 0x62, 0x9d, \
    0xa7, 0x97, 0x0c, 0xa3, 0x74, 0x51, 0x3d, 0xd0,  0x06 \
}}

SX_USING_NAMESPACES()

BOOST_AUTO_TEST_SUITE(base58__serializer)

BOOST_AUTO_TEST_CASE(base58__constructor__default__does_not_throw)
{
    BOOST_REQUIRE_NO_THROW(base58());
}

BOOST_AUTO_TEST_CASE(base58__constructor__bogus_string__throws_invalid_option)
{
    SX_REQUIRE_INVALID_OPTION_VALUE_EXCEPTION(base58("bo-gus"));
}

BOOST_AUTO_TEST_CASE(base58__constructor__valid_string_cast__decodes)
{
    const data_chunk original(BASE58_DECODED_A);
    const data_chunk instance(base58(BASE58_ENCODED_A));
    BOOST_REQUIRE(original == instance);
}

BOOST_AUTO_TEST_CASE(base58__constructor__chunk_data__decodes)
{
    const data_chunk original(BASE58_DECODED_A);
    const data_chunk instance = base58(original).data();
    BOOST_REQUIRE(original == instance);
}

BOOST_AUTO_TEST_CASE(base58__constructor__copy_address_serializer__round_trips)
{
    SX_SERIALIZE_COPY_ROUND_TRIP(base58, BASE58_ENCODED_A);
}

BOOST_AUTO_TEST_SUITE_END()