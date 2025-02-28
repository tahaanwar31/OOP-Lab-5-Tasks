#include <iostream>
using namespace std;

class MedicalRecord {
    private:
        int recordID;
        string patientName;
        float *testScores;
        int testCount;         

    public:
        MedicalRecord(int id, string name, int num) : recordID(id), patientName(name), testCount(num) {
            testScores = new float[testCount];  
            cout << "Enter test results:" << endl;
            for (int i = 0; i < testCount; i++) {
                cout << "Result for Test " << i + 1 << ": ";
                cin >> testScores[i];
            }
        }

        MedicalRecord(MedicalRecord &obj) {
            recordID = obj.recordID;
            patientName = obj.patientName;
            testCount = obj.testCount;
            testScores = new float[testCount];  
            for (int i = 0; i < testCount; i++) {
                testScores[i] = obj.testScores[i];  
            }
        }

        ~MedicalRecord() {
            delete[] testScores; 
        }

        void showInfo() {
            cout << endl << "Record ID: " << recordID << ", Patient: " << patientName << endl << "Test Scores: ";
            for (int i = 0; i < testCount; i++) {
                cout << testScores[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    MedicalRecord taha(12, "Taha Anwer", 3);
    taha.showInfo();
    MedicalRecord record2 = taha;  
    record2.showInfo();
}
