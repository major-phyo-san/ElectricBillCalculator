//
// Created by Techman on 24/07/2019.
//

#include "include/IndustrialBillCalculator.h"
#include "include/IndustrialUnits.h"
#include "include/BillCalculateSupport.h"

using namespace std;

string calculateIndustryBill(double inputUnits)
{
    string outputText = "";
    double costFactor[7] {125,135,145,155,165,175,180};
    double unitCosts[7];
    double totalCharge = 0;
    double maintenanceFee = 5000;
    double* acceptUnitSegments;

    acceptUnitSegments = getIndustrialUnitSegments(inputUnits);
    if(acceptUnitSegments[0] == -1)
    {
        outputText += "The Electrical Units should be non negative number!\n";
    }

    for(int i=0; i<7; i++)
    {
        if(acceptUnitSegments[i] == 0)
            break;
        unitCosts[i] = acceptUnitSegments[i] * costFactor[i];
        outputText += "Units: " + formatOutputString(acceptUnitSegments[i]) + " x " + formatOutputString(costFactor[i]) + " Kyats Cost: " + formatOutputString(unitCosts[i]) + " Kyats \n";
        totalCharge += unitCosts[i];
    }

    outputText += "Total Units Cost: " + formatOutputString(totalCharge) + " Kyats \n";
    outputText += "Total Bill (maintenance fee included): " + formatOutputString(totalCharge+maintenanceFee) + " Kyats \n";
    return outputText;
}
