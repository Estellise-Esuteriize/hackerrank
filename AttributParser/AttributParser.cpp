#include <iostream>
#include <vector>
#include <string>
#include <map>



void find_tag(std::string* currentTag, std::string str) 
{
	bool isTag = false;

	if (!currentTag->empty()) 
	{
		currentTag->append(".");
	}


	for (int i = 0; i < str.length(); i++) 
	{

		if (str[i] == ' ') 
		{
			break;
		}


		if (str[i] != '<' && str[i] != '>')
		{
			*currentTag += str[i];
		}
		else if (str[i] == '<' && str[i + 1] == '/') 
		{

			currentTag->erase(currentTag->length() - 1);

			for (int x = currentTag->size() - 1; x > -1; --x) 
			{
				if ((*currentTag)[x] == '.') 
				{		
					currentTag->erase(x);

					break;
				}
				currentTag->erase(x);
			}

			break;
		}

	}

}

void attr_value(const std::string tag, std::map<std::string, std::string>* hrml, std::string str)
{

	
	std::string currentTag = tag;
	std::string attrValueLabel = "";

	currentTag += '~';

	bool attrNameBool = false;
	bool attrValueBool = false;


	for (int i = 2; i < str.length(); i++) 
	{

		if (attrNameBool)
		{
			if (str[i] != ' ' && str[i] != '=' && str[i] != '"') 
			{
				currentTag += str[i];
			}
		}
		else if (attrValueBool)
		{
			if (str[i] != +'"') 
			{
				attrValueLabel += str[i];
			}
		}


		if ((str[i] == ' ' && !attrNameBool) || (str[i] == '"' && attrValueBool))
		{
			attrNameBool = true;
		}

		if (str[i] == '"') 
		{

			if (attrValueBool)
			{
				
				hrml->insert(std::pair<std::string, std::string>(currentTag, attrValueLabel));

				currentTag = tag +  '~';
				attrValueLabel = "";
				
			}

			attrValueBool = !attrValueBool;

			if (attrValueBool) 
			{
				attrNameBool = false;
			}

		}
	}


}


int main()
{
	int N = 0;
	int Q = 0;

	std::string tag = "";

	std::map<std::string, std::string> hrml;

	//std::cin >> N;
	//std::cin >> Q;

	std::vector<std::string> nT = { "<tag1 v1 = \"123\" v2 = \"43.4\" v3 = \"hello\">",
									"</tag1>",
									"<tag2 v4 = \"v2\" name = \"Tag2\">",
									"<tag3 v1 = \"Hello\" v2 = \"World!\">",
									"</tag3>",
									"<tag4 v1 = \"Hello\" v2 = \"Universe!\">",
									"</tag4>",
									"</tag2>",
									"<tag5>",
									"<tag7 new_val = \"New\">",
									"</tag7>",
									"</tag5>",
									"<tag6>",
									"<tag8 intval = \"34\" floatval = \"9.845\">",
									"</tag8>",
									"</tag6>"};

	std::vector<std::string> qT = { "tag1~v1",
									"tag1~v2",
									"tag1~v3",
									"tag4~v2",
									"tag2.tag4~v1",
									"tag2.tag4~v2",
									"tag2.tag3~v2",
									"tag5.tag7~new_val",
									"tag5~new_val",
									"tag7~new_val",
									"tag6.tag8~intval",
									"tag6.tag8~floatval",
									"tag6.tag8~val",
									"tag8~intval" };
	
	//std::cin >> std::ws;

	for (int i = 0; i < /** /N/**//**/nT.size()/**/; i++) 
	{
		std::string temp;

		//
		//std::getline(std::cin, temp);

		//test
		temp = nT[i];

		find_tag(&tag, temp);

		if (!tag.empty())
		{
			attr_value(tag, &hrml, temp);
		}

	}
	

	for (int i = 0; i < /** /Q/**//**/qT.size()/**/; i++) 
	{
		std::string temp;

		//std::cin >> temp;

		//test
		temp = qT[i];

		if (!temp.empty()) 
		{
			//
			// compare key
			// check if key exist
			// if exist output value

			// if not output Not Exist!
			auto it = hrml.find(temp);

			if (it != hrml.end()) 
			{
				std::cout << it->second << std::endl;
			}
			else 
			{
				std::cout << "Not Exists" << std::endl;
			}
		}
	}


	std::cout << "<<";


	return 0;
}