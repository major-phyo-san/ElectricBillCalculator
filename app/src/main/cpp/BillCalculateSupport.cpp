//
// Created by Techman on 23/07/2019.
//

#include "include/BillCalculateSupport.h"

string formatOutputString(double rawDouble)
{
    string tempString = to_string(rawDouble);
    tempString = tempString.erase(tempString.find_last_not_of('0')+1, string::npos);
    string formattedString = tempString.erase(tempString.find_last_not_of('.')+1, string::npos);
    return formattedString;
}
