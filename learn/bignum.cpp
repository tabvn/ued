#include <iostream>

char* subBigNumber(char* a, char* b)
{
    bool sign = false, remember = false;
 
    if (strlen(a) < strlen(b))
    {
        sign = true;
        swapPointer(&a, &b);
    }
    else if (strlen(a) == strlen(b))
    {
        for (int i = strlen(a) - 1; i >= 0; i--)
        {
            if (*(a + i) < *(b + i))
            {
                swapPointer(&a, &b);
                sign = true;
            }
        }
    }
    size_t a_len = strlen(a);
    size_t b_len = strlen(b);
    char* result = new char [a_len + 2];
    memset(result, '0', a_len + 2);
 
    for (int i = 0; i < b_len; i++)
    {
        int temp = *(a + a_len - i - 1) - *(b + b_len - i - 1);
 
        if (remember)
            temp--;
        if (temp < 0)
        {
            temp += 10;
            remember = true;
        }
        else
            remember = false;
 
        *(result + a_len - i) = temp + '0';
    }
 
    for (int i = 0; i < a_len - b_len; i++)
    {
        int temp = *(a + a_len - b_len - i - 1) - '0';
 
        if (remember == true)
            temp--;
        if (temp < 0)
        {
            temp += 10;
            remember = true;
        }
        else
            remember = false;
 
        *(result + a_len - b_len - i) = temp + '0'; 
    }
 
    while (*(result) == '0')
    {
        if (*(result + 1) != '0' && sign == true)
        {
            *(result) = '-';
            *(result + a_len + 1) = '\0';
            break;
        }
 
        for (int i = 0; i < a_len; i++)
        {
            *(result + i) = *(result + i + 1);
        }
        *(result + a_len) = '\0';
    }
 
    return result;
}

char* addBigNumber(char* a, char* b)
{
	if (strlen(a) < strlen(b))
	{
		swapPointer(&a, &b);
	}
 
	size_t a_len = strlen(a), b_len = strlen(b);
	char* result = new char[a_len + 2];
	memset(result, '0', a_len);
	bool remember = false;
 
	for (int i = 0; i < b_len; i++)
	{
		int temp = *(b + b_len - i - 1) - '0' + *(a + a_len - i - 1) - '0';
 
		if (remember)
			temp++;
 
		if (temp > 9)
			remember = true;
		else
			remember = false;
 
		temp = temp % 10;
 
		*(result + a_len - i) = temp + '0';
	}
 
	for (int i = 0; i < a_len - b_len; i++)
	{
		int temp = *(a + a_len - b_len - i - 1) - '0';
 
		if (remember)
			temp++;
		if (temp > 9)
			remember = true;
		else
			remember = false;
	
		temp = temp % 10;
 
		*(result + a_len - b_len - i) = temp + '0';
	}
 
	*(result + a_len + 1) = '\0';
 
	if (remember)
	{
		*(result) = '1';
	}
	else
	{
		for (int i = 0; i <= a_len; i++)
			*(result + i) = *(result + i + 1);
	}
 
	return result;
}

int main()
{
    char* a = "12345678987654321", *b = "98765432123456789";
    char* c = addBigNumber(a, b);
    printf("%s", c);
    delete[] c;
}