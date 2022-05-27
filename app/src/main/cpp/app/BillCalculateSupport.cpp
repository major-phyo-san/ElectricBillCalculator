//
// Created by Techman (MajorSan) on 23/07/2019.
// Updated by Techman (MajorSan) on 19/04/2020.
// Refactored by Techman (MajorSan) on 25/05/2022.
//

#include "include/billcalculatesupport.h"

string formatOutputString(double rawDouble)
{
    string tempString = to_string(rawDouble);
    tempString = tempString.erase(tempString.find_last_not_of('0')+1, string::npos);
    string formattedString = tempString.erase(tempString.find_last_not_of('.')+1, string::npos);
    return formattedString;
}
