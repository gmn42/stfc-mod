#pragma once

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>
#include <vector>
#include <il2cpp/il2cpp_helper.h>

#include <simdutf.h>
#if _WIN32
#include <winrt/base.h>
#endif

inline bool ascii_isspace(unsigned char c)
{
  return std::isspace(static_cast<unsigned char>(c));
}

inline std::string_view StripTrailingAsciiWhitespace(std::string_view str)
{
  auto it = std::find_if_not(str.rbegin(), str.rend(), ascii_isspace);
  return str.substr(0, static_cast<size_t>(str.rend() - it));
}

inline std::string_view StripLeadingAsciiWhitespace(std::string_view str)
{
  auto it = std::find_if_not(str.begin(), str.end(), ascii_isspace);
  return str.substr(static_cast<size_t>(it - str.begin()));
}

inline std::string_view StripAsciiWhitespace(std::string_view str)
{
  return StripTrailingAsciiWhitespace(StripLeadingAsciiWhitespace(str));
}

inline std::string AsciiStrToUpper(std::string_view s)
{
  std::string str = s.data();
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  return str;
}

inline std::vector<std::string> StrSplit(const std::string& input, char delimiter)
{
  std::vector<std::string> result;
  int                      last_pos = 0;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] != delimiter) {
      continue;
    }

    if (i - last_pos > 0) {
      result.emplace_back(input.substr(last_pos, i - last_pos));
    }
    last_pos = i + 1;
  }

  if (last_pos != input.length()) {
    auto sp = input.substr(last_pos, input.length() - last_pos);
    sp      = StripAsciiWhitespace(sp);
    if (!sp.empty()) {
      result.emplace_back(sp);
    }
  }

  return result;
}

inline std::wstring to_wstring(const std::string& str)
{
#if _WIN32
  return winrt::to_hstring(str).c_str();
#else
  size_t                      expected_utf32words = simdutf::utf32_length_from_utf8(str.data(), str.length());
  std::unique_ptr<char32_t[]> utf32_output{new char32_t[expected_utf32words]};
  size_t                      utf16words = simdutf::convert_utf8_to_utf32(str.data(), str.length(), utf32_output.get());
  return std::wstring(utf32_output.get(), utf32_output.get() + utf16words);
#endif
}

inline std::wstring to_wstring(Il2CppString* str)
{
#if _WIN32
  return str->chars;
#else
  size_t                      expected_utf32words = simdutf::utf32_length_from_utf16(str->chars, str->length);
  std::unique_ptr<char32_t[]> utf32_output{new char32_t[expected_utf32words]};
  size_t                      utf16words = simdutf::convert_utf16_to_utf32(str->chars, str->length, utf32_output.get());
  return std::wstring(utf32_output.get(), utf32_output.get() + utf16words);
#endif
}

static std::string to_string(const std::wstring& str)
{
#if _WIN32
  size_t                     expected_utf16words = simdutf::utf8_length_from_utf16((char16_t*)str.data(), str.length());
  std::unique_ptr<char8_t[]> utf8_output{new char8_t[expected_utf16words]};
  size_t utf16words = simdutf::convert_utf16_to_utf8((char16_t*)str.data(), str.length(), (char*)utf8_output.get());
  return std::string(utf8_output.get(), utf8_output.get() + utf16words);
#else
  size_t                     expected_utf32words = simdutf::utf8_length_from_utf32((char32_t*)str.data(), str.length());
  std::unique_ptr<char8_t[]> utf32_output{new char8_t[expected_utf32words]};
  size_t utf16words = simdutf::convert_utf32_to_utf8((char32_t*)str.data(), str.length(), (char*)utf32_output.get());
  return std::string(utf32_output.get(), utf32_output.get() + utf16words);
#endif
}
