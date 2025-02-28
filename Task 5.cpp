#include <iostream>
using namespace std;

class Guide {
    private:
        string guideName;
        int experienceYears;
        string expertise;
    public:
        Guide(string g, int e, string ex) : guideName(g), experienceYears(e), expertise(ex) {}
        string getGuideName() { return guideName; }
        int getExperienceYears() { return experienceYears; }
        string getExpertise() { return expertise; }
};

class Agency {
    private:
        int guideCount;
        Guide ** guides;
    public:
        Agency() {
            guideCount = 0;
            guides = nullptr;
        }

        void addGuide(Guide* newGuide) {
            cout << "\nRegistering new guide..." << endl;
            Guide ** temp = new Guide* [guideCount + 1];
            for(int i = 0; i < guideCount; i++) {
                temp[i] = guides[i];
            }
            temp[guideCount] = newGuide;
            delete[] guides;
            guides = temp;
            guideCount++;
            cout << "Guide " << newGuide->getGuideName() << " successfully registered!" << endl << endl;
        }

        void removeGuide() {
            cout << "\nDeleting a guide..." << endl;
            string gName;
            cout << "Enter guide's name to remove: ";
            getline(cin, gName);
            bool found = false;
            int idx;
            for(int i = 0; i < guideCount; i++) {
                if(gName == guides[i]->getGuideName()) {
                    found = true;
                    idx = i;
                }
            }
            if(!found) {
                cout << "No guide named " << gName << " found! Deletion failed." << endl;
                return;
            }
            if(guideCount == 1) {
                delete[] guides;
                guides = nullptr;
            } else {
                Guide** temp = new Guide*[guideCount - 1];
                for(int i = 0; i < idx; i++) {
                    temp[i] = guides[i];
                }
                for(int i = idx; i < guideCount; i++) {
                    temp[i - 1] = guides[i];
                }
                delete[] guides;
                guides = temp;
            }
            guideCount--;
            cout << "Guide " << gName << " has been removed!" << endl << endl;
        }

        void listGuides() {
            cout << "\nGuide Directory:" << endl;
            for(int i = 0; i < guideCount; i++) {
                cout << i + 1 << ". Name: " << guides[i]->getGuideName() << ", Experience: " << guides[i]->getExperienceYears() << " years, Expertise: " << guides[i]->getExpertise() << endl;
            }
            cout << endl;
        }

        ~Agency() {
            delete[] guides;
        }
};

int main() {
    Agency DreamTours;

    Guide* hassan = new Guide("Hassan", 5, "Cultural Tours");
    Guide* ahmed = new Guide("Ahmed", 3, "Mountain Trekking");
    Guide* zain = new Guide("Zain", 7, "Desert Safaris");

    DreamTours.addGuide(hassan);
    DreamTours.addGuide(ahmed);
    DreamTours.addGuide(zain);

    DreamTours.listGuides();

    DreamTours.removeGuide();

    DreamTours.listGuides();

    delete hassan, ahmed, zain;
}
