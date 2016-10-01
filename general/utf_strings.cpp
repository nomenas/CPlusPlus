#ifdef WIN32
#include <direct.h>
#endif
#include <locale>
#include <codecvt>
#include <iostream>

int main()
{
    auto normal = "I'm a UTF-8 string. Test this '‘'";
    auto utf8 = u8"I'm a UTF-8 string. Test this '\u2018'";
    auto utf16 = u"This is a UTF-16 string. Test this '\u2018'";
    auto utf32 = U"This is a UTF-32 string. Test this '\U00002018'";

    // escaping of \ and " is not required,
    auto raw = R"(The String Data \ ) Stuff " )";
    auto rawUTF8 = u8R"XXX(I'm a "raw UTF-8" string.)XXX";
    auto rawUTF16 = uR"*(This is a "raw UTF-16" string.)*";
    auto rowUTF32 = UR"(This is a "raw UTF-32" string.)";

    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> utf16Convert;
    std::wstring_convert<std::codecvt_utf8_utf16<char32_t>, char32_t> utf32Convert;

    std::cout << typeid(normal).name() << " " << normal << std::endl;
    std::cout << typeid(utf8).name() << " " << utf8 << std::endl;
    auto utf16Conversion = utf16Convert.to_bytes(utf16);
    std::cout << typeid(utf16Conversion).name() << " " << utf16Conversion << std::endl;
    auto utf32Conversion = utf32Convert.to_bytes(utf32);
    std::cout << typeid(utf32Conversion).name() << " " << utf32Conversion << std::endl;
    std::cout << typeid(raw).name() << " " << raw << std::endl;
    std::cout << typeid(rawUTF8).name() << " " << rawUTF8 << std::endl;
    auto rowUtf16Conversion = utf16Convert.to_bytes(rawUTF16);
    std::cout << typeid(rowUtf16Conversion).name() << " " << rowUtf16Conversion << std::endl;
    auto rowUtf32Conversion = utf32Convert.to_bytes(rowUTF32);
    std::cout << typeid(rowUtf32Conversion).name() << " " << rowUtf32Conversion << std::endl;

    // utf8 to utf32
    auto utf8to16Conversion = utf16Convert.from_bytes(normal);
    auto utf8to32Conversion = utf32Convert.from_bytes(normal);
    std::cout << typeid(utf8to16Conversion).name() << std::endl;
    std::cout << typeid(utf8to32Conversion).name() << std::endl;

    return 0;
}

