#!/usr/bin/python3
"""Roman number to int convertor"""


def romanToInt(s: str) -> int:
        
    roman_table = {"I": 1,
                    "V": 5,
                    "X": 10,
                    "L": 50,
                    "C": 100,
                    "D": 500,
                    "M": 1000}

    #Reverse iteration solution

    num = 0
    last_seen = "I"

    for numeral in s[::-1]:
        if roman_table[numeral] < roman_table[last_seen]:
            num -= roman_table[numeral]
        else:
            num += roman_table[numeral]
        last_seen = numeral

    return num


roman_number = "X"
print("{} = {}".format(roman_number, romanToInt(roman_number)))

roman_number = "VII"
print("{} = {}".format(roman_number, romanToInt(roman_number)))

roman_number = "IX"
print("{} = {}".format(roman_number, romanToInt(roman_number)))

roman_number = "LXXXVII"
print("{} = {}".format(roman_number, romanToInt(roman_number)))

roman_number = "DCCVII"
print("{} = {}".format(roman_number, romanToInt(roman_number)))
