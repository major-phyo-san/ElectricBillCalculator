//
// Created by Techman (MajorSan) on 23/07/2019.
// Updated by Techman (MajorSan) on 19/04/2020.
// Refactored by Techman (MajorSan) on 25/05/2022.
//

#include "include/industrialunits.h"

const int LAYER_0_LIMIT = 500;
const int LAYER_1_LIMIT = 5000;
const int LAYER_2_LIMIT = 10000;
const int LAYER_3_LIMIT = 20000;
const int LAYER_4_LIMIT = 50000;
const int LAYER_5_LIMIT = 100000;

static double unitSegments[7];

double* getIndustrialUnitSegments(double inputUnits)
{
    if(inputUnits>=0 && inputUnits<=LAYER_0_LIMIT)
    {
        unitSegments[0] = inputUnits;
    }

    else if(inputUnits>=0 && inputUnits>LAYER_0_LIMIT && inputUnits<=LAYER_1_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT;
        unitSegments[1] = inputUnits - unitSegments[0];
    }

    else if(inputUnits>=0 && inputUnits>LAYER_1_LIMIT && inputUnits<=LAYER_2_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT;
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; //5000 - 500 => 4500
        unitSegments[2] = inputUnits - (unitSegments[0]+unitSegments[1]);
    }

    else if(inputUnits>=0 && inputUnits>LAYER_2_LIMIT && inputUnits<=LAYER_3_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT;
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; //4500
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]); //10000 -(500+4500) => 5000;
        unitSegments[3] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]);
    }

    else if(inputUnits>=0 && inputUnits>LAYER_3_LIMIT && inputUnits<=LAYER_4_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT; //500
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; //4500
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]); //5000
        unitSegments[3] = LAYER_3_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2]); //20000 - (500+4500+5000)
        unitSegments[4] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]+unitSegments[3]);
    }

    else if(inputUnits>=0 && inputUnits>LAYER_4_LIMIT && inputUnits<=LAYER_5_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT;
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0];
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]);
        unitSegments[3] = LAYER_3_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[3]);
        unitSegments[4] = LAYER_4_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3]);
        unitSegments[5] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]+unitSegments[3]+unitSegments[4]);
    }

    else if(inputUnits>=0 && inputUnits>LAYER_5_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT;
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0];
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]);
        unitSegments[3] = LAYER_3_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[3]);
        unitSegments[4] = LAYER_4_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3]);
        unitSegments[5] = LAYER_5_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3] + unitSegments[4]);
        unitSegments[6] = inputUnits - (unitSegments[0]+unitSegments[1]+unitSegments[2]+unitSegments[3]+unitSegments[4]+unitSegments[5]);
    }

    else
    {
        unitSegments[0] = -1;
    }

    return unitSegments;
}