class Solution
{
    vector<int> Digits3Waviness()
    {
        vector<int> result;
        vector<int> digits;

        for (int num = 0; num <= 999; num++)
        {
            int numCopy = num;

            while (numCopy)
            {
                digits.push_back(numCopy % 10);
                numCopy /= 10;
            }

            while (digits.size() < 3)
                digits.push_back(0);

            for (int i = 1; i < digits.size() - 1; i++)
            {
                if (digits[i] < digits[i + 1] && digits[i] < digits[i - 1])
                    result.push_back(num);
                else if (digits[i] > digits[i + 1] && digits[i] > digits[i - 1])
                    result.push_back(num);
            }

            digits.clear();
        }

        return result;
    }

    long long WavinessTillNum(long long num, const vector<int>& digit3Waves)
    {
        long long result = 0;
        vector<int> digits;

        long long numCopy = num;

        while (numCopy)
        {
            digits.push_back(numCopy % 10);
            numCopy /= 10;
        }

        if (digits.size() < 3)
            return 0;

        reverse(digits.begin(), digits.end());

        long long leftNumber = 0;

        for (int digitPos = 1; digitPos < digits.size() - 1; digitPos++)
        {
            int numberAtPos =
                digits[digitPos - 1] * 100 +
                digits[digitPos] * 10 +
                digits[digitPos + 1];

            long long rightChoices =
                pow(10, digits.size() - digitPos - 2);

            for (int assign : digit3Waves)
            {
                if (assign > numberAtPos)
                {
                    if (assign < 100)
                        result += max(0LL, leftNumber - 1) * rightChoices;
                    else
                        result += leftNumber * rightChoices;
                }
                else if (assign < numberAtPos)
                {
                    if (assign < 100)
                        result += leftNumber * rightChoices;
                    else
                        result += (leftNumber + 1) * rightChoices;
                }
                else
                {
                    if (assign < 100)
                        result += max(0LL, leftNumber - 1) * rightChoices;
                    else
                        result += leftNumber * rightChoices;

                    long long rightNumber = 0;

                    for (int pos = digitPos + 2; pos < digits.size(); pos++)
                    {
                        rightNumber *= 10;
                        rightNumber += digits[pos];
                    }

                    result += rightNumber + 1;
                }
            }

            leftNumber *= 10;
            leftNumber += digits[digitPos - 1];
        }

        return result;
    }

public:
    long long totalWaviness(long long num1, long long num2)
    {
        auto digit3 = Digits3Waviness();
        return WavinessTillNum(num2, digit3)
             - WavinessTillNum(num1 - 1, digit3);
    }
};