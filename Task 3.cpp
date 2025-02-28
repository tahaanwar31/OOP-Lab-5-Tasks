#include <iostream>
using namespace std;

class Lecturer {
    private:
        string lecturerName;
        int lecturerID;
        string faculty;
    public:
        Lecturer(string n, int i, string f) : lecturerName(n), lecturerID(i), faculty(f) {}
        string getName() {
            return lecturerName;
        }
        string getFaculty() {
            return faculty;
        }
        int getID() {
            return lecturerID;
        }
};

class Institution {
    private:
        string instituteName;
        string location;
        string* faculties;
        int facultyCount;
        Lecturer **lecturers;
        int lecturerCount;
    public:
        Institution(string n, string loc) : instituteName(n), location(loc) {
            lecturerCount = 0;
            lecturers = nullptr;

            cout << "Enter the number of faculties in " << n << ": ";
            cin >> facultyCount;
            cin.ignore();
            faculties = new string[facultyCount];
            for(int i = 0; i < facultyCount; i++) {
                cout << "Enter faculty #" << i + 1 << ": ";
                getline(cin, faculties[i]);
            }
        }
        void showLecturers() {
            if (lecturerCount == 0) {
                cout << "No lecturers found in " << instituteName << endl;
                return;
            }
            cout << endl << "List of lecturers in " << instituteName << ":" << endl;
            for (int i = 0; i < lecturerCount; i++) {
                cout << "ID: " << lecturers[i]->getID() << endl
                     << "Name: " << lecturers[i]->getName() << endl
                     << "Faculty: " << lecturers[i]->getFaculty() << endl;
            }
            cout << endl;
        }
        string getInstituteName() {
            return instituteName;
        }
        string getLocation() {
            return location;
        }
        void enrollLecturer(Lecturer * newLecturer) {
            string faculty = newLecturer->getFaculty();
            bool found = false;
            for(int i = 0; i < facultyCount; i++) {
                if (faculty == faculties[i]) {
                    found = true;
                }
            }
            if(!found) {
                cout << "Faculty mismatch for lecturer " << newLecturer->getName() 
                     << " in " << instituteName << ". Enrollment failed!" << endl;
                return;
            }
            Lecturer** tempLecturers = new Lecturer*[lecturerCount + 1];
            for (int i = 0; i < lecturerCount; i++) {
                tempLecturers[i] = lecturers[i];
            }
            delete[] lecturers;
            tempLecturers[lecturerCount] = newLecturer;
            lecturers = tempLecturers;
            lecturerCount++;
        }
        void removeLecturer() {
            int ID;
            cout << "Enter the ID of the lecturer to be removed from " << instituteName << ": ";
            cin >> ID;
            cin.ignore();
            int index;
            bool found = false;
            for(int i = 0; i < lecturerCount; i++) {
                if(lecturers[i]->getID() == ID) {
                    index = i;
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "Lecturer with ID " << ID << " not found. Cannot proceed with removal!" << endl;
                return;
            }
            Lecturer** tempLecturers = new Lecturer*[lecturerCount - 1];
            for (int i = 0; i < index; i++) {
                tempLecturers[i] = lecturers[i];
            }
            for (int i = index + 1; i < lecturerCount; i++) {
                tempLecturers[i - 1] = lecturers[i];
            }
            delete[] lecturers;
            lecturers = tempLecturers;
            lecturerCount--;
        }
        ~Institution() {
            delete[] lecturers;
            delete[] faculties;
        }
};

int main() {
    Institution fast("FAST-NUCES", "Shah Latif Town, Karachi");
    Institution iba("IBA", "Inside Karachi University, Karachi");
    
    Lecturer* taha = new Lecturer("Taha Ahmed", 201, "Computer Science");
    Lecturer* danial = new Lecturer("Danial Khan", 202, "Computer Science");
    Lecturer* ayesha = new Lecturer("Ayesha Tariq", 203, "AI & DS");
    Lecturer* rehan = new Lecturer("Rehan Ali", 204, "Software Engineering");
    Lecturer* sara = new Lecturer("Sara Malik", 205, "Management");
    Lecturer* fahad = new Lecturer("Fahad Javed", 206, "Accounting");
    Lecturer* laiba = new Lecturer("Laiba Noor", 207, "Finance");
    Lecturer* hammad = new Lecturer("Hammad Saeed", 208, "Economics");
    
    fast.enrollLecturer(taha);
    fast.enrollLecturer(danial);
    fast.enrollLecturer(ayesha);
    fast.enrollLecturer(rehan);
    fast.enrollLecturer(sara);
    
    iba.enrollLecturer(fahad);
    iba.enrollLecturer(laiba);
    iba.enrollLecturer(hammad);
    
    cout << "Initial list of lecturers:" << endl;
    fast.showLecturers();
    iba.showLecturers();

    cout << "Lecturer transferring from FAST-NUCES to IBA..." << endl;
    fast.removeLecturer();
    iba.enrollLecturer(taha);

    cout << "Updated lecturer lists after transfer:" << endl;
    fast.showLecturers();
    iba.showLecturers();
    
    delete taha;
    delete danial;
    delete ayesha;
    delete rehan;
    delete sara;
    delete fahad;
    delete laiba;
    delete hammad;
    
    return 0;
}
