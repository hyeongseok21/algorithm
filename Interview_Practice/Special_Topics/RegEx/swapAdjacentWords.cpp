std::string solution(std::string s) {
  return std::regex_replace(s, std::regex("(\\w+)\\s(\\w+)"), "$2 $1");
}