#include <iostream>
#include <cstring>
#include <cmath>

//TASKS.MD


//TASK1

enum Division 
{
    ASSASIN,
    MEDIC,
    MAGE,
    TANK
};

enum Combat
{
    UNKNOWN = -1,
    RANGE,
    MELEE,
    BOTH
};

struct Hero
{
    char* name;
    Division division;
    Combat combat;
};

const char* divisionToText(Division division) 
{
    switch (division)
    {
        case ASSASIN: return "ASSASIN";
        case MEDIC: return "MEDIC";
        case MAGE: return "MAGE";
        case TANK: return "TANK";
        default: return "NOOO";
    }
}

const char* combatToText(Combat combat) 
{
    switch (combat)
    {
        case UNKNOWN: return "UNKNOWN";
        case RANGE: return "RANGE";
        case MELEE: return "MELEE";
        case BOTH: return "BOTH";
        default: return "NOOO";
    }
}

void deleteName(Hero& hero)
{
    delete[] hero.name;
    hero.name = nullptr;
}

/*int main()
{
    Hero MEOWMEOW;

    const char* heroName = "MEOW";
    MEOWMEOW.name = new char[5];
    strcpy(MEOWMEOW.name, heroName);

    MEOWMEOW.division = {ASSASIN};
    MEOWMEOW.combat = {BOTH};
    
    std::cout << MEOWMEOW.name << std::endl << divisionToText(MEOWMEOW.division) << std::endl << combatToText(MEOWMEOW.combat);

    deleteName(MEOWMEOW);
    std::cout << endl;
}*/


//TASK2

struct StudentDoc
{
    char* name;
    int facultyNumber;
    int totalGrades;
    double* grades;
};

void deleteName(StudentDoc& studentOne)
{
    delete[] studentOne.name;
    studentOne.name = nullptr;
}

void deleteGrades(StudentDoc& studentOne)
{
    delete[] studentOne.grades;
    studentOne.grades = nullptr;
}

void sortingGrades(StudentDoc& studentOne)
{
    for (int i = 0; i < studentOne.totalGrades; i++) 
    {
        for (int j = 0; j < studentOne.totalGrades - i - 1; j++) 
        {
            if (studentOne.grades[j] < studentOne.grades[j + 1])
            {
                double temp = studentOne.grades[j];
                studentOne.grades[j] = studentOne.grades[j + 1];
                studentOne.grades[j + 1] = temp;
            }
        }
    }
}

double averrage(StudentDoc& studentOne)
{
    double averrageGrade;
    double sum = 0;
    int successfulExam = studentOne.totalGrades;

    for (int i = 0; i < studentOne.totalGrades; i++) 
    {
        if (studentOne.grades[i] < 3.00) 
        {
            successfulExam = successfulExam - 1;
        }
        else
        {
            sum = sum + studentOne.grades[i];
        }
    }
    averrageGrade = sum / successfulExam;

    return averrageGrade;
}

int failedExams (StudentDoc& studentOne)
{
    int failed = 0;

    for (int i = 0; i < studentOne.totalGrades; i++)
    {
        if (studentOne.grades[i] < 3.00)
        {
            failed++ ;
        }
    }

    return failed;
}

bool canMoveUp(StudentDoc& studentOne) 
{
    int failed = failedExams(studentOne);
    bool can;

    if (failed > 4)
    {
        can = true;
    }
    else if (failed > 4)
    {
        can = false;
    }
    else 
    {
        if (averrage(studentOne) >= 4.00)
        {
            can = true;
        }
        else
        {
            can = false;
        }
    }

    if (can)
    {
        std::cout << "Can move up" << std::endl;
    }
    else
    {
        std::cout << "Can't move up" << std::endl;
    }

    return can;
}

bool scholarship (StudentDoc& studentOne)
{
    bool can;
    double av = averrage(studentOne);
    int failed = failedExams(studentOne);

    if (av >= 5.00)
    {
        if (failed == 0)
        {
            can = true;
        }
        else
        {
            can = false;
        }
    }
    else
    {
        can = false;
    }

    if (can)
    {
        std::cout << "Eligible for scholarship. ";
    }
    else
    {
        std::cout << "Not eligible for scholarship. ";
    }

    return can;
}

int main()
{
    StudentDoc student;
    const char* studentName = "MEOW";
    student.name = new char[5];
    strcpy(student.name, studentName);
    
    student.totalGrades = 8;
    student.facultyNumber = 7492082;

    student.grades = new double[student.totalGrades]{6, 3, 3, 5, 3, 3, 3, 4};

    bool can = scholarship(student);

    std::cout << can;

    deleteName(student);
    deleteGrades(student);
}

