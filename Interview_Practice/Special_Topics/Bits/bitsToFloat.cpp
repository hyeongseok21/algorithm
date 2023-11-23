double solution(int bits) {
  double intp = bits >> 16;
  double frap = double(bits & 0xFFFF);
  while (frap >= 1.) {
    frap /= 10.;
  }
  return intp + frap;
}