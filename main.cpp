#include <iostream>
using namespace std;

class Basic_stat{
private:
    int hp;
    int def;
    int atk;
    
public:
    Basic_stat(int newhp, int newdef, int newatk){
        hp = newhp;
        def = newdef;
        atk = newatk;
    }
    int getdef(){
        return def;
    }
    int gethp(){
        return hp;
    }
    int getatk(){
        return atk;
    }
    
    void damage(int dmg) {
    hp -= dmg;
    if (hp < 0) hp = 0;
    }

    virtual void displayInfo(){
        cout << "Current HP : " << hp << endl;
        cout << "Current DEF : " << def << endl;
        cout << "Current ATK : " << atk << endl;
    }
};

class greatsword : public Basic_stat{
private:
    int atk;
    
public:
    greatsword(int newhp, int newdef, int newatk) : Basic_stat(newhp, newdef, newatk), atk(newatk) {}
    
    int getatk2() {
        return atk;
    }
    
    void displayInfo() override {
        cout << "Current HP : " << gethp() << endl;
        cout << "Current DEF : " << getdef() << endl;
        cout << "Current ATK : " << atk << endl;
    }

    void slash(Basic_stat& target) {
        int damage = atk - target.getdef();
        if (damage < 0) damage = 0;
        target.damage(damage);
        cout << "Sunshine's HP reduced by " << damage << " pts." << endl;
    }

};

int main(){
    greatsword supaniga(100, 2, 30);
    Basic_stat lebron(50, 5, 10); 

    cout << "Alice's Attributes : " << endl; 
    supaniga.displayInfo(); 
    cout << endl; 

    cout << "Sunshine's Stats : " << endl; 
    lebron.displayInfo(); 
    cout << endl;

    cout << "*Insert Slash SFX*" << endl;
    supaniga.slash(lebron); 
    cout << endl;

    cout << "Sunshine's Stats : " << endl; 
    lebron.displayInfo(); 

    return 0;
}
