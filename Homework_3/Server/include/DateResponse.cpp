#include <stdlib.h>

#include "DateResponse.h"

DateResponse::DateResponse() : Response("Date")
{

}

std::string DateResponse::interpretPacket(const boost::property_tree::ptree& packet)
{
	auto Year = atoi(packet.get<std::string>("Year").c_str());
	auto Month = atoi(packet.get<std::string>("Month").c_str());
	auto Day = atoi(packet.get<std::string>("Day").c_str());

	bool isDateValid = true;

	this->content.push_back(boost::property_tree::ptree::value_type("File", "date.txt"));
	if (Month >= 13 || Month < 1) {
		this->content.push_back(boost::property_tree::ptree::value_type("Error", "Lunile intr-un an pot lua valori intre 1-12"));
		isDateValid = false;
	}
	else if (Day >= 31 || Day < 1) {
		this->content.push_back(boost::property_tree::ptree::value_type("Error", "Ziele intr-o luna calendaristica pot lua valori intre 1-31"));
		isDateValid = false;
	}
	else if (Year < 0) {
		this->content.push_back(boost::property_tree::ptree::value_type("Error", "Anul este mai mic decat 0"));
		isDateValid = false;
	}

	if (isDateValid) {
		switch (Month)
		{
		// January
		case 1:
			Day <= 20 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 22 Dec - 20 Ian", "Capricorn")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 21 Ian - 19 Feb", "Varsator"));
			break;
		// February
		case 2:
			Day <= 20 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 21 Ian - 19 Feb", "Varsator")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 20 Feb- 20 Mar", "Peste"));
			break;
		// March
		case 3:
			Day <= 20 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 20 Feb- 20 Mar", "Peste")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 21 Mar - 20 Apr", "Berbec"));
			break;
		// April
		case 4:
			Day <= 20 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 21 Mar - 20 Apr", "Berbec")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 21 Apr - 21 Mai", "Taur"));
			break;
		// May
		case 5:
			Day <= 21 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 21 Apr - 21 Mai", "Taur")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 22 Mai - 21 Iun", "Gemeni"));
			break;
		// June
		case 6:
			Day <= 21 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 22 Mai - 21 Iun", "Gemeni")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 22 Iun - 22 Iul", "Rac"));
			break;
		// July
		case 7:
			Day <= 22 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 22 Iun - 22 Iul", "Rac")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 23 Iul - 22 Aug", "Leu"));
			break;
		// August
		case 8:
			Day <= 22 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 23 Iul - 22 Aug", "Leu")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 23 Aug - 23 Sep", "Fecioara"));
			break;
		// September
		case 9:
			Day <= 23 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 23 Aug - 23 Sep", "Fecioara")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 24 Sep - 23 Oct", "Balanta"));
			break;
		// October
		case 10:
			Day <= 23 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 24 Sep - 23 Oct", "Balanta")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 24 Oct - 22 Noi", "Scorpion"));
			break;
		// November
		case 11:
			Day <= 22 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 24 Oct - 22 Noi", "Scorpion")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 23 Noi - 21 Dec", "Sagetator"));
			break;
		// December
		case 12:
			Day <= 21 ? this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 23 Noi - 21 Dec", "Sagetator")) : this->content.push_back(boost::property_tree::ptree::value_type("Zodia: 22 Dec- 20 Ian", "Capricorn"));
			break;
		default:
			break;
		}

	}

	return this->getContentAsString();
}
