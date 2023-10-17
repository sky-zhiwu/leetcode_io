#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;


bool check(string s)
{
    int a = (int)s[0], b = (int)s[1], c = (int)s[2], d = (int)s[3];
    if (a != b && b == c && c == d) return true;
    if (a == b && b != c && c == d) return true;
    if (a == b && b == c && c != d) return true;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    // printf("1111");
    while (t --) {
        string s;
        scanf("%s", s);
        if (check(s)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}