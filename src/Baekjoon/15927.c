//Minon142 - 15927 - 180807
#include <iostream>

using namespace std;

int check(string palindrome)
{
    int check_all_same = 1;
    int i = palindrome.length();
    int j;
    
    if (palindrome.length()%2 == 0)
        for (i = palindrome.length()/2, j=1; i < palindrome.length(); i++, j+=2) {
            if (palindrome[i] != palindrome[i - j])
                return palindrome.length();
            if (palindrome[i] != palindrome[i - 1])
                check_all_same = 0;
        }
    else
        for (i = palindrome.length()/2 + 1, j=2; i < palindrome.length(); i++, j+=2) {
            if (palindrome[i] != palindrome[i - j])
                return palindrome.length();
            if (palindrome[i] != palindrome[i - 1])
                check_all_same = 0;
        }
    if (check_all_same == 1)
        return -1;
    else
        return palindrome.length() - 1;
}

int main()
{
    string palindrome;
    cin >> palindrome;
    cout << check(palindrome);
    
    return 0;
}
/*
문제) 백준 15927번 참고.

풀이) 이 문제 같은 경우는 예문에서 모든 힌트를 다 주어서 쉽게 풀 수 있었다. 알 수 있었던 경우의 수는 3가지로, 특정 문자열 string이 회문이 아닌경우와 회문이면서 모두 같은 문자일 경우, 하나라도 다른 문자일 경우 이렇게 구할 수 있었다. 각 경우에 맞게 조건을 걸어 주어서 쉽게 풀 수 있었다.
*/