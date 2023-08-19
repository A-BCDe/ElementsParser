#include <elements_parser/ip/v4.h>

#include <iostream>

static constexpr const char *correct_ips[] {
    "127.0.0.1",
    "255.255.255.255",
    "1.2.3.4",
    "125.236.01.24",
    "1.102.103.104",
    "0.0.0.0",
    "1.1.1.1",
    "42.24.42.24",
    "192.168.0.1"
};

static constexpr const char *incorrect_ips[] {
    "127.0.0.",
    "1",
    "255.256.255.256",
    "14.-14.234.-1",
    "12.+12.12.12",
    "ae.11.22.33", // To remove octets and hex
    "11.ae.22.33", // To remove octets and hex
    "11.22.ae.33", // To remove octets and hex
    "11.22.33.ae", // To remove octets and hex
    "de.ad.be.ef", // To remove octets and hex
    ".1.1.",
    "14.2..1",
    "12..2.1",
    "#.#.#.#",
    "1,1,1,1",
    "602713043246328104.548109751347613.4123780467150145.26340782318746320467140386",
    "\xde.\xad.\xbe.\xef", // To remove octets and hex
    "\xde\xad\xbe\xef", // To remove octets and hex
    "12.12.12.12.12",
    "12.12",
    "00.01.02.03", // To remove octets and hex
};

static int test_correct_ip_v4_format() {
    int res = 0;
    for(const char *str : correct_ips) {
        try {
            tao::pegtl::memory_input in(str, "");
            tao::pegtl::parse<tao::pegtl::until<tao::pegtl::eolf, tao::pegtl::must<elements_parser::ip::v4>>>(in);
        } catch(std::exception &e) {
            std::cerr << e.what() << std::endl;
            res++;
        }
    }
    return res;
}

static int test_incorrect_ip_v4_format() {
    int res = 0;
    int idx = -1;
    for(const char *str : incorrect_ips) {
        try {
            idx++;
            tao::pegtl::memory_input in(str, "");
            tao::pegtl::parse<tao::pegtl::until<tao::pegtl::eolf, tao::pegtl::must<elements_parser::ip::v4>>>(in);
            res++;
        } catch(std::exception &e) {
            std::cerr << idx << ": Input \"" << str << "\" have incorrect ip format: " << e.what() << std::endl;
        }
    }
    return res;
}

int ip_v4(int argc, char *argv[]) {
    int result = 0;
    result += test_correct_ip_v4_format();
    result += test_incorrect_ip_v4_format();
    return result;
}