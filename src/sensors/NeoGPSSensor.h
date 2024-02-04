#include "IGPSSensor.h"

class NeoGPSSensor : public IGPSSensor {
    public:
        float getLongitude() override;
        float getLatitude() override;
        float getAltitude() override;
};