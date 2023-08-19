#ifndef ELEMENTSPARSER_IP_V4_H
#define ELEMENTSPARSER_IP_V4_H

#include <tao/pegtl.hpp>

#include "../internal/parser/decimal.h"

namespace elements_parser::ip {
    /**
     * `elements_parser::ip::v4` is a rule (in terms of PEGTL)
     * which parses IPv4 strings.
     * It only accepts the form `a.b.c.d`
     * where `a`, `b`, `c`, and `d` are decimals.
     */
    struct v4 : tao::pegtl::seq<
        internal::grammar::decimal_u8,
        tao::pegtl::rep<3, tao::pegtl::one<'.'>, internal::grammar::decimal_u8>> {};
}

#endif //ELEMENTSPARSER_IP_V4_H
