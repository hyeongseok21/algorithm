void solutionWithReference(std::vector<int>& a, int l, int r) {
  if (l >= r) {
    return;
  }

  int x = a[l];
  int i = l;
  int j = r;

  while (i <= j) {
    while (a[i] < x) {
      i++;
    }
    while (a[j] > x) {
      j--;
    }
    if (i <= j) {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++;
      j--;
    }
  }

  // modified below 2 line
  solutionWithReference(a, l, j);
  solutionWithReference(a, i, r);
}

std::vector<int> solution(std::vector<int> a, int l, int r) {
  solutionWithReference(a, l, r);
  return a;
}