#include "weapon.h"

class Missile : public Weapon 
{ 
public:
    Missile() = delete;
    Missile(int width, int height, int x, int y, float angle);
    
    void Update() override;
    bool WeaponCell(int x, int y) override;
private:
};