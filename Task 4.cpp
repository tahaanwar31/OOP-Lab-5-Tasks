#include <iostream>
using namespace std;

class PowerUnit {
    private:
        int energy;
        float level;
    public:
        PowerUnit() : energy(1000), level(100.0) { }
        PowerUnit(int e) : energy(e), level(100.0) { }
        
        int getEnergy() {
            return energy;
        }
        
        float getLevel() {
            return level;
        }

        void setLevel(float l) {
            level = l;
        }

        void refill() {
            if (level == 100) {
                cout << "Power already at max. No need to refill!" << endl;
                return;
            }
            level = 100.0;
            cout << "Power fully restored!" << endl;
        }

        void deplete() {
            if (level <= 0) {
                cout << "Device has shut down... Recharge needed!" << endl;
                return;
            }
            if (level <= 20) {
                cout << "Alert: Low power! Current level: " << level << "%." << endl;
            }
            level -= 5;
            if (level < 0) level = 0;
            cout << "Current power level: " << level << "%." << endl;
        }
};

class Gadget {
    private:
        PowerUnit battery;
        string brand;
        string version;
    public:
        Gadget(string b, string v, int e) : brand(b), version(v), battery(e) { }

        void showSpecs() {
            cout << "\nDevice Information:" << endl;
            cout << "Brand: " << brand << endl;
            cout << "Version: " << version << endl;
            cout << "Energy Storage: " << battery.getEnergy() << " mAh" << endl;
            cout << "Charge Level: " << battery.getLevel() << "%" << endl;
        }

        void recharge() {
            cout << "\nRecharging " << brand << "..." << endl;
            battery.refill();
        }

        void operate() {
            cout << "\nOperating " << brand << "..." << endl;
            battery.deplete();
        }
};

int main() {
    Gadget device1("Apple", "iPhone 15", 4500);

    device1.showSpecs();
    device1.operate();
    device1.recharge();
    device1.showSpecs();

    return 0;
}
