#include <iostream>
using namespace std;

class Vehicle {
    private:
        int regID;
        string modelType;
        string proprietor;
    public:
        Vehicle(int r, string m, string o) : regID(r), modelType(m), proprietor(o) {}
        Vehicle(const Vehicle& v) {
            regID = v.regID;
            modelType = v.modelType;
            cout << "Enter New Proprietor: ";
			getline(cin, proprietor);
        }
        void showDetails() {
            cout << "Vehicle Info - Reg ID: " << regID << ", Model: " << modelType << ", Proprietor: " << proprietor << endl << endl;
        }
};

int main() {
    Vehicle v1(101, "BMW M5 Sedan", "Taha");
    v1.showDetails();

    Vehicle v2 = Vehicle(v1);
    v2.showDetails();

    return 0;
}
