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

	std::string tag = "";

	for (int i = 0; i < str.length(); i++) 
	{

		if (str[i] == ' ') 
		{
			break;
		}


		if (str[i] != '<' && str[i] != ' ') 
		{
			tag += str[i];
		}
		else if (str[i] == '<' && str[i + 1] == '/') 
		{
			currentTag->clear();
			break;
		}

	}

	(*currentTag) = tag;

}

void attr_value(const std::string tag, std::map<std::string, std::string>* hrml, std::string str)
{

	
	std::string currentTag = tag;
	std::string attrNameLabel = "";
	std::string attrValueLabel = "";

	currentTag += '~';

	bool attrNameBool = false;
	bool attrValueBool = false;



	for (int i = (currentTag).length(); i < str.length(); i++) 
	{
	
		if(attrNameBool)
		{
			attrNameLabel += str[i];
		}
		else if (attrValueBool)
		{
			attrValueLabel += str[i];
		}


		if ((str[i] == ' ' && !attrNameBool) || (str[i] == '"' && attrValueBool))
		{
			attrNameBool = true;
		}
		else if((str[i] == ' ' || str[i] == '=') && attrNameBool)
		{
			attrNameBool = false;
			
			attrNameLabel.erase(attrNameLabel.length() - 1);
			currentTag += attrNameLabel;
		}


		if (str[i] == '"') 
		{

			if (attrValueBool)
			{
				attrValueLabel.erase(attrValueLabel.length() - 1);

				hrml->insert(attrNameLabel, attrValueLabel);

				currentTag = tag +  '~';
				attrNameLabel = "";
				attrValueLabel = "";
				
			}

			attrValueBool = !attrValueBool;

		}
	}


}


int main()
{
	int N = 0;
	int Q = 0;

	std::string tag = "";

	std::map<std::string, std::string> hrml;

	std::cin >> N;
	std::cin >> Q;

	for (int i = 0; i < N; i++) 
	{
		std::string temp;

		std::cin >> temp;

		find_tag(&tag, temp);

		if (!tag.empty())
		{
			attr_value(tag, &hrml, temp);
		}
		
	}
	

	for (int i = 0; i < Q; i++) 
	{
		std::string temp;

		std::cin >> temp;

		if (!temp.empty()) 
		{
			//
			// compare key
			// check if key exist
			// if exist output value

			// if not output Not Exist!
		}
	}





	return 0;
}