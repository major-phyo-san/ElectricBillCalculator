//
// Created by Techman on 24/07/2019.
//

#include "include/IndustrialUnits.h"

double* getIndustrialUnitSegments(double inputUnits)
{

    if(inputUnits>=0 && inputUnits<=500)
    {
        unitSegments[0] = inputUnits;
    }

    else if(inputUnits>=0 && inputUnits>500 && inputUnits<=5000)
    {
        unitSegments[0] = 500;
        unitSegments[1] = inputUnits - unitSegments[0];

    }

    else if(inputUnits>=0 && inputUnits>5000 && inputUnits<=10000)
    {
        unitSegments[0] = 500;
        unitSegments[1] = 4500;
        unitSegments[2] = inputUnits - (unitSegments[0]+unitSegments[1]);
    }

    else if(inputUnits>=0 && inputUnits>10000 && inputUnits<=20000)
    {
        unitSegments[0] = 500;
        unitSegments[1] = 4500;
        unitSegments[2] = 5000;
        unitSegments[3] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]);
    }

    else if(inputUnits>=0 && inputUnits>20000 && inputUnits<=50000)
    {
        unitSegments[0] = 500;
        unitSegments[1] = 4500;
        unitSegments[2] = 5000;
        unitSegments[3] = 10000;
        unitSegments[4] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]+unitSegments[3]);
    }

    else if(inputUnits>=0 && inputUnits>50000 && inputUnits<=100000)
    {
        unitSegments[0] = 500;
        unitSegments[1] = 4500;
        unitSegments[2] = 5000;
        unitSegments[3] = 10000;
        unitSegments[4] = 30000;
        unitSegments[5] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]+unitSegments[3]+unitSegments[4]);
    }

    else if(inputUnits>=0 && inputUnits>100000)
    {
        unitSegments[0] = 500;
        unitSegments[1] = 4500;
        unitSegments[2] = 5000;
        unitSegments[3] = 10000;
        unitSegments[4] = 30000;
        unitSegments[5] = 50000;
        unitSegments[6] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]+unitSegments[3]+unitSegments[4]+unitSegments[5]);
    }

    else
    {
        unitSegments[0] = -1;
    }

    return unitSegments;
}
