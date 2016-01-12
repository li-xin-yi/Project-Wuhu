#include <iostream>
#include <string>
using namespace std;

class TheElder{
private:
unsigned int life;
int VisitedCountries;
int Languages;
int MusicalInstruments;
public:
TheElder(int time,int CountryNumber,int LanguageNumber,int MusicalInstrumentNumber);
void Recite(string title="GettysburgAddress" );
void CombHair();
void ApplyForProfessor();
void PlayWithThreeOwls();
};

TheElder::TheElder(int time,int CountryNumber,int LanguageNumber,int MusicalInstrumentNumber)
{}

TheElder::CombHair()
{}

TheElder::ApplyForProfessor()
{}

TheElder::PlayWithThreeOwls()
{}

int main()
{
	int i;
	cin>>i;
	return 0;
}