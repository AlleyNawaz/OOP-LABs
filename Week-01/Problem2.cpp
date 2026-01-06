#include <iostream>
using namespace std;

int reverse_digits(int n)
{
    int reversed_n = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reversed_n = reversed_n * 10 + digit;
        n /= 10;
    }
    return reversed_n;
}

int main()
{
    int N;
    cin >> N;

    int min_steps = N - 1;

    for (int i = 1; i <= N; ++i)
    {
        int reversed_i = reverse_digits(i);

        if (reversed_i <= N)
        {
            int current_steps = (i - 1) + (N - reversed_i);

            if (current_steps < min_steps)
            {
                min_steps = current_steps;
            }
        }
    }

    cout << min_steps << endl;

    return 0;
}