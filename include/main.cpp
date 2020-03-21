// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru
#include"string.hpp"

using std::cout;

int main() {
    String str_1;
    String str_2("papa");
    String new_str("mama");
    String str_copy(str_2);
    str_1 = new_str;
    cout << str_2;
    str_2 += str_1;
    str_1 *= 7;
    cout << (str_1 == str_2);
    cout << (str_2 < str_1);
    String substr("pa");
    cout << str_2.Find(substr);
    str_2.Replace('a', '-');
    str_2.Size();
    str_2.Empty();
    cout << str_2[6];
    str_2[2] = '+';
    String strrt("____PAPA____");
    strrt.RTrim('_');
    strrt.LTrim('_');
    String s1("aaa"), s2("bbb");
    s1.swap(s2);
    cout << s1 + s2;
    cout << s1 * 3;
    cout << (s1 != s2);
    cout << (s1 > s2);
    return 0;
}
