//
// Created by Techman (MajorSan) on 23/07/2019.
// Updated by Techman (MajorSan) on 19/04/2020.
// Refactored by Techman (MajorSan) on 25/05/2022.
//

#include "include/domesticbillcalculator.h"
#include "include/domesticunits.h"
#include "include/billcalculatesupport.h"

using namespace std;

string calculateDomesticBill(double inputUnits)
{
    string outputText = "";
    double costFactor [7] {35,50,70,90,110,120,125};
    double unitCosts [7];
    double totalCharge = 0;
    double maintenanceFee = 500;
    double* acceptUnitSegments;

    acceptUnitSegments = getDomesticUnitSegments(inputUnits);
    if(acceptUnitSegments[0] == -1)
    {
        outputText += "The Electrical Units should be non negative number!\n";
    }

    else
    {
        for (int i = 0; i < 7; i++)
        {
            if (acceptUnitSegments[i] == 0)
                break;
            unitCosts[i] = acceptUnitSegments[i] * costFactor[i];
            outputText += "Units: " + formatOutputString(acceptUnitSegments[i]) + " x " + formatOutputString(costFactor[i]) + " Kyats, Cost: " + formatOutputString(unitCosts[i]) + " Kyats \n";
            totalCharge += unitCosts[i];
        }

        outputText += "Total Units Cost: " + formatOutputString(totalCharge) + " Kyats\n";
        outputText += "Total Bill (maintenance fee included): " + formatOutputString(totalCharge + maintenanceFee) + " Kyats \n";
    }

    return outputText;
}
