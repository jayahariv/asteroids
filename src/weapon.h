
class Weapon {
public:
    Weapon() = delete;
    Weapon(int width, int height, int x, int y, float angle);

    virtual void Update();
    virtual bool WeaponCell(int x, int y);

    bool destroyed{false}; // (1)hitting target or (2)remove from frame

private:
    float _angle;
    float _x;
    float _y;
    
    int _grid_width;
    int _grid_height;
};