class Weapon: public Item{
private:
        int damage;
        int hands;
public:
        Weapon(string/*name*/, int/*price*/, int/*levelReq*/, int/*damage*/, int/*hands*/);
        Weapon();
        Weapon(const Weapon&);
        int getDamage();
        int getHands();
};

