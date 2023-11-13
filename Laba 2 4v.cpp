#include <sstream>
#include <iomanip>
#include <string>
#include<filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define filename1 "World_Happiness_ Report_2019.csv"
#define filename2 "NewFile.txt"

using namespace std;

int main(int argc, char* argv[])
{
	
	ofstream fout;
	fout.open(filename2);
	//fout << "Overall rank" << ";" << "Country or region" << ";" << "Score" << ";" << "GDP per capita" << ";" << "Social support" << ";" << "Healthy life expectancy" << ";" << "Freedom to make life choices" << ";" << "Generosity" << ";" << "Perceptions of corruption";


	ifstream fin;
	fin.open(filename1);


	string num;
	string CountryorRegion, Score, GDPPerCapita, SocialSupport, HealthyLifeExpectancy, Freedom, Generosity, PerceptionsOfCorruption;
	double num_max = 0;
	char delimiter = ',';
	char dd = '.';
	string str;


	getline(fin, str);
	if (fin.is_open())
	{
		while (getline(fin, str))
		{

			istringstream iss(str);

			stringstream stream(str);
			iss>> num >> CountryorRegion >> Score >> GDPPerCapita >> SocialSupport >> HealthyLifeExpectancy >> Freedom >> Generosity >> PerceptionsOfCorruption;

			getline(stream, num, delimiter);
			getline(stream, CountryorRegion, delimiter);
			getline(stream, Score, delimiter);
			getline(stream, GDPPerCapita, delimiter);
			getline(stream, SocialSupport, delimiter);
			getline(stream, HealthyLifeExpectancy, delimiter);
			getline(stream, Freedom, delimiter);
			getline(stream, Generosity, delimiter);
			getline(stream, PerceptionsOfCorruption, delimiter);


			double num_GDPPerCapita = std::stod(GDPPerCapita);
			if (num_GDPPerCapita < 0.6)
			{
				cout << CountryorRegion << "-" << num_GDPPerCapita << endl;
			}


			double num_SocialSupport = std::stod(SocialSupport);
			if (num_SocialSupport > num_max)
			{
				num_max = num_SocialSupport;
			}


			double num_Generosity = std::stod(Generosity);			
			if (num_Generosity > 0.15)
			{
				fout << CountryorRegion << " " << Score << " " << GDPPerCapita << " " << SocialSupport << " " << HealthyLifeExpectancy << " " << Freedom << " " << Generosity << " " << PerceptionsOfCorruption<<endl;
			}
		}
		cout << "\n\nSocial support max=" << num_max << "\n\n\n";

		

	}

	fin.close();
	fout.close();



	return 0;
}
