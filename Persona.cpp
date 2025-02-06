#include <iostream>
#include <format>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <random>

class Persona {
    private:
	std::string FILE_NAME_MEN = "nombresMasculinos.txt";
	std::string FILE_NAME_WOMEN = "nombresFemeninos.txt";
    std::string FILE_SURNAME = "apellidos.txt";
    int CURRENT_YEAR = 2025;
	int MAX_NAMES_MEN = 47;
	int MAX_NAMES_WOMEN = 40;
    int MAX_SURNAMES = 40;

    std::string name;
    std::string surname1;
    std::string surname2;
    int age;
    bool gender;
    int birthDay;
    int birthMonth;
    int birthYear;

    void calculateAge () {
        age = CURRENT_YEAR - birthYear;
    }

    public:
	Persona() {
	    generateGender();
	    generateBirthDate();
        generateName(); 
        surname1 = generateSurname();
        surname2 = generateSurname();
	}

	void showPersonInfo() {
        std::cout << std::format("Name: {} {} {}\n", name, surname1, surname2);
        std::cout << std::format("Age: {}\n", age);
        std::cout << std::format("Birthday: {}/{}/{}\n", birthDay, birthMonth, birthYear);
        if (gender) {
            std::cout << "Gender: male\n";
        } else {
            std::cout << "Gender: female\n";
        }
        
	}

    //Section: get methods
    std::string getName () {
        return name;
    }
        
    std::string getSurname1 () {
        return surname1;
    }

    std::string getSurname2 () {
        return surname2;
    }

    int getAge () {
        return age;
    }

    bool getGender () {
        return gender;
    }

    int getBirthDay () {
        return birthDay;
    }

    int getBirthMonth () {
        return birthMonth;
    }

    int getBirthYear () {
        return birthYear;
    }

    //SECTION: generation functions
	int rangeRandomInt(int max, int min) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(min, max);
        
	    return distrib(gen);
	}

    void generateBirthDate () {
	    birthDay = rangeRandomInt(31, 0);
        birthMonth = rangeRandomInt(12, 0);
        birthYear = rangeRandomInt(2025, 1915);
        calculateAge();
    }

	void generateGender () {
	    gender = rangeRandomInt(1, 0);
	}

    std::string generateSurname() {
        std::ifstream ifile;
        ifile.open(FILE_SURNAME);

        if (!ifile) {
            std::cout << "Error opening reading file." << std::endl;
        }

        std::string line = "";
        int randomPosition = rangeRandomInt(MAX_SURNAMES, 0);
        int counter = 0;
        std::string surname;

        while (std::getline(ifile, line)) {
	        if (randomPosition == counter) {
                surname = line;
            }
	        counter++;
        }

        ifile.close();
        return surname;
    }

    void generateName () {

        std::ifstream ifile;
	    int max_names;

	    if (gender) {
            ifile.open(FILE_NAME_MEN);
		    max_names = MAX_NAMES_MEN;
	    } else {
		    ifile.open(FILE_NAME_WOMEN);
		    max_names = MAX_NAMES_WOMEN;
	    }

  	    if (!ifile) {
	        std::cout << "Error opening reading file." << std::endl;
        }

        std::string line = "";
        int randomPosition = rangeRandomInt(max_names, 0);
        int counter = 0;

        while (std::getline(ifile, line)) {
	        if (randomPosition == counter) {
                name = line;
            }
	        counter++;
        }

        ifile.close();
    }
};
