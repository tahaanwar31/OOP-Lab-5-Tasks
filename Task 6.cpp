#include <iostream>
using namespace std;

class Film {
    private:
        string filmTitle, filmDirector;
        float filmDuration;
    public:
        Film(string fT, string fD, float fDu) : filmTitle(fT), filmDirector(fD), filmDuration(fDu) {}
        string getFilmTitle() { return filmTitle; }
        string getFilmDirector() { return filmDirector; }
        float getFilmDuration() { return filmDuration; }
};

class Theatre {
    private:
        int totalFilms;
        Film** filmList;
        bool* currentlyPlaying;
    public:
        Theatre() {
            cout << "How many films are there? ";
            cin >> totalFilms;
            cin.ignore();
            filmList = new Film*[totalFilms];
            currentlyPlaying = new bool[totalFilms];
            for(int i = 0; i < totalFilms; i++) {
                string fT, fD;
                float fDu;
                cout << "Film Title: ";
                getline(cin, fT);
                cout << "Directed by: ";
                getline(cin, fD);
                cout << "Duration (hours): ";
                cin >> fDu;
                cin.ignore();
                filmList[i] = new Film(fT, fD, fDu);
                string playing;
                cout << "Currently Showing? (yes/no): ";
                getline(cin, playing);
                currentlyPlaying[i] = ("yes" == playing) ? true : false;
            }
        }
        ~Theatre() {
            for(int i = 0; i < totalFilms; i++) {
                delete filmList[i];
            }
            delete[] filmList;
            delete[] currentlyPlaying;
        }
        void showFilms() {
            cout << "\nNow Showing:" << endl;
            for(int i = 0; i < totalFilms; i++) {
                cout << i + 1 << ". Name: " << filmList[i]->getFilmTitle() << ", Director: " << filmList[i]->getFilmDirector() << ", Duration: " << filmList[i]->getFilmDuration() << " hours, Status: " << ((currentlyPlaying[i]) ? "Playing" : "Not Playing") << endl;
            }
            cout << endl;
        }
};

int main() {
    Theatre venue;
    venue.showFilms();
}
