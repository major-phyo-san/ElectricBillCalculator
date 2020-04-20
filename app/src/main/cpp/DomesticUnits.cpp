//
// Created by Techman on 23/07/2019.
// Updated by MajorSan on 19/04/2020.
//

#include "include/DomesticUnits.h"

const int LAYER_0_LIMIT = 30;
const int LAYER_1_LIMIT = 50;
const int LAYER_2_LIMIT = 75;
const int LAYER_3_LIMIT = 100;
const int LAYER_4_LIMIT = 150;
const int LAYER_5_LIMIT = 200;

double* getDomesticUnitSegments(double inputUnits) {
    if (inputUnits >= 0 && inputUnits <= LAYER_0_LIMIT)
    {
        unitSegments[0] = inputUnits;
    }
    else if (inputUnits >= 0 && inputUnits > LAYER_0_LIMIT && inputUnits <= LAYER_1_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT; //30
        unitSegments[1] = inputUnits - unitSegments[0];

    }
    else if (inputUnits >= 0 && inputUnits > LAYER_1_LIMIT && inputUnits <= LAYER_2_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT; //30
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; //50 - 30 => 20
        unitSegments[2] = inputUnits - (unitSegments[0] + unitSegments[1]);
    }
    else if (inputUnits >= 0 && inputUnits > LAYER_2_LIMIT && inputUnits <= LAYER_3_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT; //30
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; //50 - 30 => 20
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]); //75 - (30+20) => 25
        unitSegments[3] = inputUnits - (unitSegments[0] + unitSegments[1] + unitSegments[2]);
    }
    else if (inputUnits >= 0 && inputUnits > LAYER_3_LIMIT && inputUnits <= LAYER_4_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT; //30
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; // 50 - 30 => 20
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]); // 75 - (30+20) => 25
        unitSegments[3] = LAYER_3_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2]); // 100 - (30+20+25) => 25
        unitSegments[4] = inputUnits - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3]);
    }
    else if (inputUnits >= 0 && inputUnits > LAYER_4_LIMIT && inputUnits <= LAYER_5_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT; //30
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; //20
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]); //25
        unitSegments[3] = LAYER_3_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2]); //25
        unitSegments[4] = LAYER_4_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3]); //150 - (30+20+25+25) => 50;
        unitSegments[5] =
                inputUnits - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3] + unitSegments[4]);
    }
    else if (inputUnits >= 0 && inputUnits > LAYER_5_LIMIT)
    {
        unitSegments[0] = LAYER_0_LIMIT; //30
        unitSegments[1] = LAYER_1_LIMIT - unitSegments[0]; //20
        unitSegments[2] = LAYER_2_LIMIT - (unitSegments[0] + unitSegments[1]); //25
        unitSegments[3] = LAYER_3_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2]); //25
        unitSegments[4] = LAYER_4_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3]); //150 - (25+25+20+30) => 50;
        unitSegments[5] = LAYER_5_LIMIT - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3] + unitSegments[4]); //200 - (30+20+25+25+50) => 50
        unitSegments[6] = inputUnits -
                          (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3] + unitSegments[4] +
                           unitSegments[5]);
    }
    else
    {
        unitSegments[0] = -1;
    }

    return unitSegments;
}