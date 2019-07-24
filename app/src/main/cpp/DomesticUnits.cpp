//
// Created by Techman on 23/07/2019.
//

#include "include/DomesticUnits.h"

double* getDomesticUnitSegments(double inputUnits) {
    if (inputUnits >= 0 && inputUnits <= 30) {
        unitSegments[0] = inputUnits;
    } else if (inputUnits >= 0 && inputUnits > 30 && inputUnits <= 50) {
        unitSegments[0] = 30;
        unitSegments[1] = inputUnits - unitSegments[0];

    } else if (inputUnits >= 0 && inputUnits > 50 && inputUnits <= 75) {
        unitSegments[0] = 30;
        unitSegments[1] = 20;
        unitSegments[2] = inputUnits - (unitSegments[0] + unitSegments[1]);
    } else if (inputUnits >= 0 && inputUnits > 75 && inputUnits <= 100) {
        unitSegments[0] = 30;
        unitSegments[1] = 20;
        unitSegments[2] = 25;
        unitSegments[3] = inputUnits - (unitSegments[0] + unitSegments[1] + unitSegments[2]);
    } else if (inputUnits >= 0 && inputUnits > 100 && inputUnits <= 150) {
        unitSegments[0] = 30;
        unitSegments[1] = 20;
        unitSegments[2] = 25;
        unitSegments[3] = 25;
        unitSegments[4] = inputUnits - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3]);
    } else if (inputUnits >= 0 && inputUnits > 150 && inputUnits <= 200) {
        unitSegments[0] = 30;
        unitSegments[1] = 20;
        unitSegments[2] = 25;
        unitSegments[3] = 25;
        unitSegments[4] = 50;
        unitSegments[5] =
                inputUnits - (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3] + unitSegments[4]);
    } else if (inputUnits >= 0 && inputUnits > 200) {
        unitSegments[0] = 30;
        unitSegments[1] = 20;
        unitSegments[2] = 25;
        unitSegments[3] = 25;
        unitSegments[4] = 50;
        unitSegments[5] = 50;
        unitSegments[6] = inputUnits -
                          (unitSegments[0] + unitSegments[1] + unitSegments[2] + unitSegments[3] + unitSegments[4] +
                           unitSegments[5]);
    } else {
        unitSegments[0] = -1;
    }

    return unitSegments;
}