bool palindrome(int i, int j, string &str) {
  while (i <= j) {
    if (str[i] != str[j])
      return false;
    i++;
    j--;
  }
  return true;
}
int minCharsforPalindrome(string str) { // Write your code here.
  int n = str.length();
  int i = 0, j = n - 1;
  while (i <= j) {
    bool x = palindrome(i, j, str);
    if (x)
      break;
    else
      j--;
  }
  return n - j - 1;
}
