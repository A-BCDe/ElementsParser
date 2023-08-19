#ifndef ELEMENTSPARSER_DECIMAL_H
#define ELEMENTSPARSER_DECIMAL_H

#include <tao/pegtl.hpp>

namespace elements_parser::internal {
    namespace grammar {
        struct positive_decimal : tao::pegtl::seq<
            tao::pegtl::minus<tao::pegtl::digit, tao::pegtl::one<'0'>>,
            tao::pegtl::star<tao::pegtl::digit>
        > {};

        struct negative_decimal : tao::pegtl::seq<
            tao::pegtl::one<'-'>,
            positive_decimal
        > {};

        struct decimal : tao::pegtl::sor<
            tao::pegtl::one<'0'>,
            positive_decimal,
            negative_decimal
        > {};

        struct decimal_u8 : tao::pegtl::sor<
            tao::pegtl::seq<
                tao::pegtl::one<'2'>,
                tao::pegtl::sor<
                    tao::pegtl::seq<
                        tao::pegtl::range<'0', '4'>,
                        tao::pegtl::digit
                    >,
                    tao::pegtl::seq<
                        tao::pegtl::one<'5'>,
                        tao::pegtl::range<'0', '5'>
                    >
                >
            >,
            tao::pegtl::seq<
                tao::pegtl::one<'1'>,
                tao::pegtl::digit,
                tao::pegtl::digit
            >,
            tao::pegtl::seq<
                tao::pegtl::minus<tao::pegtl::digit, tao::pegtl::one<'0'>>,
                tao::pegtl::digit
            >,
            tao::pegtl::digit
        > {};
    }
}

#endif //ELEMENTSPARSER_DECIMAL_H
