
class Bullet {
public:
    Bullet() = delete;
    Bullet(int width, int height, int x, int y, float angle);

    // postion
    void Update();
    // checks whether bullet is in given position
    bool isBulletCell(int x, int y);
    
    /*
    * should we need head and body kind of missle or just a bullet for now?
    * how can we extend the bullet?  should we rename bullet class itself?
    
    *** how the bullet hits the target? who decides the collition???? 

    * who responsible of holding the bullets? ship or game? i say, ship

    */

private:
    float _angle; 
};