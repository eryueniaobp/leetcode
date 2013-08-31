#include<iostream>
#include<string>
using namespace::std;

class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int result = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(i + 1 < s.size())
			{
				if(getValue(s[i]) < getValue(s[i+1]))
				{
					result = result - getValue(s[i]);
				}
				else
				{
					result = result + getValue(s[i]);
				}
			}
			else
			{
				result = result + getValue(s[i]);
			}
		}
		return result;
        
    }

	
	int getValue(char c)
	{
		switch(c)
		{
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
		default:
			return 0;

		}
	}
};


