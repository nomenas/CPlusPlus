#include <iostream>

#include <regex>


void testRegexWithNubers() {
    std::smatch match;
    std::string value = "1st 2nd 3th 4th 5th 6th 1920x1600";
    std::cout << "exact string \"4th\" = " << std::regex_search(value, std::regex{"4th"}) << std::endl;
    std::cout << "any char (.) \"4.\" = " << std::regex_search(value, std::regex{"4."}) << std::endl;
    std::cout << "optional character \"24?nd\" " << std::regex_search(value, match, std::regex{"24?nd"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "if starts with number \"^\\d+\" = " << std::regex_search(value, std::regex{"^\\d+"}) << std::endl;
    std::cout << "if starts with alphabetic \"^\\D+\" = " << std::regex_search(value, std::regex{"^\\D+"}) << std::endl;
    std::cout << "any alphanumerical char \"\\w\" " << std::regex_search(value, match, std::regex{"\\w"}) << " " << match[0] << std::endl;
    std::cout << "any non-alphanumerical char \"\\W\" " << std::regex_search(value, match, std::regex{"\\W"}) << " " << match[0] << match.position(0) << std::endl;
    std::cout << "any whitespace \"\\s\" " << std::regex_search(value, match, std::regex{"\\s"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "any non-whitespace \"\\S\" " << std::regex_search(value, match, std::regex{"\\S"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "OR \"[234]..\" " << std::regex_search(value, match, std::regex{"[234].."}) << " " << match[0] << std::endl;
    std::cout << "NOT \"[^1234]..\" " << std::regex_search(value, match, std::regex{"[^1234].."}) << " " << match[0] << std::endl;
    std::cout << "any char in range \"[a-z]\" " << std::regex_search(value, match, std::regex{"[a-z]"}) << " " << match[0] << std::endl;
    std::cout << "any char in range\"[A-Z]\" " << std::regex_search(value, match, std::regex{"[A-Z]"}) << " " << match[0] << std::endl;
    std::cout << "repetitions \"[ht4]{3}\" " << std::regex_search(value, match, std::regex{"[ht4]{3}"}) << " " << match[0] << std::endl;
    std::cout << "repetitions in range \".{4,6}\" " << std::regex_search(value, match, std::regex{".{4,6}"}) << " " << match[0] << std::endl;
    std::cout << "zero or more repetitions \"[ht4]*\" " << std::regex_search(value, match, std::regex{"[ht4]*"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "one or more repetitions \"[ht4]+\" " << std::regex_search(value, match, std::regex{"[ht4]+"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "starts with \"^2\" " << std::regex_search(value, match, std::regex{"^2"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "ends with \"h$\" " << std::regex_search(value, match, std::regex{"h$"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "starts and finish with \"^1.*h$\" " << std::regex_search(value, match, std::regex{"^1.*h$"}) << " " << match[0] << " " << match.position(0) << std::endl;
    std::cout << "matches or \"(2nd|5th)\" " << std::regex_search(value, match, std::regex{"(2nd|5th)"}) << " " << match[0] << " " << match[1] << std::endl;

    std::cout << "!matching group \"([2-5])..\" " << std::regex_search(value, match, std::regex{"([2-5]).."}) << " " << match[0] << " " <<  match.size() << std::endl;
    std::cout << "!matching group \"(\\d+)x(\\d+)\" " << std::regex_search(value, match, std::regex{"(\\d+)x(\\d+)"}) << " " << match[0] << " " <<  match.size() << std::endl;
}

void findMatchCaseInSensitive() {
    std::string s = "Some people, when confronted with a problem, think "
            "\"I know, I'll use regular expressions.\" "
            "Now they have two problems.";

    std::smatch match;
    std::regex self_regex("REGULAR EXPRESSIONS",
                          std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, match, self_regex)) {
        std::cout << "Text contains the phrase '" << match[0] << "' at index " << match.position(0) << "\n";
    }
}

void replaceAllStringLargerThenThen7() {
    std::string s = "1 12 123 1234 123456 1234567 12345678 123456789";
    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
}

void testParseUrl() {
    std::string url = "http://domain.com:8080/path?query#fragment";
    std::regex url_regex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)");
    std::cmatch what;
    if(std::regex_match(url.c_str(), what, url_regex))
    {
        std::cout << "protocol: " << std::string(what[1].first, what[1].second) << std::endl;
        std::cout << "domain:   " << std::string(what[2].first, what[2].second) << std::endl;
        std::cout << "port:     " << std::string(what[3].first, what[3].second) << std::endl;
        std::cout << "path:     " << std::string(what[4].first, what[4].second) << std::endl;
        std::cout << "query:    " << std::string(what[5].first, what[5].second) << std::endl;
        std::cout << "fragment: " << std::string(what[6].first, what[6].second) << std::endl;
    }
}

void testRegexIterator() {
    const std::string http_header{
            "HTTP/1.1 200 OK\n"
                    "Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0\n"
                    "Connection: close\n"
                    "Pragma: no-cache\n"
                    "Content-Type: application/json\n"
                    "Expires: Mon, 1 Aug 2011 09:00:00 GMT\n"
                    "Access-Control-Max-Age: 3600\n"
                    "Access-Control-Allow-Origin: *\n"
                    "Access-Control-Allow-Credentials: true\n"
                    "Access-Control-Allow-Methods: POST, GET, OPTIONS, PUT, DELETE, HEAD\n"
                    "Access-Control-Allow-Headers: Content-Type"};


    std::regex url_re{"\\n"};
    auto iter = std::sregex_token_iterator(http_header.begin(), http_header.end(), url_re, -1);
    while (iter != std::sregex_token_iterator()) {
        std::string item = *iter;
        std::regex url_regex("(.+):\\s+(\\w.+)");
        std::cmatch what;
        if(std::regex_match(item.c_str(), what, url_regex))
        {
            std::cout << "header: " << std::string(what[1].first, what[1].second) << std::endl;
            std::cout << "value:  " << std::string(what[2].first, what[2].second) << std::endl;
        }

        ++iter;
    }
}

int main() {
    std::cout << "\n*** Playing with regex ***\n" << std::endl;
    testRegexWithNubers();

    std::cout << "\n*** Find case insensitive ***" << std::endl;
    findMatchCaseInSensitive();

    std::cout << "\n*** Replace all words larger than 7" << std::endl;
    replaceAllStringLargerThenThen7();

    std::cout << "\n*** Parse url test ***" << std::endl;
    testParseUrl();

    std::cout << "\n*** Regex iterator ***" << std::endl;
    testRegexIterator();


    return 0;
}