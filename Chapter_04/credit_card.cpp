#include <iostream>

using namespace std;

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

// main function
int main()
{
    cout << "Enter a credit card number as an integer: ";
    long long number;
    cin >> number;

    if (isValid(number))
    {
        cout << number << " is valid" << endl;
    }
    else
    {
        cout << number << " is invalid" << endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number)
{
    int size = getSize(number);

    // Valid credit card lengths are between 13 and 16 digits
    if (size < 13 || size > 16)
    {
        return false;
    }

    // Check if prefix matches Visa (4), MasterCard (5), Amex (37), or Discover (6)
    if (!(prefixMatched(number, 4) ||
          prefixMatched(number, 5) ||
          prefixMatched(number, 37) ||
          prefixMatched(number, 6)))
    {
        return false;
    }

    // Luhn check sum divisible by 10
    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (total % 10 == 0);
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    number /= 10; // Start at the 2nd digit from the right
    while (number > 0)
    {
        int digit = number % 10;
        sum += getDigit(digit * 2);
        number /= 100; // Move 2 digits to the left
    }
    return sum;
}

// Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Return sum of odd place digits in number
int sumOfOddPlace(long long number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10; // Take the rightmost digit
        number /= 100;      // Move 2 digits to the left
    }
    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}

// Return the number of digits in d
int getSize(long long d)
{
    if (d == 0)
        return 1;
    int count = 0;
    while (d > 0)
    {
        d /= 10;
        count++;
    }
    return count;
}

// Return the first k number of digits from number.
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k)
{
    int size = getSize(number);
    if (size < k)
    {
        return number;
    }
    for (int i = 0; i < size - k; i++)
    {
        number /= 10;
    }
    return number;
}