std::string solution(std::string s, int n) {
  std::regex regex(
    "(?:[^0-9]*[0-9]*){"+ to_string(n-1) + "}[^1-9]*([0-9]*)([^]*)");
  std::smatch match;
  std::regex_match(s, match, regex);
  return match[1];
}